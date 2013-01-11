
#ifndef XK_STRING_H
#define XK_STRING_H

                                                                                       

#include "XkStable.h"
#include "XkBuffer.h"
#include <iostream>
#include <vector>
#include "XkMap.h"

                                                                                       

namespace Xk
{



typedef std::string String;

typedef std::stringstream StringStream;

typedef size_t StringHash;

class Vec2;

class Vec3;

class Vec4;

class Radian;

static const String BLANK_STRING = String();

static const StringHash BLANK_HASH = 0;

typedef std::pair<std::string, std::string> StringPair;

/*! function. to_s (bool)
    desc.
        Turns a boolean value into a string (true = "true", false = "false")
*/
String XkPublicFunction to_s(bool);

/*! function. to_s (unsigned char)
    desc.
        Turns a unsigned char into a string.
*/
String XkPublicFunction to_s(unsigned char);

/*! function. to_s (char)
    desc.
        Turns a char into a string.
*/
String XkPublicFunction to_s(char);

/*! function. to_s (short)
    desc.
        Turns a short into a string.
*/
String XkPublicFunction to_s(short);

/*! function. to_s (unsigned short)
    desc.
        Turns a unsigned short into a string.
*/
String XkPublicFunction to_s(unsigned short);

/*! function. to_s (int)
    desc.
        Turns a int into a string.
*/
String XkPublicFunction to_s(int);

/*! function. to_s (unsigned int)
    desc.
        Turns a unsigned int into a string.
*/
String XkPublicFunction to_s(unsigned int);

/*! function. to_s (float)
    desc.
        Turns a float into a string.
*/
String XkPublicFunction to_s(float);

/*! function. to_s (double)
    desc.
        Turns a double into a string.
*/
String XkPublicFunction to_s(double);

/*! function. to_s (Vec2)
    desc.
        Turns a Vec2 into a string.
*/
String XkPublicFunction to_s(const Vec2&);

/*! function. to_s (Vec3)
    desc.
        Turns a Vec3 into a string.
*/
String XkPublicFunction to_s(const Vec3&);

/*! function. to_s (Vec4)
    desc.
        Turns a Vec4 into a string.
*/
String XkPublicFunction to_s(const Vec4&);

/*! function. to_s (Radian)
    desc.
        Turns a Radian into a string.
*/
String XkPublicFunction to_s(const Radian&);

/*! function. to_s (void* with description)
   desc.
       Turns a pointer into a string, with a descriptional prefix.
*/
String XkPublicFunction to_s(void*, const String& = BLANK_STRING);

/*! function. to_s(float* array with length)
    desc.
       Turns a number of floats into strings, seperated by a space.
*/
String XkPublicFunction to_s(float*, size_t length);

/*! function. to_s(float* array with length)
    desc.
       Turns a number of floats into strings, seperated by a space.
*/
String XkPublicFunction to_s(unsigned int*, size_t length);


/*! function. to_i
    desc.
        String to int
*/
int XkPublicFunction to_i(const String&);

/*! function. to_f
    desc.
        String to float
*/
float XkPublicFunction to_f(const String&);

/*! function. to_b
    desc.
        String to bool
    note.
        This string checks upon the value of "true" (case-insensitive), any other values returns false.
*/
bool XkPublicFunction to_b(const String&);

template<typename T> void inspect(const T& value)
{
 std::cout << value << std::endl;
}

void XkPublicFunction inspect(const float& value);

void XkPublicFunction inspect(const double& value);

void XkPublicFunction inspect(const int& value);

void XkPublicFunction inspect(const char& value);

void XkPublicFunction inspect(const short& value);

void XkPublicFunction inspect(const unsigned int& value);

void XkPublicFunction inspect(const unsigned char& value);

void XkPublicFunction inspect(const unsigned short& value);

void XkPublicFunction inspect(const String& value);

template<typename T> void inspect(const std::vector<T>& value)
{
 std::cout << "{";
 for (typename std::vector<T>::iterator it = value.begin(); it != value.end(); ++it)
 {
  if (it != value.begin())
   std::cout << ", ";
  std::cout << (*it);
 }
 std::cout << "}" << std::endl;;
}

template<typename K,typename T> void inspect(const std::map<K,T>& value)
{
 std::cout << "[";
 for (typename std::map<K,T>::const_iterator it = value.begin(); it != value.end(); ++it)
 {
  if (it != value.begin())
   std::cout << ", ";
  std::cout << (*it).first << " => '" << (*it).second << "'";
 }
 std::cout << "]" << std::endl;;
}

template<typename K,typename T> void inspect(const std::multimap<K,T>& value)
{
 std::cout << "[";
 for (typename std::multimap<K,T>::const_iterator it = value.begin(); it != value.end(); ++it)
 {
  if (it != value.begin())
   std::cout << " , ";
  std::cout << (*it).first << " => '" << (*it).second << "'";
 }
 std::cout << "]" << std::endl;;
}

template<typename T> void inspect(const buffer<T>& value)
{
 std::cout << "{";
 for (unsigned int i=0;i < value.size();++i)
 {
  if (i != 0)
   std::cout << ", ";
  std::cout << value[i];
 }
 std::cout << "}" << std::endl;;
}


namespace Strings
{

/* function. hash
   desc.
        Turn a string into a hash
   args.
        const char* str -- String to hash.
   return.
        Hash of the string.
*/
StringHash XkPublicFunction hash(const char* str);

/* function. hash (alternate)
   desc.
        Turn a string into a hash
   args.
        const char* str -- String to hash.
   return.
        Hash of the string.
*/
StringHash XkPublicFunction hash(const String& str);

/* function. index
   desc.
       Find the first occurance of a char in a string
   args.
      const String& string -- String to search
      char search - Character to search
   return.
      size_t -- Position of the character, or String::npos if not found.
*/
size_t XkPublicFunction index(const String& string, char search);

/* function. index
   desc.
       Find the first occurance of a char in a string
   args.
      const String& string -- String to search
      char search - Character to search
   return.
      bool -- If the character exists.
*/
bool XkPublicFunction has(const String& string, char search);

/*! function. replace
    desc.
        Replaces all instances of a char with another.
*/
void XkPublicFunction replace(String& string, char search, char replacement);

/*! function. replace_copy
    desc.
        Replaces all instances of a char with another.
*/
String XkPublicFunction replace_copy(const String& original, char search, char replacement);

/*! function. trim
    desc.
        Removes whitespace at the start and end of a string
*/
void XkPublicFunction trim(String& string);

/*! function. trim
    desc.
        Removes whitespace at the start and end of a string
*/
String XkPublicFunction trim_copy(const String& original);

/*! function. captialise
    desc.
        Captialises the string
*/
void XkPublicFunction captialise(String& string);
/*! function. captialise
    desc.
        Captialises the string
*/
String XkPublicFunction captialise_copy(const String& original);

/*! function. lower
    desc.
        Lower cases the string.
*/
void XkPublicFunction lower(String& string);
/*! function. lower
    desc.
        Lower cases the string.
*/
String XkPublicFunction lower_copy(const String& original);

/*! function. lower
    desc.
        Upper cases the string.
*/
void XkPublicFunction upper(String& string);
/*! function. lower
    desc.
        Upper cases the string.
*/
String XkPublicFunction upper_copy(const String& original);

/*! function. slice
    desc.
        slices up the string to the beginning to the first occurance of a character
*/
void XkPublicFunction slice_to_first_of(String& string, char pattern);

/*! function. slice
    desc.
        slices up the string to the beginning to the last occurance of a character
*/
void XkPublicFunction slice_to_last_of(String& string, char pattern);

/*! function. slice
    desc.
        slices up the string after to the first occurance of a character
*/
void XkPublicFunction slice_after_first_of(String& string, char pattern);

/*! function. slice
    desc.
        slices up the string after to the last occurance of a character
*/
void XkPublicFunction slice_after_last_of(String& string, char pattern);

/*! function. slice
    desc.
        slices up the string based on a range.
*/
void XkPublicFunction slice(String& string, size_t begin);

/*! function. slice
    desc.
        slices up the string based on a range.
*/
void XkPublicFunction slice(String& string, size_t begin, size_t end);

/*! function. slice_copy
    desc.
        slices up the string based on a range.
*/
String XkPublicFunction slice_copy(const String& original, size_t begin);

/*! function. slice_copy
    desc.
        slices up the string based on a range.
*/
String XkPublicFunction slice_copy(const String& original, size_t begin, size_t end);

/*! function. starts
    desc.
        Does the string start with another string?
*/
bool XkPublicFunction starts(const String& original, const String& comparision);

/*! function. starts_insensitive
    desc.
        Does the string start with another string? Case insensitive version
*/
bool XkPublicFunction starts_insensitive(const String& original, const String& comparision);

/*! function. matches
    desc.
        Does the string match with another string?
*/
bool XkPublicFunction matches(const String& original, const String& comparision);

/*! function. matches_insensitive
    desc.
        Does the string match with another string? Case insensitive version
*/
bool XkPublicFunction matches_insensitive(const String& original, const String& comparision);


/*! function. join
    desc.
        joins up a string from a range of values.
*/
template<typename T> String join(T* begin, T* end, const std::string& delimiter = " ")
{
 StringStream stream;
 for (;begin != end; ++begin)
  stream << *begin << delimiter;
 std::string out = stream.str();
 return out.substr(0, out.length() - delimiter.length());
}


template<typename T> String join(const std::vector<T>& values, const std::string& seperator = " ")
{
 StringStream s;
 for (typename std::vector<T>::const_iterator it = values.begin(); it != values.end(); ++it)
  s << (*it) << seperator;
 std::string out = s.str();
 return out.substr(0, out.length() - seperator.length());
}

/*! function. cut
    desc.
        cuts up a string into two pieces, based on a delimeter. An additional delimiter may
        be used to mark as the ending of the string. Both strings are trimmed and cleaned.
*/
StringPair XkPublicFunction cut(const String& str, bool& did_cut, char delimiter = ':', char endDelimiter = '#');

/*! function. cut_many
    desc.
        cuts up each line in a string into two pieces, based on a delimeter. An additional delimiter may
        be used to mark as the ending of the string. Both strings are trimmed and cleaned.
*/
std::map<std::string, std::string> XkPublicFunction cut_many(const String& str, char delimiter = ':', char endDelimiter = '#');



/*! function. split
    desc.
        slices up the string based on a delimiters.
*/
std::vector<std::string> split(const String& str, const String& delimiters = " \t"); 

/*! function. split
    desc.
        slices up the string based on a delimiters.
*/
template<typename T> std::vector<T> split(const String& str, const String& delimiters = " \t")
{
 std::vector<T> out;
 size_t b = str.find_first_not_of(delimiters, 0);
 size_t a = str.find_first_of(delimiters, b);
 T t;
 while (a != String::npos || b != String::npos)
 {
  std::stringstream s(str.substr(b, a - b));
  s >> t;
  out.push_back(t);
  b = str.find_first_not_of(delimiters, a);
  a = str.find_first_of(delimiters, b);
 }

 return out;
}

/*! function. split
    desc.
        slices up the string based on a range.
*/
template<typename T> void split(const String& str, buffer<T>& buffer, const String& delimiters = " \t")
{

 size_t b = str.find_first_not_of(delimiters, 0);
 size_t a = str.find_first_of(delimiters, b);
 T t;
 while (a != String::npos || b != String::npos)
 {
  std::stringstream s(str.substr(b, a - b));
  s >> t;
  buffer.push_back(t);
  b = str.find_first_not_of(delimiters, a);
  a = str.find_first_of(delimiters, b);
 }

}

/*! function. split
    desc.
        Splits up a string intwo two and places them into a map.
        The first being the key and the second being the value.
    return.
        If the split was succesful or not.
*/
bool XkPublicFunction split(const String& str, std::map<String, String>&, char delimiter = ' ', bool lowerKey = true, bool trim = true);


/*! function. split
    desc.
        Splits up a string intwo two and places them into a map.
        The first being the key and the second being the value.
    return.
        If the split was succesful or not.
*/
bool XkPublicFunction split(const String& str, Xk::map<String, String>&, char delimiter = ' ', bool lowerKey = true, bool trim = true);
 
 /*! function. numWords
     desc.
          Get the number of words (blocks of non-whitespace text) in a string.
     note.
         This just counts the blocks of text seperated by whitespace, and not actual
         "words" in a sentence. Punctation and other characters are counted as words.
     example.
          Strings::numWords("one two three four") => 4
 */
 int numWords(const std::string& str);
 
 /*! function. isNull
     desc.
         Either the string is empty, or has four characters within it saying "null" in it.
 */
 bool isNull(const std::string& str);
 
 /*! function. isInteger
     desc.
         Is a string a base-10 integer?
 */
 bool XkPublicFunction isInteger(const std::string& str);
 
 /*! function. isReal
     desc.
         Is a string a base-10 real number?
 */
 bool XkPublicFunction isReal(const std::string& str);
 
 /*! function. isBoolean
    desc.
        Is a string a boolean
 */
 bool XkPublicFunction isBoolean(const std::string& str);



// void XkPublicFunction getLine(Xk::Resource* resource, Xk::buffer<char>& buffer);


} // namespace Strings

                                                                                       

} // namespace XK_NAMESPACE

                                                                                       

#endif
