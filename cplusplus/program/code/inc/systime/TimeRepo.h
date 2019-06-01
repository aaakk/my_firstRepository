#pragma once

NS_LIANG_BEG

struct TimeRepo
{
    int year{0};
    int month{0};
    int day{0};
    int hour{0};
    int minute{0};
    int second{0};
    int msecond{0};
    int usecond{0};

    void reset()
    {
        year    = 0;
        month   = 0;
        day     = 0;
        hour    = 0;
        minute  = 0;
        second  = 0;
        msecond = 0;
    }
}

NS_LIANG_END