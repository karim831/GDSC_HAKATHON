#ifndef _APPLICATION_H_
#define _APPLICATION_H_
/*  section : includes   */
#include "./ultrasonic_sensor/ultrasonic_sensor.h"
#include "./sv_seg_dec/sv_seg_dec.h"
/*  section : macro declaration */
#define SYS_SEV_MAX_NUMBER   0x1E
#define SYSTEM_ONE_SEC       0x7D

#define PIN0                 0x00
#define PIN1                 0x01
#define PIN2                 0x02
#define PIN3                 0x03
#define PIN4                 0x04
#define PIN5                 0x05
#define PIN6                 0x06
#define PIN7                 0x07
#define PIN8                 0x08
#define PIN9                 0x09
#define PIN10                 0x0A
#define PIN11                 0x0B
#define PIN12                 0x0C
#define PIN13                 0x0D


/*  section : macro function declaration    */

/*  section : userdata type defination  */

/*  section : function declaration  */
void digit_activion(uint8 digit);
#endif