/*******************************************************************************
timmer_ISR.c
*******************************************************************************/
#include "address_map_nios2.h"
//global 변수 선언과 초기화
//포인터변수는 외부에서 참조
extern volatile int *TIMER_ptr;
extern int count;
//N번 Hex에 X Display하는 함수

void timmer_ISR(void) {
	int *TIMER_control = (int*)(TIMER_BASE + 4);
	int TO_IRQ = *TIMER_ptr;
	TO_IRQ = 0;
	*TIMER_ptr = TO_IRQ; // 타이머 TO값 초기화
	count++;
	*TIMER_control = 0x5; //다시 타이머 시작
	return;
}
