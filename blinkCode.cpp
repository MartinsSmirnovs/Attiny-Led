#include <avr/io.h>
#include <stdint.h>

int main(void)
{
  TCCR0B |= 0b0000001; //timer counter control register B on normal mode
  uint16_t timeCount = 0;
  uint16_t delay = 256;

  while (1)
  {
    if (TCNT0 == 255) //timer counter
    {
      timeCount++;
    }

    if (timeCount == delay) //executes if delay time units have passed
    {
      timeCount = 0;
      if (PORTB == 8)
      {
        PORTB &= 0b00000000; //PORTB register, pin 3 LOW
        DDRB &= 0b00000000;  //DDRB register, pin 3 LOW
      }
      else //if all bits are 0
      {
        PORTB |= 0b00001000; //PORTB register, pin 3 HIGH
        DDRB |= 0b00001000;  //DDRB register, pin 3 HIGH
      }
    }
  }
  return 0;
}