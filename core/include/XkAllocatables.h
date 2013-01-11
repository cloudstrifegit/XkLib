
#ifndef XK_ALLOCATABLES_H
#define XK_ALLOCATABLES_H

                                                                                       

#include "XkStable.h"
#include "XkAllocator.h"

#include "XkMallocAllocator.h"

                                                                                       

namespace Xk
{

                                                                                       

// Anything that doesn't fit in the other allocators.
typedef Allocator<MallocAllocator>                  GenericBasedAllocator;
typedef Allocatable<GenericBasedAllocator>          GenericBasedAllocatable;

// All PhysX classes and memory
typedef Allocator<MallocAllocator>                  PhysXClassAllocator;
typedef Allocatable<PhysXClassAllocator>            PhysXClassAllocatable;

// Worlds, Singletons and Scenes
typedef Allocator<MallocAllocator>                  BigClassAllocator;
typedef Allocatable<BigClassAllocator>              BigClassAllocatable;

// Archives, Resources, Meshes and HeightFields
typedef Allocator<MallocAllocator>                  ResourceAllocator;
typedef Allocatable<ResourceAllocator>              ResourceAllocatable;

// All Shapes.
typedef Allocator<MallocAllocator>                  ShapeAllocator;
typedef Allocatable<ShapeAllocator>                 ShapeAllocatable;

// RigidBodies and inherited classes.
typedef Allocator<MallocAllocator>                  RigidBodyBasedAllocator;
typedef Allocatable<RigidBodyBasedAllocator>        RigidBodyBasedAllocatable;

// Big RigidBody-like classes: Forcefields, SoftBodies, Cloths and Fluids
typedef Allocator<MallocAllocator>                  NonRigidBodyBasedAllocator;
typedef Allocatable<NonRigidBodyBasedAllocator>     NonRigidBodyBasedAllocatable;

// Joints
typedef Allocator<MallocAllocator>                  JointBasedAllocator;
typedef Allocatable<JointBasedAllocator>            JointBasedAllocatable;

// Classes that frequency create, resize or delete memory of fixed sizes, i.e. the Buffer.
typedef Allocator<MallocAllocator>                  FrequentOperationsAllocator;
typedef Allocatable<FrequentOperationsAllocator>    FrequentOperationsAllocatable;

// Classes/Memory that is exactly 16 bytes in size.
typedef Allocator<MallocAllocator>                  SixteenBytesAllocator;
typedef Allocatable<SixteenBytesAllocator>          SixteenBytesAllocatable;

// Classes/Memory that is exactly 4 bytes in size.
typedef Allocator<MallocAllocator>                  FourByteAllocator;
typedef Allocatable<FourByteAllocator>              FourByteAllocatable;

// STL classes, or classes that wrap them.
typedef Allocator<MallocAllocator>                  STLBasedAllocator;
typedef Allocatable<STLBasedAllocator>              STLBasedAllocatable;

// Classes outside of the Xk namespace may wish to inherit from this.
typedef Allocator<MallocAllocator>                  UserExtendedClassAllocator;
typedef Allocatable<UserExtendedClassAllocator>     UserExtendedClassAllocatable;

// Classes outside of the Xk namespace that manage Xk classes may want to use this.
typedef Allocator<MallocAllocator>                  UserBigClassAllocator;
typedef Allocatable<UserExtendedClassAllocator>     UserBigClassAllocatable;

// ForceFields and related/inherited classes.
typedef Allocator<MallocAllocator>                  ForceFieldBasedAllocator;
typedef Allocatable<RigidBodyBasedAllocator>        ForceFieldBasedAllocatable;


                                                                                       

} // namespace Xk

                                                                                       

#endif
