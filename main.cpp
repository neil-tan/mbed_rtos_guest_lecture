#include "mbed.h"

//https://os.mbed.com/blog/entry/Simplify-your-code-with-mbed-events/

DigitalOut led(LED1);
InterruptIn btn(SW2);

EventQueue queue;

void do_something_outside_irq() {
  // this does not run in the ISR
  printf("Toggle LED!\r\n");
}

void do_something_in_irq() {
  // this runs in the ISR
  led = !led;

  // then defer the printf call to the other thread
  queue.call(&do_something_outside_irq);
}

int main() {
  Thread eventThread;
  eventThread.start(callback(&queue, &EventQueue::dispatch_forever));

  btn.fall(&do_something_in_irq);

  wait(osWaitForever);
}
