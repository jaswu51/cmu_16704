#include <Arduino.h>  // required for the delay

#define DDRB_REG (*(volatile uint8_t *)0x24 /* TBD*/)  // place the register value here
                                              // and replace ?? with the real value 
                                              // from the datasheet

#define PORTB_REG (*(volatile uint8_t *)0x25 /* TBD*/) // place the register value here
                                              // and replace ?? with the real value 
                                              // from the datasheet
#define INPUT   0
#define OUTPUT  1
#define LED_PIN_B 1   // PB5 = D13

void setupTimer1PWM(void) {
    const uint16_t PWM_TOP = 1999; 

    TCCR1A = 0; 
    TCCR1B = 0; 

    TCCR1A |= (1 << WGM11); 
    TCCR1B |= (1 << WGM13) | (1 << WGM12);

    TCCR1A |= (1 << COM1A1);

    ICR1 = PWM_TOP;  
    OCR1A = (PWM_TOP+1)*0.1;      

    TCCR1B |= (1 << CS11);

}

void fastPinModeB(uint8_t pin, uint8_t mode)
{
    // pin: 0–5 → PB0–PB5 (Arduino D8–D13)
    uint8_t mask = (uint8_t)(1u << pin);

    if (mode == OUTPUT) {
      /*    TBD:  Fill the value of DDRB_REG using bit masking for output */
        DDRB_REG |= mask;   // set as output

    } else {
       /*    TBD:  Fill the value of DDRB_REG using bit masking for input  */
        DDRB_REG &= ~mask;  // set as input
    }
}


void setup()
{
    // Configure D13 (PB5) as output
    fastPinModeB(LED_PIN_B, OUTPUT); 
    setupTimer1PWM();
}

void loop()
{                     // 1 second
}