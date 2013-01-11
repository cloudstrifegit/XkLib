
#include "XkStable.h"
#include "XkVec3.h"
#include "XkMath.h"

                                                                                       

namespace Xk
{

                                                                                       

const Quat Quat::IDENTITY = Quat(1,0,0,0);

                                                                                       

Quat::Quat()
{
 identity();
}
 
Quat::Quat(const Quat& other)
{
 set(other);
}

Quat::Quat(const Real& w_val, const Real& x_val, const Real& y_val, const Real& z_val)
{
 setWXYZ(w_val, x_val, y_val, z_val);
}

Quat::Quat(const Radian& rad, const Vec3& vec)
{
 fromAngleAxis(rad, vec);
}

Quat::Quat(const Matrix33& other)
{
 set(other);
}
 
Quat::Quat(const Matrix44& other)
{
 set(other);
}

Quat Quat::operator=(const Matrix33& other)
{
 set(other);
 return *this;
}

Quat Quat::operator=(const Matrix44& other)
{
 set(other);
 return *this;
}
 
 
 // This function was adopted from the OGRE3D Library,Quat class from http://www.ogre3d.org
 void Quat::set(const Matrix33& kRot)
 {

   // Algorithm in Ken Shoemake's article in 1987 SIGGRAPH course notes
   // article "Quat Calculus and Fast Animation".

   Real fTrace = kRot[0][0]+kRot[1][1]+kRot[2][2];
   Real fRoot;

   if ( fTrace > 0.0 )
   {
       // |w| > 1/2, may as well choose w > 1/2
       fRoot = ::Xk::Math::sqrt(fTrace + (Real) 1.0);  // 2w
       w = (Real) 0.5 * fRoot;
       fRoot = (Real) 0.5 / fRoot;  // 1/(4w)
       x = (kRot[2][1]-kRot[1][2])*fRoot;
       y = (kRot[0][2]-kRot[2][0])*fRoot;
       z = (kRot[1][0]-kRot[0][1])*fRoot;
   }
   else
   {
       // |w| <= 1/2
        size_t s_iNext[3] = { 1, 2, 0 };
       size_t i = 0;
       if ( kRot[1][1] > kRot[0][0] )
           i = 1;
       if ( kRot[2][2] > kRot[i][i] )
           i = 2;
       size_t j = s_iNext[i];
       size_t k = s_iNext[j];

       fRoot = ::Xk::Math::sqrt(kRot[i][i]-kRot[j][j]-kRot[k][k] + (Real) 1.0);
       Real* apkQuat[3] = { &x, &y, &z };
       *apkQuat[i] = (Real) 0.5 * fRoot;
       fRoot = (Real) 0.5 /fRoot;
       w = (kRot[k][j]-kRot[j][k])*fRoot;
       *apkQuat[j] = (kRot[j][i]+kRot[i][j])*fRoot;
       *apkQuat[k] = (kRot[k][i]+kRot[i][k])*fRoot;
   }
 }

 // This function was adopted from the OGRE3D Library,Quat class from http://www.ogre3d.org
 void Quat::set(const Matrix44& kRot)
 {

   // Algorithm in Ken Shoemake's article in 1987 SIGGRAPH course notes
   // article "Quat Calculus and Fast Animation".

   Real fTrace = kRot[0][0]+kRot[1][1]+kRot[2][2];
   Real fRoot;

   if ( fTrace > 0.0 )
   {
       // |w| > 1/2, may as well choose w > 1/2
       fRoot = ::Xk::Math::sqrt(fTrace + (Real) 1.0);  // 2w
       w = (Real) 0.5 * fRoot;
       fRoot = (Real) 0.5 / fRoot;  // 1/(4w)
       x = (kRot[2][1]-kRot[1][2])*fRoot;
       y = (kRot[0][2]-kRot[2][0])*fRoot;
       z = (kRot[1][0]-kRot[0][1])*fRoot;
   }
   else
   {
       // |w| <= 1/2
        size_t s_iNext[3] = { 1, 2, 0 };
       size_t i = 0;
       if ( kRot[1][1] > kRot[0][0] )
           i = 1;
       if ( kRot[2][2] > kRot[i][i] )
           i = 2;
       size_t j = s_iNext[i];
       size_t k = s_iNext[j];

       fRoot = ::Xk::Math::sqrt(kRot[i][i]-kRot[j][j]-kRot[k][k] + (Real) 1.0);
       Real* apkQuat[3] = { &x, &y, &z };
       *apkQuat[i] = (Real) 0.5 * fRoot;
       fRoot = (Real) 0.5 /fRoot;
       w = (kRot[k][j]-kRot[j][k])*fRoot;
       *apkQuat[j] = (kRot[j][i]+kRot[i][j])*fRoot;
       *apkQuat[k] = (kRot[k][i]+kRot[i][k])*fRoot;
   }
 }

 void Quat::set(const Quat& other)
 {
  w = other.w;
  x = other.x;
  y = other.y;
  z = other.z;
 }

 void Quat::setXYZW(const Real& x_val, const Real& y_val, const Real& z_val, const Real& w_val)
 {
  w = w_val;
  x = x_val;
  y = y_val;
  z = z_val;
 }

 void Quat::setWXYZ(const Real& w_val, const Real& x_val, const Real& y_val, const Real& z_val)
 {
  w = w_val;
  x = x_val;
  y = y_val;
  z = z_val;
 }

 void Quat::identity()
 {
  w = (Real) 1;
  x = (Real) 0;
  y = (Real) 0;
  z = (Real) 0;
 }

 Real Quat::dot(Quat& q)
 {
  return Real( (w * q.w) + 
               (x * q.x) + 
               (y * q.y) + 
               (z * q.z)  );
 }

 Real Quat::dot(const Quat& q) const
 {
  return Real( (w * q.w) + 
               (x * q.x) + 
               (y * q.y) + 
               (z * q.z)  );
 }

 Real Quat::lengthSquared()
 {
  return dot(*this);
 }

 Real Quat::length()
 {
  return ::Xk::Math::sqrt(lengthSquared());
 }

 void Quat::normalise()
 {
  Real l = length();
  if (l < (Real) 1E-4)
   return;
  
  Real inv = (Real) 1.0 / l;
  x *= inv;
  y *= inv;
  z *= inv;
  w *= inv;
 }

 bool Quat::isNormalised(Real epsilon_tolerance)
 {
  return ::Xk::Math::nearEqual( lengthSquared(), (Real) 1, epsilon_tolerance);
 }

 void Quat::conj()
 {
  x = -x;
  y = -y;
  z = -z;
 }

 void Quat::fromAngleAxis(const Radian& rad, const Vec3& axis)
 {
  float half_rad = rad * 0.5f;
  float s = Math::sin(half_rad);
  w = Math::cos(s);
  x = axis.x;
  y = axis.y;
  z = axis.z;
 }
 

 void Quat::invert()
 {
  conj();
  
  Real l = lengthSquared();
  if (l < (Real) 1E-4)
   return;
  
  Real inv = (Real) 1.0 / l;
  x *= inv;
  y *= inv;
  z *= inv;
  w *= inv;
 }

 Quat Quat::invert(const Quat& original)
 {
  Quat r(original);
  r.invert();
  return r;
 }

 bool Quat::nearly(const Quat& a, const Quat& b, const Real& tolerance)
 {
  return bool( ::Xk::Math::nearEqual( a.w, b.w, tolerance) &&
               ::Xk::Math::nearEqual( a.x, b.x, tolerance) &&
               ::Xk::Math::nearEqual( a.y, b.y, tolerance) &&
               ::Xk::Math::nearEqual( a.z, b.z, tolerance) );
 }

 Quat Quat::lerp(const Quat& a, const Quat& b, const Real& alpha)
 {
  Real cosom = a.dot(b);
  
  Quat q;
   
  if (cosom < (Real) 0.0)
  {
   q.w = -b.w;
   q.x = -b.x;
   q.y = -b.y;
   q.z = -b.z;
  }
  else
  {
   q = b;
  }

  Real sclp, sclq;
  sclp = (Real) 1.0 - alpha;
  sclq = alpha;

  Quat result;
  result.w = sclp * a.w + sclq * q.w;
  result.x = sclp * a.x + sclq * q.x;
  result.y = sclp * a.y + sclq * q.y;
  result.z = sclp * a.z + sclq * q.z;
  return result;
 }

 Quat Quat::slerp(const Quat& a, const Quat& b, const Real& alpha, bool adjustSign)
 {
  Real cosom = a.dot(b);
  
  Quat q;
   
  if (cosom < (Real) 0.0)
  {
   cosom = -cosom;
   q.w = -b.w;
   q.x = -b.x;
   q.y = -b.y;
   q.z = -b.z;
  }
  else
  {
   q = b;
  }

  Real sclp, sclq;
  if ( ((Real) 1.0 - cosom) > (Real) 1E-4)
  {
   Real omega, sinom;
   omega = ::Xk::Math::arccos(cosom);
   sinom = ::Xk::Math::sin(omega);
   sclp  = ::Xk::Math::sin( ( (Real) 1.0 - alpha) * omega ) / sinom;
   sclq  = ::Xk::Math::sin( alpha * omega) / sinom;
  }
  else
  {
   sclp = (Real) 1.0 - alpha;
   sclq = alpha;
  }
  
  Quat result;
  result.w = sclp * a.w + sclq * q.w;
  result.x = sclp * a.x + sclq * q.x;
  result.y = sclp * a.y + sclq * q.y;
  result.z = sclp * a.z + sclq * q.z;
  return result;
 }


 Real& Quat::operator[](const size_t i)
 {
  return (&x)[i];
 }

 const Real& Quat::operator[](const size_t i) const
 {
  return (&x)[i];
 }

 void Quat::multiply(Quat& r, const Quat& a, const Quat& b)
 {
  r.x = (a.w * b.x) + (a.x * b.w) + (a.y * b.z) - (a.z * b.y);
  r.y = (a.w * b.y) + (a.y * b.w) + (a.z * b.x) - (a.x * b.z);
  r.z = (a.w * b.z) + (a.z * b.w) + (a.x * b.y) - (a.y * b.x);
  r.w = (a.w * b.w) - (a.x * b.x) - (a.y * b.y) - (a.z * b.z);
 }

 void Quat::multiply(Quat& r, const Quat& a, const Real& s)
 {
  r.w = a.w * s;
  r.x = a.x * s;
  r.y = a.y * s;
  r.z = a.z * s;
 }

 void Quat::divide(Quat& r, const Quat& a, const Quat& b)
 {
//  multiply(r, a, b.invert());
  multiply(r, a, Quat::invert(b));
 };

   void Quat::divide(Quat& r, const Quat& a, const Real& s)
 {
  r.w = a.w / s;
  r.x = a.x / s;
  r.y = a.y / s;
  r.z = a.z / s;
 };

 void Quat::add(Quat& r, const Quat& a, const Quat& b)
 {
  r.w = a.w + b.w;
  r.x = a.x + b.x;
  r.y = a.y + b.y;
  r.z = a.z + b.z;
 };

 void Quat::subtract(Quat& r, const Quat& a, const Quat& b)
 {
  r.w = a.w + b.w;
  r.x = a.x + b.x;
  r.y = a.y + b.y;
  r.z = a.z + b.z;
 };

  bool Quat::operator == (const Quat& other) const
 {
  return (w == other.w && x == other.x && y == other.y && z == other.z);
 }

  bool Quat::operator != (const Quat& other) const
 {
  return (w != other.w || x != other.x || y != other.y || z != other.z);
 }

  Quat Quat::operator + ( const Quat& other)
 {
  Quat r;
  add(r, *this, other);
  return r;
 }
 
  void Quat::operator +=(const Quat& other)
 {
  Quat r;
  add(r, *this, other);
  set(r);
 }

  Quat Quat::operator - ( const Quat& other)
 {
  Quat r;
  subtract(r, *this, other);
  return r;
 }

  void Quat::operator -=(const Quat& other)
 {
  Quat r;
  subtract(r, *this, other);
  set(r);
 }

  Quat Quat::operator * ( const Quat& other)
 {
  Quat r;
  multiply(r, *this, other);
  return r;
 }

  void Quat::operator *= (const Quat& other)
 {
  Quat r;
  multiply(r, *this, other);
  set(r);
 }

  Quat Quat::operator * (Real scalar)
 {
  Quat r;
  multiply(r, *this, scalar);
  return r;
 }

  void Quat::operator *= (Real scalar)
 {
  Quat r;
  multiply(r, *this, scalar);
  set(r);
 }

  Quat Quat::operator / ( const Quat& other)
 {
  Quat r;
  divide(r, *this, other);
  return r;
 }

  void Quat::operator /=( const Quat& other)
 {
  Quat r;
  divide(r, *this, other);
  set(r);
 }

 Quat Quat::operator / ( const Real& scalar)
 {
  Quat r;
  divide(r, *this, scalar);
  return r;
 }

  void Quat::operator /=( const Real& scalar)
 {
  Quat r;
  divide(r, *this, scalar);
  set(r);
 }

 Quat Quat::operator-() const
 {
  return Quat(-w, -x, -y, -z);
 }

                                                                                       

} // namespace Xk

                                                                                       
