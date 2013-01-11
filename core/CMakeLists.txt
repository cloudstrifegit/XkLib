INCLUDE_DIRECTORIES(
		./include
)

IF(WIN32)
ADD_DEFINITIONS(-DXK_STATIC_LIBRARY)
ENDIF(WIN32)

SET(SRC_LIST src/XkAllocator.cpp
			 src/XkClasses.cpp
			 src/XkException.cpp
			 src/XkGC.cpp
			 src/XkMallocAllocator.cpp
			 src/XkMatrix.cpp
			 src/XkQuat.cpp
			 src/XkRadian.cpp
			 src/XkString.cpp
			 src/XkVec2.cpp
			 src/XkVec3.cpp
			 src/XkVec4.cpp
)

ADD_LIBRARY(xkcore ${SRC_LIST})
