#include "DefaultTree.h"
#include <thread>
#include <sstream>
#include <time.h>
using namespace nlog;
using namespace std;

Logger* S_NLOG_INSTANCE = nullptr;

DefaultTree::DefaultTree() {
    this->level = 0xFF;
    this->f_log_e = [](const char* log) {
        std::cerr << log << endl;
    };
    this->f_thread_fmt = []() -> std::string {
            std::stringstream ss;
            ss << "0x" << hex << std::this_thread::get_id();
            return ss.str();
    };
    this->f_time_fmt = []() -> string {
        const size_t maxlen = 32;
        char buf[maxlen] = {0};
        time_t     now = time(0);
        struct tm  tstruct;
        tstruct = *localtime(&now);
        strftime(buf, maxlen, "%Y-%m-%d %H:%M:%S", &tstruct);

        return buf;
    };
}

Logger* Logger::instance() {
    if (!S_NLOG_INSTANCE) {
        S_NLOG_INSTANCE = new DefaultTree();
    }

    return S_NLOG_INSTANCE;
}

void Logger::setInstance(Logger *logger) {
    S_NLOG_INSTANCE = logger;
}
