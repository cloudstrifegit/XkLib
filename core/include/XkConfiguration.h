#ifndef XK_MSWINDOWS_CONFIGURATION_H
#define XK_MSWINDOWS_CONFIGURATION_H
#define XK_HAS_CONFIGURATION

#include "XkAutoConfiguration.h"

/*
  Debug options
  ===========================
  
  - Set to 0 to disable
  - Set to 1 to enable
  
*/
// Enable Memory Debugging.
#define XK_DEBUG_MEMORY 1
// File to write to.
#define XK_DEBUG_MEMORY_FILE nxogre.allocations.html
// Debug cooking processes
#define XK_DEBUG_COOKING 0
// Debug reading and writing to resources.
#define XK_DEBUG_RESOURCES 0
// Debug Xk Core. Constructor/Destruction of key classes.
#define XK_DEBUG_CORE 1
// Debug buffer<T> class.
#define XK_DEBUG_BUFFER 0
// Debug Meshes
#define XK_DEBUG_MESHES 0
// Debug HeightFields
#define XK_DEBUG_HEIGHTFIELDS 0
// Debug Cloth
#define XK_DEBUG_CLOTH 0
// Debug FlatYAML
#define XK_DEBUG_FLATYAML 0

/*
  XkUsesCookingLib
  ====================
  Use the PhysX cooking library to create Triangle/Convex/Cloth/SoftBody/Skeleton meshes
  Warning! If disabled, all of Xk cooking functions will automatically fail on use.
  - Requires use of the PhysXCooking.lib/PhysXCooking.dll
*/
#define XkUsesCookingLib 1

/*
  XkHasCharacterController
  ============================
  
  Enable use of the PhysX Character Controller.
   - Requires use of the NxCharacter.lib/NxCharacter.dll
*/
#define XkHasCharacterController 1

/*
  XkFloatingPointAccuracy
  ===========================
  
  Precision of a real number. This must be the same type as PhysX's NxReal.
  
  options:
   - XkFloatingPointFloat
   - XkFloatingPointDouble
   
*/
#define XkFloatingPointAccuracy XkFloatingPointFloat

/*
  XkHasFluids
  ===============
  
  Enable (or disable) fluids.
  options
    - 1
    - 0
  note:
      This should be disabled in Linux.
*/
#define XkHasFluids 1


#if XkPlatform == XkPlatformLinux
 // Linux PhysX does not have Fluids, it must be disabled.
 #define XkHasFluids 0
#endif

/* 
  Minimal PhysX Version
  =====================

  Minimal PhysX version that Xk should adhere to, any features known
  not to exist before that will be disabled.
*/

#if XkPlatform == XkPlatformWindows
 // Public version for Windows on the Ageia website is at least 2.8.1
 #define XkMinimalPhysXVersion 281
#elif XkPlatform == XkPlatformLinux
 // Public version for Linux on the NVidia website is PhysX 2.8.0 
 #define XkPhysXVersion 280
#endif



#endif
