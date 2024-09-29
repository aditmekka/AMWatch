#include <Arduino.h>
#include <ui.h>
#include <lvgl.h>
#include "clock.h"
#include "rtc.h"

// Helper function to animate text change
void anim_text_cb(void *label, int32_t v)
{
    char buf[2];
    sprintf(buf, "%01d", v);  // Convert the number to a single digit
    lv_label_set_text((lv_obj_t *)label, buf);
}

// Function to apply animation on the text
void animate_digit_change(lv_obj_t *label, int old_digit, int new_digit, uint16_t anim_time = 500)
{
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, label);
    lv_anim_set_values(&a, old_digit, new_digit);  // From old digit to new digit
    lv_anim_set_time(&a, anim_time);               // Animation time (500ms for example)
    lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)anim_text_cb);  // Animation callback
    lv_anim_start(&a);
}

void loadMainClock() {
    DateTime now = rtc.now();

    int hour = now.hour();
    int min = now.minute();
    int sec = now.second();

    static int old_hour = -1, old_min = -1, old_sec = -1;  // Keep track of old values

    // Update hour if changed
    if (hour != old_hour) {
        animate_digit_change(ui_firstDigitHour, old_hour / 10, hour / 10);  // First digit of the hour
        animate_digit_change(ui_secondDigitHour, old_hour % 10, hour % 10); // Second digit of the hour
        old_hour = hour;
    }

    // Update minutes if changed
    if (min != old_min) {
        animate_digit_change(ui_firstDigitMin, old_min / 10, min / 10);  // First digit of the minute
        animate_digit_change(ui_secondDigitMin, old_min % 10, min % 10); // Second digit of the minute
        old_min = min;
    }

    // Update seconds if changed
    if (sec != old_sec) {
        animate_digit_change(ui_firstDigitSec, old_sec / 10, sec / 10);  // Tens digit of seconds
        animate_digit_change(ui_secondDigitSec, old_sec % 10, sec % 10); // Ones digit of seconds
        old_sec = sec;
    }
}
