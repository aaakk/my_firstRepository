#include "nsport.h"
#include "singleton.h"
#include "role.h"
#include "systime/TimeInfo.h"
#include "systime/TimeManager.h"

NS_LIANG_BEG

class TimeReader;
class TimeRecorder;

namespace
{
    SINGLETON(SysTime), public TimeInfo
                      , private TimeManager
    {
    private:
        IMPL_ROLE(TimeReader);
        IMPL_ROLE(TimeRecorder);
    };
}

TimeInfo& getTimer()
{
    return static_cast<TimeInfo&>(*SysTime::getInstance()); 
}

NS_LIANG_END
