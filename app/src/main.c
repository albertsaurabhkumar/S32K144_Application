/*
**  Processor: S32K144
**  Author: Saurabh Kumar
**  GCC Version: 12.3
**  
**  Main program file for the GCC Compiler
*/
#include "main.h"
#include "clock.h"
#include "common.h"
#include <stdint.h>

volatile uint32_t a=10;

void delay(int dlyCnt) {
  for(uint32_t i=dlyCnt; i>0;i--);
}

int main(void)
{
  //initClk();
  PTE->PDDR = GPIO_PDDR_PDD(0x40);

  while(1)
  {
    PTE->PTOR = GPIO_PTOR_PTTO(0x40);
    delay(1000);
    // Never returns from this loop 
  }
  return 0;
}