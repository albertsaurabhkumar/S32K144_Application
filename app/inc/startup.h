extern uint32_t _intvec_start_;
extern uint32_t _intvec_end_;
extern uint32_t _bss_start_;
extern uint32_t _bss_end_;

void initRam();
void initbss();
void Reset_Handler();