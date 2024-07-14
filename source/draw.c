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
 * @param x The horizontal offset at which to start drawing.
 * @param y The vertical offset at which to start drawing.
 * @param width The width in pixels to draw.
 * @param height The height in pixels to draw
 * @param color The RGB color to draw.
 * @param isDrawDirect Flag to draw the directly on screen on not in the Vcache.
 */
void IWRAM_CODE Clear(u16 x, u16 y, u16 width, u16 height, u16 color, u8 isDrawDirect) {
   u16* p;
   u16 yi, ww, hh;

   if (isDrawDirect)
      p = VideoBuffer;
   else
      p = Vcache;

   hh = (y + height > 160) ? 160 : (y + height);
   ww = (x + width > 240) ? (240 - x) : width;

   // u16 tmp[240];
   for (u32 i = 0; i < 240; i++)
      ((u16*)pReadCache)[i] = color;

   for (yi = y; yi < hh; yi++)
      dmaCopy(pReadCache, p + yi * 240 + x, ww * 2);
}

/**
 * @brief Draws the given background image.
 *
 * @param pbg Pointer to the background image to draw.
 * @param x The horizontal coordinate at which to start drawing.
 * @param y The vertical coordinate at which to start drawing.
 * @param width The width to draw.
 * @param height The height to draw.
 * @param isDrawDirect Flag to write the image to video buffer or the cache.
 */
void IWRAM_CODE ClearWithBG(u16* pbg, u16 x, u16 y, u16 width, u16 height, u8 isDrawDirect) {
   u16* p;
   u16 yi, ww, hh;

   if (isDrawDirect)
      p = VideoBuffer;
   else
      p = Vcache;

   hh = (y + height > 160) ? 160 : (y + height);
   ww = (x + width > 240) ? (240 - x) : width;

   for (yi = y; yi < hh; yi++)
      dmaCopy(pbg + yi * 240 + x, p + yi * 240 + x, ww * 2);
}

/**
 * @brief Draws the given image, removing the transparency color if wanted.
 *
 * @param GFX Pointer to the image to draw.
 * @param x The horizontal coordinate at which to start drawing.
 * @param y The vertical coordinate at which to start drawing.
 * @param width The width of the image to draw.
 * @param height The height of the image to draw.
 * @param isTrans Flag if parts of the image should be transparent.
 * @param tcolor The color in the image should be considered as transparent.
 * @param isDrawDirect Flag to write the image to the video buffer or the cache.
 */
void IWRAM_CODE DrawPic(u16* GFX, u16 x, u16 y, u16 width, u16 height, u8 isTrans, u16 tcolor, u8 isDrawDirect) {
   u16 *p, c;
   u16 xi, yi, ww, hh;

   if (isDrawDirect)
      p = VideoBuffer;
   else
      p = Vcache;

   hh = (y + height > 160) ? 160 : (y + height);
   ww = (x + width > 240) ? (240 - x) : width;

   if (isTrans)
   {
      for (yi = y; yi < hh; yi++)
         for (xi = x; xi < x + ww; xi++) {
            c = GFX[(yi - y) * width + (xi - x)];
            if (c != tcolor)
               p[yi * 240 + xi] = c;
         }
   }
   else 
   {
      for (yi = y; yi < hh; yi++)
         dmaCopy(GFX + (yi - y) * width, p + yi * 240 + x, width * 2);
   }
}

/**
 * @brief Draws the given text on the screen by drawing it pixel by pixel.
 *
 * @param str The string to display on screen.
 * @param len The length of the string (optional).
 * @param x The horizontal coordinate at which to start writing the string.
 * @param y The vertical coordiante at which to start writing the string.
 * @param color The color in which to write the string.
 * @param isDrawDirect Flag to draw the image directly in the video buffer or the cache.
 */
void DrawText(char* str, u16 len, u16 x, u16 y, u16 color, u8 isDrawDirect) {
   u32 i, l, hi = 0;
   u32 location;
   u8 cc, c1, c2;
   u16* v;
   u16* p1 = Vcache;
   u16* p2 = VideoBuffer;
   u16 yy;

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

   while (hi < l)
   {
      c1 = str[hi];
      hi++;
      if (c1 < *FONT_START_CHAR)
         continue;

      if (c1 < 0x80)
      {
         // Get location of ASCII character
         location = (c1 - *FONT_START_CHAR) * 13;
      }
      else if (!(c1 >> 5 & 1))
      {
         // Get location of Extended-ASCII character
         c2 = str[hi];
         hi++;
         location = ((((c1 & 0x1F) << 6) | (c2 & 0x3F)) - *FONT_START_CHAR) * 13;
      }
      else
      {
         break;
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
            v[x + 5 + yy] = color;
         if (cc & 0x02)
            v[x + 4 + yy] = color;
         if (cc & 0x04)
            v[x + 3 + yy] = color;
         if (cc & 0x08)
            v[x + 2 + yy] = color;
         if (cc & 0x10)
            v[x + 1 + yy] = color;
         if (cc & 0x20)
            v[x + yy] = color;
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

//    DrawText(str, 0, 0, current_y, RGB(31, 31, 31), 1);

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
   DrawText(MESSAGES[L_LOAD_ROM], 0, (240 - strlen(MESSAGES[L_LOAD_ROM]) * 6) / 2, 72, 0x7FFF, 1);
   DrawText(str, 0, (240 - str_len * 6) / 2, 160 - 15, 0x7FFF, 1);
}