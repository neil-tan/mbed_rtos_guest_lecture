#include "mbed.h"

Thread thread0;
Thread thread1;

int state = 0;
Mutex my_mutex;

void task0() {
  //creating a race condition
  while(1) {
    my_mutex.lock();
    if(state % 2 == 0) {
      int wait_time = rand() % 10;
      wait(wait_time);
      printf("Task 0 waited %d\r\n", wait_time);
      state++;
    }
    my_mutex.unlock();

    wait(0);
  }
}

void task1() {
  //creating a race condition
  while(1) {
    my_mutex.lock();
    if(state % 2 == 1) {
      int wait_time = rand() % 10;
      wait(wait_time);
      printf("Task 1 waited %d\r\n", wait_time);
      state++;
    }
    my_mutex.unlock();
    
    wait(0);
  }
}

int main() {

    thread0.start(task0);
    thread1.start(task1);

    while (true) {
      //printf("print from main()\r\n");
      wait(10);
    }
}
