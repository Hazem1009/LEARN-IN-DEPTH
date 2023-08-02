
MEMORY
{
	FLASH(rx) : ORIGIN = 0x08000000 , LENGTH = 128K
	SRAM(rwx) : ORIGIN = 0x20000000 , LENGTH = 20K
}

SECTIONS 
{
	.text : {
		*(.vectors*)
		*(.text*)
		*(.rodata*)
		. = ALIGN(4);
		_E_TEXT = . ;
	}>FLASH

	.data : {	
		_S_DATA = . ;
		*(.data*)
		. = ALIGN(4);
		_E_DATA = . ;
	}>SRAM AT> FLASH

	.bss : {
		_S_BSS = . ;
		*(.bss*)
		. = ALIGN(4);
		_E_BSS = . ;

	}>SRAM
	. = . + 0x1000 ; 

	_stack_top = . ;

}