
Urho3D_StringHash Urho3D_GetEventHash(Urho3D_Event symbol) URHO3D_API;

const Urho3D_TypeInfo* Urho3D_GetTypeInfo(Urho3D_Type type) URHO3D_API;

Urho3D_AnimationController* Urho3D_AnimationController_New(Urho3D_Context* context) URHO3D_API;

void Urho3D_AnimationController_Play(Urho3D_AnimationController* self, const char* name, bool looped, float fadeInTime) URHO3D_API;

void Urho3D_AnimationController_Stop(Urho3D_AnimationController* self, const char* name, float fadeOutTime) URHO3D_API;

void Urho3D_AnimationController_StopAll(Urho3D_AnimationController* self, float fadeTime) URHO3D_API;

Urho3D_Camera* Urho3D_Camera_New(Urho3D_Context* context) URHO3D_API;

Urho3D_CollisionShape* Urho3D_CollisionShape_New(Urho3D_Context* context) URHO3D_API;

void Urho3D_CollisionShape_SetBox(Urho3D_CollisionShape* self, const Urho3D_Vector3* size, const Urho3D_Vector3* position, const Urho3D_Quaternion* rotation) URHO3D_API;

void Urho3D_CollisionShape_SetSphere(Urho3D_CollisionShape* self, float diameter, const Urho3D_Vector3* position, const Urho3D_Quaternion* rotation) URHO3D_API;

void Urho3D_CollisionShape_SetStaticPlane(Urho3D_CollisionShape* self, const Urho3D_Vector3* position, const Urho3D_Quaternion* rotation) URHO3D_API;

Urho3D_Node* Urho3D_Component_GetNode(Urho3D_Component* self) URHO3D_API;

Urho3D_Scene* Urho3D_Component_GetScene(Urho3D_Component* self) URHO3D_API;

unsigned int Urho3D_Component_GetID(Urho3D_Component* self) URHO3D_API;

void Urho3D_Component_Remove(Urho3D_Component* self) URHO3D_API;

Urho3D_CrowdAgent* Urho3D_CrowdAgent_New(Urho3D_Context* context) URHO3D_API;

float Urho3D_CrowdAgent_GetHeight(Urho3D_CrowdAgent* self) URHO3D_API;

void Urho3D_CrowdAgent_SetHeight(Urho3D_CrowdAgent* self, float newValue) URHO3D_API;

float Urho3D_CrowdAgent_GetRadius(Urho3D_CrowdAgent* self) URHO3D_API;

void Urho3D_CrowdAgent_SetRadius(Urho3D_CrowdAgent* self, float newValue) URHO3D_API;

float Urho3D_CrowdAgent_GetMaxSpeed(Urho3D_CrowdAgent* self) URHO3D_API;

void Urho3D_CrowdAgent_SetMaxSpeed(Urho3D_CrowdAgent* self, float newValue) URHO3D_API;

float Urho3D_CrowdAgent_GetMaxAccel(Urho3D_CrowdAgent* self) URHO3D_API;

void Urho3D_CrowdAgent_SetMaxAccel(Urho3D_CrowdAgent* self, float newValue) URHO3D_API;

void Urho3D_CrowdAgent_GetTargetPosition(Urho3D_CrowdAgent* self, Urho3D_Vector3* value) URHO3D_API;

void Urho3D_CrowdAgent_SetTargetPosition(Urho3D_CrowdAgent* self, const Urho3D_Vector3* newValue) URHO3D_API;

void Urho3D_CrowdAgent_ResetTarget(Urho3D_CrowdAgent* self) URHO3D_API;

Urho3D_CrowdManager* Urho3D_CrowdManager_New(Urho3D_Context* context) URHO3D_API;

void Urho3D_CrowdManager_SetCrowdTarget(Urho3D_CrowdManager* self, const Urho3D_Vector3* position, Urho3D_Node* node) URHO3D_API;

Urho3D_DebugRenderer* Urho3D_DebugRenderer_New(Urho3D_Context* context) URHO3D_API;

Urho3D_DynamicNavigationMesh* Urho3D_DynamicNavigationMesh_New(Urho3D_Context* context) URHO3D_API;

bool Urho3D_Input_IsMouseVisible(Urho3D_Input* self) URHO3D_API;

void Urho3D_Input_SetMouseVisible(Urho3D_Input* self, bool newValue) URHO3D_API;

void Urho3D_Input_GetMousePosition(Urho3D_Input* self, Urho3D_IntVector2* value) URHO3D_API;

void Urho3D_Input_GetMouseMove(Urho3D_Input* self, Urho3D_IntVector2* value) URHO3D_API;

int Urho3D_Input_GetMouseMoveWheel(Urho3D_Input* self) URHO3D_API;

bool Urho3D_Input_GetKeyDown(Urho3D_Input* self, int key) URHO3D_API;

bool Urho3D_Input_GetKeyPress(Urho3D_Input* self, int key) URHO3D_API;

Urho3D_Navigable* Urho3D_Navigable_New(Urho3D_Context* context) URHO3D_API;

Urho3D_NavigationMesh* Urho3D_NavigationMesh_New(Urho3D_Context* context) URHO3D_API;

float Urho3D_NavigationMesh_GetAgentHeight(Urho3D_NavigationMesh* self) URHO3D_API;

void Urho3D_NavigationMesh_SetAgentHeight(Urho3D_NavigationMesh* self, float newValue) URHO3D_API;

float Urho3D_NavigationMesh_GetCellHeight(Urho3D_NavigationMesh* self) URHO3D_API;

void Urho3D_NavigationMesh_SetCellHeight(Urho3D_NavigationMesh* self, float newValue) URHO3D_API;

void Urho3D_NavigationMesh_GetPadding(Urho3D_NavigationMesh* self, Urho3D_Vector3* value) URHO3D_API;

void Urho3D_NavigationMesh_SetPadding(Urho3D_NavigationMesh* self, const Urho3D_Vector3* newValue) URHO3D_API;

void Urho3D_NavigationMesh_Build(Urho3D_NavigationMesh* self) URHO3D_API;

void Urho3D_NavigationMesh_FindNearestPoint(Urho3D_NavigationMesh* self, const Urho3D_Vector3* point, Urho3D_Vector3* result) URHO3D_API;

Urho3D_Node* Urho3D_Node_GetParent(Urho3D_Node* self) URHO3D_API;

Urho3D_Scene* Urho3D_Node_GetScene(Urho3D_Node* self) URHO3D_API;

unsigned int Urho3D_Node_GetID(Urho3D_Node* self) URHO3D_API;

void Urho3D_Node_GetPosition(Urho3D_Node* self, Urho3D_Vector3* value) URHO3D_API;

void Urho3D_Node_SetPosition(Urho3D_Node* self, const Urho3D_Vector3* newValue) URHO3D_API;

void Urho3D_Node_GetWorldPosition(Urho3D_Node* self, Urho3D_Vector3* value) URHO3D_API;

void Urho3D_Node_SetWorldPosition(Urho3D_Node* self, const Urho3D_Vector3* newValue) URHO3D_API;

void Urho3D_Node_GetRotation(Urho3D_Node* self, Urho3D_Quaternion* value) URHO3D_API;

void Urho3D_Node_SetRotation(Urho3D_Node* self, const Urho3D_Quaternion* newValue) URHO3D_API;

void Urho3D_Node_GetWorldRotation(Urho3D_Node* self, Urho3D_Quaternion* value) URHO3D_API;

void Urho3D_Node_SetWorldRotation(Urho3D_Node* self, const Urho3D_Quaternion* newValue) URHO3D_API;

void Urho3D_Node_GetScale(Urho3D_Node* self, Urho3D_Vector3* value) URHO3D_API;

void Urho3D_Node_SetScale(Urho3D_Node* self, const Urho3D_Vector3* newValue) URHO3D_API;

const char* Urho3D_Node_GetName(Urho3D_Node* self) URHO3D_API;

void Urho3D_Node_SetName(Urho3D_Node* self, const char* newValue) URHO3D_API;

void Urho3D_Node_AddChild(Urho3D_Node* self, Urho3D_Node* node) URHO3D_API;

void Urho3D_Node_Pitch(Urho3D_Node* self, float angle) URHO3D_API;

void Urho3D_Node_Remove(Urho3D_Node* self) URHO3D_API;

void Urho3D_Node_Roll(Urho3D_Node* self, float angle) URHO3D_API;

void Urho3D_Node_Yaw(Urho3D_Node* self, float angle) URHO3D_API;

Urho3D_Octree* Urho3D_Octree_New(Urho3D_Context* context) URHO3D_API;

Urho3D_PhysicsWorld* Urho3D_PhysicsWorld_New(Urho3D_Context* context) URHO3D_API;

Urho3D_RigidBody* Urho3D_RigidBody_New(Urho3D_Context* context) URHO3D_API;

Urho3D_PhysicsWorld* Urho3D_RigidBody_GetPhysicsWorld(Urho3D_RigidBody* self) URHO3D_API;

float Urho3D_RigidBody_GetMass(Urho3D_RigidBody* self) URHO3D_API;

void Urho3D_RigidBody_SetMass(Urho3D_RigidBody* self, float newValue) URHO3D_API;

bool Urho3D_RigidBody_IsKinematic(Urho3D_RigidBody* self) URHO3D_API;

void Urho3D_RigidBody_SetKinematic(Urho3D_RigidBody* self, bool newValue) URHO3D_API;

bool Urho3D_RigidBody_IsTrigger(Urho3D_RigidBody* self) URHO3D_API;

void Urho3D_RigidBody_SetTrigger(Urho3D_RigidBody* self, bool newValue) URHO3D_API;

void Urho3D_RigidBody_ApplyForce(Urho3D_RigidBody* self, const Urho3D_Vector3* force) URHO3D_API;

void Urho3D_RigidBody_ApplyImpulse(Urho3D_RigidBody* self, const Urho3D_Vector3* impulse) URHO3D_API;

Urho3D_StaticModel* Urho3D_StaticModel_New(Urho3D_Context* context) URHO3D_API;

Urho3D_Model* Urho3D_StaticModel_GetModel(Urho3D_StaticModel* self) URHO3D_API;

void Urho3D_StaticModel_SetModel(Urho3D_StaticModel* self, Urho3D_Model* newValue) URHO3D_API;

Urho3D_Material* Urho3D_StaticModel_GetMaterial(Urho3D_StaticModel* self) URHO3D_API;

void Urho3D_StaticModel_SetMaterial(Urho3D_StaticModel* self, Urho3D_Material* newValue) URHO3D_API;

const char* Urho3D_Text_GetText(Urho3D_Text* self) URHO3D_API;

void Urho3D_Text_SetText(Urho3D_Text* self, const char* newValue) URHO3D_API;

void Urho3D_Text_SetFont(Urho3D_Text* self, Urho3D_Font* font, int size) URHO3D_API;

Urho3D_UIElement* Urho3D_UI_GetRoot(Urho3D_UI* self) URHO3D_API;

void Urho3D_UIElement_GetPosition(Urho3D_UIElement* self, Urho3D_IntVector2* value) URHO3D_API;

void Urho3D_UIElement_SetPosition(Urho3D_UIElement* self, const Urho3D_IntVector2* newValue) URHO3D_API;

void Urho3D_UIElement_AddChild(Urho3D_UIElement* self, Urho3D_UIElement* child) URHO3D_API;

