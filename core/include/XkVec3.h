
#ifndef XK_VEC3_H
#define XK_VEC3_H

                                                                                       

#include "XkStable.h"
#include "XkString.h"
#include "XkMatrix.h"
#include "XkEnums.h"

namespace Xk
{



class Vec2;
class Vec3;
class Vec4;
class Quat;
class Matrix33;
class Matrix44;

class XkPublicClass Vec3
{
 public:

  enum
  {
   Size = 3
  };

  Vec3();

  Vec3(const Vec3& other);

  template<typename xyz_vector_class>
  Vec3(const xyz_vector_class& other)
  {
   set(other.x, other.y, other.z);
  }

  Vec3(const Matrix44& other);

  template<typename xyz_vector_class>
  Vec3 operator=(const xyz_vector_class& other)
  {
   set(other.x, other.y, other.z);
   return *this;
  }
  
  Enums::Axis axis() const;

  /*! function. used
      desc.
          Returns a Vec3, with the contents set to 1.0, if the original is a non-zero value.
          i.e.
             {0,4.5,-2} => {0,1,1}
  */
  Vec3 used() const;

  Vec3(const Real& X, const Real& Y, const Real& Z);

  Vec3(const std::string&);

  void set(const Real& X, const Real& Y, const Real& Z);

  void set(const Vec3& other);

  Real* ptr();

  const Real* ptr() const;

  Real normalise();
  
  Vec3 normaliseCopy() const;
  
  Vec3 mid(const Vec3& other) const;

  Real dot(const Vec3& other) const;

  Vec3 cross(const Vec3& other);

  Real distance(const Vec3& other) const;

  Real distanceSquared(const Vec3& other) const;

  Real magnitudeSquared() const;

  Real magnitude() const;

  void min(const Vec3& other);

  void max(const Vec3& other);

  void fill(const Real& value);

  void zero();

  bool isZero() const;

  bool isNegative() const;

  void clamp(const Vec3& min, const Vec3& max);

  Vec3 lerp(const Vec3& other, const Real& alpha) const;

  friend Vec3 operator * ( const Real fScalar, const Vec3& rkVector )
  {
      return Vec3(
          fScalar * rkVector.x,
          fScalar * rkVector.y,
          fScalar * rkVector.z);
  }

  friend Vec3 operator * (  const Vec3& rkVector, const Real fScalar )
  {
      return Vec3(
          fScalar * rkVector.x,
          fScalar * rkVector.y,
          fScalar * rkVector.z);
  }

  Vec3 operator=(const Vec3& other);

  bool operator<(const Vec3& other) const;

  bool operator<=(const Vec3& other) const;

  bool operator>=(const Vec3& other) const;

  bool operator>(const Vec3& other) const;

  bool operator==(const Vec3& other) const;

  bool operator!=(const Vec3& other) const;

  Vec3 operator+(const Vec3& other);

  Vec3 operator+(const Vec3& other) const;

  Matrix44 operator+(const Quat& other);

  void operator+=(const Vec3& other);

  Vec3 operator-(const Vec3& other);

  Vec3 operator-(const Vec3& other) const;

  void operator-=(const Vec3& other);

  Vec3 operator*(const Vec3& other);

  void operator*=(const Vec3& other);

  Vec3 operator*=(const Quat& other);

  Vec3 operator*(const Real& s);

  void operator*=(const Real& s);

  Vec3 operator*(const Quat& quat);

  void operator/=(const Vec3& other);

  Vec3 operator/(const Vec3& other);

  void operator/=(const Real& s);

  Vec3 operator/(const Real& s);

  Vec3 operator+() const;

  Vec3 operator-() const;

  Real& operator[](const size_t i);

  const Real& operator[](const size_t i) const;

  template<class user_xyz_vector_type>
  user_xyz_vector_type as() const
  {
   user_xyz_vector_type v;
   v.x = x;
   v.y = y;
   v.z = z;
   return v;
  }

  template<class user_xyz_vector_type>
  void from(const user_xyz_vector_type& vec)
  {
   x = vec.x;
   y = vec.y;
   z = vec.z;
  }

  String to_s() const;

  XkPublicFunction friend std::ostream& operator << (std::ostream& o, const Vec3& v)
  {
   o << v.to_s();
   return o;
  }

  std::vector<Real> to_a() const;

  static Vec3 random(float x0, float x1, float y0, float y1, float z0, float z1);

  static const Vec3 ZERO;

  static const Vec3 UNIT_X;

  static const Vec3 UNIT_Y;

  static const Vec3 UNIT_Z;

  static const Vec3 NEGATIVE_UNIT_X;

  static const Vec3 NEGATIVE_UNIT_Y;

  static const Vec3 NEGATIVE_UNIT_Z;

  static const Vec3 POSITIVE_1_1_1;

  static const Vec3 NEGATIVE_1_1_1;


  Real x, y, z;

};

                                                                                       

} // namespace Xk

                                                                                       

#endif
