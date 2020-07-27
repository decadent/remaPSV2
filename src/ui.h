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
#define CREDITS_NUM			16
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

#define MAIN_MENU_NUM 9
#define REMAP_MENU_NUM 1
#define ANALOG_MENU_NUM 10
#define TOUCH_MENU_NUM 20
#define GYRO_MENU_NUM 11
#define SETTINGS_MENU_NUM 4
#define PROFILE_MENU_NUM 8
#define HOOKS_MENU_NUM 18
#define CONTROLLERS_MENU_NUM 3
#define REMAP_TRIGGER_GROUP_SUB_NUM 9
#define REMAP_TRIGGER_BTN_SUB_NUM 16
#define REMAP_TRIGGER_ANALOG_SUB_NUM 4
#define REMAP_TRIGGER_TOUCH_SUB_NUM 4
#define REMAP_TRIGGER_GYRO_SUB_NUM 6

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