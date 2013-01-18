
INCLUDE_DIRECTORIES(
		include
		../core/include
)

IF(WIN32)
ADD_DEFINITIONS(-DXK_DYNAMIC_LIBRARY)
SET(havoklib $ENV{HAVOK_SDK_HOME}/Lib/win32_vs2010/$(ConfigurationName)_multithreaded)
SET(havokinc $ENV{HAVOK_SDK_HOME}/Source)
LINK_DIRECTORIES(
	${havoklib}
	$ENV{PHYSX_SDK_HOME}/Lib/win32
	${PROJECT_BINARY_DIR}/lib
)

INCLUDE_DIRECTORIES(
	${havokinc}
)

ENDIF(WIN32)

AUX_SOURCE_DIRECTORY(./src SRC_LIST)

FILE(GLOB HDR_FILE_LIST "include/*.h")
FOREACH(myhdr ${HDR_FILE_LIST})
	LIST(APPEND INC_LIST ${myhdr})
ENDFOREACH()

LIST(APPEND SRC_LIST "${INC_LIST}")

ADD_LIBRARY(xkphysics SHARED ${SRC_LIST})

IF(WIN32)
TARGET_LINK_LIBRARIES(xkphysics
						hkBase.lib
						hkCompat.lib
						hkSceneData.lib
						hkSerialize.lib
						hkInternal.lib
						hkGeometryUtilities.lib
						hkVisualize.lib
						hkcdInternal.lib
						hkcdCollide.lib
						hkpCollide.lib
						hkpConstraintSolver.lib
						hkpDynamics.lib
						hkpInternal.lib
						hkpUtilities.lib
						hkpVehicle.lib
						PhysX3_x86.lib
						PhysX3CharacterKinematic_x86.lib
						PhysX3Common_x86.lib
						PhysX3Cooking_x86.lib
						PhysX3Extensions.lib
						PhysX3PROFILE_x86.lib
						PhysX3Vehicle.lib
						PhysXProfileSDK.lib
						PhysXVisualDebuggerSDK.lib
						PxTask.lib
						RepX3.lib
						RepXUpgrader3.lib
						xkcore.lib
)

ENDIF(WIN32)

SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
