#include "./headers/ultrasonic_sensor/ultrasonic_sensor.h"

#if (ULTRASONIC_CONFIGURATION == CONFIG_ENABLE) 
    STD_RETURNTYPE ultrasonic_initialize(ultrasonic_t* sonic){
        STD_RETURNTYPE ret = E_OK;
        if(!sonic)
            ret = E_NOT_OK;
        else{
            pinMode(sonic->trig,OUTPUT);
            pinMode(sonic->echo,INPUT);
            digitalWrite(sonic->trig,LOW);
            delayMicroseconds(BROCHE_TRIGGER);
        }
        return ret;
    }
#endif

#if (ULTRASONIC_CONFIGURATION == CONFIG_ENABLE) 
    STD_RETURNTYPE ultrasonic_distance(ultrasonic_t* sonic,dec32* distance){
        STD_RETURNTYPE ret = E_OK;
        if(!sonic)
            ret = E_NOT_OK;
        else{
            dec32 time = 0;
            digitalWrite(sonic->trig,HIGH);
            delayMicroseconds(BROCHE_TRIGGER);
            digitalWrite(sonic->trig,LOW);
            time = pulseIn(sonic->echo,HIGH);
            *distance = DISTANCE(SOUND_SPEED,time);
        }
        return ret;
    }
#endif