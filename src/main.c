#include <startup/nrf.h>
#include <stdio.h>
#include <segger_rtt/SEGGER_RTT.h>
#include <stdio.h>

void InitClock();

int main() {
  InitClock();

#ifdef APP_A
  uint8_t pin = 17;
#endif
#ifdef APP_B
  uint8_t pin = 18;
#endif
  NRF_P0->PIN_CNF[pin] = 0x03;

  while(1) { asm("nop"); asm("nop"); asm("nop"); }

  return 0;
}

void InitClock() {
  NRF_CLOCK->LFCLKSRC = 1;
}
