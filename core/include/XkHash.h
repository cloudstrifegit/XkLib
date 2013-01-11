
#ifndef XK_HASH_H
#define XK_HASH_H

                                                                                       

#include "XkStable.h"

                                                                                       

namespace Xk
{

                                                                                       


template<typename K> struct HashFunction
{
   
 public:
   
   static HashFunction accessor;
   
   size_t operator()(const K&)
   {
    return 0;
   }
};


template<> struct HashFunction<std::string>
{
   
 public:
   
   size_t operator()(const std::string& str)
   {
    
    if (str.length() == 0)
     return 0;
    
    size_t ret = 2166136261U;
    std::string::const_iterator it = str.begin();
    while(it != str.end())
     ret = 16777619 * ret ^ (size_t) *it++;
    
    return ret;
    
   }
   
};


                                                                                       

} // namespace Xk

                                                                                       

#endif
