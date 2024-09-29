#ifndef RTC_H
#define RTC_H

#include <RTClib.h>
#include <Wire.h>

extern RTC_DS3231 rtc;

void rtcSetup();

#endif