
#include "XkStable.h"
#include "XkRadian.h"

                                                                                       

namespace Xk
{

                                                                                       

const Xk::Radian Xk::Radian::ZERO(0.0f);

Radian::Radian()
: mRadian(ZERO.mRadian)
{
}


Radian::Radian(Real radians)
: mRadian(radians)
{
}

Radian::Radian(const Radian& other)
: mRadian(other.mRadian)
{
}

Real Radian::rad() const
{
 return mRadian;
}

Radian& Radian::operator=(const Real& other)
{
 mRadian = other;
 return *this;
}

const Radian Radian::operator+() const
{
 return *this;
}

Radian Radian::operator+(const Radian& other) const
{
 return Radian(mRadian + other.mRadian);
}

Radian Radian::operator+(const Real& other) const
{
 return Radian(mRadian + other);
}

Radian& Radian::operator+=(const Radian& other)
{
 mRadian += other.mRadian;
 return *this;
}

Radian& Radian::operator+=(const Real& other)
{
 mRadian += other;
 return *this;
}

Radian Radian::operator-() const
{
 return Radian(-mRadian);
}

Radian Radian::operator-(const Radian& other) const
{
 return Radian(mRadian - other.mRadian);
}

Radian Radian::operator-(const Real& other) const
{
 return Radian(mRadian - other);
}

Radian& Radian::operator-=(const Radian& other)
{
 mRadian -= other.mRadian;
 return *this;
}

Radian& Radian::operator-=(const Real& other)
{
 mRadian -= other;
 return *this;
}

Radian Radian::operator*(const Radian& other) const
{
 return Radian(mRadian * other);
}

Radian Radian::operator*(const Real& other) const
{
 return Radian(mRadian * other);
}

Radian& Radian::operator*=(const Radian& other)
{
 mRadian *= other.mRadian;
 return *this;
}

Radian& Radian::operator*=(const Real& other)
{
 mRadian *= other;
 return *this;
}

Radian Radian::operator/(const Radian& other) const
{
 return Radian(mRadian / other.mRadian);
}

Radian Radian::operator/(const Real& other) const
{
 return Radian(mRadian / other);
}

Radian& Radian::operator/=(const Radian& other)
{
 mRadian /= other.mRadian;
 return *this;
}

Radian& Radian::operator/=(const Real& other)
{
 mRadian /= other;
 return *this;
}

bool Radian::operator<(const Radian& other)
{
 return mRadian < other.mRadian;
}

bool Radian::operator<(const Real& other)
{
 return mRadian < other;
}

bool Radian::operator<=(const Radian& other)
{
 return mRadian <= other.mRadian;
}

bool Radian::operator<=(const Real& other)
{
 return mRadian <= other;
}

bool Radian::operator!=(const Radian& other)
{
 return mRadian != other.mRadian;
}

bool Radian::operator!=(const Real& other)
{
 return mRadian != other;
}

bool Radian::operator==(const Radian& other)
{
 return mRadian == other.mRadian;
}

bool Radian::operator==(const Real& other)
{
 return mRadian == other;
}

bool Radian::operator>=(const Radian& other)
{
 return mRadian >= other.mRadian;
}

bool Radian::operator>=(const Real& other)
{
 return mRadian >= other;
}

bool Radian::operator>(const Radian& other)
{
 return mRadian >= other.mRadian;
}

bool Radian::operator>(const Real& other)
{
 return mRadian >= other;
}

std::string Radian::to_s() const
{
 std::ostringstream ss;
 ss << mRadian;
 return ss.str();
}

Radian::operator Real() const
{
 return mRadian;
}

                                                                                       

} // namespace Xk

                                                                                       
