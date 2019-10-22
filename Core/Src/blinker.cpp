
#include "gpio.h"
#include "GPIORegisters.hpp"
#include "blinker.h"

void Blinker::initBlinker()
{
    using RedLed = registers::GpioPin< GPIOC_BASE, 9>;
    using GreenLed = registers::GpioPin< GPIOC_BASE, 10>;
    RedLed::OutputPushPull();
    GreenLed::OutputPushPull();
}

void Blinker::processBlinkEvent()
{
    using RedLed = registers::GpioPin< GPIOC_BASE, 9>;
    using GreenLed = registers::GpioPin< GPIOC_BASE, 10>;
    if (_do_i_blink)
    {
        RedLed::Toggle();
        GreenLed::Toggle();
    }
}