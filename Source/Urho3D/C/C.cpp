#include "../Precompiled.h"

#include "../C/C.h"
#include "../C/CApplication.h"
#include "../C/CComponent.h"
#include "../Engine/Application.h"
#include "../IO/Log.h"
#include "../Scene/Scene.h"

using namespace Urho3D;

// environment

void Urho3D_SetRuntimeInterface(const Urho3D_RuntimeInterface* interface)
{
    CRuntimeEnvironment::SetInterface(*interface);
}

Urho3D_StringHash Urho3D_RegisterEventName(const char* name)
{
	return EventNameRegistrar::RegisterEventName(name).Value();
}

// Application

Urho3D_TypeInfo* Urho3D_Application_RegisterClass(const char* name, const Urho3D_ApplicationInterface* interface)
{
    return CApplication::CreateDerivedType(name, *interface);
}

Urho3D_Application* Urho3D_Application_New(Urho3D_Context* context, const Urho3D_TypeInfo* type)
{
    return new CApplication(context, reinterpret_cast<const CApplication::BridgeTypeInfo*>(type));
}

Urho3D_VariantMap* Urho3D_Application_GetEngineParameters(Urho3D_Application* self)
{
    return &reinterpret_cast<CApplication*>(self)->GetEngineParameters();
}

int Urho3D_Application_Run(Urho3D_Application* self)
{
    return self->Run();
}

// Component

Urho3D_TypeInfo* Urho3D_Component_RegisterClass(const char* name, const Urho3D_ComponentInterface* interface)
{
    return CComponent::CreateDerivedType(name, *interface);
}

Urho3D_Component* Urho3D_Component_New(Urho3D_Context* context, const Urho3D_TypeInfo* type)
{
    return new CComponent(context, reinterpret_cast<const CComponent::BridgeTypeInfo*>(type));
}

// Context

Urho3D_Context* Urho3D_Context_New()
{
    return new Context();
}

Urho3D_VariantMap* Urho3D_Context_GetEventDataMap(Urho3D_Context* self)
{
    return &self->GetEventDataMap();
}

Urho3D_Object* Urho3D_Context_GetSubsystem(Urho3D_Context* self, Urho3D_StringHash type)
{
	return self->GetSubsystem(StringHash(type));
}

// Log

void Urho3D_Log_Write(Urho3D_LogLevel level, const char* message)
{
	Log::Write(level, message);
}

// Object

Urho3D_Context* Urho3D_Object_GetContext(Urho3D_Object* self)
{
	return self->GetContext();
}

Urho3D_StringHash Urho3D_Object_GetType(Urho3D_Object* self)
{
    return self->GetType().ToHash();
}

const Urho3D_TypeInfo* Urho3D_Object_GetTypeInfo(Urho3D_Object* self)
{
    return self->GetTypeInfo();
}

void Urho3D_Object_SendEvent(Urho3D_Object* self, Urho3D_StringHash eventType, Urho3D_VariantMap* eventData)
{
    self->SendEvent(StringHash(eventType), *eventData);
}

void Urho3D_Object_SubscribeToEvent(Urho3D_Object* self, Urho3D_Object* sender, Urho3D_StringHash eventType, void* userData)
{
    self->SubscribeToEvent(
        sender, StringHash(eventType), new CEventHandler(self, userData)
    );
}

void Urho3D_Object_SubscribeToGlobalEvent(Urho3D_Object* self, Urho3D_StringHash eventType, void* userData)
{
    self->SubscribeToEvent(
        StringHash(eventType), new CEventHandler(self, userData)
    );
}

void Urho3D_Object_UnsubscribeFromEvent(Urho3D_Object* self, Urho3D_Object* sender, Urho3D_StringHash eventType)
{
	self->UnsubscribeFromEvent(
		sender, StringHash(eventType)
	);
}

void Urho3D_Object_UnsubscribeFromGlobalEvent(Urho3D_Object* self, Urho3D_Object* sender, Urho3D_StringHash eventType)
{
	self->UnsubscribeFromEvent(
		StringHash(eventType)
	);
}

// RefCounted

int Urho3D_RefCounted_Refs(Urho3D_RefCounted* self)
{
    return self->Refs();
}

int Urho3D_RefCounted_WeakRefs(Urho3D_RefCounted* self)
{
    return self->WeakRefs();
}

void Urho3D_RefCounted_AddRef(Urho3D_RefCounted* self)
{
    self->AddRef();
}

void Urho3D_RefCounted_ReleaseRef(Urho3D_RefCounted* self)
{
    self->ReleaseRef();
}

void* Urho3D_RefCounted_GetInstanceWrapper(Urho3D_RefCounted* self)
{
    return CRuntimeEnvironment::GetInstanceWrapper(self);
}

void Urho3D_RefCounted_SetInstanceWrapper(Urho3D_RefCounted* self, void* newValue)
{
    CRuntimeEnvironment::SetInstanceWrapper(self, newValue);
}

void Urho3D_RefCounted_Delete(Urho3D_RefCounted* self)
{
    delete self;
}

// StringHash

Urho3D_StringHash Urho3D_StringHash_Make(const char* name)
{
	return StringHash::Calculate(name);
}

// TypeInfo

Urho3D_StringHash Urho3D_TypeInfo_GetType(const Urho3D_TypeInfo* self)
{
    return self->GetType().ToHash();
}

const char* Urho3D_TypeInfo_GetTypeName(const Urho3D_TypeInfo* self)
{
    return self->GetTypeName().CString();
}

const Urho3D_TypeInfo* Urho3D_TypeInfo_GetBaseTypeInfo(const Urho3D_TypeInfo* self)
{
    return self->GetBaseTypeInfo();
}

// Variant

bool Urho3D_Variant_GetBool(const Urho3D_Variant* self)
{
	return self->GetBool();
}

float Urho3D_Variant_GetFloat(const Urho3D_Variant* self)
{
	return self->GetFloat();
}

int Urho3D_Variant_GetInt(const Urho3D_Variant* self)
{
	return self->GetInt();
}

Urho3D_RefCounted* Urho3D_Variant_GetRefCounted(const Urho3D_Variant* self)
{
	return self->GetPtr();
}

const char* Urho3D_Variant_GetString(const Urho3D_Variant* self)
{
	return self->GetString().CString();
}

void Urho3D_Variant_GetQuaternion(const Urho3D_Variant* self, Urho3D_Quaternion* value)
{
	*value = self->GetQuaternion();
}

void Urho3D_Variant_GetVector3(const Urho3D_Variant* self, Urho3D_Vector3* value)
{
	*value = self->GetVector3();
}

void Urho3D_Variant_SetBool(Urho3D_Variant* self, bool newValue)
{
	*self = newValue;
}

void Urho3D_Variant_SetFloat(Urho3D_Variant* self, float newValue)
{
	*self = newValue;
}

void Urho3D_Variant_SetInt(Urho3D_Variant* self, int newValue)
{
	*self = newValue;
}

void Urho3D_Variant_SetRefCounted(Urho3D_Variant* self, Urho3D_RefCounted* newValue)
{
	*self = newValue;
}

void Urho3D_Variant_SetString(Urho3D_Variant* self, const char* newValue)
{
	*self = newValue;
}

void Urho3D_Variant_SetQuaternion(Urho3D_Variant* self, const Urho3D_Quaternion* newValue)
{
	*self = *newValue;
}

void Urho3D_Variant_SetVector3(Urho3D_Variant* self, const Urho3D_Vector3* newValue)
{
	*self = *newValue;
}

// VariantMap

void Urho3D_VariantMap_Clear(Urho3D_VariantMap* self)
{
	self->Clear();
}

bool Urho3D_VariantMap_Contains(const Urho3D_VariantMap* self, Urho3D_StringHash key)
{
	return self->Contains(StringHash(key));
}

Urho3D_Variant* Urho3D_VariantMap_GetOrCreate(Urho3D_VariantMap* self, Urho3D_StringHash key)
{
	return &(*self)[StringHash(key)];
}

bool Urho3D_VariantMap_Erase(Urho3D_VariantMap* self, Urho3D_StringHash key)
{
	return self->Erase(StringHash(key));
}
