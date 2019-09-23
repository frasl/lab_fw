#ifndef _TEMPLATES_H_
#define _TEMPLATES_H_

#include <string.h>

#include "types.h"
#include "mem.h"
#include "errors.h"

namespace FWT {

template <typename Head, typename ...Tail> class tuple {
public:
   
public:
    typedef Head elem_type; 

    tuple(Head h, Tail ...t) :
        _data(h),
        _rest(t...)
    {

    }

    tuple()
    {

    }

    void set(const Head &val)
    {
        _data = val;
    }

    const Head &get() const
    {
        return _data;
    }

    const tuple <Tail ...> &get_rest() const 
    {
        return _rest; 
    } 

private:
    Head _data;
    tuple <Tail...> _rest;
};

template <typename Tail> class tuple<Tail> {
    public:
    tuple(Tail t) :
        _data(t)
    {

    }

    tuple()
    {

    }

    const Tail &get() const
    {
        return _data;
    }

    void set(const Tail &val)
    {
        _data = val;
    }

private:
    Tail _data;
};

template <> class tuple<void> {
    public:
    tuple() 
    {

    }    

private:
};

template <typename ...Args> tuple<Args...> make_tuple(Args... args)
{
    return tuple<Args...>(args...);
}




template <size_t I, typename ...T> struct tuple_element;
template <size_t I, typename Head, typename ...Tail> struct tuple_element<I, Head, Tail...> {
        typedef typename tuple_element<I - 1, Tail...>::type type;    
};

template <typename Head, typename ...Tail> struct tuple_element<0, Head, Tail...> {
    typedef Head type;    
};

template<size_t Index> struct tuple_at;

template<>
struct tuple_at<0>
{
    template<typename... Args>
    static auto get(const tuple<Args...> & source)
    {
        return source.get();
    }
};

template<size_t Index>
struct tuple_at
{
    template<typename... Args>
    static auto get(const tuple<Args...> & source)
    {
        static_assert
            ( Index < sizeof...(Args), " <- Index out of range" );
        return tuple_at<Index - 1>::get(source.get_rest());
    }
};


template <typename First, typename Second> class pair {
public:
    First first;
    Second second;

    pair(const First &f, const Second &s) :
        first(f),
        second(s)
    {

    }
};

template <typename CharT = char, size_t max_len = 64> class base_str {
public:
    void assign(const CharT *from, size_t len)
    {
        assert(len < max_len, "String out of bounds");
        strncpy(_buf, from, len);
        _buf[len] = 0; 
    }

    base_str<CharT, max_len> &operator=(const CharT *from)
    {
        strcpy(_buf, from);
    }

    operator const CharT *() const
    {
        return _buf; 
    }

    base_str(const base_str<CharT, max_len> &from)
    {
        strcpy(_buf, from._buf);
    }

    base_str(const CharT *from) 
    {
        strcpy(_buf, from);
    }    

private:
    CharT _buf[max_len];
};

typedef base_str<char, 64> str;

template <typename T> class function
{
public:
    template <typename ...Args> 
        function<T> &operator()(Args ... args)
        {
            _callable(args...);
            return *this; 
        }


    function(const T &fn) : _callable(fn)
    {}

    function(const function<T> &f) :
        _callable(f._callable)
    {}

private:
    const T &_callable;
};

template <typename T> 
    function <T> make_fn(const T &fn)
{
    return function<T>(fn);    
}

template <typename T> T parse_dec(const char *str, size_t len)
{
    T ret_val = 0;
    for (size_t i = 0; i < len; ++i)
    {
        ret_val *= 10; 
        ret_val += (str[i] - '0');
    }

    return ret_val; 
}

template <typename T> T min(const T a, const T b)
{
    return a < b ? a : b;
}

};

#endif