#ifndef NLOGGER_H
#define NLOGGER_H

#include "NLog_global.h"
#include "NLog.h"
#include <string>
#include <cstdarg>
#include <iostream>

#define NLOG_ACTION(NAME, LVL) \
    LogAction f_log_##NAME = [](const char* message) { \
    std::cout << message << std::endl;  \
    };  \
    void log##NAME(const char *format, ...)    \
{   \
    if (!(level & LVL)) {  \
    return; \
    }   \
    \
    va_list args;   \
    va_start(args, format); \
    \
    LogComponent comp = *this;  \
    auto message = vformat(std::move(comp), format, args);  \
    comp.level = LVL;  \
    NLog _log(std::move(comp), message.data()); \
    \
    va_end(args);   \
    \
    log(std::move(_log), f_log_##NAME);  \
    }   \
    \
    void log##NAME##Tag(const char *tag, const char *format, ...)  \
{   \
    if (!(level & LVL)) {  \
    return; \
    }   \
    \
    va_list args;   \
    va_start(args, format); \
    \
    LogComponent component = *this; \
    component.tag = tag;    \
    component.level = LVL; \
    \
    auto message = vformat(std::move(component), format, args); \
    NLog _log(std::move(component), message.data());    \
    \
    va_end(args);   \
    \
    log(std::move(_log), f_log_##NAME);  \
    }   \
    \
    void log##NAME##With(LogComponent &&component, const char *format, ...)    \
{   \
    NLOG_LVL level = this->level & component.level; \
    if (!(level & LVL)) {  \
    return; \
    }   \
    \
    va_list args;   \
    va_start(args, format); \
    \
    auto message = vformat(std::move(component), format, args); \
    NLog _log(std::move(component), message.data());    \
    \
    va_end(args);   \
    \
    log(std::move(_log), f_log_##NAME);  \
    }

namespace nlog {

class NLOG_EXPORT Logger : public LogComponent {
private:
    typedef void(*LogAction)(const char* msg);
public:
    std::string (*f_thread_fmt)() = nullptr;
    std::string (*f_time_fmt)() = nullptr;

    virtual std::string vformat(LogComponent&& component, const char* fmt, va_list args);

    void logException(std::exception& e, std::string&& err = "");
    void logException(std::exception_ptr e, std::string&& err = "");
    void log(NLog&& message, LogAction action);

    NLOG_ACTION(d, NLOG_LVL_DBG)
    NLOG_ACTION(e, NLOG_LVL_ERR)

    static Logger* instance();
    static void setInstance(Logger* logger);
};

}

#endif // NLOGGER_H
