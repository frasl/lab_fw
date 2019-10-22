/*

**********************************************

*/

#pragma once

#include <stdint.h>
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
                            class = typename std::enable_if_t<std::is_base_of<ReadReg, T1>::value>>
    __forceinline static uint32_t GetValue()
    {
        return reinterpret_cast<T *>(addr)->*member;
    }
    template <typename T1 = RegType,
                            class = typename std::enable_if_t<std::is_base_of<WriteReg, T1>::value>>
    __forceinline static void SetValue(const uint32_t value)
    {
        reinterpret_cast<T *>(addr)->*member = (value);
    }
    template <typename T1 = RegType,
                            class = typename std::enable_if_t<std::is_base_of<ReadReg, T1>::value>>
    __forceinline static bool GetBit(const uint32_t bit)
    {
        return (0 != (reinterpret_cast<T *>(addr)->*member & (0x01 << bit)));
    }
    template <typename T1 = RegType,
                            class = typename std::enable_if_t<std::is_base_of<WriteReg, T1>::value>>
    __forceinline static void SetBit(const uint32_t bit)
    {
        reinterpret_cast<T *>(addr)->*member |= (1 << bit);
    }
    template <typename T1 = RegType,
                            class = typename std::enable_if_t<std::is_base_of<WriteReg, T1>::value>>
    __forceinline static void ResetBit(const uint32_t bit)
    {
        reinterpret_cast<T *>(addr)->*member &= ~(1 << bit);
    }
    template <typename T1 = RegType,
                            class = typename std::enable_if_t<std::is_base_of<ReadReg, T1>::value>>
    __forceinline static uint32_t GetBitMask(const uint32_t mask, const uint32_t pos)
    {
        return (reinterpret_cast<T *>(addr)->*member & (mask << pos));
    }
    template <typename T1 = RegType,
                            class = typename std::enable_if_t<std::is_base_of<WriteReg, T1>::value>>
    __forceinline static void ClearBitMask(const uint32_t mask, const uint32_t pos)
    {

        return (reinterpret_cast<T *>(addr)->*member &= ~(mask << pos));
    }
    template <typename T1 = RegType,
                            class = typename std::enable_if_t<std::is_base_of<WriteReg, T1>::value>>
    __forceinline static void ModifyBitMask(const uint32_t mask_clear, const uint32_t mask_set, const uint32_t pos)
    {
        reinterpret_cast<T *>(addr)->*member = (reinterpret_cast<T *>(addr)->*member & ~(mask_clear << pos)) | (mask_set << pos);
    }
};


} // namespace registers
