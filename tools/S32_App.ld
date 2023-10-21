MEMORY
{
    FLASH1(rx): ORIGIN = 0X00000000, LENGTH =0X00000400
    FLASH_CONFIG(rx): ORIGIN =Ox00000400, LENGTH =Ox00000010
    FLASH2(rx): ORIGIN =Ox00000400, LENGTH =Ox00000010
    SRAM1(rwx): ORIGIN =Ox00000400, LENGTH =Ox00000010
    SRAM2(rwx): ORIGIN =Ox00000400, LENGTH =Ox00000010
}

SECTION
{
    .intvec :
    {
    *(.intvec)
    . =ALIGN(4);
    }> FLASH1

    .flashConfig :
    {
    *(.flashConfig)
    . =ALIGN(4);
    }> FLASH1

    .text :
    {
    *(.text)
    . =ALIGN(4);
    }> FLASH2

    .data :
    {
    *(.data)
    . =ALIGN(4);
    }> FLASH2 AT> SRAM1

    .bss :
    {
    *(.bss)
    . =ALIGN(4);
    }> FLASH2 AT> SRAM1
}