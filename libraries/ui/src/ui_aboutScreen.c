// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.2
// LVGL version: 8.3.6
// Project name: watchBeta

#include "ui.h"

void ui_aboutScreen_screen_init(void)
{
    ui_aboutScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_aboutScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label4 = lv_label_create(ui_aboutScreen);
    lv_obj_set_width(ui_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label4, 0);
    lv_obj_set_y(ui_Label4, -80);
    lv_obj_set_align(ui_Label4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label4, "About");

    ui_label12 = lv_label_create(ui_aboutScreen);
    lv_obj_set_width(ui_label12, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_label12, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_label12, 0);
    lv_obj_set_y(ui_label12, -35);
    lv_obj_set_align(ui_label12, LV_ALIGN_CENTER);
    lv_label_set_text(ui_label12, "AMWatch");

    ui_label1 = lv_label_create(ui_aboutScreen);
    lv_obj_set_width(ui_label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_label1, "https://github.com/aditmekka");

    ui_label2 = lv_label_create(ui_aboutScreen);
    lv_obj_set_width(ui_label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_label2, 0);
    lv_obj_set_y(ui_label2, 35);
    lv_obj_set_align(ui_label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_label2, "asheraaa");

    ui_label3 = lv_label_create(ui_aboutScreen);
    lv_obj_set_width(ui_label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_label3, 0);
    lv_obj_set_y(ui_label3, 80);
    lv_obj_set_align(ui_label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_label3, "V0.2_alpha");

}
