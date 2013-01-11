
#ifndef XK_VEC4_H
#define XK_VEC4_H

                                                                                       

#include "XkStable.h"
#include "XkMath.h"
#include "XkMatrix.h"
                                                                                       

namespace Xk
{

                                                                                       

class Vec2;
class Vec3;
class Vec4;
class Quat;
class Matrix33;
class Matrix44;

class XkPublicClass Vec4
{
 public:
  
  enum
  {
   Size = 4
  };
  
  Vec4();

  Vec4(const Vec4& other);
  
  Vec4(const Real& W, const Real& X, const Real& Y, const Real& Z);
  
  void set(const Real& W,const Real& X, const Real& Y, const Real& Z);
  
  void set(const Vec4& other);
  
  Real* ptr();

  const Real* ptr() const;

  Real normalise();

  Vec4 mid(const Vec4& other) const;
  
  Real magnitudeSquared() const;

  Real magnitude() const;

  void min(const Vec4& other);

  void max(const Vec4& other);

  void fill(const Real& value);

  void zero();

  bool isZero() const;

  Vec4 lerp(const Vec4& other, const Real& alpha) const;

  Vec4 operator=(const Vec4& other);

  bool operator<(const Vec4& other) const;

  bool operator>(const Vec4& other) const;

  bool operator==(const Vec4& other) const;

  bool operator!=(const Vec4& other) const;

  Vec4 operator+(const Vec4& other);

  Vec4 operator+(const Vec4& other) const;

  void operator+=(const Vec4& other);

  Vec4 operator-(const Vec4& other) const;

  Vec4 operator-(const Vec4& other);

  void operator-=(const Vec4& other);

  Vec4 operator*(const Vec4& other);

  void operator*=(const Vec4& other);

  Vec4 operator*(const Real& s);

  void operator*=(const Real& s);

  friend Vec4 operator*(const Real& s, const Vec4& vector)
  {
   return Vec4(vector.w * s, vector.x * s, vector.y * s, vector.z * s);
  }

  void operator/=(const Vec4& other);

  Vec4 operator/(const Vec4& other);

  void operator/=(const Real& s);

  Vec4 operator/(const Real& s);

  Vec4 operator+() const;

  Vec4 operator-() const;

  Real& operator[](const size_t i);
  
  const Real& operator[](const size_t i) const;

  std::string to_s() const;

  std::vector<Real> to_a() const;

  Real x, y, z, w;

  static const Vec4 ZERO;
};

                                                                                       

} // namespace Xk

                                                                                       

#endif
