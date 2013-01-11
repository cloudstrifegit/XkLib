
#ifndef XK_EXCEPTION_H
#define XK_EXCEPTION_H

                                                                                       

#include "XkStable.h"
#include "XkEnums.h"
#include "XkClasses.h"
#include <exception>
#include <string>

                                                                                       

namespace Xk
{


                                                                                       

/*! class. Exception
    desc.
        Base class for all Xk exceptions
*/
class XkPublicClass Exception : public std::exception
{
 public:
  
  /*! constructor. Exception
      desc.
  */
  Exception(const std::string& file, unsigned int line, const std::string& description, unsigned int class_type, unsigned int exception_type, const std::string& exception_description);
  
  /*! constructor. Exception.copy
      desc.
          Copy constructor.
  */
  Exception(const Exception&);
  
  /*! destructor. Exception
  */
  ~Exception() throw();
  
  /*! function. Operator.assignment
      desc.
           Assignment operator.
  */
  Exception& operator=(const Exception& other);

  /*! function. getFile
      desc.
           Get file that threw the exception
  */
  const std::string& getFile() const;
  
  /*! function. getLine
      desc.
           Get the line in the file that threw the exception.
  */
  unsigned int getLine() const;
  
  /*! function. getDescription
      desc. 
           Get a descriptive message of why the exception was thrown.
  */
  const std::string& getDescription() const;
  
  /*! function. getExceptionType
      desc.
           Get the type of exception.
  */
  unsigned int getExceptionType() const;
  
  /*! function. getExceptionTypeAsString
      desc.
          Get the exception type as string
  */
  std::string getExceptionTypeAsString() const;
  
  /*! function. getClassType
      desc.
          Get type of class that threw the exception.
  */
  unsigned int getClassType() const;

  /*! function. str
      desc.
           Formats the exception as a markdown formatted string
  */
  std::string to_s() const;
  
 protected:
  
  std::string  mFile;
  unsigned int mLine;
  std::string  mDescription;
  std::string  mExceptionName;
  unsigned int mExceptionType;
  unsigned int mClassType;
};

/*! exception. UnknownErrorException
    desc.
        Thrown when the something unexpected has happened.
*/
class XkPublicClass UnknownErrorException : public Exception
{
 public:
  UnknownErrorException(const std::string& file, unsigned int line, const std::string& description, unsigned int class_type)
  : Exception(file, line, description, class_type, Enums::ExceptionType_UnknownError, "Unknown Error") {}
};

/*! exception. InternalErrorException
    desc.
        Thrown when a generic error has happened.
*/
class XkPublicClass InternalErrorException : public Exception
{
 public:
  InternalErrorException(const std::string& file, unsigned int line, const std::string& description, unsigned int class_type)
  : Exception(file, line, description, class_type, Enums::ExceptionType_InternalError, "Internal Error") {}
};

/*! exception. IOErrorException
    desc.
        Thrown when a the Resource system has an IO error.
*/
class XkPublicClass IOException : public Exception
{
 public:
  IOException(const std::string& file, unsigned int line, const std::string& description, unsigned int class_type)
  : Exception(file, line, description, class_type, Enums::ExceptionType_IOException, "IO Exception") {}
};

/*! exception. PhysXInternalErrorException
    desc.
        Thrown when PhysX has raised an error.
*/
class XkPublicClass PhysXInternalErrorException : public Exception
{
 public:
  PhysXInternalErrorException(const std::string& file, unsigned int line, const std::string& description, unsigned int class_type)
  : Exception(file, line, description, class_type, Enums::ExceptionType_PhysXInternalError, "PhysX Internal Error Exception") {}
};

/*! exception. PhysXSDKCreationFailedException
    desc.
        Thrown when the PhysX SDK has not been created properly.
*/
class XkPublicClass PhysXSDKCreationFailedException : public Exception
{
 public:
  PhysXSDKCreationFailedException(const std::string& file, unsigned int line, const std::string& description, unsigned int class_type)
  : Exception(file, line, description, class_type, Enums::ExceptionType_PhysXSDKCreationFailed, "PhysX SDK creation failed") {}
};

/*! exception. DescriptionInvalidException
    desc.
        Thrown when the properties of a new PhysX wrapped class that is to be created is invalid.
*/
class XkPublicClass DescriptionInvalidException : public Exception
{
 public:
  DescriptionInvalidException(const std::string& file, unsigned int line, const std::string& description, unsigned int class_type)
  : Exception(file, line, description, class_type, Enums::ExceptionType_DescriptionInvalid, "Description properties is invalid") {}
};

/*! exception. WrongTypeException
    desc.
        Thrown when the a type of class isn't the one that was expected.
*/
class XkPublicClass WrongTypeException : public Exception
{
 public:
  WrongTypeException(const std::string& file, unsigned int line, const std::string& description, unsigned int class_type)
  : Exception(file, line, description, class_type, Enums::ExceptionType_WrongType, "Type given isn't the type expected.") {}
};

/*! exception. NullPointerException
    desc.
        Thrown when the pointer that is to be used is a null pointer.
*/
class XkPublicClass NullPointerException : public Exception
{
 public:
  NullPointerException(const std::string& file, unsigned int line, unsigned int class_type)
  : Exception(file, line, std::string(Classes::TypeToCStr(class_type)) + std::string(" is a null pointer"), class_type, Enums::ExceptionType_NullPointerException, "Null Pointer Exception") {}
};

/*! exception. NonNullPointerException
    desc.
        Thrown when the that a pointer is expected to be null, when it is not.
*/
class XkPublicClass NonNullPointerException : public Exception
{
 public:
  NonNullPointerException(const std::string& file, unsigned int line, const std::string& description, unsigned int class_type)
  : Exception(file, line, description, class_type, Enums::ExceptionType_NonNullPointerException, "Non-Null Pointer Exception") {}
};


/*! exception. DescriptionInvalidException
    desc.
        Thrown when the pointer that is to be used is a null pointer.
*/
class XkPublicClass PathInvalidException : public Exception
{
 public:
  PathInvalidException(const std::string& file, unsigned int line,  const std::string& description, unsigned int class_type)
  : Exception(file, line, description, class_type, Enums::ExceptionType_PathInvalidException, "Path is invalid") {}
};

/*! exception. PhysXSystemSoftwareException
    desc.
        Thrown when the pointer the PhysX System Software is not installed, or has been installed incorrectly.
*/
class XkPublicClass PhysXSystemSoftwareException : public Exception
{
 public:
  PhysXSystemSoftwareException(const std::string& file, unsigned int line,  unsigned int class_type)
  : Exception(file, line, "The PhysX System Software has not been installed.", class_type, Enums::ExceptionType_NoPhysXSDKError, "No PhysX System Software") {}
};


                                                                                       

} // namespace Xk

                                                                                       

#endif
