#include "templates.h"
#include "command_handler.h"
#include "blinker.h"

template <> void fetch_param(const char *pstr, size_t len, FWT::str &str)
{
    str.assign(pstr, len);
}

template <> void fetch_param(const char *pstr, size_t len, int &num)
{
    num = FWT::parse_dec<int>(pstr, len);
}

template <>
    void FillParamTuple(const char *params, size_t length, FWT::tuple<void> &tup)
{        
}