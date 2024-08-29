/*******************************************************************************
exception_handler.c
*******************************************************************************/
#include "nios2_ctrl_reg_macros.h"
/* 함수 선언 */
void main(void);
void interrupt_handler(void);
void pushbutton_ISR(void);
void timer_ISR(void);
/* 아래는 NIOS2의 reset processing을 처리하는 Assembly 코드 */
void the_reset (void) __attribute__ ((section (".reset")));
void the_reset (void)
/******************************************************************************
* Reset code; ".reset"이라는 section attribute를 사용하므로써 Linker가 이 코드를
* 이전의 reset vector address에 위치 시키게 한다. 이 코드는 단지 main 프로그램을 호출한다.
******************************************************************************/
{
asm (".set noat"); // magic, for the C compiler
asm (".set nobreak"); // magic, for the C compiler
asm ("movia r2, main"); // C 언어의 main program이 있는 주소를 r2에 저장한다.
asm ("jmp r2"); // main program이 저장된 r2 gpr로 Jump 한다.
}
/* 아래는 NIOS2의 Exception processing을 처리하는 Assembly 코드. 이 코드는 수정될 수 없다.
대신, C언어로된 interrupt_handler() 는 주어진 application의 필요에 따라 수정될 수 있다.*/
void the_exception (void) __attribute__ ((section (".exceptions")));
void the_exception (void)
/*******************************************************************************
* Exceptions code; ".exceptions"이라는 section attribute를 사용하여 Linker가 이 코드를
* 이전의 exceptions vector address에 위치 시키게 한다. 이 코드는 interrupt handler를 호출하고
* 이후에 Exeption으로부터 리턴 시킨다.
******************************************************************************/
{
asm (".set noat"); // magic, for the C compile
asm (".set nobreak"); // magic, for the C compiler
asm ( "subi sp, sp, 128");
asm ( "stw et, 96(sp)");
asm ( "rdctl et, ctl4");
asm ( "beq et, r0, SKIP_EA_DEC"); // Trap이 아닌 경우를 확인한다.
asm ( "subi ea, ea, 4");
 // Trap이라면 리턴 할 주소를 한 word만큼 복귀 pc를 앞당겨야 Trap을 계속해서 수행하는 무한 루프에 빠지지 않는다. 
asm ( "SKIP_EA_DEC:" );
// 범용적 기능 수행을 위해 모든 복귀할 값들을 스택에 저장
asm ( "stw r1, 4(sp)" ); 
asm ( "stw r2, 8(sp)" );
asm ( "stw r3, 12(sp)" );
asm ( "stw r4, 16(sp)" );
asm ( "stw r5, 20(sp)" );
asm ( "stw r6, 24(sp)" );
asm ( "stw r7, 28(sp)" );
asm ( "stw r8, 32(sp)" );
asm ( "stw r9, 36(sp)" );
asm ( "stw r10, 40(sp)" );
asm ( "stw r11, 44(sp)" );
asm ( "stw r12, 48(sp)" );
asm ( "stw r13, 52(sp)" );
asm ( "stw r14, 56(sp)" );
asm ( "stw r15, 60(sp)" );
asm ( "stw r16, 64(sp)" );
asm ( "stw r17, 68(sp)" );
asm ( "stw r18, 72(sp)" );
asm ( "stw r19, 76(sp)" );
asm ( "stw r20, 80(sp)" );
asm ( "stw r21, 84(sp)" );
asm ( "stw r22, 88(sp)" );
asm ( "stw r23, 192(sp)" );
asm ( "stw r24, 100(sp)" );
asm ( "stw r25, 104(sp)" );
asm ( "stw r26, 108(sp)" );
asm ( "stw r28, 112(sp)" );
asm ( "stw r29, 116(sp)" );
asm ( "stw r30, 120(sp)" );
asm ( "stw r31, 124(sp)" ); // r31 = ra
asm ( "addi fp, sp, 128" );
asm ( "call interrupt_handler" ); // C언어로된 interrupt handler를 호출한다.
asm ( "ldw r1, 4(sp)" ); // 모든 레지스터를 Stack에서 복구
asm ( "ldw r2, 8(sp)" );
asm ( "ldw r3, 12(sp)" );
asm ( "ldw r4, 16(sp)" );
asm ( "ldw r5, 20(sp)" );
asm ( "ldw r6, 24(sp)" );
asm ( "ldw r7, 28(sp)" );
asm ( "ldw r8, 32(sp)" );
asm ( "ldw r9, 36(sp)" );
asm ( "ldw r10, 40(sp)" );
asm ( "ldw r11, 44(sp)" );
asm ( "ldw r12, 48(sp)" );
asm ( "ldw r13, 52(sp)" );
asm ( "ldw r14, 56(sp)" );
asm ( "ldw r15, 60(sp)" );
asm ( "ldw r16, 64(sp)" );
asm ( "ldw r17, 68(sp)" );
asm ( "ldw r18, 72(sp)" );
asm ( "ldw r19, 76(sp)" );
asm ( "ldw r20, 80(sp)" );
asm ( "ldw r21, 84(sp)" );
asm ( "ldw r22, 88(sp)" );
asm ( "ldw r23, 92(sp)" );
asm ( "ldw r24, 96(sp)" );
asm ( "ldw r25, 100(sp)" );
asm ( "ldw r26, 104(sp)" );
asm ( "ldw r28, 112(sp)" );
asm ( "ldw r29, 116(sp)" );
asm ( "ldw r30, 120(sp)" );
asm ( "ldw r31, 124(sp)" );
asm ( "addi sp, sp, 128" );
asm ( "eret" );
}
/******************************************************************************
* Interrupt Service Routine: interrupt의 원인을 결정하고 해당 interrupt를 처리할
* subroutine을 호출한다.
*******************************************************************************/
void interrupt_handler(void)
{
	int ipending;
	NIOS2_READ_IPENDING(ipending);
	if ( ipending & 0x02 ) 
	{
		pushbutton_ISR( ); 
	}
	else if ( ipending & 0x01) 
	{
		timer_ISR( ); 
	}
	return;
}