
#ifndef XK_ALLOCATOR_H
#define XK_ALLOCATOR_H

                                                                                       

#include "XkStable.h"
#include "XkEnums.h"
#include "string.h"

                                                                                       

namespace Xk
{

                                                                                       

template<class SpecialisedAllocator> class Allocator : public SpecialisedAllocator
{ // empty mixin class.
};

template<class Allocator> class Allocatable
{
 public:

  typedef Allocator allocator_t;

  explicit Allocatable() {}

  ~Allocatable() {}

  void* operator new(size_t length)
  {
   return Allocator::allocateBytes(length);
  }

  void* operator new[](size_t length)
  {
   return Allocator::allocateBytes(length);
  }

  void operator delete(void* ptr)
  {
   Allocator::deallocateBytes(ptr);
  }

  void operator delete[](void* ptr)
  {
   Allocator::deallocateBytes(ptr);
  }

};

inline void XkCopy(void* dest, const void* src, size_t length)
{
 memcpy(dest, src, length);
}

                                                                                       


} // namespace Xk

                                                                                       


#endif


