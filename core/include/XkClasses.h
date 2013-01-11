
#ifndef XK_CLASSES_H
#define XK_CLASSES_H

                                                                                       


namespace Xk
{

namespace Classes
{

enum classes
{
  XK_CLASSES_BEGIN = 0,
  _void,
  _bool,
  _char,
  _short,
  _int,
  _float,
  _double,
  _long,
  _unsigned_char,
  _unsigned_short,
  _unsigned_int,
  _unsigned_long,
  RENDERSYSTEMS_CLASSES_BEGIN,
  USER_CLASS = 50000
};

                                                                                       

/** \brief Turns a Xk::Classes::Enum into a String and any PhysX MemoryType enum value as well.
*/
const char*  TypeToCStr(int i);

                                                                                       
} // namespace Classes
} // namespace Xk

                                                                                       
#endif
