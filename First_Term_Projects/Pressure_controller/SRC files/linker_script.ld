/*bY*/
/*ENG : arafa*/


MEMORY
{
FLASH (RX) : ORIGIN = 0x08000000 ,LENGTH = 128K
SRAM (RWX) : ORIGIN = 0x20000000 , LENGTH = 20K

}

SECTIONS
{
	.text :
	{
		*(.vectors*)
		*(.text*)
		*(.rodata)
		_E_text = . ;
	}> FLASH
	.data :
	{
	_S_DATA = .;
	*(.data
	*(.data.*))
	*(.data.*)
	. = ALIGN(4);
	_E_DATA = .;
	}> SRAM AT> FLASH
	
	.bss :
	{
	_S_BSS = .;
	*(.bss*)
	_E_BSS = .;
	. = ALIGN(4);
	.
	_heap_End = .;
	. = ALIGN(4);
	. = . +0x1000; = . +0x1000;
	_heap_End = .;
	. = ALIGN(4);
	. = . +0x1000;
	_stack_top = .;
	}> SRAM
}