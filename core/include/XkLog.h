#ifndef XK_LOG_H
#define XK_LOG_H

#include "XkStable.h"
#include "XkFormat.h"

namespace Xk
{
    
class XkPublicClass XkLog
{
public:
    XkLog();
    ~XkLog();

    void fatal(const std::string& msg, const char* file, int line);
    void critical(const std::string& msg, const char* file, int line);
    void error(const std::string& msg, const char* file, int line);
    void warning(const std::string& msg, const char* file, int line);
    void notice(const std::string& msg, const char* file, int line);
    void information(const std::string& msg, const char* file, int line);
    void debug(const std::string& msg, const char* file, int line);
    void trace(const std::string& msg, const char* file, int line);
    void dump(const std::string& msg, const void* buffer, std::size_t length);

    bool fatal();
    bool critical();
    bool error();
    bool warning();
    bool notice();
    bool information();
    bool debug();
    bool trace();

public:
    static XkLog* defaultLogger();
};

////////////////////////

#define xk_fatal(msg) \
	if(Xk::XkLog::defaultLogger()->fatal()) Xk::XkLog::defaultLogger()->fatal(msg, __FILE__, __LINE__); else (void) 0

#define xk_fatal_f1(fmt, arg1) \
    if(Xk::XkLog::defaultLogger()->fatal()) Xk::XkLog::defaultLogger()->fatal(Xk::format((fmt), arg1), __FILE__, __LINE__); else (void) 0

#define xk_fatal_f2(fmt, arg1, arg2) \
    if(Xk::XkLog::defaultLogger()->fatal()) Xk::XkLog::defaultLogger()->fatal(Xk::format((fmt), (arg1), (arg2)), __FILE__, __LINE__); else (void) 0

#define xk_fatal_f3(fmt, arg1, arg2, arg3) \
    if(Xk::XkLog::defaultLogger()->fatal()) Xk::XkLog::defaultLogger()->fatal(Xk::format((fmt), (arg1), (arg2), (arg3)), __FILE__, __LINE__); else (void) 0

#define xk_fatal_f4(fmt, arg1, arg2, arg3, arg4) \
    if(Xk::XkLog::defaultLogger()->fatal()) Xk::XkLog::defaultLogger()->fatal(Xk::format((fmt), (arg1), (arg2), (arg3), (arg4)), __FILE__, __LINE__); else (void) 0

#define xk_critical(msg) \
	if(Xk::XkLog::defaultLogger()->critical()) Xk::XkLog::defaultLogger()->critical(msg, __FILE__, __LINE__); else (void) 0

#define xk_critical_f1(fmt, arg1) \
    if(Xk::XkLog::defaultLogger()->critical()) Xk::XkLog::defaultLogger()->critical(Xk::format((fmt), arg1), __FILE__, __LINE__); else (void) 0

#define xk_critical_f2(fmt, arg1, arg2) \
    if(Xk::XkLog::defaultLogger()->critical()) Xk::XkLog::defaultLogger()->critical(Xk::format((fmt), (arg1), (arg2)), __FILE__, __LINE__); else (void) 0

#define xk_critical_f3(fmt, arg1, arg2, arg3) \
    if(Xk::XkLog::defaultLogger()->critical()) Xk::XkLog::defaultLogger()->critical(Xk::format((fmt), (arg1), (arg2), (arg3)), __FILE__, __LINE__); else (void) 0

#define xk_critical_f4(fmt, arg1, arg2, arg3, arg4) \
    if(Xk::XkLog::defaultLogger()->critical()) Xk::XkLog::defaultLogger()->critical(Xk::format((fmt), (arg1), (arg2), (arg3), (arg4)), __FILE__, __LINE__); else (void) 0

#define xk_error(msg) \
	if(Xk::XkLog::defaultLogger()->error()) Xk::XkLog::defaultLogger()->error(msg, __FILE__, __LINE__); else (void) 0

#define xk_error_f1(fmt, arg1) \
    if(Xk::XkLog::defaultLogger()->error()) Xk::XkLog::defaultLogger()->error(Xk::format((fmt), arg1), __FILE__, __LINE__); else (void) 0

#define xk_error_f2(fmt, arg1, arg2) \
    if(Xk::XkLog::defaultLogger()->error()) Xk::XkLog::defaultLogger()->error(Xk::format((fmt), (arg1), (arg2)), __FILE__, __LINE__); else (void) 0

#define xk_error_f3(fmt, arg1, arg2, arg3) \
    if(Xk::XkLog::defaultLogger()->error()) Xk::XkLog::defaultLogger()->error(Xk::format((fmt), (arg1), (arg2), (arg3)), __FILE__, __LINE__); else (void) 0

#define xk_error_f4(fmt, arg1, arg2, arg3, arg4) \
    if(Xk::XkLog::defaultLogger()->error()) Xk::XkLog::defaultLogger()->error(Xk::format((fmt), (arg1), (arg2), (arg3), (arg4)), __FILE__, __LINE__); else (void) 0

#define xk_warning(msg) \
	if(Xk::XkLog::defaultLogger()->warning()) Xk::XkLog::defaultLogger()->warning(msg, __FILE__, __LINE__); else (void) 0

#define xk_warning_f1(fmt, arg1) \
    if(Xk::XkLog::defaultLogger()->warning()) Xk::XkLog::defaultLogger()->warning(Xk::format((fmt), arg1), __FILE__, __LINE__); else (void) 0

#define xk_warning_f2(fmt, arg1, arg2) \
    if(Xk::XkLog::defaultLogger()->warning()) Xk::XkLog::defaultLogger()->warning(Xk::format((fmt), (arg1), (arg2)), __FILE__, __LINE__); else (void) 0

#define xk_warning_f3(fmt, arg1, arg2, arg3) \
    if(Xk::XkLog::defaultLogger()->warning()) Xk::XkLog::defaultLogger()->warning(Xk::format((fmt), (arg1), (arg2), (arg3)), __FILE__, __LINE__); else (void) 0

#define xk_warning_f4(fmt, arg1, arg2, arg3, arg4) \
    if(Xk::XkLog::defaultLogger()->warning()) Xk::XkLog::defaultLogger()->warning(Xk::format((fmt), (arg1), (arg2), (arg3), (arg4)), __FILE__, __LINE__); else (void) 0

#define xk_notice(msg) \
	if(Xk::XkLog::defaultLogger()->notice()) Xk::XkLog::defaultLogger()->notice(msg, __FILE__, __LINE__); else (void) 0

#define xk_notice_f1(fmt, arg1) \
    if(Xk::XkLog::defaultLogger()->notice()) Xk::XkLog::defaultLogger()->notice(Xk::format((fmt), arg1), __FILE__, __LINE__); else (void) 0

#define xk_notice_f2(fmt, arg1, arg2) \
    if(Xk::XkLog::defaultLogger()->notice()) Xk::XkLog::defaultLogger()->notice(Xk::format((fmt), (arg1), (arg2)), __FILE__, __LINE__); else (void) 0

#define xk_notice_f3(fmt, arg1, arg2, arg3) \
    if(Xk::XkLog::defaultLogger()->notice()) Xk::XkLog::defaultLogger()->notice(Xk::format((fmt), (arg1), (arg2), (arg3)), __FILE__, __LINE__); else (void) 0

#define xk_notice_f4(fmt, arg1, arg2, arg3, arg4) \
    if(Xk::XkLog::defaultLogger()->notice()) Xk::XkLog::defaultLogger()->notice(Xk::format((fmt), (arg1), (arg2), (arg3), (arg4)), __FILE__, __LINE__); else (void) 0


#define xk_information(msg) \
	if(Xk::XkLog::defaultLogger()->information()) Xk::XkLog::defaultLogger()->information(msg, __FILE__, __LINE__); else (void) 0

#define xk_information_f1(fmt, arg1) \
    if(Xk::XkLog::defaultLogger()->information()) Xk::XkLog::defaultLogger()->information(Xk::format((fmt), arg1), __FILE__, __LINE__); else (void) 0

#define xk_information_f2(fmt, arg1, arg2) \
    if(Xk::XkLog::defaultLogger()->information()) Xk::XkLog::defaultLogger()->information(Xk::format((fmt), (arg1), (arg2)), __FILE__, __LINE__); else (void) 0

#define xk_information_f3(fmt, arg1, arg2, arg3) \
    if(Xk::XkLog::defaultLogger()->information()) Xk::XkLog::defaultLogger()->information(Xk::format((fmt), (arg1), (arg2), (arg3)), __FILE__, __LINE__); else (void) 0

#define xk_information_f4(fmt, arg1, arg2, arg3, arg4) \
    if(Xk::XkLog::defaultLogger()->information()) Xk::XkLog::defaultLogger()->information(Xk::format((fmt), (arg1), (arg2), (arg3), (arg4)), __FILE__, __LINE__); else (void) 0



#if defined(_DEBUG)
	#define xk_debug(msg) \
	    if(Xk::XkLog::defaultLogger()->debug()) Xk::XkLog::defaultLogger()->debug(msg, __FILE__, __LINE__); else (void) 0

    #define xk_debug_f1(fmt, arg1) \
        if(Xk::XkLog::defaultLogger()->debug()) Xk::XkLog::defaultLogger()->debug(Xk::format((fmt), arg1), __FILE__, __LINE__); else (void) 0

    #define xk_debug_f2(fmt, arg1, arg2) \
        if(Xk::XkLog::defaultLogger()->debug()) Xk::XkLog::defaultLogger()->debug(Xk::format((fmt), (arg1), (arg2)), __FILE__, __LINE__); else (void) 0

    #define xk_debug_f3(fmt, arg1, arg2, arg3) \
        if(Xk::XkLog::defaultLogger()->debug()) Xk::XkLog::defaultLogger()->debug(Xk::format((fmt), (arg1), (arg2), (arg3)), __FILE__, __LINE__); else (void) 0

    #define xk_debug_f4(fmt, arg1, arg2, arg3, arg4) \
        if(Xk::XkLog::defaultLogger()->debug()) Xk::XkLog::defaultLogger()->debug(Xk::format((fmt), (arg1), (arg2), (arg3), (arg4)), __FILE__, __LINE__); else (void) 0

	#define xk_trace(msg) \
	    if(Xk::XkLog::defaultLogger()->trace()) Xk::XkLog::defaultLogger()->trace(msg, __FILE__, __LINE__); else (void) 0

    #define xk_trace_f1(fmt, arg1) \
        if(Xk::XkLog::defaultLogger()->trace()) Xk::XkLog::defaultLogger()->trace(Xk::format((fmt), arg1), __FILE__, __LINE__); else (void) 0

    #define xk_trace_f2(fmt, arg1, arg2) \
        if(Xk::XkLog::defaultLogger()->trace()) Xk::XkLog::defaultLogger()->trace(Xk::format((fmt), (arg1), (arg2)), __FILE__, __LINE__); else (void) 0

    #define xk_trace_f3(fmt, arg1, arg2, arg3) \
        if(Xk::XkLog::defaultLogger()->trace()) Xk::XkLog::defaultLogger()->trace(Xk::format((fmt), (arg1), (arg2), (arg3)), __FILE__, __LINE__); else (void) 0

    #define xk_trace_f4(fmt, arg1, arg2, arg3, arg4) \
        if(Xk::XkLog::defaultLogger()->trace()) Xk::XkLog::defaultLogger()->trace(Xk::format((fmt), (arg1), (arg2), (arg3), (arg4)), __FILE__, __LINE__); else (void) 0

#else
	#define xk_debug(msg)
	#define xk_debug_f1(fmt, arg1)
	#define xk_debug_f2(fmt, arg1, arg2)
	#define xk_debug_f3(fmt, arg1, arg2, arg3)
	#define xk_debug_f4(fmt, arg1, arg2, arg3, arg4)
	#define xk_trace(msg)
	#define xk_trace_f1(fmt, arg1)
	#define xk_trace_f2(fmt, arg1, arg2)
	#define xk_trace_f3(fmt, arg1, arg2, arg3)
	#define xk_trace_f4(fmt, arg1, arg2, arg3, arg4)
#endif

///////////////////////





} //namespace Xk

#endif