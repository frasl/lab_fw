"# lab_fw" 

For compile please use:

make all STM_CUBE_PATH=c:\Users\xxx\STM32Cube\Repository\STM32Cube_FW_F2_V1.x.x -j 8

!!! substitute "x" chars !!!


NAND datasheet 4.1 Command Latch cycle diagram:

SetupTime - определяет сколько тактов HSE прошло между тем, как CE стало 0 и тем как WE так же стало 0 ((tCS - tWP) in NAND datasheet).
WaitSetupTime - Время, которое WE находится в 0 (tWP in NAND datasheet).
HoldSetupTime - Время, которое продолжают идти адресные данные после установки WE в 1. (В расчётах данного параметра можно опираться на время установки СЕ) (tch in NAND datasheet)
HiZSetupTime - Время в тактах, которое проходит между тем как CE стало 0 и началом передачи команды. (tcs-tds)

