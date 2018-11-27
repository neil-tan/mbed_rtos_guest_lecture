#include "mbed.h"

DigitalOut led(LED1);
Thread thread;

void led_loop() {
    while (true) {
        led = !led;
        wait(0.1);
    }
}
 
int main() {
    thread.start(led_loop);
    
    while (true) {
        printf("waiting for 2 seconds\r\n");
        wait(2);
    }
}
