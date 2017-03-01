#pragma once

#include "../C/CRuntimeEnvironment.h"
#include "../Scene/Component.h"

namespace Urho3D
{

class CComponent: public Component
{
	URHO3D_C_OBJECTBRIDGE(CComponent, Component, Urho3D_ComponentInterface)

public:

	CComponent(Context* context, const BridgeTypeInfo* bridgeTypeInfo):
		Component(context),
		bridgeTypeInfo_(bridgeTypeInfo)
    {
    }

protected:

    void OnNodeSet(Node* node)
    {
    	GetInterface().OnNodeSet(GetInstanceWrapper(), node);
    }

    void OnSceneSet(Scene* scene)
    {
    	GetInterface().OnSceneSet(GetInstanceWrapper(), scene);
    }

};

}
