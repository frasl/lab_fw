#include "gpio.h"
#include "blinker.h"

#include "RegistersTemplate.hpp"

void Blinker::processBlinkEvent()
{
    using RedLed = registers::GpioPin< GPIOC_BASE, LEDR_Pin >;
    using RedGreen = registers::GpioPin< GPIOC_BASE , LEDR_Pin >;
    if (_do_i_blink)
    {
        RedLed::Toggle();
        RedGreen::Toggle();
    }
}