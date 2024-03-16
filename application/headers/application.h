#ifndef _APPLICATION_H_
#define _APPLICATION_H_
/*  section : includes   */
#include "./ultrasonic_sensor/ultrasonic_sensor.h"
#include "./sv_seg_dec/sv_seg_dec.h"
/*  section : macro declaration */
#define SYS_SEV_MAX_NUMBER   0x1E
#define SYSTEM_ONE_SEC       0x7D
/*  section : macro function declaration    */

/*  section : userdata type defination  */

/*  section : function declaration  */
void digit_activion(uint8 digit);
#endif