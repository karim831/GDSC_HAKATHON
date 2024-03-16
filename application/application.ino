#include "./headers/application.h"
/*      ultrasonic     */
ultrasonic_t sonic_ver = {
    .trig = PIN10,
    .echo = PIN11
};

ultrasonic_t sonic_hor = {
    .trig = PIN12,
    .echo = PIN13
};
dec32 distance = 0.0;
/*      ultrasonic     */

/*      seven_seg      */
sev_seg_t seven = {
    .sev_pins = {PIN2,PIN3,PIN4,PIN5}
};

uint8 left_v = PIN6;
uint8 right_v = PIN7;
uint8 left_h = PIN8;
uint8 right_h = PIN9;

uint8 ver_number = SYS_SEV_MAX_NUMBER;
uint8 hor_number = 0;
uint8 turn = 0;
uint8 counter = 0;
/*      seven_seg      */
void setup(){
    /*      seven_seg      */
    ultrasonic_initialize(&sonic_hor);
    ultrasonic_initialize(&sonic_ver);
    /*      seven_seg      */

    /*      ultrasonic     */
    pinMode(left_v,OUTPUT);
    pinMode(right_v,OUTPUT);
    pinMode(left_h,OUTPUT);
    pinMode(right_h,OUTPUT);
    sev_seg_initialize(&seven);
    digitalWrite(left_v,SEV_DISABLE);
    digitalWrite(right_v,SEV_DISABLE);
    digitalWrite(left_h,SEV_DISABLE);
    digitalWrite(right_h,SEV_DISABLE);
    /*      ultrasonic     */
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
            ultrasonic_distance(&sonic_ver,&distance);
            if(distance <= SELECTED_DISTANCE){
                Serial.print("distance = ");
                Serial.print(distance);
                Serial.println(" Vertical ROAD HAS PROBLEM!");
            }
        }
    }
    if(!counter && turn){
        if(!hor_number)
            turn = !turn;
        else{
            hor_number--;
            ver_number++;
            ultrasonic_distance(&sonic_hor,&distance);
            if(distance <= SELECTED_DISTANCE){
                Serial.print("distance = ");
                Serial.print(distance);
                Serial.println(" Horizontal ROAD HAS PROBLEM!");
            }
                
        }
    }
}

void digit_activion(uint8 digit){
    digitalWrite(digit,SEV_ENABLE);
    _delay_ms(2);
    digitalWrite(digit,SEV_DISABLE);
}