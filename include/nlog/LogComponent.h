#ifndef LOGCOMPONENT_H
#define LOGCOMPONENT_H

#include "NLog_global.h"

namespace nlog {

struct NLOG_EXPORT LogComponent {
    NLOG_FLG flag = 0xFF;
    NLOG_LVL level = NLOG_LVL_DBG;
    const char* tag = nullptr;

    bool shouldLogThread();
    bool shouldLogTime();
    bool shouldLogTag();
    bool isConfigable();
};

}

#endif // LOGCOMPONENT_H
