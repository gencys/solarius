#include <gba_base.h>

#ifndef _LANG_H
#define _LANG_H

#define N_LANGUAGES 2
#define N_MESSAGES 81
#define N_BOOT 6
#define N_NOR 5

#define INIT_ERR "Failed to initialize microSD card."
#define POWER_OFF "Power off the console."
#define INIT_OK "microSD card initialization successful."
#define LOADING "Loading..."

#define CREDIT_1 "Solarius v1.0"
#define CREDIT_2 "by Gencys."

#define L_INIT_ERR 0
#define L_POWER_OFF 1
#define L_INIT_OK 2
#define L_LOADING 3
#define L_F_OVERFLOW 4
#define L_MENU_BTN 5
#define L_WRITING 6
#define L_SELECT_LATEST 7
#define L_TIME 8
#define L_MONDAY 9
#define L_TUESDAY 10
#define L_WEDNESDAY 11
#define L_THURSDAY 12
#define L_FRIDAY 13
#define L_SATURDAY 14
#define L_SUNDAY 15
#define L_ADDON 16
#define L_RESET 17
#define L_SAVESTATE 18
#define L_SLEEP 19
#define L_CHEAT 20
#define L_SLEEP_K 21
#define L_MENU_K 22
#define L_LANG 23
#define L_SET 24
#define L_OK 25
#define L_DISCLAIMER_OK 26
#define L_WARN_TIME 27
#define L_FINAL_WARN 28
#define L_CHECK_SAVE 29
#define L_CREATE_SAVE 30
#define L_CHECK_RTS 31
#define L_CREATE_RTS 32
#define L_CHECK_PATCH 33
#define L_CREATE_PATCH 34
#define L_WAIT 35
#define L_LOAD_ROM 36
#define L_NO_GBA 37
#define L_ENGINE 38
#define L_FP_ENGINE 39
#define L_RECENT 40
#define L_RECENT_LIST 41
#define L_MORE_OPT 42
#define L_COLD_START 43
#define L_DEL_FILE 44
#define L_DEL_SAVE 45
#define L_MANUAL 46
#define L_NO_RECENT 47
#define L_RTC 48
#define L_OPEN 49
#define L_CLOSE 50
#define L_HARDRESET 51
#define L_BACKUP 52
#define L_FOLDER_ERR 53
#define L_FILE_ERR 54
#define L_BACKUP_ERR 55
#define L_SAVE_ERR 56
#define L_READ_SAVE_ERR 57
#define L_WRITE_SAVE_ERR 58
#define L_RTS_ERR 59
#define L_COPY_SAVE 60
#define L_SAVING 61
#define L_SAVE 62
#define L_AUTO_SAVE 63
#define L_MODE_B 64
#define L_RUMBLE 65
#define L_RAM 66
#define L_CART 67
#define L_LED 68
#define L_ENABLE_LED 69
#define L_BREATHE_LED 70
#define L_SD_LED 71
#define L_NOR_FULL 72
#define L_SAV_LOADED 73
#define L_SAV_SAVED 74
#define L_OVERWRITE 75
#define L_NO_SAV 76
#define L_COPY_ROM 77
#define L_GEN_EMU 78
#define L_ENABLED 79
#define L_DISABLED 80

extern char* MESSAGES[N_MESSAGES];
extern char* MENU_BOOT[N_BOOT];
extern char* MENU_NOR[N_NOR];

extern char* LANGUAGES[N_LANGUAGES];
extern char* LANG_PATHS[N_LANGUAGES];

// ASCII Font
extern unsigned char* GLOBAL_FONT;
extern int* FONT_START_CHAR;

u8 load_language(char* path);

#endif
