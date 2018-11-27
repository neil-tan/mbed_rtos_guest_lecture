#include "mbed.h"
#include "examples.hpp"


#include "mbed.h"
#include "examples.hpp"

DigitalOut led1(LED1);
 
void led_loop() {
        led1 = !led1;
        wait(0.1);
}
 
int main() {
    while (true) {
        led_loop();
        printf("waiting for 2 seconds\r\n");
        wait(2);
    }
}
