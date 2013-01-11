
#ifndef XK_SHAREDPOINTER_H
#define XK_SHAREDPOINTER_H

                                                                                       

#include "XkStable.h"
#include "XkException.h"
                                                                                       

namespace Xk
{

                                                                                       

/*! class. SharedPointer
    desc.
        Shared Pointer
    note.
        Much of this code is based of the SharedPtr class from Ogre3D http://www.ogre3d.org
*/
template<typename T> class /*XkPublicTemplateClass*/ SharedPointer
{
  public:
  
   SharedPointer()
   : mPtr(0), mReferences(0)
   {
   }
  
   template<typename user_type>
   explicit SharedPointer(user_type* ptr)
   : mPtr(ptr), mReferences(0)
   {
    if (mPtr)
     mReferences = GC::safe_new0<unsigned int>(XK_GC_THIS);
   }
   
   SharedPointer(const SharedPointer& other)
   : mPtr(0), mReferences(0)
   {
    mPtr = other.mPtr;
    mReferences = other.mReferences;
    if (mReferences)
     ++(*mReferences);
   }
   
   SharedPointer& operator=(const SharedPointer& other)
   {
    if (mPtr == other.mPtr)
     return *this;
    
    SharedPointer<T> temp(other);
    swap(temp);
    return *this;
   }
   
   template<typename user_type>
   SharedPointer(const SharedPointer<user_type>& other)
   : mPtr(0), mReferences(0)
   {
    mPtr = other.getPtr();
    mReferences = other.getReferencesPtr();
    if (mReferences)
     ++(*mReferences);
   }
   
   template<typename user_type>
   SharedPointer& operator=(const SharedPointer<user_type>& other)
   {
    if (mPtr == other.getPtr())
     return *this;
    
    SharedPointer<T> temp(other);
    swap(temp);
    return *this;
   }
   
   virtual ~SharedPointer()
   {
    release();
   }
   
   inline T& operator*() const
   {
    Xk_ThrowExceptionIfNull(mPtr, Classes::_void);
    return *mPtr;
   }
   
   inline T* operator->() const
   {
    Xk_ThrowExceptionIfNull(mPtr, Classes::_void);
    return mPtr;
   }
   
   inline T* get() const
   {
    Xk_ThrowExceptionIfNull(mPtr, Classes::_void);
    return mPtr;
   }
   
   void bind(T* ptr)
   {
    Xk_ThrowExceptionIfNotNull(mPtr, "Pointer was expected to be null!", Classes::_void);
    Xk_ThrowExceptionIfNotNull(mReferences, "Pointer was expected to be null!", Classes::_unsigned_int);
    
    mReferences = GC::safe_new0<unsigned int>(XK_GC_THIS);
    mPtr = ptr;
   }
   
   inline bool unique() const
   {
    Xk_ThrowExceptionIfNull(mReferences, Classes::_unsigned_int);
    return (*mReferences) == 1;
   }
   
   inline unsigned int references() const
   {
    Xk_ThrowExceptionIfNull(mReferences, Classes::_unsigned_int);
    return (*mReferences);
   }
   
   inline unsigned int* referencesPtr() const
   {
    return mReferences;
   }
   
   inline bool isNull() const
   {
    return mPtr == 0;
   }

   inline void setNull()
   {
    if (mPtr == 0)
     return;
    release();
    mPtr = 0;
    mReferences = 0;
   }
   
  protected:
   
   inline void release()
   {
    // Got errors from here? Call setNull before shutting down!
    if (--(*mReferences) == 0)
    {
     GC::safe_delete(mPtr, XK_GC_THIS);
     GC::safe_delete(mReferences, XK_GC_THIS);
    }
   }
   
  inline void swap(SharedPointer<T>& other)
  {
   std::swap(mPtr, other.mPtr);
   std::swap(mReferences, other.mReferences);
  }
  
  T* mPtr;
  unsigned int* mReferences;
}; // class SharedPtr

template<typename T1, typename T2> inline bool operator==(SharedPointer<T1> const& a, SharedPointer<T2> const& b)
{
 return a.get() == b.get();
}

template<typename T1, typename T2> inline bool operator!=(SharedPointer<T1> const& a, SharedPointer<T2> const& b)
{
 return a.get() != b.get();
}

template<typename T1, typename T2> inline bool operator<(SharedPointer<T1> const& a, SharedPointer<T2> const& b)
{
 return std::less<const void*>(a.get(), b.get());
}
                                                                                       

} // namespace Xk

                                                                                       

#endif
