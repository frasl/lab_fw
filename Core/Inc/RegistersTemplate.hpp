
#pragma once

#include <utility>

#define __forceinline __attribute__((always_inline))

namespace registers
{
    
struct WriteReg
{
};
struct ReadReg
{
};
struct ReadWriteReg : public WriteReg, public ReadReg
{
};

template <uint32_t addr, typename T, volatile uint32_t T::*member, typename RegType>
class Register
{
public:
    template <typename T1 = RegType,
                            class = typename std::enable_if_t<std::is_base_of<WriteReg, T1>::value>>
    __forceinline static void Xor(const uint32_t mask)
    {
        reinterpret_cast<T *>(addr)->*member ^= mask;
    }
    template <typename T1 = RegType,
                            class = typename std::enable_if_t<std::is_base_of<WriteReg, T1>::value>>
    __forceinline static uint32_t GetValue()
    {
        return reinterpret_cast<T *>(addr)->*member;
    }
    template <typename T1 = RegType,
                            class = typename std::enable_if_t<std::is_base_of<WriteReg, T1>::value>>
    __forceinline static void SetValue(const uint32_t value)
    {
        reinterpret_cast<T *>(addr)->*member |= (value);
    }
    template <typename T1 = RegType,
                            class = typename std::enable_if_t<std::is_base_of<WriteReg, T1>::value>>
    __forceinline static void SetBitDirect(const uint32_t bit)
    {
        reinterpret_cast<T *>(addr)->*member = (1 << bit);
    }
};

template <uint32_t addr>
struct Gpio
{
    using Moder = Register<addr, GPIO_TypeDef, &GPIO_TypeDef::MODER, ReadWriteReg>;
    using Otyper = Register<addr, GPIO_TypeDef, &GPIO_TypeDef::OTYPER, ReadWriteReg>;
    using Ospeedr = Register<addr, GPIO_TypeDef, &GPIO_TypeDef::OSPEEDR, ReadWriteReg>;
    using Pupdr = Register<addr, GPIO_TypeDef, &GPIO_TypeDef::PUPDR, ReadWriteReg>;
    using Idr = Register<addr, GPIO_TypeDef, &GPIO_TypeDef::IDR, ReadReg>;
    using Odr = Register<addr, GPIO_TypeDef, &GPIO_TypeDef::ODR, WriteReg>;
    using Bsrr = Register<addr, GPIO_TypeDef, &GPIO_TypeDef::BSRR, WriteReg>;    
};

template <uint32_t addr, uint32_t pin>
class GpioPin
{
public:    
    enum PinSpeed
    {
        LOW = 0b00,
        MEDIUM = 0b01,
        HIGH = 0b10,
        VERYHIGH = 0b11
    };
private:     
    using GPIOReg = Gpio<addr>;
public:
    __forceinline static void OutputPushPull(PinSpeed speed)
    {
        GPIOReg::Moder::SetValue((uint32_t)(0x01 << (pin * 2)));
        GPIOReg::Otyper::SetValue((uint32_t)(0x00 << pin));
        GPIOReg::Ospeedr::SetValue(speed << (pin * 2));
    }
    __forceinline static void Set(void)
    {
        GPIOReg::Bsrr::SetBitDirect(pin);
    }
    __forceinline static void Reset(void)
    {
        GPIOReg::Bsrr::SetBitDirect(pin + 0x10);
    }
    __forceinline static void Toggle(void)
    {        
        if (GPIOReg::Odr::GetValue() & pin)
        {
            GPIOReg::Bsrr::SetBitDirect(pin + 0x10);
        }
        else
        {
            GPIOReg::Bsrr::SetBitDirect(pin);
        }
    }
};

} // namespace registers
