
#ifndef XK_AUTOCONFIGURATION_H
#define XK_AUTOCONFIGURATION_H

#define XkMemoryAllocatorMalloc 1
#define XkMemoryAllocatorNedmalloc 2

#define XkFloatingPointFloat 1
#define XkFloatingPointDouble 2
#define XkCompilerUnknown 0
#define XkCompilerMSVC 1
#define XkCompilerGNUC 2

#define XkPlatformUnknown 0
#define XkPlatformWindows 1
#define XkPlatformLinux 2
#define XkPlatformAndroid 3

#define XkArchitecture32Bit 32
#define XkArchitecture64Bit 64

#define XkPhysicsLibPhysX 0
#define XkPhysicsLibHavok 1

#define XK_EXPORT_OPTIONS_EXPORT 1
#define XK_EXPORT_OPTIONS_IMPORT 2
#define XK_EXPORT_OPTIONS_AVOID 3

#if defined (_MSC_VER)
# define XkCompiler XkCompilerMSVC
#elif defined ( __GNUC__ )
# define XkCompiler XkCompilerGNUC
#endif

#if defined (_WIN32) || defined (__WIN32)
# define XkPlatform XkPlatformWindows
# define NOMINMAX
#define XkPhysicsLib XkPhysicsLibHavok
#elif defined (LINUX) || defined(_LINUX)
# define XkPlatform XkPlatformLinux
#define XkPhysicsLib XkPhysicsLibPhysX
#elif defined (__ANDROID__) || defined(ANDROID)
#define XkPlatform XkPlatformAndroid
#define XkPhysicsLib XkPhysicsLibPhysX
#endif

#if defined(_M_X64) || defined (_M_X64)
# define XkArchitecture XkArchitecture64Bit
#else
# define XkArchitecture XkArchitecture32Bit
#endif


// XkArray.h generates this warning - a lot.
#pragma warning (disable : 4251)

// XkSingleton.h and other classes that inherit generate this warning in Visual Studio.
#pragma warning (disable : 4661)

// Occurs when inheriting from a PhysX class.
#pragma warning (disable : 4275)

// Conversion from 'double' to 'float', possible loss of data
#pragma warning (disable : 4244)

// forcing value to bool 'true' or 'false' (performance warning)
#pragma warning (disable : 4800)

// 'fopen': This function or variable may be unsafe. Consider using fopen_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.
#pragma warning (disable : 4996)

#if (XkCompiler == XkCompilerMSVC)
 
 #define XkForceInline __forceinline
 
 #ifdef XK_DYNAMIC_LIBRARY
 # define XK_EXPORT_OPTIONS XK_EXPORT_OPTIONS_EXPORT
 #endif

 #ifdef XK_STATIC_LIBRARY
 # define XK_EXPORT_OPTIONS XK_EXPORT_OPTIONS_AVOID
 #endif

 #ifndef XK_EXPORT_OPTIONS
 # define XK_EXPORT_OPTIONS XK_EXPORT_OPTIONS_IMPORT
 #endif

 #if (XK_EXPORT_OPTIONS == XK_EXPORT_OPTIONS_EXPORT)
 # define XkPublicClass __declspec(dllexport)
 # define XkPublicFunction __declspec(dllexport)
 # define XkPublicTemplateClass
 #endif

 #if (XK_EXPORT_OPTIONS == XK_EXPORT_OPTIONS_IMPORT)
 # define XkPublicClass __declspec(dllimport)
 # define XkPublicFunction __declspec(dllimport)
 # define XkPublicTemplateClass
 #endif

 #if (XK_EXPORT_OPTIONS == XK_EXPORT_OPTIONS_AVOID)
 # define XkPublicClass
 # define XkPublicFunction
 # define XkPublicTemplateClass
 #endif


#endif

#if (XkCompiler == XkCompilerGNUC)
# define XkForceInline __inline
# define XkPublicClass
# define XkPublicFunction
#endif

#if defined(_DEBUG) || defined(DEBUG)
# ifndef XK_DEBUG
#  define XK_DEBUG
# endif
#endif

#endif
