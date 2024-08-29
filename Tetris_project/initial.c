#include "nios2_ctrl_reg_macros.h"
#include "address_map_nios2.h"

extern volatile int *KEY_ptr;
extern volatile int *TIMER_ptr;

extern int RUN;
extern int timer;

void init_vars(void);
void init_timer(void);
void init_audio(void);
void init_int(void);

void init_vars()
{
    timer = 0;
	RUN = 0;
}

void init_timer()
{
    int mil = 1000000-1; //10 milliseconds
	*(TIMER_ptr + 2) = mil;
	mil = mil >> 16;
	*(TIMER_ptr + 3) = mil;	
	*(TIMER_ptr + 1) = 7;
}

void init_key()
{
	*(KEY_ptr + 2) = 0x03;
}

void init_int(void)
{
    NIOS2_WRITE_STATUS(0x01);
    NIOS2_WRITE_IENABLE(0x003); //0x43
}
