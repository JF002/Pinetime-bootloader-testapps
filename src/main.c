#include <startup/nrf.h>
#include <stdio.h>
#include <segger_rtt/SEGGER_RTT.h>
#include <stdio.h>
#include "nrf52_nvmc.h"

void InitClock();

int main() {
  InitClock();
  SEGGER_RTT_Init();

#ifdef APP_A
  uint8_t pin = 17;
#endif
#ifdef APP_B
  uint8_t pin = 18;
#endif

#ifdef APP_A
  SEGGER_RTT_printf(0, "Hello from AAA");
#endif
#ifdef APP_B
  SEGGER_RTT_printf(0, "Hello from BBB");
#endif
  NRF_P0->PIN_CNF[pin] = 0x03;

  nrf52_nvmc_write_word(0x62fe8, 0x01);

  while(1) { asm("nop"); asm("nop"); asm("nop"); }

  return 0;
}

void InitClock() {
  NRF_CLOCK->LFCLKSRC = 1;
}
