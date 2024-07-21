#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gba_base.h>
#include <gba_dma.h>

#include "ff.h"
#include "ezkernel.h"

extern FIL gfile;

/**
 * @brief Removes trailing whitespaces from the string.
 * 
 * @param s The string from which to remove trailing spaces.
 */
void trim(char s[])
{
   int n;
   for (n = strlen(s) - 1; n >= 0; n--) {
      if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
         break;
      s[n] = '\0';
   }
}

/**
 * @brief Gets the lines of a file and stores them into the given list of pointers.
 * 
 * @param path Path to the file to read.
 * @param list The list of pointers in which to store the lines
 * @param size The size of the list.
 * @param keep_open A boolean to keep the file handle open after this function ends.
 * @param from_start A boolean to open the file and start reading from its start.
 * @return u32 The number of lines that were populated in the list.
 */
u32 get_file_lines(char* path, char** list, u32 size, u8 keep_open, u8 from_start)
{
   char buf[512];
   u32 i = 0;
   u32 len;
   if (from_start)
   {
      u32 res;
      res = f_open(&gfile, path, FA_READ);
      if (res != FR_OK)
      {
         f_close(&gfile);
         return 0;
      }
      f_lseek(&gfile, 0x0);
   }

   memset(buf, 0x00, 512);
   while (f_gets(buf, 512, &gfile) != NULL)
   {
      trim(buf);
      len = strlen(buf);
      if (!len)
         continue;

      list[i] = realloc(list[i], (len + 1) * sizeof(char));
      dmaCopy(buf, list[i], len + 1);
      memset(buf, 0x00, 512);

      i++;
      if (i == size)
         break;
   }

   if (!keep_open || i != size)
      f_close(&gfile);
   return i;
}

/**
 * @brief Runs an empty for loop to create delay.
 * 
 * @param R0 The number of iterations for the loop.
 */
void delay(u32 R0) {
   int volatile i;

   for (i = R0; i; --i)
      ;
   return;
}