
#include "XkStable.h"
#include "XkVec4.h"

                                                                                       

namespace Xk
{

                                                                                       

const Xk::Vec4        Xk::Vec4::ZERO(0,0,0,0);


Vec4::Vec4()
{
 zero();
}

Vec4::Vec4(const Vec4& other)
{
 set(other);
}

Vec4::Vec4(const Real& W, const Real& X, const Real& Y, const Real& Z)
{
 set(W, X, Y, Z);
};

void Vec4::set(const Real& W,const Real& X, const Real& Y, const Real& Z)
{
 w = W; x = X; y = Y; z = Z;
}

void Vec4::set(const Vec4& other)
{
 w = other.w;
 x = other.x;
 y = other.y;
 z = other.z;
}

Real* Vec4::ptr()
{
 return &x;
}

const Real* Vec4::ptr() const
{
 return &x;
}

Real Vec4::normalise()
{
 const Real length = magnitudeSquared();
 if (length < 1E-8)
 {
  const Real inv = (Real) 1.0 / length;
  w *= inv;
  x *= inv;
  y *= inv;
  z *= inv;
 }
 return length;
}

Vec4 Vec4::mid(const Vec4& other) const
{
 return Vec4( (w + other.w) * 0.5, (x + other.x) * 0.5, (y + other.y) * 0.5, (z + other.z) * 0.5);
}

Real Vec4::magnitudeSquared() const
{
 return (w * w) + (x * x) + (y * y) + (z * z);
}

Real Vec4::magnitude() const
{
 return ::Xk::Math::sqrt(magnitudeSquared());
}

void Vec4::min(const Vec4& other)
{
 w = ::Xk::Math::min(w, other.w);
 x = ::Xk::Math::min(x, other.x);
 y = ::Xk::Math::min(y, other.y);
 z = ::Xk::Math::min(z, other.z);
}

void Vec4::max(const Vec4& other)
{
 w = ::Xk::Math::max(w, other.w);
 x = ::Xk::Math::max(x, other.x);
 y = ::Xk::Math::max(y, other.y);
 z = ::Xk::Math::max(z, other.z);
}

void Vec4::fill(const Real& value)
{
 w = x = y = z = value;
}

void Vec4::zero()
{
 fill((Real)0);
}

bool Vec4::isZero() const
{
 return ((w == (Real) 0) &&  (x == (Real) 0) && (y == (Real) 0) && (z == (Real) 0));
}

Vec4 Vec4::lerp(const Vec4& other, const Real& alpha) const
{
 return Vec4(::Xk::Math::lerp(x, other.x, alpha), ::Xk::Math::lerp(x, other.x, alpha),::Xk::Math::lerp(y, other.y, alpha),::Xk::Math::lerp(z, other.z, alpha));
}

Vec4 Vec4::operator=(const Vec4& other)
{
 set(other);
 return *this;
}

bool Vec4::operator<(const Vec4& other) const
{
 return ((w < other.w) && (x < other.x) && (y < other.y) && (z < other.z));
}

 bool Vec4::operator>(const Vec4& other) const
{
 return ((w > other.w) && (x > other.x) && (y > other.y) && (z > other.z));
}

bool Vec4::operator==(const Vec4& other) const
{
 return ((w == other.w) && (x == other.x) && (y == other.y) && (z == other.z));
}

bool Vec4::operator!=(const Vec4& other) const
{
 return ((w != other.w) || (x != other.x) || (y != other.y) || (z != other.z));
}

Vec4 Vec4::operator+(const Vec4& other)
{
 return Vec4(w + other.w, x + other.x, y + other.y, z + other.z);
}

Vec4 Vec4::operator+(const Vec4& other) const
{
 return Vec4(w + other.w, x + other.x, y + other.y, z + other.z);
}

void Vec4::operator+=(const Vec4& other)
{
 w += other.w;
 x += other.x;
 y += other.y;
 z += other.z;
}

Vec4 Vec4::operator-(const Vec4& other) const
{
 return Vec4(w - other.w, x - other.x, y - other.y, z - other.z);
}

Vec4 Vec4::operator-(const Vec4& other)
{
 return Vec4(w - other.w, x - other.x, y - other.y, z - other.z);
}

void Vec4::operator-=(const Vec4& other)
{
 w -= other.w;
 x -= other.x;
 y -= other.y;
 z -= other.z;
}

 Vec4 Vec4::operator*(const Vec4& other)
{
 return Vec4(w * other.w, x * other.x, y * other.y, z * other.z);
}

void Vec4::operator*=(const Vec4& other)
{
 w *= other.w;
 x *= other.x;
 y *= other.y;
 z *= other.z;
}

Vec4 Vec4::operator*(const Real& s)
{
 return Vec4(w * s, x * s, y * s, z * s);
}

void Vec4::operator*=(const Real& s)
{
 w *= s;
 x *= s;
 y *= s;
 z *= s;
}

void Vec4::operator/=(const Vec4& other)
{
 w /= other.w;
 x /= other.x;
 y /= other.y;
 z /= other.z;
}

Vec4 Vec4::operator/(const Vec4& other)
{
 return Vec4(w * other.w, x * other.x, y * other.y, z * other.z);
}

void Vec4::operator/=(const Real& s)
{
 const Real inv = (Real) 1.0 / s;
 w *= inv;
 x *= inv;
 y *= inv;
 z *= inv;
}

Vec4 Vec4::operator/(const Real& s)
{
 const Real inv = (Real) 1.0 / s;
 return Vec4(w * inv, x * inv, y * inv, z * inv);
}

Vec4 Vec4::operator+() const
{
 return *this;
}

Vec4 Vec4::operator-() const
{
 return Vec4(-w, -x, -y, -z);
}

Real& Vec4::operator[](const size_t i)
{
 return (&x)[i];
}

const Real& Vec4::operator[](const size_t i) const
{
 return (&x)[i];
}

std::string Vec4::to_s() const
{
 std::ostringstream ss;
 ss << w << " " << x << " " << y << " " << z;
 return ss.str();
}

std::vector<Real> Vec4::to_a() const
{
 std::vector<Real> a;
 a.push_back(w);
 a.push_back(x);
 a.push_back(y);
 a.push_back(z);
 return a;
}

                                                                                       

} // namespace Xk

                                                                                       
