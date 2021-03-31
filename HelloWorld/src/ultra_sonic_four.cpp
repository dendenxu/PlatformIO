#include <Arduino.h>
#define EchoPin PB13
#define TrigPin PB12
#define EchoPin2 PB11
#define TrigPin2 PB10
#define EchoPin3 PE1
#define TrigPin3 PE0
#define EchoPin3 PE1
#define TrigPin3 PE0
#define EchoPin4 PB9
#define TrigPin4 PB8
#define VCC1 PE3
#define GND1 PE2
#define VCC2 PB7
#define GND2 PB6
#define LASER_TRIG1 PB5
#define LASER_VCC1 PB4
#define LASER_GND1 PB3
#define LASER_TRIG2 PE5
#define LASER_VCC2 PE4
#define LASER_GND2 PC13
#define LASER_PIN PB14
unsigned long Time_Echo_us = 0;
unsigned long Len_mm = 0;
void setup()
{
    // initialize LED digital pin as an output.
    pinMode(LASER_PIN, OUTPUT);
    pinMode(LED_D1, OUTPUT);
    pinMode(LED_D2, OUTPUT);
    Serial.begin(115200);
    pinMode(EchoPin, INPUT);
    pinMode(TrigPin, OUTPUT);
    pinMode(EchoPin2, INPUT);
    pinMode(TrigPin2, OUTPUT);
    pinMode(EchoPin3, INPUT);
    pinMode(TrigPin3, OUTPUT);
    pinMode(EchoPin4, INPUT);
    pinMode(TrigPin4, OUTPUT);
    pinMode(VCC1, OUTPUT);
    pinMode(GND1, OUTPUT);
    digitalWrite(VCC1, HIGH);
    digitalWrite(GND1, LOW);
    pinMode(VCC2, OUTPUT);
    pinMode(GND2, OUTPUT);
    digitalWrite(VCC2, HIGH);
    digitalWrite(GND2, LOW);
    pinMode(LASER_TRIG1, OUTPUT);
    pinMode(LASER_TRIG2, OUTPUT);
    pinMode(LASER_VCC1, OUTPUT);
    pinMode(LASER_VCC2, OUTPUT);
    pinMode(LASER_GND1, OUTPUT);
    pinMode(LASER_GND2, OUTPUT);
    digitalWrite(LASER_VCC2, HIGH);
    digitalWrite(LASER_GND2, LOW);
    digitalWrite(LASER_VCC1, HIGH);
    digitalWrite(LASER_GND1, LOW);
}

void loop()
{
    digitalWrite(TrigPin, HIGH);           //begin to send a high pulse, then US-025/US-026 begin to measure the distance
    delayMicroseconds(10);                 //set this high pulse width as 20us (>10us)
    digitalWrite(TrigPin, LOW);            //end this high pulse
    Time_Echo_us = pulseIn(EchoPin, HIGH); //calculate the pulse width at EchoPin,
    if (Time_Echo_us > 1 && Time_Echo_us < 66000) {
        Len_mm = (Time_Echo_us * 34 / 100) / 2; //calculate the distance by pulse width, Len_mm = (Time_Echo_us * 0.34mm/us) / 2 (mm)
        // Serial.print("Echo pulse time is: ");
        // Serial.print(Time_Echo_us, DEC);
        // Serial.println("us");
        Serial.print("1st Present Distance is: "); //output result to Serial monitor
        Serial.print(Len_mm, DEC);                 //output result to Serial monitor
        Serial.println("mm");                      //output result to Serial monitor
    } else {
        Serial.println("Too Far or Too Close!");
    }
    delayMicroseconds(100);
    digitalWrite(TrigPin2, HIGH);           //begin to send a high pulse, then US-025/US-026 begin to measure the distance
    delayMicroseconds(10);                  //set this high pulse width as 20us (>10us)
    digitalWrite(TrigPin2, LOW);            //end this high pulse
    Time_Echo_us = pulseIn(EchoPin2, HIGH); //calculate the pulse width at EchoPin,
    if (Time_Echo_us > 1 && Time_Echo_us < 66000) {
        Len_mm = (Time_Echo_us * 34 / 100) / 2; //calculate the distance by pulse width, Len_mm = (Time_Echo_us * 0.34mm/us) / 2 (mm)
        // Serial.print("Echo pulse time is: ");
        // Serial.print(Time_Echo_us, DEC);
        // Serial.println("us");
        Serial.print("2st Present Distance is: "); //output result to Serial monitor
        Serial.print(Len_mm, DEC);                 //output result to Serial monitor
        Serial.println("mm");                      //output result to Serial monitor
    } else {
        Serial.println("Too Far or Too Close!");
    }
    delayMicroseconds(100);
    digitalWrite(TrigPin3, HIGH);           //begin to send a high pulse, then US-025/US-026 begin to measure the distance
    delayMicroseconds(10);                  //set this high pulse width as 20us (>10us)
    digitalWrite(TrigPin3, LOW);            //end this high pulse
    Time_Echo_us = pulseIn(EchoPin3, HIGH); //calculate the pulse width at EchoPin,
    if (Time_Echo_us > 1 && Time_Echo_us < 66000) {
        Len_mm = (Time_Echo_us * 34 / 100) / 2; //calculate the distance by pulse width, Len_mm = (Time_Echo_us * 0.34mm/us) / 2 (mm)
        // Serial.print("Echo pulse time is: ");
        // Serial.print(Time_Echo_us, DEC);
        // Serial.println("us");
        Serial.print("3st Present Distance is: "); //output result to Serial monitor
        Serial.print(Len_mm, DEC);                 //output result to Serial monitor
        Serial.println("mm");                      //output result to Serial monitor
    } else {
        Serial.println("Too Far or Too Close!");
    }

    delayMicroseconds(100);
    digitalWrite(TrigPin4, HIGH);           //begin to send a high pulse, then US-025/US-026 begin to measure the distance
    delayMicroseconds(10);                  //set this high pulse width as 20us (>10us)
    digitalWrite(TrigPin4, LOW);            //end this high pulse
    Time_Echo_us = pulseIn(EchoPin4, HIGH); //calculate the pulse width at EchoPin,
    if (Time_Echo_us > 1 && Time_Echo_us < 66000) {
        Len_mm = (Time_Echo_us * 34 / 100) / 2; //calculate the distance by pulse width, Len_mm = (Time_Echo_us * 0.34mm/us) / 2 (mm)
        // Serial.print("Echo pulse time is: ");
        // Serial.print(Time_Echo_us, DEC);
        // Serial.println("us");
        Serial.print("4st Present Distance is: "); //output result to Serial monitor
        Serial.print(Len_mm, DEC);                 //output result to Serial monitor
        Serial.println("mm");                      //output result to Serial monitor
    } else {
        Serial.println("Too Far or Too Close!");
    }

    Serial.println("");
    delayMicroseconds(100);
    // turn the LED on (HIGH is the voltage level)
    digitalWrite(LASER_PIN, HIGH);
    digitalWrite(LASER_TRIG2, LOW);
    digitalWrite(LASER_TRIG1, HIGH);
    digitalWrite(LED_D1, HIGH);
    digitalWrite(LED_D2, LOW);
    // Serial.println("LED_D1 ON! LED_D2 OFF!");
    // wait for a second
    delay(250);
    // turn the LED off by making the voltage LOW
    digitalWrite(LASER_PIN, LOW);
    digitalWrite(LASER_TRIG1, LOW);
    digitalWrite(LASER_TRIG2, HIGH);
    digitalWrite(LED_D2, HIGH);
    digitalWrite(LED_D1, LOW);
    // Serial.println("LED_D1 OFF! LED_D2 ON!");
    // wait for a second
    delay(250);
    delay(250);
}
