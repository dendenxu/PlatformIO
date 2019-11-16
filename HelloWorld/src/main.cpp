#include <Arduino.h>
#include <algorithm>
#include <vector>
using namespace std;
// ! Pins are all defined here.
vector<int> TriggerPins = {
    PB8,
    PB6,
    PB4,
    PG15,
    PG13,
    PG11,
    PG9,
    PD6,
    // PD4,
    // PD2,
};
vector<int> EchoPins = {
    PB9,
    PB7,
    PB5,
    PB3,
    PG14,
    PG12,
    PG10,
    PD7,
    // PD5,
    // PD3,
};
vector<int> VCC = {
    PB10,
    PE14,
    PE12,
    PE10,
    PE8,
    PG1,
};
vector<int> GND = {
    PB11,
    PE15,
    PE13,
    PE11,
    PE9,
    PE7,
};
unsigned long Time_Echo_us = 0;
unsigned long Len_mm = 0;
void setup()
{
    // Initialize trigger and echo pins as output and input
    for (unsigned int i = 0; i < TriggerPins.size(); i++) {
        pinMode(TriggerPins[i], OUTPUT);
    }
    for (unsigned int i = 0; i < EchoPins.size(); i++) {
        pinMode(EchoPins[i], INPUT);
    }

    // Setting VCC and GND as output and initialize their value
    for (unsigned int i = 0; i < VCC.size(); i++) {
        pinMode(VCC[i], OUTPUT);
        digitalWrite(VCC[i], HIGH);
    }
    for (unsigned int i = 0; i < GND.size(); i++) {
        pinMode(GND[i], OUTPUT);
        digitalWrite(GND[i], LOW);
    }

    // Begin receiving signals from the serial port
    Serial.begin(115200);
}

void loop()
{
    // ? Assume their's equal number of trigger pins ans echo pins
    // ? Might not be a good design
    // ? Currently using the number of trigger pins to begin the for loop
    for (unsigned int i = 0; i < TriggerPins.size(); i++) {
        digitalWrite(TriggerPins[i], HIGH);        //begin to send a high pulse, then US-025/US-026 begin to measure the distance
        delayMicroseconds(10);                     //set this high pulse width as 10us (>10us)
        digitalWrite(TriggerPins[i], LOW);         //end this high pulse
        Time_Echo_us = pulseIn(EchoPins[i], HIGH); //calculate the pulse width at EchoPin,
        if (Time_Echo_us > 1 && Time_Echo_us < 66000) {
            Len_mm = (Time_Echo_us * 34 / 100) / 2; //calculate the distance by pulse width, Len_mm = (Time_Echo_us * 0.34mm/us) / 2 (mm)
            // Serial.print("Echo pulse time is: ");
            // Serial.print(Time_Echo_us, DEC);
            // Serial.println("us");
            Serial.print(i, DEC);
            Serial.print("st Present Distance is: "); //output result to Serial monitor
            Serial.print(Len_mm, DEC);
            Serial.println("mm");
        } else {
            Serial.println("Too Far or Too Close!");
        }
        delay(100); // Set the time interval between pulses to 100ms
    }
}
