/*
**  Processor: S32K144
**  Author: Saurabh Kumar
**  GCC Version: 12.3
**  
**  Main program file for the GCC Compiler
*/
#include "main.h"
#include "clock.h"
#include "port.h"
#include "common.h"

volatile uint32_t dlyCnt;
volatile uint32_t counter;
//volatile uint32_t a=10;
void WDOG_disable (void) {
 WDOG->CNT=0xD928C520; /*Unlock watchdog*/
 WDOG->TOVAL=0x0000FFFF; /*Maximum timeout value*/
 WDOG->CS = 0x00002100; /*Disable watchdog*/
}

void delay(uint32_t a) {
  while(a>0){
    a--;
    dlyCnt=a;
  }
}

int main(void) {
  initClk();
  WDOG_disable();
  
  PortPCR(PORTB,PIN4);
  PortPCR(PORTA,PIN6);
  PortPCR(PORTA,PIN11);

  DataDirectionGPIO(PTB,PIN4);
  DataDirectionGPIO(PTA,PIN6);
  DataDirectionGPIO(PTA,PIN11);

  while(1)
  {
    ToggleGPIO(PTA,PIN6);
    delay(720000);

    ToggleGPIO(PTB,PIN4);
    delay(720000);

    ToggleGPIO(PTA,PIN11);
    delay(720000);
    // Never returns from this loop 
  }
  return 0;
}