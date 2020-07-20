#include <avr/io.h>
#include <stdint.h>

void timer(uint16_t *tc, uint16_t *del)
{
  //time counter
  if (TCNT0 == 255)
    *tc += 1;
  //executes if timeCount time units have passed
  if (*tc >= *del - 1)
  {
    //PB3 HIGH
    DDRB |= (1 << PB3);
    PORTB |= (1 << PB3);
  }
}

int main(void)
{
  //timer counter control register B on normal mode
  TCCR0B |= 0b0000010;

  //time counting variables
  uint16_t timeCount = 0;
  uint16_t delay = 1000;

  //read and save input states
  bool powerIn;
  
  //for keeping pins turned off
  bool off;

  //sets up PB4 as input
  PORTB |= (1 << PB4);
  MCUCR |= (1 << PB4);

  //main loop
  while (true)
  {
    //reads 19V input
    powerIn = ((PINB & 16)) ? false : true;

    if (powerIn)
    {
      // toggle 19V OUT
      DDRB |= (1 << PB0);
      PORTB |= (1 << PB0);

      //turn off 12V OUT
      off = ((PINB & 2)) ? true : false;
      DDRB ^= (off << PB1);
      PORTB ^= (off << PB1);
    }
    else
    {
      //toggle 12V OUT
      DDRB |= (1 << PB1);
      PORTB |= (1 << PB1);

      //turn off 19V OUT
      off = ((PINB & 1)) ? true : false;
      DDRB ^= (off << PB0);
      PORTB ^= (off << PB0);
    }
    //turns on slow start output
    timer(&timeCount, &delay);
  }

  return 0;
}
