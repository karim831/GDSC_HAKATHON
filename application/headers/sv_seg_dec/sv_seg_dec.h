#ifndef _SV_SEG_DEC_H_
#define _SV_SEG_DEC_H_
/*  section : includes   */
#include <Arduino.h>
#include "sv_seg_config.h"
/*  section : macro declaration */
#define SEV_MIN_NUMBER          0x00
#define SEV_MAX_NUMBER          0x09

#define SEV_ENABLE              0x00 //for left or the right of seven
#define SEV_DISABLE             0x01
#define SEV_MAX_PINS            0x04

/*  section : macro function declaration    */
#define READ_BIT(NUMBER,PIN_ORG)    ((BIT_MASK) & ((NUMBER)>>PIN_ORG))

#define RIGHT_DIGIT(NUMBER)    ((NUMBER)%10) 
#define LEFT_DIGIT(NUMBER)     ((NUMBER)/10)
/*  section : userdata type defination  */
typedef struct{ // from most_sig to least_sig
    uint8 sev_pins[SEV_MAX_PINS];
}sev_seg_t;
/*  section : function declaration  */
STD_RETURNTYPE sev_seg_initialize(sev_seg_t* dec);
STD_RETURNTYPE sev_seg_write_number(sev_seg_t* dec,uint8 number);
STD_RETURNTYPE sev_seg_stop(sev_seg_t* dec);
#endif