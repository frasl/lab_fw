#include "uart_command_manager.h"
#include "usart.h"

extern UART_HandleTypeDef huart1;

UARTCommandManager::UARTCommandManager(ICmdProcessor **proc, size_t count) : 
    _proc(proc),
    _proc_count(count)
{

}

void UARTCommandManager::onCommand()
{
    for (size_t i = 0; i < _proc_count; ++i)
    {
        if (_proc[i]->onCommand(_cmd_buffer, _cmd_buffer_size))        
            return;
        
    }

    static const char msg_buf[] = "Command not found, try \"help\"\r\n";
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
            onCommand();
            _cmd_buffer_size = 0;
            dst_ptr = _cmd_buffer;
            break;

        default:
            *(dst_ptr++) = *pData;
            ++_cmd_buffer_size;
        }
    }   
}

