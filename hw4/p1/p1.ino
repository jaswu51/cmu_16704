// ---------------- Inbuilt LED Blinking --------------------------

// void setup() {
//   pinMode(13, OUTPUT);   // Set pin 13 as output
// }

// void loop() {
//   digitalWrite(13, HIGH); // Turn LED ON
//   delay(1000);            // Wait 1 second
//   digitalWrite(13, LOW);  // Turn LED OFF
//   delay(1000);            // Wait 1 second
// }

//----------------- Plot a sine wave ------------------------------
// #include <math.h>

// const int samples = 100;   // points per cycle
// int i = 0;

// void setup() {
//   Serial.begin(9600);
// }

// void loop() {
//   float angle = 2.0 * PI * i / samples;  // 0 → 2π
//   float sineValue = sin(angle);           // -1 → 1

//   // Scale to 0 → 1 for Serial Plotter
//   float plotValue = (sineValue + 1.0) / 2.0;

//   Serial.println(plotValue);

//   i++;
//   if (i >= samples) {
//     i = 0;
//   }

//   delay(20);   // controls frequency
// }

//--------------------- Q8 a code -------------------
const uint8_t LED_PIN = 13;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_PIN as an output.
  pinMode(LED_PIN, OUTPUT);
}
// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_PIN, HIGH); // turn the LED on
  delay(1000); // wait for a second
  digitalWrite(LED_PIN, LOW); // turn the LED off
  delay(1000); // wait for a second
}


//----------------------- Q 9 a Code ------------------

// #include <Arduino.h>  // required for the delay

// #define DDRB_REG (*(volatile uint8_t *)0x24 /* TBD*/)  // place the register value here
//                                               // and replace ?? with the real value 
//                                               // from the datasheet

// #define PORTB_REG (*(volatile uint8_t *)0x25 /* TBD*/) // place the register value here
//                                               // and replace ?? with the real value 
//                                               // from the datasheet
// #define INPUT   0
// #define OUTPUT  1
// #define LED_PIN_B 5   // PB5 = D13

// void fastPinModeB(uint8_t pin, uint8_t mode)
// {
//     // pin: 0–5 → PB0–PB5 (Arduino D8–D13)
//     uint8_t mask = (uint8_t)(1u << pin);

//     if (mode == OUTPUT) {
//       /*    TBD:  Fill the value of DDRB_REG using bit masking for output */
//         DDRB_REG |= mask;   // set as output

//     } else {
//        /*    TBD:  Fill the value of DDRB_REG using bit masking for input  */
//         DDRB_REG &= ~mask;  // set as input
//     }
// }

// void fastDigitalWriteB(uint8_t pin, uint8_t value)
// {
//     // pin: 0–5 → PB0–PB5 (Arduino D8–D13)
//     uint8_t mask = (uint8_t)(1u << pin);

//     if (value) {
//       /*    TBD:  Fill the value of PORTB_REG using bit masking for HIGH */
//         PORTB_REG |= mask;    // set HIGH
//     } else {
//       /*    TBD:  Fill the value of PORTB_REG using bit masking for LOW */
//         PORTB_REG &= ~mask;   // set LOW
//     }
// }

// void setup()
// {
//     // Configure D13 (PB5) as output
//     fastPinModeB(LED_PIN_B, OUTPUT); 
// }

// void loop()
// {
//     fastDigitalWriteB(LED_PIN_B, 1);  // LED ON
//     delay(1000);                      // 1 second

//     fastDigitalWriteB(LED_PIN_B, 0);  // LED OFF
//     delay(1000);                      // 1 second
// }