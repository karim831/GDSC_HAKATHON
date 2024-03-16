#include "./headers/application.h"
sev_seg_t seven = {
    .sev_pins = {2,3,4,5}
};

uint8 left_v = 6;
uint8 right_v = 7;
uint8 left_h = 8;
uint8 right_h = 9;

uint8 ver_number = SYS_SEV_MAX_NUMBER;
uint8 hor_number = 0;
uint8 turn = 0;
uint8 counter = 0;
void setup(){
    pinMode(left_v,OUTPUT);
    pinMode(right_v,OUTPUT);
    pinMode(left_h,OUTPUT);
    pinMode(right_h,OUTPUT);

    sev_seg_initialize(&seven);
    digitalWrite(left_v,SEV_DISABLE);
    digitalWrite(right_v,SEV_DISABLE);
    digitalWrite(left_h,SEV_DISABLE);
    digitalWrite(right_h,SEV_DISABLE);
    Serial.begin(9600);
}
void loop(){
    sev_seg_write_number(&seven,RIGHT_DIGIT(ver_number));
    digit_activion(right_v);
    sev_seg_write_number(&seven,LEFT_DIGIT(ver_number));
    digit_activion(left_v);
    sev_seg_write_number(&seven,RIGHT_DIGIT(hor_number));
    digit_activion(right_h);
    sev_seg_write_number(&seven,LEFT_DIGIT(hor_number));
    digit_activion(left_h);  
    (counter == SYSTEM_ONE_SEC) ? (counter = 0) : (counter++);
    if(!counter && !turn){
        if(!ver_number)
            turn = !turn;
        else{
            ver_number--;
            hor_number++;
        }
    }
    if(!counter && turn){
        if(!hor_number)
            turn = !turn;
        else{
            hor_number--;
            ver_number++;
        }
    }
}

void digit_activion(uint8 digit){
    digitalWrite(digit,SEV_ENABLE);
    _delay_ms(2);
    digitalWrite(digit,SEV_DISABLE);
}