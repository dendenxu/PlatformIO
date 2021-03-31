#include <Arduino.h>
#include <Servo.h>
#include <vector>

#define NUMBER_OF_SERVOS 2
using namespace std;
vector<int> servo_signal_pins_pool = {
    PB3,
    PB4,
    PB6,
    PB7,
    PB8,
    PB9,
};
vector<int> servo_signal_pins;
vector<Servo> servos;
vector<int> pos; // variable to store the servo position

void setup()
{
    // Allocate pins according to the number of servos to be used
    servos.resize(NUMBER_OF_SERVOS);
    Serial.begin(115200);
    for (int i = 0; i < NUMBER_OF_SERVOS; i++) {
        // Getting pins from pins pool
        servo_signal_pins.push_back(servo_signal_pins_pool.back());
        servo_signal_pins_pool.pop_back();
        // Attaching pins
        servos[i].attach(servo_signal_pins[i]);
        Serial.print("Servo No.");
        Serial.print(i, DEC);
        Serial.print("Attached to pin");
        Serial.println(servo_signal_pins[i], DEC);
        // Initializing servo positions
        pos.push_back(0);
    }
}

void loop()
{
    for (pos[0] = 0; pos[0] <= 180; pos[0] += 10) {
        Serial.println("Circle begins");
        servos[0].write(pos[0]);
        for (pos[1] = 0; pos[1] <= 180; pos[1] += 1) { // goes from 0 degrees to 180 degrees
            // in steps of 1 degree
            servos[1].write(pos[1]); // tell servo to go to position in variable 'pos[1]'
            delay(150);              // waits 15ms for the servo to reach the position
        }
        Serial.println("180 degree swept");
        for (pos[1] = 180; pos[1] >= 0; pos[1] -= 1) { // goes from 180 degrees to 0 degrees
            servos[1].write(pos[1]);                   // tell servo to go to position in variable 'pos[1]'
            delay(150);                                // waits 15ms for the servo to reach the position
        }
        Serial.println("Circle ends");
    }
}
