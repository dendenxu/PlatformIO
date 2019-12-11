#include <Arduino.h>
#include <Servo.h>
#include <Thread.h>
#include <ThreadController.h>
#include <vector>
// ThreadController that will controll all threads
ThreadController control = ThreadController();

//My Thread
Thread servo0_thread = Thread();
//His Thread
Thread servo1_thread = Thread();
//ThreadController, that will be added to controll
ThreadController group_of_threads = ThreadController();

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
void servo0_motion();
void servo1_motion();

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
        pinMode(servo_signal_pins[i], OUTPUT);
        servos[i].attach(servo_signal_pins[i]);
        Serial.print("Servo No.");
        Serial.print(i, DEC);
        Serial.print("Attached to pin");
        Serial.println(servo_signal_pins[i], DEC);
        // Initializing servo positions
        pos.push_back(0);
    }
    // Configure threads
    servo0_thread.onRun(servo0_motion);
    servo0_thread.setInterval(10);
    servo1_thread.onRun(servo1_motion);
    servo1_thread.setInterval(1800);
    control.add(&servo1_thread);
    control.add(&servo0_thread);
}
void servo1_motion()
{
    pos[1] %= 170;
    pos[1] += 10;
    servos[1].write(pos[1]);
}
void servo0_motion()
{
    static bool di_up = true;
    if (pos[0] == 150) {
        di_up = false;
    } else if (pos[0] == 30) {
        di_up = true;
    }
    pos[0] += di_up ? 1 : -1;
    servos[0].write(pos[0]);
}
void loop()
{
    control.run();
}
