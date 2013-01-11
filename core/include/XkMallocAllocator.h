
#ifndef XK_MALLOCALLOCATOR_H
#define XK_MALLOCALLOCATOR_H

                                                                                       

#include "XkStable.h"

                                                                                       

namespace Xk
{

                                                                                       

/*! class. MallocAllocator
    desc.
        An allocator using malloc/free/realloc functions with optional tracking.
*/
class XkPublicClass MallocAllocator
{
  
 public:

  static void* allocateBytes(size_t length);
  
  static void* reallocateBytes(void* memory, size_t newLength);
  
  static void  deallocateBytes(void* memory);
  
};


                                                                                       

} // namespace Xk

                                                                                       

#endif
