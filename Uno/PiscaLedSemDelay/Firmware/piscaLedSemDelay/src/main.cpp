#include <Arduino.h>

#define PIN_LED_STATUS 13   // Pino que deve piscar o LED
#define TIMER_DELAY 500     // Tempo para piscar o LED.

#define LED_ON 1    // led ligado
#define LED_OFF 0   // led desligado

#define TOGGLE_DATA(DATA) ((DATA)?DATA=0:DATA=1) // macro para inverter estado do pino

void funcPiscaLed( void ); // funcao do pisca led

void setup() {
    pinMode(PIN_LED_STATUS, OUTPUT);
}

void loop() {
    funcPiscaLed();
}

/**
 * @brief Funcao para piscar um led. 
 * 
 * @param void.
 * 
 * @return void.
 **/
void funcPiscaLed( void ){

    static unsigned long timerPiscaLed = 0;
    static uint8_t toggleData = 0; 

    if(millis() - timerPiscaLed > TIMER_DELAY){
        timerPiscaLed = millis();

        TOGGLE_DATA(toggleData); // Variavel para inverter estado do pino. 

        if((toggleData) == LED_ON){
            digitalWrite(PIN_LED_STATUS, 1);
        }else{
            digitalWrite(PIN_LED_STATUS, 0);
        }
    }   
}