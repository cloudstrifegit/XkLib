
#include "XkStable.h"
#include "XkClasses.h"

                                                                                       

namespace Xk
{

                                                                                       

namespace Classes
{

                                                                                       

static const char*  sClasses[626] = {

  "USER_CLASSES_BEGIN",
  "void",
  "bool",
  "char",
  "short",
  "int",
  "float",
  "double",
  "long",
  "unsigned_char",
  "unsigned_short",
  "unsigned_int",
  "unsigned_long",
  "RENDERSYSTEMS_CLASSES_BEGIN",
  "USER_CLASSES_BEGIN",
};

const char* TypeToCStr(int i)
{
 if (i < RENDERSYSTEMS_CLASSES_BEGIN)
  return sClasses[i];
 return "User";
} // void TypeToCstr

                                                                                       

} // namespace Classes

                                                                                       

} // namespace XK_NAMESPACE

                                                                                       
	