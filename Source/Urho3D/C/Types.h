#ifndef URHO3D_C_TYPES_H
#define URHO3D_C_TYPES_H

#ifdef __cplusplus

#include "../Core/Variant.h"

typedef int Urho3D_LogLevel;

typedef Urho3D::Vector3 Urho3D_Vector3;
typedef Urho3D::IntVector2 Urho3D_IntVector2;
typedef Urho3D::Quaternion Urho3D_Quaternion;
typedef Urho3D::VariantMap Urho3D_VariantMap;

#define URHO3D_C_CLASS(name) namespace Urho3D { class name; } typedef Urho3D::name Urho3D_##name;

#else

#include <stdbool.h>

typedef enum
{
	URHO3D_LOGLEVEL_DEBUG = 0,
	URHO3D_LOGLEVEL_INFO = 1,
	URHO3D_LOGLEVEL_WARNING = 2,
	URHO3D_LOGLEVEL_ERROR = 3,
	URHO3D_LOGLEVEL_NONE = 4

} Urho3D_LogLevel;

typedef struct
{
    int x;
    int y;

} Urho3D_IntVector2;

typedef struct
{
    float w;
    float x;
    float y;
    float z;

} Urho3D_Quaternion;

typedef struct
{
    float x;
    float y;
    float z;

} Urho3D_Vector3;

struct Urho3D_Opaque_VariantMap;
typedef struct Urho3D_Opaque_VariantMap Urho3D_VariantMap;

#define URHO3D_C_CLASS(name) struct Urho3D_Opaque_##name; typedef struct Urho3D_Opaque_##name Urho3D_##name;

#endif

URHO3D_C_CLASS(Context)
URHO3D_C_CLASS(Object)
URHO3D_C_CLASS(RefCounted)
URHO3D_C_CLASS(TypeInfo)
URHO3D_C_CLASS(Variant)
URHO3D_C_CLASS(Application)

#include "../C/StubsTypes.h"

typedef unsigned Urho3D_StringHash;

typedef struct
{
    void (*Setup)(void*, Urho3D_VariantMap*);
    void (*Start)(void*);
    void (*Stop)(void*);

} Urho3D_ApplicationInterface;

typedef struct
{
    void (*OnNodeSet)(void*, Urho3D_Node*);
    void (*OnSceneSet)(void*, Urho3D_Scene*);

} Urho3D_ComponentInterface;

typedef struct
{
    /** Called when a RefCounted gets its first strong reference. */
    void (*RefCountedRetained)(void*);

    /** Called when a RefCounted is released from its last strong reference. */
    void (*RefCountedDropped)(void*);

    /** Called when an event is fired on an Object with a subscription created from the C API. */
    void (*EventFired)(void*, Urho3D_VariantMap*, void*);

    /** Called when an object is unsuscribed from an event (including when the object is being destroyed). */
    void (*DestroyEventHandler)(void*, void*);

} Urho3D_RuntimeInterface;

#endif
