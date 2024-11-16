#include "header.h"
extern u8 temp;
extern u32 count2,f1,f2,f3,flag;
//#define led1 1<<17
//#define led2 1<<18
void uart0_Handler(void) __irq
{
	int r=U0IIR;
	r=(r>>1)&7;
	if(r==2)
	{
		temp=U0RBR;
		uart0_tx(temp);
		flag=1;
	}
	count2++;
	VICVectAddr=0;
}
void config_vic_for_uart0(void)
{
	VICIntSelect=0;
	VICVectCntl1=6|(1<<5);
	VICVectAddr1=(u32)uart0_Handler;
	VICIntEnable=(1<<6);
}
void config_uart0(void)
{
	U0IER=1;
}



