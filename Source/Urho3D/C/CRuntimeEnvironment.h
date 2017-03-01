#pragma once

#include "../C/Types.h"
#include "../Core/Object.h"

#define URHO3D_C_OBJECTBRIDGE(typeName, baseTypeName, interfaceType) \
    public: \
        typedef typeName ClassName; \
        typedef baseTypeName BaseClassName; \
        typedef interfaceType InterfaceType; \
        typedef CTypeInfo<interfaceType> BridgeTypeInfo; \
        Urho3D::StringHash GetType() const { return bridgeTypeInfo_->GetType(); } \
        virtual const Urho3D::String& GetTypeName() const { return bridgeTypeInfo_->GetTypeName(); } \
        virtual const Urho3D::TypeInfo* GetTypeInfo() const { return bridgeTypeInfo_; } \
        static Urho3D::StringHash GetTypeStatic() { return GetTypeInfoStatic()->GetType(); } \
        static const Urho3D::String& GetTypeNameStatic() { return GetTypeInfoStatic()->GetTypeName(); } \
        static const Urho3D::TypeInfo* GetTypeInfoStatic() { static const Urho3D::TypeInfo typeInfoStatic(#typeName, BaseClassName::GetTypeInfoStatic()); return &typeInfoStatic; } \
		const BridgeTypeInfo* GetBridgeTypeInfo() const { return bridgeTypeInfo_; } \
		void* GetInstanceWrapper() const { return CRuntimeEnvironment::GetInstanceWrapper(this); } \
		const InterfaceType& GetInterface() const { return bridgeTypeInfo_->GetInterface(); } \
		static BridgeTypeInfo* CreateDerivedType(const char* name, const InterfaceType& interface) { return new BridgeTypeInfo(name, GetTypeInfoStatic(), interface); } \
    protected: \
		const BridgeTypeInfo* bridgeTypeInfo_;

namespace Urho3D
{

/// Contains global variables used by the C API.
class CRuntimeEnvironment
{
public:

    static Urho3D_RuntimeInterface& GetInterface()
    {
        return interface_;
    }

    static void SetInterface(const Urho3D_RuntimeInterface& newValue)
    {
        interface_ = newValue;
    }

    static void* GetInstanceWrapper(const RefCounted* object)
    {
        return object->instanceWrapper_;
    }

    static void SetInstanceWrapper(RefCounted* object, void* newValue)
    {
        object->instanceWrapper_ = newValue;
    }

private:

    static Urho3D_RuntimeInterface interface_;

    CRuntimeEnvironment();

};

template<typename InterfaceType>
class CTypeInfo: public TypeInfo
{
public:

    CTypeInfo(const char* name, const TypeInfo* baseTypeInfo, const InterfaceType& interface):
        TypeInfo(name, baseTypeInfo),
        interface_(interface)
    {
    }

    const InterfaceType& GetInterface() const
    {
        return interface_;
    }

protected:

    InterfaceType interface_;
};

class CEventHandler: public EventHandler
{
public:

    CEventHandler(Object* receiver, void* userData = 0): EventHandler(receiver, userData)
    {
    }

    ~CEventHandler();

    void Invoke(VariantMap& eventData);

    EventHandler* Clone() const;

};

}
