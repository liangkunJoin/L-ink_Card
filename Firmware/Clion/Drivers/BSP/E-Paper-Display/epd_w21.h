#ifndef _DISPLAY_EPD_W21_H_
#define _DISPLAY_EPD_W21_H_

#include <sched.h>

#define xDot 200
#define yDot 200

#define UBYTE   uint8_t
#define UWORD   uint16_t
#define UDOUBLE uint32_t

extern void DriverDelay(unsigned long xms);

extern void moduleInit(void);

extern void EpdW21Init(void);

extern void EpdW21Display(uint8_t *Image);

extern void EpdW21Clear(void);

extern void SpiWrite(unsigned char value);

#define EPD_W21_MOSI_0    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET)
#define EPD_W21_MOSI_1    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET)

#define EPD_W21_CLK_0    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_RESET)
#define EPD_W21_CLK_1    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET)

#define EPD_W21_CS_0    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_RESET)
#define EPD_W21_CS_1    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_SET)

#define EPD_W21_DC_0    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET)
#define EPD_W21_DC_1    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET)

#define EPD_W21_RST_0    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET)
#define EPD_W21_RST_1    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET)


#define EPD_W21_BUSY_LEVEL 0
#define isEPD_W21_BUSY HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8)

#endif
/***********************************************************
						end file
***********************************************************/


