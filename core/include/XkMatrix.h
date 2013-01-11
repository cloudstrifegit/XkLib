
#ifndef XK_MATRIX_H
#define XK_MATRIX_H

                                                                                       

#include "XkStable.h"
#include "XkMatrix.h"
#include "XkVec3.h"
#include "XkQuat.h"
#include "XkString.h"
#include "XkEnums.h"

                                                                                       

namespace Xk
{

class Quat;
class Vec3;

/** \brief Matrix33
*/
class XkPublicClass Matrix33
{
 public:
 
 enum
 {
  Rows = 3,
  Cols = 3,
  Size = 9
 };
 
 Matrix33();
 
 Matrix33(const Real& _00, const Real& _01, const Real& _02,
                 const Real& _10, const Real& _11, const Real& _12,
                 const Real& _20, const Real& _21, const Real& _22);
 
 Matrix33(const Real mem[Rows][Cols]);
 
 Matrix33(const Matrix33& other);

 Matrix33(const Quat& quat);

 Matrix33 operator=(const Matrix33& other);

 void set(const Matrix33& other);

 void set(const Real mem[Rows][Cols]);

 void set(const Quat& quat);

 void set(const Real& w, const Real& x, const Real& y, const Real& z);

 void set(const Real& _00, const Real& _01, const Real& _02,
                 const Real& _10, const Real& _11, const Real& _12,
                 const Real& _20, const Real& _21, const Real& _22);

  
 Real* operator[](size_t row) const;

 void identity();
  
 void zero();

 Real* ptr();
 
 const Real* ptr() const;

 String to_s() const;

 XkPublicFunction friend std::ostream& operator << (std::ostream& o, const Matrix33& m)
 {
  o << m.to_s();
  return o;
 }

 static const Matrix33 ZERO;
 
 static const Matrix33 IDENTITY;
 
 protected:
 
  union
  {
   Real M[9];
   Real m[3][3];
  } m;
  
};

/** \brief Matrix44
*/
class XkPublicClass Matrix44
{
 public:
 
 enum
 {
  Rows = 4,
  Cols = 4,
  Size = 16
 };
 
 Matrix44();
 
 Matrix44(const Real& _00, const Real& _01, const Real& _02, const Real& _03,
                 const Real& _10, const Real& _11, const Real& _12, const Real& _13,
                 const Real& _20, const Real& _21, const Real& _22, const Real& _23,
                 const Real& _30, const Real& _31, const Real& _32, const Real& _33
                );
 
 Matrix44(const Real mem[Rows][Cols]);
 
 Matrix44(const Matrix44& other);
 
 Matrix44(const Vec3& translation_component);
 
 Matrix44(const Quat& rotation_asquaternion_component);
 
 Matrix44(const Vec3& translation_component, const Quat& rotation_asquaternion_component);

 Matrix44 operator=(const Matrix44& other);
 

 void set(const Matrix44& other);
 
 void set(const Real mem[Rows][Cols]);
 
 void set(const Quat& quat);
 
 void set(const Radian& angle, Enums::Axis);

 void set(const Real& w, const Real& x, const Real& y, const Real& z);
 
 void set(const Vec3& vec);
 
 void set(const Real& trans_x, const Real& trans_y, const Real& trans_z);
 
 void get(Real& trans_x, Real& trans_y, Real& trans_z) const;
 
 void set(const Real& _00, const Real& _01, const Real& _02, const Real& _03,
                 const Real& _10, const Real& _11, const Real& _12, const Real& _13,
                 const Real& _20, const Real& _21, const Real& _22, const Real& _23,
                 const Real& _30, const Real& _31, const Real& _32, const Real& _33
                );

 Real* operator[](size_t row) const;

 operator Vec3();

 operator Vec3() const;

 template<typename T> T translation_as() const
 {
  T t;
  t.x = m.m[0][3];
  t.y = m.m[1][3];
  t.z = m.m[2][3];
 }

 void identity();

 void translationIdentity();

 void scaleIdentity();

 void rotationIdentity();

 void zero();

 Real* ptr();

 const Real* ptr() const;
 
 String to_s() const;

 XkPublicFunction friend std::ostream& operator << (std::ostream& o, const Matrix44& m)
 {
  o << m.to_s();
  return o;
 }

 void columnMajor(Real* f_16);
 
 Vec3 operator*(const Vec3& other) const;
 
 static const Matrix44 ZERO;
 
 static const Matrix44 IDENTITY;
 
 static const Matrix44 UNINITIALISED;
 
 protected:
 
 union
 {
  Real M[16];
  Real m[4][4];
 } m;
 
};

                                                                                       

} // namespace Xk

                                                                                       

#endif
