/*
*******************
*/

#include <stddef.h>
#include <main.h>
#include "uart.hpp"

USARTPerif::USARTPerif()
{
    pUsart = NULL;
}

USARTPerif* USARTPerif::getInstance()
{
    static USARTPerif usart_instance;
    return &usart_instance;
}

void USARTPerif::Initialize(uint32_t UsartBaseAddress, uint32_t BaudRate)
{
    USARTPerif* pInstance = getInstance();
    pInstance->pUsart = (USART_TypeDef*) UsartBaseAddress;
    pInstance->pUsart->BRR = UART_BRR_SAMPLING16(HAL_RCC_GetPCLK2Freq(), BaudRate);
    pInstance->pUsart->CR1 = (USART_CR1_TE | USART_CR1_RE | USART_CR1_RXNEIE);
    pInstance->pUsart->CR1 |= USART_CR1_UE;
}
