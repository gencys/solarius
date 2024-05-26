#include "lang.h"

#include "asc126_new.h"
#include "asc126_old.h"

char* gl_init_error;
char* gl_power_off;
char* gl_init_ok;
char* gl_Loading;
char* gl_file_overflow;
char* gl_theme_credit;
char* gl_theme_credit2;

char* gl_generating_emu;

char* gl_menu_btn;
char* gl_lastest_game;

char* gl_writing;

char* gl_time;
char* gl_Mon;
char* gl_Tues;
char* gl_Wed;
char* gl_Thur;
char* gl_Fri;
char* gl_Sat;
char* gl_Sun;

char* gl_addon;
char* gl_reset;
char* gl_rts;
char* gl_sleep;
char* gl_cheat;

char* gl_hot_key;
char* gl_hot_key2;

char* gl_language;
char* gl_en_lang;
char* gl_fr_lang;
char* gl_set_btn;
char* gl_ok_btn;

char* gl_formatnor_info1;
char* gl_formatnor_info2;

char* temp;

char* gl_check_sav;
char* gl_make_sav;

char* gl_check_RTS;
char* gl_make_RTS;

char* gl_check_pat;
char* gl_make_pat;

char* gl_loading_game;

char* gl_engine;
char* gl_use_engine;

char* gl_recently_play;

char* gl_START_help;
char* gl_SELECT_help;
char* gl_L_A_help;
char* gl_LSTART_help;
char* gl_online_manual;

char* gl_no_game_played;

char* gl_ingameRTC;
// char* gl_offRTC_powersave;
char* gl_ingameRTC_open;
char* gl_ingameRTC_close;

char* gl_lang_toggle_reset;
char* gl_lang_toggle_backup;

char* gl_error_0;
char* gl_error_1;
char* gl_error_2;
char* gl_error_3;
char* gl_error_4;
char* gl_error_5;
char* gl_error_6;

char* gl_save_sav;
char* gl_save_ing;

char* gl_save;
char* gl_auto_save;

char* gl_modeB_INITstr;
char* gl_modeB_RUMBLE;
char* gl_modeB_RAM;
char* gl_modeB_LINK;

char* gl_led;
char* gl_led_open;

char* gl_Breathing_light;
char* gl_SD_working;

char* gl_NOR_full;
char* gl_save_loaded;
char* gl_save_saved;
char* gl_file_exist;
char* gl_file_noexist;
//--
char** gl_rom_menu;
char** gl_nor_op;

char* gl_copying_data;

char* gl_enabled;
char* gl_disabled;

unsigned char* ASC_DATA;

// French
const char fr_init_error[] = "Initilization de la carte SD impossible.";
const char fr_power_off[] = "Eteignez la console.";
const char fr_init_ok[] = "Initilization de la carte SD reussie.";
const char fr_Loading[] = "Chargement...";
const char fr_file_overflow[] = "Fichier trop volumineux.";

const char fr_menu_btn[] = " (B)Non     (A)Oui";
const char fr_writing[] = "Ecriture...";
const char fr_lastest_game[] = "Selectionnez plus recent";

const char fr_time[] = "  Horloge";
const char fr_Mon[] = "Lun";
const char fr_Tues[] = "Mar";
const char fr_Wed[] = "Mer";
const char fr_Thur[] = "Jeu";
const char fr_Fri[] = "Ven";
const char fr_Sat[] = "Sam";
const char fr_Sun[] = "Dim";

const char fr_addon[] = "    Addon";
const char fr_reset[] = "Reset";
const char fr_rts[] = "Savestate";
const char fr_sleep[] = "Veille";
const char fr_cheat[] = "Cheat";

const char fr_hot_key[] = "   Veille";
const char fr_hot_key2[] = "     Menu";

const char fr_language[] = "   Langue";
const char fr_lang[] = "Francais";

const char fr_set_btn[] = "Mod.";
const char fr_ok_btn[] = " OK";
const char fr_formatnor_info[] = "Vous etes sur.e?";
const char fr_formatnor_info2[] = "Ca va etre long.";

const char fr_theme_credit[] = "Solarius v1.0";
const char fr_theme_credit2[] = "by Gencys.";

const char fr_check_sav[] = "Verification sauvegarde...";
const char fr_make_sav[] = "Creation sauvegarde...";

const char fr_check_RTS[] = "Verification fichier RTS...";
const char fr_make_RTS[] = "Creation fichier RTS...";

const char fr_check_pat[] = "Verification fichier Patch...";
const char fr_make_pat[] = "Creation fichier Patch...";

const char fr_please_wait[] = "Veuillez patienter...";

const char fr_loading_game[] = "Chargement...";

const char fr_no_roms[] = "Pas de ROM .gba trouve!";

const char fr_engine[] = "   Engine";
const char fr_use_engine[] = "Fast Patch Engine";

const char fr_recently_play[] = "Recemment joue";

const char fr_START_help[] = "Ouvrir liste Recemment joue";
const char fr_SELECT_help[] = "Plus d'options";
const char fr_L_A_help[] = "Inverser option demarrage";
const char fr_LSTART_help[] = "Suppr. fichier";
const char fr_LSELECT_help[] = "Suppr. sauvegarde";
const char fr_online_manual[] = "Manuel online";

const char fr_no_game_played[] = "Pas de jeu lance recemment...";

const char fr_ingameRTC[] = " Game RTC";
const char fr_ingameRTC_open[] = "Ouvrir";
const char fr_ingameRTC_close[] = "Fermer";  // TURNOFF TO POWER SAVE

const char fr_lang_toggle_reset[] = "HardReset";
const char fr_lang_toggle_backup[] = "Backup";

const char fr_error_0[] = "Erreur dossier";
const char fr_error_1[] = "Erreur fichier";
const char fr_error_2[] = "Erreur SAVER";
const char fr_error_3[] = "Erreur sauvegarde";
const char fr_error_4[] = "Erreur lecture sauvegarde";
const char fr_error_5[] = "Erreur de sauvegarde";
const char fr_error_6[] = "Erreur fichier RTS";

const char fr_save_sav[] = "Copier la sauvegarde?";
const char fr_save_ing[] = "Sauvegarde...";
const char fr_save[] = "   Sauver";
const char fr_auto_save[] = "Sauvegarde auto";

const char fr_modeB_INITstr[] = "   Mode B";
const char fr_modeB_RUMBLE[] = "Rumble";
const char fr_modeB_RAM[] = "RAM";
const char fr_modeB_LINK[] = "Cart";

const char fr_led[] = "      LED";
const char fr_led_open[] = "Activer LED";
const char fr_Breathing_light[] = "Respiration";
const char fr_SD_working[] = "     SD LED";

const char fr_NOR_full[] = "Memoire NOR pleine !  ";
const char fr_save_loaded[] = ".sav a ete charge";
const char fr_save_saved[] = ".sav sauvegarde";
const char fr_file_exist[] = "Ecraser le fichier?";
const char fr_file_noexist[] = "Fihier .sav inexistant";

const char fr_copying_data[] = "Copie de la ROM...";
const char fr_generating_emu[] = "Generation Emulateur...";

const char fr_enabled[] = "Activer";
const char fr_disabled[] = "Desactiver";

const char* fr_rom_menu[] = {
    "Lancer", "Lancer avec addon", "Copier vers NOR", "Copier vers NOR (addon)", "Type sauv.", "Cheat",
};
const char* fr_nor_op[5] = {
    "Lancer", "Supprimer", "Tout formater", "Charger la sauvergarde", "Copier la sauvegarde",
};

// English
const char en_init_error[] = "Failed to initialize microSD card.";
const char en_power_off[] = "Power off the console.";
const char en_init_ok[] = "microSD card initialization successful.";
const char en_Loading[] = "Loading...";
const char en_file_overflow[] = "The file is too big.";

const char en_menu_btn[] = " (B) No     (A) OK";
const char en_writing[] = "Writing...";
const char en_lastest_game[] = "Select the lastest";

const char en_time[] = "     Time";
const char en_Mon[] = "Mon";
const char en_Tues[] = "Tue";
const char en_Wed[] = "Wed";
const char en_Thur[] = "Thu";
const char en_Fri[] = "Fri";
const char en_Sat[] = "Sat";
const char en_Sun[] = "Sun";

const char en_addon[] = "    Addon";
const char en_reset[] = "Reset";
const char en_rts[] = "Savestate";
const char en_sleep[] = "Sleep";
const char en_cheat[] = "Cheat";

const char en_hot_key[] = "Sleep key";
const char en_hot_key2[] = " Menu key";

const char en_language[] = " Language";
const char en_lang[] = "English";

const char en_set_btn[] = "Set";
const char en_ok_btn[] = " OK";
const char en_formatnor_info1[] = "Are you sure?";
const char en_formatnor_info2[] = "This will take a while.";

const char en_theme_credit[] = "Solarius v1.0";
const char en_theme_credit2[] = "by Gencys.";

const char en_check_sav[] = "Checking Save Data...";
const char en_make_sav[] = "Creating Save Data...";

const char en_check_RTS[] = "Checking RTS file...";
const char en_make_RTS[] = "Creating RTS file...";

const char en_check_pat[] = "Checking Patch file...";
const char en_make_pat[] = "Creating Patch file...";

const char en_please_wait[] = "Please Wait...";

const char en_loading_game[] = "Loading ROM...";

const char en_no_roms[] = "No .gba ROMs found!";

const char en_engine[] = "   Engine";
const char en_use_engine[] = "Fast Patch Engine";

const char en_recently_play[] = "Recently Played";

const char en_START_help[] = "Open recently played list";
const char en_SELECT_help[] = "More options";
const char en_L_A_help[] = "Invert cold start option";
const char en_LSTART_help[] = "Delete file";
const char en_LSELECT_help[] = "Delete save file";
const char en_online_manual[] = "Online manual";

const char en_no_game_played[] = "No recently played games yet...";

const char en_ingameRTC[] = " Game RTC";
const char en_ingameRTC_open[] = "Open";
const char en_ingameRTC_close[] = "Close";  // TURNOFF TO POWER SAVE

const char en_lang_toggle_reset[] = "HardReset";
const char en_lang_toggle_backup[] = "Backup";

const char en_error_0[] = "Folder error";
const char en_error_1[] = "File error";
const char en_error_2[] = "SAVER error";
const char en_error_3[] = "Save error";
const char en_error_4[] = "Read save error";
const char en_error_5[] = "Make save error";
const char en_error_6[] = "RTS file error";

const char en_save_sav[] = "Copy game save?";
const char en_save_ing[] = "Saving...";
const char en_save[] = "     Save";
const char en_auto_save[] = "Auto save";

const char en_modeB_INITstr[] = "   Mode B";
const char en_modeB_RUMBLE[] = "Rumble";
const char en_modeB_RAM[] = "RAM";
const char en_modeB_LINK[] = "Cart";

const char en_led[] = "      LED";
const char en_led_open[] = "Enable LED";
const char en_Breathing_light[] = "Breathing";
const char en_SD_working[] = "   SD LED";

const char en_NOR_full[] = "NOR is full!          ";
const char en_save_loaded[] = ".sav has been loaded";
const char en_save_saved[] = ".sav has been saved";
const char en_file_exist[] = "Overwrite file?";
const char en_file_noexist[] = "Can't find .sav file";

const char en_copying_data[] = "Copying ROM...";
const char en_generating_emu[] = "Generating Emulator...";

const char en_enabled[] = "Enabled";
const char en_disabled[] = "Disabled";

const char* en_rom_menu[] = {
    "Clean boot", "Boot with addon", "Write to NOR clean", "Write to NOR with addon", "Save type", "Cheat",
};
const char* en_nor_op[5] = {
    "Direct boot", "Delete", "Format all", "Load save data", "Save save data",
};

//---------------------------------------------------------------------------------
void LoadFrench(void) {
   gl_init_error = (char*)fr_init_error;
   gl_power_off = (char*)fr_power_off;
   gl_init_ok = (char*)fr_init_ok;
   gl_Loading = (char*)fr_Loading;
   gl_file_overflow = (char*)fr_file_overflow;
   gl_theme_credit = (char*)fr_theme_credit;
   gl_theme_credit2 = (char*)fr_theme_credit2;

   gl_menu_btn = (char*)fr_menu_btn;
   gl_writing = (char*)fr_writing;
   gl_lastest_game = (char*)fr_lastest_game;

   gl_time = (char*)fr_time;
   gl_Mon = (char*)fr_Mon;
   gl_Tues = (char*)fr_Tues;
   gl_Wed = (char*)fr_Wed;
   gl_Thur = (char*)fr_Thur;
   gl_Fri = (char*)fr_Fri;
   gl_Sat = (char*)fr_Sat;
   gl_Sun = (char*)fr_Sun;

   gl_addon = (char*)fr_addon;
   gl_reset = (char*)fr_reset;
   gl_rts = (char*)fr_rts;
   gl_sleep = (char*)fr_sleep;
   gl_cheat = (char*)fr_cheat;

   gl_hot_key = (char*)fr_hot_key;
   gl_hot_key2 = (char*)fr_hot_key2;

   gl_language = (char*)fr_language;
   gl_en_lang = (char*)en_lang;
   gl_fr_lang = (char*)fr_lang;
   ;
   gl_set_btn = (char*)fr_set_btn;
   gl_ok_btn = (char*)fr_ok_btn;
   gl_formatnor_info1 = (char*)fr_formatnor_info;
   gl_formatnor_info2 = (char*)fr_formatnor_info2;

   temp = " ";

   gl_check_sav = (char*)fr_check_sav;
   gl_make_sav = (char*)fr_make_sav;

   gl_check_RTS = (char*)fr_check_RTS;
   gl_make_RTS = (char*)fr_make_RTS;

   gl_check_pat = (char*)fr_check_pat;
   gl_make_pat = (char*)fr_make_pat;

   gl_loading_game = (char*)fr_loading_game;
   gl_engine = (char*)fr_engine;
   gl_use_engine = (char*)fr_use_engine;

   gl_recently_play = (char*)fr_recently_play;

   gl_START_help = (char*)fr_START_help;
   gl_SELECT_help = (char*)fr_SELECT_help;
   gl_L_A_help = (char*)fr_L_A_help;
   gl_LSTART_help = (char*)fr_LSTART_help;
   gl_online_manual = (char*)fr_online_manual;

   gl_no_game_played = (char*)fr_no_game_played;

   gl_ingameRTC = (char*)fr_ingameRTC;
   // gl_offRTC_powersave = (char*)fr_offRTC_powersave;
   gl_ingameRTC_open = (char*)fr_ingameRTC_open;
   gl_ingameRTC_close = (char*)fr_ingameRTC_close;

   gl_lang_toggle_reset = (char*)fr_lang_toggle_reset;
   gl_lang_toggle_backup = (char*)fr_lang_toggle_backup;

   gl_error_0 = (char*)fr_error_0;
   gl_error_1 = (char*)fr_error_1;
   gl_error_2 = (char*)fr_error_2;
   gl_error_3 = (char*)fr_error_3;
   gl_error_4 = (char*)fr_error_4;
   gl_error_5 = (char*)fr_error_5;
   gl_error_6 = (char*)fr_error_6;

   gl_save_sav = (char*)fr_save_sav;
   gl_save_ing = (char*)fr_save_ing;
   gl_save = (char*)fr_save;
   gl_auto_save = (char*)fr_auto_save;

   gl_modeB_INITstr = (char*)fr_modeB_INITstr;
   gl_modeB_RUMBLE = (char*)fr_modeB_RUMBLE;
   gl_modeB_RAM = (char*)fr_modeB_RAM;
   gl_modeB_LINK = (char*)fr_modeB_LINK;

   gl_led = (char*)fr_led;
   gl_led_open = (char*)fr_led_open;

   gl_Breathing_light = (char*)fr_Breathing_light;
   gl_SD_working = (char*)fr_SD_working;

   gl_NOR_full = (char*)fr_NOR_full;
   gl_save_loaded = (char*)fr_save_loaded;
   gl_save_saved = (char*)fr_save_saved;
   gl_file_exist = (char*)fr_file_exist;
   gl_file_noexist = (char*)fr_file_noexist;
   //
   gl_rom_menu = (char**)fr_rom_menu;
   gl_nor_op = (char**)fr_nor_op;

   gl_copying_data = (char*)fr_copying_data;

   gl_generating_emu = (char*)fr_generating_emu;

   gl_enabled = (char*)fr_enabled;
   gl_disabled = (char*)fr_disabled;

   ASC_DATA = (unsigned char*)ASC_DATA_NEW;
}
//---------------------------------------------------------------------------------
void LoadEnglish(void) {
   gl_init_error = (char*)en_init_error;
   gl_power_off = (char*)en_power_off;
   gl_init_ok = (char*)en_init_ok;
   gl_Loading = (char*)en_Loading;
   gl_file_overflow = (char*)en_file_overflow;
   gl_theme_credit = (char*)en_theme_credit;
   gl_theme_credit2 = (char*)en_theme_credit2;

   gl_menu_btn = (char*)en_menu_btn;
   gl_writing = (char*)en_writing;
   gl_lastest_game = (char*)en_lastest_game;

   gl_time = (char*)en_time;
   gl_Mon = (char*)en_Mon;
   gl_Tues = (char*)en_Tues;
   gl_Wed = (char*)en_Wed;
   gl_Thur = (char*)en_Thur;
   gl_Fri = (char*)en_Fri;
   gl_Sat = (char*)en_Sat;
   gl_Sun = (char*)en_Sun;
   gl_addon = (char*)en_addon;
   gl_reset = (char*)en_reset;
   gl_rts = (char*)en_rts;
   gl_sleep = (char*)en_sleep;
   gl_cheat = (char*)en_cheat;

   gl_hot_key = (char*)en_hot_key;
   gl_hot_key2 = (char*)en_hot_key2;

   gl_language = (char*)en_language;
   gl_en_lang = (char*)en_lang;
   gl_fr_lang = (char*)fr_lang;
   ;
   gl_set_btn = (char*)en_set_btn;
   gl_ok_btn = (char*)en_ok_btn;
   gl_formatnor_info1 = (char*)en_formatnor_info1;
   gl_formatnor_info2 = (char*)en_formatnor_info2;

   temp = "Sure? about 4 mins";

   gl_check_sav = (char*)en_check_sav;
   gl_make_sav = (char*)en_make_sav;

   gl_check_RTS = (char*)en_check_RTS;
   gl_make_RTS = (char*)en_make_RTS;

   gl_check_pat = (char*)en_check_pat;
   gl_make_pat = (char*)en_make_pat;

   gl_loading_game = (char*)en_loading_game;

   gl_engine = (char*)en_engine;
   gl_use_engine = (char*)en_use_engine;

   gl_recently_play = (char*)en_recently_play;

   gl_START_help = (char*)en_START_help;
   gl_SELECT_help = (char*)en_SELECT_help;
   gl_L_A_help = (char*)en_L_A_help;
   gl_LSTART_help = (char*)en_LSTART_help;
   gl_online_manual = (char*)en_online_manual;

   gl_no_game_played = (char*)en_no_game_played;

   gl_ingameRTC = (char*)en_ingameRTC;
   // gl_offRTC_powersave = (char*)en_offRTC_powersave;
   gl_ingameRTC_open = (char*)en_ingameRTC_open;
   gl_ingameRTC_close = (char*)en_ingameRTC_close;

   gl_lang_toggle_reset = (char*)en_lang_toggle_reset;
   gl_lang_toggle_backup = (char*)en_lang_toggle_backup;

   gl_error_0 = (char*)en_error_0;
   gl_error_1 = (char*)en_error_1;
   gl_error_2 = (char*)en_error_2;
   gl_error_3 = (char*)en_error_3;
   gl_error_4 = (char*)en_error_4;
   gl_error_5 = (char*)en_error_5;
   gl_error_6 = (char*)en_error_6;

   gl_save_sav = (char*)en_save_sav;
   gl_save_ing = (char*)en_save_ing;
   gl_save = (char*)en_save;
   gl_auto_save = (char*)en_auto_save;

   gl_modeB_INITstr = (char*)en_modeB_INITstr;
   gl_modeB_RUMBLE = (char*)en_modeB_RUMBLE;
   gl_modeB_RAM = (char*)en_modeB_RAM;
   gl_modeB_LINK = (char*)en_modeB_LINK;

   gl_led = (char*)en_led;
   gl_led_open = (char*)en_led_open;
   gl_Breathing_light = (char*)en_Breathing_light;
   gl_SD_working = (char*)en_SD_working;

   gl_NOR_full = (char*)en_NOR_full;
   gl_save_loaded = (char*)en_save_loaded;
   gl_save_saved = (char*)en_save_saved;
   gl_file_exist = (char*)en_file_exist;
   gl_file_noexist = (char*)en_file_noexist;
   //
   gl_rom_menu = (char**)en_rom_menu;
   gl_nor_op = (char**)en_nor_op;

   gl_copying_data = (char*)en_copying_data;

   gl_generating_emu = (char*)en_generating_emu;

   gl_enabled = (char*)en_enabled;
   gl_disabled = (char*)en_disabled;

   // For English, Use new font
   ASC_DATA = (unsigned char*)ASC_DATA_NEW;
}
