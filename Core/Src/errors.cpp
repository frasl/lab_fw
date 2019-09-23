#include "errors.h"
#include "usart.h"
#include "string.h"

void assert(bool condition, const char *error)
{
    if (!condition)
    {
        HAL_UART_Transmit(&huart1, (uint8_t *)error, strlen(error), 1000);
        while (1);
    }
}