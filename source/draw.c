/**
 * @file draw.c
 * @author EZ-Flash
 * @brief Functions to draw pixels on the screen.
 * @version 1.0
 * @date 2024-05-26
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <gba_base.h>
#include <gba_dma.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "draw.h"
#include "ez_define.h"
#include "ezkernel.h"
#include "lang.h"

int current_y = 1;
extern u8 pReadCache[MAX_pReadCache_size] EWRAM_BSS;

/**
 * @brief Clears the read cache with a color and draws the color on the screen.
 *
 * @param x The horizontal offsst at which to start drawing.
 * @param y The vertical offset at which to start drawing.
 * @param w The width in pixels to draw.
 * @param h The height in pixels to draw
 * @param c The RGB color to draw.
 * @param isDrawDirect Flag to draw the directly on screen on not in the Vcache.
 */
void IWRAM_CODE Clear(u16 x, u16 y, u16 w, u16 h, u16 c, u8 isDrawDirect) {
   u16* p;
   u16 yi, ww, hh;

   if (isDrawDirect)
      p = VideoBuffer;
   else
      p = Vcache;

   hh = (y + h > 160) ? 160 : (y + h);
   ww = (x + w > 240) ? (240 - x) : w;

   // u16 tmp[240];
   for (u32 i = 0; i < 240; i++)
      ((u16*)pReadCache)[i] = c;

   for (yi = y; yi < hh; yi++)
      dmaCopy(pReadCache, p + yi * 240 + x, ww * 2);
}

/**
 * @brief
 *
 * @param pbg
 * @param x
 * @param y
 * @param w
 * @param h
 * @param isDrawDirect
 */
void IWRAM_CODE ClearWithBG(u16* pbg, u16 x, u16 y, u16 w, u16 h, u8 isDrawDirect) {
   u16* p;
   u16 yi, ww, hh;

   if (isDrawDirect)
      p = VideoBuffer;
   else
      p = Vcache;

   hh = (y + h > 160) ? 160 : (y + h);
   ww = (x + w > 240) ? (240 - x) : w;

   for (yi = y; yi < hh; yi++)
      dmaCopy(pbg + yi * 240 + x, p + yi * 240 + x, ww * 2);
}

/**
 * @brief
 *
 * @param GFX
 * @param x
 * @param y
 * @param w
 * @param h
 * @param isTrans
 * @param tcolor
 * @param isDrawDirect
 */
void IWRAM_CODE DrawPic(u16* GFX, u16 x, u16 y, u16 w, u16 h, u8 isTrans, u16 tcolor, u8 isDrawDirect) {
   u16 *p, c;
   u16 xi, yi, ww, hh;

   if (isDrawDirect)
      p = VideoBuffer;
   else
      p = Vcache;

   hh = (y + h > 160) ? 160 : (y + h);
   ww = (x + w > 240) ? (240 - x) : w;

   if (isTrans) {
      for (yi = y; yi < hh; yi++)
         for (xi = x; xi < x + ww; xi++) {
            c = GFX[(yi - y) * w + (xi - x)];
            if (c != tcolor)
               p[yi * 240 + xi] = c;
         }
   } else {
      for (yi = y; yi < hh; yi++)
         dmaCopy(GFX + (yi - y) * w, p + yi * 240 + x, w * 2);
   }
}

/**
 * @brief
 *
 * @param str
 * @param len
 * @param x
 * @param y
 * @param c
 * @param isDrawDirect
 */
void DrawHZText12(char* str, u16 len, u16 x, u16 y, u16 c, u8 isDrawDirect) {
   u32 i, l, hi = 0;
   u32 location;
   u8 cc, c1, c2;
   u16* v;
   u16* p1 = Vcache;
   u16* p2 = VideoBuffer;
   u16 yy;
   char msg[20];

   if (isDrawDirect)
      v = p2;
   else
      v = p1;

   if (len == 0 || len > strlen(str))
      l = strlen(str);
   else
      l = len;

   if ((u16)(len * 6) > (u16)(240 - x))
      len = (240 - x) / 6;

   while (hi < l) {
      c1 = str[hi];
      hi++;
      if (c1 < *FONT_START_CHAR)
         continue;

      if (c1 < 0x80)  // ASCII
      {
         location = (c1 - *FONT_START_CHAR) * 13;
      }
      else if (!(c1 >> 5 & 1))
      {
         c2 = str[hi];
         hi++;
         location = ((((c1 & 0x1F) << 6) | (c2 & 0x3F)) - *FONT_START_CHAR) * 13;
      }

      yy = 240 * y;
      for (i = 0; i < 13; i++)
      {
         cc = GLOBAL_FONT[location + i];
         if (!cc)
         {
            yy += 240;
            continue;
         }

         if (cc & 0x01)
            v[x + 5 + yy] = c;
         if (cc & 0x02)
            v[x + 4 + yy] = c;
         if (cc & 0x04)
            v[x + 3 + yy] = c;
         if (cc & 0x08)
            v[x + 2 + yy] = c;
         if (cc & 0x10)
            v[x + 1 + yy] = c;
         if (cc & 0x20)
            v[x + yy] = c;
         // The width of cozette is 6px so we can skip the two MSBs
         // if (cc & 0x40)
         //    v[x + 1 + yy] = c;
         // if (cc & 0x80)
         //    v[x + yy] = c;
         yy += 240;
      }
      x += 6;
      continue;
   }
}

/**
 * @brief
 *
 * @param format
 * @param ...
 */
// void DEBUG_printf(const char* format, ...) {
//    char str[128];
//    va_list va;
//    va_start(va, format);
//    // vasprintf(str, format, va);
//    vsprintf(str, format, va);
//    va_end(va);

//    if (current_y == 1) {
//       Clear(0, 0, 240, 160, 0x0000, 1);
//    }

//    DrawHZText12(str, 0, 0, current_y, RGB(31, 31, 31), 1);

//    // free(str);

//    current_y += 12;
//    if (current_y > 150) {
//       wait_btn();
//       current_y = 1;
//    }
// }

/**
 * @brief
 *
 * @param str
 */
void ShowbootProgress(char* str) {
   u8 str_len = strlen(str);
   Clear(0, 160 - 15, 240, 15, gl_color_cheat_black, 1);
   DrawHZText12(gl_loading_game, 0, (240 - strlen(gl_loading_game) * 6) / 2, 72, 0x7FFF, 1);
   DrawHZText12(str, 0, (240 - str_len * 6) / 2, 160 - 15, 0x7FFF, 1);
}