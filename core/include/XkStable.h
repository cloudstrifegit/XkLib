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
