#include "gpio.h"
#include "blinker.h"

void Blinker::processBlinkEvent()
{
    if (_do_i_blink)
    {
        HAL_GPIO_WritePin(LEDR_GPIO_Port, LEDR_Pin, _current_blink ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(LEDG_GPIO_Port, LEDG_Pin, _current_blink ? GPIO_PIN_RESET : GPIO_PIN_SET);

        _current_blink = !_current_blink;
    }
}