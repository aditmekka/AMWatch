#include <Arduino.h>
#include <ui.h>
#include <lvgl.h>
#include "btn.h"

void btnSetup(){
    pinMode(navUp, INPUT_PULLUP);
    pinMode(navSelect, INPUT_PULLUP);
    pinMode(navDown, INPUT_PULLUP);
    pinMode(volUp, INPUT_PULLUP);
    pinMode(volDown, INPUT_PULLUP);
    pinMode(navExit, INPUT_PULLUP);
}

void changeScreen(lv_obj_t *newScreen){
  lv_scr_load_anim(newScreen, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, false);
}

void previousScreen(lv_obj_t *prevScreen){
  lv_scr_load_anim(prevScreen, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0, false);
}

void debounce(){
  delay(300);
}

void btnHandler(){
    int navUpState = digitalRead(navUp);
    int navSelectState = digitalRead(navSelect);
    int navDownState = digitalRead(navDown);
    int volUpState = digitalRead(volUp);
    int volDownState = digitalRead(volDown);
    int navExitState = digitalRead(navExit);

    int menuSelected = lv_roller_get_selected(ui_menuRoller);

    lv_obj_t *currentScreen = lv_scr_act();

    if(navSelectState == LOW){
      if(currentScreen == ui_clockScreen){
        lv_scr_load_anim(ui_menuScreen, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, false);
      }else if(currentScreen == ui_menuScreen){
        int selectedOpt = lv_roller_get_selected(ui_menuRoller);
        switch(selectedOpt){
          case 0:
            changeScreen(ui_clockScreen);
            break;
          case 1:
            changeScreen(ui_spotifyScreen);
            break;
          case 2:
            changeScreen(ui_blynkScreen);
            break;
          case 3:
            changeScreen(ui_calendarScreen);
            break;
          case 4:
            changeScreen(ui_aboutScreen);
            break;
          case 5:
            changeScreen(ui_clockScreen);
            break;
        }
      }
      debounce();
    }

    if(navUpState == LOW){
      if(currentScreen == ui_menuScreen){
        lv_roller_set_selected(ui_menuRoller, (menuSelected - 1) % 6, LV_ANIM_ON);
      }
      debounce();
    }

    if(navDownState == LOW){
      if(currentScreen == ui_menuScreen){
        lv_roller_set_selected(ui_menuRoller, (menuSelected + 1) % 6, LV_ANIM_ON);
      }
      debounce();
    }

    if(navExitState == LOW && currentScreen != ui_clockScreen){
      if(currentScreen != ui_menuScreen){
        previousScreen(ui_menuScreen);
      }else if(currentScreen = ui_menuScreen){
        previousScreen(ui_clockScreen);
      }
      debounce();
    }
}