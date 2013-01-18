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

/*
#ifndef XkPlatform
#  define XkCompiler XkPlatformunknown
#endif
*/

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

#if XkPlatform == XkPlatformLinux && XkPhysicsLib == XkPhysicsLibHavok
#error Can not use havok on linux platform
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

#if defined(_MSC_VER)
	//
	// Windows/Visual C++
	//
	typedef signed char            Int8;
	typedef unsigned char          UInt8;
	typedef signed short           Int16;
	typedef unsigned short         UInt16;
	typedef signed int             Int32;
	typedef unsigned int           UInt32;
	typedef signed __int64         Int64;
	typedef unsigned __int64       UInt64;
	#if defined(_WIN64)
		#define POCO_PTR_IS_64_BIT 1
		typedef signed __int64     IntPtr;
		typedef unsigned __int64   UIntPtr;
	#else
		typedef signed long        IntPtr;
		typedef unsigned long      UIntPtr;
	#endif
	#define POCO_HAVE_INT64 1
#elif defined(__GNUC__) || defined(__clang__)
	//
	// Unix/GCC
	//
	typedef signed char            Int8;
	typedef unsigned char          UInt8;
	typedef signed short           Int16;
	typedef unsigned short         UInt16;
	typedef signed int             Int32;
	typedef unsigned int           UInt32;
	typedef signed long            IntPtr;
	typedef unsigned long          UIntPtr;
	#if defined(__LP64__)
		#define POCO_PTR_IS_64_BIT 1
		#define POCO_LONG_IS_64_BIT 1
		typedef signed long        Int64;
		typedef unsigned long      UInt64;
	#else
		typedef signed long long   Int64;
		typedef unsigned long long UInt64;
	#endif
	#define POCO_HAVE_INT64 1
#endif

} // namespace Xk

#endif
