#include <gtest/gtest.h>
#include "DefaultTree.h"
using namespace nlog;
using namespace testing::internal;

Logger* logger;

TEST(SimpleTest, Hello) {
    printf("\nTested success\n");
}

TEST(DefaultLog, WithDebug) {
    CaptureStdout();
    logger->logd("Hello %d, %d, %d", 1, 2, 3);
    EXPECT_TRUE(GetCapturedStdout().find("Hello 1, 2, 3") != std::string::npos);
}

TEST(DefaultLog, Dbg_With_Len_1024) {
    char buf[1024] = {'0'};
    memset(buf, '0', 1024);
    buf[1023] = '\0';

    CaptureStdout();
    logger->logd(buf);

    auto ret = GetCapturedStdout();
    EXPECT_EQ(ret.length(), 1024);
}

TEST(DefaultLog, WithError) {
    CaptureStderr();
    logger->loge("Hello %d, %d, %d", 1, 2, 3);
    EXPECT_TRUE(GetCapturedStderr().find("Hello 1, 2, 3") != std::string::npos);
}

TEST(DefaultLog, Err_With_Len_1024) {
    char buf[1024] = {'0'};
    memset(buf, '0', 1024);
    buf[1023] = '\0';

    CaptureStderr();
    logger->loge(buf);

    auto ret = GetCapturedStderr();
    EXPECT_EQ(ret.length(), 1024);
}

int main(int argc, char **argv) {
    logger = Logger::instance();
    logger->tag = "NLog";
//    logger->f_log_d = [](const char* message) {
//        std::cout << message << std::endl;
//    };

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
