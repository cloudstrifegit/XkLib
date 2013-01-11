
#ifndef XK_RADIAN_H
#define XK_RADIAN_H

                                                                                       

#include "XkStable.h"
#include <string>

                                                                                       

namespace Xk
{

                                                                                       

class XkPublicClass Radian
{
 public:
  
   Radian();
  
   Radian(Real radians);
  
   Radian(const Radian& other);
  
   Real    rad() const;

   Radian& operator=(const Real& other);
  
   const Radian operator+() const;
  
   Radian operator+(const Radian& other) const;
  
   Radian operator+(const Real& other) const;
  
   Radian& operator+=(const Radian& other);
  
   Radian& operator+=(const Real& other);
  
   Radian operator-() const;
  
   Radian operator-(const Radian& other) const;
  
   Radian operator-(const Real& other) const;
  
   Radian& operator-=(const Radian& other);
  
   Radian& operator-=(const Real& other);

   Radian operator*(const Radian& other) const;
  
   Radian operator*(const Real& other) const;

   Radian& operator*=(const Radian& other);
  
   Radian& operator*=(const Real& other);

   Radian operator/(const Radian& other) const;
  
   Radian operator/(const Real& other) const;

   Radian& operator/=(const Radian& other);
  
   Radian& operator/=(const Real& other);

   bool operator<(const Radian& other);

   bool operator<(const Real& other);

   bool operator<=(const Radian& other);

   bool operator<=(const Real& other);

   bool operator!=(const Radian& other);

   bool operator!=(const Real& other);

   bool operator==(const Radian& other);

   bool operator==(const Real& other);

   bool operator>=(const Radian& other);

   bool operator>=(const Real& other);

   bool operator>(const Radian& other);

   bool operator>(const Real& other);

   std::string to_s() const;
  
   operator Real() const;
  
  static const Radian ZERO;
  
 private:
  
  Real mRadian;
  
};

                                                                                       

} // namespace Xk

                                                                                       

#endif
