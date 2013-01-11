
#include "XkStable.h"
#include "XkException.h"
#include "XkString.h"
//#include "XkErrorStream.h"

#include <iostream>

                                                                                       

namespace Xk
{

                                                                                       

Exception::Exception(const std::string& file, unsigned int line, const std::string& description, unsigned int class_type, unsigned int exception_type, const std::string& exception_name)
: mFile(file),
  mLine(line),
  mDescription(description),
  mClassType(class_type),
  mExceptionType(exception_type),
  mExceptionName(exception_name)
{
 
 std::cout << to_s() << std::endl;
 
 //if (Xk::ErrorStream::getSingleton())
  //Xk::ErrorStream::getSingleton()->addException(*this);
 
}

Exception::Exception(const Exception& other)
: mFile(other.mFile),
  mLine(other.mLine),
  mDescription(other.mDescription),
  mClassType(other.mClassType),
  mExceptionType(other.mExceptionType),
  mExceptionName(other.mExceptionName)
{
}

Exception::~Exception() throw()
{
}

Exception& Exception::operator=(const Exception& other)
{
 mFile = other.mFile;
 mLine = other.mLine;
 mDescription = other.mDescription;
 mClassType = other.mClassType;
 mExceptionType = other.mExceptionType;
 mExceptionName = other.mExceptionName;
 return *this;
}

const std::string& Exception::getFile() const
{
 return mFile;
}

unsigned int Exception::getLine() const
{
 return mLine;
}

const std::string& Exception::getDescription() const
{
 return mDescription;
}

unsigned int Exception::getExceptionType() const
{
 return mExceptionType;
}

std::string Exception::getExceptionTypeAsString() const
{
 return mExceptionName;
}

unsigned int Exception::getClassType() const
{
 return mClassType;
}

std::string Exception::to_s() const
{

 // ExceptionName (ClassType)
 // =========================
 //
 // Description Text. Description Text. Description Text. Description Text. Description Text. Description Text. 
 // Description Text. Description Text. Description Text. Description Text. Description Text. Description Text. 
 // Description Text. Description Text. Description Text. Description Text. Description Text. Description Text. 
 // Description Text. Description Text. Description Text. Description Text. Description Text. Description Text. 
 // Description Text. Description Text. Description Text. Description Text. Description Text. Description Text. 
 // 
 // From: File.cpp#42

 std::ostringstream s;
 s << "\n=====================================================================\n";
 s << mExceptionName <<  " (" << Classes::TypeToCStr(mClassType) << ")\n";
 s << "=====================================================================\n";
 s << "\n" << mDescription << "\nFrom: " << mFile << "#" << mLine << "\n\n";
 s << "=====================================================================\n\n";
 return s.str();

}

                                                                                       

} // namespace Xk

                                                                                       
