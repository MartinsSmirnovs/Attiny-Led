#include <avr/io.h>
#include <stdint.h>

int main(void)
{
  TCCR0B |= 0b0000001; //timer counter control register B on normal mode
  uint16_t timeCount = 0;
  uint16_t delay = 6000;

  while (timeCount != delay)
  {
    if (TCNT0 == 255) //timer counter
      timeCount++;

    if (timeCount == delay - 1) //executes if timeCount time units have passed
    {
      PORTB |= 0b00001000; //PORTB register, pin 3 HIGH
      DDRB |= 0b00001000;  //DDRB register, pin 3 HIGH
    }
  }
  return 0;
}