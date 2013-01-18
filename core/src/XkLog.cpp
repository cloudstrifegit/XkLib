#include "XkLog.h"
#include <iostream>
#include <Poco/Logger.h>
#include <Poco/AutoPtr.h>
#include <Poco/SingletonHolder.h>
#include <Poco/ConsoleChannel.h>

namespace
{
    Poco::Logger* g_pLogger;
}

namespace Xk
{

    class TestChannel : public Poco::Channel
    {
    public:
        void log(const Poco::Message& msg)
        {
            std::cout<<msg.getText()<<" "<<msg.getSourceFile()<<" "<<msg.getSourceLine()<<std::endl;
        }
    };

XkLog::XkLog()
{
    g_pLogger = &Poco::Logger::get("xklog");
    Poco::AutoPtr<Poco::ConsoleChannel> pChannel = new Poco::ConsoleChannel();
    g_pLogger->setChannel(pChannel);
}

XkLog::~XkLog()
{
    xk_trace("XkLog::~XkLog");
}

void XkLog::fatal(const std::string& msg, const char* file, int line)
{
    (*g_pLogger).fatal(msg, file, line);
}

void XkLog::critical(const std::string& msg, const char* file, int line)
{
    (*g_pLogger).critical(msg, file, line);
}

void XkLog::error(const std::string& msg, const char* file, int line)
{
    (*g_pLogger).error(msg, file, line);
}
    
void XkLog::warning(const std::string& msg, const char* file, int line)
{
    (*g_pLogger).warning(msg, file, line);
}
    
void XkLog::notice(const std::string& msg, const char* file, int line)
{
    (*g_pLogger).notice(msg, file, line);
}
       
void XkLog::information(const std::string& msg, const char* file, int line)
{
    (*g_pLogger).information(msg, file, line);
}   
    
void XkLog::debug(const std::string& msg, const char* file, int line)
{
    (*g_pLogger).debug(msg, file, line);
}    
    
void XkLog::trace(const std::string& msg, const char* file, int line)
{
    (*g_pLogger).trace(msg, file, line);
}

bool XkLog::fatal()
{
    return g_pLogger->fatal();
}

bool XkLog::critical()
{
    return g_pLogger->critical();
}

bool XkLog::error()
{
    return g_pLogger->error();
}

bool XkLog::warning()
{
    return g_pLogger->warning();
}

bool XkLog::notice()
{
    return g_pLogger->notice();
}

bool XkLog::information()
{
    return g_pLogger->information();
}

bool XkLog::debug()
{
    return g_pLogger->debug();
}

bool XkLog::trace()
{
    return g_pLogger->trace();
}

XkLog* XkLog::defaultLogger()
{
    static Poco::SingletonHolder<XkLog> sh;
	return sh.get();
}
    


} //namespace Xk