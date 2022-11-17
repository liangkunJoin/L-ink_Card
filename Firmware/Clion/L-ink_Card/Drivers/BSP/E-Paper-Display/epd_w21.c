#include "epd_w21.h"
#include "stm32l0xx_hal.h"
#include "Debug.h"
#include "stdio.h"
#include "epd_w21_config.h"


void DriverDelay(unsigned long xms)
{
    HAL_Delay(xms);
}

void SpiDelay(unsigned char xrate)
{
    unsigned char i;
    while (xrate)
    {
        for (i = 0; i < 1; i++);
        xrate--;
    }
}

void SpiWrite(unsigned char value)
{
    unsigned char i;

    SpiDelay(1);
    for (i = 0; i < 8; i++)
    {
        EPD_W21_CLK_0;
        SpiDelay(1);
        if (value & 0x80)
            EPD_W21_MOSI_1;
        else
            EPD_W21_MOSI_0;
        value = (value << 1);
        SpiDelay(1);
        EPD_W21_CLK_1;
        SpiDelay(1);
    }
}

static void EpdW21WriteCommand(unsigned char value)
{
    EPD_W21_CS_0;
    EPD_W21_DC_0; // command write

    SpiWrite(value);

    EPD_W21_CS_1;
}

static void EpdW21WriteData(unsigned char data)
{
    EPD_W21_CS_0;
    EPD_W21_DC_1; // command data

    SpiWrite(data);

    EPD_W21_CS_1;
}

static void EpdW21Write(unsigned char *value, unsigned char datalen)
{
    unsigned char i = 0;
    unsigned char *ptemp;

    ptemp = value;

    EPD_W21_CS_0;
    EPD_W21_DC_0; // command write

    SpiWrite(*ptemp);
    ptemp++;

    EPD_W21_DC_1; //data write

    for (i = 0; i < datalen - 1; i++)
    {
        SpiWrite(*ptemp);
        ptemp++;
    }

    EPD_W21_CS_1;
}

static void ReadBusy(void)
{
    Debug("e-Paper busy\r\n");
    while (isEPD_W21_BUSY != EPD_W21_BUSY_LEVEL)  //LOW: idle, HIGH: busy
    {
        DriverDelay(10);
    }
    Debug("e-Paper busy release\r\n");
}

static void EpdW21Reset(void)
{
    EPD_W21_RST_1;
    DriverDelay(200);
    EPD_W21_RST_0;
    DriverDelay(2);
    EPD_W21_RST_1;
    DriverDelay(200);
}

static void EpdW21SetWindows(void)
{
    EpdW21Write(ram_x_address_start_end_position, sizeof(ram_x_address_start_end_position));
    EpdW21Write(ram_y_address_start_end_position, sizeof(ram_y_address_start_end_position));
}

static void EpdW21SetCursor(void)
{
    EpdW21Write(ram_x_address_counter, sizeof(ram_x_address_counter));
    EpdW21Write(ram_y_address_counter, sizeof(ram_y_address_counter));
}

static void EpdW21SetLut(void)
{
    EpdW21Write(lut_normal, sizeof(lut_normal));
    ReadBusy();
    EpdW21Write(lut_0x3f, sizeof(lut_0x3f));
    EpdW21Write(lut_0x03, sizeof(lut_0x03));
    EpdW21Write(lut_0x04, sizeof(lut_0x04));
    EpdW21Write(lut_0x2c, sizeof(lut_0x2c));
}

static void EpdW21DispInit(void)
{
    ReadBusy();
    EpdW21Write(swreset, sizeof(swreset));
    ReadBusy();
    EpdW21Write(driverOutputControl, sizeof(driverOutputControl));
    EpdW21Write(dataEntryMode, sizeof(dataEntryMode));
    EpdW21SetWindows();
    EpdW21Write(borderWavefrom, sizeof(borderWavefrom));
    EpdW21Write(unkonwCommand, sizeof(unkonwCommand));
    EpdW21Write(loadTemperatureAndWaveformSetting, sizeof(loadTemperatureAndWaveformSetting));
    EpdW21Write(masterActivation, sizeof(masterActivation));
    EpdW21SetCursor();
    ReadBusy();
    EpdW21SetLut();
}

// Module init
void moduleInit(void){
    EPD_W21_DC_0;
    EPD_W21_CS_0;
    EPD_W21_RST_1;
}

// Module reset
void EpdW21Init(void)
{
    EpdW21Reset();
    EpdW21DispInit();
}

void EpdW21Clear(void)
{
    UWORD Width, Height;
    Width = (xDot % 8 == 0) ? (xDot / 8 ): (xDot / 8 + 1);
    Height = yDot;

    EpdW21WriteCommand(0x24);
    for (UWORD j = 0; j < Height; j++) {
        for (UWORD i = 0; i < Width; i++) {
            EpdW21WriteData(0XFF);
        }
    }

    EpdW21WriteCommand(0x26);
    for (UWORD j = 0; j < Height; j++) {
        for (UWORD i = 0; i < Width; i++) {
            EpdW21WriteData(0XFF);
        }
    }

    // TurnOnDisplay
    EpdW21Write(turnOnDisplay, sizeof(turnOnDisplay));
    EpdW21Write(masterActivation, sizeof(masterActivation));
    ReadBusy();
}

void EpdW21Display(unsigned char *Image)
{
    UWORD Width, Height;
    Width = (xDot % 8 == 0)? (xDot / 8 ) : (xDot / 8 + 1);
    Height = yDot;

    UDOUBLE Addr = 0;
    EpdW21WriteCommand(0x24);
    for (UWORD j = 0; j < Height; j++) {
        for (UWORD i = 0; i < Width; i++) {
            Addr = i + j * Width;
            EpdW21WriteData(Image[Addr]);
        }
    }

    // TurnOnDisplay
    EpdW21Write(turnOnDisplay, sizeof(turnOnDisplay));
    EpdW21Write(masterActivation, sizeof(masterActivation));
    ReadBusy();
}



