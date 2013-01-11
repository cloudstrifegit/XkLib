
#ifndef XK_VEC2_H
#define XK_VEC2_H

                                                                                       

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

class XkPublicClass Vec2
{
 public:
    
  enum
  {
   Size = 2
  };
  
  Vec2();
  
  Vec2(const Vec2& other);
  
  Vec2(const Real& X, const Real& Y);
  
  void set(const Real& X, const Real& Y);
  
  void set(const Vec2& other);
  
  Real* ptr();
  
  const Real* ptr() const;
  
  Real normalise();
  
  Vec2 mid(const Vec2& other) const;
  
  Real dot(const Vec2& other) const;
  
  Real cross(const Vec2& other);
  
  Real magnitudeSquared() const;
  
  Real magnitude() const;
  
  void min(const Vec2& other);
  
  void max(const Vec2& other);
  
  void fill(const Real& value);
  
  void zero();
  
  bool isZero() const;
  
  Vec2 lerp(const Vec2& other, const Real& alpha) const;
  
  Vec2 operator=(const Vec2& other);
  
  bool operator<=(const Vec2& other) const;
  
  bool operator>=(const Vec2& other) const;
  
  bool operator<(const Vec2& other) const;
  
  bool operator>(const Vec2& other) const;
  
  bool operator==(const Vec2& other) const;
  
  bool operator!=(const Vec2& other) const;
  
  Vec2 operator+(const Vec2& other);
  
  Vec2 operator+(const Vec2& other) const;
  
  void operator+=(const Vec2& other);
  
  Vec2 operator-(const Vec2& other);
  
  Vec2 operator-(const Vec2& other) const;
  
  void operator-=(const Vec2& other);
  
  Vec2 operator*(const Vec2& other);
  
  void operator*=(const Vec2& other);
  
  Vec2 operator*(const Real& s);
  
  void operator*=(const Real& s);
  
  friend Vec2 operator*(const Real& s, const Vec2& vector)
  {
   return Vec2(vector.x * s, vector.y * s);
  }
  
  void operator/=(const Vec2& other);
  
  Vec2 operator/(const Vec2& other);
  
  void operator/=(const Real& s);
  
  Vec2 operator/(const Real& s);
  
  Vec2 operator+() const;
  
  Vec2 operator-() const;
  
  Real& operator[](const size_t i);
  
  const Real& operator[](const size_t i) const;
  
  std::string to_s() const;

  std::vector<Real> to_a() const;

  Real x, y;
  
  static const Vec2 ZERO;
  
};                                                                  

} // namespace Xk

#endif
