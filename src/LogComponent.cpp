#include "LogComponent.h"
using namespace nlog;



bool LogComponent::shouldLogThread()
{
    return flag & NLOG_FLG_THREAD;
}

bool LogComponent::shouldLogTime()
{
    return flag & NLOG_FLG_TIME;
}

bool LogComponent::shouldLogTag()
{
    return flag & NLOG_FLG_TAG;
}

bool LogComponent::isConfigable()
{
    return flag & NLOG_FLG_CONFIG;
}
