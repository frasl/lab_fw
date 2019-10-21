#include "gpio.h"
#include "blinker.h"

#include "RegistersTemplate.hpp"

void Blinker::initBlinker()
{
    using RedLed = registers::GpioPin< GPIOC_BASE, 9>;
    using RedGreen = registers::GpioPin< GPIOC_BASE , 10>;
    RedLed::OutputPushPull(RedLed::PinSpeed::LOW);
    RedGreen::OutputPushPull(RedGreen::PinSpeed::LOW);
}

void Blinker::processBlinkEvent()
{
    using RedLed = registers::GpioPin< GPIOC_BASE, 9>;
    using RedGreen = registers::GpioPin< GPIOC_BASE , 10>;
    if (_do_i_blink)
    {
        RedLed::Toggle();
        RedGreen::Toggle();
    }
}