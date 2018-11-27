#include "mbed.h"

Thread thread0;
Thread thread1;

void task0() {
  //creating a race condition
  while(1) {
    int wait_time = rand() % 10;
    wait(wait_time);
    printf("Task 0 waited %d\r\n", wait_time);
  }
}

void task1() {
  //creating a race condition
  while(1) {
    int wait_time = rand() % 10;
    wait(wait_time);
    printf("Task 1 waited %d\r\n", wait_time);
  }
}

int main() {
    number = 0;

    thread0.start(task0);
    thread1.start(task1);

    while (true) {
      //printf("print from main()\r\n");
      wait(10);
    }
}
