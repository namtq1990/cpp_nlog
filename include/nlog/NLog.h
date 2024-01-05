#ifndef NLOG_H
#define NLOG_H

#include "NLog_global.h"
#include "LogComponent.h"

namespace nlog {

struct NLOG_EXPORT NLog
{
    LogComponent component;
    const char* message = nullptr;

    NLog();
    NLog(LogComponent&& com, const char* message);
};

}

#endif // NLOG_H
