
#ifndef XK_RAY_H
#define XK_RAY_H

                                                                                       

#include "XkStable.h"
#include "XkVec3.h"                                                                  

namespace Xk
{                                                            

/** \brief
*/
class XkPublicClass Ray
{
  
  
  public: // Functions
  
  /** \brief Constructor with 0,0,0 as Origin and 1,0,0 as Direction.
  */
                                              Ray();
  
  /** \brief Alternate Constructor.
  */
                                              Ray(const Vec3& origin, const Vec3& direction);
  
  /** \brief Destructor.
  */
                                             ~Ray();
  
  public: // Variables
  
  /** \brief The origin in global coordinates of the ray.
  */
                                              Vec3 mOrigin;
  
  /** \brief The normalised direction of the ray.
  */
                                              Vec3 mDirection;
  
  
}; // class ClassName

                                                                                       

} // namespace Xk

                                                                                       

#endif
