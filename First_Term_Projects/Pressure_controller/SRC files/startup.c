#include "Platform_Types.h"
extern int main(void);
extern uint32 _stack_top;

//Vector Handler
void Reset_Handler(void);
void NMI_Handler(void) __attribute__((weak,alias("Default_Handler")));
void Hard_Fault_Handler(void) __attribute__((weak,alias("Default_Handler")));
void MM_Fault_Handler(void) __attribute__((weak,alias("Default_Handler")));
void Bus_Fault_Handler(void) __attribute__((weak,alias("Default_Handler")));
void Usage_Fault_Handler(void) __attribute__((weak,alias("Default_Handler")));


vuint32 vectors[] __attribute__((section(".vectors"))) = 
{
	(vuint32) &_stack_top,
	(vuint32) &Reset_Handler,
	(vuint32) &NMI_Handler,
	(uint32)  &Hard_Fault_Handler,
	(uint32)  &MM_Fault_Handler,
	(uint32)  &Bus_Fault_Handler,
	(uint32)  &Usage_Fault_Handler
};

extern uint32 _E_text;
extern uint32 _S_DATA;
extern uint32 _E_DATA;
extern uint32 _S_rodata;
extern uint32 _E_rodata;
extern uint32 _S_BSS;
extern uint32 _E_BSS;


void Reset_Handler (void)
{
	int i;
	
	//copy .data section from flash to ram
	uint32 DATA_size = (uint8 *)&_E_DATA - (uint8 *)&_S_DATA ;
	uint8 *P_src = (uint8 *)&_E_text ;
	uint8 *P_dst = (uint8 *)&_S_DATA ;
	for(i = 0; i < DATA_size; i++)
	{
		*((uint8 *)P_dst++) = *((uint8 *)P_src++); 
	}
	
	//locate .bss section in ram and initalize it with zero
	uint32 BSS_size = (uint8 *)&_E_BSS - (uint8 *)&_S_BSS ;
	P_dst = (uint8 *)&_S_BSS ;
	for(i = 0; i < BSS_size; i++)
	{
		*((uint8 *)P_dst++) = (uint8)0; 
	}
	
	//jump to main()
	main();
}

void Default_Handler (void)
{
	Reset_Handler();
}