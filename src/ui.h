#ifndef _UI_H_
#define _UI_H_

;enum MENU_IDS{
	MAIN_MENU = 0,
	REMAP_MENU,
	ANALOG_MENU,
	TOUCH_MENU,
	GYRO_MENU,
	CNTRL_MENU,
	HOOKS_MENU,
	SETTINGS_MENU,
	CREDITS_MENU,
	PROFILES_MENU,
	REMAP_LIST,
	REMAP_NEW_TRIGGER_GROUP_SUB,
	REMAP_NEW_TRIGGER_BTN_SUB,
	REMAP_NEW_TRIGGER_COMBO_SUB,
	REMAP_NEW_TRIGGER_ANALOG_SUB,
	REMAP_NEW_TRIGGER_TOUCH_SUB,
	REMAP_NEW_TRIGGER_GYRO_SUB,
	REMAP_NEW_EMU_GROUP_SUB,
	REMAP_NEW_EMU_BTN_SUB,
	REMAP_NEW_EMU_COMBO_SUB,
	REMAP_NEW_EMU_ANALOG_SUB,
	REMAP_NEW_EMU_DIGITAL_ANALOG_SUB,
	REMAP_NEW_EMU_TOUCH_SUB
}MENU_IDS;

enum PROFILE_ACTIONS{
	PROFILE_GLOBAL_SAVE = 0,
	PROFILE_GLOABL_LOAD,
	PROFILE_GLOBAL_DELETE,
	PROFILE_LOCAL_SAVE,
	PROFILE_LOCAL_LOAD,
	PROFILE_LOCAL_DELETE
}PROFILE_ACTIONS;

#define MENU_MODES          23  // Menu modes num
#define HEADER_IDX          -1
#define TEXT_IDX            -2

typedef struct Menu{
	uint8_t id;
	uint8_t num;
	uint8_t idx;
	char* name;
	struct MenuEntry* entries;
}Menu;
typedef struct MenuEntry{
	char* name;
	int8_t id;
} MenuEntry;

extern uint8_t ui_opened;
extern uint8_t ui_lines;
extern uint8_t new_frame;
Menu* ui_menu;
MenuEntry* ui_entry;

void ui_setMenu(int menuId);
void ui_nextEntry();
void ui_prevEntry();
extern void ui_draw(const SceDisplayFrameBuf *pParam);
extern void ui_open();
extern void ui_init();
extern void ui_destroy();

void ui_setIdx(int i);

#endif