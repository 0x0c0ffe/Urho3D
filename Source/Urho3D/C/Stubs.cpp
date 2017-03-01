#include "../Precompiled.h"
#include "../C/C.h"
#include "../Graphics/AnimationController.h"
#include "../Graphics/Camera.h"
#include "../Physics/CollisionShape.h"
#include "../Scene/Component.h"
#include "../Navigation/CrowdAgent.h"
#include "../Navigation/CrowdManager.h"
#include "../Graphics/DebugRenderer.h"
#include "../Navigation/DynamicNavigationMesh.h"
#include "../UI/Font.h"
#include "../Graphics/Graphics.h"
#include "../Resource/Image.h"
#include "../Input/Input.h"
#include "../Graphics/Light.h"
#include "../Graphics/Material.h"
#include "../Graphics/Model.h"
#include "../Navigation/Navigable.h"
#include "../Navigation/NavigationMesh.h"
#include "../Scene/Node.h"
#include "../Graphics/Octree.h"
#include "../Physics/PhysicsWorld.h"
#include "../Resource/ResourceCache.h"
#include "../Physics/RigidBody.h"
#include "../Scene/Scene.h"
#include "../Graphics/StaticModel.h"
#include "../UI/Text.h"
#include "../UI/UI.h"
#include "../UI/UIElement.h"
#include "../Graphics/Viewport.h"
#include "../Audio/AudioEvents.h"
#include "../Core/CoreEvents.h"
#include "../Engine/EngineEvents.h"
#ifdef URHO3D_DATABASE_ODBC
#include "../Database/DatabaseEvents.h"
#endif
#include "../Graphics/DrawableEvents.h"
#include "../Graphics/GraphicsEvents.h"
#include "../IO/IOEvents.h"
#include "../Input/InputEvents.h"
#include "../Navigation/NavigationEvents.h"
#include "../Network/NetworkEvents.h"
#include "../Physics/PhysicsEvents.h"
#include "../Resource/ResourceEvents.h"
#include "../Scene/SceneEvents.h"
#include "../UI/UIEvents.h"

using namespace Urho3D;

Urho3D_StringHash Urho3D_GetEventHash(Urho3D_Event symbol)
{
    switch (symbol) {
        case URHO3D_EVENT_SOUNDFINISHED: return E_SOUNDFINISHED.Value();
        case URHO3D_EVENT_SOUNDFINISHED_NODE: return SoundFinished::P_NODE.Value();
        case URHO3D_EVENT_SOUNDFINISHED_SOUNDSOURCE: return SoundFinished::P_SOUNDSOURCE.Value();
        case URHO3D_EVENT_SOUNDFINISHED_SOUND: return SoundFinished::P_SOUND.Value();
        case URHO3D_EVENT_BEGINFRAME: return E_BEGINFRAME.Value();
        case URHO3D_EVENT_BEGINFRAME_FRAMENUMBER: return BeginFrame::P_FRAMENUMBER.Value();
        case URHO3D_EVENT_BEGINFRAME_TIMESTEP: return BeginFrame::P_TIMESTEP.Value();
        case URHO3D_EVENT_UPDATE: return E_UPDATE.Value();
        case URHO3D_EVENT_UPDATE_TIMESTEP: return Update::P_TIMESTEP.Value();
        case URHO3D_EVENT_POSTUPDATE: return E_POSTUPDATE.Value();
        case URHO3D_EVENT_POSTUPDATE_TIMESTEP: return PostUpdate::P_TIMESTEP.Value();
        case URHO3D_EVENT_RENDERUPDATE: return E_RENDERUPDATE.Value();
        case URHO3D_EVENT_RENDERUPDATE_TIMESTEP: return RenderUpdate::P_TIMESTEP.Value();
        case URHO3D_EVENT_POSTRENDERUPDATE: return E_POSTRENDERUPDATE.Value();
        case URHO3D_EVENT_POSTRENDERUPDATE_TIMESTEP: return PostRenderUpdate::P_TIMESTEP.Value();
        case URHO3D_EVENT_ENDFRAME: return E_ENDFRAME.Value();
#ifdef URHO3D_DATABASE_ODBC
        case URHO3D_EVENT_DBCURSOR: return E_DBCURSOR.Value();
        case URHO3D_EVENT_DBCURSOR_DBCONNECTION: return DbCursor::P_DBCONNECTION.Value();
        case URHO3D_EVENT_DBCURSOR_RESULTIMPL: return DbCursor::P_RESULTIMPL.Value();
        case URHO3D_EVENT_DBCURSOR_SQL: return DbCursor::P_SQL.Value();
        case URHO3D_EVENT_DBCURSOR_NUMCOLS: return DbCursor::P_NUMCOLS.Value();
        case URHO3D_EVENT_DBCURSOR_COLVALUES: return DbCursor::P_COLVALUES.Value();
        case URHO3D_EVENT_DBCURSOR_COLHEADERS: return DbCursor::P_COLHEADERS.Value();
        case URHO3D_EVENT_DBCURSOR_FILTER: return DbCursor::P_FILTER.Value();
        case URHO3D_EVENT_DBCURSOR_ABORT: return DbCursor::P_ABORT.Value();
#endif
        case URHO3D_EVENT_CONSOLECOMMAND: return E_CONSOLECOMMAND.Value();
        case URHO3D_EVENT_CONSOLECOMMAND_COMMAND: return ConsoleCommand::P_COMMAND.Value();
        case URHO3D_EVENT_CONSOLECOMMAND_ID: return ConsoleCommand::P_ID.Value();
        case URHO3D_EVENT_BONEHIERARCHYCREATED: return E_BONEHIERARCHYCREATED.Value();
        case URHO3D_EVENT_BONEHIERARCHYCREATED_NODE: return BoneHierarchyCreated::P_NODE.Value();
        case URHO3D_EVENT_ANIMATIONTRIGGER: return E_ANIMATIONTRIGGER.Value();
        case URHO3D_EVENT_ANIMATIONTRIGGER_NODE: return AnimationTrigger::P_NODE.Value();
        case URHO3D_EVENT_ANIMATIONTRIGGER_ANIMATION: return AnimationTrigger::P_ANIMATION.Value();
        case URHO3D_EVENT_ANIMATIONTRIGGER_NAME: return AnimationTrigger::P_NAME.Value();
        case URHO3D_EVENT_ANIMATIONTRIGGER_TIME: return AnimationTrigger::P_TIME.Value();
        case URHO3D_EVENT_ANIMATIONTRIGGER_DATA: return AnimationTrigger::P_DATA.Value();
        case URHO3D_EVENT_ANIMATIONFINISHED: return E_ANIMATIONFINISHED.Value();
        case URHO3D_EVENT_ANIMATIONFINISHED_NODE: return AnimationFinished::P_NODE.Value();
        case URHO3D_EVENT_ANIMATIONFINISHED_ANIMATION: return AnimationFinished::P_ANIMATION.Value();
        case URHO3D_EVENT_ANIMATIONFINISHED_NAME: return AnimationFinished::P_NAME.Value();
        case URHO3D_EVENT_ANIMATIONFINISHED_LOOPED: return AnimationFinished::P_LOOPED.Value();
        case URHO3D_EVENT_PARTICLEEFFECTFINISHED: return E_PARTICLEEFFECTFINISHED.Value();
        case URHO3D_EVENT_PARTICLEEFFECTFINISHED_NODE: return ParticleEffectFinished::P_NODE.Value();
        case URHO3D_EVENT_PARTICLEEFFECTFINISHED_EFFECT: return ParticleEffectFinished::P_EFFECT.Value();
        case URHO3D_EVENT_TERRAINCREATED: return E_TERRAINCREATED.Value();
        case URHO3D_EVENT_TERRAINCREATED_NODE: return TerrainCreated::P_NODE.Value();
        case URHO3D_EVENT_SCREENMODE: return E_SCREENMODE.Value();
        case URHO3D_EVENT_SCREENMODE_WIDTH: return ScreenMode::P_WIDTH.Value();
        case URHO3D_EVENT_SCREENMODE_HEIGHT: return ScreenMode::P_HEIGHT.Value();
        case URHO3D_EVENT_SCREENMODE_FULLSCREEN: return ScreenMode::P_FULLSCREEN.Value();
        case URHO3D_EVENT_SCREENMODE_BORDERLESS: return ScreenMode::P_BORDERLESS.Value();
        case URHO3D_EVENT_SCREENMODE_RESIZABLE: return ScreenMode::P_RESIZABLE.Value();
        case URHO3D_EVENT_SCREENMODE_HIGHDPI: return ScreenMode::P_HIGHDPI.Value();
        case URHO3D_EVENT_WINDOWPOS: return E_WINDOWPOS.Value();
        case URHO3D_EVENT_WINDOWPOS_X: return WindowPos::P_X.Value();
        case URHO3D_EVENT_WINDOWPOS_Y: return WindowPos::P_Y.Value();
        case URHO3D_EVENT_RENDERSURFACEUPDATE: return E_RENDERSURFACEUPDATE.Value();
        case URHO3D_EVENT_BEGINRENDERING: return E_BEGINRENDERING.Value();
        case URHO3D_EVENT_ENDRENDERING: return E_ENDRENDERING.Value();
        case URHO3D_EVENT_BEGINVIEWUPDATE: return E_BEGINVIEWUPDATE.Value();
        case URHO3D_EVENT_BEGINVIEWUPDATE_VIEW: return BeginViewUpdate::P_VIEW.Value();
        case URHO3D_EVENT_BEGINVIEWUPDATE_TEXTURE: return BeginViewUpdate::P_TEXTURE.Value();
        case URHO3D_EVENT_BEGINVIEWUPDATE_SURFACE: return BeginViewUpdate::P_SURFACE.Value();
        case URHO3D_EVENT_BEGINVIEWUPDATE_SCENE: return BeginViewUpdate::P_SCENE.Value();
        case URHO3D_EVENT_BEGINVIEWUPDATE_CAMERA: return BeginViewUpdate::P_CAMERA.Value();
        case URHO3D_EVENT_ENDVIEWUPDATE: return E_ENDVIEWUPDATE.Value();
        case URHO3D_EVENT_ENDVIEWUPDATE_VIEW: return EndViewUpdate::P_VIEW.Value();
        case URHO3D_EVENT_ENDVIEWUPDATE_TEXTURE: return EndViewUpdate::P_TEXTURE.Value();
        case URHO3D_EVENT_ENDVIEWUPDATE_SURFACE: return EndViewUpdate::P_SURFACE.Value();
        case URHO3D_EVENT_ENDVIEWUPDATE_SCENE: return EndViewUpdate::P_SCENE.Value();
        case URHO3D_EVENT_ENDVIEWUPDATE_CAMERA: return EndViewUpdate::P_CAMERA.Value();
        case URHO3D_EVENT_BEGINVIEWRENDER: return E_BEGINVIEWRENDER.Value();
        case URHO3D_EVENT_BEGINVIEWRENDER_VIEW: return BeginViewRender::P_VIEW.Value();
        case URHO3D_EVENT_BEGINVIEWRENDER_TEXTURE: return BeginViewRender::P_TEXTURE.Value();
        case URHO3D_EVENT_BEGINVIEWRENDER_SURFACE: return BeginViewRender::P_SURFACE.Value();
        case URHO3D_EVENT_BEGINVIEWRENDER_SCENE: return BeginViewRender::P_SCENE.Value();
        case URHO3D_EVENT_BEGINVIEWRENDER_CAMERA: return BeginViewRender::P_CAMERA.Value();
        case URHO3D_EVENT_ENDVIEWRENDER: return E_ENDVIEWRENDER.Value();
        case URHO3D_EVENT_ENDVIEWRENDER_VIEW: return EndViewRender::P_VIEW.Value();
        case URHO3D_EVENT_ENDVIEWRENDER_TEXTURE: return EndViewRender::P_TEXTURE.Value();
        case URHO3D_EVENT_ENDVIEWRENDER_SURFACE: return EndViewRender::P_SURFACE.Value();
        case URHO3D_EVENT_ENDVIEWRENDER_SCENE: return EndViewRender::P_SCENE.Value();
        case URHO3D_EVENT_ENDVIEWRENDER_CAMERA: return EndViewRender::P_CAMERA.Value();
        case URHO3D_EVENT_RENDERPATHEVENT: return E_RENDERPATHEVENT.Value();
        case URHO3D_EVENT_RENDERPATHEVENT_NAME: return RenderPathEvent::P_NAME.Value();
        case URHO3D_EVENT_DEVICELOST: return E_DEVICELOST.Value();
        case URHO3D_EVENT_DEVICERESET: return E_DEVICERESET.Value();
        case URHO3D_EVENT_LOGMESSAGE: return E_LOGMESSAGE.Value();
        case URHO3D_EVENT_LOGMESSAGE_MESSAGE: return LogMessage::P_MESSAGE.Value();
        case URHO3D_EVENT_LOGMESSAGE_LEVEL: return LogMessage::P_LEVEL.Value();
        case URHO3D_EVENT_ASYNCEXECFINISHED: return E_ASYNCEXECFINISHED.Value();
        case URHO3D_EVENT_ASYNCEXECFINISHED_REQUESTID: return AsyncExecFinished::P_REQUESTID.Value();
        case URHO3D_EVENT_ASYNCEXECFINISHED_EXITCODE: return AsyncExecFinished::P_EXITCODE.Value();
        case URHO3D_EVENT_MOUSEBUTTONDOWN: return E_MOUSEBUTTONDOWN.Value();
        case URHO3D_EVENT_MOUSEBUTTONDOWN_BUTTON: return MouseButtonDown::P_BUTTON.Value();
        case URHO3D_EVENT_MOUSEBUTTONDOWN_BUTTONS: return MouseButtonDown::P_BUTTONS.Value();
        case URHO3D_EVENT_MOUSEBUTTONDOWN_QUALIFIERS: return MouseButtonDown::P_QUALIFIERS.Value();
        case URHO3D_EVENT_MOUSEBUTTONUP: return E_MOUSEBUTTONUP.Value();
        case URHO3D_EVENT_MOUSEBUTTONUP_BUTTON: return MouseButtonUp::P_BUTTON.Value();
        case URHO3D_EVENT_MOUSEBUTTONUP_BUTTONS: return MouseButtonUp::P_BUTTONS.Value();
        case URHO3D_EVENT_MOUSEBUTTONUP_QUALIFIERS: return MouseButtonUp::P_QUALIFIERS.Value();
        case URHO3D_EVENT_MOUSEMOVE: return E_MOUSEMOVE.Value();
        case URHO3D_EVENT_MOUSEMOVE_X: return MouseMove::P_X.Value();
        case URHO3D_EVENT_MOUSEMOVE_Y: return MouseMove::P_Y.Value();
        case URHO3D_EVENT_MOUSEMOVE_DX: return MouseMove::P_DX.Value();
        case URHO3D_EVENT_MOUSEMOVE_DY: return MouseMove::P_DY.Value();
        case URHO3D_EVENT_MOUSEMOVE_BUTTONS: return MouseMove::P_BUTTONS.Value();
        case URHO3D_EVENT_MOUSEMOVE_QUALIFIERS: return MouseMove::P_QUALIFIERS.Value();
        case URHO3D_EVENT_MOUSEWHEEL: return E_MOUSEWHEEL.Value();
        case URHO3D_EVENT_MOUSEWHEEL_WHEEL: return MouseWheel::P_WHEEL.Value();
        case URHO3D_EVENT_MOUSEWHEEL_BUTTONS: return MouseWheel::P_BUTTONS.Value();
        case URHO3D_EVENT_MOUSEWHEEL_QUALIFIERS: return MouseWheel::P_QUALIFIERS.Value();
        case URHO3D_EVENT_KEYDOWN: return E_KEYDOWN.Value();
        case URHO3D_EVENT_KEYDOWN_KEY: return KeyDown::P_KEY.Value();
        case URHO3D_EVENT_KEYDOWN_SCANCODE: return KeyDown::P_SCANCODE.Value();
        case URHO3D_EVENT_KEYDOWN_BUTTONS: return KeyDown::P_BUTTONS.Value();
        case URHO3D_EVENT_KEYDOWN_QUALIFIERS: return KeyDown::P_QUALIFIERS.Value();
        case URHO3D_EVENT_KEYDOWN_REPEAT: return KeyDown::P_REPEAT.Value();
        case URHO3D_EVENT_KEYUP: return E_KEYUP.Value();
        case URHO3D_EVENT_KEYUP_KEY: return KeyUp::P_KEY.Value();
        case URHO3D_EVENT_KEYUP_SCANCODE: return KeyUp::P_SCANCODE.Value();
        case URHO3D_EVENT_KEYUP_BUTTONS: return KeyUp::P_BUTTONS.Value();
        case URHO3D_EVENT_KEYUP_QUALIFIERS: return KeyUp::P_QUALIFIERS.Value();
        case URHO3D_EVENT_TEXTINPUT: return E_TEXTINPUT.Value();
        case URHO3D_EVENT_TEXTINPUT_TEXT: return TextInput::P_TEXT.Value();
        case URHO3D_EVENT_TEXTINPUT_BUTTONS: return TextInput::P_BUTTONS.Value();
        case URHO3D_EVENT_TEXTINPUT_QUALIFIERS: return TextInput::P_QUALIFIERS.Value();
        case URHO3D_EVENT_JOYSTICKCONNECTED: return E_JOYSTICKCONNECTED.Value();
        case URHO3D_EVENT_JOYSTICKCONNECTED_JOYSTICKID: return JoystickConnected::P_JOYSTICKID.Value();
        case URHO3D_EVENT_JOYSTICKDISCONNECTED: return E_JOYSTICKDISCONNECTED.Value();
        case URHO3D_EVENT_JOYSTICKDISCONNECTED_JOYSTICKID: return JoystickDisconnected::P_JOYSTICKID.Value();
        case URHO3D_EVENT_JOYSTICKBUTTONDOWN: return E_JOYSTICKBUTTONDOWN.Value();
        case URHO3D_EVENT_JOYSTICKBUTTONDOWN_JOYSTICKID: return JoystickButtonDown::P_JOYSTICKID.Value();
        case URHO3D_EVENT_JOYSTICKBUTTONDOWN_BUTTON: return JoystickButtonDown::P_BUTTON.Value();
        case URHO3D_EVENT_JOYSTICKBUTTONUP: return E_JOYSTICKBUTTONUP.Value();
        case URHO3D_EVENT_JOYSTICKBUTTONUP_JOYSTICKID: return JoystickButtonUp::P_JOYSTICKID.Value();
        case URHO3D_EVENT_JOYSTICKBUTTONUP_BUTTON: return JoystickButtonUp::P_BUTTON.Value();
        case URHO3D_EVENT_JOYSTICKAXISMOVE: return E_JOYSTICKAXISMOVE.Value();
        case URHO3D_EVENT_JOYSTICKAXISMOVE_JOYSTICKID: return JoystickAxisMove::P_JOYSTICKID.Value();
        case URHO3D_EVENT_JOYSTICKAXISMOVE_BUTTON: return JoystickAxisMove::P_AXIS.Value();
        case URHO3D_EVENT_JOYSTICKAXISMOVE_POSITION: return JoystickAxisMove::P_POSITION.Value();
        case URHO3D_EVENT_JOYSTICKHATMOVE: return E_JOYSTICKHATMOVE.Value();
        case URHO3D_EVENT_JOYSTICKHATMOVE_JOYSTICKID: return JoystickHatMove::P_JOYSTICKID.Value();
        case URHO3D_EVENT_JOYSTICKHATMOVE_BUTTON: return JoystickHatMove::P_HAT.Value();
        case URHO3D_EVENT_JOYSTICKHATMOVE_POSITION: return JoystickHatMove::P_POSITION.Value();
        case URHO3D_EVENT_TOUCHBEGIN: return E_TOUCHBEGIN.Value();
        case URHO3D_EVENT_TOUCHBEGIN_TOUCHID: return TouchBegin::P_TOUCHID.Value();
        case URHO3D_EVENT_TOUCHBEGIN_X: return TouchBegin::P_X.Value();
        case URHO3D_EVENT_TOUCHBEGIN_Y: return TouchBegin::P_Y.Value();
        case URHO3D_EVENT_TOUCHBEGIN_PRESSURE: return TouchBegin::P_PRESSURE.Value();
        case URHO3D_EVENT_TOUCHEND: return E_TOUCHEND.Value();
        case URHO3D_EVENT_TOUCHEND_TOUCHID: return TouchEnd::P_TOUCHID.Value();
        case URHO3D_EVENT_TOUCHEND_X: return TouchEnd::P_X.Value();
        case URHO3D_EVENT_TOUCHEND_Y: return TouchEnd::P_Y.Value();
        case URHO3D_EVENT_TOUCHMOVE: return E_TOUCHMOVE.Value();
        case URHO3D_EVENT_TOUCHMOVE_TOUCHID: return TouchMove::P_TOUCHID.Value();
        case URHO3D_EVENT_TOUCHMOVE_X: return TouchMove::P_X.Value();
        case URHO3D_EVENT_TOUCHMOVE_Y: return TouchMove::P_Y.Value();
        case URHO3D_EVENT_TOUCHMOVE_DX: return TouchMove::P_DX.Value();
        case URHO3D_EVENT_TOUCHMOVE_DY: return TouchMove::P_DY.Value();
        case URHO3D_EVENT_TOUCHMOVE_PRESSURE: return TouchMove::P_PRESSURE.Value();
        case URHO3D_EVENT_GESTURERECORDED: return E_GESTURERECORDED.Value();
        case URHO3D_EVENT_GESTURERECORDED_GESTUREID: return GestureRecorded::P_GESTUREID.Value();
        case URHO3D_EVENT_GESTUREINPUT: return E_GESTUREINPUT.Value();
        case URHO3D_EVENT_GESTUREINPUT_GESTUREID: return GestureInput::P_GESTUREID.Value();
        case URHO3D_EVENT_GESTUREINPUT_CENTERX: return GestureInput::P_CENTERX.Value();
        case URHO3D_EVENT_GESTUREINPUT_CENTERY: return GestureInput::P_CENTERY.Value();
        case URHO3D_EVENT_GESTUREINPUT_NUMFINGERS: return GestureInput::P_NUMFINGERS.Value();
        case URHO3D_EVENT_GESTUREINPUT_ERROR: return GestureInput::P_ERROR.Value();
        case URHO3D_EVENT_MULTIGESTURE: return E_MULTIGESTURE.Value();
        case URHO3D_EVENT_MULTIGESTURE_CENTERX: return MultiGesture::P_CENTERX.Value();
        case URHO3D_EVENT_MULTIGESTURE_CENTERY: return MultiGesture::P_CENTERY.Value();
        case URHO3D_EVENT_MULTIGESTURE_NUMFINGERS: return MultiGesture::P_NUMFINGERS.Value();
        case URHO3D_EVENT_MULTIGESTURE_DTHETA: return MultiGesture::P_DTHETA.Value();
        case URHO3D_EVENT_MULTIGESTURE_DDIST: return MultiGesture::P_DDIST.Value();
        case URHO3D_EVENT_DROPFILE: return E_DROPFILE.Value();
        case URHO3D_EVENT_DROPFILE_FILENAME: return DropFile::P_FILENAME.Value();
        case URHO3D_EVENT_INPUTFOCUS: return E_INPUTFOCUS.Value();
        case URHO3D_EVENT_INPUTFOCUS_FOCUS: return InputFocus::P_FOCUS.Value();
        case URHO3D_EVENT_INPUTFOCUS_MINIMIZED: return InputFocus::P_MINIMIZED.Value();
        case URHO3D_EVENT_MOUSEVISIBLECHANGED: return E_MOUSEVISIBLECHANGED.Value();
        case URHO3D_EVENT_MOUSEVISIBLECHANGED_VISIBLE: return MouseVisibleChanged::P_VISIBLE.Value();
        case URHO3D_EVENT_MOUSEMODECHANGED: return E_MOUSEMODECHANGED.Value();
        case URHO3D_EVENT_MOUSEMODECHANGED_MODE: return MouseModeChanged::P_MODE.Value();
        case URHO3D_EVENT_MOUSEMODECHANGED_MOUSELOCKED: return MouseModeChanged::P_MOUSELOCKED.Value();
        case URHO3D_EVENT_EXITREQUESTED: return E_EXITREQUESTED.Value();
        case URHO3D_EVENT_SDLRAWINPUT: return E_SDLRAWINPUT.Value();
        case URHO3D_EVENT_SDLRAWINPUT_SDLEVENT: return SDLRawInput::P_SDLEVENT.Value();
        case URHO3D_EVENT_SDLRAWINPUT_CONSUMED: return SDLRawInput::P_CONSUMED.Value();
        case URHO3D_EVENT_INPUTBEGIN: return E_INPUTBEGIN.Value();
        case URHO3D_EVENT_INPUTEND: return E_INPUTEND.Value();
        case URHO3D_EVENT_NAVIGATIONMESHREBUILT: return E_NAVIGATION_MESH_REBUILT.Value();
        case URHO3D_EVENT_NAVIGATIONMESHREBUILT_NODE: return NavigationMeshRebuilt::P_NODE.Value();
        case URHO3D_EVENT_NAVIGATIONMESHREBUILT_MESH: return NavigationMeshRebuilt::P_MESH.Value();
        case URHO3D_EVENT_NAVIGATIONAREAREBUILT: return E_NAVIGATION_AREA_REBUILT.Value();
        case URHO3D_EVENT_NAVIGATIONAREAREBUILT_NODE: return NavigationAreaRebuilt::P_NODE.Value();
        case URHO3D_EVENT_NAVIGATIONAREAREBUILT_MESH: return NavigationAreaRebuilt::P_MESH.Value();
        case URHO3D_EVENT_NAVIGATIONAREAREBUILT_BOUNDSMIN: return NavigationAreaRebuilt::P_BOUNDSMIN.Value();
        case URHO3D_EVENT_NAVIGATIONAREAREBUILT_BOUNDSMAX: return NavigationAreaRebuilt::P_BOUNDSMAX.Value();
        case URHO3D_EVENT_CROWDAGENTFORMATION: return E_CROWD_AGENT_FORMATION.Value();
        case URHO3D_EVENT_CROWDAGENTFORMATION_NODE: return CrowdAgentFormation::P_NODE.Value();
        case URHO3D_EVENT_CROWDAGENTFORMATION_CROWDAGENT: return CrowdAgentFormation::P_CROWD_AGENT.Value();
        case URHO3D_EVENT_CROWDAGENTFORMATION_INDEX: return CrowdAgentFormation::P_INDEX.Value();
        case URHO3D_EVENT_CROWDAGENTFORMATION_SIZE: return CrowdAgentFormation::P_SIZE.Value();
        case URHO3D_EVENT_CROWDAGENTFORMATION_POSITION: return CrowdAgentFormation::P_POSITION.Value();
        case URHO3D_EVENT_CROWDAGENTNODEFORMATION: return E_CROWD_AGENT_NODE_FORMATION.Value();
        case URHO3D_EVENT_CROWDAGENTNODEFORMATION_NODE: return CrowdAgentNodeFormation::P_NODE.Value();
        case URHO3D_EVENT_CROWDAGENTNODEFORMATION_CROWDAGENT: return CrowdAgentNodeFormation::P_CROWD_AGENT.Value();
        case URHO3D_EVENT_CROWDAGENTNODEFORMATION_INDEX: return CrowdAgentNodeFormation::P_INDEX.Value();
        case URHO3D_EVENT_CROWDAGENTNODEFORMATION_SIZE: return CrowdAgentNodeFormation::P_SIZE.Value();
        case URHO3D_EVENT_CROWDAGENTNODEFORMATION_POSITION: return CrowdAgentNodeFormation::P_POSITION.Value();
        case URHO3D_EVENT_CROWDAGENTREPOSITION: return E_CROWD_AGENT_REPOSITION.Value();
        case URHO3D_EVENT_CROWDAGENTREPOSITION_NODE: return CrowdAgentReposition::P_NODE.Value();
        case URHO3D_EVENT_CROWDAGENTREPOSITION_CROWDAGENT: return CrowdAgentReposition::P_CROWD_AGENT.Value();
        case URHO3D_EVENT_CROWDAGENTREPOSITION_POSITION: return CrowdAgentReposition::P_POSITION.Value();
        case URHO3D_EVENT_CROWDAGENTREPOSITION_VELOCITY: return CrowdAgentReposition::P_VELOCITY.Value();
        case URHO3D_EVENT_CROWDAGENTREPOSITION_ARRIVED: return CrowdAgentReposition::P_ARRIVED.Value();
        case URHO3D_EVENT_CROWDAGENTREPOSITION_TIMESTEP: return CrowdAgentReposition::P_TIMESTEP.Value();
        case URHO3D_EVENT_CROWDAGENTNODEREPOSITION: return E_CROWD_AGENT_NODE_REPOSITION.Value();
        case URHO3D_EVENT_CROWDAGENTNODEREPOSITION_NODE: return CrowdAgentNodeReposition::P_NODE.Value();
        case URHO3D_EVENT_CROWDAGENTNODEREPOSITION_CROWDAGENT: return CrowdAgentNodeReposition::P_CROWD_AGENT.Value();
        case URHO3D_EVENT_CROWDAGENTNODEREPOSITION_POSITION: return CrowdAgentNodeReposition::P_POSITION.Value();
        case URHO3D_EVENT_CROWDAGENTNODEREPOSITION_VELOCITY: return CrowdAgentNodeReposition::P_VELOCITY.Value();
        case URHO3D_EVENT_CROWDAGENTNODEREPOSITION_ARRIVED: return CrowdAgentNodeReposition::P_ARRIVED.Value();
        case URHO3D_EVENT_CROWDAGENTNODEREPOSITION_TIMESTEP: return CrowdAgentNodeReposition::P_TIMESTEP.Value();
        case URHO3D_EVENT_CROWDAGENTFAILURE: return E_CROWD_AGENT_FAILURE.Value();
        case URHO3D_EVENT_CROWDAGENTFAILURE_NODE: return CrowdAgentFailure::P_NODE.Value();
        case URHO3D_EVENT_CROWDAGENTFAILURE_CROWDAGENT: return CrowdAgentFailure::P_CROWD_AGENT.Value();
        case URHO3D_EVENT_CROWDAGENTFAILURE_POSITION: return CrowdAgentFailure::P_POSITION.Value();
        case URHO3D_EVENT_CROWDAGENTFAILURE_VELOCITY: return CrowdAgentFailure::P_VELOCITY.Value();
        case URHO3D_EVENT_CROWDAGENTFAILURE_CROWDAGENTSTATE: return CrowdAgentFailure::P_CROWD_AGENT_STATE.Value();
        case URHO3D_EVENT_CROWDAGENTFAILURE_CROWDTARGETSTATE: return CrowdAgentFailure::P_CROWD_TARGET_STATE.Value();
        case URHO3D_EVENT_CROWDAGENTNODEFAILURE: return E_CROWD_AGENT_NODE_FAILURE.Value();
        case URHO3D_EVENT_CROWDAGENTNODEFAILURE_NODE: return CrowdAgentNodeFailure::P_NODE.Value();
        case URHO3D_EVENT_CROWDAGENTNODEFAILURE_CROWDAGENT: return CrowdAgentNodeFailure::P_CROWD_AGENT.Value();
        case URHO3D_EVENT_CROWDAGENTNODEFAILURE_POSITION: return CrowdAgentNodeFailure::P_POSITION.Value();
        case URHO3D_EVENT_CROWDAGENTNODEFAILURE_VELOCITY: return CrowdAgentNodeFailure::P_VELOCITY.Value();
        case URHO3D_EVENT_CROWDAGENTNODEFAILURE_CROWDAGENTSTATE: return CrowdAgentNodeFailure::P_CROWD_AGENT_STATE.Value();
        case URHO3D_EVENT_CROWDAGENTNODEFAILURE_CROWDTARGETSTATE: return CrowdAgentNodeFailure::P_CROWD_TARGET_STATE.Value();
        case URHO3D_EVENT_CROWDAGENTSTATECHANGED: return E_CROWD_AGENT_STATE_CHANGED.Value();
        case URHO3D_EVENT_CROWDAGENTSTATECHANGED_NODE: return CrowdAgentStateChanged::P_NODE.Value();
        case URHO3D_EVENT_CROWDAGENTSTATECHANGED_CROWDAGENT: return CrowdAgentStateChanged::P_CROWD_AGENT.Value();
        case URHO3D_EVENT_CROWDAGENTSTATECHANGED_POSITION: return CrowdAgentStateChanged::P_POSITION.Value();
        case URHO3D_EVENT_CROWDAGENTSTATECHANGED_VELOCITY: return CrowdAgentStateChanged::P_VELOCITY.Value();
        case URHO3D_EVENT_CROWDAGENTSTATECHANGED_CROWDAGENTSTATE: return CrowdAgentStateChanged::P_CROWD_AGENT_STATE.Value();
        case URHO3D_EVENT_CROWDAGENTSTATECHANGED_CROWDTARGETSTATE: return CrowdAgentStateChanged::P_CROWD_TARGET_STATE.Value();
        case URHO3D_EVENT_CROWDAGENTNODESTATECHANGED: return E_CROWD_AGENT_NODE_STATE_CHANGED.Value();
        case URHO3D_EVENT_CROWDAGENTNODESTATECHANGED_NODE: return CrowdAgentNodeStateChanged::P_NODE.Value();
        case URHO3D_EVENT_CROWDAGENTNODESTATECHANGED_CROWDAGENT: return CrowdAgentNodeStateChanged::P_CROWD_AGENT.Value();
        case URHO3D_EVENT_CROWDAGENTNODESTATECHANGED_POSITION: return CrowdAgentNodeStateChanged::P_POSITION.Value();
        case URHO3D_EVENT_CROWDAGENTNODESTATECHANGED_VELOCITY: return CrowdAgentNodeStateChanged::P_VELOCITY.Value();
        case URHO3D_EVENT_CROWDAGENTNODESTATECHANGED_CROWDAGENTSTATE: return CrowdAgentNodeStateChanged::P_CROWD_AGENT_STATE.Value();
        case URHO3D_EVENT_CROWDAGENTNODESTATECHANGED_CROWDTARGETSTATE: return CrowdAgentNodeStateChanged::P_CROWD_TARGET_STATE.Value();
        case URHO3D_EVENT_NAVIGATIONOBSTACLEADDED: return E_NAVIGATION_OBSTACLE_ADDED.Value();
        case URHO3D_EVENT_NAVIGATIONOBSTACLEADDED_NODE: return NavigationObstacleAdded::P_NODE.Value();
        case URHO3D_EVENT_NAVIGATIONOBSTACLEADDED_OBSTACLE: return NavigationObstacleAdded::P_OBSTACLE.Value();
        case URHO3D_EVENT_NAVIGATIONOBSTACLEADDED_POSITION: return NavigationObstacleAdded::P_POSITION.Value();
        case URHO3D_EVENT_NAVIGATIONOBSTACLEADDED_RADIUS: return NavigationObstacleAdded::P_RADIUS.Value();
        case URHO3D_EVENT_NAVIGATIONOBSTACLEADDED_HEIGHT: return NavigationObstacleAdded::P_HEIGHT.Value();
        case URHO3D_EVENT_NAVIGATIONOBSTACLEREMOVED: return E_NAVIGATION_OBSTACLE_REMOVED.Value();
        case URHO3D_EVENT_NAVIGATIONOBSTACLEREMOVED_NODE: return NavigationObstacleRemoved::P_NODE.Value();
        case URHO3D_EVENT_NAVIGATIONOBSTACLEREMOVED_OBSTACLE: return NavigationObstacleRemoved::P_OBSTACLE.Value();
        case URHO3D_EVENT_NAVIGATIONOBSTACLEREMOVED_POSITION: return NavigationObstacleRemoved::P_POSITION.Value();
        case URHO3D_EVENT_NAVIGATIONOBSTACLEREMOVED_RADIUS: return NavigationObstacleRemoved::P_RADIUS.Value();
        case URHO3D_EVENT_NAVIGATIONOBSTACLEREMOVED_HEIGHT: return NavigationObstacleRemoved::P_HEIGHT.Value();
        case URHO3D_EVENT_SERVERCONNECTED: return E_SERVERCONNECTED.Value();
        case URHO3D_EVENT_SERVERDISCONNECTED: return E_SERVERDISCONNECTED.Value();
        case URHO3D_EVENT_CONNECTFAILED: return E_CONNECTFAILED.Value();
        case URHO3D_EVENT_CLIENTCONNECTED: return E_CLIENTCONNECTED.Value();
        case URHO3D_EVENT_CLIENTCONNECTED_CONNECTION: return ClientConnected::P_CONNECTION.Value();
        case URHO3D_EVENT_CLIENTDISCONNECTED: return E_CLIENTDISCONNECTED.Value();
        case URHO3D_EVENT_CLIENTDISCONNECTED_CONNECTION: return ClientDisconnected::P_CONNECTION.Value();
        case URHO3D_EVENT_CLIENTIDENTITY: return E_CLIENTIDENTITY.Value();
        case URHO3D_EVENT_CLIENTIDENTITY_CONNECTION: return ClientIdentity::P_CONNECTION.Value();
        case URHO3D_EVENT_CLIENTIDENTITY_ALLOW: return ClientIdentity::P_ALLOW.Value();
        case URHO3D_EVENT_CLIENTSCENELOADED: return E_CLIENTSCENELOADED.Value();
        case URHO3D_EVENT_CLIENTSCENELOADED_CONNECTION: return ClientSceneLoaded::P_CONNECTION.Value();
        case URHO3D_EVENT_NETWORKMESSAGE: return E_NETWORKMESSAGE.Value();
        case URHO3D_EVENT_NETWORKMESSAGE_CONNECTION: return NetworkMessage::P_CONNECTION.Value();
        case URHO3D_EVENT_NETWORKMESSAGE_MESSAGEID: return NetworkMessage::P_MESSAGEID.Value();
        case URHO3D_EVENT_NETWORKMESSAGE_DATA: return NetworkMessage::P_DATA.Value();
        case URHO3D_EVENT_NETWORKUPDATE: return E_NETWORKUPDATE.Value();
        case URHO3D_EVENT_NETWORKUPDATESENT: return E_NETWORKUPDATESENT.Value();
        case URHO3D_EVENT_NETWORKSCENELOADFAILED: return E_NETWORKSCENELOADFAILED.Value();
        case URHO3D_EVENT_NETWORKSCENELOADFAILED_CONNECTION: return NetworkSceneLoadFailed::P_CONNECTION.Value();
        case URHO3D_EVENT_REMOTEEVENTDATA: return E_REMOTEEVENTDATA.Value();
        case URHO3D_EVENT_REMOTEEVENTDATA_CONNECTION: return RemoteEventData::P_CONNECTION.Value();
        case URHO3D_EVENT_PHYSICSPRESTEP: return E_PHYSICSPRESTEP.Value();
        case URHO3D_EVENT_PHYSICSPRESTEP_WORLD: return PhysicsPreStep::P_WORLD.Value();
        case URHO3D_EVENT_PHYSICSPRESTEP_TIMESTEP: return PhysicsPreStep::P_TIMESTEP.Value();
        case URHO3D_EVENT_PHYSICSPOSTSTEP: return E_PHYSICSPOSTSTEP.Value();
        case URHO3D_EVENT_PHYSICSPOSTSTEP_WORLD: return PhysicsPostStep::P_WORLD.Value();
        case URHO3D_EVENT_PHYSICSPOSTSTEP_TIMESTEP: return PhysicsPostStep::P_TIMESTEP.Value();
        case URHO3D_EVENT_PHYSICSCOLLISIONSTART: return E_PHYSICSCOLLISIONSTART.Value();
        case URHO3D_EVENT_PHYSICSCOLLISIONSTART_WORLD: return PhysicsCollisionStart::P_WORLD.Value();
        case URHO3D_EVENT_PHYSICSCOLLISIONSTART_NODEA: return PhysicsCollisionStart::P_NODEA.Value();
        case URHO3D_EVENT_PHYSICSCOLLISIONSTART_NODEB: return PhysicsCollisionStart::P_NODEB.Value();
        case URHO3D_EVENT_PHYSICSCOLLISIONSTART_BODYA: return PhysicsCollisionStart::P_BODYA.Value();
        case URHO3D_EVENT_PHYSICSCOLLISIONSTART_BODYB: return PhysicsCollisionStart::P_BODYB.Value();
        case URHO3D_EVENT_PHYSICSCOLLISIONSTART_TRIGGER: return PhysicsCollisionStart::P_TRIGGER.Value();
        case URHO3D_EVENT_PHYSICSCOLLISIONSTART_CONTACTS: return PhysicsCollisionStart::P_CONTACTS.Value();
        case URHO3D_EVENT_PHYSICSCOLLISION: return E_PHYSICSCOLLISION.Value();
        case URHO3D_EVENT_PHYSICSCOLLISION_WORLD: return PhysicsCollision::P_WORLD.Value();
        case URHO3D_EVENT_PHYSICSCOLLISION_NODEA: return PhysicsCollision::P_NODEA.Value();
        case URHO3D_EVENT_PHYSICSCOLLISION_NODEB: return PhysicsCollision::P_NODEB.Value();
        case URHO3D_EVENT_PHYSICSCOLLISION_BODYA: return PhysicsCollision::P_BODYA.Value();
        case URHO3D_EVENT_PHYSICSCOLLISION_BODYB: return PhysicsCollision::P_BODYB.Value();
        case URHO3D_EVENT_PHYSICSCOLLISION_TRIGGER: return PhysicsCollision::P_TRIGGER.Value();
        case URHO3D_EVENT_PHYSICSCOLLISION_CONTACTS: return PhysicsCollision::P_CONTACTS.Value();
        case URHO3D_EVENT_PHYSICSCOLLISIONEND: return E_PHYSICSCOLLISIONEND.Value();
        case URHO3D_EVENT_PHYSICSCOLLISIONEND_WORLD: return PhysicsCollisionEnd::P_WORLD.Value();
        case URHO3D_EVENT_PHYSICSCOLLISIONEND_NODEA: return PhysicsCollisionEnd::P_NODEA.Value();
        case URHO3D_EVENT_PHYSICSCOLLISIONEND_NODEB: return PhysicsCollisionEnd::P_NODEB.Value();
        case URHO3D_EVENT_PHYSICSCOLLISIONEND_BODYA: return PhysicsCollisionEnd::P_BODYA.Value();
        case URHO3D_EVENT_PHYSICSCOLLISIONEND_BODYB: return PhysicsCollisionEnd::P_BODYB.Value();
        case URHO3D_EVENT_PHYSICSCOLLISIONEND_TRIGGER: return PhysicsCollisionEnd::P_TRIGGER.Value();
        case URHO3D_EVENT_NODECOLLISIONSTART: return E_NODECOLLISIONSTART.Value();
        case URHO3D_EVENT_NODECOLLISIONSTART_BODY: return NodeCollisionStart::P_BODY.Value();
        case URHO3D_EVENT_NODECOLLISIONSTART_OTHERNODE: return NodeCollisionStart::P_OTHERNODE.Value();
        case URHO3D_EVENT_NODECOLLISIONSTART_OTHERBODY: return NodeCollisionStart::P_OTHERBODY.Value();
        case URHO3D_EVENT_NODECOLLISIONSTART_TRIGGER: return NodeCollisionStart::P_TRIGGER.Value();
        case URHO3D_EVENT_NODECOLLISIONSTART_CONTACTS: return NodeCollisionStart::P_CONTACTS.Value();
        case URHO3D_EVENT_NODECOLLISION: return E_NODECOLLISION.Value();
        case URHO3D_EVENT_NODECOLLISION_BODY: return NodeCollision::P_BODY.Value();
        case URHO3D_EVENT_NODECOLLISION_OTHERNODE: return NodeCollision::P_OTHERNODE.Value();
        case URHO3D_EVENT_NODECOLLISION_OTHERBODY: return NodeCollision::P_OTHERBODY.Value();
        case URHO3D_EVENT_NODECOLLISION_TRIGGER: return NodeCollision::P_TRIGGER.Value();
        case URHO3D_EVENT_NODECOLLISION_CONTACTS: return NodeCollision::P_CONTACTS.Value();
        case URHO3D_EVENT_NODECOLLISIONEND: return E_NODECOLLISIONEND.Value();
        case URHO3D_EVENT_NODECOLLISIONEND_BODY: return NodeCollisionEnd::P_BODY.Value();
        case URHO3D_EVENT_NODECOLLISIONEND_OTHERNODE: return NodeCollisionEnd::P_OTHERNODE.Value();
        case URHO3D_EVENT_NODECOLLISIONEND_OTHERBODY: return NodeCollisionEnd::P_OTHERBODY.Value();
        case URHO3D_EVENT_NODECOLLISIONEND_TRIGGER: return NodeCollisionEnd::P_TRIGGER.Value();
        case URHO3D_EVENT_RELOADSTARTED: return E_RELOADSTARTED.Value();
        case URHO3D_EVENT_RELOADFINISHED: return E_RELOADFINISHED.Value();
        case URHO3D_EVENT_RELOADFAILED: return E_RELOADFAILED.Value();
        case URHO3D_EVENT_FILECHANGED: return E_FILECHANGED.Value();
        case URHO3D_EVENT_FILECHANGED_FILENAME: return FileChanged::P_FILENAME.Value();
        case URHO3D_EVENT_FILECHANGED_RESOURCENAME: return FileChanged::P_RESOURCENAME.Value();
        case URHO3D_EVENT_LOADFAILED: return E_LOADFAILED.Value();
        case URHO3D_EVENT_LOADFAILED_RESOURCENAME: return LoadFailed::P_RESOURCENAME.Value();
        case URHO3D_EVENT_RESOURCENOTFOUND: return E_RESOURCENOTFOUND.Value();
        case URHO3D_EVENT_RESOURCENOTFOUND_RESOURCENAME: return ResourceNotFound::P_RESOURCENAME.Value();
        case URHO3D_EVENT_UNKNOWNRESOURCETYPE: return E_UNKNOWNRESOURCETYPE.Value();
        case URHO3D_EVENT_UNKNOWNRESOURCETYPE_RESOURCETYPE: return UnknownResourceType::P_RESOURCETYPE.Value();
        case URHO3D_EVENT_RESOURCEBACKGROUNDLOADED: return E_RESOURCEBACKGROUNDLOADED.Value();
        case URHO3D_EVENT_RESOURCEBACKGROUNDLOADED_RESOURCENAME: return ResourceBackgroundLoaded::P_RESOURCENAME.Value();
        case URHO3D_EVENT_RESOURCEBACKGROUNDLOADED_SUCCESS: return ResourceBackgroundLoaded::P_SUCCESS.Value();
        case URHO3D_EVENT_RESOURCEBACKGROUNDLOADED_RESOURCE: return ResourceBackgroundLoaded::P_RESOURCE.Value();
        case URHO3D_EVENT_CHANGELANGUAGE: return E_CHANGELANGUAGE.Value();
        case URHO3D_EVENT_SCENEUPDATE: return E_SCENEUPDATE.Value();
        case URHO3D_EVENT_SCENEUPDATE_SCENE: return SceneUpdate::P_SCENE.Value();
        case URHO3D_EVENT_SCENEUPDATE_TIMESTEP: return SceneUpdate::P_TIMESTEP.Value();
        case URHO3D_EVENT_SCENESUBSYSTEMUPDATE: return E_SCENESUBSYSTEMUPDATE.Value();
        case URHO3D_EVENT_SCENESUBSYSTEMUPDATE_SCENE: return SceneSubsystemUpdate::P_SCENE.Value();
        case URHO3D_EVENT_SCENESUBSYSTEMUPDATE_TIMESTEP: return SceneSubsystemUpdate::P_TIMESTEP.Value();
        case URHO3D_EVENT_UPDATESMOOTHING: return E_UPDATESMOOTHING.Value();
        case URHO3D_EVENT_UPDATESMOOTHING_CONSTANT: return UpdateSmoothing::P_CONSTANT.Value();
        case URHO3D_EVENT_UPDATESMOOTHING_SQUAREDSNAPTHRESHOLD: return UpdateSmoothing::P_SQUAREDSNAPTHRESHOLD.Value();
        case URHO3D_EVENT_SCENEDRAWABLEUPDATEFINISHED: return E_SCENEDRAWABLEUPDATEFINISHED.Value();
        case URHO3D_EVENT_SCENEDRAWABLEUPDATEFINISHED_SCENE: return SceneDrawableUpdateFinished::P_SCENE.Value();
        case URHO3D_EVENT_SCENEDRAWABLEUPDATEFINISHED_TIMESTEP: return SceneDrawableUpdateFinished::P_TIMESTEP.Value();
        case URHO3D_EVENT_TARGETPOSITIONCHANGED: return E_TARGETPOSITION.Value();
        case URHO3D_EVENT_TARGETROTATIONCHANGED: return E_TARGETROTATION.Value();
        case URHO3D_EVENT_ATTRIBUTEANIMATIONUPDATE: return E_ATTRIBUTEANIMATIONUPDATE.Value();
        case URHO3D_EVENT_ATTRIBUTEANIMATIONUPDATE_SCENE: return AttributeAnimationUpdate::P_SCENE.Value();
        case URHO3D_EVENT_ATTRIBUTEANIMATIONUPDATE_TIMESTEP: return AttributeAnimationUpdate::P_TIMESTEP.Value();
        case URHO3D_EVENT_ATTRIBUTEANIMATIONADDED: return E_ATTRIBUTEANIMATIONADDED.Value();
        case URHO3D_EVENT_ATTRIBUTEANIMATIONADDED_OBJECTANIMATION: return AttributeAnimationAdded::P_OBJECTANIMATION.Value();
        case URHO3D_EVENT_ATTRIBUTEANIMATIONADDED_ATTRIBUTEANIMATIONNAME: return AttributeAnimationAdded::P_ATTRIBUTEANIMATIONNAME.Value();
        case URHO3D_EVENT_ATTRIBUTEANIMATIONREMOVED: return E_ATTRIBUTEANIMATIONREMOVED.Value();
        case URHO3D_EVENT_ATTRIBUTEANIMATIONREMOVED_OBJECTANIMATION: return AttributeAnimationRemoved::P_OBJECTANIMATION.Value();
        case URHO3D_EVENT_ATTRIBUTEANIMATIONREMOVED_ATTRIBUTEANIMATIONNAME: return AttributeAnimationRemoved::P_ATTRIBUTEANIMATIONNAME.Value();
        case URHO3D_EVENT_SCENEPOSTUPDATE: return E_SCENEPOSTUPDATE.Value();
        case URHO3D_EVENT_SCENEPOSTUPDATE_SCENE: return ScenePostUpdate::P_SCENE.Value();
        case URHO3D_EVENT_SCENEPOSTUPDATE_TIMESTEP: return ScenePostUpdate::P_TIMESTEP.Value();
        case URHO3D_EVENT_ASYNCLOADPROGRESS: return E_ASYNCLOADPROGRESS.Value();
        case URHO3D_EVENT_ASYNCLOADPROGRESS_SCENE: return AsyncLoadProgress::P_SCENE.Value();
        case URHO3D_EVENT_ASYNCLOADPROGRESS_PROGRESS: return AsyncLoadProgress::P_PROGRESS.Value();
        case URHO3D_EVENT_ASYNCLOADPROGRESS_LOADEDNODES: return AsyncLoadProgress::P_LOADEDNODES.Value();
        case URHO3D_EVENT_ASYNCLOADPROGRESS_TOTALNODES: return AsyncLoadProgress::P_TOTALNODES.Value();
        case URHO3D_EVENT_ASYNCLOADPROGRESS_LOADEDRESOURCES: return AsyncLoadProgress::P_LOADEDRESOURCES.Value();
        case URHO3D_EVENT_ASYNCLOADPROGRESS_TOTALRESOURCES: return AsyncLoadProgress::P_TOTALRESOURCES.Value();
        case URHO3D_EVENT_ASYNCLOADFINISHED: return E_ASYNCLOADFINISHED.Value();
        case URHO3D_EVENT_ASYNCLOADFINISHED_SCENE: return AsyncLoadFinished::P_SCENE.Value();
        case URHO3D_EVENT_NODEADDED: return E_NODEADDED.Value();
        case URHO3D_EVENT_NODEADDED_SCENE: return NodeAdded::P_SCENE.Value();
        case URHO3D_EVENT_NODEADDED_PARENT: return NodeAdded::P_PARENT.Value();
        case URHO3D_EVENT_NODEADDED_NODE: return NodeAdded::P_NODE.Value();
        case URHO3D_EVENT_NODEREMOVED: return E_NODEREMOVED.Value();
        case URHO3D_EVENT_NODEREMOVED_SCENE: return NodeRemoved::P_SCENE.Value();
        case URHO3D_EVENT_NODEREMOVED_PARENT: return NodeRemoved::P_PARENT.Value();
        case URHO3D_EVENT_NODEREMOVED_NODE: return NodeRemoved::P_NODE.Value();
        case URHO3D_EVENT_COMPONENTADDED: return E_COMPONENTADDED.Value();
        case URHO3D_EVENT_COMPONENTADDED_SCENE: return ComponentAdded::P_SCENE.Value();
        case URHO3D_EVENT_COMPONENTADDED_NODE: return ComponentAdded::P_NODE.Value();
        case URHO3D_EVENT_COMPONENTADDED_COMPONENT: return ComponentAdded::P_COMPONENT.Value();
        case URHO3D_EVENT_COMPONENTREMOVED: return E_COMPONENTREMOVED.Value();
        case URHO3D_EVENT_COMPONENTREMOVED_SCENE: return ComponentRemoved::P_SCENE.Value();
        case URHO3D_EVENT_COMPONENTREMOVED_NODE: return ComponentRemoved::P_NODE.Value();
        case URHO3D_EVENT_COMPONENTREMOVED_COMPONENT: return ComponentRemoved::P_COMPONENT.Value();
        case URHO3D_EVENT_NODENAMECHANGED: return E_NODENAMECHANGED.Value();
        case URHO3D_EVENT_NODENAMECHANGED_SCENE: return NodeNameChanged::P_SCENE.Value();
        case URHO3D_EVENT_NODENAMECHANGED_NODE: return NodeNameChanged::P_NODE.Value();
        case URHO3D_EVENT_NODEENABLEDCHANGED: return E_NODEENABLEDCHANGED.Value();
        case URHO3D_EVENT_NODEENABLEDCHANGED_SCENE: return NodeEnabledChanged::P_SCENE.Value();
        case URHO3D_EVENT_NODEENABLEDCHANGED_NODE: return NodeEnabledChanged::P_NODE.Value();
        case URHO3D_EVENT_NODETAGADDED: return E_NODETAGADDED.Value();
        case URHO3D_EVENT_NODETAGADDED_SCENE: return NodeTagAdded::P_SCENE.Value();
        case URHO3D_EVENT_NODETAGADDED_NODE: return NodeTagAdded::P_NODE.Value();
        case URHO3D_EVENT_NODETAGADDED_TAG: return NodeTagAdded::P_TAG.Value();
        case URHO3D_EVENT_NODETAGREMOVED: return E_NODETAGREMOVED.Value();
        case URHO3D_EVENT_NODETAGREMOVED_SCENE: return NodeTagRemoved::P_SCENE.Value();
        case URHO3D_EVENT_NODETAGREMOVED_NODE: return NodeTagRemoved::P_NODE.Value();
        case URHO3D_EVENT_NODETAGREMOVED_TAG: return NodeTagRemoved::P_TAG.Value();
        case URHO3D_EVENT_COMPONENTENABLEDCHANGED: return E_COMPONENTENABLEDCHANGED.Value();
        case URHO3D_EVENT_COMPONENTENABLEDCHANGED_SCENE: return ComponentEnabledChanged::P_SCENE.Value();
        case URHO3D_EVENT_COMPONENTENABLEDCHANGED_NODE: return ComponentEnabledChanged::P_NODE.Value();
        case URHO3D_EVENT_COMPONENTENABLEDCHANGED_COMPONENT: return ComponentEnabledChanged::P_COMPONENT.Value();
        case URHO3D_EVENT_TEMPORARYCHANGED: return E_TEMPORARYCHANGED.Value();
        case URHO3D_EVENT_TEMPORARYCHANGED_SERIALIZABLE: return TemporaryChanged::P_SERIALIZABLE.Value();
        case URHO3D_EVENT_NODECLONED: return E_NODECLONED.Value();
        case URHO3D_EVENT_NODECLONED_SCENE: return NodeCloned::P_SCENE.Value();
        case URHO3D_EVENT_NODECLONED_NODE: return NodeCloned::P_NODE.Value();
        case URHO3D_EVENT_NODECLONED_CLONENODE: return NodeCloned::P_CLONENODE.Value();
        case URHO3D_EVENT_COMPONENTCLONED: return E_COMPONENTCLONED.Value();
        case URHO3D_EVENT_COMPONENTCLONED_SCENE: return ComponentCloned::P_SCENE.Value();
        case URHO3D_EVENT_COMPONENTCLONED_COMPONENT: return ComponentCloned::P_COMPONENT.Value();
        case URHO3D_EVENT_COMPONENTCLONED_CLONECOMPONENT: return ComponentCloned::P_CLONECOMPONENT.Value();
        case URHO3D_EVENT_INTERCEPTNETWORKUPDATE: return E_INTERCEPTNETWORKUPDATE.Value();
        case URHO3D_EVENT_INTERCEPTNETWORKUPDATE_SERIALIZABLE: return InterceptNetworkUpdate::P_SERIALIZABLE.Value();
        case URHO3D_EVENT_INTERCEPTNETWORKUPDATE_TIMESTAMP: return InterceptNetworkUpdate::P_TIMESTAMP.Value();
        case URHO3D_EVENT_INTERCEPTNETWORKUPDATE_INDEX: return InterceptNetworkUpdate::P_INDEX.Value();
        case URHO3D_EVENT_INTERCEPTNETWORKUPDATE_NAME: return InterceptNetworkUpdate::P_NAME.Value();
        case URHO3D_EVENT_INTERCEPTNETWORKUPDATE_VALUE: return InterceptNetworkUpdate::P_VALUE.Value();
        case URHO3D_EVENT_UIMOUSECLICK: return E_UIMOUSECLICK.Value();
        case URHO3D_EVENT_UIMOUSECLICK_ELEMENT: return UIMouseClick::P_ELEMENT.Value();
        case URHO3D_EVENT_UIMOUSECLICK_X: return UIMouseClick::P_X.Value();
        case URHO3D_EVENT_UIMOUSECLICK_Y: return UIMouseClick::P_Y.Value();
        case URHO3D_EVENT_UIMOUSECLICK_BUTTON: return UIMouseClick::P_BUTTON.Value();
        case URHO3D_EVENT_UIMOUSECLICK_BUTTONS: return UIMouseClick::P_BUTTONS.Value();
        case URHO3D_EVENT_UIMOUSECLICK_QUALIFIERS: return UIMouseClick::P_QUALIFIERS.Value();
        case URHO3D_EVENT_UIMOUSECLICKEND: return E_UIMOUSECLICKEND.Value();
        case URHO3D_EVENT_UIMOUSECLICKEND_ELEMENT: return UIMouseClickEnd::P_ELEMENT.Value();
        case URHO3D_EVENT_UIMOUSECLICKEND_BEGINELEMENT: return UIMouseClickEnd::P_BEGINELEMENT.Value();
        case URHO3D_EVENT_UIMOUSECLICKEND_X: return UIMouseClickEnd::P_X.Value();
        case URHO3D_EVENT_UIMOUSECLICKEND_Y: return UIMouseClickEnd::P_Y.Value();
        case URHO3D_EVENT_UIMOUSECLICKEND_BUTTON: return UIMouseClickEnd::P_BUTTON.Value();
        case URHO3D_EVENT_UIMOUSECLICKEND_BUTTONS: return UIMouseClickEnd::P_BUTTONS.Value();
        case URHO3D_EVENT_UIMOUSECLICKEND_QUALIFIERS: return UIMouseClickEnd::P_QUALIFIERS.Value();
        case URHO3D_EVENT_UIMOUSEDOUBLECLICK: return E_UIMOUSEDOUBLECLICK.Value();
        case URHO3D_EVENT_UIMOUSEDOUBLECLICK_ELEMENT: return UIMouseDoubleClick::P_ELEMENT.Value();
        case URHO3D_EVENT_UIMOUSEDOUBLECLICK_X: return UIMouseDoubleClick::P_X.Value();
        case URHO3D_EVENT_UIMOUSEDOUBLECLICK_Y: return UIMouseDoubleClick::P_Y.Value();
        case URHO3D_EVENT_UIMOUSEDOUBLECLICK_BUTTON: return UIMouseDoubleClick::P_BUTTON.Value();
        case URHO3D_EVENT_UIMOUSEDOUBLECLICK_BUTTONS: return UIMouseDoubleClick::P_BUTTONS.Value();
        case URHO3D_EVENT_UIMOUSEDOUBLECLICK_QUALIFIERS: return UIMouseDoubleClick::P_QUALIFIERS.Value();
        case URHO3D_EVENT_CLICK: return E_CLICK.Value();
        case URHO3D_EVENT_CLICK_ELEMENT: return Click::P_ELEMENT.Value();
        case URHO3D_EVENT_CLICK_X: return Click::P_X.Value();
        case URHO3D_EVENT_CLICK_Y: return Click::P_Y.Value();
        case URHO3D_EVENT_CLICK_BUTTON: return Click::P_BUTTON.Value();
        case URHO3D_EVENT_CLICK_BUTTONS: return Click::P_BUTTONS.Value();
        case URHO3D_EVENT_CLICK_QUALIFIERS: return Click::P_QUALIFIERS.Value();
        case URHO3D_EVENT_CLICKEND: return E_CLICKEND.Value();
        case URHO3D_EVENT_CLICKEND_ELEMENT: return ClickEnd::P_ELEMENT.Value();
        case URHO3D_EVENT_CLICKEND_BEGINELEMENT: return ClickEnd::P_BEGINELEMENT.Value();
        case URHO3D_EVENT_CLICKEND_X: return ClickEnd::P_X.Value();
        case URHO3D_EVENT_CLICKEND_Y: return ClickEnd::P_Y.Value();
        case URHO3D_EVENT_CLICKEND_BUTTON: return ClickEnd::P_BUTTON.Value();
        case URHO3D_EVENT_CLICKEND_BUTTONS: return ClickEnd::P_BUTTONS.Value();
        case URHO3D_EVENT_CLICKEND_QUALIFIERS: return ClickEnd::P_QUALIFIERS.Value();
        case URHO3D_EVENT_DOUBLECLICK: return E_DOUBLECLICK.Value();
        case URHO3D_EVENT_DOUBLECLICK_ELEMENT: return DoubleClick::P_ELEMENT.Value();
        case URHO3D_EVENT_DOUBLECLICK_X: return DoubleClick::P_X.Value();
        case URHO3D_EVENT_DOUBLECLICK_Y: return DoubleClick::P_Y.Value();
        case URHO3D_EVENT_DOUBLECLICK_BUTTON: return DoubleClick::P_BUTTON.Value();
        case URHO3D_EVENT_DOUBLECLICK_BUTTONS: return DoubleClick::P_BUTTONS.Value();
        case URHO3D_EVENT_DOUBLECLICK_QUALIFIERS: return DoubleClick::P_QUALIFIERS.Value();
        case URHO3D_EVENT_DRAGDROPTEST: return E_DRAGDROPTEST.Value();
        case URHO3D_EVENT_DRAGDROPTEST_SOURCE: return DragDropTest::P_SOURCE.Value();
        case URHO3D_EVENT_DRAGDROPTEST_TARGET: return DragDropTest::P_TARGET.Value();
        case URHO3D_EVENT_DRAGDROPTEST_ACCEPT: return DragDropTest::P_ACCEPT.Value();
        case URHO3D_EVENT_DRAGDROPFINISH: return E_DRAGDROPFINISH.Value();
        case URHO3D_EVENT_DRAGDROPFINISH_SOURCE: return DragDropFinish::P_SOURCE.Value();
        case URHO3D_EVENT_DRAGDROPFINISH_TARGET: return DragDropFinish::P_TARGET.Value();
        case URHO3D_EVENT_DRAGDROPFINISH_ACCEPT: return DragDropFinish::P_ACCEPT.Value();
        case URHO3D_EVENT_FOCUSCHANGED: return E_FOCUSCHANGED.Value();
        case URHO3D_EVENT_FOCUSCHANGED_ELEMENT: return FocusChanged::P_ELEMENT.Value();
        case URHO3D_EVENT_FOCUSCHANGED_CLICKEDELEMENT: return FocusChanged::P_CLICKEDELEMENT.Value();
        case URHO3D_EVENT_NAMECHANGED: return E_NAMECHANGED.Value();
        case URHO3D_EVENT_NAMECHANGED_ELEMENT: return NameChanged::P_ELEMENT.Value();
        case URHO3D_EVENT_RESIZED: return E_RESIZED.Value();
        case URHO3D_EVENT_RESIZED_ELEMENT: return Resized::P_ELEMENT.Value();
        case URHO3D_EVENT_RESIZED_WIDTH: return Resized::P_WIDTH.Value();
        case URHO3D_EVENT_RESIZED_HEIGHT: return Resized::P_HEIGHT.Value();
        case URHO3D_EVENT_POSITIONED: return E_POSITIONED.Value();
        case URHO3D_EVENT_POSITIONED_ELEMENT: return Positioned::P_ELEMENT.Value();
        case URHO3D_EVENT_POSITIONED_X: return Positioned::P_X.Value();
        case URHO3D_EVENT_POSITIONED_Y: return Positioned::P_Y.Value();
        case URHO3D_EVENT_VISIBLECHANGED: return E_VISIBLECHANGED.Value();
        case URHO3D_EVENT_VISIBLECHANGED_ELEMENT: return VisibleChanged::P_ELEMENT.Value();
        case URHO3D_EVENT_VISIBLECHANGED_VISIBLE: return VisibleChanged::P_VISIBLE.Value();
        case URHO3D_EVENT_FOCUSED: return E_FOCUSED.Value();
        case URHO3D_EVENT_FOCUSED_ELEMENT: return Focused::P_ELEMENT.Value();
        case URHO3D_EVENT_FOCUSED_BYKEY: return Focused::P_BYKEY.Value();
        case URHO3D_EVENT_DEFOCUSED: return E_DEFOCUSED.Value();
        case URHO3D_EVENT_DEFOCUSED_ELEMENT: return Defocused::P_ELEMENT.Value();
        case URHO3D_EVENT_LAYOUTUPDATED: return E_LAYOUTUPDATED.Value();
        case URHO3D_EVENT_LAYOUTUPDATED_ELEMENT: return LayoutUpdated::P_ELEMENT.Value();
        case URHO3D_EVENT_PRESSED: return E_PRESSED.Value();
        case URHO3D_EVENT_PRESSED_ELEMENT: return Pressed::P_ELEMENT.Value();
        case URHO3D_EVENT_RELEASED: return E_RELEASED.Value();
        case URHO3D_EVENT_RELEASED_ELEMENT: return Released::P_ELEMENT.Value();
        case URHO3D_EVENT_TOGGLED: return E_TOGGLED.Value();
        case URHO3D_EVENT_TOGGLED_ELEMENT: return Toggled::P_ELEMENT.Value();
        case URHO3D_EVENT_TOGGLED_STATE: return Toggled::P_STATE.Value();
        case URHO3D_EVENT_SLIDERCHANGED: return E_SLIDERCHANGED.Value();
        case URHO3D_EVENT_SLIDERCHANGED_ELEMENT: return SliderChanged::P_ELEMENT.Value();
        case URHO3D_EVENT_SLIDERCHANGED_VALUE: return SliderChanged::P_VALUE.Value();
        case URHO3D_EVENT_SLIDERPAGED: return E_SLIDERPAGED.Value();
        case URHO3D_EVENT_SLIDERPAGED_ELEMENT: return SliderPaged::P_ELEMENT.Value();
        case URHO3D_EVENT_SLIDERPAGED_OFFSET: return SliderPaged::P_OFFSET.Value();
        case URHO3D_EVENT_SLIDERPAGED_PRESSED: return SliderPaged::P_PRESSED.Value();
        case URHO3D_EVENT_SCROLLBARCHANGED: return E_SCROLLBARCHANGED.Value();
        case URHO3D_EVENT_SCROLLBARCHANGED_ELEMENT: return ScrollBarChanged::P_ELEMENT.Value();
        case URHO3D_EVENT_SCROLLBARCHANGED_VALUE: return ScrollBarChanged::P_VALUE.Value();
        case URHO3D_EVENT_VIEWCHANGED: return E_VIEWCHANGED.Value();
        case URHO3D_EVENT_VIEWCHANGED_ELEMENT: return ViewChanged::P_ELEMENT.Value();
        case URHO3D_EVENT_VIEWCHANGED_X: return ViewChanged::P_X.Value();
        case URHO3D_EVENT_VIEWCHANGED_Y: return ViewChanged::P_Y.Value();
        case URHO3D_EVENT_MODALCHANGED: return E_MODALCHANGED.Value();
        case URHO3D_EVENT_MODALCHANGED_ELEMENT: return ModalChanged::P_ELEMENT.Value();
        case URHO3D_EVENT_MODALCHANGED_MODAL: return ModalChanged::P_MODAL.Value();
        case URHO3D_EVENT_CHARENTRY: return E_TEXTENTRY.Value();
        case URHO3D_EVENT_CHARENTRY_ELEMENT: return CharEntry::P_ELEMENT.Value();
        case URHO3D_EVENT_CHARENTRY_TEXT: return CharEntry::P_TEXT.Value();
        case URHO3D_EVENT_CHARENTRY_BUTTONS: return CharEntry::P_BUTTONS.Value();
        case URHO3D_EVENT_CHARENTRY_QUALIFIERS: return CharEntry::P_QUALIFIERS.Value();
        case URHO3D_EVENT_TEXTCHANGED: return E_TEXTCHANGED.Value();
        case URHO3D_EVENT_TEXTCHANGED_ELEMENT: return TextChanged::P_ELEMENT.Value();
        case URHO3D_EVENT_TEXTCHANGED_TEXT: return TextChanged::P_TEXT.Value();
        case URHO3D_EVENT_TEXTFINISHED: return E_TEXTFINISHED.Value();
        case URHO3D_EVENT_TEXTFINISHED_ELEMENT: return TextFinished::P_ELEMENT.Value();
        case URHO3D_EVENT_TEXTFINISHED_TEXT: return TextFinished::P_TEXT.Value();
        case URHO3D_EVENT_TEXTFINISHED_VALUE: return TextFinished::P_VALUE.Value();
        case URHO3D_EVENT_MENUSELECTED: return E_MENUSELECTED.Value();
        case URHO3D_EVENT_MENUSELECTED_ELEMENT: return MenuSelected::P_ELEMENT.Value();
        case URHO3D_EVENT_ITEMSELECTED: return E_ITEMSELECTED.Value();
        case URHO3D_EVENT_ITEMSELECTED_ELEMENT: return ItemSelected::P_ELEMENT.Value();
        case URHO3D_EVENT_ITEMSELECTED_SELECTION: return ItemSelected::P_SELECTION.Value();
        case URHO3D_EVENT_ITEMDESELECTED: return E_ITEMDESELECTED.Value();
        case URHO3D_EVENT_ITEMDESELECTED_ELEMENT: return ItemDeselected::P_ELEMENT.Value();
        case URHO3D_EVENT_ITEMDESELECTED_SELECTION: return ItemDeselected::P_SELECTION.Value();
        case URHO3D_EVENT_SELECTIONCHANGED: return E_SELECTIONCHANGED.Value();
        case URHO3D_EVENT_SELECTIONCHANGED_ELEMENT: return SelectionChanged::P_ELEMENT.Value();
        case URHO3D_EVENT_ITEMCLICKED: return E_ITEMCLICKED.Value();
        case URHO3D_EVENT_ITEMCLICKED_ELEMENT: return ItemClicked::P_ELEMENT.Value();
        case URHO3D_EVENT_ITEMCLICKED_ITEM: return ItemClicked::P_ITEM.Value();
        case URHO3D_EVENT_ITEMCLICKED_SELECTION: return ItemClicked::P_SELECTION.Value();
        case URHO3D_EVENT_ITEMCLICKED_BUTTON: return ItemClicked::P_BUTTON.Value();
        case URHO3D_EVENT_ITEMCLICKED_BUTTONS: return ItemClicked::P_BUTTONS.Value();
        case URHO3D_EVENT_ITEMCLICKED_QUALIFIERS: return ItemClicked::P_QUALIFIERS.Value();
        case URHO3D_EVENT_ITEMDOUBLECLICKED: return E_ITEMDOUBLECLICKED.Value();
        case URHO3D_EVENT_ITEMDOUBLECLICKED_ELEMENT: return ItemDoubleClicked::P_ELEMENT.Value();
        case URHO3D_EVENT_ITEMDOUBLECLICKED_ITEM: return ItemDoubleClicked::P_ITEM.Value();
        case URHO3D_EVENT_ITEMDOUBLECLICKED_SELECTION: return ItemDoubleClicked::P_SELECTION.Value();
        case URHO3D_EVENT_ITEMDOUBLECLICKED_BUTTON: return ItemDoubleClicked::P_BUTTON.Value();
        case URHO3D_EVENT_ITEMDOUBLECLICKED_BUTTONS: return ItemDoubleClicked::P_BUTTONS.Value();
        case URHO3D_EVENT_ITEMDOUBLECLICKED_QUALIFIERS: return ItemDoubleClicked::P_QUALIFIERS.Value();
        case URHO3D_EVENT_UNHANDLEDKEY: return E_UNHANDLEDKEY.Value();
        case URHO3D_EVENT_UNHANDLEDKEY_ELEMENT: return UnhandledKey::P_ELEMENT.Value();
        case URHO3D_EVENT_UNHANDLEDKEY_KEY: return UnhandledKey::P_KEY.Value();
        case URHO3D_EVENT_UNHANDLEDKEY_BUTTONS: return UnhandledKey::P_BUTTONS.Value();
        case URHO3D_EVENT_UNHANDLEDKEY_QUALIFIERS: return UnhandledKey::P_QUALIFIERS.Value();
        case URHO3D_EVENT_FILESELECTED: return E_FILESELECTED.Value();
        case URHO3D_EVENT_FILESELECTED_FILENAME: return FileSelected::P_FILENAME.Value();
        case URHO3D_EVENT_FILESELECTED_FILTER: return FileSelected::P_FILTER.Value();
        case URHO3D_EVENT_FILESELECTED_OK: return FileSelected::P_OK.Value();
        case URHO3D_EVENT_MESSAGEACK: return E_MESSAGEACK.Value();
        case URHO3D_EVENT_MESSAGEACK_OK: return MessageACK::P_OK.Value();
        case URHO3D_EVENT_ELEMENTADDED: return E_ELEMENTADDED.Value();
        case URHO3D_EVENT_ELEMENTADDED_ROOT: return ElementAdded::P_ROOT.Value();
        case URHO3D_EVENT_ELEMENTADDED_PARENT: return ElementAdded::P_PARENT.Value();
        case URHO3D_EVENT_ELEMENTADDED_ELEMENT: return ElementAdded::P_ELEMENT.Value();
        case URHO3D_EVENT_ELEMENTREMOVED: return E_ELEMENTREMOVED.Value();
        case URHO3D_EVENT_ELEMENTREMOVED_ROOT: return ElementRemoved::P_ROOT.Value();
        case URHO3D_EVENT_ELEMENTREMOVED_PARENT: return ElementRemoved::P_PARENT.Value();
        case URHO3D_EVENT_ELEMENTREMOVED_ELEMENT: return ElementRemoved::P_ELEMENT.Value();
        case URHO3D_EVENT_HOVERBEGIN: return E_HOVERBEGIN.Value();
        case URHO3D_EVENT_HOVERBEGIN_ELEMENT: return HoverBegin::P_ELEMENT.Value();
        case URHO3D_EVENT_HOVERBEGIN_X: return HoverBegin::P_X.Value();
        case URHO3D_EVENT_HOVERBEGIN_Y: return HoverBegin::P_Y.Value();
        case URHO3D_EVENT_HOVERBEGIN_ELEMENTX: return HoverBegin::P_ELEMENTX.Value();
        case URHO3D_EVENT_HOVERBEGIN_ELEMENTY: return HoverBegin::P_ELEMENTY.Value();
        case URHO3D_EVENT_HOVEREND: return E_HOVEREND.Value();
        case URHO3D_EVENT_HOVEREND_ELEMENT: return HoverEnd::P_ELEMENT.Value();
        case URHO3D_EVENT_DRAGBEGIN: return E_DRAGBEGIN.Value();
        case URHO3D_EVENT_DRAGBEGIN_ELEMENT: return DragBegin::P_ELEMENT.Value();
        case URHO3D_EVENT_DRAGBEGIN_X: return DragBegin::P_X.Value();
        case URHO3D_EVENT_DRAGBEGIN_Y: return DragBegin::P_Y.Value();
        case URHO3D_EVENT_DRAGBEGIN_ELEMENTX: return DragBegin::P_ELEMENTX.Value();
        case URHO3D_EVENT_DRAGBEGIN_ELEMENTY: return DragBegin::P_ELEMENTY.Value();
        case URHO3D_EVENT_DRAGBEGIN_BUTTONS: return DragBegin::P_BUTTONS.Value();
        case URHO3D_EVENT_DRAGBEGIN_NUMBUTTONS: return DragBegin::P_NUMBUTTONS.Value();
        case URHO3D_EVENT_DRAGMOVE: return E_DRAGMOVE.Value();
        case URHO3D_EVENT_DRAGMOVE_ELEMENT: return DragMove::P_ELEMENT.Value();
        case URHO3D_EVENT_DRAGMOVE_X: return DragMove::P_X.Value();
        case URHO3D_EVENT_DRAGMOVE_Y: return DragMove::P_Y.Value();
        case URHO3D_EVENT_DRAGMOVE_DX: return DragMove::P_DX.Value();
        case URHO3D_EVENT_DRAGMOVE_DY: return DragMove::P_DY.Value();
        case URHO3D_EVENT_DRAGMOVE_ELEMENTX: return DragMove::P_ELEMENTX.Value();
        case URHO3D_EVENT_DRAGMOVE_ELEMENTY: return DragMove::P_ELEMENTY.Value();
        case URHO3D_EVENT_DRAGMOVE_BUTTONS: return DragMove::P_BUTTONS.Value();
        case URHO3D_EVENT_DRAGMOVE_NUMBUTTONS: return DragMove::P_NUMBUTTONS.Value();
        case URHO3D_EVENT_DRAGEND: return E_DRAGEND.Value();
        case URHO3D_EVENT_DRAGEND_ELEMENT: return DragEnd::P_ELEMENT.Value();
        case URHO3D_EVENT_DRAGEND_X: return DragEnd::P_X.Value();
        case URHO3D_EVENT_DRAGEND_Y: return DragEnd::P_Y.Value();
        case URHO3D_EVENT_DRAGEND_ELEMENTX: return DragEnd::P_ELEMENTX.Value();
        case URHO3D_EVENT_DRAGEND_ELEMENTY: return DragEnd::P_ELEMENTY.Value();
        case URHO3D_EVENT_DRAGEND_BUTTONS: return DragEnd::P_BUTTONS.Value();
        case URHO3D_EVENT_DRAGEND_NUMBUTTONS: return DragEnd::P_NUMBUTTONS.Value();
        case URHO3D_EVENT_DRAGCANCEL: return E_DRAGCANCEL.Value();
        case URHO3D_EVENT_DRAGCANCEL_ELEMENT: return DragCancel::P_ELEMENT.Value();
        case URHO3D_EVENT_DRAGCANCEL_X: return DragCancel::P_X.Value();
        case URHO3D_EVENT_DRAGCANCEL_Y: return DragCancel::P_Y.Value();
        case URHO3D_EVENT_DRAGCANCEL_ELEMENTX: return DragCancel::P_ELEMENTX.Value();
        case URHO3D_EVENT_DRAGCANCEL_ELEMENTY: return DragCancel::P_ELEMENTY.Value();
        case URHO3D_EVENT_DRAGCANCEL_BUTTONS: return DragCancel::P_BUTTONS.Value();
        case URHO3D_EVENT_DRAGCANCEL_NUMBUTTONS: return DragCancel::P_NUMBUTTONS.Value();
        case URHO3D_EVENT_UIDROPFILE: return E_UIDROPFILE.Value();
        case URHO3D_EVENT_UIDROPFILE_FILENAME: return UIDropFile::P_FILENAME.Value();
        case URHO3D_EVENT_UIDROPFILE_ELEMENT: return UIDropFile::P_ELEMENT.Value();
        case URHO3D_EVENT_UIDROPFILE_X: return UIDropFile::P_X.Value();
        case URHO3D_EVENT_UIDROPFILE_Y: return UIDropFile::P_Y.Value();
        case URHO3D_EVENT_UIDROPFILE_ELEMENTX: return UIDropFile::P_ELEMENTX.Value();
        case URHO3D_EVENT_UIDROPFILE_ELEMENTY: return UIDropFile::P_ELEMENTY.Value();
        default: return 0;
    }
}

const Urho3D_TypeInfo* Urho3D_GetTypeInfo(Urho3D_Type type)
{
    switch (type) {
        case URHO3D_TYPE_ANIMATIONCONTROLLER: return AnimationController::GetTypeInfoStatic();
        case URHO3D_TYPE_CAMERA: return Camera::GetTypeInfoStatic();
        case URHO3D_TYPE_COLLISIONSHAPE: return CollisionShape::GetTypeInfoStatic();
        case URHO3D_TYPE_COMPONENT: return Component::GetTypeInfoStatic();
        case URHO3D_TYPE_CROWDAGENT: return CrowdAgent::GetTypeInfoStatic();
        case URHO3D_TYPE_CROWDMANAGER: return CrowdManager::GetTypeInfoStatic();
        case URHO3D_TYPE_DEBUGRENDERER: return DebugRenderer::GetTypeInfoStatic();
        case URHO3D_TYPE_DYNAMICNAVIGATIONMESH: return DynamicNavigationMesh::GetTypeInfoStatic();
        case URHO3D_TYPE_FONT: return Font::GetTypeInfoStatic();
        case URHO3D_TYPE_GRAPHICS: return Graphics::GetTypeInfoStatic();
        case URHO3D_TYPE_IMAGE: return Image::GetTypeInfoStatic();
        case URHO3D_TYPE_INPUT: return Input::GetTypeInfoStatic();
        case URHO3D_TYPE_LIGHT: return Light::GetTypeInfoStatic();
        case URHO3D_TYPE_MATERIAL: return Material::GetTypeInfoStatic();
        case URHO3D_TYPE_MODEL: return Model::GetTypeInfoStatic();
        case URHO3D_TYPE_NAVIGABLE: return Navigable::GetTypeInfoStatic();
        case URHO3D_TYPE_NAVIGATIONMESH: return NavigationMesh::GetTypeInfoStatic();
        case URHO3D_TYPE_NODE: return Node::GetTypeInfoStatic();
        case URHO3D_TYPE_OCTREE: return Octree::GetTypeInfoStatic();
        case URHO3D_TYPE_PHYSICSWORLD: return PhysicsWorld::GetTypeInfoStatic();
        case URHO3D_TYPE_RESOURCECACHE: return ResourceCache::GetTypeInfoStatic();
        case URHO3D_TYPE_RIGIDBODY: return RigidBody::GetTypeInfoStatic();
        case URHO3D_TYPE_SCENE: return Scene::GetTypeInfoStatic();
        case URHO3D_TYPE_STATICMODEL: return StaticModel::GetTypeInfoStatic();
        case URHO3D_TYPE_TEXT: return Text::GetTypeInfoStatic();
        case URHO3D_TYPE_UI: return UI::GetTypeInfoStatic();
        case URHO3D_TYPE_UIELEMENT: return UIElement::GetTypeInfoStatic();
        case URHO3D_TYPE_VIEWPORT: return Viewport::GetTypeInfoStatic();
        default: return 0;
    }
}

Urho3D_AnimationController* Urho3D_AnimationController_New(Urho3D_Context* context)
{
    return new AnimationController(context);
}

void Urho3D_AnimationController_Play(Urho3D_AnimationController* self, const char* name, bool looped, float fadeInTime)
{
    self->Play(name, looped, fadeInTime);
}

void Urho3D_AnimationController_Stop(Urho3D_AnimationController* self, const char* name, float fadeOutTime)
{
    self->Stop(name, fadeOutTime);
}

void Urho3D_AnimationController_StopAll(Urho3D_AnimationController* self, float fadeTime)
{
    self->StopAll(fadeTime);
}

Urho3D_Camera* Urho3D_Camera_New(Urho3D_Context* context)
{
    return new Camera(context);
}

Urho3D_CollisionShape* Urho3D_CollisionShape_New(Urho3D_Context* context)
{
    return new CollisionShape(context);
}

void Urho3D_CollisionShape_SetBox(Urho3D_CollisionShape* self, const Urho3D_Vector3* size, const Urho3D_Vector3* position, const Urho3D_Quaternion* rotation)
{
    self->SetBox(*size, *position, *rotation);
}

void Urho3D_CollisionShape_SetSphere(Urho3D_CollisionShape* self, float diameter, const Urho3D_Vector3* position, const Urho3D_Quaternion* rotation)
{
    self->SetSphere(diameter, *position, *rotation);
}

void Urho3D_CollisionShape_SetStaticPlane(Urho3D_CollisionShape* self, const Urho3D_Vector3* position, const Urho3D_Quaternion* rotation)
{
    self->SetStaticPlane(*position, *rotation);
}

Urho3D_Node* Urho3D_Component_GetNode(Urho3D_Component* self)
{
    return self->GetNode();
}

Urho3D_Scene* Urho3D_Component_GetScene(Urho3D_Component* self)
{
    return self->GetScene();
}

unsigned int Urho3D_Component_GetID(Urho3D_Component* self)
{
    return self->GetID();
}

void Urho3D_Component_Remove(Urho3D_Component* self)
{
    self->Remove();
}

Urho3D_CrowdAgent* Urho3D_CrowdAgent_New(Urho3D_Context* context)
{
    return new CrowdAgent(context);
}

float Urho3D_CrowdAgent_GetHeight(Urho3D_CrowdAgent* self)
{
    return self->GetHeight();
}

void Urho3D_CrowdAgent_SetHeight(Urho3D_CrowdAgent* self, float newValue)
{
    self->SetHeight(newValue);
}

float Urho3D_CrowdAgent_GetRadius(Urho3D_CrowdAgent* self)
{
    return self->GetRadius();
}

void Urho3D_CrowdAgent_SetRadius(Urho3D_CrowdAgent* self, float newValue)
{
    self->SetRadius(newValue);
}

float Urho3D_CrowdAgent_GetMaxSpeed(Urho3D_CrowdAgent* self)
{
    return self->GetMaxSpeed();
}

void Urho3D_CrowdAgent_SetMaxSpeed(Urho3D_CrowdAgent* self, float newValue)
{
    self->SetMaxSpeed(newValue);
}

float Urho3D_CrowdAgent_GetMaxAccel(Urho3D_CrowdAgent* self)
{
    return self->GetMaxAccel();
}

void Urho3D_CrowdAgent_SetMaxAccel(Urho3D_CrowdAgent* self, float newValue)
{
    self->SetMaxAccel(newValue);
}

void Urho3D_CrowdAgent_GetTargetPosition(Urho3D_CrowdAgent* self, Urho3D_Vector3* value)
{
    *value = self->GetTargetPosition();
}

void Urho3D_CrowdAgent_SetTargetPosition(Urho3D_CrowdAgent* self, const Urho3D_Vector3* newValue)
{
    self->SetTargetPosition(*newValue);
}

void Urho3D_CrowdAgent_ResetTarget(Urho3D_CrowdAgent* self)
{
    self->ResetTarget();
}

Urho3D_CrowdManager* Urho3D_CrowdManager_New(Urho3D_Context* context)
{
    return new CrowdManager(context);
}

void Urho3D_CrowdManager_SetCrowdTarget(Urho3D_CrowdManager* self, const Urho3D_Vector3* position, Urho3D_Node* node)
{
    self->SetCrowdTarget(*position, node);
}

Urho3D_DebugRenderer* Urho3D_DebugRenderer_New(Urho3D_Context* context)
{
    return new DebugRenderer(context);
}

Urho3D_DynamicNavigationMesh* Urho3D_DynamicNavigationMesh_New(Urho3D_Context* context)
{
    return new DynamicNavigationMesh(context);
}

bool Urho3D_Input_IsMouseVisible(Urho3D_Input* self)
{
    return self->IsMouseVisible();
}

void Urho3D_Input_SetMouseVisible(Urho3D_Input* self, bool newValue)
{
    self->SetMouseVisible(newValue);
}

void Urho3D_Input_GetMousePosition(Urho3D_Input* self, Urho3D_IntVector2* value)
{
    *value = self->GetMousePosition();
}

void Urho3D_Input_GetMouseMove(Urho3D_Input* self, Urho3D_IntVector2* value)
{
    *value = self->GetMouseMove();
}

int Urho3D_Input_GetMouseMoveWheel(Urho3D_Input* self)
{
    return self->GetMouseMoveWheel();
}

bool Urho3D_Input_GetKeyDown(Urho3D_Input* self, int key)
{
    return self->GetKeyDown(key);
}

bool Urho3D_Input_GetKeyPress(Urho3D_Input* self, int key)
{
    return self->GetKeyPress(key);
}

Urho3D_Navigable* Urho3D_Navigable_New(Urho3D_Context* context)
{
    return new Navigable(context);
}

Urho3D_NavigationMesh* Urho3D_NavigationMesh_New(Urho3D_Context* context)
{
    return new NavigationMesh(context);
}

float Urho3D_NavigationMesh_GetAgentHeight(Urho3D_NavigationMesh* self)
{
    return self->GetAgentHeight();
}

void Urho3D_NavigationMesh_SetAgentHeight(Urho3D_NavigationMesh* self, float newValue)
{
    self->SetAgentHeight(newValue);
}

float Urho3D_NavigationMesh_GetCellHeight(Urho3D_NavigationMesh* self)
{
    return self->GetCellHeight();
}

void Urho3D_NavigationMesh_SetCellHeight(Urho3D_NavigationMesh* self, float newValue)
{
    self->SetCellHeight(newValue);
}

void Urho3D_NavigationMesh_GetPadding(Urho3D_NavigationMesh* self, Urho3D_Vector3* value)
{
    *value = self->GetPadding();
}

void Urho3D_NavigationMesh_SetPadding(Urho3D_NavigationMesh* self, const Urho3D_Vector3* newValue)
{
    self->SetPadding(*newValue);
}

void Urho3D_NavigationMesh_Build(Urho3D_NavigationMesh* self)
{
    self->Build();
}

void Urho3D_NavigationMesh_FindNearestPoint(Urho3D_NavigationMesh* self, const Urho3D_Vector3* point, Urho3D_Vector3* result)
{
    *result = self->FindNearestPoint(*point);
}

Urho3D_Node* Urho3D_Node_GetParent(Urho3D_Node* self)
{
    return self->GetParent();
}

Urho3D_Scene* Urho3D_Node_GetScene(Urho3D_Node* self)
{
    return self->GetScene();
}

unsigned int Urho3D_Node_GetID(Urho3D_Node* self)
{
    return self->GetID();
}

void Urho3D_Node_GetPosition(Urho3D_Node* self, Urho3D_Vector3* value)
{
    *value = self->GetPosition();
}

void Urho3D_Node_SetPosition(Urho3D_Node* self, const Urho3D_Vector3* newValue)
{
    self->SetPosition(*newValue);
}

void Urho3D_Node_GetWorldPosition(Urho3D_Node* self, Urho3D_Vector3* value)
{
    *value = self->GetWorldPosition();
}

void Urho3D_Node_SetWorldPosition(Urho3D_Node* self, const Urho3D_Vector3* newValue)
{
    self->SetWorldPosition(*newValue);
}

void Urho3D_Node_GetRotation(Urho3D_Node* self, Urho3D_Quaternion* value)
{
    *value = self->GetRotation();
}

void Urho3D_Node_SetRotation(Urho3D_Node* self, const Urho3D_Quaternion* newValue)
{
    self->SetRotation(*newValue);
}

void Urho3D_Node_GetWorldRotation(Urho3D_Node* self, Urho3D_Quaternion* value)
{
    *value = self->GetWorldRotation();
}

void Urho3D_Node_SetWorldRotation(Urho3D_Node* self, const Urho3D_Quaternion* newValue)
{
    self->SetWorldRotation(*newValue);
}

void Urho3D_Node_GetScale(Urho3D_Node* self, Urho3D_Vector3* value)
{
    *value = self->GetScale();
}

void Urho3D_Node_SetScale(Urho3D_Node* self, const Urho3D_Vector3* newValue)
{
    self->SetScale(*newValue);
}

const char* Urho3D_Node_GetName(Urho3D_Node* self)
{
    return self->GetName().CString();
}

void Urho3D_Node_SetName(Urho3D_Node* self, const char* newValue)
{
    self->SetName(newValue);
}

void Urho3D_Node_AddChild(Urho3D_Node* self, Urho3D_Node* node)
{
    self->AddChild(node);
}

void Urho3D_Node_Pitch(Urho3D_Node* self, float angle)
{
    self->Pitch(angle);
}

void Urho3D_Node_Remove(Urho3D_Node* self)
{
    self->Remove();
}

void Urho3D_Node_Roll(Urho3D_Node* self, float angle)
{
    self->Roll(angle);
}

void Urho3D_Node_Yaw(Urho3D_Node* self, float angle)
{
    self->Yaw(angle);
}

Urho3D_Octree* Urho3D_Octree_New(Urho3D_Context* context)
{
    return new Octree(context);
}

Urho3D_PhysicsWorld* Urho3D_PhysicsWorld_New(Urho3D_Context* context)
{
    return new PhysicsWorld(context);
}

Urho3D_RigidBody* Urho3D_RigidBody_New(Urho3D_Context* context)
{
    return new RigidBody(context);
}

Urho3D_PhysicsWorld* Urho3D_RigidBody_GetPhysicsWorld(Urho3D_RigidBody* self)
{
    return self->GetPhysicsWorld();
}

float Urho3D_RigidBody_GetMass(Urho3D_RigidBody* self)
{
    return self->GetMass();
}

void Urho3D_RigidBody_SetMass(Urho3D_RigidBody* self, float newValue)
{
    self->SetMass(newValue);
}

bool Urho3D_RigidBody_IsKinematic(Urho3D_RigidBody* self)
{
    return self->IsKinematic();
}

void Urho3D_RigidBody_SetKinematic(Urho3D_RigidBody* self, bool newValue)
{
    self->SetKinematic(newValue);
}

bool Urho3D_RigidBody_IsTrigger(Urho3D_RigidBody* self)
{
    return self->IsTrigger();
}

void Urho3D_RigidBody_SetTrigger(Urho3D_RigidBody* self, bool newValue)
{
    self->SetTrigger(newValue);
}

void Urho3D_RigidBody_ApplyForce(Urho3D_RigidBody* self, const Urho3D_Vector3* force)
{
    self->ApplyForce(*force);
}

void Urho3D_RigidBody_ApplyImpulse(Urho3D_RigidBody* self, const Urho3D_Vector3* impulse)
{
    self->ApplyImpulse(*impulse);
}

Urho3D_StaticModel* Urho3D_StaticModel_New(Urho3D_Context* context)
{
    return new StaticModel(context);
}

Urho3D_Model* Urho3D_StaticModel_GetModel(Urho3D_StaticModel* self)
{
    return self->GetModel();
}

void Urho3D_StaticModel_SetModel(Urho3D_StaticModel* self, Urho3D_Model* newValue)
{
    self->SetModel(newValue);
}

Urho3D_Material* Urho3D_StaticModel_GetMaterial(Urho3D_StaticModel* self)
{
    return self->GetMaterial();
}

void Urho3D_StaticModel_SetMaterial(Urho3D_StaticModel* self, Urho3D_Material* newValue)
{
    self->SetMaterial(newValue);
}

const char* Urho3D_Text_GetText(Urho3D_Text* self)
{
    return self->GetText().CString();
}

void Urho3D_Text_SetText(Urho3D_Text* self, const char* newValue)
{
    self->SetText(newValue);
}

void Urho3D_Text_SetFont(Urho3D_Text* self, Urho3D_Font* font, int size)
{
    self->SetFont(font, size);
}

Urho3D_UIElement* Urho3D_UI_GetRoot(Urho3D_UI* self)
{
    return self->GetRoot();
}

void Urho3D_UIElement_GetPosition(Urho3D_UIElement* self, Urho3D_IntVector2* value)
{
    *value = self->GetPosition();
}

void Urho3D_UIElement_SetPosition(Urho3D_UIElement* self, const Urho3D_IntVector2* newValue)
{
    self->SetPosition(*newValue);
}

void Urho3D_UIElement_AddChild(Urho3D_UIElement* self, Urho3D_UIElement* child)
{
    self->AddChild(child);
}

