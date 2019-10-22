#pragma once

#include <utility>
#include "RegistersTemplate.hpp"

namespace registers
{

template <uint32_t addr>
class Moder : public Register<addr, GPIO_TypeDef, &GPIO_TypeDef::MODER, ReadWriteReg>
{
private:
    static const uint32_t moder_mask = 0b11;
    static const uint32_t moder_input = 0b00;
    static const uint32_t moder_output = 0b01;
    static const uint32_t moder_alternate = 0b10;

    using reg = Register<addr, GPIO_TypeDef, &GPIO_TypeDef::MODER, ReadWriteReg>;
public:
    __forceinline static void AsInput(uint32_t pin)
    {        
        reg::ModifyBitMask(moder_mask, moder_input, (pin * 2U));
    }
    __forceinline static void AsOutput(uint32_t pin)
    {
        reg::ModifyBitMask(moder_mask, moder_output, (pin * 2U));
    }
    __forceinline static void AsAlternate(uint32_t pin)
    {
        reg::ModifyBitMask(moder_mask, moder_alternate, (pin * 2));
    }
};

template <uint32_t addr>
class Otyper : public Register<addr, GPIO_TypeDef, &GPIO_TypeDef::OTYPER, ReadWriteReg>
{
private:
    using reg = Register<addr, GPIO_TypeDef, &GPIO_TypeDef::OTYPER, ReadWriteReg>;
public:
    __forceinline static void AsPushPull(uint32_t pin)
    {
        reg::ResetBit(pin);
    }
    __forceinline static void AsOpenDrain(uint32_t pin)
    {
        reg::SetBit(pin);
    }
};

template <uint32_t addr, uint32_t pin>
class GpioPin
{
protected:    
    using moder = Moder<addr>;
    using otyper = Otyper<addr>;
    using Ospeedr = Register<addr, GPIO_TypeDef, &GPIO_TypeDef::OSPEEDR, ReadWriteReg>;
    using Pupdr = Register<addr, GPIO_TypeDef, &GPIO_TypeDef::PUPDR, ReadWriteReg>;
    using Idr = Register<addr, GPIO_TypeDef, &GPIO_TypeDef::IDR, ReadReg>;
    using Odr = Register<addr, GPIO_TypeDef, &GPIO_TypeDef::ODR, WriteReg>;
    using Bsrr = Register<addr, GPIO_TypeDef, &GPIO_TypeDef::BSRR, WriteReg>;
public:
    __forceinline static void OutputPushPull(void)
    {
        moder::AsOutput(pin);
        otyper::AsPushPull(pin);
        //Ospeedr::SetValue(speed << (pin * 2));
    }
    __forceinline static void Set(void)
    {
        Bsrr::SetBit(pin);
    }
    __forceinline static void Reset(void)
    {
        Bsrr::SetBit(pin + 0x10);
    }
    __forceinline static bool IsRised(void)
    {
        return (0 != Idr::GetBit(pin));
    }
    __forceinline static void Toggle(void)
    {
        volatile bool a = IsRised();
        if (a)
        {
            Reset();
        }
        else
        {
            Set();
        }
    }
};

} // namespace registers
