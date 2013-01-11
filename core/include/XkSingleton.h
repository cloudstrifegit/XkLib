
#ifndef XK_SINGLETON_H
#define XK_SINGLETON_H

                                                                                       

#include "XkStable.h"

                                                                                       

namespace Xk
{

                                                                                       

/*! function. Singleton
    desc.
         Generic singleton class
*/
template<class T> class Singleton
{
  
  public:
  
  /*! function. getSingleton
      desc.
          Get's a copy of the singleton pointer
  */
  static T* getSingleton()
  {
   return sSingleton;
  }
  
  protected: // Functions
  
  /*! constructor. Singleton
      desc.
          Constructor for inherited classes.
  */
  Singleton()
  {
   sSingleton = static_cast<T*>(this);
  }
  
  /*! destructor. Singleton
  */
 ~Singleton()
  {
   sSingleton = 0;
  }
  
  protected:
  
   static T* sSingleton;
  
}; // class Singleton

                                                                                       

} // namespace Xk

                                                                                       

#endif
