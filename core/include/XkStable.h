#ifndef XK_STABLE_H
#define XK_STABLE_H

#include "XkVersion.h"
#include "XkAutoConfiguration.h"
#include "XkConfiguration.h"

#ifndef XK_HAS_CONFIGURATION
#error Could not find XkConfiguration.h
#endif

#include "limits.h"
#include "float.h"
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <list>

#ifndef XkCompiler
#  define XkCompiler XkCompilerUnknown
#endif

#ifndef XkPlatform
#  define XkCompiler XkPlatformunknown
#endif

#ifndef XkArchitecture
#  define XkArchitecture XkArchitecture32Bit
#endif

#ifndef XkPublicClass
#  define XkPublicClass
#endif

#ifndef XkPublicFunction
#  define XkPublicFunction
#endif

#ifndef XkForceInline
#define XkForceInline
#endif

#define Xk_ExceptionNoClassType 0

#define Xk_ThrowException(EXCEPTION, DESCRIPTION, CLASS_TYPE) throw EXCEPTION(__FILE__, __LINE__, DESCRIPTION, CLASS_TYPE); 

#define Xk_ThrowExceptionIfNull(PTR, CLASS_TYPE) if(PTR == 0){throw ::Xk::NullPointerException(__FILE__, __LINE__, CLASS_TYPE);}

#define Xk_ThrowExceptionIfNotNull(PTR, DESCRIPTION, CLASS_TYPE) if(PTR != 0){throw ::Xk::NonNullPointerException(__FILE__, __LINE__, DESCRIPTION, CLASS_TYPE);}

#define Xk_ThrowWarning(DESCRIPTION, CLASS_TYPE) ::Xk::ErrorStream::getSingleton()->addWarning(Warning(__FILE__, __LINE__, DESCRIPTION, CLASS_TYPE));

#define Xk_ThrowNotice(DESCRIPTION) ::Xk::ErrorStream::getSingleton()->addNotice(Notice(__FILE__, __LINE__, DESCRIPTION));

#define Xk_CompileAssertion(exp, reason)  extern char XkCompilerAssertion__##reason__[ size_t((exp) ? 1 : -1) ]

#define Xk_PreprocessorToStringBase(x) #x

#define Xk_Stringify(x) Xk_PreprocessorToStringBase(x)

#define Xk_DeclareEmptyClassFunctionVoid(FUNCTION_SIGNATURE) FUNCTION_SIGNATURE {}

#define Xk_DeclareEmptyClassFunctionValue(FUNCTION_SIGNATURE, RETURN_VALUE) FUNCTION_SIGNATURE {return RETURN_VALUE;}

#ifdef XK_SDK
// All classes that use the TinyClassAllocatable, must use this macro when the class is defined.
#  define XkSixteenBytesRestriction(CLASS) extern char XkCompileAssert[size_t(sizeof(CLASS) == 16 ? 1 : -1)];
#  define XkFourBytesRestriction(CLASS) extern char XkCompileAssert[size_t(sizeof(CLASS) == 4 ? 1 : -1)];
#else
#  define XkSixteenBytesRestriction(CLASS)
#  define XkFourBytesRestriction(CLASS)
#endif

                                                                                       

#define Xk_DebugPrint(MESSAGE) std::cout << MESSAGE << std::end                                    

#if XK_DEBUG_CORE == 1
 #define Xk_DebugPrint_Core(MESSAGE) Xk_DebugPrint("[Xk/Core] " << MESSAGE)
#else
 #define Xk_DebugPrint_Core(MESSAGE) /* MESSAGE */
#endif

#if XK_DEBUG_RESOURCES == 1
 #define Xk_DebugPrint_Resources(MESSAGE) Xk_DebugPrint("[Xk/Resources] " << MESSAGE)
#else
 #define Xk_DebugPrint_Resources(MESSAGE) /* MESSAGE */
#endif

#if XK_DEBUG_MEMORY == 1
 #define Xk_DebugPrint_Memory(MESSAGE) Xk_DebugPrint("[Xk/Memory] " << MESSAGE)
#else
 #define Xk_DebugPrint_Memory(MESSAGE) /* MESSAGE */
#endif

#if XK_DEBUG_COOKING == 1
 #define Xk_DebugPrint_Cooking(MESSAGE) Xk_DebugPrint("[Xk/Cooking] " << MESSAGE)
#else
 #define Xk_DebugPrint_Cooking(MESSAGE) /* MESSAGE */
#endif

#if XK_DEBUG_BUFFER == 1
 #define Xk_DebugPrint_Buffer(MESSAGE) Xk_DebugPrint("[Xk/Buffer] " << MESSAGE)
#else
 #define Xk_DebugPrint_Buffer(MESSAGE) /* MESSAGE */
#endif

#if XK_DEBUG_MESHES == 1
 #define Xk_DebugPrint_Meshes(MESSAGE) Xk_DebugPrint("[Xk/Meshes] " << MESSAGE)
#else
 #define Xk_DebugPrint_Meshes(MESSAGE) /* MESSAGE */
#endif

#if XK_DEBUG_HEIGHTFIELDS == 1
 #define Xk_DebugPrint_HeightFields(MESSAGE) Xk_DebugPrint("[Xk/HeightFields] " << MESSAGE)
#else
 #define Xk_DebugPrint_HeightFields(MESSAGE) /* MESSAGE */
#endif

#if XK_DEBUG_CLOTH == 1
 #define Xk_DebugPrint_Cloth(MESSAGE) Xk_DebugPrint("[Xk/Cloth] " << MESSAGE)
#else
 #define Xk_DebugPrint_Cloth(MESSAGE) /* MESSAGE */
#endif

#if XK_DEBUG_FLATYAML == 1
 #define Xk_DebugPrint_FlatYAML(MESSAGE) Xk_DebugPrint("[Xk/FlatYAML] " << MESSAGE)
#else
 #define Xk_DebugPrint_FlatYAML(MESSAGE) /* MESSAGE */
#endif

                                                                                       

#define XkIntTypeMax INT_MAX
#define XkIntTypeMin (-INT_MAX)
#define XkFloatTypeMax FLT_MAX
#define XkFloatTypeMin (-FLT_MAX)
#define XkDoubleTypeMax DBL_MAX
#define XkDoubleTypeMin (-DBL_MAX)

#if (XkFloatingPointAccuracy == XkFloatingPointFloat)
#  define XkRealType float
#  define XkRealMax XkFloatTypeMax
#  define XkRealMin XkFloatTypeMin
#elif (XkFloatingPointAccuracy == XkFloatingPointDouble)
#  define XkRealType double
#  define XkRealMax XkDoubleTypeMax
#  define XkRealMin XkDoubleTypeMin
#else
#  error Floating point accuracy not specified
#endif

                                                                                       

namespace Xk
{

/** \brief All floating-types are called "Real" in Xk; this allows single or double precision of every
           class using a real number by changing the XkFloatingPointAccuracy macro.
*/
typedef XkRealType Real;


#if (XkFloatingPointAccuracy == XkFloatingPointFloat)
/** \brief A much more accurate Real used with Character controller and other high-precision classes.
    \note  Some classes will disappear or remove functions if Real is a double.
*/
typedef double DoubleReal;
#endif

/** \brief References type for Containers.
*/
typedef unsigned int RefT;

} // namespace Xk

#endif