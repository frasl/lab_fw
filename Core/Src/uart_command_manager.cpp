#include "uart_command_manager.h"
#include "usart.h"

extern UART_HandleTypeDef huart1;
static char msg_buf[128];

UARTCommandManager::UARTCommandManager(ICmdProcessor **proc, size_t count) : 
    _proc(proc),
    _proc_count(count)
{

}

void UARTCommandManager::onCommand()
{
    _cmd_buffer[_cmd_buffer_size] = 0;
    for (size_t i = 0; i < _proc_count; ++i)
    {
        if (_proc[i]->onCommand(_cmd_buffer, _cmd_buffer_size))        
            return;
        
    }

    strcpy(msg_buf, "Command not found, try \"help\"\r\n\0");
    HAL_UART_Transmit(&huart1, (uint8_t *)msg_buf, strlen(msg_buf), 1000);
}

void UARTCommandManager::ShowPrompt()
{
    strcpy(msg_buf, "O>\0");
    HAL_UART_Transmit(&huart1, (uint8_t *)msg_buf, strlen(msg_buf), 1000);
}

void UARTCommandManager::onData(const char *pData, size_t size)
{
    const char *src_ptr = pData;
    for (char *dst_ptr = _cmd_buffer + _cmd_buffer_size; src_ptr < pData + size; ++src_ptr)
    {
        switch (*src_ptr)
        {
        case '\n':
        case '\r':
            if (_cmd_buffer_size > 1)
            {
                onCommand();
                _cmd_buffer_size = 0;
                dst_ptr = _cmd_buffer;
            }
            ShowPrompt();
            break;
        default:
            *(dst_ptr++) = *pData;
            ++_cmd_buffer_size;
        }
    }   
}

