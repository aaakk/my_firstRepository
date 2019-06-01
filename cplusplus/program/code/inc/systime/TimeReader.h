#pragma once

NS_LIANG_BEG

struct TimeReader
{
    virtual void readTime() = 0;
    virtual void readCurTime() = 0;
};

NS_LIANG_END
