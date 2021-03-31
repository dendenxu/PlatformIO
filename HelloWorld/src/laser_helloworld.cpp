#include <Arduino.h>
#define LASER_PIN1 PB12
#define LASER_PIN2 PB13
#define LASER_GND PB14
#define LASER_VCC PB15
#define DELAY_TIME 100
void setup()
{
    pinMode(LASER_PIN1, OUTPUT);
    pinMode(LASER_PIN2, OUTPUT);
    pinMode(LASER_GND, OUTPUT);
    pinMode(LASER_VCC, OUTPUT);
    pinMode(LED_D1, OUTPUT);
    pinMode(LED_D2, OUTPUT);
    digitalWrite(LASER_VCC, HIGH);
    digitalWrite(LASER_GND, LOW);
}

void loop()
{
    // turn the LED on (HIGH is the voltage level)
    digitalWrite(LASER_PIN1, HIGH);
    digitalWrite(LASER_PIN2, LOW);
    digitalWrite(LED_D1, HIGH);
    digitalWrite(LED_D2, LOW);
    // Serial.println("LED_D1 ON! LED_D2 OFF!");
    // wait for a second
    delayMicroseconds(DELAY_TIME);
    // turn the LED off by making the voltage LOW
    digitalWrite(LASER_PIN2, HIGH);
    digitalWrite(LASER_PIN1, LOW);
    digitalWrite(LED_D2, HIGH);
    digitalWrite(LED_D1, LOW);
    // Serial.println("LED_D1 OFF! LED_D2 ON!");
    // wait for a second
    delayMicroseconds(DELAY_TIME);
}
