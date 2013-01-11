
#include "XkStable.h"
#include "XkRay.h"

                                                                                       

namespace Xk
{

                                                                                       

Ray::Ray()
: mOrigin(0,0,0), mDirection(1,0,0)
{
}

Ray::Ray(const Vec3& origin, const Vec3& direction)
: mOrigin(origin), mDirection(direction)
{
}

Ray::~Ray()
{
}

                                                                                       

} // namespace NxOgre

                                                                                       
