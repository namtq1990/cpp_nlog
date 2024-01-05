#ifndef NLOG_GLOBAL_H
#define NLOG_GLOBAL_H

#if defined(_MSC_VER) || defined(WIN64) || defined(_WIN64) || defined(__WIN64__) || defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#  define Q_DECL_EXPORT __declspec(dllexport)
#  define Q_DECL_IMPORT __declspec(dllimport)
#else
#  define Q_DECL_EXPORT     __attribute__((visibility("default")))
#  define Q_DECL_IMPORT     __attribute__((visibility("default")))
#endif

#if defined(NLOG_LIBRARY)
#  define NLOG_EXPORT Q_DECL_EXPORT
#else
#  define NLOG_EXPORT Q_DECL_IMPORT
#endif

#include <cstdint>

#define NLOG_LVL_EMER   0x01
#define NLOG_LVL_ALRT   0x02
#define NLOG_LVL_CRIT   0x04
#define NLOG_LVL_ERR    0x08
#define NLOG_LVL_WARN   0x10
#define NLOG_LVL_NOTI   0x20
#define NLOG_LVL_INF    0x40
#define NLOG_LVL_DBG    0x80

#define NLOG_FLG_THREAD 0x01
#define NLOG_FLG_TIME   0x02
#define NLOG_FLG_TAG    0x04
#define NLOG_FLG_CONFIG 0x08

typedef uint8_t NLOG_LVL;
typedef uint8_t NLOG_FLG;

#endif // NLOG_GLOBAL_H
