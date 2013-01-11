
#MESSAGE(CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
#MESSAGE(CMAKE_CURRENT_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})


IF(WIN32)
	ADD_DEFINITIONS(-DXK_STATIC_LIBRARY)
	
	SET(gtestinc $ENV{SNH_HOME}/sdk/gtest/include)
	
	LINK_DIRECTORIES(
		$ENV{SNH_HOME}/sdk/gtest/lib
)
	
ELSE(WIN32)
	SET(gtestinc /usr/local/include)
ENDIF(WIN32)

INCLUDE_DIRECTORIES(
	../core/include
	${gtestinc}
)

LINK_DIRECTORIES(
	${CMAKE_BINARY_DIR}/lib
)

SET(SRC_LIST 
	main.cpp
)


ADD_EXECUTABLE(xktest ${SRC_LIST})

IF(WIN32)
	TARGET_LINK_LIBRARIES(xktest gtest.lib gtest_main.lib xkcore.lib)
ELSE(WIN32)
	TARGET_LINK_LIBRARIES(xktest libgtest.a libgtest_main.a xkcore.a pthread dl)
ENDIF(WIN32)

INSTALL(TARGETS DESTINATION bin)
