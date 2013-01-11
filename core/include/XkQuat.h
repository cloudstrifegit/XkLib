
#ifndef XK_QUAT_H
#define XK_QUAT_H

                                                                                       

#include "XkStable.h"
#include "XkRadian.h"

                                                                                       

namespace Xk
{

                                                                                       

class Matrix33;
class Matrix44;
class Vec3;

class XkPublicClass Quat
{
 
 public:
  
 Quat();
 
 Quat(const Quat& other);

 Quat(const Real& w_val, const Real& x_val, const Real& y_val, const Real& z_val);
  
 Quat(const Radian& rad, const Vec3&);

 Quat(const Matrix33& other);
  
 Quat(const Matrix44& other);
 
 template<typename wxyz_quaternion_class>
 Quat(const wxyz_quaternion_class& quat)
 {
  setWXYZ(quat.w, quat.x, quat.y, quat.z);
 }

 template<typename wxyz_quaternion_class>
 Quat operator=(const wxyz_quaternion_class& other)
 {
  set(other.w, other.x, other.y, other.z);
  return *this;
 }

 Quat operator=(const Matrix33& other);
 
 Quat operator=(const Matrix44& other);
 
 void set(const Matrix33& kRot);

 void set(const Matrix44& kRot);

 void set(const Quat& other);

 void setXYZW(const Real& x_val, const Real& y_val, const Real& z_val, const Real& w_val);

 void setWXYZ(const Real& w_val, const Real& x_val, const Real& y_val, const Real& z_val);

 void identity();

 Real dot(Quat& q);

 Real dot(const Quat& q) const;

 Real lengthSquared();

 Real length();

 void normalise();

 bool isNormalised(Real epsilon_tolerance = 1E-4);

 void conj();

 void invert();
 
 void fromAngleAxis(const Radian& rad, const Vec3& axis);
 
 static Quat invert(const Quat& original);

 bool nearly(const Quat& a, const Quat& b, const Real& tolerance = 1E-4);

 static Quat lerp(const Quat& a, const Quat& b, const Real& alpha);

 static Quat slerp(const Quat& a, const Quat& b, const Real& alpha, bool adjustSign = true);

 Real& operator[](const size_t i);

 const Real& operator[](const size_t i) const;

 static  void multiply(Quat& r, const Quat& a, const Quat& b);

 static  void multiply(Quat& r, const Quat& a, const Real& s);

 static  void divide(Quat& r, const Quat& a, const Quat& b);

 static  void divide(Quat& r, const Quat& a, const Real& s);

 static  void add(Quat& r, const Quat& a, const Quat& b);

 static  void subtract(Quat& r, const Quat& a, const Quat& b);

  bool operator == (const Quat& other) const;

  bool operator != (const Quat& other) const;

  Quat operator + ( const Quat& other);
 
  void operator +=(const Quat& other);

  Quat operator - ( const Quat& other);

  void operator -=(const Quat& other);

  Quat operator * ( const Quat& other);

  void operator *= (const Quat& other);

  Quat operator * (Real scalar);

  void operator *= (Real scalar);

  Quat operator / ( const Quat& other);

  void operator /=( const Quat& other);

  Quat operator / ( const Real& scalar);

  void operator /=( const Real& scalar);

  Quat operator-() const;

 template<class user_wxyz_vector_type>
  user_wxyz_vector_type as() const
 {
  user_wxyz_vector_type q;
  q.w = w;
  q.x = x;
  q.y = y;
  q.z = z;
  return q;
 }

 static const Quat IDENTITY;

 Real w, x, y, z;

};


                                                                                       

} // namespace Xk

                                                                                       

#endif
