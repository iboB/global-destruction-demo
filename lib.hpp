#pragma once

#if defined(_MSC_VER)
#   define SYMBOL_EXPORT __declspec(dllexport)
#   define SYMBOL_IMPORT __declspec(dllimport)
#else
#   define SYMBOL_EXPORT __attribute__((__visibility__("default")))
#   define SYMBOL_IMPORT
#endif

#if LIB_SHARED
#if BUILDING_LIB
#   define LIB_API SYMBOL_EXPORT
#else
#   define LIB_API SYMBOL_IMPORT
#endif
#else
#define LIB_API
#endif

class LIB_API thread_runner
{
public:
    thread_runner();
    ~thread_runner();

    static void init();

    class impl;
private:
};
