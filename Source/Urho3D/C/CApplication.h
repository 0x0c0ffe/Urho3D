#pragma once

#include "../C/CRuntimeEnvironment.h"
#include "../Engine/Application.h"

namespace Urho3D
{

class CApplication: public Application
{
	URHO3D_C_OBJECTBRIDGE(CApplication, Application, Urho3D_ApplicationInterface)

public:

	CApplication(Context* context, const BridgeTypeInfo* bridgeTypeInfo):
		Application(context),
		bridgeTypeInfo_(bridgeTypeInfo)
    {
    }

	const VariantMap& GetEngineParameters() const
	{
		return engineParameters_;
	}

	VariantMap& GetEngineParameters()
	{
		return engineParameters_;
	}

	void Setup()
	{
		GetInterface().Setup(GetInstanceWrapper(), &engineParameters_);
	}

	void Start()
	{
		GetInterface().Start(GetInstanceWrapper());
	}

	void Stop()
	{
		GetInterface().Stop(GetInstanceWrapper());
	}

};

}
