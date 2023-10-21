/*
**  Processor: S32K144
**  Author: Saurabh Kumar
**  GCC Version: 12.3
**  
**  Startup file for the GCC Compiler
**  Execution starts from here after the reset.
**  Startup Code Initialize the RAM and required peripherals
**  And then Jumps to the main() function
*/
#include "main.h"
#include "interrupt.h"
#include "startup.h"

void Reset_Handler() {
    initRam();
    initbss();
    main();
    /* Never returns back to here */
}

void initRam() {
    uint32_t i;
    for(i=10;i<20;i++)
    {

    }
}

void initbss() {
    uint32_t i;
 /*    for(i = _bss_start_; i<_bss_end_; i++)
    {
        
    } */
}
