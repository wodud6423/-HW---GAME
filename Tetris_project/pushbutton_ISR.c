/*******************************************************************************
pushbutton_ISR.c
*******************************************************************************/
#include "address_map_nios2.h"
#include "nios2_ctrl_reg_macros.h"
#include <stdio.h>
//global 변수 선언과 초기화
//포인터변수는 외부에서 참조


extern volatile int *KEY_ptr;
extern volatile int *TIMER_ptr;
extern volatile int RUN;

extern int timer;

void pushbutton_ISR(void) {

    int press = *(KEY_ptr + 3);
    int i = 0;
    *(KEY_ptr + 3) = press;
    for (; press != 0; press = press >> 1) {
        if ((press & 1) != 0) {
            break;
        }
        else {
            i++;
        }
    }
    if (i == 0) {
        RUN = 1;
        //block_right();
    }
    else if (i == 1) {
        RUN = 1;
        //block_left();
    }
    else if (i == 2) {
        RUN = 1;
        //block_down();
    }
    else if (i == 3) {
        RUN = 1;
        //rotate_block();
    }
}

void timer_ISR(void){
    *(TIMER_ptr) = 0;
    timer = timer + 1;
}