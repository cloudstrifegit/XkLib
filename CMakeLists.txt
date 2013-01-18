CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

IF(WIN32)
#foreach(flag_var
 #       CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
 #       CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
 #  if(${flag_var} MATCHES "/MD")
 #     string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
 #  endif(${flag_var} MATCHES "/MD")
#endforeach(flag_var)

ADD_DEFINITIONS(-DPOCO_STATIC)
INCLUDE_DIRECTORIES($ENV{SNH_HOME}/sdk/poco-1.4.5-all/include)
LINK_DIRECTORIES($ENV{SNH_HOME}/sdk/poco-1.4.5-all/lib)

ENDIF(WIN32)

PROJECT(XkLib)

ADD_SUBDIRECTORY(core lib)
ADD_SUBDIRECTORY(test)
ADD_SUBDIRECTORY(physics)