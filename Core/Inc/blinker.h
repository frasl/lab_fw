#ifndef _BLINKER_H_
#define _BLINKER_H_

class Blinker {

public:
    static Blinker &getInstance()
    {
        static Blinker b;

        return b;
    }

    void setBlink(bool shall_i)
    {
        _do_i_blink = shall_i;
    }

    void processBlinkEvent();

private:
    Blinker() :
        _do_i_blink(false),
        _current_blink(false)
    {}

    bool _do_i_blink;
    bool _current_blink;
};

#endif