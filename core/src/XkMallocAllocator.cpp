
#include "XkStable.h"
#include "XkMallocAllocator.h"

#include "malloc.h"

                                                                                       

namespace Xk
{

                                                                                       

void* MallocAllocator::allocateBytes(size_t length)
{
 
 void* ptr = malloc(length);

 return ptr;
 
}


void* MallocAllocator::reallocateBytes(void* memory, size_t newLength)
{
 void* newPtr = realloc(memory, newLength);

 return newPtr;
}

void MallocAllocator::deallocateBytes(void* memory)
{
 if (memory == 0)
  return;
 
 free(memory);
 
}

                                                                                       

} // namespace Xk

                                                                                       
