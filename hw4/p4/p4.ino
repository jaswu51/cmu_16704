
#include <Arduino.h>  // required for the delay

#define DDRB_REG (*(volatile uint8_t *)0x24 /* TBD*/)  // place the register value here
                                              // and replace ?? with the real value 
                                              // from the datasheet

#define PORTB_REG (*(volatile uint8_t *)0x25 /* TBD*/) // place the register value here
                                              // and replace ?? with the real value 
                                              // from the datasheet
#define INPUT   0
#define OUTPUT  1
#define LED_PIN_B 5   // PB5 = D13

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

void fastDigitalWriteB(uint8_t pin, uint8_t value)
{
    // pin: 0–5 → PB0–PB5 (Arduino D8–D13)
    uint8_t mask = (uint8_t)(1u << pin);

    if (value) {
      /*    TBD:  Fill the value of PORTB_REG using bit masking for HIGH */
        PORTB_REG |= mask;    // set HIGH
    } else {
      /*    TBD:  Fill the value of PORTB_REG using bit masking for LOW */
        PORTB_REG &= ~mask;   // set LOW
    }
}

void setup()
{
    // Configure D13 (PB5) as output
    fastPinModeB(LED_PIN_B, OUTPUT); 
}

void loop()
{
    fastDigitalWriteB(LED_PIN_B, HIGH);  // LED ON
    delay(100);                      // 1 second

    fastDigitalWriteB(LED_PIN_B, LOW);  // LED OFF
    delay(900);                      // 1 second
}