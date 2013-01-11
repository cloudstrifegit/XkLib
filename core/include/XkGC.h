
#ifndef XK_GC_H
#define XK_GC_H

#include "XkConfiguration.h"
#include "XkType2Id.h"

                                                                                       

namespace Xk
{

                                                                                       

typedef unsigned char Byte;

                                                                                       

namespace GC
{

                                                                                       

#define XK_GC_THIS  __FILE__, __LINE__

#define XK_GC_FRIEND_DELETE template<class T> friend inline void ::Xk::GC::safe_delete(T*,const char*,int);
#define XK_GC_FRIEND_NEW0 template<class T> friend inline T* ::Xk::GC::safe_new0(const char*,int);
#define XK_GC_FRIEND_NEW1 template<class T, typename A1> friend inline T* ::Xk::GC::safe_new1(const A1&,const char*,int);
#define XK_GC_FRIEND_NEW2 template<class T, typename A1, typename A2> friend inline T* ::Xk::GC::safe_new2(const A1&,const A2&,const char*,int);
#define XK_GC_FRIEND_NEW3 template<class T, typename A1, typename A2, typename A3> friend inline T* ::Xk::GC::safe_new3(const A1&,const A2&,const A3&,const char*,int);
#define XK_GC_FRIEND_NEW4 template<class T, typename A1, typename A2, typename A3, typename A4> friend inline T* ::Xk::GC::safe_new4(const A1&,const A2&,const A3&,const A4&,const char*,int);
#define XK_GC_FRIEND_NEW5 template<class T, typename A1, typename A2, typename A3, typename A4, typename A5> friend inline T* ::Xk::GC::safe_new5(const A1&,const A2&,const A3&,const A4&,const A5&,const char*,int);
#define XK_GC_FRIEND_NEW6 template<class T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6> friend inline T* ::Xk::GC::safe_new6(const A1&,const A2&,const A3&,const A4&,const A5&,const A6&,const char*,int);
#define XK_GC_FRIEND_NEW7 template<class T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7> friend inline T* ::Xk::GC::safe_new7(const A1&,const A2&,const A3&,const A4&,const A5&,const A6&,const A7&,const char*,int);
#define XK_GC_FRIEND_NEW8 template<class T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8> friend inline T* ::Xk::GC::safe_new8(const A1&,const A2&,const A3&,const A4&,const A5&,const A6&,const A7&,const A8&,const char*,int);

#if XK_DEBUG_MEMORY == 1
void XkPublicFunction gc_debugger_push_ptr(void* ptr, unsigned int size, const char* type, const char* file, unsigned int line);
void XkPublicFunction gc_debugger_change_ptr(void* old_ptr, void*  new_ptr, unsigned int new_size, const char* file, unsigned int line);
void XkPublicFunction gc_debugger_pop_ptr(void* ptr, const char* file, unsigned int line);
void XkPublicFunction gc_debugger_first_frame();
void XkPublicFunction gc_debugger_frame(unsigned int id, float time);
void XkPublicFunction gc_debugger_last_frame();
#endif

template<typename T, typename AX> inline T* safe_malloc(size_t bytes, const char* file, unsigned line)
{
 T* mem = (T*) AX::allocateBytes(bytes);
#if XK_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(mem, bytes, type2id<T>::type_name(), file, line);
#endif
 return mem;
}

template<typename T, typename AX> inline T* safe_malloc(size_t bytes, const char* type, const char* file, unsigned line)
{
 T* mem = (T*) AX::allocateBytes(bytes);
#if XK_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(mem, bytes, type, file, line);
#endif
 return mem;
}

template<typename T, typename AX> inline T* safe_realloc(T* mem, size_t new_size, const char* file, unsigned line)
{
 T* new_mem = (T*) AX::reallocateBytes(mem, new_size);
#if XK_DEBUG_MEMORY == 1
 gc_debugger_change_ptr(mem, new_mem, new_size, file, line);
#endif
 return new_mem;
}

template<typename T, typename AX> inline void safe_free(T* mem, const char* file, unsigned line)
{
 if (mem == 0)
  return;
#if XK_DEBUG_MEMORY == 1
 gc_debugger_pop_ptr(mem, file, line);
#endif
 AX::deallocateBytes(mem);
}

template<typename T> inline T* safe_new0(const char* file, int line)
{
 T* ptr = new T();
#if XK_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename AX> inline T* safe_allocated_new0(const char* file, int line)
{
 void* mem = AX::allocateBytes(sizeof(T));
 T* ptr = new(mem) T();
#if XK_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename A1> inline T* safe_new1(const A1& v1, const char* file = 0, int line = 0)
{
 T* ptr = new T(v1);
#if XK_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename AX, typename A1> inline T* safe_allocated_new1(const A1& v1, const char* file = 0, int line = 0)
{
 void* mem = AX::allocateBytes(sizeof(T));
 T* ptr = new(mem) T(v1);
#if XK_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename A1, typename A2> inline T* safe_new2(const A1& v1, const A2& v2, const char* file = 0, int line = 0)
{
 T* ptr = new T(v1, v2);
#if XK_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename AX, typename A1, typename A2> inline T* safe_allocated_new2(const A1& v1, const A2& v2, const char* file = 0, int line = 0)
{
 void* mem = AX::allocateBytes(sizeof(T));
 T* ptr = new(mem) T(v1, v2);
#if XK_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename A1, typename A2, typename A3> inline T* safe_new3(const A1& v1, const A2& v2, const A3& v3, const char* file = 0, int line = 0)
{
 T* ptr = new T(v1, v2, v3);
#if XK_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename AX, typename A1, typename A2, typename A3> inline T* safe_allocated_new3(const A1& v1, const A2& v2, const A3& v3, const char* file = 0, int line = 0)
{
 void* mem = AX::allocateBytes(sizeof(T));
 T* ptr = new(mem) T(v1, v2, v3);
#if XK_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename A1, typename A2, typename A3, typename A4> inline T* safe_new4(const A1& v1, const A2& v2, const A3& v3, const A4& v4, const char* file = 0, int line = 0)
{
 T* ptr = new T(v1, v2, v3, v4);
#if XK_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename AX, typename A1, typename A2, typename A3, typename A4> inline T* safe_allocated_new4(const A1& v1, const A2& v2, const A3& v3, const A4& v4, const char* file = 0, int line = 0)
{
 void* mem = AX::allocateBytes(sizeof(T));
 T* ptr = new(mem) T(v1, v2, v3, v4);
#if XK_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5> inline T* safe_new5(const A1& v1, const A2& v2, const A3& v3, const A4& v4, const A5& v5, const char* file = 0, int line = 0)
{
 T* ptr = new T(v1, v2, v3, v4, v5);
#if XK_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename AX, typename A1, typename A2, typename A3, typename A4, typename A5> inline T* safe_allocated_new5(const A1& v1, const A2& v2, const A3& v3, const A4& v4, const A5& v5, const char* file = 0, int line = 0)
{
 void* mem = AX::allocateBytes(sizeof(T));
 T* ptr = new(mem) T(v1, v2, v3, v4, v5);
#if XK_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6> inline T* safe_new6(const A1& v1, const A2& v2, const A3& v3, const A4& v4, const A5& v5, const A6& v6, const char* file = 0, int line = 0)
{
 T* ptr = new T(v1, v2, v3, v4, v5, v6);
#if XK_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename AX, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6> inline T* safe_allocated_new6(const A1& v1, const A2& v2, const A3& v3, const A4& v4, const A5& v5, const A6& v6, const char* file = 0, int line = 0)
{
 void* mem = AX::allocateBytes(sizeof(T));
 T* ptr = new(mem) T(v1, v2, v3, v4, v5, v6);
#if XK_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7> inline T* safe_new7(const A1& v1, const A2& v2, const A3& v3, const A4& v4, const A5& v5, const A6& v6, const A7& v7, const char* file = 0, int line = 0)
{
 T* ptr = new T(v1, v2, v3, v4, v5, v6, v7);
#if XK_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename AX, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7> inline T* safe_allocated_new7(const A1& v1, const A2& v2, const A3& v3, const A4& v4, const A5& v5, const A6& v6, const A7& v7, const char* file = 0, int line = 0)
{
 void* mem = AX::allocateBytes(sizeof(T));
 T* ptr = new(mem) T(v1, v2, v3, v4, v5, v6, v7);
#if XK_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>  inline T* safe_new8(const A1& v1, const A2& v2, const A3& v3, const A4& v4, const A5& v5, const A6& v6, const A7& v7, const A8& v8, const char* file = 0, int line = 0)
{
 T* ptr = new T(v1, v2, v3, v4, v5, v6, v7, v8);
#if XK_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename AX, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>  inline T* safe_allocated_new8(const A1& v1, const A2& v2, const A3& v3, const A4& v4, const A5& v5, const A6& v6, const A7& v7, const A8& v8, const char* file = 0, int line = 0)
{
 void* mem = AX::allocateBytes(sizeof(T));
 T* ptr = new(mem) T(v1, v2, v3, v4, v5, v6, v7, v8);
#if XK_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T> void inline safe_delete(T* ptr, const char* file, int line)
{
 if (ptr == 0)
  return;
#if XK_DEBUG_MEMORY == 1
 gc_debugger_pop_ptr(ptr, file, line);
#endif
 delete ptr;
}

template<typename T, typename AX> void inline safe_allocated_delete(T* ptr, const char* file, int line)
{
 if (ptr == 0)
  return;
 ptr->~T();
#if XK_DEBUG_MEMORY == 1
 gc_debugger_pop_ptr(ptr, file, line);
#endif
 AX::deallocateBytes(ptr);
}

class NoGarbageCollection
{
 public:

 // map<K,T>, multimap<K,T>, hashmap<K,T>
 template<typename K, typename T> class impl_map
 {
  public:
    inline void gc_free(T&) {}
    template<typename it> inline void gc_free_range(it first, it last) {}
 };

 // map<K,T*>, multimap<K,T*>, hashmap<K,T*>
 template<typename K, typename T> class impl_map<K,T*>
 {
  public:
    inline void gc_free(T*) {}
    template<typename it> inline void gc_free_range(it first, it last) {}
 };

 // vector<T>
 template<typename T> class impl_vector
 {
  protected:

    inline void gc_free(T&) {}
    template<typename it> inline void gc_free_range(it first, it last) {}
 };

 // vector<T*>
 template<typename T> class impl_vector<T*>
 {
  protected:

    inline void gc_free(T*) {}
    template<typename it>  inline void gc_free_range(it first, it last) {}
 };

};

class HasGarbageCollection
{
 public:

 // map<K,T>, multimap<K,T>, hashmap<K,T>
 template<typename K, typename T> class impl_map
 {
  public:
    inline void gc_free(T& ref) {ref.~T();}
    template<typename it> inline void gc_free_range(it first, it last)
    {
     while(first != last)
     {
       (*first).second.~T();
       first++;
     }
    }
 };

 // map<K,T*>, multimap<K,T*>, hashmap<K,T*>
 template<typename K, typename T> class impl_map<K,T*>
 {
  public:
    inline void gc_free(T* ptr) {safe_delete(ptr, XK_GC_THIS);}
    template<typename it> inline void gc_free_range(it first, it last)
    {
     while(first != last)
     {
       //delete (*first).second;
       safe_delete((*first).second, XK_GC_THIS);
       first++;
     }
    }
 };

 // vector<T>
 template<typename T> class impl_vector
 {
  protected:

    inline void gc_free(T& ref) {ref.~T();}
    template<typename it> inline void gc_free_range(it first, it last)
    {
     while(first != last)
     {
       (*first).~T();
       first++;
     }
    }
 };

 // vector<T*>
 template<typename T> class impl_vector<T*>
 {
  protected:

    inline void gc_free(T* ptr) {safe_delete<T>(ptr, XK_GC_THIS);}
    template<typename it> inline void gc_free_range(it first, it last)
    {
     while(first != last)
     {
       safe_delete<T>((*first), XK_GC_THIS);
       first++;
     }
    }
 };

};

template<typename T> bool safe_copy(T* first, T* last, T* dest)
{
 if (first == 0 || last == 0 || dest == 0)
  return false;
 for (; first != last; ++dest, ++first)
  *dest = *first;
 return true;
}

                                                                                       

} // namespace GC

                                                                                       

} // namespace Xk

                                                                                       

#endif
