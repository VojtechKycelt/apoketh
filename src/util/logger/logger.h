#pragma once
#include <iostream>
#include <cstdarg>

namespace logger_apoketh
{
    // Internal helper to print prefix with optional color
    inline void print_prefix(const char* level, const char* color)
    {
        std::cout << color << "[" << level << "] " << "\033[0m"; // reset color
    }

    // Warning log (yellow)
    inline void warning(const char* fmt, ...)
    {
        print_prefix("WARNING", "\033[33m");

        va_list args;
        va_start(args, fmt);
        vprintf(fmt, args);
        va_end(args);

        std::cout << std::endl;
    }

    // Info log (cyan)
    inline void info(const char* fmt, ...)
    {
        print_prefix("INFO", "\033[36m");

        va_list args;
        va_start(args, fmt);
        vprintf(fmt, args);
        va_end(args);

        std::cout << std::endl;
    }

    // Error log (red)
    inline void error(const char* fmt, ...)
    {
        print_prefix("ERROR", "\033[31m");

        va_list args;
        va_start(args, fmt);
        vprintf(fmt, args);
        va_end(args);

        std::cout << std::endl;
    }
}

// Convenience macros — globally available
#define warning(...) ::logger_apoketh::warning(__VA_ARGS__)
#define info(...)    ::logger_apoketh::info(__VA_ARGS__)
#define error(...)   ::logger_apoketh::error(__VA_ARGS__)

// Optional: disable logs in release builds
#ifdef NDEBUG
#undef warning
#undef info
#undef error
#define warning(...) ((void)0)
#define info(...)    ((void)0)
#define error(...)   ((void)0)
#endif
