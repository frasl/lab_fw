/*
*******************
*/

#pragma once

//#include <stm32f207xx.h>

class USARTPerif
{
private:
    USART_TypeDef* pUsart;
    USARTPerif();    
    USARTPerif* getInstance();
public:    
    void Initialize(uint32_t UsartBaseAddress, uint32_t BaudRate);
};
