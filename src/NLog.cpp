#include "NLog.h"
using namespace nlog;

NLog::NLog() {

}

NLog::NLog(LogComponent &&com, const char *message)
    : component(com),
      message(message)
{

}
