#include"header.h"
#define led1 1<<17
#define led2 1<<18
#define sw1 ((IOPIN0>>14)&1)
#define sw2 ((IOPIN0>>15)&1)
#define sw3 ((IOPIN0>>16)&1)
u32 count1=0,count2=0,f1,f2,f3,flag;
u8 temp;
main()
{
	uart0_init(9600);
	lcd_init();
	config_vic_for_uart0();
	config_uart0();
	IODIR0=led1|led2;
	IOSET0=led1|led2;
	lcd_cmd(0x1);
	lcd_string("Welcome Home");
		uart0_tx_string("\r\nMenu:");
		uart0_tx_string("\r\n1 : on 1st led");
		uart0_tx_string("\r\n2 : off 1st led");
		uart0_tx_string("\r\n3 : on 2st led");
		uart0_tx_string("\r\n4 : off 2st led");
		uart0_tx_string("\r\n5 : on 1st & 2nd led");
		uart0_tx_string("\r\n6 : off 1st & 2nd led");
	while(1)
	{
		if(sw1==0)
		{
			while(sw1==0);
			f1^=1;
		}
		if(sw2==0)
		{
			while(sw2==0);
			f2^=1;
		}
		if(sw3==0)
		{
			while(sw3==0);
			f3^=1;
				if(f3)
				{
					f1=1;
					f2=1;
				}
				else
				{
					f1=0;
					f2=0;
				}			
		}
		if(f1)
			IOCLR0=led1;
		else
			IOSET0=led1;

		if(f2)
			IOCLR0=led2;
		else
			IOSET0=led2;
		if(flag)
		{
			flag=0;
			switch(temp)
			{
			
				case '1':f1=1;//IOCLR0=led1;
						break;
				case '2':f1=0;//IOSET0=led1;
						break;
				case '3':f2=1;//IOCLR0=led2;
						break;
				case '4':f2=0;//IOSET0=led2;
						break;
				case '5':f3=f2=f1=1;//IOCLR0=led1|led2;
						break;
				case '6':f3=f2=f1=0;//IOSET0=led1|led2;
						break;
			}
			uart0_tx_string("\r\nMenu:");
			uart0_tx_string("\r\n1 : on 1st led");
			uart0_tx_string("\r\n2 : off 1st led");
			uart0_tx_string("\r\n3 : on 2st led");
			uart0_tx_string("\r\n4 : off 2st led");
			uart0_tx_string("\r\n5 : on 1st & 2nd led");
			uart0_tx_string("\r\n6 : off 1st & 2nd led");
		}
	
	}

}

