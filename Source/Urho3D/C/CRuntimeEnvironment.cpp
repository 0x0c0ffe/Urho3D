#include "../Precompiled.h"

#include "../C/CRuntimeEnvironment.h"

namespace Urho3D
{

// CRuntimeInterface

Urho3D_RuntimeInterface CRuntimeEnvironment::interface_;

// CEventHandler

CEventHandler::~CEventHandler()
{
    CRuntimeEnvironment::GetInterface().DestroyEventHandler(
        CRuntimeEnvironment::GetInstanceWrapper(receiver_),
        userData_
    );
}

void CEventHandler::Invoke(Urho3D::VariantMap& eventData)
{
    CRuntimeEnvironment::GetInterface().EventFired(
        CRuntimeEnvironment::GetInstanceWrapper(receiver_),
        &eventData, userData_
    );
}

EventHandler* CEventHandler::Clone() const
{
    return new CEventHandler(receiver_, userData_);
}

}
