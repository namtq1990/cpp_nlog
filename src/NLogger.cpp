#include "NLogger.h"
using namespace nlog;

std::string Logger::vformat(LogComponent &&component, const char *fmt, va_list args)
{
    char buf[NLOG_BUF_SIZE];     // TODO Increase this buff size
    char* p = buf;
    int size = 0;

    if (f_time_fmt && component.shouldLogTime()) {
        std::string time = f_time_fmt();
        int size = sprintf(p, "[%s]", time.data());
        p += size;
    }

    if (f_thread_fmt && component.shouldLogThread()) {
        std::string thread = f_thread_fmt();
        int size = sprintf(p, "[%s]", thread.data());
        p += size;
    }

    if (component.shouldLogTag()) {
        int size = sprintf(p, "[%s]", component.tag);
        p += size;
    }

    *(p++) = ' ';

    size = p - buf;
    size += vsnprintf(p, NLOG_BUF_SIZE - size, fmt, args);
    size = std::min(size, NLOG_BUF_SIZE - 1);
    buf[size] = '\0';

    return buf;
}

void Logger::logException(std::exception &e, std::string &&err)
{
    loge("%s: %s, errno: %d", err.empty() ? "Exception" : err.data(), e.what(), errno);
}

void Logger::logException(std::__exception_ptr::exception_ptr e, std::string &&err)
{
    try {
        std::rethrow_exception(e);
    }  catch (std::exception& ex) {
        logException(ex, std::move(err));
    }
}

void Logger::log(NLog &&message, LogAction action)
{
    if (!message.message || !message.component.level || !action)
        return;

    action(message.message);
}

