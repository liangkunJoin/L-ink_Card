#ifndef _DISPLAY_EPD_W21_CONFIG_H_
#define _DISPLAY_EPD_W21_CONFIG_H_

#include "epd_w21.h"




unsigned char swreset[] = {0x12};
unsigned char driverOutputControl[]={0x01, 0xC7, 0x00, 0x01};
unsigned char dataEntryMode[] = {0x11, 0x01};
unsigned char ram_x_address_start_end_position[] = {0x44, 0x00, 0X18};
unsigned char ram_y_address_start_end_position[] = {0x45, 0Xc7, 0x00, 0x00, 0x00};  // 0Xc7 = 199
unsigned char borderWavefrom[] = {0x3C, 0x01};
unsigned char unkonwCommand[] = {0x18, 0x80};
unsigned char loadTemperatureAndWaveformSetting[] = {0x22, 0XB1};
unsigned char turnOnDisplay[] = {0x22, 0xc7};
unsigned char masterActivation[] = {0x20};
unsigned char ram_x_address_counter[] = {0x4e, 0x00};
unsigned char ram_y_address_counter[] = {0x4f, 0Xc7, 0x00};
unsigned char lut_normal[] = {0x32,
        0x80,	0x48,	0x40,	0x0,	0x0,	0x0,	0x0,	0x0,
        0x0,	0x0,    0x0,	0x0,    0x40,	0x48,	0x80,	0x0,
        0x0,	0x0,	0x0,	0x0,    0x0,	0x0,	0x0,	0x0,
        0x80,	0x48,	0x40,	0x0,	0x0,	0x0,    0x0,	0x0,
        0x0,	0x0,	0x0,	0x0,    0x40,	0x48,	0x80,	0x0,
        0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,
        0x0,	0x0,    0x0,	0x0,	0x0,	0x0,	0x0,	0x0,
        0x0,	0x0,	0x0,	0x0,    0xA,	0x0,	0x0,	0x0,
        0x0,	0x0,	0x0,    0x8,	0x1,	0x0,    0x8,	0x1,
        0x0,	0x2,    0xA,	0x0,	0x0,	0x0,	0x0,	0x0,
        0x0,    0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,
        0x0,	0x0,    0x0,	0x0,	0x0,	0x0,	0x0,    0x0,
        0x0,	0x0,	0x0,	0x0,    0x0,	0x0,    0x0,	0x0,
        0x0,	0x0,	0x0,	0x0,	0x0,    0x0,    0x0,	0x0,
        0x0,	0x0,	0x0,	0x0,    0x0,	0x0,	0x0,	0x0,
        0x0,	0x0,	0x0,    0x0,	0x0,	0x0,	0x0,	0x0,
        0x0,	0x0,    0x0,	0x0,	0x0,	0x0,	0x0,	0x0,
        0x0,    0x0,	0x0,	0x0,    0x0,	0x0,	0x0,	0x0,
        0x22,	0x22,	0x22,	0x22,	0x22,	0x22,   0x0,	0x0,
        0x0
};

unsigned char lut_0x3f[] = {0x3f, 0x22};
unsigned char lut_0x03[] = {0x03, 0x17};
unsigned char lut_0x04[] = {0x04, 0x41,	0x0,	0x32};
unsigned char lut_0x2c[] = {0x2c, 0x20};

#endif

