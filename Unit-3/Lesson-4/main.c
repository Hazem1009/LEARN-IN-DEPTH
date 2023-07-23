/*Define Registers Addresses for PORTF GPIO LED*/
#define SYSCTL_RCGC2_R *((volatile unsigned long*) 0x400FE108)
#define GPIO_PORTF_DATA_R *((volatile unsigned long*) 0x400253FC)
#define GPIO_PORTF_DIR_R *((volatile unsigned long*) 0x40025400)
#define GPIO_PORTF_DEN_R *((volatile unsigned long*) 0x4002551C)


void main()
{
	// init GPIO
	SYSCTL_RCGC2_R =0x20;

	//delay to wait for module enable

	volatile unsigned int i=0;
	for(i=0;i<20;i++);

	//DIR OUTPUT
	GPIO_PORTF_DIR_R |=(1<<3);
	//DEN ON 
	GPIO_PORTF_DEN_R |=(1<<3);

	while(1)
	{
		//TOGGLE LED With delay

		//ON
		GPIO_PORTF_DATA_R|=(1<<3);
		for(i=0;i<10;i++);

		//OFF
		GPIO_PORTF_DATA_R&=~(1<<3);
		for(i=0;i<10;i++);
	}
}