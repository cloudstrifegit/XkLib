
IF(WIN32)
	SET(gtestinc $ENV{SNH_HOME}/sdk/gtest/include)
	
	LINK_DIRECTORIES(
		$ENV{SNH_HOME}/sdk/gtest/lib
	)
	
ELSE(WIN32)
	SET(gtestinc /usr/local/include)
ENDIF(WIN32)

INCLUDE_DIRECTORIES(
	../core/include
	../physics/include
	${gtestinc}
)

LINK_DIRECTORIES(
	${CMAKE_BINARY_DIR}/lib
)

SET(SRC_LIST 
    XkCoreTest.h
	XkPhysicsTest.h
	main.cpp
)


ADD_EXECUTABLE(xktest ${SRC_LIST})

IF(WIN32)
	TARGET_LINK_LIBRARIES(xktest gtest.lib gtest_main.lib xkcore.lib xkphysics.lib)
ELSE(WIN32)
	TARGET_LINK_LIBRARIES(xktest gtest gtest_main xkcore.a xkphysics.a pthread dl)
ENDIF(WIN32)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
