#ifndef URHO3D_C_H
#define URHO3D_C_H

#include "../C/Types.h"
#include "../Urho3D.h"

#ifdef __cplusplus
extern "C" {
#endif

/* environment */

void Urho3D_SetRuntimeInterface(const Urho3D_RuntimeInterface* interface) URHO3D_API;

Urho3D_StringHash Urho3D_RegisterEventName(const char* name) URHO3D_API;

/* Application */

Urho3D_TypeInfo* Urho3D_Application_RegisterClass(const char* name, const Urho3D_ApplicationInterface* interface) URHO3D_API;

Urho3D_Application* Urho3D_Application_New(Urho3D_Context* context, const Urho3D_TypeInfo* type) URHO3D_API;

Urho3D_VariantMap* Urho3D_Application_GetEngineParameters(Urho3D_Application* self) URHO3D_API;

int Urho3D_Application_Run(Urho3D_Application* self) URHO3D_API;

/* Component */

Urho3D_TypeInfo* Urho3D_Component_RegisterClass(const char* name, const Urho3D_ComponentInterface* interface) URHO3D_API;

Urho3D_Component* Urho3D_Component_New(Urho3D_Context* context, const Urho3D_TypeInfo* type) URHO3D_API;

/* Context */

Urho3D_Context* Urho3D_Context_New() URHO3D_API;

Urho3D_VariantMap* Urho3D_Context_GetEventDataMap(Urho3D_Context* self) URHO3D_API;

Urho3D_Object* Urho3D_Context_GetSubsystem(Urho3D_Context* self, Urho3D_StringHash type) URHO3D_API;

/* Log */

void Urho3D_Log_Write(Urho3D_LogLevel level, const char* message) URHO3D_API;

/* Object */

Urho3D_Context* Urho3D_Object_GetContext(Urho3D_Object* self) URHO3D_API;

Urho3D_StringHash Urho3D_Object_GetType(Urho3D_Object* self) URHO3D_API;

const Urho3D_TypeInfo* Urho3D_Object_GetTypeInfo(Urho3D_Object* self) URHO3D_API;

void Urho3D_Object_SendEvent(Urho3D_Object* self, Urho3D_StringHash eventType, Urho3D_VariantMap* eventData) URHO3D_API;

void Urho3D_Object_SubscribeToEvent(Urho3D_Object* self, Urho3D_Object* sender, Urho3D_StringHash eventType, void* userData) URHO3D_API;

void Urho3D_Object_SubscribeToGlobalEvent(Urho3D_Object* self, Urho3D_StringHash eventType, void* userData) URHO3D_API;

void Urho3D_Object_UnsubscribeFromEvent(Urho3D_Object* self, Urho3D_Object* sender, Urho3D_StringHash eventType) URHO3D_API;

void Urho3D_Object_UnsubscribeFromGlobalEvent(Urho3D_Object* self, Urho3D_Object* sender, Urho3D_StringHash eventType) URHO3D_API;

/* RefCounted */

int Urho3D_RefCounted_Refs(Urho3D_RefCounted* self) URHO3D_API;

int Urho3D_RefCounted_WeakRefs(Urho3D_RefCounted* self) URHO3D_API;

void Urho3D_RefCounted_AddRef(Urho3D_RefCounted* self) URHO3D_API;

void Urho3D_RefCounted_ReleaseRef(Urho3D_RefCounted* self) URHO3D_API;

void* Urho3D_RefCounted_GetInstanceWrapper(Urho3D_RefCounted* self) URHO3D_API;

void Urho3D_RefCounted_SetInstanceWrapper(Urho3D_RefCounted* self, void* newValue) URHO3D_API;

void Urho3D_RefCounted_Delete(Urho3D_RefCounted* self) URHO3D_API;

/* StringHash */

Urho3D_StringHash Urho3D_StringHash_Make(const char* name) URHO3D_API;

/* TypeInfo */

Urho3D_StringHash Urho3D_TypeInfo_GetType(const Urho3D_TypeInfo* self) URHO3D_API;

const char* Urho3D_TypeInfo_GetTypeName(const Urho3D_TypeInfo* self) URHO3D_API;

const Urho3D_TypeInfo* Urho3D_TypeInfo_GetBaseTypeInfo(const Urho3D_TypeInfo* self) URHO3D_API;

/* Variant */

bool Urho3D_Variant_GetBool(const Urho3D_Variant* self) URHO3D_API;

float Urho3D_Variant_GetFloat(const Urho3D_Variant* self) URHO3D_API;

int Urho3D_Variant_GetInt(const Urho3D_Variant* self) URHO3D_API;

Urho3D_RefCounted* Urho3D_Variant_GetRefCounted(const Urho3D_Variant* self) URHO3D_API;

const char* Urho3D_Variant_GetString(const Urho3D_Variant* self) URHO3D_API;

void Urho3D_Variant_GetQuaternion(const Urho3D_Variant* self, Urho3D_Quaternion* value) URHO3D_API;

void Urho3D_Variant_GetVector3(const Urho3D_Variant* self, Urho3D_Vector3* value) URHO3D_API;

void Urho3D_Variant_SetBool(Urho3D_Variant* self, bool newValue) URHO3D_API;

void Urho3D_Variant_SetFloat(Urho3D_Variant* self, float newValue) URHO3D_API;

void Urho3D_Variant_SetInt(Urho3D_Variant* self, int newValue) URHO3D_API;

void Urho3D_Variant_SetRefCounted(Urho3D_Variant* self, Urho3D_RefCounted* newValue) URHO3D_API;

void Urho3D_Variant_SetString(Urho3D_Variant* self, const char* newValue) URHO3D_API;

void Urho3D_Variant_SetQuaternion(Urho3D_Variant* self, const Urho3D_Quaternion* newValue) URHO3D_API;

void Urho3D_Variant_SetVector3(Urho3D_Variant* self, const Urho3D_Vector3* newValue) URHO3D_API;

/* VariantMap */

void Urho3D_VariantMap_Clear(Urho3D_VariantMap* self) URHO3D_API;

bool Urho3D_VariantMap_Contains(const Urho3D_VariantMap* self, Urho3D_StringHash key) URHO3D_API;

Urho3D_Variant* Urho3D_VariantMap_GetOrCreate(Urho3D_VariantMap* self, Urho3D_StringHash key) URHO3D_API;

bool Urho3D_VariantMap_Erase(Urho3D_VariantMap* self, Urho3D_StringHash key) URHO3D_API;

#include "Stubs.h"

#ifdef __cplusplus
}
#endif

#endif
