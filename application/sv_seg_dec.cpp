#include "./headers/sv_seg_dec/sv_seg_dec.h"

#if (SEV_SEG_CONFIGURATION == CONFIG_ENABLE)
    STD_RETURNTYPE sev_seg_initialize(sev_seg_t* dec){
        STD_RETURNTYPE ret = E_OK;
        if(!dec)
            ret = E_NOT_OK;
        else{
            for(uint8 i=0;i<SEV_MAX_PINS;i++){
                pinMode(dec->sev_pins[i],OUTPUT);
                digitalWrite(dec->sev_pins[i],LOW);
            }
        }
        return ret;
    }
#endif;

#if (SEV_SEG_CONFIGURATION == CONFIG_ENABLE)
    STD_RETURNTYPE sev_seg_write_number(sev_seg_t* dec,uint8 number){
        STD_RETURNTYPE ret = E_OK;
        if(!dec && number<=SEV_MAX_NUMBER && number >= SEV_MIN_NUMBER)
            ret = E_NOT_OK;
        else{
            for(uint8 i=0;i<SEV_MAX_PINS;i++){
                digitalWrite(dec->sev_pins[i],READ_BIT(number,i));
            }
        }
        return ret;
    }
#endif;