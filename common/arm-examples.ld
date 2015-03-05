/* arm-examples.ld - derived from TI's Blinky linker script */

MEMORY
{
    FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 0x00100000
    SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 0x00040000
}

SECTIONS
{
    .text :
    {
        __text_start__ = .;
        KEEP(*(.isr_vector))
        *(.text*)
        *(.rodata*)
        __text_end__ = .;
    } > FLASH

    .data : AT(ADDR(.text) + SIZEOF(.text))
    {
        __data_start__ = .;
        *(vtable)
        *(.data*)
        __data_end__ = .;
    } > SRAM

    .bss :
    {
        __bss_start__ = .;
        *(.bss*)
        *(COMMON)
        __bss_end__ = .;
    } > SRAM

}
/*
.ARM.exidx : 
{
__exidx_start__ = .;
*(.ARM.exidx* .gnu.linkonce.armexidx.*)
__exidx_end__ = .;
} > SRAM 
*/
