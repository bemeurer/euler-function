#if defined(_WIN32) || defined(_WIN64)
#define OS_WINDOWS
#elif defined(__APPLE__)
#define OS_MACOS
#elif defined(__unix__) || defined(__unix)
#define OS_LINUX
#else
#error Unsupported Platform.
#endif

#if defined(OS_MACOS) || defined(OS_LINUX)

#include <unistd.h>

#elif defined(OS_WINDOWS)
#include <io.h>
#include <windows.h>
#endif

#include <iostream>
#include <cstdio>

namespace color {
    namespace _internal {
        inline FILE *get_standard_stream(const std::ostream &stream);

        inline bool is_atty(const std::ostream &stream);

#if defined(OS_WINDOWS)
        void win_change_attributes(std::ostream& stream, int foreground, int background=-1);
#endif
    }

    inline
    std::ostream &red(std::ostream &stream) {
        if (_internal::is_atty(stream)) {
#if defined(OS_MACOS) || defined(OS_LINUX)
            stream << "\033[31m";
#elif defined(OS_WINDOWS)
            _internal::win_change_attributes(stream,FOREGROUND_RED);
#endif
        }
        return stream;
    }

    inline
    std::ostream &green(std::ostream &stream) {
        if (_internal::is_atty(stream)) {
#if defined(OS_MACOS) || defined(OS_LINUX)
            stream << "\033[32m";
#elif defined(OS_WINDOWS)
            _internal::win_change_attributes(stream,FOREGROUND_GREEN);
#endif
        }
        return stream;
    }

    inline
    std::ostream &grey(std::ostream &stream) {
        if (_internal::is_atty(stream)) {
#if defined(TERMCOLOR_OS_MACOS) || defined(TERMCOLOR_OS_LINUX)
            stream << "\033[30m";
#elif defined(TERMCOLOR_OS_WINDOWS)
            _internal::win_change_attributes(stream,0);
#endif
        }
        return stream;
    }

    namespace _internal {
        //! Since C++ hasn't a true way to extract stream handler
        //! from the a given `std::ostream` object, I have to write
        //! this kind of hack.
        inline
        FILE *get_standard_stream(const std::ostream &stream) {
            if (&stream == &std::cout)
                return stdout;
            else if ((&stream == &std::cerr) || (&stream == &std::clog))
                return stderr;

            return nullptr;
        }

        inline
        bool is_atty(const std::ostream &stream) {
            FILE *std_stream = get_standard_stream(stream);
#if defined(OS_MACOS) || defined(OS_LINUX)
            return ::isatty(fileno(std_stream));
#elif defined(OS_WINDOWS)
            return ::_isatty(_fileno(std_stream));
#endif
        }

#if defined(OS_WINDOWS)
        void win_change_attributes(std::ostream& stream, int foreground, int background)
        {
            static WORD defaultAttributes = 0;
            HANDLE hTerminal = INVALID_HANDLE_VALUE;
            if (&stream == &std::cout)
                hTerminal = GetStdHandle(STD_OUTPUT_HANDLE);
            else if (&stream == &std::cerr)
                hTerminal = GetStdHandle(STD_ERROR_HANDLE);
            if (!defaultAttributes)
            {
                CONSOLE_SCREEN_BUFFER_INFO info;
                if (!GetConsoleScreenBufferInfo(hTerminal, &info))
                    return;
                defaultAttributes = info.wAttributes;
            }
            if (foreground == -1 && background == -1)
            {
                SetConsoleTextAttribute(hTerminal, defaultAttributes);
                return;
            }
            CONSOLE_SCREEN_BUFFER_INFO info;
            if (!GetConsoleScreenBufferInfo(hTerminal, &info))
                return;

            if (foreground != -1)
            {
                info.wAttributes &= ~(info.wAttributes & 0x0F);
                info.wAttributes |= static_cast<WORD>(foreground);
            }

            if (background != -1)
            {
                info.wAttributes &= ~(info.wAttributes & 0xF0);
                info.wAttributes |= static_cast<WORD>(background);
            }

            SetConsoleTextAttribute(hTerminal, info.wAttributes);
       }
#endif
    }
}