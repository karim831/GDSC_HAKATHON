#ifndef _ULTRASONIC_SENSOR_H_
#define _ULTRASONIC_SENSOR_H_

/*  section : includes   */
#include <Arduino.h>
#include "ultrasonic_config.h"
/*  section : macro declaration */
#define     MINIMUM_DISTANCE    2       //cm
#define     MAXIMUM_DISTANCE    400     //cm
#define     SELECTED_DISTANCE   40      //cm

#define     SOUND_SPEED         .0351   //cm/us
#define     BROCHE_TRIGGER      10      //us  time for trig to be high
#define     SIGNAL_FREQUENCY    40      //khz eight pulses frequency
#define     SIGNAL_PERIOD       25      //us  eight pulses period
#define     SINGAL_WIDTH        12.5      //us  eight pulse width (approximetly half cycle) => SIGNAL_PERIOD/=2 => 12.5
/*  section : macro function declaration    */
#define     DISTANCE(SOUND_SPEED,FULL_TIME_ECHO_TRIGGERD)   (SOUND_SPEED*(FULL_TIME_ECHO_TRIGGERD/2.0))
/*  section : userdata type defination  */
typedef struct{
    uint8 trig;
    uint8 echo;
}ultrasonic_t;
/*  section : function declaration  */
STD_RETURNTYPE ultrasonic_initialize(ultrasonic_t* sonic);
STD_RETURNTYPE ultrasonic_distance(ultrasonic_t* sonic,dec32* distance);
#endif