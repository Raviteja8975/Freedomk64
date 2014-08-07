#include "mbed.h"
#include "rtos.h"

void blinkLED1(void const *args) {
	DigitalOut led1(LED1);
	while(true){
		led1 = !led1;
		Thread::wait(300);
	}
}

void blinkLED2(void const *args) {
	DigitalOut led2(LED2);
	while(true){
		led2 = !led2;
		Thread::wait(500);
	}
}

void blinkLED3(void const *args) {
	DigitalOut led3(LED3);
	while(true){
		led3 = !led3;
		Thread::wait(800);
	}
}
int main() {

	Thread thread1(blinkLED1);
	Thread thread2(blinkLED2);
	Thread thread3(blinkLED3);

	while (true) {
		Thread::wait(250);
	}

}
