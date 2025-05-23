#include <Arduino.h>
#include <avr/io.h>
volatile uint8_t  counter=0;


void setup() {
 
}

void loop() {
  asm volatile("push r17\n\t" // these saves the register on the stack so we dont mess up the system
              "push r16\n\t"
               "ldi r16,0x01\n\t" // this one gives 1 to r16
              "lds r17,counter\n\t"// and this gives the data in counter and push it to r17
              "loop_continue: \n\t"// label for loop 
              "cpi r17,0x00\n\t" // this compares the data in r17 with 0 hex
              "breq loop_exit \n\t" // branch if equal this looks at r17 if its 0 it will go to loop_exit if not it will ignore
              "lsl r16\n\t"// this one shifts r16 data to the left by one bit
              "dec r17\n\t"// decrements r17 data always from 1 to 0
            "rjmp loop_continue\n\t" // this jumps back to loop_continue
              "loop_exit: \n\t" // just a label loop
              "out 0x05,r16\n\t"// basically the hex adreess of 5 0x05 this is the PORTB in I/O memory space and this 0x20 this is in the ram space and it says give this value inside of r16 to PORTB
              "pop r16\n\t" //these two will release the registers
            "pop r17\n\t");
 if(++counter>=6)
    counter=0;

delay(300);
}

