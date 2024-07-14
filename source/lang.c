#include <gba_base.h>
#include "lang.h"
#include "fnt_cozette.h"
#include "utils.h"

char* MESSAGES[N_MESSAGES];
char* MENU_BOOT[N_BOOT];
char* MENU_NOR[N_NOR];

char* LANGUAGES[2] = {
   "English",
   "Français"
};

unsigned char* GLOBAL_FONT = (unsigned char*)COZETTE_FNT;
int* FONT_START_CHAR = &COZETTE_START_CHAR;

/**
 * @brief Loads the language file's content into different arrays.
 * 
 * @param path The path to the language file to load.
 * @return u8 True (1) if the file was correctly loaded, False (0) otherwise.
 */
u8 load_language(char* path)
{
   u32 res;
   res = get_file_lines(path, MESSAGES, N_MESSAGES, 1, 1);
   if (res != N_MESSAGES)
      return 0;
   
   res = get_file_lines("", MENU_BOOT, N_BOOT, 1, 0);
   if (res != N_BOOT)
      return 0;
   
   res = get_file_lines("", MENU_NOR, N_NOR, 0, 0);
   if (res != N_NOR)
      return 0;

   return 1;
}
