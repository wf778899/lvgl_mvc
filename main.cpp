#include "resource.h"

#include <lvgl/lvgl.h>
#include <lv_drivers/win32drv/win32drv.h>

#include <Windows.h>


bool single_display_mode_initialization()
{
    if (!lv_win32_init(
        GetModuleHandleW(NULL),
        SW_SHOW,
        800,
        480,
        LoadIconW(GetModuleHandleW(NULL), MAKEINTRESOURCE(IDI_LVGL))))
    {
        return false;
    }

    lv_win32_add_all_input_devices_to_group(NULL);

    return true;
}

int main()
{
	lv_init();

    if (!single_display_mode_initialization())
    {
        return -1;
    }

    while (!lv_win32_quit_signal)
    {
        lv_task_handler();
        Sleep(1);
    }

	return 0;
}