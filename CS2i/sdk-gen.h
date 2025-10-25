#pragma once

#include "sdk.h"

namespace CS2 {
#pragma region Declarations
class C_CSGO_TeamIntroCharacterPosition;
class C_FireCrackerBlast;
class CCSGO_WingmanIntroCounterTerroristPosition;
class CPulseCell_WaitForCursorsWithTag;
class CCSPlayer_PingServices;
class CEconItemAttribute;
class CBaseTriggerAPI;
class PredictedDamageTag_t;
class CFuncRetakeBarrier;
class C_EnvWindShared;
class C_SkyCamera;
class CPulseCell_Base;
class C_FuncRotating;
class C_SoundOpvarSetPointBase;
class C_EnvCubemapFog;
class C_CSGO_TeamSelectTerroristPosition;
class C_EnvParticleGlow;
class CCS_PortraitWorldCallbackHandler;
class CCSPlayerController_InventoryServices;
class CPulse_ResumePoint;
class CTriggerFan;
class C_HostageCarriableProp;
class C_BulletHitModel;
class C_FuncElectrifiedVolume;
class C_MapVetoPickController;
class C_EnvVolumetricFogVolume;
class C_CSGO_EndOfMatchCharacterPosition;
class CPulseCell_PlaySequence;
class C_BaseEntityAPI {};
class C_BarnLight;
class CPulseCell_LerpCameraSettings;
class CPointOffScreenIndicatorUi;
class CCSObserver_UseServices;
class C_PostProcessingVolume;
class CCSPlayer_UseServices;
class C_CSGO_CounterTerroristWingmanIntroCamera;
class CPulseCell_PickBestOutflowSelector;
class CInfoFan;
class C_VoteController;
class C_CSPlayerPawnBase;
class C_C4;
class C_BreakableProp;
class CCSGO_WingmanIntroTerroristPosition;
class CPrecipitationVData;
class C_RetakeGameRules;
class CPulseCell_WaitForObservable;
class C_SoundAreaEntitySphere;
class CPulseCell_Step_EntFire;
class C_WeaponAWP;
class C_BaseButton;
class CCSObserver_ObserverServices;
class CHitboxComponent;
class C_CSMinimapBoundary;
class CPathQueryComponent;
class C_Precipitation;
class CLogicRelay;
class SequenceHistory_t;
class CPlayer_ItemServices {};
class CPulse_OutflowConnection;
class C_WeaponUMP45;
class C_WeaponG3SG1;
class C_SpotlightEnd;
class C_Fish;
class C_WeaponFamas;
class C_EnvVolumetricFogController;
class CPulseGraphDef;
class C_EnvDetailController;
class C_EnvWindVolume;
class CBasePlayerControllerAPI;
class CHostageRescueZoneShim;
class CEnvSoundscapeAlias_snd_soundscape;
class CCSPlayer_HostageServices;
class C_GameRulesProxy {};
class CRenderComponent;
class C_Team;
class C_PathParticleRopeAlias_path_particle_rope_clientside;
class CPointChildModifier;
class C_WeaponNOVA;
class C_DEagle;
class C_CS2HudModelAddon;
class C_TriggerMultiple;
class C_CSGO_TeamPreviewCamera;
class C_ColorCorrectionVolume;
class CPlayer_MovementServices;
class CInfoDynamicShadowHintBox;
class CBaseAnimGraphController;
class C_ColorCorrection;
class CBuoyancyHelper;
class C_PhysBox;
class CCSPlayer_CameraServices;
class CFilterMultiple;
class CPulseCell_FireCursors;
class CEnvSoundscape;
class C_SoundEventEntityAlias_snd_event_point;
class C_FogController;
class C_SoundOpvarSetOBBWindEntity;
class C_MolotovGrenade;
class C_NetTestBaseCombatCharacter;
class CBodyComponentPoint;
class C_WeaponM4A1Silencer;
class C_EconItemView;
class CPulseCell_BaseRequirement;
class CPulseCell_BaseState;
class OutflowWithRequirements_t;
class CPulseCell_IsRequirementValid;
class C_SoundEventPathCornerEntity;
class C_InfoVisibilityBox;
class CCSPlayer_ItemServices;
class CPulseCell_Value_Gradient;
class IntervalTimer;
class audioparams_t;
class C_PathParticleRope;
class C_DecoyProjectile;
class C_AttributeContainer;
class C_CSWeaponBase;
class CTimeline;
class CPulseCursorFuncs;
class C_TonemapController2;
class CountdownTimer;
class C_WeaponMag7;
class WeaponPurchaseCount_t;
class CBasePulseGraphInstance;
class FilterHealth;
class C_PointClientUIHUD;
class CPulseCell_Inflow_GraphHook;
class SignatureOutflow_Resume;
class CPathSimpleAPI;
class C_InfoLadderDismount;
class C_PointCommentaryNode;
class CSpriteOriented;
class shard_model_desc_t;
class C_KeychainModule;
class CFuncWater;
class CCSPlayer_GlowServices;
class CCSGameModeRules;
class C_Flashbang;
class C_PointClientUIWorldTextPanel;
class CCSPlayer_WaterServices;
class C_CSObserverPawn;
class ViewAngleServerChange_t;
class C_FuncLadder;
class C_WeaponMP5SD;
class C_World;
class C_CSGO_TeamSelectCounterTerroristPosition;
class C_WeaponGalilAR;
class CCSPlayerBase_CameraServices;
class C_TeamplayRules;
class CPulseCell_Inflow_BaseEntrypoint;
class C_WeaponSG556;
class C_CSPlayerPawn;
class C_CSGO_TeamIntroTerroristPosition;
class CPulseCell_WaitForCursorsWithTagBase;
class C_Hostage;
class C_fogplayerparams_t;
class CGameSceneNode;
class CPlayer_ObserverServices;
class C_SoundAreaEntityBase;
class C_PlayerVisibility;
class C_BasePlayerWeapon;
class CRagdollManager;
class C_HEGrenade;
class C_EnvSky;
class CPulse_InvokeBinding;
class C_EnvWindController;
class C_GameRules;
class C_WeaponMAC10;
class C_CSGO_MapPreviewCameraPath;
class C_PointWorldText;
class C_RopeKeyframe;
class C_BaseToggle {};
class C_EnvCubemapBox;
class C_EnvCombinedLightProbeVolumeAlias_func_combined_light_probe_volume;
class CInfoDynamicShadowHint;
class C_FuncMoveLinear;
class CServerOnlyModelEntity;
class C_CSGO_TeamSelectCamera;
class CPulseCell_IntervalTimer;
class C_WeaponXM1014;
class C_WorldModelGloves;
class C_PhysicsPropMultiplayer;
class C_SoundEventOBBEntity;
class CPulseTestScriptLib;
class CPulseCell_BaseLerp;
class C_WeaponAug;
class C_BasePropDoor;
class CNetworkedSequenceOperation;
class C_Item_Healthshot;
class CEntityInstance;
class CCSPlayer_BulletServices;
class C_SoundOpvarSetAutoRoomEntity;
class C_EnvCombinedLightProbeVolume;
class C_MultiplayRules;
class CPlayer_AutoaimServices;
class C_LightDirectionalEntity;
class ActiveModelConfig_t;
class C_WeaponSSG08;
class CPulseCell_Value_Curve;
class C_BasePlayerPawn;
class C_Chicken;
class C_SoundOpvarSetAABBEntity;
class C_WeaponBizon;
class C_StattrakModule;
class CCSObserver_CameraServices;
class CTakeDamageInfoAPI;
class CEnvSoundscapeProxy;
class C_SoundEventEntity;
class CPulseCell_Inflow_EventHandler;
class C_LightOrthoEntity;
class CPulseCell_BaseFlow;
class CBombTarget;
class C_Knife;
class C_CSGO_TerroristWingmanIntroCamera;
class CSkeletonInstance;
class CEntityComponent {};
class C_ItemDogtags;
class C_LateUpdatedAnimating;
class CPulseAnimFuncs;
class C_BaseClientUIEntity;
class CPulseArraylib;
class C_WeaponUSPSilencer;
class C_MolotovProjectile;
class C_TriggerLerpObject;
class CPointTemplateAPI;
class C_WeaponRevolver;
class C_WeaponElite;
class C_DynamicPropAlias_cable_dynamic;
class CBaseProp;
class CInfoOffscreenPanoramaTexture;
class CCSWeaponBaseVData;
class CAttributeManager;
class SignatureOutflow_Continue;
class CInfoTarget;
class CPlayer_CameraServices;
class CPulseCell_Timeline;
class CPulseCell_Inflow_EntOutputHandler;
class C_BaseCSGrenade;
class CFilterAttributeInt;
class CPointTemplate;
class CPlayer_FlashlightServices;
class CCSPlayerController;
class C_CSGO_TeamIntroCounterTerroristPosition;
class C_CSGO_PreviewModel;
class C_CSGO_TeamSelectCharacterPosition;
class C_SoundEventAABBEntity;
class CCSPlayer_MovementServices;
class SellbackPurchaseEntry_t;
class C_TintController;
class C_WeaponBaseItem;
class CWaterSplasher;
class C_FuncBrush {};
class PhysicsRagdollPose_t;
class CPropDataComponent;
class C_WeaponCZ75a;
class C_DynamicLight;
class EngineCountdownTimer;
class C_SoundEventSphereEntity;
class CCSPlayerController_DamageServices;
class C_CSGO_TeamPreviewModel;
class C_TonemapController2Alias_env_tonemap_controller2;
class C_Inferno;
class CFilterLOS;
class CPointOrient;
class C_GlobalLight;
class C_EnvWindClientside;
class sky3dparams_t;
class C_FlashbangProjectile;
class CDestructiblePartsComponent;
class C_WeaponP90;
class C_EnvWind;
class C_CSGO_TerroristTeamIntroCamera;
class CPulseCell_Step_DebugLog;
class CCSPlayerController_ActionTrackingServices;
class CBodyComponentBaseAnimGraph;
class C_CSGO_PreviewModelAlias_csgo_item_previewmodel;
class C_InfoInstructorHintHostageRescueZone;
class CPulseCell_BaseYieldingInflow;
class PulseNodeDynamicOutflows_t;
class C_TriggerBuoyancy;
class CPlayer_MovementServices_Humanoid;
class C_WeaponTec9;
class C_PhysPropClientside;
class C_BaseDoor;
class CSMatchStats_t;
class EntityRenderAttribute_t;
class CPulseCell_Inflow_ObservableVariableListener;
class CFilterMultipleAPI;
class CHostageRescueZone;
class CModelState;
class CPulseCell_Outflow_CycleOrdered;
class C_CSWeaponBaseGun;
class C_CSGameRulesProxy;
class CCollisionProperty;
class C_WeaponP250;
class C_ShatterGlassShardPhysics;
class CFilterMassGreater;
class C_EntityDissolve;
class C_SoundOpvarSetOBBEntity;
class CCSGameModeRules_ArmsRace;
class C_FuncMonitor;
class C_ClientRagdoll;
class PulseSelectorOutflowList_t;
class CBodyComponentSkeletonInstance;
class C_CS2WeaponModuleBase {};
class C_CSGO_TeamPreviewCharacterPosition;
class C_SmokeGrenadeProjectile;
class CScriptComponent;
class CCSPlayer_BuyServices;
class C_PortraitWorldCallbackHandler;
class C_DynamicProp;
class C_CSTeam;
class C_CS2HudModelWeapon;
class C_TextureBasedAnimatable;
class C_LightEnvironmentEntity;
class CLogicRelayAPI;
class C_TriggerPhysics;
class C_PropDoorRotating;
class C_HandleTest;
class CInfoWorldLayer;
class CBodyComponentBaseModelEntity;
class C_Multimeter;
class FilterDamageType;
class CAttributeList;
class CPulseCell_Inflow_Wait;
class CFilterProximity;
class CEffectData;
class C_ParticleSystem;
class CPulseCell_Outflow_CycleShuffled;
class C_WeaponSCAR20;
class C_BaseFlex;
class C_FuncMover;
class CLightComponent;
class C_DecoyGrenade;
class C_WaterBullet;
class CCSPlayer_ActionTrackingServices;
class C_EnvCubemap;
class CCSObserver_MovementServices;
class CBodyComponent;
class CPulseCell_Inflow_Method;
class C_BaseCombatCharacter;
class CGlowProperty;
class C_PointClientUIDialog;
class CPulseCell_BaseValue;
class C_WeaponHKP2000;
class C_FootstepControl;
class CCitadelSoundOpvarSetOBB;
class C_CSGO_EndOfMatchLineupStart;
class CPlayer_WaterServices {};
class CPulseCell_BooleanSwitchState;
class CDamageRecord;
class VPhysicsCollisionAttribute_t;
class C_DynamicPropAlias_dynamic_prop;
class CEnvSoundscapeProxyAlias_snd_soundscape_proxy;
class C_OmniLight;
class C_SceneEntity;
class CPulseCell_Inflow_Yield;
class CPulseMathlib;
class C_NametagModule;
class C_EconEntity;
class CPlayer_UseServices;
class C_PointValueRemapper;
class CGameSceneNodeHandle;
class CPulseCell_Unknown;
class C_WeaponMP7;
class CSPerRoundStats_t;
class CPulseCell_Outflow_CycleRandom;
class CPulseCell_Step_PublicOutput;
class C_CS2HudModelBase;
class C_CSGameRules;
class CGrenadeTracer;
class CCSGameModeRules_Noop;
class CPulse_BlackboardReference;
class C_BaseCSGrenadeProjectile;
class C_GradientFog;
class CCSPlayerController_InGameMoneyServices;
class C_HEGrenadeProjectile;
class CAnimGraphNetworkedVariables;
class CFilterModel;
class C_SoundAreaEntityOrientedBox;
class C_SoundOpvarSetPointEntity;
class CPulseGameBlackboard;
class CPulseCell_Value_RandomInt;
class C_CSWeaponBaseShotgun;
class C_RagdollPropAttached;
class C_ModelPointEntity {};
class C_CSGO_PreviewPlayer;
class C_RectLight;
class CPathSimple;
class C_FuncTrackTrain;
class C_EconWearable;
class C_EnvDecal;
class EntitySpottedState_t;
class fogparams_t;
class C_WeaponM4A1;
class C_Item;
class C_CSPetPlacement;
class C_Beam;
class C_EnvLightProbeVolume;
class C_FuncConveyor;
class CCSPlayer_WeaponServices;
class C_PhysMagnet;
class CEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable;
class C_Breakable;
class C_PlantedC4;
class CCSGO_WingmanIntroCharacterPosition;
class CFilterName;
class C_RagdollProp;
class CPulse_CallInfo;
class C_MapPreviewParticleSystem;
class CBaseAnimGraph;
class CPulseCell_InlineNodeSkipSelector;
class C_LightEntity;
class C_WeaponM249;
class C_LocalTempEntity;
class C_WeaponTaser;
class C_PointEntity {};
class C_SingleplayRules;
class CLogicalEntity {};
class C_PrecipitationBlocker;
class C_CSGO_CounterTerroristTeamIntroCamera;
class C_SoundOpvarSetPathCornerEntity;
class CPlayer_WeaponServices;
class C_WeaponNegev;
class C_WeaponFiveSeven;
class C_WeaponSawedoff;
class C_TriggerVolume;
class CPulseCell_LimitCount;
class CPulseCell_Step_CallExternalMethod;
class C_WeaponMP9;
class C_DynamicPropAlias_prop_dynamic_override;
class CEnvSoundscapeTriggerable;
class C_PlayerPing;
class C_AK47;
class C_CSGO_MapPreviewCameraPathNode;
class C_CSPlayerResource;
class CSkyboxReference;
class C_IncendiaryGrenade;
class CFilterClass;
class C_PointCameraVFOV;
class C_PointCamera;
class CBaseFilter;
class WeaponPurchaseTracker_t;
class PulseObservableBoolExpression_t;
class CMapInfo;
class C_CSGO_EndOfMatchCamera;
class C_BaseGrenade;
class C_PlayerSprayDecal;
class CEntityIdentity; // Forward declaration only; full definition in sdk.h
class C_CS2HudModelArms;
class CBasePlayerVData;
class C_LightSpotEntity;
class CCSGameModeRules_Deathmatch;
class CPulseCell_CursorQueue;
class CPulseCell_Value_RandomFloat;
class CPulseExecCursor;
class C_Sprite;
class C_CsmFovOverride;
class C_WeaponGlock;
class C_PhysicsProp;
class CFilterTeam;
class CBasePlayerWeaponVData;
class C_CSGO_EndOfMatchLineupEnd;
class C_CSGO_PreviewPlayerAlias_csgo_player_previewmodel;
class C_SmokeGrenade;
class CInfoParticleTarget;
class CCSPlayer_DamageReactServices;
class C_PointClientUIWorldPanel;
class C_EntityFlame;
class CBasePlayerController;
class C_CSGO_EndOfMatchLineupEndpoint;

class PulseCursorCancelPriority_t;
class CPlayerPawnComponent {};
class CHandle;
using Vector = Vector3;
using VectorWS = Vector3;
class CUtlStringToken;
class PulseDocNodeID_t;
class CUtlSymbolLarge;
class Color;
class CPlayerControllerComponent {};
class C_UtlVectorEmbeddedNetworkVar;
class Quaternion;
class matrix3x4_t;
class ParticleIndex_t;
using CUtlString = const char*;
class QAngle;
class PointCameraSettings_t;
class PulseBestOutflowRules_t;
class CSPlayerState;
class C4LightEffect_t;
class CEntityIOOutput;
class CEntityOutputTemplate;
class PerformanceMode_t;
class BreakableContentsType_t;
class CResourceNameTyped;
class ParticleAttachment_t;
class ObserverInterpState_t;
class HSequence;
class AnimLoopMode_t;
class PulseSymbol_t;
class PulseRuntimeChunkIndex_t;
class PulseRegisterMap_t;
class CPulseValueFullType;
class CNetworkVarChainer;
class CInButtonState;
class CSkeletonAnimationController {};
class CNetworkedQuantizedFloat;
class SequenceFinishNotifyState_t;
class filter_t;
class CColorGradient;
class WorldGroupId_t;
class WeaponGameplayAnimState;
class CSWeaponMode;
class C_IronSightController;
class TimelineCompression_t;
class ShardSolid_t;
class Vector2D;
class CEntityHandle;
class FixAngleSet_t;
class loadout_slot_t;
class CSPlayerBlockingUseAction_t;
class CEntityIndex;
class AttachmentHandle_t;
class CTransformWS;
class CNetworkOriginCellCoordQuantizedVector;
class ObserverMode_t;
class PulseRuntimeCellIndex_t;
class PointWorldTextJustifyHorizontal_t;
class PointWorldTextJustifyVertical_t;
class PointWorldTextReorientMode_t;
class CBitVec;
class DoorState_t;
class HitGroup_t;
class CGlobalSymbol;
class RenderMode_t;
class RenderFx_t;
class DecalMode_t;
class CNetworkViewOffsetVector;
class CClientAlphaProperty;
class CNetworkTransmitComponent;
class TakeDamageFlags_t;
class EntityPlatformTypes_t;
class CNetworkVelocityVector;
class MoveCollide_t;
class MoveType_t;
class CParticleProperty;
class BloodType;
class ModelConfigHandle_t;
class CPiecewiseCurve;
class CTransform;
class CSWeaponType;
class CSWeaponCategory;
class gear_slot_t;
class CSWeaponSilencerType;
class CFiringModeFloat;
class CFiringModeInt;
class attributeprovidertypes_t;
class Color;
class PointTemplateClientOnlyEntityBehavior_t;
class PointTemplateOwnerSpawnGroupType_t;
class HSCRIPT;
class PointOrientGoalDirectionType_t;
class PointOrientConstraint_t;
class DamageTypes_t;
class Vector4D;
class PulseRuntimeBlackboardReferenceIndex_t;
class SolidType_t;
class SurroundingBoundsType_t;
class EntityDisolveType_t;
class CWeakHandle;
class SceneEventId_t;
class CUtlLeanVector;
class EKillTypes_t;
class ValueRemapperInputType_t;
class ValueRemapperOutputType_t;
class ValueRemapperHapticsType_t;
class ValueRemapperMomentumType_t;
class ValueRemapperRatchetType_t;
class KeyValues3;
class PulseRuntimeOutputIndex_t;
class CPlayerSlot;
class GrenadeType_t;
class BeamType_t;
class BeamClipStyle_t;
class PulseMethodCallMode_t;
class CPlayerSprayDecalRenderHelper;
class ChangeAccessorFieldPathIndex_t;
class CSkillFloat;
class CAttachmentNameSymbolWithStorage;
class ItemFlagTypes_t;
class AmmoIndex_t;
class RumbleEffect_t;
class CUtlOrderedMap;
class C_CommandContext;
class CSplitScreenSlot;
class PlayerConnectedState;
#pragma endregion


// Class: ActiveModelConfig_t (Size: 0x70)
class ActiveModelConfig_t {
public:
	SCHEMA(ModelConfigHandle_t, m_Handle, "m_Handle", "ActiveModelConfig_t", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_Name, "m_Name", "ActiveModelConfig_t", "client.dll");
	SCHEMA(CUtlVector< CHandle >, m_AssociatedEntities, "m_AssociatedEntities", "ActiveModelConfig_t", "client.dll");
	SCHEMA(CUtlVector< CUtlSymbolLarge >, m_AssociatedEntityNames, "m_AssociatedEntityNames", "ActiveModelConfig_t", "client.dll");
};

// Class: CAnimGraphNetworkedVariables (Size: 0x1490)
class CAnimGraphNetworkedVariables {
public:
	SCHEMA(CUtlVector< uint32 >, m_PredNetBoolVariables, "m_PredNetBoolVariables", "CAnimGraphNetworkedVariables", "client.dll");
	SCHEMA(CUtlVector< uint8 >, m_PredNetByteVariables, "m_PredNetByteVariables", "CAnimGraphNetworkedVariables", "client.dll");
	SCHEMA(CUtlVector< uint16 >, m_PredNetUInt16Variables, "m_PredNetUInt16Variables", "CAnimGraphNetworkedVariables", "client.dll");
	SCHEMA(CUtlVector< int32 >, m_PredNetIntVariables, "m_PredNetIntVariables", "CAnimGraphNetworkedVariables", "client.dll");
	SCHEMA(CUtlVector< uint32 >, m_PredNetUInt32Variables, "m_PredNetUInt32Variables", "CAnimGraphNetworkedVariables", "client.dll");
	SCHEMA(CUtlVector< uint64 >, m_PredNetUInt64Variables, "m_PredNetUInt64Variables", "CAnimGraphNetworkedVariables", "client.dll");
	SCHEMA(CUtlVector< float32 >, m_PredNetFloatVariables, "m_PredNetFloatVariables", "CAnimGraphNetworkedVariables", "client.dll");
	SCHEMA(CUtlVector< Vector >, m_PredNetVectorVariables, "m_PredNetVectorVariables", "CAnimGraphNetworkedVariables", "client.dll");
	SCHEMA(CUtlVector< Quaternion >, m_PredNetQuaternionVariables, "m_PredNetQuaternionVariables", "CAnimGraphNetworkedVariables", "client.dll");
	SCHEMA(CUtlVector< CGlobalSymbol >, m_PredNetGlobalSymbolVariables, "m_PredNetGlobalSymbolVariables", "CAnimGraphNetworkedVariables", "client.dll");
	SCHEMA(CUtlVector< uint32 >, m_OwnerOnlyPredNetBoolVariables, "m_OwnerOnlyPredNetBoolVariables", "CAnimGraphNetworkedVariables", "client.dll");
	SCHEMA(CUtlVector< uint8 >, m_OwnerOnlyPredNetByteVariables, "m_OwnerOnlyPredNetByteVariables", "CAnimGraphNetworkedVariables", "client.dll");
	SCHEMA(CUtlVector< uint16 >, m_OwnerOnlyPredNetUInt16Variables, "m_OwnerOnlyPredNetUInt16Variables", "CAnimGraphNetworkedVariables", "client.dll");
	SCHEMA(CUtlVector< int32 >, m_OwnerOnlyPredNetIntVariables, "m_OwnerOnlyPredNetIntVariables", "CAnimGraphNetworkedVariables", "client.dll");
	SCHEMA(CUtlVector< uint32 >, m_OwnerOnlyPredNetUInt32Variables, "m_OwnerOnlyPredNetUInt32Variables", "CAnimGraphNetworkedVariables", "client.dll");
	SCHEMA(CUtlVector< uint64 >, m_OwnerOnlyPredNetUInt64Variables, "m_OwnerOnlyPredNetUInt64Variables", "CAnimGraphNetworkedVariables", "client.dll");
	SCHEMA(CUtlVector< float32 >, m_OwnerOnlyPredNetFloatVariables, "m_OwnerOnlyPredNetFloatVariables", "CAnimGraphNetworkedVariables", "client.dll");
	SCHEMA(CUtlVector< Vector >, m_OwnerOnlyPredNetVectorVariables, "m_OwnerOnlyPredNetVectorVariables", "CAnimGraphNetworkedVariables", "client.dll");
	SCHEMA(CUtlVector< Quaternion >, m_OwnerOnlyPredNetQuaternionVariables, "m_OwnerOnlyPredNetQuaternionVariables", "CAnimGraphNetworkedVariables", "client.dll");
	SCHEMA(CUtlVector< CGlobalSymbol >, m_OwnerOnlyPredNetGlobalSymbolVariables, "m_OwnerOnlyPredNetGlobalSymbolVariables", "CAnimGraphNetworkedVariables", "client.dll");
	SCHEMA(int32, m_nBoolVariablesCount, "m_nBoolVariablesCount", "CAnimGraphNetworkedVariables", "client.dll");
	SCHEMA(int32, m_nOwnerOnlyBoolVariablesCount, "m_nOwnerOnlyBoolVariablesCount", "CAnimGraphNetworkedVariables", "client.dll");
	SCHEMA(int32, m_nRandomSeedOffset, "m_nRandomSeedOffset", "CAnimGraphNetworkedVariables", "client.dll");
	SCHEMA(float32, m_flLastTeleportTime, "m_flLastTeleportTime", "CAnimGraphNetworkedVariables", "client.dll");
};

// Class: CAttributeList (Size: 0x78)
class CAttributeList {
public:
	SCHEMA(CAttributeManager*, m_pManager, "m_pManager", "CAttributeList", "client.dll");
};

// Class: CAttributeManager (Size: 0x50)
class CAttributeManager {
public:
	class cached_attribute_float_t {
	public:
		SCHEMA(float32, flIn, "flIn", "CAttributeManager::cached_attribute_float_t", "client.dll");
		SCHEMA(CUtlSymbolLarge, iAttribHook, "iAttribHook", "CAttributeManager::cached_attribute_float_t", "client.dll");
		SCHEMA(float32, flOut, "flOut", "CAttributeManager::cached_attribute_float_t", "client.dll");
	};

	SCHEMA(CUtlVector< CHandle >, m_Providers, "m_Providers", "CAttributeManager", "client.dll");
	SCHEMA(int32, m_iReapplyProvisionParity, "m_iReapplyProvisionParity", "CAttributeManager", "client.dll");
	SCHEMA(CHandle, m_hOuter, "m_hOuter", "CAttributeManager", "client.dll");
	SCHEMA(bool, m_bPreventLoopback, "m_bPreventLoopback", "CAttributeManager", "client.dll");
	SCHEMA(attributeprovidertypes_t, m_ProviderType, "m_ProviderType", "CAttributeManager", "client.dll");
	SCHEMA(CUtlVector< CAttributeManager::cached_attribute_float_t >, m_CachedResults, "m_CachedResults", "CAttributeManager", "client.dll");
};

// Class: CBaseAnimGraphController (Size: 0x1A90)
class CBaseAnimGraphController : public CSkeletonAnimationController {
public:
	SCHEMA(CAnimGraphNetworkedVariables, m_animGraphNetworkedVars, "m_animGraphNetworkedVars", "CBaseAnimGraphController", "client.dll");
	SCHEMA(bool, m_bSequenceFinished, "m_bSequenceFinished", "CBaseAnimGraphController", "client.dll");
	SCHEMA(float32, m_flSoundSyncTime, "m_flSoundSyncTime", "CBaseAnimGraphController", "client.dll");
	SCHEMA(uint32, m_nActiveIKChainMask, "m_nActiveIKChainMask", "CBaseAnimGraphController", "client.dll");
	SCHEMA(HSequence, m_hSequence, "m_hSequence", "CBaseAnimGraphController", "client.dll");
	SCHEMA(GameTime_t, m_flSeqStartTime, "m_flSeqStartTime", "CBaseAnimGraphController", "client.dll");
	SCHEMA(float32, m_flSeqFixedCycle, "m_flSeqFixedCycle", "CBaseAnimGraphController", "client.dll");
	SCHEMA(AnimLoopMode_t, m_nAnimLoopMode, "m_nAnimLoopMode", "CBaseAnimGraphController", "client.dll");
	SCHEMA(CNetworkedQuantizedFloat, m_flPlaybackRate, "m_flPlaybackRate", "CBaseAnimGraphController", "client.dll");
	SCHEMA(SequenceFinishNotifyState_t, m_nNotifyState, "m_nNotifyState", "CBaseAnimGraphController", "client.dll");
	SCHEMA(bool, m_bNetworkedAnimationInputsChanged, "m_bNetworkedAnimationInputsChanged", "CBaseAnimGraphController", "client.dll");
	SCHEMA(bool, m_bNetworkedSequenceChanged, "m_bNetworkedSequenceChanged", "CBaseAnimGraphController", "client.dll");
	SCHEMA(bool, m_bLastUpdateSkipped, "m_bLastUpdateSkipped", "CBaseAnimGraphController", "client.dll");
	SCHEMA(GameTime_t, m_flPrevAnimUpdateTime, "m_flPrevAnimUpdateTime", "CBaseAnimGraphController", "client.dll");
	SCHEMA(bool, m_bIsUsingAG2, "m_bIsUsingAG2", "CBaseAnimGraphController", "client.dll");
	SCHEMA(CUtlVector< uint8 >, m_serializedPoseRecipeAG2, "m_serializedPoseRecipeAG2", "CBaseAnimGraphController", "client.dll");
	SCHEMA(int32, m_nSerializePoseRecipeSizeAG2, "m_nSerializePoseRecipeSizeAG2", "CBaseAnimGraphController", "client.dll");
	SCHEMA(int32, m_nSerializePoseRecipeVersionAG2, "m_nSerializePoseRecipeVersionAG2", "CBaseAnimGraphController", "client.dll");
	SCHEMA(uint8, m_nGraphCreationFlagsAG2, "m_nGraphCreationFlagsAG2", "CBaseAnimGraphController", "client.dll");
	SCHEMA(int32, m_nServerGraphDefReloadCountAG2, "m_nServerGraphDefReloadCountAG2", "CBaseAnimGraphController", "client.dll");
	SCHEMA(int32, m_nServerSerializationContextIteration, "m_nServerSerializationContextIteration", "CBaseAnimGraphController", "client.dll");
};

// Class: CBaseFilter (Size: 0x650)
class CBaseFilter : public CLogicalEntity {
public:
	SCHEMA(bool, m_bNegated, "m_bNegated", "CBaseFilter", "client.dll");
	SCHEMA(CEntityIOOutput, m_OnPass, "m_OnPass", "CBaseFilter", "client.dll");
	SCHEMA(CEntityIOOutput, m_OnFail, "m_OnFail", "CBaseFilter", "client.dll");
};

// Class: CBasePlayerVData (Size: 0x178)
class CBasePlayerVData {
public:
	SCHEMA(CSkillFloat, m_flHeadDamageMultiplier, "m_flHeadDamageMultiplier", "CBasePlayerVData", "client.dll");
	SCHEMA(CSkillFloat, m_flChestDamageMultiplier, "m_flChestDamageMultiplier", "CBasePlayerVData", "client.dll");
	SCHEMA(CSkillFloat, m_flStomachDamageMultiplier, "m_flStomachDamageMultiplier", "CBasePlayerVData", "client.dll");
	SCHEMA(CSkillFloat, m_flArmDamageMultiplier, "m_flArmDamageMultiplier", "CBasePlayerVData", "client.dll");
	SCHEMA(CSkillFloat, m_flLegDamageMultiplier, "m_flLegDamageMultiplier", "CBasePlayerVData", "client.dll");
	SCHEMA(float32, m_flHoldBreathTime, "m_flHoldBreathTime", "CBasePlayerVData", "client.dll");
	SCHEMA(float32, m_flDrowningDamageInterval, "m_flDrowningDamageInterval", "CBasePlayerVData", "client.dll");
	SCHEMA(int32, m_nDrowningDamageInitial, "m_nDrowningDamageInitial", "CBasePlayerVData", "client.dll");
	SCHEMA(int32, m_nDrowningDamageMax, "m_nDrowningDamageMax", "CBasePlayerVData", "client.dll");
	SCHEMA(int32, m_nWaterSpeed, "m_nWaterSpeed", "CBasePlayerVData", "client.dll");
	SCHEMA(float32, m_flUseRange, "m_flUseRange", "CBasePlayerVData", "client.dll");
	SCHEMA(float32, m_flUseAngleTolerance, "m_flUseAngleTolerance", "CBasePlayerVData", "client.dll");
	SCHEMA(float32, m_flCrouchTime, "m_flCrouchTime", "CBasePlayerVData", "client.dll");
};

// Class: CBasePlayerWeaponVData (Size: 0x440)
class CBasePlayerWeaponVData {
public:
	SCHEMA(bool, m_bBuiltRightHanded, "m_bBuiltRightHanded", "CBasePlayerWeaponVData", "client.dll");
	SCHEMA(bool, m_bAllowFlipping, "m_bAllowFlipping", "CBasePlayerWeaponVData", "client.dll");
	SCHEMA(CAttachmentNameSymbolWithStorage, m_sMuzzleAttachment, "m_sMuzzleAttachment", "CBasePlayerWeaponVData", "client.dll");
	SCHEMA(CUtlString, m_szMuzzleFlashParticleConfig, "m_szMuzzleFlashParticleConfig", "CBasePlayerWeaponVData", "client.dll");
	SCHEMA(uint8, m_nMuzzleSmokeShotThreshold, "m_nMuzzleSmokeShotThreshold", "CBasePlayerWeaponVData", "client.dll");
	SCHEMA(float32, m_flMuzzleSmokeTimeout, "m_flMuzzleSmokeTimeout", "CBasePlayerWeaponVData", "client.dll");
	SCHEMA(float32, m_flMuzzleSmokeDecrementRate, "m_flMuzzleSmokeDecrementRate", "CBasePlayerWeaponVData", "client.dll");
	SCHEMA(bool, m_bLinkedCooldowns, "m_bLinkedCooldowns", "CBasePlayerWeaponVData", "client.dll");
	SCHEMA(ItemFlagTypes_t, m_iFlags, "m_iFlags", "CBasePlayerWeaponVData", "client.dll");
	SCHEMA(AmmoIndex_t, m_nPrimaryAmmoType, "m_nPrimaryAmmoType", "CBasePlayerWeaponVData", "client.dll");
	SCHEMA(AmmoIndex_t, m_nSecondaryAmmoType, "m_nSecondaryAmmoType", "CBasePlayerWeaponVData", "client.dll");
	SCHEMA(int32, m_iMaxClip1, "m_iMaxClip1", "CBasePlayerWeaponVData", "client.dll");
	SCHEMA(int32, m_iMaxClip2, "m_iMaxClip2", "CBasePlayerWeaponVData", "client.dll");
	SCHEMA(int32, m_iDefaultClip1, "m_iDefaultClip1", "CBasePlayerWeaponVData", "client.dll");
	SCHEMA(int32, m_iDefaultClip2, "m_iDefaultClip2", "CBasePlayerWeaponVData", "client.dll");
	SCHEMA(bool, m_bReserveAmmoAsClips, "m_bReserveAmmoAsClips", "CBasePlayerWeaponVData", "client.dll");
	SCHEMA(bool, m_bTreatAsSingleClip, "m_bTreatAsSingleClip", "CBasePlayerWeaponVData", "client.dll");
	SCHEMA(bool, m_bKeepLoadedAmmo, "m_bKeepLoadedAmmo", "CBasePlayerWeaponVData", "client.dll");
	SCHEMA(int32, m_iWeight, "m_iWeight", "CBasePlayerWeaponVData", "client.dll");
	SCHEMA(bool, m_bAutoSwitchTo, "m_bAutoSwitchTo", "CBasePlayerWeaponVData", "client.dll");
	SCHEMA(bool, m_bAutoSwitchFrom, "m_bAutoSwitchFrom", "CBasePlayerWeaponVData", "client.dll");
	SCHEMA(RumbleEffect_t, m_iRumbleEffect, "m_iRumbleEffect", "CBasePlayerWeaponVData", "client.dll");
	SCHEMA(float32, m_flDropSpeed, "m_flDropSpeed", "CBasePlayerWeaponVData", "client.dll");
	SCHEMA(int32, m_iSlot, "m_iSlot", "CBasePlayerWeaponVData", "client.dll");
	SCHEMA(int32, m_iPosition, "m_iPosition", "CBasePlayerWeaponVData", "client.dll");
};

// Class: CBodyComponent (Size: 0x78)
class CBodyComponent : public CEntityComponent {
public:
	SCHEMA(CGameSceneNode*, m_pSceneNode, "m_pSceneNode", "CBodyComponent", "client.dll");
	SCHEMA(CNetworkVarChainer, __m_pChainEntity, "__m_pChainEntity", "CBodyComponent", "client.dll");
};

// Class: CBodyComponentPoint (Size: 0x200)
class CBodyComponentPoint : public CBodyComponent {
public:
	SCHEMA(CGameSceneNode, m_sceneNode, "m_sceneNode", "CBodyComponentPoint", "client.dll");
};

// Class: CBodyComponentSkeletonInstance (Size: 0x5B0)
class CBodyComponentSkeletonInstance : public CBodyComponent {
public:
	SCHEMA(CSkeletonInstance, m_skeletonInstance, "m_skeletonInstance", "CBodyComponentSkeletonInstance", "client.dll");
};

// Class: CBodyComponentBaseAnimGraph (Size: 0x2040)
class CBodyComponentBaseAnimGraph : public CBodyComponentSkeletonInstance {
public:
	SCHEMA(CBaseAnimGraphController, m_animationController, "m_animationController", "CBodyComponentBaseAnimGraph", "client.dll");
};

// Class: CBuoyancyHelper (Size: 0x118)
class CBuoyancyHelper {
public:
	SCHEMA(CUtlStringToken, m_nFluidType, "m_nFluidType", "CBuoyancyHelper", "client.dll");
	SCHEMA(float32, m_flFluidDensity, "m_flFluidDensity", "CBuoyancyHelper", "client.dll");
	SCHEMA(float32, m_flNeutrallyBuoyantGravity, "m_flNeutrallyBuoyantGravity", "CBuoyancyHelper", "client.dll");
	SCHEMA(float32, m_flNeutrallyBuoyantLinearDamping, "m_flNeutrallyBuoyantLinearDamping", "CBuoyancyHelper", "client.dll");
	SCHEMA(float32, m_flNeutrallyBuoyantAngularDamping, "m_flNeutrallyBuoyantAngularDamping", "CBuoyancyHelper", "client.dll");
	SCHEMA(bool, m_bNeutrallyBuoyant, "m_bNeutrallyBuoyant", "CBuoyancyHelper", "client.dll");
	SCHEMA(CUtlVector< float32 >, m_vecFractionOfWheelSubmergedForWheelFriction, "m_vecFractionOfWheelSubmergedForWheelFriction", "CBuoyancyHelper", "client.dll");
	SCHEMA(CUtlVector< float32 >, m_vecWheelFrictionScales, "m_vecWheelFrictionScales", "CBuoyancyHelper", "client.dll");
	SCHEMA(CUtlVector< float32 >, m_vecFractionOfWheelSubmergedForWheelDrag, "m_vecFractionOfWheelSubmergedForWheelDrag", "CBuoyancyHelper", "client.dll");
	SCHEMA(CUtlVector< float32 >, m_vecWheelDrag, "m_vecWheelDrag", "CBuoyancyHelper", "client.dll");
};

// Class: CCSGameModeRules (Size: 0x30)
class CCSGameModeRules {
public:
	SCHEMA(CNetworkVarChainer, __m_pChainEntity, "__m_pChainEntity", "CCSGameModeRules", "client.dll");
};

// Class: CCSGameModeRules_ArmsRace (Size: 0x48)
class CCSGameModeRules_ArmsRace {
public:
};

// Class: CCSGameModeRules_Deathmatch (Size: 0x40)
class CCSGameModeRules_Deathmatch {
public:
	SCHEMA(GameTime_t, m_flDMBonusStartTime, "m_flDMBonusStartTime", "CCSGameModeRules_Deathmatch", "client.dll");
	SCHEMA(float32, m_flDMBonusTimeLength, "m_flDMBonusTimeLength", "CCSGameModeRules_Deathmatch", "client.dll");
	SCHEMA(CUtlString, m_sDMBonusWeapon, "m_sDMBonusWeapon", "CCSGameModeRules_Deathmatch", "client.dll");
};

// Class: CCSPlayerController_ActionTrackingServices (Size: 0x138)
class CCSPlayerController_ActionTrackingServices : public CPlayerControllerComponent {
public:
	SCHEMA(CSMatchStats_t, m_matchStats, "m_matchStats", "CCSPlayerController_ActionTrackingServices", "client.dll");
	SCHEMA(int32, m_iNumRoundKills, "m_iNumRoundKills", "CCSPlayerController_ActionTrackingServices", "client.dll");
	SCHEMA(int32, m_iNumRoundKillsHeadshots, "m_iNumRoundKillsHeadshots", "CCSPlayerController_ActionTrackingServices", "client.dll");
	SCHEMA(float32, m_flTotalRoundDamageDealt, "m_flTotalRoundDamageDealt", "CCSPlayerController_ActionTrackingServices", "client.dll");
};

// Class: CCSPlayerController_DamageServices (Size: 0xB0)
class CCSPlayerController_DamageServices : public CPlayerControllerComponent {
public:
	SCHEMA(int32, m_nSendUpdate, "m_nSendUpdate", "CCSPlayerController_DamageServices", "client.dll");
};

// Class: CCSPlayerController_InGameMoneyServices (Size: 0x50)
class CCSPlayerController_InGameMoneyServices : public CPlayerControllerComponent {
public:
	SCHEMA(int32, m_iAccount, "m_iAccount", "CCSPlayerController_InGameMoneyServices", "client.dll");
	SCHEMA(int32, m_iStartAccount, "m_iStartAccount", "CCSPlayerController_InGameMoneyServices", "client.dll");
	SCHEMA(int32, m_iTotalCashSpent, "m_iTotalCashSpent", "CCSPlayerController_InGameMoneyServices", "client.dll");
	SCHEMA(int32, m_iCashSpentThisRound, "m_iCashSpentThisRound", "CCSPlayerController_InGameMoneyServices", "client.dll");
};

// Class: CCSPlayerController_InventoryServices (Size: 0xF0)
class CCSPlayerController_InventoryServices : public CPlayerControllerComponent {
public:
	class NetworkedLoadoutSlot_t {
	public:
		SCHEMA(C_EconItemView*, pItem, "pItem", "CCSPlayerController_InventoryServices::NetworkedLoadoutSlot_t", "client.dll");
		SCHEMA(uint16, team, "team", "CCSPlayerController_InventoryServices::NetworkedLoadoutSlot_t", "client.dll");
		SCHEMA(uint16, slot, "slot", "CCSPlayerController_InventoryServices::NetworkedLoadoutSlot_t", "client.dll");
	};

	SCHEMA(CUtlVector< CCSPlayerController_InventoryServices::NetworkedLoadoutSlot_t >, m_vecNetworkableLoadout, "m_vecNetworkableLoadout", "CCSPlayerController_InventoryServices", "client.dll");
	SCHEMA(uint16, m_unMusicID, "m_unMusicID", "CCSPlayerController_InventoryServices", "client.dll");
	SCHEMA(int32, m_nPersonaDataPublicLevel, "m_nPersonaDataPublicLevel", "CCSPlayerController_InventoryServices", "client.dll");
	SCHEMA(int32, m_nPersonaDataPublicCommendsLeader, "m_nPersonaDataPublicCommendsLeader", "CCSPlayerController_InventoryServices", "client.dll");
	SCHEMA(int32, m_nPersonaDataPublicCommendsTeacher, "m_nPersonaDataPublicCommendsTeacher", "CCSPlayerController_InventoryServices", "client.dll");
	SCHEMA(int32, m_nPersonaDataPublicCommendsFriendly, "m_nPersonaDataPublicCommendsFriendly", "CCSPlayerController_InventoryServices", "client.dll");
	SCHEMA(int32, m_nPersonaDataXpTrailLevel, "m_nPersonaDataXpTrailLevel", "CCSPlayerController_InventoryServices", "client.dll");
};

// Class: CCSPlayer_ActionTrackingServices (Size: 0x128)
class CCSPlayer_ActionTrackingServices : public CPlayerPawnComponent {
public:
	SCHEMA(CHandle, m_hLastWeaponBeforeC4AutoSwitch, "m_hLastWeaponBeforeC4AutoSwitch", "CCSPlayer_ActionTrackingServices", "client.dll");
	SCHEMA(bool, m_bIsRescuing, "m_bIsRescuing", "CCSPlayer_ActionTrackingServices", "client.dll");
	SCHEMA(WeaponPurchaseTracker_t, m_weaponPurchasesThisMatch, "m_weaponPurchasesThisMatch", "CCSPlayer_ActionTrackingServices", "client.dll");
	SCHEMA(WeaponPurchaseTracker_t, m_weaponPurchasesThisRound, "m_weaponPurchasesThisRound", "CCSPlayer_ActionTrackingServices", "client.dll");
};

// Class: CCSPlayer_BulletServices (Size: 0xA0)
class CCSPlayer_BulletServices : public CPlayerPawnComponent {
public:
	SCHEMA(int32, m_totalHitsOnServer, "m_totalHitsOnServer", "CCSPlayer_BulletServices", "client.dll");
};

// Class: CCSPlayer_BuyServices (Size: 0xA8)
class CCSPlayer_BuyServices : public CPlayerPawnComponent {
public:
};

// Class: CCSPlayer_HostageServices (Size: 0x48)
class CCSPlayer_HostageServices : public CPlayerPawnComponent {
public:
	SCHEMA(CHandle, m_hCarriedHostage, "m_hCarriedHostage", "CCSPlayer_HostageServices", "client.dll");
	SCHEMA(CHandle, m_hCarriedHostageProp, "m_hCarriedHostageProp", "CCSPlayer_HostageServices", "client.dll");
};

// Class: CCSPlayer_ItemServices (Size: 0x48)
class CCSPlayer_ItemServices : public CPlayer_ItemServices {
public:
	SCHEMA(bool, m_bHasDefuser, "m_bHasDefuser", "CCSPlayer_ItemServices", "client.dll");
	SCHEMA(bool, m_bHasHelmet, "m_bHasHelmet", "CCSPlayer_ItemServices", "client.dll");
};

// Class: CCSPlayer_PingServices (Size: 0x48)
class CCSPlayer_PingServices : public CPlayerPawnComponent {
public:
	SCHEMA(CHandle, m_hPlayerPing, "m_hPlayerPing", "CCSPlayer_PingServices", "client.dll");
};

// Class: CCSPlayer_WaterServices (Size: 0x68)
class CCSPlayer_WaterServices : public CPlayer_WaterServices {
public:
	SCHEMA(float32, m_flWaterJumpTime, "m_flWaterJumpTime", "CCSPlayer_WaterServices", "client.dll");
	SCHEMA(Vector, m_vecWaterJumpVel, "m_vecWaterJumpVel", "CCSPlayer_WaterServices", "client.dll");
	SCHEMA(float32, m_flSwimSoundTime, "m_flSwimSoundTime", "CCSPlayer_WaterServices", "client.dll");
};

// Class: CCSWeaponBaseVData (Size: 0x8A0)
class CCSWeaponBaseVData {
public:
	SCHEMA(CSWeaponType, m_WeaponType, "m_WeaponType", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(CSWeaponCategory, m_WeaponCategory, "m_WeaponCategory", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(Vector, m_vecMuzzlePos0, "m_vecMuzzlePos0", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(Vector, m_vecMuzzlePos1, "m_vecMuzzlePos1", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(gear_slot_t, m_GearSlot, "m_GearSlot", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(int32, m_GearSlotPosition, "m_GearSlotPosition", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(loadout_slot_t, m_DefaultLoadoutSlot, "m_DefaultLoadoutSlot", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(int32, m_nPrice, "m_nPrice", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(int32, m_nKillAward, "m_nKillAward", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(int32, m_nPrimaryReserveAmmoMax, "m_nPrimaryReserveAmmoMax", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(int32, m_nSecondaryReserveAmmoMax, "m_nSecondaryReserveAmmoMax", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(bool, m_bMeleeWeapon, "m_bMeleeWeapon", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(bool, m_bHasBurstMode, "m_bHasBurstMode", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(bool, m_bIsRevolver, "m_bIsRevolver", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(bool, m_bCannotShootUnderwater, "m_bCannotShootUnderwater", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(CGlobalSymbol, m_szName, "m_szName", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(CSWeaponSilencerType, m_eSilencerType, "m_eSilencerType", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(int32, m_nCrosshairMinDistance, "m_nCrosshairMinDistance", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(int32, m_nCrosshairDeltaDistance, "m_nCrosshairDeltaDistance", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(bool, m_bIsFullAuto, "m_bIsFullAuto", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(int32, m_nNumBullets, "m_nNumBullets", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(bool, m_bReloadsSingleShells, "m_bReloadsSingleShells", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(CFiringModeFloat, m_flCycleTime, "m_flCycleTime", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(CFiringModeFloat, m_flMaxSpeed, "m_flMaxSpeed", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(CFiringModeFloat, m_flSpread, "m_flSpread", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(CFiringModeFloat, m_flInaccuracyCrouch, "m_flInaccuracyCrouch", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(CFiringModeFloat, m_flInaccuracyStand, "m_flInaccuracyStand", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(CFiringModeFloat, m_flInaccuracyJump, "m_flInaccuracyJump", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(CFiringModeFloat, m_flInaccuracyLand, "m_flInaccuracyLand", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(CFiringModeFloat, m_flInaccuracyLadder, "m_flInaccuracyLadder", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(CFiringModeFloat, m_flInaccuracyFire, "m_flInaccuracyFire", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(CFiringModeFloat, m_flInaccuracyMove, "m_flInaccuracyMove", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(CFiringModeFloat, m_flRecoilAngle, "m_flRecoilAngle", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(CFiringModeFloat, m_flRecoilAngleVariance, "m_flRecoilAngleVariance", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(CFiringModeFloat, m_flRecoilMagnitude, "m_flRecoilMagnitude", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(CFiringModeFloat, m_flRecoilMagnitudeVariance, "m_flRecoilMagnitudeVariance", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(CFiringModeInt, m_nTracerFrequency, "m_nTracerFrequency", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(float32, m_flInaccuracyJumpInitial, "m_flInaccuracyJumpInitial", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(float32, m_flInaccuracyJumpApex, "m_flInaccuracyJumpApex", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(float32, m_flInaccuracyReload, "m_flInaccuracyReload", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(float32, m_flDeployDuration, "m_flDeployDuration", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(float32, m_flDisallowAttackAfterReloadStartDuration, "m_flDisallowAttackAfterReloadStartDuration", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(int32, m_nBurstShotCount, "m_nBurstShotCount", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(bool, m_bAllowBurstHolster, "m_bAllowBurstHolster", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(int32, m_nRecoilSeed, "m_nRecoilSeed", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(int32, m_nSpreadSeed, "m_nSpreadSeed", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(float32, m_flAttackMovespeedFactor, "m_flAttackMovespeedFactor", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(float32, m_flInaccuracyPitchShift, "m_flInaccuracyPitchShift", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(float32, m_flInaccuracyAltSoundThreshold, "m_flInaccuracyAltSoundThreshold", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(CUtlString, m_szUseRadioSubtitle, "m_szUseRadioSubtitle", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(bool, m_bUnzoomsAfterShot, "m_bUnzoomsAfterShot", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(bool, m_bHideViewModelWhenZoomed, "m_bHideViewModelWhenZoomed", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(int32, m_nZoomLevels, "m_nZoomLevels", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(int32, m_nZoomFOV1, "m_nZoomFOV1", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(int32, m_nZoomFOV2, "m_nZoomFOV2", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(float32, m_flZoomTime0, "m_flZoomTime0", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(float32, m_flZoomTime1, "m_flZoomTime1", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(float32, m_flZoomTime2, "m_flZoomTime2", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(float32, m_flIronSightPullUpSpeed, "m_flIronSightPullUpSpeed", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(float32, m_flIronSightPutDownSpeed, "m_flIronSightPutDownSpeed", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(float32, m_flIronSightFOV, "m_flIronSightFOV", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(float32, m_flIronSightPivotForward, "m_flIronSightPivotForward", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(float32, m_flIronSightLooseness, "m_flIronSightLooseness", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(int32, m_nDamage, "m_nDamage", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(float32, m_flHeadshotMultiplier, "m_flHeadshotMultiplier", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(float32, m_flArmorRatio, "m_flArmorRatio", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(float32, m_flPenetration, "m_flPenetration", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(float32, m_flRange, "m_flRange", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(float32, m_flRangeModifier, "m_flRangeModifier", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(float32, m_flFlinchVelocityModifierLarge, "m_flFlinchVelocityModifierLarge", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(float32, m_flFlinchVelocityModifierSmall, "m_flFlinchVelocityModifierSmall", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(float32, m_flRecoveryTimeCrouch, "m_flRecoveryTimeCrouch", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(float32, m_flRecoveryTimeStand, "m_flRecoveryTimeStand", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(float32, m_flRecoveryTimeCrouchFinal, "m_flRecoveryTimeCrouchFinal", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(float32, m_flRecoveryTimeStandFinal, "m_flRecoveryTimeStandFinal", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(int32, m_nRecoveryTransitionStartBullet, "m_nRecoveryTransitionStartBullet", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(int32, m_nRecoveryTransitionEndBullet, "m_nRecoveryTransitionEndBullet", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(float32, m_flThrowVelocity, "m_flThrowVelocity", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(Vector, m_vSmokeColor, "m_vSmokeColor", "CCSWeaponBaseVData", "client.dll");
	SCHEMA(CGlobalSymbol, m_szAnimClass, "m_szAnimClass", "CCSWeaponBaseVData", "client.dll");
};

// Class: CCollisionProperty (Size: 0xB0)
class CCollisionProperty {
public:
	SCHEMA(VPhysicsCollisionAttribute_t, m_collisionAttribute, "m_collisionAttribute", "CCollisionProperty", "client.dll");
	SCHEMA(Vector, m_vecMins, "m_vecMins", "CCollisionProperty", "client.dll");
	SCHEMA(Vector, m_vecMaxs, "m_vecMaxs", "CCollisionProperty", "client.dll");
	SCHEMA(uint8, m_usSolidFlags, "m_usSolidFlags", "CCollisionProperty", "client.dll");
	SCHEMA(SolidType_t, m_nSolidType, "m_nSolidType", "CCollisionProperty", "client.dll");
	SCHEMA(uint8, m_triggerBloat, "m_triggerBloat", "CCollisionProperty", "client.dll");
	SCHEMA(SurroundingBoundsType_t, m_nSurroundType, "m_nSurroundType", "CCollisionProperty", "client.dll");
	SCHEMA(uint8, m_CollisionGroup, "m_CollisionGroup", "CCollisionProperty", "client.dll");
	SCHEMA(uint8, m_nEnablePhysics, "m_nEnablePhysics", "CCollisionProperty", "client.dll");
	SCHEMA(float32, m_flBoundingRadius, "m_flBoundingRadius", "CCollisionProperty", "client.dll");
	SCHEMA(Vector, m_vecSpecifiedSurroundingMins, "m_vecSpecifiedSurroundingMins", "CCollisionProperty", "client.dll");
	SCHEMA(Vector, m_vecSpecifiedSurroundingMaxs, "m_vecSpecifiedSurroundingMaxs", "CCollisionProperty", "client.dll");
	SCHEMA(Vector, m_vecSurroundingMaxs, "m_vecSurroundingMaxs", "CCollisionProperty", "client.dll");
	SCHEMA(Vector, m_vecSurroundingMins, "m_vecSurroundingMins", "CCollisionProperty", "client.dll");
	SCHEMA(Vector, m_vCapsuleCenter1, "m_vCapsuleCenter1", "CCollisionProperty", "client.dll");
	SCHEMA(Vector, m_vCapsuleCenter2, "m_vCapsuleCenter2", "CCollisionProperty", "client.dll");
	SCHEMA(float32, m_flCapsuleRadius, "m_flCapsuleRadius", "CCollisionProperty", "client.dll");
};

// Class: CDamageRecord (Size: 0x78)
class CDamageRecord {
public:
	SCHEMA(CHandle, m_PlayerDamager, "m_PlayerDamager", "CDamageRecord", "client.dll");
	SCHEMA(CHandle, m_PlayerRecipient, "m_PlayerRecipient", "CDamageRecord", "client.dll");
	SCHEMA(CHandle, m_hPlayerControllerDamager, "m_hPlayerControllerDamager", "CDamageRecord", "client.dll");
	SCHEMA(CHandle, m_hPlayerControllerRecipient, "m_hPlayerControllerRecipient", "CDamageRecord", "client.dll");
	SCHEMA(CUtlString, m_szPlayerDamagerName, "m_szPlayerDamagerName", "CDamageRecord", "client.dll");
	SCHEMA(CUtlString, m_szPlayerRecipientName, "m_szPlayerRecipientName", "CDamageRecord", "client.dll");
	SCHEMA(uint64, m_DamagerXuid, "m_DamagerXuid", "CDamageRecord", "client.dll");
	SCHEMA(uint64, m_RecipientXuid, "m_RecipientXuid", "CDamageRecord", "client.dll");
	SCHEMA(float32, m_flBulletsDamage, "m_flBulletsDamage", "CDamageRecord", "client.dll");
	SCHEMA(float32, m_flDamage, "m_flDamage", "CDamageRecord", "client.dll");
	SCHEMA(float32, m_flActualHealthRemoved, "m_flActualHealthRemoved", "CDamageRecord", "client.dll");
	SCHEMA(int32, m_iNumHits, "m_iNumHits", "CDamageRecord", "client.dll");
	SCHEMA(int32, m_iLastBulletUpdate, "m_iLastBulletUpdate", "CDamageRecord", "client.dll");
	SCHEMA(bool, m_bIsOtherEnemy, "m_bIsOtherEnemy", "CDamageRecord", "client.dll");
	SCHEMA(EKillTypes_t, m_killType, "m_killType", "CDamageRecord", "client.dll");
};

// Class: CDestructiblePartsComponent (Size: 0x68)
class CDestructiblePartsComponent {
public:
	SCHEMA(CNetworkVarChainer, __m_pChainEntity, "__m_pChainEntity", "CDestructiblePartsComponent", "client.dll");
	SCHEMA(CUtlVector< uint16 >, m_vecDamageTakenByHitGroup, "m_vecDamageTakenByHitGroup", "CDestructiblePartsComponent", "client.dll");
	SCHEMA(CHandle, m_hOwner, "m_hOwner", "CDestructiblePartsComponent", "client.dll");
	SCHEMA(int32, m_nLastHitDamageLevel, "m_nLastHitDamageLevel", "CDestructiblePartsComponent", "client.dll");
};

// Class: CEconItemAttribute (Size: 0x48)
class CEconItemAttribute {
public:
	SCHEMA(uint16, m_iAttributeDefinitionIndex, "m_iAttributeDefinitionIndex", "CEconItemAttribute", "client.dll");
	SCHEMA(float32, m_flValue, "m_flValue", "CEconItemAttribute", "client.dll");
	SCHEMA(float32, m_flInitialValue, "m_flInitialValue", "CEconItemAttribute", "client.dll");
	SCHEMA(int32, m_nRefundableCurrency, "m_nRefundableCurrency", "CEconItemAttribute", "client.dll");
	SCHEMA(bool, m_bSetBonus, "m_bSetBonus", "CEconItemAttribute", "client.dll");
};

// Class: CEffectData (Size: 0x78)
class CEffectData {
public:
	SCHEMA(VectorWS, m_vOrigin, "m_vOrigin", "CEffectData", "client.dll");
	SCHEMA(VectorWS, m_vStart, "m_vStart", "CEffectData", "client.dll");
	SCHEMA(Vector, m_vNormal, "m_vNormal", "CEffectData", "client.dll");
	SCHEMA(QAngle, m_vAngles, "m_vAngles", "CEffectData", "client.dll");
	SCHEMA(CEntityHandle, m_hEntity, "m_hEntity", "CEffectData", "client.dll");
	SCHEMA(CEntityHandle, m_hOtherEntity, "m_hOtherEntity", "CEffectData", "client.dll");
	SCHEMA(float32, m_flScale, "m_flScale", "CEffectData", "client.dll");
	SCHEMA(float32, m_flMagnitude, "m_flMagnitude", "CEffectData", "client.dll");
	SCHEMA(float32, m_flRadius, "m_flRadius", "CEffectData", "client.dll");
	SCHEMA(CUtlStringToken, m_nSurfaceProp, "m_nSurfaceProp", "CEffectData", "client.dll");
	SCHEMA(uint32, m_nDamageType, "m_nDamageType", "CEffectData", "client.dll");
	SCHEMA(uint8, m_nPenetrate, "m_nPenetrate", "CEffectData", "client.dll");
	SCHEMA(uint16, m_nMaterial, "m_nMaterial", "CEffectData", "client.dll");
	SCHEMA(int16, m_nHitBox, "m_nHitBox", "CEffectData", "client.dll");
	SCHEMA(uint8, m_nColor, "m_nColor", "CEffectData", "client.dll");
	SCHEMA(uint8, m_fFlags, "m_fFlags", "CEffectData", "client.dll");
	SCHEMA(AttachmentHandle_t, m_nAttachmentIndex, "m_nAttachmentIndex", "CEffectData", "client.dll");
	SCHEMA(CUtlStringToken, m_nAttachmentName, "m_nAttachmentName", "CEffectData", "client.dll");
	SCHEMA(uint16, m_iEffectName, "m_iEffectName", "CEffectData", "client.dll");
	SCHEMA(uint8, m_nExplosionType, "m_nExplosionType", "CEffectData", "client.dll");
};

// Class: CEntityInstance (Size: 0x38)
class CEntityInstance {
public:
	SCHEMA(CUtlSymbolLarge, m_iszPrivateVScripts, "m_iszPrivateVScripts", "CEntityInstance", "client.dll");
	SCHEMA(CEntityIdentity*, m_pEntity, "m_pEntity", "CEntityInstance", "client.dll");
	SCHEMA(CScriptComponent*, m_CScriptComponent, "m_CScriptComponent", "CEntityInstance", "client.dll");
};

// Class: CFilterAttributeInt (Size: 0x658)
class CFilterAttributeInt : public CBaseFilter {
public:
	SCHEMA(CUtlSymbolLarge, m_sAttributeName, "m_sAttributeName", "CFilterAttributeInt", "client.dll");
};

// Class: CFilterClass (Size: 0x658)
class CFilterClass : public CBaseFilter {
public:
	SCHEMA(CUtlSymbolLarge, m_iFilterClass, "m_iFilterClass", "CFilterClass", "client.dll");
};

// Class: CFilterMassGreater (Size: 0x658)
class CFilterMassGreater : public CBaseFilter {
public:
	SCHEMA(float32, m_fFilterMass, "m_fFilterMass", "CFilterMassGreater", "client.dll");
};

// Class: CFilterModel (Size: 0x658)
class CFilterModel : public CBaseFilter {
public:
	SCHEMA(CUtlSymbolLarge, m_iFilterModel, "m_iFilterModel", "CFilterModel", "client.dll");
};

// Class: CFilterMultiple (Size: 0x6D0)
class CFilterMultiple : public CBaseFilter {
public:
	SCHEMA(filter_t, m_nFilterType, "m_nFilterType", "CFilterMultiple", "client.dll");
	SCHEMA(CUtlSymbolLarge*, m_iFilterName, "m_iFilterName", "CFilterMultiple", "client.dll");
	SCHEMA(CHandle, m_hFilter, "m_hFilter", "CFilterMultiple", "client.dll");
};

// Class: CFilterName (Size: 0x658)
class CFilterName : public CBaseFilter {
public:
	SCHEMA(CUtlSymbolLarge, m_iFilterName, "m_iFilterName", "CFilterName", "client.dll");
};

// Class: CFilterProximity (Size: 0x658)
class CFilterProximity : public CBaseFilter {
public:
	SCHEMA(float32, m_flRadius, "m_flRadius", "CFilterProximity", "client.dll");
};

// Class: CFilterTeam (Size: 0x658)
class CFilterTeam : public CBaseFilter {
public:
	SCHEMA(int32, m_iFilterTeam, "m_iFilterTeam", "CFilterTeam", "client.dll");
};

// Class: CGameSceneNode (Size: 0x180)
class CGameSceneNode {
public:
	SCHEMA(CTransformWS, m_nodeToWorld, "m_nodeToWorld", "CGameSceneNode", "client.dll");
	SCHEMA(CEntityInstance*, m_pOwner, "m_pOwner", "CGameSceneNode", "client.dll");
	SCHEMA(CGameSceneNode*, m_pParent, "m_pParent", "CGameSceneNode", "client.dll");
	SCHEMA(CGameSceneNode*, m_pChild, "m_pChild", "CGameSceneNode", "client.dll");
	SCHEMA(CGameSceneNode*, m_pNextSibling, "m_pNextSibling", "CGameSceneNode", "client.dll");
	SCHEMA(CGameSceneNodeHandle, m_hParent, "m_hParent", "CGameSceneNode", "client.dll");
	SCHEMA(CNetworkOriginCellCoordQuantizedVector, m_vecOrigin, "m_vecOrigin", "CGameSceneNode", "client.dll");
	SCHEMA(QAngle, m_angRotation, "m_angRotation", "CGameSceneNode", "client.dll");
	SCHEMA(float32, m_flScale, "m_flScale", "CGameSceneNode", "client.dll");
	SCHEMA(VectorWS, m_vecAbsOrigin, "m_vecAbsOrigin", "CGameSceneNode", "client.dll");
	SCHEMA(QAngle, m_angAbsRotation, "m_angAbsRotation", "CGameSceneNode", "client.dll");
	SCHEMA(float32, m_flAbsScale, "m_flAbsScale", "CGameSceneNode", "client.dll");
	SCHEMA(Vector, m_vecWrappedLocalOrigin, "m_vecWrappedLocalOrigin", "CGameSceneNode", "client.dll");
	SCHEMA(QAngle, m_angWrappedLocalRotation, "m_angWrappedLocalRotation", "CGameSceneNode", "client.dll");
	SCHEMA(float32, m_flWrappedScale, "m_flWrappedScale", "CGameSceneNode", "client.dll");
	SCHEMA(int16, m_nParentAttachmentOrBone, "m_nParentAttachmentOrBone", "CGameSceneNode", "client.dll");
	SCHEMA(bool, m_bDebugAbsOriginChanges, "m_bDebugAbsOriginChanges", "CGameSceneNode", "client.dll");
	SCHEMA(bool, m_bDormant, "m_bDormant", "CGameSceneNode", "client.dll");
	SCHEMA(bool, m_bForceParentToBeNetworked, "m_bForceParentToBeNetworked", "CGameSceneNode", "client.dll");
	SCHEMA(bool, m_bDirtyHierarchy, "m_bDirtyHierarchy", "CGameSceneNode", "client.dll");
	SCHEMA(bool, m_bDirtyBoneMergeInfo, "m_bDirtyBoneMergeInfo", "CGameSceneNode", "client.dll");
	SCHEMA(bool, m_bNetworkedPositionChanged, "m_bNetworkedPositionChanged", "CGameSceneNode", "client.dll");
	SCHEMA(bool, m_bNetworkedAnglesChanged, "m_bNetworkedAnglesChanged", "CGameSceneNode", "client.dll");
	SCHEMA(bool, m_bNetworkedScaleChanged, "m_bNetworkedScaleChanged", "CGameSceneNode", "client.dll");
	SCHEMA(bool, m_bWillBeCallingPostDataUpdate, "m_bWillBeCallingPostDataUpdate", "CGameSceneNode", "client.dll");
	SCHEMA(bool, m_bBoneMergeFlex, "m_bBoneMergeFlex", "CGameSceneNode", "client.dll");
	SCHEMA(bool, m_nLatchAbsOrigin, "m_nLatchAbsOrigin", "CGameSceneNode", "client.dll");
	SCHEMA(bool, m_bDirtyBoneMergeBoneToRoot, "m_bDirtyBoneMergeBoneToRoot", "CGameSceneNode", "client.dll");
	SCHEMA(uint8, m_nHierarchicalDepth, "m_nHierarchicalDepth", "CGameSceneNode", "client.dll");
	SCHEMA(uint8, m_nHierarchyType, "m_nHierarchyType", "CGameSceneNode", "client.dll");
	SCHEMA(uint8, m_nDoNotSetAnimTimeInInvalidatePhysicsCount, "m_nDoNotSetAnimTimeInInvalidatePhysicsCount", "CGameSceneNode", "client.dll");
	SCHEMA(CUtlStringToken, m_name, "m_name", "CGameSceneNode", "client.dll");
	SCHEMA(CUtlStringToken, m_hierarchyAttachName, "m_hierarchyAttachName", "CGameSceneNode", "client.dll");
	SCHEMA(float32, m_flZOffset, "m_flZOffset", "CGameSceneNode", "client.dll");
	SCHEMA(float32, m_flClientLocalScale, "m_flClientLocalScale", "CGameSceneNode", "client.dll");
	SCHEMA(Vector, m_vRenderOrigin, "m_vRenderOrigin", "CGameSceneNode", "client.dll");
};

// Class: CGameSceneNodeHandle (Size: 0x10)
class CGameSceneNodeHandle {
public:
	SCHEMA(CEntityHandle, m_hOwner, "m_hOwner", "CGameSceneNodeHandle", "client.dll");
	SCHEMA(CUtlStringToken, m_name, "m_name", "CGameSceneNodeHandle", "client.dll");
};

// Class: CGlowProperty (Size: 0x58)
class CGlowProperty {
public:
	SCHEMA(Vector, m_fGlowColor, "m_fGlowColor", "CGlowProperty", "client.dll");
	SCHEMA(int32, m_iGlowType, "m_iGlowType", "CGlowProperty", "client.dll");
	SCHEMA(int32, m_iGlowTeam, "m_iGlowTeam", "CGlowProperty", "client.dll");
	SCHEMA(int32, m_nGlowRange, "m_nGlowRange", "CGlowProperty", "client.dll");
	SCHEMA(int32, m_nGlowRangeMin, "m_nGlowRangeMin", "CGlowProperty", "client.dll");
	SCHEMA(Color, m_glowColorOverride, "m_glowColorOverride", "CGlowProperty", "client.dll");
	SCHEMA(bool, m_bFlashing, "m_bFlashing", "CGlowProperty", "client.dll");
	SCHEMA(float32, m_flGlowTime, "m_flGlowTime", "CGlowProperty", "client.dll");
	SCHEMA(float32, m_flGlowStartTime, "m_flGlowStartTime", "CGlowProperty", "client.dll");
	SCHEMA(bool, m_bEligibleForScreenHighlight, "m_bEligibleForScreenHighlight", "CGlowProperty", "client.dll");
	SCHEMA(bool, m_bGlowing, "m_bGlowing", "CGlowProperty", "client.dll");
};

// Class: CHitboxComponent (Size: 0x18)
class CHitboxComponent : public CEntityComponent {
public:
	SCHEMA(float32, m_flBoundsExpandRadius, "m_flBoundsExpandRadius", "CHitboxComponent", "client.dll");
};

// Class: CInfoDynamicShadowHint (Size: 0x610)
class CInfoDynamicShadowHint : public C_PointEntity {
public:
	SCHEMA(bool, m_bDisabled, "m_bDisabled", "CInfoDynamicShadowHint", "client.dll");
	SCHEMA(float32, m_flRange, "m_flRange", "CInfoDynamicShadowHint", "client.dll");
	SCHEMA(int32, m_nImportance, "m_nImportance", "CInfoDynamicShadowHint", "client.dll");
	SCHEMA(int32, m_nLightChoice, "m_nLightChoice", "CInfoDynamicShadowHint", "client.dll");
	SCHEMA(CHandle, m_hLight, "m_hLight", "CInfoDynamicShadowHint", "client.dll");
};

// Class: CInfoDynamicShadowHintBox (Size: 0x628)
class CInfoDynamicShadowHintBox : public CInfoDynamicShadowHint {
public:
	SCHEMA(Vector, m_vBoxMins, "m_vBoxMins", "CInfoDynamicShadowHintBox", "client.dll");
	SCHEMA(Vector, m_vBoxMaxs, "m_vBoxMaxs", "CInfoDynamicShadowHintBox", "client.dll");
};

// Class: CInfoFan (Size: 0x650)
class CInfoFan : public C_PointEntity {
public:
	SCHEMA(float32, m_fFanForceMaxRadius, "m_fFanForceMaxRadius", "CInfoFan", "client.dll");
	SCHEMA(float32, m_fFanForceMinRadius, "m_fFanForceMinRadius", "CInfoFan", "client.dll");
	SCHEMA(float32, m_flCurveDistRange, "m_flCurveDistRange", "CInfoFan", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_FanForceCurveString, "m_FanForceCurveString", "CInfoFan", "client.dll");
};

// Class: CInfoOffscreenPanoramaTexture (Size: 0x7D8)
class CInfoOffscreenPanoramaTexture : public C_PointEntity {
public:
	SCHEMA(bool, m_bDisabled, "m_bDisabled", "CInfoOffscreenPanoramaTexture", "client.dll");
	SCHEMA(int32, m_nResolutionX, "m_nResolutionX", "CInfoOffscreenPanoramaTexture", "client.dll");
	SCHEMA(int32, m_nResolutionY, "m_nResolutionY", "CInfoOffscreenPanoramaTexture", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_szLayoutFileName, "m_szLayoutFileName", "CInfoOffscreenPanoramaTexture", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_RenderAttrName, "m_RenderAttrName", "CInfoOffscreenPanoramaTexture", "client.dll");
	SCHEMA(CUtlVector< CHandle >, m_TargetEntities, "m_TargetEntities", "CInfoOffscreenPanoramaTexture", "client.dll");
	SCHEMA(int32, m_nTargetChangeCount, "m_nTargetChangeCount", "CInfoOffscreenPanoramaTexture", "client.dll");
	SCHEMA(CUtlVector< CUtlSymbolLarge >, m_vecCSSClasses, "m_vecCSSClasses", "CInfoOffscreenPanoramaTexture", "client.dll");
	SCHEMA(bool, m_bCheckCSSClasses, "m_bCheckCSSClasses", "CInfoOffscreenPanoramaTexture", "client.dll");
};

// Class: CLightComponent (Size: 0x1E8)
class CLightComponent : public CEntityComponent {
public:
	SCHEMA(CNetworkVarChainer, __m_pChainEntity, "__m_pChainEntity", "CLightComponent", "client.dll");
	SCHEMA(Color, m_Color, "m_Color", "CLightComponent", "client.dll");
	SCHEMA(Color, m_SecondaryColor, "m_SecondaryColor", "CLightComponent", "client.dll");
	SCHEMA(float32, m_flBrightness, "m_flBrightness", "CLightComponent", "client.dll");
	SCHEMA(float32, m_flBrightnessScale, "m_flBrightnessScale", "CLightComponent", "client.dll");
	SCHEMA(float32, m_flBrightnessMult, "m_flBrightnessMult", "CLightComponent", "client.dll");
	SCHEMA(float32, m_flRange, "m_flRange", "CLightComponent", "client.dll");
	SCHEMA(float32, m_flFalloff, "m_flFalloff", "CLightComponent", "client.dll");
	SCHEMA(float32, m_flAttenuation0, "m_flAttenuation0", "CLightComponent", "client.dll");
	SCHEMA(float32, m_flAttenuation1, "m_flAttenuation1", "CLightComponent", "client.dll");
	SCHEMA(float32, m_flAttenuation2, "m_flAttenuation2", "CLightComponent", "client.dll");
	SCHEMA(float32, m_flTheta, "m_flTheta", "CLightComponent", "client.dll");
	SCHEMA(float32, m_flPhi, "m_flPhi", "CLightComponent", "client.dll");
	SCHEMA(int32, m_nCascades, "m_nCascades", "CLightComponent", "client.dll");
	SCHEMA(int32, m_nCastShadows, "m_nCastShadows", "CLightComponent", "client.dll");
	SCHEMA(int32, m_nShadowWidth, "m_nShadowWidth", "CLightComponent", "client.dll");
	SCHEMA(int32, m_nShadowHeight, "m_nShadowHeight", "CLightComponent", "client.dll");
	SCHEMA(bool, m_bRenderDiffuse, "m_bRenderDiffuse", "CLightComponent", "client.dll");
	SCHEMA(int32, m_nRenderSpecular, "m_nRenderSpecular", "CLightComponent", "client.dll");
	SCHEMA(bool, m_bRenderTransmissive, "m_bRenderTransmissive", "CLightComponent", "client.dll");
	SCHEMA(float32, m_flOrthoLightWidth, "m_flOrthoLightWidth", "CLightComponent", "client.dll");
	SCHEMA(float32, m_flOrthoLightHeight, "m_flOrthoLightHeight", "CLightComponent", "client.dll");
	SCHEMA(int32, m_nStyle, "m_nStyle", "CLightComponent", "client.dll");
	SCHEMA(CUtlString, m_Pattern, "m_Pattern", "CLightComponent", "client.dll");
	SCHEMA(int32, m_nCascadeRenderStaticObjects, "m_nCascadeRenderStaticObjects", "CLightComponent", "client.dll");
	SCHEMA(float32, m_flShadowCascadeCrossFade, "m_flShadowCascadeCrossFade", "CLightComponent", "client.dll");
	SCHEMA(float32, m_flShadowCascadeDistanceFade, "m_flShadowCascadeDistanceFade", "CLightComponent", "client.dll");
	SCHEMA(float32, m_flShadowCascadeDistance0, "m_flShadowCascadeDistance0", "CLightComponent", "client.dll");
	SCHEMA(float32, m_flShadowCascadeDistance1, "m_flShadowCascadeDistance1", "CLightComponent", "client.dll");
	SCHEMA(float32, m_flShadowCascadeDistance2, "m_flShadowCascadeDistance2", "CLightComponent", "client.dll");
	SCHEMA(float32, m_flShadowCascadeDistance3, "m_flShadowCascadeDistance3", "CLightComponent", "client.dll");
	SCHEMA(int32, m_nShadowCascadeResolution0, "m_nShadowCascadeResolution0", "CLightComponent", "client.dll");
	SCHEMA(int32, m_nShadowCascadeResolution1, "m_nShadowCascadeResolution1", "CLightComponent", "client.dll");
	SCHEMA(int32, m_nShadowCascadeResolution2, "m_nShadowCascadeResolution2", "CLightComponent", "client.dll");
	SCHEMA(int32, m_nShadowCascadeResolution3, "m_nShadowCascadeResolution3", "CLightComponent", "client.dll");
	SCHEMA(bool, m_bUsesBakedShadowing, "m_bUsesBakedShadowing", "CLightComponent", "client.dll");
	SCHEMA(int32, m_nShadowPriority, "m_nShadowPriority", "CLightComponent", "client.dll");
	SCHEMA(int32, m_nBakedShadowIndex, "m_nBakedShadowIndex", "CLightComponent", "client.dll");
	SCHEMA(int32, m_nLightPathUniqueId, "m_nLightPathUniqueId", "CLightComponent", "client.dll");
	SCHEMA(int32, m_nLightMapUniqueId, "m_nLightMapUniqueId", "CLightComponent", "client.dll");
	SCHEMA(bool, m_bRenderToCubemaps, "m_bRenderToCubemaps", "CLightComponent", "client.dll");
	SCHEMA(bool, m_bAllowSSTGeneration, "m_bAllowSSTGeneration", "CLightComponent", "client.dll");
	SCHEMA(int32, m_nDirectLight, "m_nDirectLight", "CLightComponent", "client.dll");
	SCHEMA(int32, m_nIndirectLight, "m_nIndirectLight", "CLightComponent", "client.dll");
	SCHEMA(float32, m_flFadeMinDist, "m_flFadeMinDist", "CLightComponent", "client.dll");
	SCHEMA(float32, m_flFadeMaxDist, "m_flFadeMaxDist", "CLightComponent", "client.dll");
	SCHEMA(float32, m_flShadowFadeMinDist, "m_flShadowFadeMinDist", "CLightComponent", "client.dll");
	SCHEMA(float32, m_flShadowFadeMaxDist, "m_flShadowFadeMaxDist", "CLightComponent", "client.dll");
	SCHEMA(bool, m_bEnabled, "m_bEnabled", "CLightComponent", "client.dll");
	SCHEMA(bool, m_bFlicker, "m_bFlicker", "CLightComponent", "client.dll");
	SCHEMA(bool, m_bPrecomputedFieldsValid, "m_bPrecomputedFieldsValid", "CLightComponent", "client.dll");
	SCHEMA(Vector, m_vPrecomputedBoundsMins, "m_vPrecomputedBoundsMins", "CLightComponent", "client.dll");
	SCHEMA(Vector, m_vPrecomputedBoundsMaxs, "m_vPrecomputedBoundsMaxs", "CLightComponent", "client.dll");
	SCHEMA(Vector, m_vPrecomputedOBBOrigin, "m_vPrecomputedOBBOrigin", "CLightComponent", "client.dll");
	SCHEMA(QAngle, m_vPrecomputedOBBAngles, "m_vPrecomputedOBBAngles", "CLightComponent", "client.dll");
	SCHEMA(Vector, m_vPrecomputedOBBExtent, "m_vPrecomputedOBBExtent", "CLightComponent", "client.dll");
	SCHEMA(float32, m_flPrecomputedMaxRange, "m_flPrecomputedMaxRange", "CLightComponent", "client.dll");
	SCHEMA(int32, m_nFogLightingMode, "m_nFogLightingMode", "CLightComponent", "client.dll");
	SCHEMA(float32, m_flFogContributionStength, "m_flFogContributionStength", "CLightComponent", "client.dll");
	SCHEMA(float32, m_flNearClipPlane, "m_flNearClipPlane", "CLightComponent", "client.dll");
	SCHEMA(Color, m_SkyColor, "m_SkyColor", "CLightComponent", "client.dll");
	SCHEMA(float32, m_flSkyIntensity, "m_flSkyIntensity", "CLightComponent", "client.dll");
	SCHEMA(Color, m_SkyAmbientBounce, "m_SkyAmbientBounce", "CLightComponent", "client.dll");
	SCHEMA(bool, m_bUseSecondaryColor, "m_bUseSecondaryColor", "CLightComponent", "client.dll");
	SCHEMA(bool, m_bMixedShadows, "m_bMixedShadows", "CLightComponent", "client.dll");
	SCHEMA(GameTime_t, m_flLightStyleStartTime, "m_flLightStyleStartTime", "CLightComponent", "client.dll");
	SCHEMA(float32, m_flCapsuleLength, "m_flCapsuleLength", "CLightComponent", "client.dll");
	SCHEMA(float32, m_flMinRoughness, "m_flMinRoughness", "CLightComponent", "client.dll");
};

// Class: CLogicRelay (Size: 0x600)
class CLogicRelay : public CLogicalEntity {
public:
	SCHEMA(bool, m_bDisabled, "m_bDisabled", "CLogicRelay", "client.dll");
	SCHEMA(bool, m_bWaitForRefire, "m_bWaitForRefire", "CLogicRelay", "client.dll");
	SCHEMA(bool, m_bTriggerOnce, "m_bTriggerOnce", "CLogicRelay", "client.dll");
	SCHEMA(bool, m_bFastRetrigger, "m_bFastRetrigger", "CLogicRelay", "client.dll");
	SCHEMA(bool, m_bPassthoughCaller, "m_bPassthoughCaller", "CLogicRelay", "client.dll");
};

// Class: CMapInfo (Size: 0x628)
class CMapInfo : public C_PointEntity {
public:
	SCHEMA(int32, m_iBuyingStatus, "m_iBuyingStatus", "CMapInfo", "client.dll");
	SCHEMA(float32, m_flBombRadius, "m_flBombRadius", "CMapInfo", "client.dll");
	SCHEMA(int32, m_iPetPopulation, "m_iPetPopulation", "CMapInfo", "client.dll");
	SCHEMA(bool, m_bUseNormalSpawnsForDM, "m_bUseNormalSpawnsForDM", "CMapInfo", "client.dll");
	SCHEMA(bool, m_bDisableAutoGeneratedDMSpawns, "m_bDisableAutoGeneratedDMSpawns", "CMapInfo", "client.dll");
	SCHEMA(float32, m_flBotMaxVisionDistance, "m_flBotMaxVisionDistance", "CMapInfo", "client.dll");
	SCHEMA(int32, m_iHostageCount, "m_iHostageCount", "CMapInfo", "client.dll");
	SCHEMA(bool, m_bFadePlayerVisibilityFarZ, "m_bFadePlayerVisibilityFarZ", "CMapInfo", "client.dll");
	SCHEMA(bool, m_bRainTraceToSkyEnabled, "m_bRainTraceToSkyEnabled", "CMapInfo", "client.dll");
	SCHEMA(float32, m_flEnvRainStrength, "m_flEnvRainStrength", "CMapInfo", "client.dll");
	SCHEMA(float32, m_flEnvPuddleRippleStrength, "m_flEnvPuddleRippleStrength", "CMapInfo", "client.dll");
	SCHEMA(float32, m_flEnvPuddleRippleDirection, "m_flEnvPuddleRippleDirection", "CMapInfo", "client.dll");
	SCHEMA(float32, m_flEnvWetnessCoverage, "m_flEnvWetnessCoverage", "CMapInfo", "client.dll");
	SCHEMA(float32, m_flEnvWetnessDryingAmount, "m_flEnvWetnessDryingAmount", "CMapInfo", "client.dll");
};

// Class: CModelState (Size: 0x300)
class CModelState {
public:
	SCHEMA(CUtlSymbolLarge, m_ModelName, "m_ModelName", "CModelState", "client.dll");
	SCHEMA(bool, m_bClientClothCreationSuppressed, "m_bClientClothCreationSuppressed", "CModelState", "client.dll");
	SCHEMA(uint64, m_MeshGroupMask, "m_MeshGroupMask", "CModelState", "client.dll");
	SCHEMA(CUtlVector< int32 >, m_nBodyGroupChoices, "m_nBodyGroupChoices", "CModelState", "client.dll");
	SCHEMA(int8, m_nIdealMotionType, "m_nIdealMotionType", "CModelState", "client.dll");
	SCHEMA(int8, m_nForceLOD, "m_nForceLOD", "CModelState", "client.dll");
	SCHEMA(int8, m_nClothUpdateFlags, "m_nClothUpdateFlags", "CModelState", "client.dll");
};

// Class: CNetworkedSequenceOperation (Size: 0x28)
class CNetworkedSequenceOperation {
public:
	SCHEMA(HSequence, m_hSequence, "m_hSequence", "CNetworkedSequenceOperation", "client.dll");
	SCHEMA(float32, m_flPrevCycle, "m_flPrevCycle", "CNetworkedSequenceOperation", "client.dll");
	SCHEMA(float32, m_flCycle, "m_flCycle", "CNetworkedSequenceOperation", "client.dll");
	SCHEMA(CNetworkedQuantizedFloat, m_flWeight, "m_flWeight", "CNetworkedSequenceOperation", "client.dll");
	SCHEMA(bool, m_bSequenceChangeNetworked, "m_bSequenceChangeNetworked", "CNetworkedSequenceOperation", "client.dll");
	SCHEMA(bool, m_bDiscontinuity, "m_bDiscontinuity", "CNetworkedSequenceOperation", "client.dll");
	SCHEMA(float32, m_flPrevCycleFromDiscontinuity, "m_flPrevCycleFromDiscontinuity", "CNetworkedSequenceOperation", "client.dll");
	SCHEMA(float32, m_flPrevCycleForAnimEventDetection, "m_flPrevCycleForAnimEventDetection", "CNetworkedSequenceOperation", "client.dll");
};

// Class: CPlayer_CameraServices (Size: 0x288)
class CPlayer_CameraServices : public CPlayerPawnComponent {
public:
	SCHEMA(QAngle, m_vecCsViewPunchAngle, "m_vecCsViewPunchAngle", "CPlayer_CameraServices", "client.dll");
	SCHEMA(GameTick_t, m_nCsViewPunchAngleTick, "m_nCsViewPunchAngleTick", "CPlayer_CameraServices", "client.dll");
	SCHEMA(float32, m_flCsViewPunchAngleTickRatio, "m_flCsViewPunchAngleTickRatio", "CPlayer_CameraServices", "client.dll");
	SCHEMA(C_fogplayerparams_t, m_PlayerFog, "m_PlayerFog", "CPlayer_CameraServices", "client.dll");
	SCHEMA(CHandle, m_hColorCorrectionCtrl, "m_hColorCorrectionCtrl", "CPlayer_CameraServices", "client.dll");
	SCHEMA(CHandle, m_hViewEntity, "m_hViewEntity", "CPlayer_CameraServices", "client.dll");
	SCHEMA(CHandle, m_hTonemapController, "m_hTonemapController", "CPlayer_CameraServices", "client.dll");
	SCHEMA(audioparams_t, m_audio, "m_audio", "CPlayer_CameraServices", "client.dll");
	SCHEMA(CUtlVector< CHandle >, m_PostProcessingVolumes, "m_PostProcessingVolumes", "CPlayer_CameraServices", "client.dll");
	SCHEMA(float32, m_flOldPlayerZ, "m_flOldPlayerZ", "CPlayer_CameraServices", "client.dll");
	SCHEMA(float32, m_flOldPlayerViewOffsetZ, "m_flOldPlayerViewOffsetZ", "CPlayer_CameraServices", "client.dll");
	SCHEMA(fogparams_t, m_CurrentFog, "m_CurrentFog", "CPlayer_CameraServices", "client.dll");
	SCHEMA(CHandle, m_hOldFogController, "m_hOldFogController", "CPlayer_CameraServices", "client.dll");
	SCHEMA(bool*, m_bOverrideFogColor, "m_bOverrideFogColor", "CPlayer_CameraServices", "client.dll");
	SCHEMA(Color*, m_OverrideFogColor, "m_OverrideFogColor", "CPlayer_CameraServices", "client.dll");
	SCHEMA(bool*, m_bOverrideFogStartEnd, "m_bOverrideFogStartEnd", "CPlayer_CameraServices", "client.dll");
	SCHEMA(float32*, m_fOverrideFogStart, "m_fOverrideFogStart", "CPlayer_CameraServices", "client.dll");
	SCHEMA(float32*, m_fOverrideFogEnd, "m_fOverrideFogEnd", "CPlayer_CameraServices", "client.dll");
	SCHEMA(CHandle, m_hActivePostProcessingVolume, "m_hActivePostProcessingVolume", "CPlayer_CameraServices", "client.dll");
	SCHEMA(QAngle, m_angDemoViewAngles, "m_angDemoViewAngles", "CPlayer_CameraServices", "client.dll");
};

// Class: CCSPlayerBase_CameraServices (Size: 0x2A0)
class CCSPlayerBase_CameraServices : public CPlayer_CameraServices {
public:
	SCHEMA(uint32, m_iFOV, "m_iFOV", "CCSPlayerBase_CameraServices", "client.dll");
	SCHEMA(uint32, m_iFOVStart, "m_iFOVStart", "CCSPlayerBase_CameraServices", "client.dll");
	SCHEMA(GameTime_t, m_flFOVTime, "m_flFOVTime", "CCSPlayerBase_CameraServices", "client.dll");
	SCHEMA(float32, m_flFOVRate, "m_flFOVRate", "CCSPlayerBase_CameraServices", "client.dll");
	SCHEMA(CHandle, m_hZoomOwner, "m_hZoomOwner", "CCSPlayerBase_CameraServices", "client.dll");
	SCHEMA(float32, m_flLastShotFOV, "m_flLastShotFOV", "CCSPlayerBase_CameraServices", "client.dll");
};

// Class: CCSPlayer_CameraServices (Size: 0x338)
class CCSPlayer_CameraServices : public CCSPlayerBase_CameraServices {
public:
	SCHEMA(float32, m_flDeathCamTilt, "m_flDeathCamTilt", "CCSPlayer_CameraServices", "client.dll");
	SCHEMA(Vector, m_vClientScopeInaccuracy, "m_vClientScopeInaccuracy", "CCSPlayer_CameraServices", "client.dll");
};

// Class: CPlayer_MovementServices (Size: 0x238)
class CPlayer_MovementServices : public CPlayerPawnComponent {
public:
	SCHEMA(int32, m_nImpulse, "m_nImpulse", "CPlayer_MovementServices", "client.dll");
	SCHEMA(CInButtonState, m_nButtons, "m_nButtons", "CPlayer_MovementServices", "client.dll");
	SCHEMA(uint64, m_nQueuedButtonDownMask, "m_nQueuedButtonDownMask", "CPlayer_MovementServices", "client.dll");
	SCHEMA(uint64, m_nQueuedButtonChangeMask, "m_nQueuedButtonChangeMask", "CPlayer_MovementServices", "client.dll");
	SCHEMA(uint64, m_nButtonDoublePressed, "m_nButtonDoublePressed", "CPlayer_MovementServices", "client.dll");
	SCHEMA(uint32*, m_pButtonPressedCmdNumber, "m_pButtonPressedCmdNumber", "CPlayer_MovementServices", "client.dll");
	SCHEMA(uint32, m_nLastCommandNumberProcessed, "m_nLastCommandNumberProcessed", "CPlayer_MovementServices", "client.dll");
	SCHEMA(uint64, m_nToggleButtonDownMask, "m_nToggleButtonDownMask", "CPlayer_MovementServices", "client.dll");
	SCHEMA(float32, m_flMaxspeed, "m_flMaxspeed", "CPlayer_MovementServices", "client.dll");
	SCHEMA(float32*, m_arrForceSubtickMoveWhen, "m_arrForceSubtickMoveWhen", "CPlayer_MovementServices", "client.dll");
	SCHEMA(float32, m_flForwardMove, "m_flForwardMove", "CPlayer_MovementServices", "client.dll");
	SCHEMA(float32, m_flLeftMove, "m_flLeftMove", "CPlayer_MovementServices", "client.dll");
	SCHEMA(float32, m_flUpMove, "m_flUpMove", "CPlayer_MovementServices", "client.dll");
	SCHEMA(Vector, m_vecLastMovementImpulses, "m_vecLastMovementImpulses", "CPlayer_MovementServices", "client.dll");
	SCHEMA(QAngle, m_vecOldViewAngles, "m_vecOldViewAngles", "CPlayer_MovementServices", "client.dll");
};

// Class: CPlayer_MovementServices_Humanoid (Size: 0x278)
class CPlayer_MovementServices_Humanoid : public CPlayer_MovementServices {
public:
	SCHEMA(float32, m_flStepSoundTime, "m_flStepSoundTime", "CPlayer_MovementServices_Humanoid", "client.dll");
	SCHEMA(float32, m_flFallVelocity, "m_flFallVelocity", "CPlayer_MovementServices_Humanoid", "client.dll");
	SCHEMA(bool, m_bInCrouch, "m_bInCrouch", "CPlayer_MovementServices_Humanoid", "client.dll");
	SCHEMA(uint32, m_nCrouchState, "m_nCrouchState", "CPlayer_MovementServices_Humanoid", "client.dll");
	SCHEMA(GameTime_t, m_flCrouchTransitionStartTime, "m_flCrouchTransitionStartTime", "CPlayer_MovementServices_Humanoid", "client.dll");
	SCHEMA(bool, m_bDucked, "m_bDucked", "CPlayer_MovementServices_Humanoid", "client.dll");
	SCHEMA(bool, m_bDucking, "m_bDucking", "CPlayer_MovementServices_Humanoid", "client.dll");
	SCHEMA(bool, m_bInDuckJump, "m_bInDuckJump", "CPlayer_MovementServices_Humanoid", "client.dll");
	SCHEMA(Vector, m_groundNormal, "m_groundNormal", "CPlayer_MovementServices_Humanoid", "client.dll");
	SCHEMA(float32, m_flSurfaceFriction, "m_flSurfaceFriction", "CPlayer_MovementServices_Humanoid", "client.dll");
	SCHEMA(CUtlStringToken, m_surfaceProps, "m_surfaceProps", "CPlayer_MovementServices_Humanoid", "client.dll");
	SCHEMA(int32, m_nStepside, "m_nStepside", "CPlayer_MovementServices_Humanoid", "client.dll");
};

// Class: CCSPlayer_MovementServices (Size: 0x5D8)
class CCSPlayer_MovementServices : public CPlayer_MovementServices_Humanoid {
public:
	SCHEMA(Vector, m_vecLadderNormal, "m_vecLadderNormal", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(int32, m_nLadderSurfacePropIndex, "m_nLadderSurfacePropIndex", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(float32, m_flDuckAmount, "m_flDuckAmount", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(float32, m_flDuckSpeed, "m_flDuckSpeed", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(bool, m_bDuckOverride, "m_bDuckOverride", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(bool, m_bDesiresDuck, "m_bDesiresDuck", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(float32, m_flDuckOffset, "m_flDuckOffset", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(uint32, m_nDuckTimeMsecs, "m_nDuckTimeMsecs", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(uint32, m_nDuckJumpTimeMsecs, "m_nDuckJumpTimeMsecs", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(uint32, m_nJumpTimeMsecs, "m_nJumpTimeMsecs", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(float32, m_flLastDuckTime, "m_flLastDuckTime", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(Vector2D, m_vecLastPositionAtFullCrouchSpeed, "m_vecLastPositionAtFullCrouchSpeed", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(bool, m_duckUntilOnGround, "m_duckUntilOnGround", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(bool, m_bHasWalkMovedSinceLastJump, "m_bHasWalkMovedSinceLastJump", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(bool, m_bInStuckTest, "m_bInStuckTest", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(int32, m_nTraceCount, "m_nTraceCount", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(int32, m_StuckLast, "m_StuckLast", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(bool, m_bSpeedCropped, "m_bSpeedCropped", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(int32, m_nOldWaterLevel, "m_nOldWaterLevel", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(float32, m_flWaterEntryTime, "m_flWaterEntryTime", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(Vector, m_vecForward, "m_vecForward", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(Vector, m_vecLeft, "m_vecLeft", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(Vector, m_vecUp, "m_vecUp", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(int32, m_nGameCodeHasMovedPlayerAfterCommand, "m_nGameCodeHasMovedPlayerAfterCommand", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(bool, m_bOldJumpPressed, "m_bOldJumpPressed", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(float32, m_flJumpPressedTime, "m_flJumpPressedTime", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(GameTime_t, m_fStashGrenadeParameterWhen, "m_fStashGrenadeParameterWhen", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(uint64, m_nButtonDownMaskPrev, "m_nButtonDownMaskPrev", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(float32, m_flOffsetTickCompleteTime, "m_flOffsetTickCompleteTime", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(float32, m_flOffsetTickStashedSpeed, "m_flOffsetTickStashedSpeed", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(float32, m_flStamina, "m_flStamina", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(float32, m_flHeightAtJumpStart, "m_flHeightAtJumpStart", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(float32, m_flMaxJumpHeightThisJump, "m_flMaxJumpHeightThisJump", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(float32, m_flMaxJumpHeightLastJump, "m_flMaxJumpHeightLastJump", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(float32, m_flStaminaAtJumpStart, "m_flStaminaAtJumpStart", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(float32, m_flAccumulatedJumpError, "m_flAccumulatedJumpError", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(float32, m_flTicksSinceLastSurfingDetected, "m_flTicksSinceLastSurfingDetected", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(bool, m_bWasSurfing, "m_bWasSurfing", "CCSPlayer_MovementServices", "client.dll");
	SCHEMA(Vector, m_vecInputRotated, "m_vecInputRotated", "CCSPlayer_MovementServices", "client.dll");
};

// Class: CPlayer_ObserverServices (Size: 0x58)
class CPlayer_ObserverServices : public CPlayerPawnComponent {
public:
	SCHEMA(uint8, m_iObserverMode, "m_iObserverMode", "CPlayer_ObserverServices", "client.dll");
	SCHEMA(CHandle, m_hObserverTarget, "m_hObserverTarget", "CPlayer_ObserverServices", "client.dll");
	SCHEMA(ObserverMode_t, m_iObserverLastMode, "m_iObserverLastMode", "CPlayer_ObserverServices", "client.dll");
	SCHEMA(bool, m_bForcedObserverMode, "m_bForcedObserverMode", "CPlayer_ObserverServices", "client.dll");
	SCHEMA(float32, m_flObserverChaseDistance, "m_flObserverChaseDistance", "CPlayer_ObserverServices", "client.dll");
	SCHEMA(GameTime_t, m_flObserverChaseDistanceCalcTime, "m_flObserverChaseDistanceCalcTime", "CPlayer_ObserverServices", "client.dll");
};

// Class: CCSObserver_ObserverServices (Size: 0xE0)
class CCSObserver_ObserverServices : public CPlayer_ObserverServices {
public:
	SCHEMA(ObserverInterpState_t, m_obsInterpState, "m_obsInterpState", "CCSObserver_ObserverServices", "client.dll");
};

// Class: CPlayer_WeaponServices (Size: 0xA0)
class CPlayer_WeaponServices : public CPlayerPawnComponent {
public:
	SCHEMA(CUtlVector< CHandle >, m_hMyWeapons, "m_hMyWeapons", "CPlayer_WeaponServices", "client.dll");
	SCHEMA(CHandle, m_hActiveWeapon, "m_hActiveWeapon", "CPlayer_WeaponServices", "client.dll");
	SCHEMA(CHandle, m_hLastWeapon, "m_hLastWeapon", "CPlayer_WeaponServices", "client.dll");
	SCHEMA(uint16*, m_iAmmo, "m_iAmmo", "CPlayer_WeaponServices", "client.dll");
};

// Class: CCSPlayer_WeaponServices (Size: 0x1910)
class CCSPlayer_WeaponServices : public CPlayer_WeaponServices {
public:
	SCHEMA(GameTime_t, m_flNextAttack, "m_flNextAttack", "CCSPlayer_WeaponServices", "client.dll");
	SCHEMA(bool, m_bIsLookingAtWeapon, "m_bIsLookingAtWeapon", "CCSPlayer_WeaponServices", "client.dll");
	SCHEMA(bool, m_bIsHoldingLookAtWeapon, "m_bIsHoldingLookAtWeapon", "CCSPlayer_WeaponServices", "client.dll");
	SCHEMA(uint32, m_nOldTotalShootPositionHistoryCount, "m_nOldTotalShootPositionHistoryCount", "CCSPlayer_WeaponServices", "client.dll");
	SCHEMA(uint32, m_nOldTotalInputHistoryCount, "m_nOldTotalInputHistoryCount", "CCSPlayer_WeaponServices", "client.dll");
	SCHEMA(CUtlVector< uint8 >, m_networkAnimTiming, "m_networkAnimTiming", "CCSPlayer_WeaponServices", "client.dll");
	SCHEMA(bool, m_bBlockInspectUntilNextGraphUpdate, "m_bBlockInspectUntilNextGraphUpdate", "CCSPlayer_WeaponServices", "client.dll");
};

// Class: CPointChildModifier (Size: 0x600)
class CPointChildModifier : public C_PointEntity {
public:
	SCHEMA(bool, m_bOrphanInsteadOfDeletingChildrenOnRemove, "m_bOrphanInsteadOfDeletingChildrenOnRemove", "CPointChildModifier", "client.dll");
};

// Class: CPointTemplate (Size: 0x660)
class CPointTemplate : public CLogicalEntity {
public:
	SCHEMA(CUtlSymbolLarge, m_iszWorldName, "m_iszWorldName", "CPointTemplate", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_iszSource2EntityLumpName, "m_iszSource2EntityLumpName", "CPointTemplate", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_iszEntityFilterName, "m_iszEntityFilterName", "CPointTemplate", "client.dll");
	SCHEMA(float32, m_flTimeoutInterval, "m_flTimeoutInterval", "CPointTemplate", "client.dll");
	SCHEMA(bool, m_bAsynchronouslySpawnEntities, "m_bAsynchronouslySpawnEntities", "CPointTemplate", "client.dll");
	SCHEMA(PointTemplateClientOnlyEntityBehavior_t, m_clientOnlyEntityBehavior, "m_clientOnlyEntityBehavior", "CPointTemplate", "client.dll");
	SCHEMA(PointTemplateOwnerSpawnGroupType_t, m_ownerSpawnGroupType, "m_ownerSpawnGroupType", "CPointTemplate", "client.dll");
	SCHEMA(CUtlVector< uint32 >, m_createdSpawnGroupHandles, "m_createdSpawnGroupHandles", "CPointTemplate", "client.dll");
	SCHEMA(CUtlVector< CEntityHandle >, m_SpawnedEntityHandles, "m_SpawnedEntityHandles", "CPointTemplate", "client.dll");
	SCHEMA(HSCRIPT, m_ScriptSpawnCallback, "m_ScriptSpawnCallback", "CPointTemplate", "client.dll");
	SCHEMA(HSCRIPT, m_ScriptCallbackScope, "m_ScriptCallbackScope", "CPointTemplate", "client.dll");
};

// Class: CPrecipitationVData (Size: 0x128)
class CPrecipitationVData {
public:
	SCHEMA(float32, m_flInnerDistance, "m_flInnerDistance", "CPrecipitationVData", "client.dll");
	SCHEMA(ParticleAttachment_t, m_nAttachType, "m_nAttachType", "CPrecipitationVData", "client.dll");
	SCHEMA(bool, m_bBatchSameVolumeType, "m_bBatchSameVolumeType", "CPrecipitationVData", "client.dll");
	SCHEMA(int32, m_nRTEnvCP, "m_nRTEnvCP", "CPrecipitationVData", "client.dll");
	SCHEMA(int32, m_nRTEnvCPComponent, "m_nRTEnvCPComponent", "CPrecipitationVData", "client.dll");
	SCHEMA(CUtlString, m_szModifier, "m_szModifier", "CPrecipitationVData", "client.dll");
};

// Class: CPropDataComponent (Size: 0x40)
class CPropDataComponent : public CEntityComponent {
public:
	SCHEMA(float32, m_flDmgModBullet, "m_flDmgModBullet", "CPropDataComponent", "client.dll");
	SCHEMA(float32, m_flDmgModClub, "m_flDmgModClub", "CPropDataComponent", "client.dll");
	SCHEMA(float32, m_flDmgModExplosive, "m_flDmgModExplosive", "CPropDataComponent", "client.dll");
	SCHEMA(float32, m_flDmgModFire, "m_flDmgModFire", "CPropDataComponent", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_iszPhysicsDamageTableName, "m_iszPhysicsDamageTableName", "CPropDataComponent", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_iszBasePropData, "m_iszBasePropData", "CPropDataComponent", "client.dll");
	SCHEMA(int32, m_nInteractions, "m_nInteractions", "CPropDataComponent", "client.dll");
	SCHEMA(bool, m_bSpawnMotionDisabled, "m_bSpawnMotionDisabled", "CPropDataComponent", "client.dll");
	SCHEMA(int32, m_nDisableTakePhysicsDamageSpawnFlag, "m_nDisableTakePhysicsDamageSpawnFlag", "CPropDataComponent", "client.dll");
	SCHEMA(int32, m_nMotionDisabledSpawnFlag, "m_nMotionDisabledSpawnFlag", "CPropDataComponent", "client.dll");
};

// Class: CPulseCell_Base (Size: 0x48)
class CPulseCell_Base {
public:
	SCHEMA(PulseDocNodeID_t, m_nEditorNodeID, "m_nEditorNodeID", "CPulseCell_Base", "client.dll");
};

// Class: CPulseCell_BaseLerp (Size: 0x90)
class CPulseCell_BaseLerp {
public:
	SCHEMA(CPulse_ResumePoint, m_WakeResume, "m_WakeResume", "CPulseCell_BaseLerp", "client.dll");
};

// Class: CPulseCell_BooleanSwitchState (Size: 0x198)
class CPulseCell_BooleanSwitchState {
public:
	SCHEMA(PulseObservableBoolExpression_t, m_Condition, "m_Condition", "CPulseCell_BooleanSwitchState", "client.dll");
	SCHEMA(CPulse_OutflowConnection, m_SubGraph, "m_SubGraph", "CPulseCell_BooleanSwitchState", "client.dll");
	SCHEMA(CPulse_OutflowConnection, m_WhenTrue, "m_WhenTrue", "CPulseCell_BooleanSwitchState", "client.dll");
	SCHEMA(CPulse_OutflowConnection, m_WhenFalse, "m_WhenFalse", "CPulseCell_BooleanSwitchState", "client.dll");
};

// Class: CPulseCell_CursorQueue (Size: 0xA0)
class CPulseCell_CursorQueue {
public:
	SCHEMA(int32, m_nCursorsAllowedToRunParallel, "m_nCursorsAllowedToRunParallel", "CPulseCell_CursorQueue", "client.dll");
};

// Class: CPulseCell_FireCursors (Size: 0xF8)
class CPulseCell_FireCursors {
public:
	SCHEMA(CUtlVector< CPulse_OutflowConnection >, m_Outflows, "m_Outflows", "CPulseCell_FireCursors", "client.dll");
	SCHEMA(bool, m_bWaitForChildOutflows, "m_bWaitForChildOutflows", "CPulseCell_FireCursors", "client.dll");
	SCHEMA(CPulse_ResumePoint, m_OnFinished, "m_OnFinished", "CPulseCell_FireCursors", "client.dll");
	SCHEMA(CPulse_ResumePoint, m_OnCanceled, "m_OnCanceled", "CPulseCell_FireCursors", "client.dll");
};

// Class: CPulseCell_Inflow_BaseEntrypoint (Size: 0x80)
class CPulseCell_Inflow_BaseEntrypoint {
public:
	SCHEMA(PulseRuntimeChunkIndex_t, m_EntryChunk, "m_EntryChunk", "CPulseCell_Inflow_BaseEntrypoint", "client.dll");
	SCHEMA(PulseRegisterMap_t, m_RegisterMap, "m_RegisterMap", "CPulseCell_Inflow_BaseEntrypoint", "client.dll");
};

// Class: CPulseCell_Inflow_EntOutputHandler (Size: 0xB8)
class CPulseCell_Inflow_EntOutputHandler {
public:
	SCHEMA(PulseSymbol_t, m_SourceEntity, "m_SourceEntity", "CPulseCell_Inflow_EntOutputHandler", "client.dll");
	SCHEMA(PulseSymbol_t, m_SourceOutput, "m_SourceOutput", "CPulseCell_Inflow_EntOutputHandler", "client.dll");
	SCHEMA(CPulseValueFullType, m_ExpectedParamType, "m_ExpectedParamType", "CPulseCell_Inflow_EntOutputHandler", "client.dll");
};

// Class: CPulseCell_Inflow_EventHandler (Size: 0x90)
class CPulseCell_Inflow_EventHandler {
public:
	SCHEMA(PulseSymbol_t, m_EventName, "m_EventName", "CPulseCell_Inflow_EventHandler", "client.dll");
};

// Class: CPulseCell_Inflow_GraphHook (Size: 0x90)
class CPulseCell_Inflow_GraphHook {
public:
	SCHEMA(PulseSymbol_t, m_HookName, "m_HookName", "CPulseCell_Inflow_GraphHook", "client.dll");
};

// Class: CPulseCell_Inflow_Method (Size: 0xC8)
class CPulseCell_Inflow_Method {
public:
	SCHEMA(PulseSymbol_t, m_MethodName, "m_MethodName", "CPulseCell_Inflow_Method", "client.dll");
	SCHEMA(CUtlString, m_Description, "m_Description", "CPulseCell_Inflow_Method", "client.dll");
	SCHEMA(bool, m_bIsPublic, "m_bIsPublic", "CPulseCell_Inflow_Method", "client.dll");
	SCHEMA(CPulseValueFullType, m_ReturnType, "m_ReturnType", "CPulseCell_Inflow_Method", "client.dll");
};

// Class: CPulseCell_Inflow_ObservableVariableListener (Size: 0x88)
class CPulseCell_Inflow_ObservableVariableListener {
public:
	SCHEMA(PulseRuntimeBlackboardReferenceIndex_t, m_nBlackboardReference, "m_nBlackboardReference", "CPulseCell_Inflow_ObservableVariableListener", "client.dll");
	SCHEMA(bool, m_bSelfReference, "m_bSelfReference", "CPulseCell_Inflow_ObservableVariableListener", "client.dll");
};

// Class: CPulseCell_Inflow_Wait (Size: 0x90)
class CPulseCell_Inflow_Wait {
public:
	SCHEMA(CPulse_ResumePoint, m_WakeResume, "m_WakeResume", "CPulseCell_Inflow_Wait", "client.dll");
};

// Class: CPulseCell_Inflow_Yield (Size: 0x90)
class CPulseCell_Inflow_Yield {
public:
	SCHEMA(CPulse_ResumePoint, m_UnyieldResume, "m_UnyieldResume", "CPulseCell_Inflow_Yield", "client.dll");
};

// Class: CPulseCell_InlineNodeSkipSelector (Size: 0xB0)
class CPulseCell_InlineNodeSkipSelector {
public:
	SCHEMA(PulseDocNodeID_t, m_nFlowNodeID, "m_nFlowNodeID", "CPulseCell_InlineNodeSkipSelector", "client.dll");
	SCHEMA(bool, m_bAnd, "m_bAnd", "CPulseCell_InlineNodeSkipSelector", "client.dll");
	SCHEMA(PulseSelectorOutflowList_t, m_PassOutflow, "m_PassOutflow", "CPulseCell_InlineNodeSkipSelector", "client.dll");
	SCHEMA(CPulse_OutflowConnection, m_FailOutflow, "m_FailOutflow", "CPulseCell_InlineNodeSkipSelector", "client.dll");
};

// Class: CPulseCell_IntervalTimer (Size: 0xD8)
class CPulseCell_IntervalTimer {
public:
	SCHEMA(CPulse_ResumePoint, m_Completed, "m_Completed", "CPulseCell_IntervalTimer", "client.dll");
	SCHEMA(SignatureOutflow_Continue, m_OnInterval, "m_OnInterval", "CPulseCell_IntervalTimer", "client.dll");
};

// Class: CPulseCell_LerpCameraSettings (Size: 0xB8)
class CPulseCell_LerpCameraSettings {
public:
	SCHEMA(float32, m_flSeconds, "m_flSeconds", "CPulseCell_LerpCameraSettings", "client.dll");
	SCHEMA(PointCameraSettings_t, m_Start, "m_Start", "CPulseCell_LerpCameraSettings", "client.dll");
	SCHEMA(PointCameraSettings_t, m_End, "m_End", "CPulseCell_LerpCameraSettings", "client.dll");
};

// Class: CPulseCell_LimitCount (Size: 0x50)
class CPulseCell_LimitCount {
public:
	SCHEMA(int32, m_nLimitCount, "m_nLimitCount", "CPulseCell_LimitCount", "client.dll");
};

// Class: CPulseCell_Outflow_CycleOrdered (Size: 0x60)
class CPulseCell_Outflow_CycleOrdered {
public:
	SCHEMA(CUtlVector< CPulse_OutflowConnection >, m_Outputs, "m_Outputs", "CPulseCell_Outflow_CycleOrdered", "client.dll");
};

// Class: CPulseCell_Outflow_CycleRandom (Size: 0x60)
class CPulseCell_Outflow_CycleRandom {
public:
	SCHEMA(CUtlVector< CPulse_OutflowConnection >, m_Outputs, "m_Outputs", "CPulseCell_Outflow_CycleRandom", "client.dll");
};

// Class: CPulseCell_Outflow_CycleShuffled (Size: 0x60)
class CPulseCell_Outflow_CycleShuffled {
public:
	SCHEMA(CUtlVector< CPulse_OutflowConnection >, m_Outputs, "m_Outputs", "CPulseCell_Outflow_CycleShuffled", "client.dll");
};

// Class: CPulseCell_PickBestOutflowSelector (Size: 0x68)
class CPulseCell_PickBestOutflowSelector {
public:
	SCHEMA(PulseBestOutflowRules_t, m_nCheckType, "m_nCheckType", "CPulseCell_PickBestOutflowSelector", "client.dll");
	SCHEMA(PulseSelectorOutflowList_t, m_OutflowList, "m_OutflowList", "CPulseCell_PickBestOutflowSelector", "client.dll");
};

// Class: CPulseCell_PlaySequence (Size: 0xF8)
class CPulseCell_PlaySequence {
public:
	SCHEMA(CUtlString, m_SequenceName, "m_SequenceName", "CPulseCell_PlaySequence", "client.dll");
	SCHEMA(PulseNodeDynamicOutflows_t, m_PulseAnimEvents, "m_PulseAnimEvents", "CPulseCell_PlaySequence", "client.dll");
	SCHEMA(CPulse_ResumePoint, m_OnFinished, "m_OnFinished", "CPulseCell_PlaySequence", "client.dll");
	SCHEMA(CPulse_ResumePoint, m_OnCanceled, "m_OnCanceled", "CPulseCell_PlaySequence", "client.dll");
};

// Class: CPulseCell_Step_CallExternalMethod (Size: 0xC8)
class CPulseCell_Step_CallExternalMethod {
public:
	SCHEMA(PulseSymbol_t, m_MethodName, "m_MethodName", "CPulseCell_Step_CallExternalMethod", "client.dll");
	SCHEMA(PulseSymbol_t, m_GameBlackboard, "m_GameBlackboard", "CPulseCell_Step_CallExternalMethod", "client.dll");
	SCHEMA(PulseMethodCallMode_t, m_nAsyncCallMode, "m_nAsyncCallMode", "CPulseCell_Step_CallExternalMethod", "client.dll");
	SCHEMA(CPulse_ResumePoint, m_OnFinished, "m_OnFinished", "CPulseCell_Step_CallExternalMethod", "client.dll");
};

// Class: CPulseCell_Step_EntFire (Size: 0x50)
class CPulseCell_Step_EntFire {
public:
	SCHEMA(CUtlString, m_Input, "m_Input", "CPulseCell_Step_EntFire", "client.dll");
};

// Class: CPulseCell_Step_PublicOutput (Size: 0x50)
class CPulseCell_Step_PublicOutput {
public:
	SCHEMA(PulseRuntimeOutputIndex_t, m_OutputIndex, "m_OutputIndex", "CPulseCell_Step_PublicOutput", "client.dll");
};

// Class: CPulseCell_Timeline (Size: 0xF8)
class CPulseCell_Timeline {
public:
	class TimelineEvent_t {
	public:
		SCHEMA(float32, m_flTimeFromPrevious, "m_flTimeFromPrevious", "CPulseCell_Timeline::TimelineEvent_t", "client.dll");
		SCHEMA(CPulse_OutflowConnection, m_EventOutflow, "m_EventOutflow", "CPulseCell_Timeline::TimelineEvent_t", "client.dll");
	};

	SCHEMA(CUtlVector< CPulseCell_Timeline::TimelineEvent_t >, m_TimelineEvents, "m_TimelineEvents", "CPulseCell_Timeline", "client.dll");
	SCHEMA(bool, m_bWaitForChildOutflows, "m_bWaitForChildOutflows", "CPulseCell_Timeline", "client.dll");
	SCHEMA(CPulse_ResumePoint, m_OnFinished, "m_OnFinished", "CPulseCell_Timeline", "client.dll");
	SCHEMA(CPulse_ResumePoint, m_OnCanceled, "m_OnCanceled", "CPulseCell_Timeline", "client.dll");
};

// Class: CPulseCell_Unknown (Size: 0x58)
class CPulseCell_Unknown {
public:
	SCHEMA(KeyValues3, m_UnknownKeys, "m_UnknownKeys", "CPulseCell_Unknown", "client.dll");
};

// Class: CPulseCell_Value_Curve (Size: 0x88)
class CPulseCell_Value_Curve {
public:
	SCHEMA(CPiecewiseCurve, m_Curve, "m_Curve", "CPulseCell_Value_Curve", "client.dll");
};

// Class: CPulseCell_Value_Gradient (Size: 0x60)
class CPulseCell_Value_Gradient {
public:
	SCHEMA(CColorGradient, m_Gradient, "m_Gradient", "CPulseCell_Value_Gradient", "client.dll");
};

// Class: CPulseCell_WaitForCursorsWithTag (Size: 0xA0)
class CPulseCell_WaitForCursorsWithTag {
public:
	SCHEMA(bool, m_bTagSelfWhenComplete, "m_bTagSelfWhenComplete", "CPulseCell_WaitForCursorsWithTag", "client.dll");
	SCHEMA(PulseCursorCancelPriority_t, m_nDesiredKillPriority, "m_nDesiredKillPriority", "CPulseCell_WaitForCursorsWithTag", "client.dll");
};

// Class: CPulseCell_WaitForCursorsWithTagBase (Size: 0x98)
class CPulseCell_WaitForCursorsWithTagBase {
public:
	SCHEMA(int32, m_nCursorsAllowedToWait, "m_nCursorsAllowedToWait", "CPulseCell_WaitForCursorsWithTagBase", "client.dll");
	SCHEMA(CPulse_ResumePoint, m_WaitComplete, "m_WaitComplete", "CPulseCell_WaitForCursorsWithTagBase", "client.dll");
};

// Class: CPulseCell_WaitForObservable (Size: 0x108)
class CPulseCell_WaitForObservable {
public:
	SCHEMA(PulseObservableBoolExpression_t, m_Condition, "m_Condition", "CPulseCell_WaitForObservable", "client.dll");
	SCHEMA(CPulse_ResumePoint, m_OnTrue, "m_OnTrue", "CPulseCell_WaitForObservable", "client.dll");
};

// Class: CPulseGraphDef (Size: 0x198)
class CPulseGraphDef {
public:
	SCHEMA(PulseSymbol_t, m_DomainIdentifier, "m_DomainIdentifier", "CPulseGraphDef", "client.dll");
	SCHEMA(CPulseValueFullType, m_DomainSubType, "m_DomainSubType", "CPulseGraphDef", "client.dll");
	SCHEMA(PulseSymbol_t, m_ParentMapName, "m_ParentMapName", "CPulseGraphDef", "client.dll");
	SCHEMA(PulseSymbol_t, m_ParentXmlName, "m_ParentXmlName", "CPulseGraphDef", "client.dll");
	SCHEMA(CUtlVector< CPulseCell_Base* >, m_Cells, "m_Cells", "CPulseGraphDef", "client.dll");
	SCHEMA(CUtlVector< CPulse_InvokeBinding* >, m_InvokeBindings, "m_InvokeBindings", "CPulseGraphDef", "client.dll");
	SCHEMA(CUtlVector< CPulse_CallInfo* >, m_CallInfos, "m_CallInfos", "CPulseGraphDef", "client.dll");
	SCHEMA(CUtlVector< CPulse_BlackboardReference >, m_BlackboardReferences, "m_BlackboardReferences", "CPulseGraphDef", "client.dll");
};

// Class: CPulse_BlackboardReference (Size: 0x28)
class CPulse_BlackboardReference {
public:
	SCHEMA(PulseSymbol_t, m_BlackboardResource, "m_BlackboardResource", "CPulse_BlackboardReference", "client.dll");
	SCHEMA(PulseDocNodeID_t, m_nNodeID, "m_nNodeID", "CPulse_BlackboardReference", "client.dll");
	SCHEMA(CGlobalSymbol, m_NodeName, "m_NodeName", "CPulse_BlackboardReference", "client.dll");
};

// Class: CPulse_CallInfo (Size: 0x58)
class CPulse_CallInfo {
public:
	SCHEMA(PulseSymbol_t, m_PortName, "m_PortName", "CPulse_CallInfo", "client.dll");
	SCHEMA(PulseDocNodeID_t, m_nEditorNodeID, "m_nEditorNodeID", "CPulse_CallInfo", "client.dll");
	SCHEMA(PulseRegisterMap_t, m_RegisterMap, "m_RegisterMap", "CPulse_CallInfo", "client.dll");
	SCHEMA(PulseDocNodeID_t, m_CallMethodID, "m_CallMethodID", "CPulse_CallInfo", "client.dll");
	SCHEMA(PulseRuntimeChunkIndex_t, m_nSrcChunk, "m_nSrcChunk", "CPulse_CallInfo", "client.dll");
	SCHEMA(int32, m_nSrcInstruction, "m_nSrcInstruction", "CPulse_CallInfo", "client.dll");
};

// Class: CPulse_InvokeBinding (Size: 0xB0)
class CPulse_InvokeBinding {
public:
	SCHEMA(PulseRegisterMap_t, m_RegisterMap, "m_RegisterMap", "CPulse_InvokeBinding", "client.dll");
	SCHEMA(PulseSymbol_t, m_FuncName, "m_FuncName", "CPulse_InvokeBinding", "client.dll");
	SCHEMA(PulseRuntimeCellIndex_t, m_nCellIndex, "m_nCellIndex", "CPulse_InvokeBinding", "client.dll");
	SCHEMA(PulseRuntimeChunkIndex_t, m_nSrcChunk, "m_nSrcChunk", "CPulse_InvokeBinding", "client.dll");
	SCHEMA(int32, m_nSrcInstruction, "m_nSrcInstruction", "CPulse_InvokeBinding", "client.dll");
};

// Class: CPulse_OutflowConnection (Size: 0x48)
class CPulse_OutflowConnection {
public:
	SCHEMA(PulseSymbol_t, m_SourceOutflowName, "m_SourceOutflowName", "CPulse_OutflowConnection", "client.dll");
	SCHEMA(PulseRuntimeChunkIndex_t, m_nDestChunk, "m_nDestChunk", "CPulse_OutflowConnection", "client.dll");
	SCHEMA(int32, m_nInstruction, "m_nInstruction", "CPulse_OutflowConnection", "client.dll");
	SCHEMA(PulseRegisterMap_t, m_OutflowRegisterMap, "m_OutflowRegisterMap", "CPulse_OutflowConnection", "client.dll");
};

// Class: CRenderComponent (Size: 0xD0)
class CRenderComponent : public CEntityComponent {
public:
	SCHEMA(CNetworkVarChainer, __m_pChainEntity, "__m_pChainEntity", "CRenderComponent", "client.dll");
	SCHEMA(bool, m_bIsRenderingWithViewModels, "m_bIsRenderingWithViewModels", "CRenderComponent", "client.dll");
	SCHEMA(uint32, m_nSplitscreenFlags, "m_nSplitscreenFlags", "CRenderComponent", "client.dll");
	SCHEMA(bool, m_bEnableRendering, "m_bEnableRendering", "CRenderComponent", "client.dll");
	SCHEMA(bool, m_bInterpolationReadyToDraw, "m_bInterpolationReadyToDraw", "CRenderComponent", "client.dll");
};

// Class: CSMatchStats_t (Size: 0x80)
class CSMatchStats_t {
public:
	SCHEMA(int32, m_iEnemy5Ks, "m_iEnemy5Ks", "CSMatchStats_t", "client.dll");
	SCHEMA(int32, m_iEnemy4Ks, "m_iEnemy4Ks", "CSMatchStats_t", "client.dll");
	SCHEMA(int32, m_iEnemy3Ks, "m_iEnemy3Ks", "CSMatchStats_t", "client.dll");
	SCHEMA(int32, m_iEnemyKnifeKills, "m_iEnemyKnifeKills", "CSMatchStats_t", "client.dll");
	SCHEMA(int32, m_iEnemyTaserKills, "m_iEnemyTaserKills", "CSMatchStats_t", "client.dll");
};

// Class: CSPerRoundStats_t (Size: 0x68)
class CSPerRoundStats_t {
public:
	SCHEMA(int32, m_iKills, "m_iKills", "CSPerRoundStats_t", "client.dll");
	SCHEMA(int32, m_iDeaths, "m_iDeaths", "CSPerRoundStats_t", "client.dll");
	SCHEMA(int32, m_iAssists, "m_iAssists", "CSPerRoundStats_t", "client.dll");
	SCHEMA(int32, m_iDamage, "m_iDamage", "CSPerRoundStats_t", "client.dll");
	SCHEMA(int32, m_iEquipmentValue, "m_iEquipmentValue", "CSPerRoundStats_t", "client.dll");
	SCHEMA(int32, m_iMoneySaved, "m_iMoneySaved", "CSPerRoundStats_t", "client.dll");
	SCHEMA(int32, m_iKillReward, "m_iKillReward", "CSPerRoundStats_t", "client.dll");
	SCHEMA(int32, m_iLiveTime, "m_iLiveTime", "CSPerRoundStats_t", "client.dll");
	SCHEMA(int32, m_iHeadShotKills, "m_iHeadShotKills", "CSPerRoundStats_t", "client.dll");
	SCHEMA(int32, m_iObjective, "m_iObjective", "CSPerRoundStats_t", "client.dll");
	SCHEMA(int32, m_iCashEarned, "m_iCashEarned", "CSPerRoundStats_t", "client.dll");
	SCHEMA(int32, m_iUtilityDamage, "m_iUtilityDamage", "CSPerRoundStats_t", "client.dll");
	SCHEMA(int32, m_iEnemiesFlashed, "m_iEnemiesFlashed", "CSPerRoundStats_t", "client.dll");
};

// Class: CScriptComponent (Size: 0x38)
class CScriptComponent : public CEntityComponent {
public:
	SCHEMA(CUtlSymbolLarge, m_scriptClassName, "m_scriptClassName", "CScriptComponent", "client.dll");
};

// Class: CSkeletonInstance (Size: 0x530)
class CSkeletonInstance : public CGameSceneNode {
public:
	SCHEMA(CModelState, m_modelState, "m_modelState", "CSkeletonInstance", "client.dll");
	SCHEMA(bool, m_bIsAnimationEnabled, "m_bIsAnimationEnabled", "CSkeletonInstance", "client.dll");
	SCHEMA(bool, m_bUseParentRenderBounds, "m_bUseParentRenderBounds", "CSkeletonInstance", "client.dll");
	SCHEMA(bool, m_bDisableSolidCollisionsForHierarchy, "m_bDisableSolidCollisionsForHierarchy", "CSkeletonInstance", "client.dll");
	SCHEMA(bool, m_bDirtyMotionType, "m_bDirtyMotionType", "CSkeletonInstance", "client.dll");
	SCHEMA(bool, m_bIsGeneratingLatchedParentSpaceState, "m_bIsGeneratingLatchedParentSpaceState", "CSkeletonInstance", "client.dll");
	SCHEMA(CUtlStringToken, m_materialGroup, "m_materialGroup", "CSkeletonInstance", "client.dll");
	SCHEMA(uint8, m_nHitboxSet, "m_nHitboxSet", "CSkeletonInstance", "client.dll");
};

// Class: CTimeline (Size: 0x228)
class CTimeline {
public:
	SCHEMA(float32*, m_flValues, "m_flValues", "CTimeline", "client.dll");
	SCHEMA(int32*, m_nValueCounts, "m_nValueCounts", "CTimeline", "client.dll");
	SCHEMA(int32, m_nBucketCount, "m_nBucketCount", "CTimeline", "client.dll");
	SCHEMA(float32, m_flInterval, "m_flInterval", "CTimeline", "client.dll");
	SCHEMA(float32, m_flFinalValue, "m_flFinalValue", "CTimeline", "client.dll");
	SCHEMA(TimelineCompression_t, m_nCompressionType, "m_nCompressionType", "CTimeline", "client.dll");
	SCHEMA(bool, m_bStopped, "m_bStopped", "CTimeline", "client.dll");
};

// Class: C_AttributeContainer (Size: 0x4D8)
class C_AttributeContainer : public CAttributeManager {
public:
	SCHEMA(C_EconItemView, m_Item, "m_Item", "C_AttributeContainer", "client.dll");
	SCHEMA(int32, m_iExternalItemProviderRegisteredToken, "m_iExternalItemProviderRegisteredToken", "C_AttributeContainer", "client.dll");
	SCHEMA(uint64, m_ullRegisteredAsItemID, "m_ullRegisteredAsItemID", "C_AttributeContainer", "client.dll");
};

// Class: C_BaseButton (Size: 0xEC0)
class C_BaseButton : public C_BaseToggle {
public:
	SCHEMA(CHandle, m_glowEntity, "m_glowEntity", "C_BaseButton", "client.dll");
	SCHEMA(bool, m_usable, "m_usable", "C_BaseButton", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_szDisplayText, "m_szDisplayText", "C_BaseButton", "client.dll");
};

// Class: C_BaseDoor (Size: 0xEB8)
class C_BaseDoor : public C_BaseToggle {
public:
	SCHEMA(bool, m_bIsUsable, "m_bIsUsable", "C_BaseDoor", "client.dll");
};

// Class: C_BaseEntity (Size: 0x5F8)
class C_BaseEntity {
public:
	SCHEMA(CBodyComponent*, m_CBodyComponent, "m_CBodyComponent", "C_BaseEntity", "client.dll");
	SCHEMA(CNetworkTransmitComponent, m_NetworkTransmitComponent, "m_NetworkTransmitComponent", "C_BaseEntity", "client.dll");
	SCHEMA(GameTick_t, m_nLastThinkTick, "m_nLastThinkTick", "C_BaseEntity", "client.dll");
	SCHEMA(CGameSceneNode*, m_pGameSceneNode, "m_pGameSceneNode", "C_BaseEntity", "client.dll");
	SCHEMA(CRenderComponent*, m_pRenderComponent, "m_pRenderComponent", "C_BaseEntity", "client.dll");
	SCHEMA(CCollisionProperty*, m_pCollision, "m_pCollision", "C_BaseEntity", "client.dll");
	SCHEMA(int32, m_iMaxHealth, "m_iMaxHealth", "C_BaseEntity", "client.dll");
	SCHEMA(int32, m_iHealth, "m_iHealth", "C_BaseEntity", "client.dll");
	SCHEMA(float32, m_flDamageAccumulator, "m_flDamageAccumulator", "C_BaseEntity", "client.dll");
	SCHEMA(uint8, m_lifeState, "m_lifeState", "C_BaseEntity", "client.dll");
	SCHEMA(bool, m_bTakesDamage, "m_bTakesDamage", "C_BaseEntity", "client.dll");
	SCHEMA(TakeDamageFlags_t, m_nTakeDamageFlags, "m_nTakeDamageFlags", "C_BaseEntity", "client.dll");
	SCHEMA(EntityPlatformTypes_t, m_nPlatformType, "m_nPlatformType", "C_BaseEntity", "client.dll");
	SCHEMA(uint8, m_ubInterpolationFrame, "m_ubInterpolationFrame", "C_BaseEntity", "client.dll");
	SCHEMA(CHandle, m_hSceneObjectController, "m_hSceneObjectController", "C_BaseEntity", "client.dll");
	SCHEMA(int32, m_nNoInterpolationTick, "m_nNoInterpolationTick", "C_BaseEntity", "client.dll");
	SCHEMA(int32, m_nVisibilityNoInterpolationTick, "m_nVisibilityNoInterpolationTick", "C_BaseEntity", "client.dll");
	SCHEMA(float32, m_flProxyRandomValue, "m_flProxyRandomValue", "C_BaseEntity", "client.dll");
	SCHEMA(int32, m_iEFlags, "m_iEFlags", "C_BaseEntity", "client.dll");
	SCHEMA(uint8, m_nWaterType, "m_nWaterType", "C_BaseEntity", "client.dll");
	SCHEMA(bool, m_bInterpolateEvenWithNoModel, "m_bInterpolateEvenWithNoModel", "C_BaseEntity", "client.dll");
	SCHEMA(bool, m_bPredictionEligible, "m_bPredictionEligible", "C_BaseEntity", "client.dll");
	SCHEMA(bool, m_bApplyLayerMatchIDToModel, "m_bApplyLayerMatchIDToModel", "C_BaseEntity", "client.dll");
	SCHEMA(CUtlStringToken, m_tokLayerMatchID, "m_tokLayerMatchID", "C_BaseEntity", "client.dll");
	SCHEMA(CUtlStringToken, m_nSubclassID, "m_nSubclassID", "C_BaseEntity", "client.dll");
	SCHEMA(int32, m_nSimulationTick, "m_nSimulationTick", "C_BaseEntity", "client.dll");
	SCHEMA(int32, m_iCurrentThinkContext, "m_iCurrentThinkContext", "C_BaseEntity", "client.dll");
	SCHEMA(bool, m_bDisabledContextThinks, "m_bDisabledContextThinks", "C_BaseEntity", "client.dll");
	SCHEMA(float32, m_flAnimTime, "m_flAnimTime", "C_BaseEntity", "client.dll");
	SCHEMA(float32, m_flSimulationTime, "m_flSimulationTime", "C_BaseEntity", "client.dll");
	SCHEMA(uint8, m_nSceneObjectOverrideFlags, "m_nSceneObjectOverrideFlags", "C_BaseEntity", "client.dll");
	SCHEMA(bool, m_bHasSuccessfullyInterpolated, "m_bHasSuccessfullyInterpolated", "C_BaseEntity", "client.dll");
	SCHEMA(bool, m_bHasAddedVarsToInterpolation, "m_bHasAddedVarsToInterpolation", "C_BaseEntity", "client.dll");
	SCHEMA(bool, m_bRenderEvenWhenNotSuccessfullyInterpolated, "m_bRenderEvenWhenNotSuccessfullyInterpolated", "C_BaseEntity", "client.dll");
	SCHEMA(int32*, m_nInterpolationLatchDirtyFlags, "m_nInterpolationLatchDirtyFlags", "C_BaseEntity", "client.dll");
	SCHEMA(uint16*, m_ListEntry, "m_ListEntry", "C_BaseEntity", "client.dll");
	SCHEMA(GameTime_t, m_flCreateTime, "m_flCreateTime", "C_BaseEntity", "client.dll");
	SCHEMA(float32, m_flSpeed, "m_flSpeed", "C_BaseEntity", "client.dll");
	SCHEMA(uint16, m_EntClientFlags, "m_EntClientFlags", "C_BaseEntity", "client.dll");
	SCHEMA(bool, m_bClientSideRagdoll, "m_bClientSideRagdoll", "C_BaseEntity", "client.dll");
	SCHEMA(uint8, m_iTeamNum, "m_iTeamNum", "C_BaseEntity", "client.dll");
	SCHEMA(uint32, m_spawnflags, "m_spawnflags", "C_BaseEntity", "client.dll");
	SCHEMA(GameTick_t, m_nNextThinkTick, "m_nNextThinkTick", "C_BaseEntity", "client.dll");
	SCHEMA(uint32, m_fFlags, "m_fFlags", "C_BaseEntity", "client.dll");
	SCHEMA(Vector, m_vecAbsVelocity, "m_vecAbsVelocity", "C_BaseEntity", "client.dll");
	SCHEMA(CNetworkVelocityVector, m_vecServerVelocity, "m_vecServerVelocity", "C_BaseEntity", "client.dll");
	SCHEMA(CNetworkVelocityVector, m_vecVelocity, "m_vecVelocity", "C_BaseEntity", "client.dll");
	SCHEMA(Vector, m_vecBaseVelocity, "m_vecBaseVelocity", "C_BaseEntity", "client.dll");
	SCHEMA(CHandle, m_hEffectEntity, "m_hEffectEntity", "C_BaseEntity", "client.dll");
	SCHEMA(CHandle, m_hOwnerEntity, "m_hOwnerEntity", "C_BaseEntity", "client.dll");
	SCHEMA(MoveCollide_t, m_MoveCollide, "m_MoveCollide", "C_BaseEntity", "client.dll");
	SCHEMA(MoveType_t, m_MoveType, "m_MoveType", "C_BaseEntity", "client.dll");
	SCHEMA(MoveType_t, m_nActualMoveType, "m_nActualMoveType", "C_BaseEntity", "client.dll");
	SCHEMA(float32, m_flWaterLevel, "m_flWaterLevel", "C_BaseEntity", "client.dll");
	SCHEMA(uint32, m_fEffects, "m_fEffects", "C_BaseEntity", "client.dll");
	SCHEMA(CHandle, m_hGroundEntity, "m_hGroundEntity", "C_BaseEntity", "client.dll");
	SCHEMA(int32, m_nGroundBodyIndex, "m_nGroundBodyIndex", "C_BaseEntity", "client.dll");
	SCHEMA(float32, m_flFriction, "m_flFriction", "C_BaseEntity", "client.dll");
	SCHEMA(float32, m_flElasticity, "m_flElasticity", "C_BaseEntity", "client.dll");
	SCHEMA(float32, m_flGravityScale, "m_flGravityScale", "C_BaseEntity", "client.dll");
	SCHEMA(float32, m_flTimeScale, "m_flTimeScale", "C_BaseEntity", "client.dll");
	SCHEMA(bool, m_bAnimatedEveryTick, "m_bAnimatedEveryTick", "C_BaseEntity", "client.dll");
	SCHEMA(bool, m_bGravityDisabled, "m_bGravityDisabled", "C_BaseEntity", "client.dll");
	SCHEMA(GameTime_t, m_flNavIgnoreUntilTime, "m_flNavIgnoreUntilTime", "C_BaseEntity", "client.dll");
	SCHEMA(uint16, m_hThink, "m_hThink", "C_BaseEntity", "client.dll");
	SCHEMA(uint8, m_fBBoxVisFlags, "m_fBBoxVisFlags", "C_BaseEntity", "client.dll");
	SCHEMA(float32, m_flActualGravityScale, "m_flActualGravityScale", "C_BaseEntity", "client.dll");
	SCHEMA(bool, m_bGravityActuallyDisabled, "m_bGravityActuallyDisabled", "C_BaseEntity", "client.dll");
	SCHEMA(bool, m_bPredictable, "m_bPredictable", "C_BaseEntity", "client.dll");
	SCHEMA(bool, m_bRenderWithViewModels, "m_bRenderWithViewModels", "C_BaseEntity", "client.dll");
	SCHEMA(int32, m_nFirstPredictableCommand, "m_nFirstPredictableCommand", "C_BaseEntity", "client.dll");
	SCHEMA(int32, m_nLastPredictableCommand, "m_nLastPredictableCommand", "C_BaseEntity", "client.dll");
	SCHEMA(CHandle, m_hOldMoveParent, "m_hOldMoveParent", "C_BaseEntity", "client.dll");
	SCHEMA(CParticleProperty, m_Particles, "m_Particles", "C_BaseEntity", "client.dll");
	SCHEMA(QAngle, m_vecAngVelocity, "m_vecAngVelocity", "C_BaseEntity", "client.dll");
	SCHEMA(int32, m_DataChangeEventRef, "m_DataChangeEventRef", "C_BaseEntity", "client.dll");
	SCHEMA(CUtlVector< CEntityHandle >, m_dependencies, "m_dependencies", "C_BaseEntity", "client.dll");
	SCHEMA(int32, m_nCreationTick, "m_nCreationTick", "C_BaseEntity", "client.dll");
	SCHEMA(bool, m_bAnimTimeChanged, "m_bAnimTimeChanged", "C_BaseEntity", "client.dll");
	SCHEMA(bool, m_bSimulationTimeChanged, "m_bSimulationTimeChanged", "C_BaseEntity", "client.dll");
	SCHEMA(CUtlString, m_sUniqueHammerID, "m_sUniqueHammerID", "C_BaseEntity", "client.dll");
	SCHEMA(BloodType, m_nBloodType, "m_nBloodType", "C_BaseEntity", "client.dll");
};

// Class: CBasePlayerController (Size: 0x7E8)
class CBasePlayerController : public C_BaseEntity {
public:
	SCHEMA(C_CommandContext, m_CommandContext, "m_CommandContext", "CBasePlayerController", "client.dll");
	SCHEMA(uint64, m_nInButtonsWhichAreToggles, "m_nInButtonsWhichAreToggles", "CBasePlayerController", "client.dll");
	SCHEMA(uint32, m_nTickBase, "m_nTickBase", "CBasePlayerController", "client.dll");
	SCHEMA(CHandle, m_hPawn, "m_hPawn", "CBasePlayerController", "client.dll");
	SCHEMA(bool, m_bKnownTeamMismatch, "m_bKnownTeamMismatch", "CBasePlayerController", "client.dll");
	SCHEMA(CHandle, m_hPredictedPawn, "m_hPredictedPawn", "CBasePlayerController", "client.dll");
	SCHEMA(CSplitScreenSlot, m_nSplitScreenSlot, "m_nSplitScreenSlot", "CBasePlayerController", "client.dll");
	SCHEMA(CHandle, m_hSplitOwner, "m_hSplitOwner", "CBasePlayerController", "client.dll");
	SCHEMA(CUtlVector< CHandle >, m_hSplitScreenPlayers, "m_hSplitScreenPlayers", "CBasePlayerController", "client.dll");
	SCHEMA(bool, m_bIsHLTV, "m_bIsHLTV", "CBasePlayerController", "client.dll");
	SCHEMA(PlayerConnectedState, m_iConnected, "m_iConnected", "CBasePlayerController", "client.dll");
	SCHEMA(char*, m_iszPlayerName, "m_iszPlayerName", "CBasePlayerController", "client.dll");
	SCHEMA(uint64, m_steamID, "m_steamID", "CBasePlayerController", "client.dll");
	SCHEMA(bool, m_bIsLocalPlayerController, "m_bIsLocalPlayerController", "CBasePlayerController", "client.dll");
	SCHEMA(bool, m_bNoClipEnabled, "m_bNoClipEnabled", "CBasePlayerController", "client.dll");
	SCHEMA(uint32, m_iDesiredFOV, "m_iDesiredFOV", "CBasePlayerController", "client.dll");
};

// Class: CCSPlayerController (Size: 0x948)
class CCSPlayerController : public CBasePlayerController {
public:
	SCHEMA(CCSPlayerController_InGameMoneyServices*, m_pInGameMoneyServices, "m_pInGameMoneyServices", "CCSPlayerController", "client.dll");
	SCHEMA(CCSPlayerController_InventoryServices*, m_pInventoryServices, "m_pInventoryServices", "CCSPlayerController", "client.dll");
	SCHEMA(CCSPlayerController_ActionTrackingServices*, m_pActionTrackingServices, "m_pActionTrackingServices", "CCSPlayerController", "client.dll");
	SCHEMA(CCSPlayerController_DamageServices*, m_pDamageServices, "m_pDamageServices", "CCSPlayerController", "client.dll");
	SCHEMA(uint32, m_iPing, "m_iPing", "CCSPlayerController", "client.dll");
	SCHEMA(bool, m_bHasCommunicationAbuseMute, "m_bHasCommunicationAbuseMute", "CCSPlayerController", "client.dll");
	SCHEMA(uint32, m_uiCommunicationMuteFlags, "m_uiCommunicationMuteFlags", "CCSPlayerController", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_szCrosshairCodes, "m_szCrosshairCodes", "CCSPlayerController", "client.dll");
	SCHEMA(uint8, m_iPendingTeamNum, "m_iPendingTeamNum", "CCSPlayerController", "client.dll");
	SCHEMA(GameTime_t, m_flForceTeamTime, "m_flForceTeamTime", "CCSPlayerController", "client.dll");
	SCHEMA(int32, m_iCompTeammateColor, "m_iCompTeammateColor", "CCSPlayerController", "client.dll");
	SCHEMA(bool, m_bEverPlayedOnTeam, "m_bEverPlayedOnTeam", "CCSPlayerController", "client.dll");
	SCHEMA(GameTime_t, m_flPreviousForceJoinTeamTime, "m_flPreviousForceJoinTeamTime", "CCSPlayerController", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_szClan, "m_szClan", "CCSPlayerController", "client.dll");
	SCHEMA(CUtlString, m_sSanitizedPlayerName, "m_sSanitizedPlayerName", "CCSPlayerController", "client.dll");
	SCHEMA(int32, m_iCoachingTeam, "m_iCoachingTeam", "CCSPlayerController", "client.dll");
	SCHEMA(uint64, m_nPlayerDominated, "m_nPlayerDominated", "CCSPlayerController", "client.dll");
	SCHEMA(uint64, m_nPlayerDominatingMe, "m_nPlayerDominatingMe", "CCSPlayerController", "client.dll");
	SCHEMA(int32, m_iCompetitiveRanking, "m_iCompetitiveRanking", "CCSPlayerController", "client.dll");
	SCHEMA(int32, m_iCompetitiveWins, "m_iCompetitiveWins", "CCSPlayerController", "client.dll");
	SCHEMA(int8, m_iCompetitiveRankType, "m_iCompetitiveRankType", "CCSPlayerController", "client.dll");
	SCHEMA(int32, m_iCompetitiveRankingPredicted_Win, "m_iCompetitiveRankingPredicted_Win", "CCSPlayerController", "client.dll");
	SCHEMA(int32, m_iCompetitiveRankingPredicted_Loss, "m_iCompetitiveRankingPredicted_Loss", "CCSPlayerController", "client.dll");
	SCHEMA(int32, m_iCompetitiveRankingPredicted_Tie, "m_iCompetitiveRankingPredicted_Tie", "CCSPlayerController", "client.dll");
	SCHEMA(int32, m_nEndMatchNextMapVote, "m_nEndMatchNextMapVote", "CCSPlayerController", "client.dll");
	SCHEMA(uint16, m_unActiveQuestId, "m_unActiveQuestId", "CCSPlayerController", "client.dll");
	SCHEMA(uint32, m_rtActiveMissionPeriod, "m_rtActiveMissionPeriod", "CCSPlayerController", "client.dll");
	SCHEMA(uint32, m_unPlayerTvControlFlags, "m_unPlayerTvControlFlags", "CCSPlayerController", "client.dll");
	SCHEMA(int32, m_iDraftIndex, "m_iDraftIndex", "CCSPlayerController", "client.dll");
	SCHEMA(uint32, m_msQueuedModeDisconnectionTimestamp, "m_msQueuedModeDisconnectionTimestamp", "CCSPlayerController", "client.dll");
	SCHEMA(uint32, m_uiAbandonRecordedReason, "m_uiAbandonRecordedReason", "CCSPlayerController", "client.dll");
	SCHEMA(uint32, m_eNetworkDisconnectionReason, "m_eNetworkDisconnectionReason", "CCSPlayerController", "client.dll");
	SCHEMA(bool, m_bCannotBeKicked, "m_bCannotBeKicked", "CCSPlayerController", "client.dll");
	SCHEMA(bool, m_bEverFullyConnected, "m_bEverFullyConnected", "CCSPlayerController", "client.dll");
	SCHEMA(bool, m_bAbandonAllowsSurrender, "m_bAbandonAllowsSurrender", "CCSPlayerController", "client.dll");
	SCHEMA(bool, m_bAbandonOffersInstantSurrender, "m_bAbandonOffersInstantSurrender", "CCSPlayerController", "client.dll");
	SCHEMA(bool, m_bDisconnection1MinWarningPrinted, "m_bDisconnection1MinWarningPrinted", "CCSPlayerController", "client.dll");
	SCHEMA(bool, m_bScoreReported, "m_bScoreReported", "CCSPlayerController", "client.dll");
	SCHEMA(int32, m_nDisconnectionTick, "m_nDisconnectionTick", "CCSPlayerController", "client.dll");
	SCHEMA(bool, m_bControllingBot, "m_bControllingBot", "CCSPlayerController", "client.dll");
	SCHEMA(bool, m_bHasControlledBotThisRound, "m_bHasControlledBotThisRound", "CCSPlayerController", "client.dll");
	SCHEMA(bool, m_bHasBeenControlledByPlayerThisRound, "m_bHasBeenControlledByPlayerThisRound", "CCSPlayerController", "client.dll");
	SCHEMA(int32, m_nBotsControlledThisRound, "m_nBotsControlledThisRound", "CCSPlayerController", "client.dll");
	SCHEMA(bool, m_bCanControlObservedBot, "m_bCanControlObservedBot", "CCSPlayerController", "client.dll");
	SCHEMA(CHandle, m_hPlayerPawn, "m_hPlayerPawn", "CCSPlayerController", "client.dll");
	SCHEMA(CHandle, m_hObserverPawn, "m_hObserverPawn", "CCSPlayerController", "client.dll");
	SCHEMA(bool, m_bPawnIsAlive, "m_bPawnIsAlive", "CCSPlayerController", "client.dll");
	SCHEMA(uint32, m_iPawnHealth, "m_iPawnHealth", "CCSPlayerController", "client.dll");
	SCHEMA(int32, m_iPawnArmor, "m_iPawnArmor", "CCSPlayerController", "client.dll");
	SCHEMA(bool, m_bPawnHasDefuser, "m_bPawnHasDefuser", "CCSPlayerController", "client.dll");
	SCHEMA(bool, m_bPawnHasHelmet, "m_bPawnHasHelmet", "CCSPlayerController", "client.dll");
	SCHEMA(uint16, m_nPawnCharacterDefIndex, "m_nPawnCharacterDefIndex", "CCSPlayerController", "client.dll");
	SCHEMA(int32, m_iPawnLifetimeStart, "m_iPawnLifetimeStart", "CCSPlayerController", "client.dll");
	SCHEMA(int32, m_iPawnLifetimeEnd, "m_iPawnLifetimeEnd", "CCSPlayerController", "client.dll");
	SCHEMA(int32, m_iPawnBotDifficulty, "m_iPawnBotDifficulty", "CCSPlayerController", "client.dll");
	SCHEMA(CHandle, m_hOriginalControllerOfCurrentPawn, "m_hOriginalControllerOfCurrentPawn", "CCSPlayerController", "client.dll");
	SCHEMA(int32, m_iScore, "m_iScore", "CCSPlayerController", "client.dll");
	SCHEMA(uint8*, m_recentKillQueue, "m_recentKillQueue", "CCSPlayerController", "client.dll");
	SCHEMA(uint8, m_nFirstKill, "m_nFirstKill", "CCSPlayerController", "client.dll");
	SCHEMA(uint8, m_nKillCount, "m_nKillCount", "CCSPlayerController", "client.dll");
	SCHEMA(bool, m_bMvpNoMusic, "m_bMvpNoMusic", "CCSPlayerController", "client.dll");
	SCHEMA(int32, m_eMvpReason, "m_eMvpReason", "CCSPlayerController", "client.dll");
	SCHEMA(int32, m_iMusicKitID, "m_iMusicKitID", "CCSPlayerController", "client.dll");
	SCHEMA(int32, m_iMusicKitMVPs, "m_iMusicKitMVPs", "CCSPlayerController", "client.dll");
	SCHEMA(int32, m_iMVPs, "m_iMVPs", "CCSPlayerController", "client.dll");
	SCHEMA(bool, m_bIsPlayerNameDirty, "m_bIsPlayerNameDirty", "CCSPlayerController", "client.dll");
	SCHEMA(bool, m_bFireBulletsSeedSynchronized, "m_bFireBulletsSeedSynchronized", "CCSPlayerController", "client.dll");
};

// Class: CCitadelSoundOpvarSetOBB (Size: 0x660)
class CCitadelSoundOpvarSetOBB : public C_BaseEntity {
public:
	SCHEMA(CUtlSymbolLarge, m_iszStackName, "m_iszStackName", "CCitadelSoundOpvarSetOBB", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_iszOperatorName, "m_iszOperatorName", "CCitadelSoundOpvarSetOBB", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_iszOpvarName, "m_iszOpvarName", "CCitadelSoundOpvarSetOBB", "client.dll");
	SCHEMA(Vector, m_vDistanceInnerMins, "m_vDistanceInnerMins", "CCitadelSoundOpvarSetOBB", "client.dll");
	SCHEMA(Vector, m_vDistanceInnerMaxs, "m_vDistanceInnerMaxs", "CCitadelSoundOpvarSetOBB", "client.dll");
	SCHEMA(Vector, m_vDistanceOuterMins, "m_vDistanceOuterMins", "CCitadelSoundOpvarSetOBB", "client.dll");
	SCHEMA(Vector, m_vDistanceOuterMaxs, "m_vDistanceOuterMaxs", "CCitadelSoundOpvarSetOBB", "client.dll");
	SCHEMA(int32, m_nAABBDirection, "m_nAABBDirection", "CCitadelSoundOpvarSetOBB", "client.dll");
};

// Class: CEnvSoundscape (Size: 0x698)
class CEnvSoundscape : public C_BaseEntity {
public:
	SCHEMA(CEntityIOOutput, m_OnPlay, "m_OnPlay", "CEnvSoundscape", "client.dll");
	SCHEMA(float32, m_flRadius, "m_flRadius", "CEnvSoundscape", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_soundEventName, "m_soundEventName", "CEnvSoundscape", "client.dll");
	SCHEMA(bool, m_bOverrideWithEvent, "m_bOverrideWithEvent", "CEnvSoundscape", "client.dll");
	SCHEMA(int32, m_soundscapeIndex, "m_soundscapeIndex", "CEnvSoundscape", "client.dll");
	SCHEMA(int32, m_soundscapeEntityListId, "m_soundscapeEntityListId", "CEnvSoundscape", "client.dll");
	SCHEMA(CUtlSymbolLarge*, m_positionNames, "m_positionNames", "CEnvSoundscape", "client.dll");
	SCHEMA(CHandle, m_hProxySoundscape, "m_hProxySoundscape", "CEnvSoundscape", "client.dll");
	SCHEMA(bool, m_bDisabled, "m_bDisabled", "CEnvSoundscape", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_soundscapeName, "m_soundscapeName", "CEnvSoundscape", "client.dll");
	SCHEMA(uint32, m_soundEventHash, "m_soundEventHash", "CEnvSoundscape", "client.dll");
};

// Class: CEnvSoundscapeProxy (Size: 0x6A0)
class CEnvSoundscapeProxy : public CEnvSoundscape {
public:
	SCHEMA(CUtlSymbolLarge, m_MainSoundscapeName, "m_MainSoundscapeName", "CEnvSoundscapeProxy", "client.dll");
};

// Class: CInfoWorldLayer (Size: 0x640)
class CInfoWorldLayer : public C_BaseEntity {
public:
	SCHEMA(CEntityIOOutput, m_pOutputOnEntitiesSpawned, "m_pOutputOnEntitiesSpawned", "CInfoWorldLayer", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_worldName, "m_worldName", "CInfoWorldLayer", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_layerName, "m_layerName", "CInfoWorldLayer", "client.dll");
	SCHEMA(bool, m_bWorldLayerVisible, "m_bWorldLayerVisible", "CInfoWorldLayer", "client.dll");
	SCHEMA(bool, m_bEntitiesSpawned, "m_bEntitiesSpawned", "CInfoWorldLayer", "client.dll");
	SCHEMA(bool, m_bCreateAsChildSpawnGroup, "m_bCreateAsChildSpawnGroup", "CInfoWorldLayer", "client.dll");
	SCHEMA(uint32, m_hLayerSpawnGroup, "m_hLayerSpawnGroup", "CInfoWorldLayer", "client.dll");
	SCHEMA(bool, m_bWorldLayerActuallyVisible, "m_bWorldLayerActuallyVisible", "CInfoWorldLayer", "client.dll");
};

// Class: CPathSimple (Size: 0x700)
class CPathSimple : public C_BaseEntity {
public:
	SCHEMA(CPathQueryComponent, m_CPathQueryComponent, "m_CPathQueryComponent", "CPathSimple", "client.dll");
	SCHEMA(CUtlString, m_pathString, "m_pathString", "CPathSimple", "client.dll");
	SCHEMA(bool, m_bClosedLoop, "m_bClosedLoop", "CPathSimple", "client.dll");
};

// Class: CPointOrient (Size: 0x618)
class CPointOrient : public C_BaseEntity {
public:
	SCHEMA(CUtlSymbolLarge, m_iszSpawnTargetName, "m_iszSpawnTargetName", "CPointOrient", "client.dll");
	SCHEMA(CHandle, m_hTarget, "m_hTarget", "CPointOrient", "client.dll");
	SCHEMA(bool, m_bActive, "m_bActive", "CPointOrient", "client.dll");
	SCHEMA(PointOrientGoalDirectionType_t, m_nGoalDirection, "m_nGoalDirection", "CPointOrient", "client.dll");
	SCHEMA(PointOrientConstraint_t, m_nConstraint, "m_nConstraint", "CPointOrient", "client.dll");
	SCHEMA(float32, m_flMaxTurnRate, "m_flMaxTurnRate", "CPointOrient", "client.dll");
	SCHEMA(GameTime_t, m_flLastGameTime, "m_flLastGameTime", "CPointOrient", "client.dll");
};

// Class: CPulseGameBlackboard (Size: 0x610)
class CPulseGameBlackboard : public C_BaseEntity {
public:
	SCHEMA(CUtlString, m_strGraphName, "m_strGraphName", "CPulseGameBlackboard", "client.dll");
	SCHEMA(CUtlString, m_strStateBlob, "m_strStateBlob", "CPulseGameBlackboard", "client.dll");
};

// Class: CRagdollManager (Size: 0x600)
class CRagdollManager : public C_BaseEntity {
public:
	SCHEMA(int8, m_iCurrentMaxRagdollCount, "m_iCurrentMaxRagdollCount", "CRagdollManager", "client.dll");
};

// Class: CSkyboxReference (Size: 0x600)
class CSkyboxReference : public C_BaseEntity {
public:
	SCHEMA(WorldGroupId_t, m_worldGroupId, "m_worldGroupId", "CSkyboxReference", "client.dll");
	SCHEMA(CHandle, m_hSkyCamera, "m_hSkyCamera", "CSkyboxReference", "client.dll");
};

// Class: C_BaseModelEntity (Size: 0xEB0)
class C_BaseModelEntity : public C_BaseEntity {
public:
	SCHEMA(CRenderComponent*, m_CRenderComponent, "m_CRenderComponent", "C_BaseModelEntity", "client.dll");
	SCHEMA(CHitboxComponent, m_CHitboxComponent, "m_CHitboxComponent", "C_BaseModelEntity", "client.dll");
	SCHEMA(CDestructiblePartsComponent*, m_pDestructiblePartsSystemComponent, "m_pDestructiblePartsSystemComponent", "C_BaseModelEntity", "client.dll");
	SCHEMA(HitGroup_t, m_LastHitGroup, "m_LastHitGroup", "C_BaseModelEntity", "client.dll");
	SCHEMA(CGlobalSymbol, m_sLastDamageSourceName, "m_sLastDamageSourceName", "C_BaseModelEntity", "client.dll");
	SCHEMA(VectorWS, m_vLastDamagePosition, "m_vLastDamagePosition", "C_BaseModelEntity", "client.dll");
	SCHEMA(bool, m_bInitModelEffects, "m_bInitModelEffects", "C_BaseModelEntity", "client.dll");
	SCHEMA(bool, m_bIsStaticProp, "m_bIsStaticProp", "C_BaseModelEntity", "client.dll");
	SCHEMA(int32, m_nLastAddDecal, "m_nLastAddDecal", "C_BaseModelEntity", "client.dll");
	SCHEMA(int32, m_nDecalsAdded, "m_nDecalsAdded", "C_BaseModelEntity", "client.dll");
	SCHEMA(int32, m_iOldHealth, "m_iOldHealth", "C_BaseModelEntity", "client.dll");
	SCHEMA(RenderMode_t, m_nRenderMode, "m_nRenderMode", "C_BaseModelEntity", "client.dll");
	SCHEMA(RenderFx_t, m_nRenderFX, "m_nRenderFX", "C_BaseModelEntity", "client.dll");
	SCHEMA(bool, m_bAllowFadeInView, "m_bAllowFadeInView", "C_BaseModelEntity", "client.dll");
	SCHEMA(Color, m_clrRender, "m_clrRender", "C_BaseModelEntity", "client.dll");
	SCHEMA(CUtlVector< EntityRenderAttribute_t >, m_vecRenderAttributes, "m_vecRenderAttributes", "C_BaseModelEntity", "client.dll");
	SCHEMA(bool, m_bRenderToCubemaps, "m_bRenderToCubemaps", "C_BaseModelEntity", "client.dll");
	SCHEMA(bool, m_bNoInterpolate, "m_bNoInterpolate", "C_BaseModelEntity", "client.dll");
	SCHEMA(CCollisionProperty, m_Collision, "m_Collision", "C_BaseModelEntity", "client.dll");
	SCHEMA(CGlowProperty, m_Glow, "m_Glow", "C_BaseModelEntity", "client.dll");
	SCHEMA(float32, m_flGlowBackfaceMult, "m_flGlowBackfaceMult", "C_BaseModelEntity", "client.dll");
	SCHEMA(float32, m_fadeMinDist, "m_fadeMinDist", "C_BaseModelEntity", "client.dll");
	SCHEMA(float32, m_fadeMaxDist, "m_fadeMaxDist", "C_BaseModelEntity", "client.dll");
	SCHEMA(float32, m_flFadeScale, "m_flFadeScale", "C_BaseModelEntity", "client.dll");
	SCHEMA(float32, m_flShadowStrength, "m_flShadowStrength", "C_BaseModelEntity", "client.dll");
	SCHEMA(uint8, m_nObjectCulling, "m_nObjectCulling", "C_BaseModelEntity", "client.dll");
	SCHEMA(int32, m_nAddDecal, "m_nAddDecal", "C_BaseModelEntity", "client.dll");
	SCHEMA(Vector, m_vDecalPosition, "m_vDecalPosition", "C_BaseModelEntity", "client.dll");
	SCHEMA(Vector, m_vDecalForwardAxis, "m_vDecalForwardAxis", "C_BaseModelEntity", "client.dll");
	SCHEMA(DecalMode_t, m_nDecalMode, "m_nDecalMode", "C_BaseModelEntity", "client.dll");
	SCHEMA(DecalMode_t, m_nRequiredDecalMode, "m_nRequiredDecalMode", "C_BaseModelEntity", "client.dll");
	SCHEMA(CUtlVector< CHandle >, m_ConfigEntitiesToPropagateMaterialDecalsTo, "m_ConfigEntitiesToPropagateMaterialDecalsTo", "C_BaseModelEntity", "client.dll");
	SCHEMA(CNetworkViewOffsetVector, m_vecViewOffset, "m_vecViewOffset", "C_BaseModelEntity", "client.dll");
	SCHEMA(CClientAlphaProperty*, m_pClientAlphaProperty, "m_pClientAlphaProperty", "C_BaseModelEntity", "client.dll");
	SCHEMA(Color, m_ClientOverrideTint, "m_ClientOverrideTint", "C_BaseModelEntity", "client.dll");
	SCHEMA(bool, m_bUseClientOverrideTint, "m_bUseClientOverrideTint", "C_BaseModelEntity", "client.dll");
	SCHEMA(uint32*, m_bvDisabledHitGroups, "m_bvDisabledHitGroups", "C_BaseModelEntity", "client.dll");
};

// Class: CBaseAnimGraph (Size: 0x1158)
class CBaseAnimGraph : public C_BaseModelEntity {
public:
	SCHEMA(bool, m_bInitiallyPopulateInterpHistory, "m_bInitiallyPopulateInterpHistory", "CBaseAnimGraph", "client.dll");
	SCHEMA(bool, m_bSuppressAnimEventSounds, "m_bSuppressAnimEventSounds", "CBaseAnimGraph", "client.dll");
	SCHEMA(bool, m_bAnimGraphUpdateEnabled, "m_bAnimGraphUpdateEnabled", "CBaseAnimGraph", "client.dll");
	SCHEMA(float32, m_flMaxSlopeDistance, "m_flMaxSlopeDistance", "CBaseAnimGraph", "client.dll");
	SCHEMA(VectorWS, m_vLastSlopeCheckPos, "m_vLastSlopeCheckPos", "CBaseAnimGraph", "client.dll");
	SCHEMA(bool, m_bAnimationUpdateScheduled, "m_bAnimationUpdateScheduled", "CBaseAnimGraph", "client.dll");
	SCHEMA(Vector, m_vecForce, "m_vecForce", "CBaseAnimGraph", "client.dll");
	SCHEMA(int32, m_nForceBone, "m_nForceBone", "CBaseAnimGraph", "client.dll");
	SCHEMA(CBaseAnimGraph*, m_pClientsideRagdoll, "m_pClientsideRagdoll", "CBaseAnimGraph", "client.dll");
	SCHEMA(bool, m_bBuiltRagdoll, "m_bBuiltRagdoll", "CBaseAnimGraph", "client.dll");
	SCHEMA(PhysicsRagdollPose_t, m_RagdollPose, "m_RagdollPose", "CBaseAnimGraph", "client.dll");
	SCHEMA(bool, m_bRagdollEnabled, "m_bRagdollEnabled", "CBaseAnimGraph", "client.dll");
	SCHEMA(bool, m_bRagdollClientSide, "m_bRagdollClientSide", "CBaseAnimGraph", "client.dll");
	SCHEMA(bool, m_bHasAnimatedMaterialAttributes, "m_bHasAnimatedMaterialAttributes", "CBaseAnimGraph", "client.dll");
};

// Class: CBaseProp (Size: 0x1190)
class CBaseProp : public CBaseAnimGraph {
public:
	SCHEMA(bool, m_bModelOverrodeBlockLOS, "m_bModelOverrodeBlockLOS", "CBaseProp", "client.dll");
	SCHEMA(int32, m_iShapeType, "m_iShapeType", "CBaseProp", "client.dll");
	SCHEMA(bool, m_bConformToCollisionBounds, "m_bConformToCollisionBounds", "CBaseProp", "client.dll");
	SCHEMA(CTransform, m_mPreferredCatchTransform, "m_mPreferredCatchTransform", "CBaseProp", "client.dll");
};

// Class: CFuncWater (Size: 0xFC8)
class CFuncWater : public C_BaseModelEntity {
public:
	SCHEMA(CBuoyancyHelper, m_BuoyancyHelper, "m_BuoyancyHelper", "CFuncWater", "client.dll");
};

// Class: CGrenadeTracer (Size: 0x1390)
class CGrenadeTracer : public C_BaseModelEntity {
public:
	SCHEMA(float32, m_flTracerDuration, "m_flTracerDuration", "CGrenadeTracer", "client.dll");
	SCHEMA(GrenadeType_t, m_nType, "m_nType", "CGrenadeTracer", "client.dll");
};

// Class: C_BarnLight (Size: 0x1200)
class C_BarnLight : public C_BaseModelEntity {
public:
	SCHEMA(bool, m_bEnabled, "m_bEnabled", "C_BarnLight", "client.dll");
	SCHEMA(int32, m_nColorMode, "m_nColorMode", "C_BarnLight", "client.dll");
	SCHEMA(Color, m_Color, "m_Color", "C_BarnLight", "client.dll");
	SCHEMA(float32, m_flColorTemperature, "m_flColorTemperature", "C_BarnLight", "client.dll");
	SCHEMA(float32, m_flBrightness, "m_flBrightness", "C_BarnLight", "client.dll");
	SCHEMA(float32, m_flBrightnessScale, "m_flBrightnessScale", "C_BarnLight", "client.dll");
	SCHEMA(int32, m_nDirectLight, "m_nDirectLight", "C_BarnLight", "client.dll");
	SCHEMA(int32, m_nBakedShadowIndex, "m_nBakedShadowIndex", "C_BarnLight", "client.dll");
	SCHEMA(int32, m_nLightPathUniqueId, "m_nLightPathUniqueId", "C_BarnLight", "client.dll");
	SCHEMA(int32, m_nLightMapUniqueId, "m_nLightMapUniqueId", "C_BarnLight", "client.dll");
	SCHEMA(int32, m_nLuminaireShape, "m_nLuminaireShape", "C_BarnLight", "client.dll");
	SCHEMA(float32, m_flLuminaireSize, "m_flLuminaireSize", "C_BarnLight", "client.dll");
	SCHEMA(float32, m_flLuminaireAnisotropy, "m_flLuminaireAnisotropy", "C_BarnLight", "client.dll");
	SCHEMA(CUtlString, m_LightStyleString, "m_LightStyleString", "C_BarnLight", "client.dll");
	SCHEMA(GameTime_t, m_flLightStyleStartTime, "m_flLightStyleStartTime", "C_BarnLight", "client.dll");
	SCHEMA(CEntityIOOutput*, m_StyleEvent, "m_StyleEvent", "C_BarnLight", "client.dll");
	SCHEMA(float32, m_flShape, "m_flShape", "C_BarnLight", "client.dll");
	SCHEMA(float32, m_flSoftX, "m_flSoftX", "C_BarnLight", "client.dll");
	SCHEMA(float32, m_flSoftY, "m_flSoftY", "C_BarnLight", "client.dll");
	SCHEMA(float32, m_flSkirt, "m_flSkirt", "C_BarnLight", "client.dll");
	SCHEMA(float32, m_flSkirtNear, "m_flSkirtNear", "C_BarnLight", "client.dll");
	SCHEMA(Vector, m_vSizeParams, "m_vSizeParams", "C_BarnLight", "client.dll");
	SCHEMA(float32, m_flRange, "m_flRange", "C_BarnLight", "client.dll");
	SCHEMA(Vector, m_vShear, "m_vShear", "C_BarnLight", "client.dll");
	SCHEMA(int32, m_nBakeSpecularToCubemaps, "m_nBakeSpecularToCubemaps", "C_BarnLight", "client.dll");
	SCHEMA(Vector, m_vBakeSpecularToCubemapsSize, "m_vBakeSpecularToCubemapsSize", "C_BarnLight", "client.dll");
	SCHEMA(int32, m_nCastShadows, "m_nCastShadows", "C_BarnLight", "client.dll");
	SCHEMA(int32, m_nShadowMapSize, "m_nShadowMapSize", "C_BarnLight", "client.dll");
	SCHEMA(int32, m_nShadowPriority, "m_nShadowPriority", "C_BarnLight", "client.dll");
	SCHEMA(bool, m_bContactShadow, "m_bContactShadow", "C_BarnLight", "client.dll");
	SCHEMA(bool, m_bForceShadowsEnabled, "m_bForceShadowsEnabled", "C_BarnLight", "client.dll");
	SCHEMA(int32, m_nBounceLight, "m_nBounceLight", "C_BarnLight", "client.dll");
	SCHEMA(float32, m_flBounceScale, "m_flBounceScale", "C_BarnLight", "client.dll");
	SCHEMA(float32, m_flMinRoughness, "m_flMinRoughness", "C_BarnLight", "client.dll");
	SCHEMA(Vector, m_vAlternateColor, "m_vAlternateColor", "C_BarnLight", "client.dll");
	SCHEMA(float32, m_fAlternateColorBrightness, "m_fAlternateColorBrightness", "C_BarnLight", "client.dll");
	SCHEMA(int32, m_nFog, "m_nFog", "C_BarnLight", "client.dll");
	SCHEMA(float32, m_flFogStrength, "m_flFogStrength", "C_BarnLight", "client.dll");
	SCHEMA(int32, m_nFogShadows, "m_nFogShadows", "C_BarnLight", "client.dll");
	SCHEMA(float32, m_flFogScale, "m_flFogScale", "C_BarnLight", "client.dll");
	SCHEMA(bool, m_bFogMixedShadows, "m_bFogMixedShadows", "C_BarnLight", "client.dll");
	SCHEMA(float32, m_flFadeSizeStart, "m_flFadeSizeStart", "C_BarnLight", "client.dll");
	SCHEMA(float32, m_flFadeSizeEnd, "m_flFadeSizeEnd", "C_BarnLight", "client.dll");
	SCHEMA(float32, m_flShadowFadeSizeStart, "m_flShadowFadeSizeStart", "C_BarnLight", "client.dll");
	SCHEMA(float32, m_flShadowFadeSizeEnd, "m_flShadowFadeSizeEnd", "C_BarnLight", "client.dll");
	SCHEMA(bool, m_bPrecomputedFieldsValid, "m_bPrecomputedFieldsValid", "C_BarnLight", "client.dll");
	SCHEMA(Vector, m_vPrecomputedBoundsMins, "m_vPrecomputedBoundsMins", "C_BarnLight", "client.dll");
	SCHEMA(Vector, m_vPrecomputedBoundsMaxs, "m_vPrecomputedBoundsMaxs", "C_BarnLight", "client.dll");
	SCHEMA(Vector, m_vPrecomputedOBBOrigin, "m_vPrecomputedOBBOrigin", "C_BarnLight", "client.dll");
	SCHEMA(QAngle, m_vPrecomputedOBBAngles, "m_vPrecomputedOBBAngles", "C_BarnLight", "client.dll");
	SCHEMA(Vector, m_vPrecomputedOBBExtent, "m_vPrecomputedOBBExtent", "C_BarnLight", "client.dll");
	SCHEMA(int32, m_nPrecomputedSubFrusta, "m_nPrecomputedSubFrusta", "C_BarnLight", "client.dll");
	SCHEMA(Vector, m_vPrecomputedOBBOrigin0, "m_vPrecomputedOBBOrigin0", "C_BarnLight", "client.dll");
	SCHEMA(QAngle, m_vPrecomputedOBBAngles0, "m_vPrecomputedOBBAngles0", "C_BarnLight", "client.dll");
	SCHEMA(Vector, m_vPrecomputedOBBExtent0, "m_vPrecomputedOBBExtent0", "C_BarnLight", "client.dll");
	SCHEMA(Vector, m_vPrecomputedOBBOrigin1, "m_vPrecomputedOBBOrigin1", "C_BarnLight", "client.dll");
	SCHEMA(QAngle, m_vPrecomputedOBBAngles1, "m_vPrecomputedOBBAngles1", "C_BarnLight", "client.dll");
	SCHEMA(Vector, m_vPrecomputedOBBExtent1, "m_vPrecomputedOBBExtent1", "C_BarnLight", "client.dll");
	SCHEMA(Vector, m_vPrecomputedOBBOrigin2, "m_vPrecomputedOBBOrigin2", "C_BarnLight", "client.dll");
	SCHEMA(QAngle, m_vPrecomputedOBBAngles2, "m_vPrecomputedOBBAngles2", "C_BarnLight", "client.dll");
	SCHEMA(Vector, m_vPrecomputedOBBExtent2, "m_vPrecomputedOBBExtent2", "C_BarnLight", "client.dll");
	SCHEMA(Vector, m_vPrecomputedOBBOrigin3, "m_vPrecomputedOBBOrigin3", "C_BarnLight", "client.dll");
	SCHEMA(QAngle, m_vPrecomputedOBBAngles3, "m_vPrecomputedOBBAngles3", "C_BarnLight", "client.dll");
	SCHEMA(Vector, m_vPrecomputedOBBExtent3, "m_vPrecomputedOBBExtent3", "C_BarnLight", "client.dll");
	SCHEMA(Vector, m_vPrecomputedOBBOrigin4, "m_vPrecomputedOBBOrigin4", "C_BarnLight", "client.dll");
	SCHEMA(QAngle, m_vPrecomputedOBBAngles4, "m_vPrecomputedOBBAngles4", "C_BarnLight", "client.dll");
	SCHEMA(Vector, m_vPrecomputedOBBExtent4, "m_vPrecomputedOBBExtent4", "C_BarnLight", "client.dll");
	SCHEMA(Vector, m_vPrecomputedOBBOrigin5, "m_vPrecomputedOBBOrigin5", "C_BarnLight", "client.dll");
	SCHEMA(QAngle, m_vPrecomputedOBBAngles5, "m_vPrecomputedOBBAngles5", "C_BarnLight", "client.dll");
	SCHEMA(Vector, m_vPrecomputedOBBExtent5, "m_vPrecomputedOBBExtent5", "C_BarnLight", "client.dll");
	SCHEMA(bool, m_bInitialBoneSetup, "m_bInitialBoneSetup", "C_BarnLight", "client.dll");
};

// Class: C_BaseClientUIEntity (Size: 0xEE0)
class C_BaseClientUIEntity : public C_BaseModelEntity {
public:
	SCHEMA(bool, m_bEnabled, "m_bEnabled", "C_BaseClientUIEntity", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_DialogXMLName, "m_DialogXMLName", "C_BaseClientUIEntity", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_PanelClassName, "m_PanelClassName", "C_BaseClientUIEntity", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_PanelID, "m_PanelID", "C_BaseClientUIEntity", "client.dll");
};

// Class: C_BaseFlex (Size: 0x1368)
class C_BaseFlex : public CBaseAnimGraph {
public:
	SCHEMA(CUtlVector< float32 >, m_flexWeight, "m_flexWeight", "C_BaseFlex", "client.dll");
	SCHEMA(VectorWS, m_vLookTargetPosition, "m_vLookTargetPosition", "C_BaseFlex", "client.dll");
	SCHEMA(bool, m_blinktoggle, "m_blinktoggle", "C_BaseFlex", "client.dll");
	SCHEMA(int32, m_nLastFlexUpdateFrameCount, "m_nLastFlexUpdateFrameCount", "C_BaseFlex", "client.dll");
	SCHEMA(Vector, m_CachedViewTarget, "m_CachedViewTarget", "C_BaseFlex", "client.dll");
	SCHEMA(SceneEventId_t, m_nNextSceneEventId, "m_nNextSceneEventId", "C_BaseFlex", "client.dll");
	SCHEMA(int32, m_iBlink, "m_iBlink", "C_BaseFlex", "client.dll");
	SCHEMA(float32, m_blinktime, "m_blinktime", "C_BaseFlex", "client.dll");
	SCHEMA(bool, m_prevblinktoggle, "m_prevblinktoggle", "C_BaseFlex", "client.dll");
	SCHEMA(int32, m_iJawOpen, "m_iJawOpen", "C_BaseFlex", "client.dll");
	SCHEMA(float32, m_flJawOpenAmount, "m_flJawOpenAmount", "C_BaseFlex", "client.dll");
	SCHEMA(float32, m_flBlinkAmount, "m_flBlinkAmount", "C_BaseFlex", "client.dll");
	SCHEMA(AttachmentHandle_t, m_iMouthAttachment, "m_iMouthAttachment", "C_BaseFlex", "client.dll");
	SCHEMA(AttachmentHandle_t, m_iEyeAttachment, "m_iEyeAttachment", "C_BaseFlex", "client.dll");
	SCHEMA(bool, m_bResetFlexWeightsOnModelChange, "m_bResetFlexWeightsOnModelChange", "C_BaseFlex", "client.dll");
	SCHEMA(int32, m_nEyeOcclusionRendererBone, "m_nEyeOcclusionRendererBone", "C_BaseFlex", "client.dll");
	SCHEMA(matrix3x4_t, m_mEyeOcclusionRendererCameraToBoneTransform, "m_mEyeOcclusionRendererCameraToBoneTransform", "C_BaseFlex", "client.dll");
	SCHEMA(Vector, m_vEyeOcclusionRendererHalfExtent, "m_vEyeOcclusionRendererHalfExtent", "C_BaseFlex", "client.dll");
};

// Class: C_BaseCombatCharacter (Size: 0x13F0)
class C_BaseCombatCharacter : public C_BaseFlex {
public:
	SCHEMA(CUtlVector< CHandle >, m_hMyWearables, "m_hMyWearables", "C_BaseCombatCharacter", "client.dll");
	SCHEMA(AttachmentHandle_t, m_leftFootAttachment, "m_leftFootAttachment", "C_BaseCombatCharacter", "client.dll");
	SCHEMA(AttachmentHandle_t, m_rightFootAttachment, "m_rightFootAttachment", "C_BaseCombatCharacter", "client.dll");
	SCHEMA(float32, m_flWaterWorldZ, "m_flWaterWorldZ", "C_BaseCombatCharacter", "client.dll");
	SCHEMA(float32, m_flWaterNextTraceTime, "m_flWaterNextTraceTime", "C_BaseCombatCharacter", "client.dll");
};

// Class: C_BaseGrenade (Size: 0x13B8)
class C_BaseGrenade : public C_BaseFlex {
public:
	SCHEMA(bool, m_bHasWarnedAI, "m_bHasWarnedAI", "C_BaseGrenade", "client.dll");
	SCHEMA(bool, m_bIsSmokeGrenade, "m_bIsSmokeGrenade", "C_BaseGrenade", "client.dll");
	SCHEMA(bool, m_bIsLive, "m_bIsLive", "C_BaseGrenade", "client.dll");
	SCHEMA(float32, m_DmgRadius, "m_DmgRadius", "C_BaseGrenade", "client.dll");
	SCHEMA(GameTime_t, m_flDetonateTime, "m_flDetonateTime", "C_BaseGrenade", "client.dll");
	SCHEMA(float32, m_flWarnAITime, "m_flWarnAITime", "C_BaseGrenade", "client.dll");
	SCHEMA(float32, m_flDamage, "m_flDamage", "C_BaseGrenade", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_iszBounceSound, "m_iszBounceSound", "C_BaseGrenade", "client.dll");
	SCHEMA(CUtlString, m_ExplosionSound, "m_ExplosionSound", "C_BaseGrenade", "client.dll");
	SCHEMA(CHandle, m_hThrower, "m_hThrower", "C_BaseGrenade", "client.dll");
	SCHEMA(GameTime_t, m_flNextAttack, "m_flNextAttack", "C_BaseGrenade", "client.dll");
	SCHEMA(CHandle, m_hOriginalThrower, "m_hOriginalThrower", "C_BaseGrenade", "client.dll");
};

// Class: C_BaseCSGrenadeProjectile (Size: 0x1450)
class C_BaseCSGrenadeProjectile : public C_BaseGrenade {
public:
	SCHEMA(Vector, m_vInitialPosition, "m_vInitialPosition", "C_BaseCSGrenadeProjectile", "client.dll");
	SCHEMA(Vector, m_vInitialVelocity, "m_vInitialVelocity", "C_BaseCSGrenadeProjectile", "client.dll");
	SCHEMA(int32, m_nBounces, "m_nBounces", "C_BaseCSGrenadeProjectile", "client.dll");
	SCHEMA(int32, m_nExplodeEffectTickBegin, "m_nExplodeEffectTickBegin", "C_BaseCSGrenadeProjectile", "client.dll");
	SCHEMA(Vector, m_vecExplodeEffectOrigin, "m_vecExplodeEffectOrigin", "C_BaseCSGrenadeProjectile", "client.dll");
	SCHEMA(GameTime_t, m_flSpawnTime, "m_flSpawnTime", "C_BaseCSGrenadeProjectile", "client.dll");
	SCHEMA(Vector, vecLastTrailLinePos, "vecLastTrailLinePos", "C_BaseCSGrenadeProjectile", "client.dll");
	SCHEMA(GameTime_t, flNextTrailLineTime, "flNextTrailLineTime", "C_BaseCSGrenadeProjectile", "client.dll");
	SCHEMA(bool, m_bExplodeEffectBegan, "m_bExplodeEffectBegan", "C_BaseCSGrenadeProjectile", "client.dll");
	SCHEMA(bool, m_bCanCreateGrenadeTrail, "m_bCanCreateGrenadeTrail", "C_BaseCSGrenadeProjectile", "client.dll");
	SCHEMA(ParticleIndex_t, m_nSnapshotTrajectoryEffectIndex, "m_nSnapshotTrajectoryEffectIndex", "C_BaseCSGrenadeProjectile", "client.dll");
	SCHEMA(CUtlVector< Vector >, m_arrTrajectoryTrailPoints, "m_arrTrajectoryTrailPoints", "C_BaseCSGrenadeProjectile", "client.dll");
	SCHEMA(CUtlVector< float32 >, m_arrTrajectoryTrailPointCreationTimes, "m_arrTrajectoryTrailPointCreationTimes", "C_BaseCSGrenadeProjectile", "client.dll");
	SCHEMA(float32, m_flTrajectoryTrailEffectCreationTime, "m_flTrajectoryTrailEffectCreationTime", "C_BaseCSGrenadeProjectile", "client.dll");
};

// Class: C_BasePlayerPawn (Size: 0x15C8)
class C_BasePlayerPawn : public C_BaseCombatCharacter {
public:
	SCHEMA(CPlayer_WeaponServices*, m_pWeaponServices, "m_pWeaponServices", "C_BasePlayerPawn", "client.dll");
	SCHEMA(CPlayer_ItemServices*, m_pItemServices, "m_pItemServices", "C_BasePlayerPawn", "client.dll");
	SCHEMA(CPlayer_AutoaimServices*, m_pAutoaimServices, "m_pAutoaimServices", "C_BasePlayerPawn", "client.dll");
	SCHEMA(CPlayer_ObserverServices*, m_pObserverServices, "m_pObserverServices", "C_BasePlayerPawn", "client.dll");
	SCHEMA(CPlayer_WaterServices*, m_pWaterServices, "m_pWaterServices", "C_BasePlayerPawn", "client.dll");
	SCHEMA(CPlayer_UseServices*, m_pUseServices, "m_pUseServices", "C_BasePlayerPawn", "client.dll");
	SCHEMA(CPlayer_FlashlightServices*, m_pFlashlightServices, "m_pFlashlightServices", "C_BasePlayerPawn", "client.dll");
	SCHEMA(CPlayer_CameraServices*, m_pCameraServices, "m_pCameraServices", "C_BasePlayerPawn", "client.dll");
	SCHEMA(CPlayer_MovementServices*, m_pMovementServices, "m_pMovementServices", "C_BasePlayerPawn", "client.dll");
	SCHEMA(CUtlVector< ViewAngleServerChange_t >, m_ServerViewAngleChanges, "m_ServerViewAngleChanges", "C_BasePlayerPawn", "client.dll");
	SCHEMA(QAngle, v_angle, "v_angle", "C_BasePlayerPawn", "client.dll");
	SCHEMA(QAngle, v_anglePrevious, "v_anglePrevious", "C_BasePlayerPawn", "client.dll");
	SCHEMA(uint32, m_iHideHUD, "m_iHideHUD", "C_BasePlayerPawn", "client.dll");
	SCHEMA(sky3dparams_t, m_skybox3d, "m_skybox3d", "C_BasePlayerPawn", "client.dll");
	SCHEMA(GameTime_t, m_flDeathTime, "m_flDeathTime", "C_BasePlayerPawn", "client.dll");
	SCHEMA(Vector, m_vecPredictionError, "m_vecPredictionError", "C_BasePlayerPawn", "client.dll");
	SCHEMA(GameTime_t, m_flPredictionErrorTime, "m_flPredictionErrorTime", "C_BasePlayerPawn", "client.dll");
	SCHEMA(Vector, m_vecLastCameraSetupLocalOrigin, "m_vecLastCameraSetupLocalOrigin", "C_BasePlayerPawn", "client.dll");
	SCHEMA(GameTime_t, m_flLastCameraSetupTime, "m_flLastCameraSetupTime", "C_BasePlayerPawn", "client.dll");
	SCHEMA(float32, m_flFOVSensitivityAdjust, "m_flFOVSensitivityAdjust", "C_BasePlayerPawn", "client.dll");
	SCHEMA(float32, m_flMouseSensitivity, "m_flMouseSensitivity", "C_BasePlayerPawn", "client.dll");
	SCHEMA(Vector, m_vOldOrigin, "m_vOldOrigin", "C_BasePlayerPawn", "client.dll");
	SCHEMA(float32, m_flOldSimulationTime, "m_flOldSimulationTime", "C_BasePlayerPawn", "client.dll");
	SCHEMA(int32, m_nLastExecutedCommandNumber, "m_nLastExecutedCommandNumber", "C_BasePlayerPawn", "client.dll");
	SCHEMA(int32, m_nLastExecutedCommandTick, "m_nLastExecutedCommandTick", "C_BasePlayerPawn", "client.dll");
	SCHEMA(CHandle, m_hController, "m_hController", "C_BasePlayerPawn", "client.dll");
	SCHEMA(CHandle, m_hDefaultController, "m_hDefaultController", "C_BasePlayerPawn", "client.dll");
	SCHEMA(bool, m_bIsSwappingToPredictableController, "m_bIsSwappingToPredictableController", "C_BasePlayerPawn", "client.dll");
};

// Class: C_BaseTrigger (Size: 0xFF0)
class C_BaseTrigger : public C_BaseToggle {
public:
	SCHEMA(CEntityIOOutput, m_OnStartTouch, "m_OnStartTouch", "C_BaseTrigger", "client.dll");
	SCHEMA(CEntityIOOutput, m_OnStartTouchAll, "m_OnStartTouchAll", "C_BaseTrigger", "client.dll");
	SCHEMA(CEntityIOOutput, m_OnEndTouch, "m_OnEndTouch", "C_BaseTrigger", "client.dll");
	SCHEMA(CEntityIOOutput, m_OnEndTouchAll, "m_OnEndTouchAll", "C_BaseTrigger", "client.dll");
	SCHEMA(CEntityIOOutput, m_OnTouching, "m_OnTouching", "C_BaseTrigger", "client.dll");
	SCHEMA(CEntityIOOutput, m_OnTouchingEachEntity, "m_OnTouchingEachEntity", "C_BaseTrigger", "client.dll");
	SCHEMA(CEntityIOOutput, m_OnNotTouching, "m_OnNotTouching", "C_BaseTrigger", "client.dll");
	SCHEMA(CUtlVector< CHandle >, m_hTouchingEntities, "m_hTouchingEntities", "C_BaseTrigger", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_iFilterName, "m_iFilterName", "C_BaseTrigger", "client.dll");
	SCHEMA(CHandle, m_hFilter, "m_hFilter", "C_BaseTrigger", "client.dll");
	SCHEMA(bool, m_bDisabled, "m_bDisabled", "C_BaseTrigger", "client.dll");
};

// Class: CBombTarget (Size: 0xFF8)
class CBombTarget : public C_BaseTrigger {
public:
	SCHEMA(bool, m_bBombPlantedHere, "m_bBombPlantedHere", "CBombTarget", "client.dll");
};

// Class: CTriggerFan (Size: 0x1050)
class CTriggerFan : public C_BaseTrigger {
public:
	SCHEMA(Vector, m_vFanOriginOffset, "m_vFanOriginOffset", "CTriggerFan", "client.dll");
	SCHEMA(Vector, m_vDirection, "m_vDirection", "CTriggerFan", "client.dll");
	SCHEMA(bool, m_bPushTowardsInfoTarget, "m_bPushTowardsInfoTarget", "CTriggerFan", "client.dll");
	SCHEMA(bool, m_bPushAwayFromInfoTarget, "m_bPushAwayFromInfoTarget", "CTriggerFan", "client.dll");
	SCHEMA(Quaternion, m_qNoiseDelta, "m_qNoiseDelta", "CTriggerFan", "client.dll");
	SCHEMA(CHandle, m_hInfoFan, "m_hInfoFan", "CTriggerFan", "client.dll");
	SCHEMA(float32, m_flForce, "m_flForce", "CTriggerFan", "client.dll");
	SCHEMA(bool, m_bFalloff, "m_bFalloff", "CTriggerFan", "client.dll");
	SCHEMA(CountdownTimer, m_RampTimer, "m_RampTimer", "CTriggerFan", "client.dll");
};

// Class: C_Beam (Size: 0xF70)
class C_Beam : public C_BaseModelEntity {
public:
	SCHEMA(float32, m_flFrameRate, "m_flFrameRate", "C_Beam", "client.dll");
	SCHEMA(float32, m_flHDRColorScale, "m_flHDRColorScale", "C_Beam", "client.dll");
	SCHEMA(GameTime_t, m_flFireTime, "m_flFireTime", "C_Beam", "client.dll");
	SCHEMA(float32, m_flDamage, "m_flDamage", "C_Beam", "client.dll");
	SCHEMA(uint8, m_nNumBeamEnts, "m_nNumBeamEnts", "C_Beam", "client.dll");
	SCHEMA(int32, m_queryHandleHalo, "m_queryHandleHalo", "C_Beam", "client.dll");
	SCHEMA(BeamType_t, m_nBeamType, "m_nBeamType", "C_Beam", "client.dll");
	SCHEMA(uint32, m_nBeamFlags, "m_nBeamFlags", "C_Beam", "client.dll");
	SCHEMA(CHandle*, m_hAttachEntity, "m_hAttachEntity", "C_Beam", "client.dll");
	SCHEMA(AttachmentHandle_t*, m_nAttachIndex, "m_nAttachIndex", "C_Beam", "client.dll");
	SCHEMA(float32, m_fWidth, "m_fWidth", "C_Beam", "client.dll");
	SCHEMA(float32, m_fEndWidth, "m_fEndWidth", "C_Beam", "client.dll");
	SCHEMA(float32, m_fFadeLength, "m_fFadeLength", "C_Beam", "client.dll");
	SCHEMA(float32, m_fHaloScale, "m_fHaloScale", "C_Beam", "client.dll");
	SCHEMA(float32, m_fAmplitude, "m_fAmplitude", "C_Beam", "client.dll");
	SCHEMA(float32, m_fStartFrame, "m_fStartFrame", "C_Beam", "client.dll");
	SCHEMA(float32, m_fSpeed, "m_fSpeed", "C_Beam", "client.dll");
	SCHEMA(float32, m_flFrame, "m_flFrame", "C_Beam", "client.dll");
	SCHEMA(BeamClipStyle_t, m_nClipStyle, "m_nClipStyle", "C_Beam", "client.dll");
	SCHEMA(bool, m_bTurnedOff, "m_bTurnedOff", "C_Beam", "client.dll");
	SCHEMA(VectorWS, m_vecEndPos, "m_vecEndPos", "C_Beam", "client.dll");
	SCHEMA(CHandle, m_hEndEntity, "m_hEndEntity", "C_Beam", "client.dll");
};

// Class: C_BreakableProp (Size: 0x1300)
class C_BreakableProp : public CBaseProp {
public:
	SCHEMA(CPropDataComponent, m_CPropDataComponent, "m_CPropDataComponent", "C_BreakableProp", "client.dll");
	SCHEMA(CEntityIOOutput, m_OnStartDeath, "m_OnStartDeath", "C_BreakableProp", "client.dll");
	SCHEMA(CEntityIOOutput, m_OnBreak, "m_OnBreak", "C_BreakableProp", "client.dll");
	SCHEMA(CEntityIOOutput, m_OnTakeDamage, "m_OnTakeDamage", "C_BreakableProp", "client.dll");
	SCHEMA(float32, m_impactEnergyScale, "m_impactEnergyScale", "C_BreakableProp", "client.dll");
	SCHEMA(int32, m_iMinHealthDmg, "m_iMinHealthDmg", "C_BreakableProp", "client.dll");
	SCHEMA(float32, m_flPressureDelay, "m_flPressureDelay", "C_BreakableProp", "client.dll");
	SCHEMA(float32, m_flDefBurstScale, "m_flDefBurstScale", "C_BreakableProp", "client.dll");
	SCHEMA(Vector, m_vDefBurstOffset, "m_vDefBurstOffset", "C_BreakableProp", "client.dll");
	SCHEMA(CHandle, m_hBreaker, "m_hBreaker", "C_BreakableProp", "client.dll");
	SCHEMA(PerformanceMode_t, m_PerformanceMode, "m_PerformanceMode", "C_BreakableProp", "client.dll");
	SCHEMA(GameTime_t, m_flPreventDamageBeforeTime, "m_flPreventDamageBeforeTime", "C_BreakableProp", "client.dll");
	SCHEMA(BreakableContentsType_t, m_BreakableContentsType, "m_BreakableContentsType", "C_BreakableProp", "client.dll");
	SCHEMA(CUtlString, m_strBreakableContentsPropGroupOverride, "m_strBreakableContentsPropGroupOverride", "C_BreakableProp", "client.dll");
	SCHEMA(CUtlString, m_strBreakableContentsParticleOverride, "m_strBreakableContentsParticleOverride", "C_BreakableProp", "client.dll");
	SCHEMA(bool, m_bHasBreakPiecesOrCommands, "m_bHasBreakPiecesOrCommands", "C_BreakableProp", "client.dll");
	SCHEMA(float32, m_explodeDamage, "m_explodeDamage", "C_BreakableProp", "client.dll");
	SCHEMA(float32, m_explodeRadius, "m_explodeRadius", "C_BreakableProp", "client.dll");
	SCHEMA(float32, m_explosionDelay, "m_explosionDelay", "C_BreakableProp", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_explosionBuildupSound, "m_explosionBuildupSound", "C_BreakableProp", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_explosionCustomEffect, "m_explosionCustomEffect", "C_BreakableProp", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_explosionCustomSound, "m_explosionCustomSound", "C_BreakableProp", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_explosionModifier, "m_explosionModifier", "C_BreakableProp", "client.dll");
	SCHEMA(CHandle, m_hPhysicsAttacker, "m_hPhysicsAttacker", "C_BreakableProp", "client.dll");
	SCHEMA(GameTime_t, m_flLastPhysicsInfluenceTime, "m_flLastPhysicsInfluenceTime", "C_BreakableProp", "client.dll");
	SCHEMA(float32, m_flDefaultFadeScale, "m_flDefaultFadeScale", "C_BreakableProp", "client.dll");
	SCHEMA(CHandle, m_hLastAttacker, "m_hLastAttacker", "C_BreakableProp", "client.dll");
};

// Class: C_BulletHitModel (Size: 0x11A8)
class C_BulletHitModel {
public:
	SCHEMA(matrix3x4_t, m_matLocal, "m_matLocal", "C_BulletHitModel", "client.dll");
	SCHEMA(int32, m_iBoneIndex, "m_iBoneIndex", "C_BulletHitModel", "client.dll");
	SCHEMA(CHandle, m_hPlayerParent, "m_hPlayerParent", "C_BulletHitModel", "client.dll");
	SCHEMA(bool, m_bIsHit, "m_bIsHit", "C_BulletHitModel", "client.dll");
	SCHEMA(float32, m_flTimeCreated, "m_flTimeCreated", "C_BulletHitModel", "client.dll");
	SCHEMA(Vector, m_vecStartPos, "m_vecStartPos", "C_BulletHitModel", "client.dll");
};

// Class: C_CSGO_MapPreviewCameraPath (Size: 0x680)
class C_CSGO_MapPreviewCameraPath : public C_BaseEntity {
public:
	SCHEMA(float32, m_flZFar, "m_flZFar", "C_CSGO_MapPreviewCameraPath", "client.dll");
	SCHEMA(float32, m_flZNear, "m_flZNear", "C_CSGO_MapPreviewCameraPath", "client.dll");
	SCHEMA(bool, m_bLoop, "m_bLoop", "C_CSGO_MapPreviewCameraPath", "client.dll");
	SCHEMA(bool, m_bVerticalFOV, "m_bVerticalFOV", "C_CSGO_MapPreviewCameraPath", "client.dll");
	SCHEMA(bool, m_bConstantSpeed, "m_bConstantSpeed", "C_CSGO_MapPreviewCameraPath", "client.dll");
	SCHEMA(float32, m_flDuration, "m_flDuration", "C_CSGO_MapPreviewCameraPath", "client.dll");
	SCHEMA(float32, m_flPathLength, "m_flPathLength", "C_CSGO_MapPreviewCameraPath", "client.dll");
	SCHEMA(float32, m_flPathDuration, "m_flPathDuration", "C_CSGO_MapPreviewCameraPath", "client.dll");
	SCHEMA(bool, m_bDofEnabled, "m_bDofEnabled", "C_CSGO_MapPreviewCameraPath", "client.dll");
	SCHEMA(float32, m_flDofNearBlurry, "m_flDofNearBlurry", "C_CSGO_MapPreviewCameraPath", "client.dll");
	SCHEMA(float32, m_flDofNearCrisp, "m_flDofNearCrisp", "C_CSGO_MapPreviewCameraPath", "client.dll");
	SCHEMA(float32, m_flDofFarCrisp, "m_flDofFarCrisp", "C_CSGO_MapPreviewCameraPath", "client.dll");
	SCHEMA(float32, m_flDofFarBlurry, "m_flDofFarBlurry", "C_CSGO_MapPreviewCameraPath", "client.dll");
	SCHEMA(float32, m_flDofTiltToGround, "m_flDofTiltToGround", "C_CSGO_MapPreviewCameraPath", "client.dll");
};

// Class: C_CSGO_MapPreviewCameraPathNode (Size: 0x648)
class C_CSGO_MapPreviewCameraPathNode : public C_BaseEntity {
public:
	SCHEMA(CUtlSymbolLarge, m_szParentPathUniqueID, "m_szParentPathUniqueID", "C_CSGO_MapPreviewCameraPathNode", "client.dll");
	SCHEMA(int32, m_nPathIndex, "m_nPathIndex", "C_CSGO_MapPreviewCameraPathNode", "client.dll");
	SCHEMA(Vector, m_vInTangentLocal, "m_vInTangentLocal", "C_CSGO_MapPreviewCameraPathNode", "client.dll");
	SCHEMA(Vector, m_vOutTangentLocal, "m_vOutTangentLocal", "C_CSGO_MapPreviewCameraPathNode", "client.dll");
	SCHEMA(float32, m_flFOV, "m_flFOV", "C_CSGO_MapPreviewCameraPathNode", "client.dll");
	SCHEMA(float32, m_flCameraSpeed, "m_flCameraSpeed", "C_CSGO_MapPreviewCameraPathNode", "client.dll");
	SCHEMA(float32, m_flEaseIn, "m_flEaseIn", "C_CSGO_MapPreviewCameraPathNode", "client.dll");
	SCHEMA(float32, m_flEaseOut, "m_flEaseOut", "C_CSGO_MapPreviewCameraPathNode", "client.dll");
	SCHEMA(Vector, m_vInTangentWorld, "m_vInTangentWorld", "C_CSGO_MapPreviewCameraPathNode", "client.dll");
	SCHEMA(Vector, m_vOutTangentWorld, "m_vOutTangentWorld", "C_CSGO_MapPreviewCameraPathNode", "client.dll");
};

// Class: C_CSGO_PreviewModel (Size: 0x1880)
class C_CSGO_PreviewModel : public C_BaseFlex {
public:
	SCHEMA(CUtlString, m_defaultAnim, "m_defaultAnim", "C_CSGO_PreviewModel", "client.dll");
	SCHEMA(AnimLoopMode_t, m_nDefaultAnimLoopMode, "m_nDefaultAnimLoopMode", "C_CSGO_PreviewModel", "client.dll");
	SCHEMA(float32, m_flInitialModelScale, "m_flInitialModelScale", "C_CSGO_PreviewModel", "client.dll");
	SCHEMA(CUtlString, m_sInitialWeaponState, "m_sInitialWeaponState", "C_CSGO_PreviewModel", "client.dll");
};

// Class: C_CSGO_TeamPreviewCamera (Size: 0x688)
class C_CSGO_TeamPreviewCamera : public C_CSGO_MapPreviewCameraPath {
public:
	SCHEMA(int32, m_nVariant, "m_nVariant", "C_CSGO_TeamPreviewCamera", "client.dll");
};

// Class: C_CSGO_TeamPreviewCharacterPosition (Size: 0x13B0)
class C_CSGO_TeamPreviewCharacterPosition : public C_BaseEntity {
public:
	SCHEMA(int32, m_nVariant, "m_nVariant", "C_CSGO_TeamPreviewCharacterPosition", "client.dll");
	SCHEMA(int32, m_nRandom, "m_nRandom", "C_CSGO_TeamPreviewCharacterPosition", "client.dll");
	SCHEMA(int32, m_nOrdinal, "m_nOrdinal", "C_CSGO_TeamPreviewCharacterPosition", "client.dll");
	SCHEMA(CUtlString, m_sWeaponName, "m_sWeaponName", "C_CSGO_TeamPreviewCharacterPosition", "client.dll");
	SCHEMA(uint64, m_xuid, "m_xuid", "C_CSGO_TeamPreviewCharacterPosition", "client.dll");
	SCHEMA(C_EconItemView, m_agentItem, "m_agentItem", "C_CSGO_TeamPreviewCharacterPosition", "client.dll");
	SCHEMA(C_EconItemView, m_glovesItem, "m_glovesItem", "C_CSGO_TeamPreviewCharacterPosition", "client.dll");
	SCHEMA(C_EconItemView, m_weaponItem, "m_weaponItem", "C_CSGO_TeamPreviewCharacterPosition", "client.dll");
};

// Class: C_CSGameRules (Size: 0x4F20)
class C_CSGameRules {
public:
	SCHEMA(bool, m_bFreezePeriod, "m_bFreezePeriod", "C_CSGameRules", "client.dll");
	SCHEMA(bool, m_bWarmupPeriod, "m_bWarmupPeriod", "C_CSGameRules", "client.dll");
	SCHEMA(GameTime_t, m_fWarmupPeriodEnd, "m_fWarmupPeriodEnd", "C_CSGameRules", "client.dll");
	SCHEMA(GameTime_t, m_fWarmupPeriodStart, "m_fWarmupPeriodStart", "C_CSGameRules", "client.dll");
	SCHEMA(bool, m_bTerroristTimeOutActive, "m_bTerroristTimeOutActive", "C_CSGameRules", "client.dll");
	SCHEMA(bool, m_bCTTimeOutActive, "m_bCTTimeOutActive", "C_CSGameRules", "client.dll");
	SCHEMA(float32, m_flTerroristTimeOutRemaining, "m_flTerroristTimeOutRemaining", "C_CSGameRules", "client.dll");
	SCHEMA(float32, m_flCTTimeOutRemaining, "m_flCTTimeOutRemaining", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_nTerroristTimeOuts, "m_nTerroristTimeOuts", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_nCTTimeOuts, "m_nCTTimeOuts", "C_CSGameRules", "client.dll");
	SCHEMA(bool, m_bTechnicalTimeOut, "m_bTechnicalTimeOut", "C_CSGameRules", "client.dll");
	SCHEMA(bool, m_bMatchWaitingForResume, "m_bMatchWaitingForResume", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_iFreezeTime, "m_iFreezeTime", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_iRoundTime, "m_iRoundTime", "C_CSGameRules", "client.dll");
	SCHEMA(float32, m_fMatchStartTime, "m_fMatchStartTime", "C_CSGameRules", "client.dll");
	SCHEMA(GameTime_t, m_fRoundStartTime, "m_fRoundStartTime", "C_CSGameRules", "client.dll");
	SCHEMA(GameTime_t, m_flRestartRoundTime, "m_flRestartRoundTime", "C_CSGameRules", "client.dll");
	SCHEMA(bool, m_bGameRestart, "m_bGameRestart", "C_CSGameRules", "client.dll");
	SCHEMA(float32, m_flGameStartTime, "m_flGameStartTime", "C_CSGameRules", "client.dll");
	SCHEMA(float32, m_timeUntilNextPhaseStarts, "m_timeUntilNextPhaseStarts", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_gamePhase, "m_gamePhase", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_totalRoundsPlayed, "m_totalRoundsPlayed", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_nRoundsPlayedThisPhase, "m_nRoundsPlayedThisPhase", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_nOvertimePlaying, "m_nOvertimePlaying", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_iHostagesRemaining, "m_iHostagesRemaining", "C_CSGameRules", "client.dll");
	SCHEMA(bool, m_bAnyHostageReached, "m_bAnyHostageReached", "C_CSGameRules", "client.dll");
	SCHEMA(bool, m_bMapHasBombTarget, "m_bMapHasBombTarget", "C_CSGameRules", "client.dll");
	SCHEMA(bool, m_bMapHasRescueZone, "m_bMapHasRescueZone", "C_CSGameRules", "client.dll");
	SCHEMA(bool, m_bMapHasBuyZone, "m_bMapHasBuyZone", "C_CSGameRules", "client.dll");
	SCHEMA(bool, m_bIsQueuedMatchmaking, "m_bIsQueuedMatchmaking", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_nQueuedMatchmakingMode, "m_nQueuedMatchmakingMode", "C_CSGameRules", "client.dll");
	SCHEMA(bool, m_bIsValveDS, "m_bIsValveDS", "C_CSGameRules", "client.dll");
	SCHEMA(bool, m_bLogoMap, "m_bLogoMap", "C_CSGameRules", "client.dll");
	SCHEMA(bool, m_bPlayAllStepSoundsOnServer, "m_bPlayAllStepSoundsOnServer", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_iSpectatorSlotCount, "m_iSpectatorSlotCount", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_MatchDevice, "m_MatchDevice", "C_CSGameRules", "client.dll");
	SCHEMA(bool, m_bHasMatchStarted, "m_bHasMatchStarted", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_nNextMapInMapgroup, "m_nNextMapInMapgroup", "C_CSGameRules", "client.dll");
	SCHEMA(char*, m_szTournamentEventName, "m_szTournamentEventName", "C_CSGameRules", "client.dll");
	SCHEMA(char*, m_szTournamentEventStage, "m_szTournamentEventStage", "C_CSGameRules", "client.dll");
	SCHEMA(char*, m_szMatchStatTxt, "m_szMatchStatTxt", "C_CSGameRules", "client.dll");
	SCHEMA(char*, m_szTournamentPredictionsTxt, "m_szTournamentPredictionsTxt", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_nTournamentPredictionsPct, "m_nTournamentPredictionsPct", "C_CSGameRules", "client.dll");
	SCHEMA(GameTime_t, m_flCMMItemDropRevealStartTime, "m_flCMMItemDropRevealStartTime", "C_CSGameRules", "client.dll");
	SCHEMA(GameTime_t, m_flCMMItemDropRevealEndTime, "m_flCMMItemDropRevealEndTime", "C_CSGameRules", "client.dll");
	SCHEMA(bool, m_bIsDroppingItems, "m_bIsDroppingItems", "C_CSGameRules", "client.dll");
	SCHEMA(bool, m_bIsQuestEligible, "m_bIsQuestEligible", "C_CSGameRules", "client.dll");
	SCHEMA(bool, m_bIsHltvActive, "m_bIsHltvActive", "C_CSGameRules", "client.dll");
	SCHEMA(uint16*, m_arrProhibitedItemIndices, "m_arrProhibitedItemIndices", "C_CSGameRules", "client.dll");
	SCHEMA(uint32*, m_arrTournamentActiveCasterAccounts, "m_arrTournamentActiveCasterAccounts", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_numBestOfMaps, "m_numBestOfMaps", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_nHalloweenMaskListSeed, "m_nHalloweenMaskListSeed", "C_CSGameRules", "client.dll");
	SCHEMA(bool, m_bBombDropped, "m_bBombDropped", "C_CSGameRules", "client.dll");
	SCHEMA(bool, m_bBombPlanted, "m_bBombPlanted", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_iRoundWinStatus, "m_iRoundWinStatus", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_eRoundWinReason, "m_eRoundWinReason", "C_CSGameRules", "client.dll");
	SCHEMA(bool, m_bTCantBuy, "m_bTCantBuy", "C_CSGameRules", "client.dll");
	SCHEMA(bool, m_bCTCantBuy, "m_bCTCantBuy", "C_CSGameRules", "client.dll");
	SCHEMA(int32*, m_iMatchStats_RoundResults, "m_iMatchStats_RoundResults", "C_CSGameRules", "client.dll");
	SCHEMA(int32*, m_iMatchStats_PlayersAlive_CT, "m_iMatchStats_PlayersAlive_CT", "C_CSGameRules", "client.dll");
	SCHEMA(int32*, m_iMatchStats_PlayersAlive_T, "m_iMatchStats_PlayersAlive_T", "C_CSGameRules", "client.dll");
	SCHEMA(float32*, m_TeamRespawnWaveTimes, "m_TeamRespawnWaveTimes", "C_CSGameRules", "client.dll");
	SCHEMA(GameTime_t*, m_flNextRespawnWave, "m_flNextRespawnWave", "C_CSGameRules", "client.dll");
	SCHEMA(Vector, m_vMinimapMins, "m_vMinimapMins", "C_CSGameRules", "client.dll");
	SCHEMA(Vector, m_vMinimapMaxs, "m_vMinimapMaxs", "C_CSGameRules", "client.dll");
	SCHEMA(float32*, m_MinimapVerticalSectionHeights, "m_MinimapVerticalSectionHeights", "C_CSGameRules", "client.dll");
	SCHEMA(uint64, m_ullLocalMatchID, "m_ullLocalMatchID", "C_CSGameRules", "client.dll");
	SCHEMA(int32*, m_nEndMatchMapGroupVoteTypes, "m_nEndMatchMapGroupVoteTypes", "C_CSGameRules", "client.dll");
	SCHEMA(int32*, m_nEndMatchMapGroupVoteOptions, "m_nEndMatchMapGroupVoteOptions", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_nEndMatchMapVoteWinner, "m_nEndMatchMapVoteWinner", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_iNumConsecutiveCTLoses, "m_iNumConsecutiveCTLoses", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_iNumConsecutiveTerroristLoses, "m_iNumConsecutiveTerroristLoses", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_nMatchAbortedEarlyReason, "m_nMatchAbortedEarlyReason", "C_CSGameRules", "client.dll");
	SCHEMA(bool, m_bHasTriggeredRoundStartMusic, "m_bHasTriggeredRoundStartMusic", "C_CSGameRules", "client.dll");
	SCHEMA(bool, m_bSwitchingTeamsAtRoundReset, "m_bSwitchingTeamsAtRoundReset", "C_CSGameRules", "client.dll");
	SCHEMA(CCSGameModeRules*, m_pGameModeRules, "m_pGameModeRules", "C_CSGameRules", "client.dll");
	SCHEMA(C_RetakeGameRules, m_RetakeRules, "m_RetakeRules", "C_CSGameRules", "client.dll");
	SCHEMA(uint8, m_nMatchEndCount, "m_nMatchEndCount", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_nTTeamIntroVariant, "m_nTTeamIntroVariant", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_nCTTeamIntroVariant, "m_nCTTeamIntroVariant", "C_CSGameRules", "client.dll");
	SCHEMA(bool, m_bTeamIntroPeriod, "m_bTeamIntroPeriod", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_iRoundEndWinnerTeam, "m_iRoundEndWinnerTeam", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_eRoundEndReason, "m_eRoundEndReason", "C_CSGameRules", "client.dll");
	SCHEMA(bool, m_bRoundEndShowTimerDefend, "m_bRoundEndShowTimerDefend", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_iRoundEndTimerTime, "m_iRoundEndTimerTime", "C_CSGameRules", "client.dll");
	SCHEMA(CUtlString, m_sRoundEndFunFactToken, "m_sRoundEndFunFactToken", "C_CSGameRules", "client.dll");
	SCHEMA(CPlayerSlot, m_iRoundEndFunFactPlayerSlot, "m_iRoundEndFunFactPlayerSlot", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_iRoundEndFunFactData1, "m_iRoundEndFunFactData1", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_iRoundEndFunFactData2, "m_iRoundEndFunFactData2", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_iRoundEndFunFactData3, "m_iRoundEndFunFactData3", "C_CSGameRules", "client.dll");
	SCHEMA(CUtlString, m_sRoundEndMessage, "m_sRoundEndMessage", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_iRoundEndPlayerCount, "m_iRoundEndPlayerCount", "C_CSGameRules", "client.dll");
	SCHEMA(bool, m_bRoundEndNoMusic, "m_bRoundEndNoMusic", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_iRoundEndLegacy, "m_iRoundEndLegacy", "C_CSGameRules", "client.dll");
	SCHEMA(uint8, m_nRoundEndCount, "m_nRoundEndCount", "C_CSGameRules", "client.dll");
	SCHEMA(int32, m_iRoundStartRoundNumber, "m_iRoundStartRoundNumber", "C_CSGameRules", "client.dll");
	SCHEMA(uint8, m_nRoundStartCount, "m_nRoundStartCount", "C_CSGameRules", "client.dll");
	SCHEMA(float64, m_flLastPerfSampleTime, "m_flLastPerfSampleTime", "C_CSGameRules", "client.dll");
};

// Class: C_CSGameRulesProxy (Size: 0x600)
class C_CSGameRulesProxy : public C_GameRulesProxy {
public:
	SCHEMA(C_CSGameRules*, m_pGameRules, "m_pGameRules", "C_CSGameRulesProxy", "client.dll");
};

// Class: C_CSPlayerPawnBase (Size: 0x1668)
class C_CSPlayerPawnBase : public C_BasePlayerPawn {
public:
	SCHEMA(CCSPlayer_PingServices*, m_pPingServices, "m_pPingServices", "C_CSPlayerPawnBase", "client.dll");
	SCHEMA(CSPlayerState, m_previousPlayerState, "m_previousPlayerState", "C_CSPlayerPawnBase", "client.dll");
	SCHEMA(CSPlayerState, m_iPlayerState, "m_iPlayerState", "C_CSPlayerPawnBase", "client.dll");
	SCHEMA(bool, m_bHasMovedSinceSpawn, "m_bHasMovedSinceSpawn", "C_CSPlayerPawnBase", "client.dll");
	SCHEMA(GameTime_t, m_flLastSpawnTimeIndex, "m_flLastSpawnTimeIndex", "C_CSPlayerPawnBase", "client.dll");
	SCHEMA(int32, m_iProgressBarDuration, "m_iProgressBarDuration", "C_CSPlayerPawnBase", "client.dll");
	SCHEMA(float32, m_flProgressBarStartTime, "m_flProgressBarStartTime", "C_CSPlayerPawnBase", "client.dll");
	SCHEMA(GameTime_t, m_flClientDeathTime, "m_flClientDeathTime", "C_CSPlayerPawnBase", "client.dll");
	SCHEMA(float32, m_flFlashBangTime, "m_flFlashBangTime", "C_CSPlayerPawnBase", "client.dll");
	SCHEMA(float32, m_flFlashScreenshotAlpha, "m_flFlashScreenshotAlpha", "C_CSPlayerPawnBase", "client.dll");
	SCHEMA(float32, m_flFlashOverlayAlpha, "m_flFlashOverlayAlpha", "C_CSPlayerPawnBase", "client.dll");
	SCHEMA(bool, m_bFlashBuildUp, "m_bFlashBuildUp", "C_CSPlayerPawnBase", "client.dll");
	SCHEMA(bool, m_bFlashDspHasBeenCleared, "m_bFlashDspHasBeenCleared", "C_CSPlayerPawnBase", "client.dll");
	SCHEMA(bool, m_bFlashScreenshotHasBeenGrabbed, "m_bFlashScreenshotHasBeenGrabbed", "C_CSPlayerPawnBase", "client.dll");
	SCHEMA(float32, m_flFlashMaxAlpha, "m_flFlashMaxAlpha", "C_CSPlayerPawnBase", "client.dll");
	SCHEMA(float32, m_flFlashDuration, "m_flFlashDuration", "C_CSPlayerPawnBase", "client.dll");
	SCHEMA(GameTime_t, m_flClientHealthFadeChangeTimestamp, "m_flClientHealthFadeChangeTimestamp", "C_CSPlayerPawnBase", "client.dll");
	SCHEMA(int32, m_nClientHealthFadeParityValue, "m_nClientHealthFadeParityValue", "C_CSPlayerPawnBase", "client.dll");
	SCHEMA(float32, m_fNextThinkPushAway, "m_fNextThinkPushAway", "C_CSPlayerPawnBase", "client.dll");
	SCHEMA(float32, m_flCurrentMusicStartTime, "m_flCurrentMusicStartTime", "C_CSPlayerPawnBase", "client.dll");
	SCHEMA(float32, m_flMusicRoundStartTime, "m_flMusicRoundStartTime", "C_CSPlayerPawnBase", "client.dll");
	SCHEMA(bool, m_bDeferStartMusicOnWarmup, "m_bDeferStartMusicOnWarmup", "C_CSPlayerPawnBase", "client.dll");
	SCHEMA(float32, m_flLastSmokeOverlayAlpha, "m_flLastSmokeOverlayAlpha", "C_CSPlayerPawnBase", "client.dll");
	SCHEMA(float32, m_flLastSmokeAge, "m_flLastSmokeAge", "C_CSPlayerPawnBase", "client.dll");
	SCHEMA(Vector, m_vLastSmokeOverlayColor, "m_vLastSmokeOverlayColor", "C_CSPlayerPawnBase", "client.dll");
	SCHEMA(CHandle, m_hOriginalController, "m_hOriginalController", "C_CSPlayerPawnBase", "client.dll");
};

// Class: C_CSObserverPawn (Size: 0x1670)
class C_CSObserverPawn : public C_CSPlayerPawnBase {
public:
	SCHEMA(CEntityHandle, m_hDetectParentChange, "m_hDetectParentChange", "C_CSObserverPawn", "client.dll");
};

// Class: C_CSPlayerPawn (Size: 0x3F10)
class C_CSPlayerPawn : public C_CSPlayerPawnBase {
public:
	SCHEMA(CCSPlayer_BulletServices*, m_pBulletServices, "m_pBulletServices", "C_CSPlayerPawn", "client.dll");
	SCHEMA(CCSPlayer_HostageServices*, m_pHostageServices, "m_pHostageServices", "C_CSPlayerPawn", "client.dll");
	SCHEMA(CCSPlayer_BuyServices*, m_pBuyServices, "m_pBuyServices", "C_CSPlayerPawn", "client.dll");
	SCHEMA(CCSPlayer_GlowServices*, m_pGlowServices, "m_pGlowServices", "C_CSPlayerPawn", "client.dll");
	SCHEMA(CCSPlayer_ActionTrackingServices*, m_pActionTrackingServices, "m_pActionTrackingServices", "C_CSPlayerPawn", "client.dll");
	SCHEMA(CCSPlayer_DamageReactServices*, m_pDamageReactServices, "m_pDamageReactServices", "C_CSPlayerPawn", "client.dll");
	SCHEMA(GameTime_t, m_flHealthShotBoostExpirationTime, "m_flHealthShotBoostExpirationTime", "C_CSPlayerPawn", "client.dll");
	SCHEMA(GameTime_t, m_flLastFiredWeaponTime, "m_flLastFiredWeaponTime", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bHasFemaleVoice, "m_bHasFemaleVoice", "C_CSPlayerPawn", "client.dll");
	SCHEMA(float32, m_flLandingTimeSeconds, "m_flLandingTimeSeconds", "C_CSPlayerPawn", "client.dll");
	SCHEMA(float32, m_flOldFallVelocity, "m_flOldFallVelocity", "C_CSPlayerPawn", "client.dll");
	SCHEMA(char*, m_szLastPlaceName, "m_szLastPlaceName", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bPrevDefuser, "m_bPrevDefuser", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bPrevHelmet, "m_bPrevHelmet", "C_CSPlayerPawn", "client.dll");
	SCHEMA(int32, m_nPrevArmorVal, "m_nPrevArmorVal", "C_CSPlayerPawn", "client.dll");
	SCHEMA(int32, m_nPrevGrenadeAmmoCount, "m_nPrevGrenadeAmmoCount", "C_CSPlayerPawn", "client.dll");
	SCHEMA(uint32, m_unPreviousWeaponHash, "m_unPreviousWeaponHash", "C_CSPlayerPawn", "client.dll");
	SCHEMA(uint32, m_unWeaponHash, "m_unWeaponHash", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bInBuyZone, "m_bInBuyZone", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bPreviouslyInBuyZone, "m_bPreviouslyInBuyZone", "C_CSPlayerPawn", "client.dll");
	SCHEMA(QAngle, m_aimPunchAngle, "m_aimPunchAngle", "C_CSPlayerPawn", "client.dll");
	SCHEMA(QAngle, m_aimPunchAngleVel, "m_aimPunchAngleVel", "C_CSPlayerPawn", "client.dll");
	SCHEMA(GameTick_t, m_aimPunchTickBase, "m_aimPunchTickBase", "C_CSPlayerPawn", "client.dll");
	SCHEMA(float32, m_aimPunchTickFraction, "m_aimPunchTickFraction", "C_CSPlayerPawn", "client.dll");
	SCHEMA(CUtlVector< QAngle >, m_aimPunchCache, "m_aimPunchCache", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bInLanding, "m_bInLanding", "C_CSPlayerPawn", "client.dll");
	SCHEMA(float32, m_flLandingStartTime, "m_flLandingStartTime", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bInHostageRescueZone, "m_bInHostageRescueZone", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bInBombZone, "m_bInBombZone", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bIsBuyMenuOpen, "m_bIsBuyMenuOpen", "C_CSPlayerPawn", "client.dll");
	SCHEMA(GameTime_t, m_flTimeOfLastInjury, "m_flTimeOfLastInjury", "C_CSPlayerPawn", "client.dll");
	SCHEMA(GameTime_t, m_flNextSprayDecalTime, "m_flNextSprayDecalTime", "C_CSPlayerPawn", "client.dll");
	SCHEMA(int32, m_iRetakesOffering, "m_iRetakesOffering", "C_CSPlayerPawn", "client.dll");
	SCHEMA(int32, m_iRetakesOfferingCard, "m_iRetakesOfferingCard", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bRetakesHasDefuseKit, "m_bRetakesHasDefuseKit", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bRetakesMVPLastRound, "m_bRetakesMVPLastRound", "C_CSPlayerPawn", "client.dll");
	SCHEMA(int32, m_iRetakesMVPBoostItem, "m_iRetakesMVPBoostItem", "C_CSPlayerPawn", "client.dll");
	SCHEMA(loadout_slot_t, m_RetakesMVPBoostExtraUtility, "m_RetakesMVPBoostExtraUtility", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bNeedToReApplyGloves, "m_bNeedToReApplyGloves", "C_CSPlayerPawn", "client.dll");
	SCHEMA(C_EconItemView, m_EconGloves, "m_EconGloves", "C_CSPlayerPawn", "client.dll");
	SCHEMA(uint8, m_nEconGlovesChanged, "m_nEconGlovesChanged", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bMustSyncRagdollState, "m_bMustSyncRagdollState", "C_CSPlayerPawn", "client.dll");
	SCHEMA(int32, m_nRagdollDamageBone, "m_nRagdollDamageBone", "C_CSPlayerPawn", "client.dll");
	SCHEMA(Vector, m_vRagdollDamageForce, "m_vRagdollDamageForce", "C_CSPlayerPawn", "client.dll");
	SCHEMA(Vector, m_vRagdollDamagePosition, "m_vRagdollDamagePosition", "C_CSPlayerPawn", "client.dll");
	SCHEMA(char*, m_szRagdollDamageWeaponName, "m_szRagdollDamageWeaponName", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bRagdollDamageHeadshot, "m_bRagdollDamageHeadshot", "C_CSPlayerPawn", "client.dll");
	SCHEMA(Vector, m_vRagdollServerOrigin, "m_vRagdollServerOrigin", "C_CSPlayerPawn", "client.dll");
	SCHEMA(GameTime_t, m_lastLandTime, "m_lastLandTime", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bOnGroundLastTick, "m_bOnGroundLastTick", "C_CSPlayerPawn", "client.dll");
	SCHEMA(CHandle, m_hHudModelArms, "m_hHudModelArms", "C_CSPlayerPawn", "client.dll");
	SCHEMA(QAngle, m_qDeathEyeAngles, "m_qDeathEyeAngles", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bSkipOneHeadConstraintUpdate, "m_bSkipOneHeadConstraintUpdate", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bLeftHanded, "m_bLeftHanded", "C_CSPlayerPawn", "client.dll");
	SCHEMA(GameTime_t, m_fSwitchedHandednessTime, "m_fSwitchedHandednessTime", "C_CSPlayerPawn", "client.dll");
	SCHEMA(float32, m_flViewmodelOffsetX, "m_flViewmodelOffsetX", "C_CSPlayerPawn", "client.dll");
	SCHEMA(float32, m_flViewmodelOffsetY, "m_flViewmodelOffsetY", "C_CSPlayerPawn", "client.dll");
	SCHEMA(float32, m_flViewmodelOffsetZ, "m_flViewmodelOffsetZ", "C_CSPlayerPawn", "client.dll");
	SCHEMA(float32, m_flViewmodelFOV, "m_flViewmodelFOV", "C_CSPlayerPawn", "client.dll");
	SCHEMA(uint32*, m_vecPlayerPatchEconIndices, "m_vecPlayerPatchEconIndices", "C_CSPlayerPawn", "client.dll");
	SCHEMA(Color, m_GunGameImmunityColor, "m_GunGameImmunityColor", "C_CSPlayerPawn", "client.dll");
	SCHEMA(CUtlVector< C_BulletHitModel* >, m_vecBulletHitModels, "m_vecBulletHitModels", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bIsWalking, "m_bIsWalking", "C_CSPlayerPawn", "client.dll");
	SCHEMA(QAngle, m_thirdPersonHeading, "m_thirdPersonHeading", "C_CSPlayerPawn", "client.dll");
	SCHEMA(float32, m_flSlopeDropOffset, "m_flSlopeDropOffset", "C_CSPlayerPawn", "client.dll");
	SCHEMA(float32, m_flSlopeDropHeight, "m_flSlopeDropHeight", "C_CSPlayerPawn", "client.dll");
	SCHEMA(Vector, m_vHeadConstraintOffset, "m_vHeadConstraintOffset", "C_CSPlayerPawn", "client.dll");
	SCHEMA(EntitySpottedState_t, m_entitySpottedState, "m_entitySpottedState", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bIsScoped, "m_bIsScoped", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bResumeZoom, "m_bResumeZoom", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bIsDefusing, "m_bIsDefusing", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bIsGrabbingHostage, "m_bIsGrabbingHostage", "C_CSPlayerPawn", "client.dll");
	SCHEMA(CSPlayerBlockingUseAction_t, m_iBlockingUseActionInProgress, "m_iBlockingUseActionInProgress", "C_CSPlayerPawn", "client.dll");
	SCHEMA(GameTime_t, m_flEmitSoundTime, "m_flEmitSoundTime", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bInNoDefuseArea, "m_bInNoDefuseArea", "C_CSPlayerPawn", "client.dll");
	SCHEMA(int32, m_nWhichBombZone, "m_nWhichBombZone", "C_CSPlayerPawn", "client.dll");
	SCHEMA(int32, m_iShotsFired, "m_iShotsFired", "C_CSPlayerPawn", "client.dll");
	SCHEMA(float32, m_flFlinchStack, "m_flFlinchStack", "C_CSPlayerPawn", "client.dll");
	SCHEMA(float32, m_flVelocityModifier, "m_flVelocityModifier", "C_CSPlayerPawn", "client.dll");
	SCHEMA(float32, m_flHitHeading, "m_flHitHeading", "C_CSPlayerPawn", "client.dll");
	SCHEMA(int32, m_nHitBodyPart, "m_nHitBodyPart", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bWaitForNoAttack, "m_bWaitForNoAttack", "C_CSPlayerPawn", "client.dll");
	SCHEMA(float32, m_ignoreLadderJumpTime, "m_ignoreLadderJumpTime", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bKilledByHeadshot, "m_bKilledByHeadshot", "C_CSPlayerPawn", "client.dll");
	SCHEMA(int32, m_ArmorValue, "m_ArmorValue", "C_CSPlayerPawn", "client.dll");
	SCHEMA(uint16, m_unCurrentEquipmentValue, "m_unCurrentEquipmentValue", "C_CSPlayerPawn", "client.dll");
	SCHEMA(uint16, m_unRoundStartEquipmentValue, "m_unRoundStartEquipmentValue", "C_CSPlayerPawn", "client.dll");
	SCHEMA(uint16, m_unFreezetimeEndEquipmentValue, "m_unFreezetimeEndEquipmentValue", "C_CSPlayerPawn", "client.dll");
	SCHEMA(CEntityIndex, m_nLastKillerIndex, "m_nLastKillerIndex", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bOldIsScoped, "m_bOldIsScoped", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bHasDeathInfo, "m_bHasDeathInfo", "C_CSPlayerPawn", "client.dll");
	SCHEMA(float32, m_flDeathInfoTime, "m_flDeathInfoTime", "C_CSPlayerPawn", "client.dll");
	SCHEMA(Vector, m_vecDeathInfoOrigin, "m_vecDeathInfoOrigin", "C_CSPlayerPawn", "client.dll");
	SCHEMA(GameTime_t, m_grenadeParameterStashTime, "m_grenadeParameterStashTime", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bGrenadeParametersStashed, "m_bGrenadeParametersStashed", "C_CSPlayerPawn", "client.dll");
	SCHEMA(QAngle, m_angStashedShootAngles, "m_angStashedShootAngles", "C_CSPlayerPawn", "client.dll");
	SCHEMA(Vector, m_vecStashedGrenadeThrowPosition, "m_vecStashedGrenadeThrowPosition", "C_CSPlayerPawn", "client.dll");
	SCHEMA(Vector, m_vecStashedVelocity, "m_vecStashedVelocity", "C_CSPlayerPawn", "client.dll");
	SCHEMA(QAngle*, m_angShootAngleHistory, "m_angShootAngleHistory", "C_CSPlayerPawn", "client.dll");
	SCHEMA(Vector*, m_vecThrowPositionHistory, "m_vecThrowPositionHistory", "C_CSPlayerPawn", "client.dll");
	SCHEMA(Vector*, m_vecVelocityHistory, "m_vecVelocityHistory", "C_CSPlayerPawn", "client.dll");
	SCHEMA(GameTick_t, m_nPrevHighestReceivedDamageTagTick, "m_nPrevHighestReceivedDamageTagTick", "C_CSPlayerPawn", "client.dll");
	SCHEMA(int32, m_nHighestAppliedDamageTagTick, "m_nHighestAppliedDamageTagTick", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bShouldAutobuyDMWeapons, "m_bShouldAutobuyDMWeapons", "C_CSPlayerPawn", "client.dll");
	SCHEMA(GameTime_t, m_fImmuneToGunGameDamageTime, "m_fImmuneToGunGameDamageTime", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bGunGameImmunity, "m_bGunGameImmunity", "C_CSPlayerPawn", "client.dll");
	SCHEMA(GameTime_t, m_fImmuneToGunGameDamageTimeLast, "m_fImmuneToGunGameDamageTimeLast", "C_CSPlayerPawn", "client.dll");
	SCHEMA(float32, m_fMolotovDamageTime, "m_fMolotovDamageTime", "C_CSPlayerPawn", "client.dll");
	SCHEMA(Vector, m_vecLastAliveLocalVelocity, "m_vecLastAliveLocalVelocity", "C_CSPlayerPawn", "client.dll");
	SCHEMA(float32*, m_fRenderingClipPlane, "m_fRenderingClipPlane", "C_CSPlayerPawn", "client.dll");
	SCHEMA(int32, m_nLastClipPlaneSetupFrame, "m_nLastClipPlaneSetupFrame", "C_CSPlayerPawn", "client.dll");
	SCHEMA(Vector, m_vecLastClipCameraPos, "m_vecLastClipCameraPos", "C_CSPlayerPawn", "client.dll");
	SCHEMA(Vector, m_vecLastClipCameraForward, "m_vecLastClipCameraForward", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bClipHitStaticWorld, "m_bClipHitStaticWorld", "C_CSPlayerPawn", "client.dll");
	SCHEMA(bool, m_bCachedPlaneIsValid, "m_bCachedPlaneIsValid", "C_CSPlayerPawn", "client.dll");
	SCHEMA(C_CSWeaponBase*, m_pClippingWeapon, "m_pClippingWeapon", "C_CSPlayerPawn", "client.dll");
	SCHEMA(ParticleIndex_t, m_nPlayerInfernoBodyFx, "m_nPlayerInfernoBodyFx", "C_CSPlayerPawn", "client.dll");
	SCHEMA(QAngle, m_angEyeAngles, "m_angEyeAngles", "C_CSPlayerPawn", "client.dll");
	SCHEMA(GameTime_t*, m_arrOldEyeAnglesTimes, "m_arrOldEyeAnglesTimes", "C_CSPlayerPawn", "client.dll");
	SCHEMA(QAngle*, m_arrOldEyeAngles, "m_arrOldEyeAngles", "C_CSPlayerPawn", "client.dll");
	SCHEMA(QAngle, m_angEyeAnglesVelocity, "m_angEyeAnglesVelocity", "C_CSPlayerPawn", "client.dll");
	SCHEMA(CEntityIndex, m_iIDEntIndex, "m_iIDEntIndex", "C_CSPlayerPawn", "client.dll");
	SCHEMA(CountdownTimer, m_delayTargetIDTimer, "m_delayTargetIDTimer", "C_CSPlayerPawn", "client.dll");
	SCHEMA(CEntityIndex, m_iTargetItemEntIdx, "m_iTargetItemEntIdx", "C_CSPlayerPawn", "client.dll");
	SCHEMA(CEntityIndex, m_iOldIDEntIndex, "m_iOldIDEntIndex", "C_CSPlayerPawn", "client.dll");
	SCHEMA(CountdownTimer, m_holdTargetIDTimer, "m_holdTargetIDTimer", "C_CSPlayerPawn", "client.dll");
};

// Class: C_CSGO_PreviewPlayer (Size: 0x3FB0)
class C_CSGO_PreviewPlayer : public C_CSPlayerPawn {
public:
	SCHEMA(CGlobalSymbol, m_animgraphCharacterModeString, "m_animgraphCharacterModeString", "C_CSGO_PreviewPlayer", "client.dll");
	SCHEMA(float32, m_flInitialModelScale, "m_flInitialModelScale", "C_CSGO_PreviewPlayer", "client.dll");
};

// Class: C_CSPlayerResource (Size: 0x690)
class C_CSPlayerResource : public C_BaseEntity {
public:
	SCHEMA(bool*, m_bHostageAlive, "m_bHostageAlive", "C_CSPlayerResource", "client.dll");
	SCHEMA(bool*, m_isHostageFollowingSomeone, "m_isHostageFollowingSomeone", "C_CSPlayerResource", "client.dll");
	SCHEMA(CEntityIndex*, m_iHostageEntityIDs, "m_iHostageEntityIDs", "C_CSPlayerResource", "client.dll");
	SCHEMA(Vector, m_bombsiteCenterA, "m_bombsiteCenterA", "C_CSPlayerResource", "client.dll");
	SCHEMA(Vector, m_bombsiteCenterB, "m_bombsiteCenterB", "C_CSPlayerResource", "client.dll");
	SCHEMA(int32*, m_hostageRescueX, "m_hostageRescueX", "C_CSPlayerResource", "client.dll");
	SCHEMA(int32*, m_hostageRescueY, "m_hostageRescueY", "C_CSPlayerResource", "client.dll");
	SCHEMA(int32*, m_hostageRescueZ, "m_hostageRescueZ", "C_CSPlayerResource", "client.dll");
	SCHEMA(bool, m_bEndMatchNextMapAllVoted, "m_bEndMatchNextMapAllVoted", "C_CSPlayerResource", "client.dll");
	SCHEMA(bool, m_foundGoalPositions, "m_foundGoalPositions", "C_CSPlayerResource", "client.dll");
};

// Class: C_ClientRagdoll (Size: 0x11F0)
class C_ClientRagdoll : public CBaseAnimGraph {
public:
	SCHEMA(bool, m_bFadeOut, "m_bFadeOut", "C_ClientRagdoll", "client.dll");
	SCHEMA(bool, m_bImportant, "m_bImportant", "C_ClientRagdoll", "client.dll");
	SCHEMA(GameTime_t, m_flEffectTime, "m_flEffectTime", "C_ClientRagdoll", "client.dll");
	SCHEMA(GameTime_t, m_gibDespawnTime, "m_gibDespawnTime", "C_ClientRagdoll", "client.dll");
	SCHEMA(int32, m_iCurrentFriction, "m_iCurrentFriction", "C_ClientRagdoll", "client.dll");
	SCHEMA(int32, m_iMinFriction, "m_iMinFriction", "C_ClientRagdoll", "client.dll");
	SCHEMA(int32, m_iMaxFriction, "m_iMaxFriction", "C_ClientRagdoll", "client.dll");
	SCHEMA(int32, m_iFrictionAnimState, "m_iFrictionAnimState", "C_ClientRagdoll", "client.dll");
	SCHEMA(bool, m_bReleaseRagdoll, "m_bReleaseRagdoll", "C_ClientRagdoll", "client.dll");
	SCHEMA(AttachmentHandle_t, m_iEyeAttachment, "m_iEyeAttachment", "C_ClientRagdoll", "client.dll");
	SCHEMA(bool, m_bFadingOut, "m_bFadingOut", "C_ClientRagdoll", "client.dll");
	SCHEMA(float32*, m_flScaleEnd, "m_flScaleEnd", "C_ClientRagdoll", "client.dll");
	SCHEMA(GameTime_t*, m_flScaleTimeStart, "m_flScaleTimeStart", "C_ClientRagdoll", "client.dll");
	SCHEMA(GameTime_t*, m_flScaleTimeEnd, "m_flScaleTimeEnd", "C_ClientRagdoll", "client.dll");
};

// Class: C_ColorCorrection (Size: 0x840)
class C_ColorCorrection : public C_BaseEntity {
public:
	SCHEMA(Vector, m_vecOrigin, "m_vecOrigin", "C_ColorCorrection", "client.dll");
	SCHEMA(float32, m_MinFalloff, "m_MinFalloff", "C_ColorCorrection", "client.dll");
	SCHEMA(float32, m_MaxFalloff, "m_MaxFalloff", "C_ColorCorrection", "client.dll");
	SCHEMA(float32, m_flFadeInDuration, "m_flFadeInDuration", "C_ColorCorrection", "client.dll");
	SCHEMA(float32, m_flFadeOutDuration, "m_flFadeOutDuration", "C_ColorCorrection", "client.dll");
	SCHEMA(float32, m_flMaxWeight, "m_flMaxWeight", "C_ColorCorrection", "client.dll");
	SCHEMA(float32, m_flCurWeight, "m_flCurWeight", "C_ColorCorrection", "client.dll");
	SCHEMA(char*, m_netlookupFilename, "m_netlookupFilename", "C_ColorCorrection", "client.dll");
	SCHEMA(bool, m_bEnabled, "m_bEnabled", "C_ColorCorrection", "client.dll");
	SCHEMA(bool, m_bMaster, "m_bMaster", "C_ColorCorrection", "client.dll");
	SCHEMA(bool, m_bClientSide, "m_bClientSide", "C_ColorCorrection", "client.dll");
	SCHEMA(bool, m_bExclusive, "m_bExclusive", "C_ColorCorrection", "client.dll");
	SCHEMA(bool*, m_bEnabledOnClient, "m_bEnabledOnClient", "C_ColorCorrection", "client.dll");
	SCHEMA(float32*, m_flCurWeightOnClient, "m_flCurWeightOnClient", "C_ColorCorrection", "client.dll");
	SCHEMA(bool*, m_bFadingIn, "m_bFadingIn", "C_ColorCorrection", "client.dll");
	SCHEMA(float32*, m_flFadeStartWeight, "m_flFadeStartWeight", "C_ColorCorrection", "client.dll");
	SCHEMA(float32*, m_flFadeStartTime, "m_flFadeStartTime", "C_ColorCorrection", "client.dll");
	SCHEMA(float32*, m_flFadeDuration, "m_flFadeDuration", "C_ColorCorrection", "client.dll");
};

// Class: C_ColorCorrectionVolume (Size: 0x1218)
class C_ColorCorrectionVolume : public C_BaseTrigger {
public:
	SCHEMA(float32, m_LastEnterWeight, "m_LastEnterWeight", "C_ColorCorrectionVolume", "client.dll");
	SCHEMA(GameTime_t, m_LastEnterTime, "m_LastEnterTime", "C_ColorCorrectionVolume", "client.dll");
	SCHEMA(float32, m_LastExitWeight, "m_LastExitWeight", "C_ColorCorrectionVolume", "client.dll");
	SCHEMA(GameTime_t, m_LastExitTime, "m_LastExitTime", "C_ColorCorrectionVolume", "client.dll");
	SCHEMA(bool, m_bEnabled, "m_bEnabled", "C_ColorCorrectionVolume", "client.dll");
	SCHEMA(float32, m_MaxWeight, "m_MaxWeight", "C_ColorCorrectionVolume", "client.dll");
	SCHEMA(float32, m_FadeDuration, "m_FadeDuration", "C_ColorCorrectionVolume", "client.dll");
	SCHEMA(float32, m_Weight, "m_Weight", "C_ColorCorrectionVolume", "client.dll");
	SCHEMA(char*, m_lookupFilename, "m_lookupFilename", "C_ColorCorrectionVolume", "client.dll");
};

// Class: C_CsmFovOverride (Size: 0x608)
class C_CsmFovOverride : public C_BaseEntity {
public:
	SCHEMA(CUtlString, m_cameraName, "m_cameraName", "C_CsmFovOverride", "client.dll");
	SCHEMA(float32, m_flCsmFovOverrideValue, "m_flCsmFovOverrideValue", "C_CsmFovOverride", "client.dll");
};

// Class: C_DecoyProjectile (Size: 0x1480)
class C_DecoyProjectile : public C_BaseCSGrenadeProjectile {
public:
	SCHEMA(int32, m_nDecoyShotTick, "m_nDecoyShotTick", "C_DecoyProjectile", "client.dll");
	SCHEMA(int32, m_nClientLastKnownDecoyShotTick, "m_nClientLastKnownDecoyShotTick", "C_DecoyProjectile", "client.dll");
	SCHEMA(GameTime_t, m_flTimeParticleEffectSpawn, "m_flTimeParticleEffectSpawn", "C_DecoyProjectile", "client.dll");
};

// Class: C_DynamicLight (Size: 0xED8)
class C_DynamicLight : public C_BaseModelEntity {
public:
	SCHEMA(uint8, m_Flags, "m_Flags", "C_DynamicLight", "client.dll");
	SCHEMA(uint8, m_LightStyle, "m_LightStyle", "C_DynamicLight", "client.dll");
	SCHEMA(float32, m_Radius, "m_Radius", "C_DynamicLight", "client.dll");
	SCHEMA(int32, m_Exponent, "m_Exponent", "C_DynamicLight", "client.dll");
	SCHEMA(float32, m_InnerAngle, "m_InnerAngle", "C_DynamicLight", "client.dll");
	SCHEMA(float32, m_OuterAngle, "m_OuterAngle", "C_DynamicLight", "client.dll");
	SCHEMA(float32, m_SpotRadius, "m_SpotRadius", "C_DynamicLight", "client.dll");
};

// Class: C_DynamicProp (Size: 0x1420)
class C_DynamicProp : public C_BreakableProp {
public:
	SCHEMA(bool, m_bUseHitboxesForRenderBox, "m_bUseHitboxesForRenderBox", "C_DynamicProp", "client.dll");
	SCHEMA(bool, m_bUseAnimGraph, "m_bUseAnimGraph", "C_DynamicProp", "client.dll");
	SCHEMA(CEntityIOOutput, m_pOutputAnimBegun, "m_pOutputAnimBegun", "C_DynamicProp", "client.dll");
	SCHEMA(CEntityIOOutput, m_pOutputAnimOver, "m_pOutputAnimOver", "C_DynamicProp", "client.dll");
	SCHEMA(CEntityIOOutput, m_pOutputAnimLoopCycleOver, "m_pOutputAnimLoopCycleOver", "C_DynamicProp", "client.dll");
	SCHEMA(CEntityIOOutput, m_OnAnimReachedStart, "m_OnAnimReachedStart", "C_DynamicProp", "client.dll");
	SCHEMA(CEntityIOOutput, m_OnAnimReachedEnd, "m_OnAnimReachedEnd", "C_DynamicProp", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_iszIdleAnim, "m_iszIdleAnim", "C_DynamicProp", "client.dll");
	SCHEMA(AnimLoopMode_t, m_nIdleAnimLoopMode, "m_nIdleAnimLoopMode", "C_DynamicProp", "client.dll");
	SCHEMA(bool, m_bRandomizeCycle, "m_bRandomizeCycle", "C_DynamicProp", "client.dll");
	SCHEMA(bool, m_bStartDisabled, "m_bStartDisabled", "C_DynamicProp", "client.dll");
	SCHEMA(bool, m_bFiredStartEndOutput, "m_bFiredStartEndOutput", "C_DynamicProp", "client.dll");
	SCHEMA(bool, m_bForceNpcExclude, "m_bForceNpcExclude", "C_DynamicProp", "client.dll");
	SCHEMA(bool, m_bCreateNonSolid, "m_bCreateNonSolid", "C_DynamicProp", "client.dll");
	SCHEMA(bool, m_bIsOverrideProp, "m_bIsOverrideProp", "C_DynamicProp", "client.dll");
	SCHEMA(int32, m_iInitialGlowState, "m_iInitialGlowState", "C_DynamicProp", "client.dll");
	SCHEMA(int32, m_nGlowRange, "m_nGlowRange", "C_DynamicProp", "client.dll");
	SCHEMA(int32, m_nGlowRangeMin, "m_nGlowRangeMin", "C_DynamicProp", "client.dll");
	SCHEMA(Color, m_glowColor, "m_glowColor", "C_DynamicProp", "client.dll");
	SCHEMA(int32, m_nGlowTeam, "m_nGlowTeam", "C_DynamicProp", "client.dll");
	SCHEMA(int32, m_iCachedFrameCount, "m_iCachedFrameCount", "C_DynamicProp", "client.dll");
	SCHEMA(Vector, m_vecCachedRenderMins, "m_vecCachedRenderMins", "C_DynamicProp", "client.dll");
	SCHEMA(Vector, m_vecCachedRenderMaxs, "m_vecCachedRenderMaxs", "C_DynamicProp", "client.dll");
};

// Class: C_BasePropDoor (Size: 0x1460)
class C_BasePropDoor : public C_DynamicProp {
public:
	SCHEMA(DoorState_t, m_eDoorState, "m_eDoorState", "C_BasePropDoor", "client.dll");
	SCHEMA(bool, m_modelChanged, "m_modelChanged", "C_BasePropDoor", "client.dll");
	SCHEMA(bool, m_bLocked, "m_bLocked", "C_BasePropDoor", "client.dll");
	SCHEMA(bool, m_bNoNPCs, "m_bNoNPCs", "C_BasePropDoor", "client.dll");
	SCHEMA(Vector, m_closedPosition, "m_closedPosition", "C_BasePropDoor", "client.dll");
	SCHEMA(QAngle, m_closedAngles, "m_closedAngles", "C_BasePropDoor", "client.dll");
	SCHEMA(CHandle, m_hMaster, "m_hMaster", "C_BasePropDoor", "client.dll");
	SCHEMA(Vector, m_vWhereToSetLightingOrigin, "m_vWhereToSetLightingOrigin", "C_BasePropDoor", "client.dll");
};

// Class: C_Chicken (Size: 0x1930)
class C_Chicken : public C_DynamicProp {
public:
	SCHEMA(CHandle, m_hHolidayHatAddon, "m_hHolidayHatAddon", "C_Chicken", "client.dll");
	SCHEMA(bool, m_jumpedThisFrame, "m_jumpedThisFrame", "C_Chicken", "client.dll");
	SCHEMA(CHandle, m_leader, "m_leader", "C_Chicken", "client.dll");
	SCHEMA(C_AttributeContainer, m_AttributeManager, "m_AttributeManager", "C_Chicken", "client.dll");
	SCHEMA(bool, m_bAttributesInitialized, "m_bAttributesInitialized", "C_Chicken", "client.dll");
	SCHEMA(ParticleIndex_t, m_hWaterWakeParticles, "m_hWaterWakeParticles", "C_Chicken", "client.dll");
	SCHEMA(bool, m_bIsPreviewModel, "m_bIsPreviewModel", "C_Chicken", "client.dll");
};

// Class: C_EconEntity (Size: 0x18E0)
class C_EconEntity : public C_BaseFlex {
public:
	SCHEMA(float32, m_flFlexDelayTime, "m_flFlexDelayTime", "C_EconEntity", "client.dll");
	SCHEMA(float32*, m_flFlexDelayedWeight, "m_flFlexDelayedWeight", "C_EconEntity", "client.dll");
	SCHEMA(bool, m_bAttributesInitialized, "m_bAttributesInitialized", "C_EconEntity", "client.dll");
	SCHEMA(C_AttributeContainer, m_AttributeManager, "m_AttributeManager", "C_EconEntity", "client.dll");
	SCHEMA(uint32, m_OriginalOwnerXuidLow, "m_OriginalOwnerXuidLow", "C_EconEntity", "client.dll");
	SCHEMA(uint32, m_OriginalOwnerXuidHigh, "m_OriginalOwnerXuidHigh", "C_EconEntity", "client.dll");
	SCHEMA(int32, m_nFallbackPaintKit, "m_nFallbackPaintKit", "C_EconEntity", "client.dll");
	SCHEMA(int32, m_nFallbackSeed, "m_nFallbackSeed", "C_EconEntity", "client.dll");
	SCHEMA(float32, m_flFallbackWear, "m_flFallbackWear", "C_EconEntity", "client.dll");
	SCHEMA(int32, m_nFallbackStatTrak, "m_nFallbackStatTrak", "C_EconEntity", "client.dll");
	SCHEMA(bool, m_bClientside, "m_bClientside", "C_EconEntity", "client.dll");
	SCHEMA(bool, m_bParticleSystemsCreated, "m_bParticleSystemsCreated", "C_EconEntity", "client.dll");
	SCHEMA(CUtlVector< int32 >, m_vecAttachedParticles, "m_vecAttachedParticles", "C_EconEntity", "client.dll");
	SCHEMA(CHandle, m_hViewmodelAttachment, "m_hViewmodelAttachment", "C_EconEntity", "client.dll");
	SCHEMA(int32, m_iOldTeam, "m_iOldTeam", "C_EconEntity", "client.dll");
	SCHEMA(bool, m_bAttachmentDirty, "m_bAttachmentDirty", "C_EconEntity", "client.dll");
	SCHEMA(int32, m_nUnloadedModelIndex, "m_nUnloadedModelIndex", "C_EconEntity", "client.dll");
	SCHEMA(int32, m_iNumOwnerValidationRetries, "m_iNumOwnerValidationRetries", "C_EconEntity", "client.dll");
	SCHEMA(CHandle, m_hOldProvidee, "m_hOldProvidee", "C_EconEntity", "client.dll");
};

// Class: C_BasePlayerWeapon (Size: 0x1918)
class C_BasePlayerWeapon : public C_EconEntity {
public:
	SCHEMA(GameTick_t, m_nNextPrimaryAttackTick, "m_nNextPrimaryAttackTick", "C_BasePlayerWeapon", "client.dll");
	SCHEMA(float32, m_flNextPrimaryAttackTickRatio, "m_flNextPrimaryAttackTickRatio", "C_BasePlayerWeapon", "client.dll");
	SCHEMA(GameTick_t, m_nNextSecondaryAttackTick, "m_nNextSecondaryAttackTick", "C_BasePlayerWeapon", "client.dll");
	SCHEMA(float32, m_flNextSecondaryAttackTickRatio, "m_flNextSecondaryAttackTickRatio", "C_BasePlayerWeapon", "client.dll");
	SCHEMA(int32, m_iClip1, "m_iClip1", "C_BasePlayerWeapon", "client.dll");
	SCHEMA(int32, m_iClip2, "m_iClip2", "C_BasePlayerWeapon", "client.dll");
	SCHEMA(int32*, m_pReserveAmmo, "m_pReserveAmmo", "C_BasePlayerWeapon", "client.dll");
};

// Class: C_CSWeaponBase (Size: 0x1F80)
class C_CSWeaponBase : public C_BasePlayerWeapon {
public:
	SCHEMA(WeaponGameplayAnimState, m_iWeaponGameplayAnimState, "m_iWeaponGameplayAnimState", "C_CSWeaponBase", "client.dll");
	SCHEMA(GameTime_t, m_flWeaponGameplayAnimStateTimestamp, "m_flWeaponGameplayAnimStateTimestamp", "C_CSWeaponBase", "client.dll");
	SCHEMA(GameTime_t, m_flInspectCancelCompleteTime, "m_flInspectCancelCompleteTime", "C_CSWeaponBase", "client.dll");
	SCHEMA(bool, m_bInspectPending, "m_bInspectPending", "C_CSWeaponBase", "client.dll");
	SCHEMA(bool, m_bInspectShouldLoop, "m_bInspectShouldLoop", "C_CSWeaponBase", "client.dll");
	SCHEMA(float32, m_flCrosshairDistance, "m_flCrosshairDistance", "C_CSWeaponBase", "client.dll");
	SCHEMA(int32, m_iAmmoLastCheck, "m_iAmmoLastCheck", "C_CSWeaponBase", "client.dll");
	SCHEMA(int32, m_nLastEmptySoundCmdNum, "m_nLastEmptySoundCmdNum", "C_CSWeaponBase", "client.dll");
	SCHEMA(bool, m_bFireOnEmpty, "m_bFireOnEmpty", "C_CSWeaponBase", "client.dll");
	SCHEMA(CEntityIOOutput, m_OnPlayerPickup, "m_OnPlayerPickup", "C_CSWeaponBase", "client.dll");
	SCHEMA(CSWeaponMode, m_weaponMode, "m_weaponMode", "C_CSWeaponBase", "client.dll");
	SCHEMA(float32, m_flTurningInaccuracyDelta, "m_flTurningInaccuracyDelta", "C_CSWeaponBase", "client.dll");
	SCHEMA(Vector, m_vecTurningInaccuracyEyeDirLast, "m_vecTurningInaccuracyEyeDirLast", "C_CSWeaponBase", "client.dll");
	SCHEMA(float32, m_flTurningInaccuracy, "m_flTurningInaccuracy", "C_CSWeaponBase", "client.dll");
	SCHEMA(float32, m_fAccuracyPenalty, "m_fAccuracyPenalty", "C_CSWeaponBase", "client.dll");
	SCHEMA(GameTime_t, m_flLastAccuracyUpdateTime, "m_flLastAccuracyUpdateTime", "C_CSWeaponBase", "client.dll");
	SCHEMA(float32, m_fAccuracySmoothedForZoom, "m_fAccuracySmoothedForZoom", "C_CSWeaponBase", "client.dll");
	SCHEMA(int32, m_iRecoilIndex, "m_iRecoilIndex", "C_CSWeaponBase", "client.dll");
	SCHEMA(float32, m_flRecoilIndex, "m_flRecoilIndex", "C_CSWeaponBase", "client.dll");
	SCHEMA(bool, m_bBurstMode, "m_bBurstMode", "C_CSWeaponBase", "client.dll");
	SCHEMA(GameTime_t, m_flLastBurstModeChangeTime, "m_flLastBurstModeChangeTime", "C_CSWeaponBase", "client.dll");
	SCHEMA(GameTick_t, m_nPostponeFireReadyTicks, "m_nPostponeFireReadyTicks", "C_CSWeaponBase", "client.dll");
	SCHEMA(float32, m_flPostponeFireReadyFrac, "m_flPostponeFireReadyFrac", "C_CSWeaponBase", "client.dll");
	SCHEMA(bool, m_bInReload, "m_bInReload", "C_CSWeaponBase", "client.dll");
	SCHEMA(GameTime_t, m_flDroppedAtTime, "m_flDroppedAtTime", "C_CSWeaponBase", "client.dll");
	SCHEMA(bool, m_bIsHauledBack, "m_bIsHauledBack", "C_CSWeaponBase", "client.dll");
	SCHEMA(bool, m_bSilencerOn, "m_bSilencerOn", "C_CSWeaponBase", "client.dll");
	SCHEMA(GameTime_t, m_flTimeSilencerSwitchComplete, "m_flTimeSilencerSwitchComplete", "C_CSWeaponBase", "client.dll");
	SCHEMA(int32, m_iOriginalTeamNumber, "m_iOriginalTeamNumber", "C_CSWeaponBase", "client.dll");
	SCHEMA(int32, m_iMostRecentTeamNumber, "m_iMostRecentTeamNumber", "C_CSWeaponBase", "client.dll");
	SCHEMA(bool, m_bDroppedNearBuyZone, "m_bDroppedNearBuyZone", "C_CSWeaponBase", "client.dll");
	SCHEMA(float32, m_flNextAttackRenderTimeOffset, "m_flNextAttackRenderTimeOffset", "C_CSWeaponBase", "client.dll");
	SCHEMA(bool, m_bClearWeaponIdentifyingUGC, "m_bClearWeaponIdentifyingUGC", "C_CSWeaponBase", "client.dll");
	SCHEMA(bool, m_bVisualsDataSet, "m_bVisualsDataSet", "C_CSWeaponBase", "client.dll");
	SCHEMA(bool, m_bUIWeapon, "m_bUIWeapon", "C_CSWeaponBase", "client.dll");
	SCHEMA(int32, m_nCustomEconReloadEventId, "m_nCustomEconReloadEventId", "C_CSWeaponBase", "client.dll");
	SCHEMA(GameTime_t, m_nextPrevOwnerUseTime, "m_nextPrevOwnerUseTime", "C_CSWeaponBase", "client.dll");
	SCHEMA(CHandle, m_hPrevOwner, "m_hPrevOwner", "C_CSWeaponBase", "client.dll");
	SCHEMA(GameTick_t, m_nDropTick, "m_nDropTick", "C_CSWeaponBase", "client.dll");
	SCHEMA(bool, m_bWasActiveWeaponWhenDropped, "m_bWasActiveWeaponWhenDropped", "C_CSWeaponBase", "client.dll");
	SCHEMA(bool, m_donated, "m_donated", "C_CSWeaponBase", "client.dll");
	SCHEMA(GameTime_t, m_fLastShotTime, "m_fLastShotTime", "C_CSWeaponBase", "client.dll");
	SCHEMA(bool, m_bWasOwnedByCT, "m_bWasOwnedByCT", "C_CSWeaponBase", "client.dll");
	SCHEMA(bool, m_bWasOwnedByTerrorist, "m_bWasOwnedByTerrorist", "C_CSWeaponBase", "client.dll");
	SCHEMA(float32, m_flNextClientFireBulletTime, "m_flNextClientFireBulletTime", "C_CSWeaponBase", "client.dll");
	SCHEMA(float32, m_flNextClientFireBulletTime_Repredict, "m_flNextClientFireBulletTime_Repredict", "C_CSWeaponBase", "client.dll");
	SCHEMA(C_IronSightController, m_IronSightController, "m_IronSightController", "C_CSWeaponBase", "client.dll");
	SCHEMA(int32, m_iIronSightMode, "m_iIronSightMode", "C_CSWeaponBase", "client.dll");
	SCHEMA(GameTime_t, m_flLastLOSTraceFailureTime, "m_flLastLOSTraceFailureTime", "C_CSWeaponBase", "client.dll");
	SCHEMA(float32, m_flWatTickOffset, "m_flWatTickOffset", "C_CSWeaponBase", "client.dll");
	SCHEMA(GameTime_t, m_flLastShakeTime, "m_flLastShakeTime", "C_CSWeaponBase", "client.dll");
};

// Class: C_BaseCSGrenade (Size: 0x2040)
class C_BaseCSGrenade : public C_CSWeaponBase {
public:
	SCHEMA(bool, m_bClientPredictDelete, "m_bClientPredictDelete", "C_BaseCSGrenade", "client.dll");
	SCHEMA(bool, m_bRedraw, "m_bRedraw", "C_BaseCSGrenade", "client.dll");
	SCHEMA(bool, m_bIsHeldByPlayer, "m_bIsHeldByPlayer", "C_BaseCSGrenade", "client.dll");
	SCHEMA(bool, m_bPinPulled, "m_bPinPulled", "C_BaseCSGrenade", "client.dll");
	SCHEMA(bool, m_bJumpThrow, "m_bJumpThrow", "C_BaseCSGrenade", "client.dll");
	SCHEMA(bool, m_bThrowAnimating, "m_bThrowAnimating", "C_BaseCSGrenade", "client.dll");
	SCHEMA(GameTime_t, m_fThrowTime, "m_fThrowTime", "C_BaseCSGrenade", "client.dll");
	SCHEMA(float32, m_flThrowStrength, "m_flThrowStrength", "C_BaseCSGrenade", "client.dll");
	SCHEMA(GameTime_t, m_fDropTime, "m_fDropTime", "C_BaseCSGrenade", "client.dll");
	SCHEMA(GameTime_t, m_fPinPullTime, "m_fPinPullTime", "C_BaseCSGrenade", "client.dll");
	SCHEMA(bool, m_bJustPulledPin, "m_bJustPulledPin", "C_BaseCSGrenade", "client.dll");
	SCHEMA(GameTick_t, m_nNextHoldTick, "m_nNextHoldTick", "C_BaseCSGrenade", "client.dll");
	SCHEMA(float32, m_flNextHoldFrac, "m_flNextHoldFrac", "C_BaseCSGrenade", "client.dll");
	SCHEMA(CHandle, m_hSwitchToWeaponAfterThrow, "m_hSwitchToWeaponAfterThrow", "C_BaseCSGrenade", "client.dll");
};

// Class: C_C4 (Size: 0x1FC0)
class C_C4 : public C_CSWeaponBase {
public:
	SCHEMA(ParticleIndex_t, m_activeLightParticleIndex, "m_activeLightParticleIndex", "C_C4", "client.dll");
	SCHEMA(C4LightEffect_t, m_eActiveLightEffect, "m_eActiveLightEffect", "C_C4", "client.dll");
	SCHEMA(bool, m_bStartedArming, "m_bStartedArming", "C_C4", "client.dll");
	SCHEMA(GameTime_t, m_fArmedTime, "m_fArmedTime", "C_C4", "client.dll");
	SCHEMA(bool, m_bBombPlacedAnimation, "m_bBombPlacedAnimation", "C_C4", "client.dll");
	SCHEMA(bool, m_bIsPlantingViaUse, "m_bIsPlantingViaUse", "C_C4", "client.dll");
	SCHEMA(EntitySpottedState_t, m_entitySpottedState, "m_entitySpottedState", "C_C4", "client.dll");
	SCHEMA(int32, m_nSpotRules, "m_nSpotRules", "C_C4", "client.dll");
	SCHEMA(bool*, m_bPlayedArmingBeeps, "m_bPlayedArmingBeeps", "C_C4", "client.dll");
	SCHEMA(bool, m_bBombPlanted, "m_bBombPlanted", "C_C4", "client.dll");
};

// Class: C_CSWeaponBaseGun (Size: 0x1FB0)
class C_CSWeaponBaseGun : public C_CSWeaponBase {
public:
	SCHEMA(int32, m_zoomLevel, "m_zoomLevel", "C_CSWeaponBaseGun", "client.dll");
	SCHEMA(int32, m_iBurstShotsRemaining, "m_iBurstShotsRemaining", "C_CSWeaponBaseGun", "client.dll");
	SCHEMA(int32, m_iSilencerBodygroup, "m_iSilencerBodygroup", "C_CSWeaponBaseGun", "client.dll");
	SCHEMA(int32, m_silencedModelIndex, "m_silencedModelIndex", "C_CSWeaponBaseGun", "client.dll");
	SCHEMA(bool, m_inPrecache, "m_inPrecache", "C_CSWeaponBaseGun", "client.dll");
	SCHEMA(bool, m_bNeedsBoltAction, "m_bNeedsBoltAction", "C_CSWeaponBaseGun", "client.dll");
	SCHEMA(int32, m_nRevolverCylinderIdx, "m_nRevolverCylinderIdx", "C_CSWeaponBaseGun", "client.dll");
};

// Class: C_EconItemView (Size: 0x478)
class C_EconItemView {
public:
	SCHEMA(bool, m_bInventoryImageRgbaRequested, "m_bInventoryImageRgbaRequested", "C_EconItemView", "client.dll");
	SCHEMA(bool, m_bInventoryImageTriedCache, "m_bInventoryImageTriedCache", "C_EconItemView", "client.dll");
	SCHEMA(int32, m_nInventoryImageRgbaWidth, "m_nInventoryImageRgbaWidth", "C_EconItemView", "client.dll");
	SCHEMA(int32, m_nInventoryImageRgbaHeight, "m_nInventoryImageRgbaHeight", "C_EconItemView", "client.dll");
	SCHEMA(char*, m_szCurrentLoadCachedFileName, "m_szCurrentLoadCachedFileName", "C_EconItemView", "client.dll");
	SCHEMA(bool, m_bRestoreCustomMaterialAfterPrecache, "m_bRestoreCustomMaterialAfterPrecache", "C_EconItemView", "client.dll");
	SCHEMA(uint16, m_iItemDefinitionIndex, "m_iItemDefinitionIndex", "C_EconItemView", "client.dll");
	SCHEMA(int32, m_iEntityQuality, "m_iEntityQuality", "C_EconItemView", "client.dll");
	SCHEMA(uint32, m_iEntityLevel, "m_iEntityLevel", "C_EconItemView", "client.dll");
	SCHEMA(uint64, m_iItemID, "m_iItemID", "C_EconItemView", "client.dll");
	SCHEMA(uint32, m_iItemIDHigh, "m_iItemIDHigh", "C_EconItemView", "client.dll");
	SCHEMA(uint32, m_iItemIDLow, "m_iItemIDLow", "C_EconItemView", "client.dll");
	SCHEMA(uint32, m_iAccountID, "m_iAccountID", "C_EconItemView", "client.dll");
	SCHEMA(uint32, m_iInventoryPosition, "m_iInventoryPosition", "C_EconItemView", "client.dll");
	SCHEMA(bool, m_bInitialized, "m_bInitialized", "C_EconItemView", "client.dll");
	SCHEMA(bool, m_bDisallowSOC, "m_bDisallowSOC", "C_EconItemView", "client.dll");
	SCHEMA(bool, m_bIsStoreItem, "m_bIsStoreItem", "C_EconItemView", "client.dll");
	SCHEMA(bool, m_bIsTradeItem, "m_bIsTradeItem", "C_EconItemView", "client.dll");
	SCHEMA(int32, m_iEntityQuantity, "m_iEntityQuantity", "C_EconItemView", "client.dll");
	SCHEMA(int32, m_iRarityOverride, "m_iRarityOverride", "C_EconItemView", "client.dll");
	SCHEMA(int32, m_iQualityOverride, "m_iQualityOverride", "C_EconItemView", "client.dll");
	SCHEMA(int32, m_iOriginOverride, "m_iOriginOverride", "C_EconItemView", "client.dll");
	SCHEMA(uint8, m_ubStyleOverride, "m_ubStyleOverride", "C_EconItemView", "client.dll");
	SCHEMA(uint8, m_unClientFlags, "m_unClientFlags", "C_EconItemView", "client.dll");
	SCHEMA(CAttributeList, m_AttributeList, "m_AttributeList", "C_EconItemView", "client.dll");
	SCHEMA(CAttributeList, m_NetworkedDynamicAttributes, "m_NetworkedDynamicAttributes", "C_EconItemView", "client.dll");
	SCHEMA(char*, m_szCustomName, "m_szCustomName", "C_EconItemView", "client.dll");
	SCHEMA(char*, m_szCustomNameOverride, "m_szCustomNameOverride", "C_EconItemView", "client.dll");
	SCHEMA(bool, m_bInitializedTags, "m_bInitializedTags", "C_EconItemView", "client.dll");
};

// Class: C_EconWearable (Size: 0x18E8)
class C_EconWearable : public C_EconEntity {
public:
	SCHEMA(int32, m_nForceSkin, "m_nForceSkin", "C_EconWearable", "client.dll");
	SCHEMA(bool, m_bAlwaysAllow, "m_bAlwaysAllow", "C_EconWearable", "client.dll");
};

// Class: C_EntityDissolve (Size: 0xEF8)
class C_EntityDissolve : public C_BaseModelEntity {
public:
	SCHEMA(GameTime_t, m_flStartTime, "m_flStartTime", "C_EntityDissolve", "client.dll");
	SCHEMA(float32, m_flFadeInStart, "m_flFadeInStart", "C_EntityDissolve", "client.dll");
	SCHEMA(float32, m_flFadeInLength, "m_flFadeInLength", "C_EntityDissolve", "client.dll");
	SCHEMA(float32, m_flFadeOutModelStart, "m_flFadeOutModelStart", "C_EntityDissolve", "client.dll");
	SCHEMA(float32, m_flFadeOutModelLength, "m_flFadeOutModelLength", "C_EntityDissolve", "client.dll");
	SCHEMA(float32, m_flFadeOutStart, "m_flFadeOutStart", "C_EntityDissolve", "client.dll");
	SCHEMA(float32, m_flFadeOutLength, "m_flFadeOutLength", "C_EntityDissolve", "client.dll");
	SCHEMA(GameTime_t, m_flNextSparkTime, "m_flNextSparkTime", "C_EntityDissolve", "client.dll");
	SCHEMA(EntityDisolveType_t, m_nDissolveType, "m_nDissolveType", "C_EntityDissolve", "client.dll");
	SCHEMA(Vector, m_vDissolverOrigin, "m_vDissolverOrigin", "C_EntityDissolve", "client.dll");
	SCHEMA(uint32, m_nMagnitude, "m_nMagnitude", "C_EntityDissolve", "client.dll");
	SCHEMA(bool, m_bCoreExplode, "m_bCoreExplode", "C_EntityDissolve", "client.dll");
	SCHEMA(bool, m_bLinkedToServerEnt, "m_bLinkedToServerEnt", "C_EntityDissolve", "client.dll");
};

// Class: C_EntityFlame (Size: 0x640)
class C_EntityFlame : public C_BaseEntity {
public:
	SCHEMA(CHandle, m_hEntAttached, "m_hEntAttached", "C_EntityFlame", "client.dll");
	SCHEMA(CHandle, m_hOldAttached, "m_hOldAttached", "C_EntityFlame", "client.dll");
	SCHEMA(bool, m_bCheapEffect, "m_bCheapEffect", "C_EntityFlame", "client.dll");
};

// Class: C_EnvCombinedLightProbeVolume (Size: 0x1740)
class C_EnvCombinedLightProbeVolume : public C_BaseEntity {
public:
	SCHEMA(Color, m_Entity_Color, "m_Entity_Color", "C_EnvCombinedLightProbeVolume", "client.dll");
	SCHEMA(float32, m_Entity_flBrightness, "m_Entity_flBrightness", "C_EnvCombinedLightProbeVolume", "client.dll");
	SCHEMA(bool, m_Entity_bCustomCubemapTexture, "m_Entity_bCustomCubemapTexture", "C_EnvCombinedLightProbeVolume", "client.dll");
	SCHEMA(Vector, m_Entity_vBoxMins, "m_Entity_vBoxMins", "C_EnvCombinedLightProbeVolume", "client.dll");
	SCHEMA(Vector, m_Entity_vBoxMaxs, "m_Entity_vBoxMaxs", "C_EnvCombinedLightProbeVolume", "client.dll");
	SCHEMA(bool, m_Entity_bMoveable, "m_Entity_bMoveable", "C_EnvCombinedLightProbeVolume", "client.dll");
	SCHEMA(int32, m_Entity_nHandshake, "m_Entity_nHandshake", "C_EnvCombinedLightProbeVolume", "client.dll");
	SCHEMA(int32, m_Entity_nEnvCubeMapArrayIndex, "m_Entity_nEnvCubeMapArrayIndex", "C_EnvCombinedLightProbeVolume", "client.dll");
	SCHEMA(int32, m_Entity_nPriority, "m_Entity_nPriority", "C_EnvCombinedLightProbeVolume", "client.dll");
	SCHEMA(bool, m_Entity_bStartDisabled, "m_Entity_bStartDisabled", "C_EnvCombinedLightProbeVolume", "client.dll");
	SCHEMA(float32, m_Entity_flEdgeFadeDist, "m_Entity_flEdgeFadeDist", "C_EnvCombinedLightProbeVolume", "client.dll");
	SCHEMA(Vector, m_Entity_vEdgeFadeDists, "m_Entity_vEdgeFadeDists", "C_EnvCombinedLightProbeVolume", "client.dll");
	SCHEMA(int32, m_Entity_nLightProbeSizeX, "m_Entity_nLightProbeSizeX", "C_EnvCombinedLightProbeVolume", "client.dll");
	SCHEMA(int32, m_Entity_nLightProbeSizeY, "m_Entity_nLightProbeSizeY", "C_EnvCombinedLightProbeVolume", "client.dll");
	SCHEMA(int32, m_Entity_nLightProbeSizeZ, "m_Entity_nLightProbeSizeZ", "C_EnvCombinedLightProbeVolume", "client.dll");
	SCHEMA(int32, m_Entity_nLightProbeAtlasX, "m_Entity_nLightProbeAtlasX", "C_EnvCombinedLightProbeVolume", "client.dll");
	SCHEMA(int32, m_Entity_nLightProbeAtlasY, "m_Entity_nLightProbeAtlasY", "C_EnvCombinedLightProbeVolume", "client.dll");
	SCHEMA(int32, m_Entity_nLightProbeAtlasZ, "m_Entity_nLightProbeAtlasZ", "C_EnvCombinedLightProbeVolume", "client.dll");
	SCHEMA(bool, m_Entity_bEnabled, "m_Entity_bEnabled", "C_EnvCombinedLightProbeVolume", "client.dll");
};

// Class: C_EnvCubemap (Size: 0x6E0)
class C_EnvCubemap : public C_BaseEntity {
public:
	SCHEMA(bool, m_Entity_bCustomCubemapTexture, "m_Entity_bCustomCubemapTexture", "C_EnvCubemap", "client.dll");
	SCHEMA(float32, m_Entity_flInfluenceRadius, "m_Entity_flInfluenceRadius", "C_EnvCubemap", "client.dll");
	SCHEMA(Vector, m_Entity_vBoxProjectMins, "m_Entity_vBoxProjectMins", "C_EnvCubemap", "client.dll");
	SCHEMA(Vector, m_Entity_vBoxProjectMaxs, "m_Entity_vBoxProjectMaxs", "C_EnvCubemap", "client.dll");
	SCHEMA(bool, m_Entity_bMoveable, "m_Entity_bMoveable", "C_EnvCubemap", "client.dll");
	SCHEMA(int32, m_Entity_nHandshake, "m_Entity_nHandshake", "C_EnvCubemap", "client.dll");
	SCHEMA(int32, m_Entity_nEnvCubeMapArrayIndex, "m_Entity_nEnvCubeMapArrayIndex", "C_EnvCubemap", "client.dll");
	SCHEMA(int32, m_Entity_nPriority, "m_Entity_nPriority", "C_EnvCubemap", "client.dll");
	SCHEMA(float32, m_Entity_flEdgeFadeDist, "m_Entity_flEdgeFadeDist", "C_EnvCubemap", "client.dll");
	SCHEMA(Vector, m_Entity_vEdgeFadeDists, "m_Entity_vEdgeFadeDists", "C_EnvCubemap", "client.dll");
	SCHEMA(float32, m_Entity_flDiffuseScale, "m_Entity_flDiffuseScale", "C_EnvCubemap", "client.dll");
	SCHEMA(bool, m_Entity_bStartDisabled, "m_Entity_bStartDisabled", "C_EnvCubemap", "client.dll");
	SCHEMA(bool, m_Entity_bDefaultEnvMap, "m_Entity_bDefaultEnvMap", "C_EnvCubemap", "client.dll");
	SCHEMA(bool, m_Entity_bDefaultSpecEnvMap, "m_Entity_bDefaultSpecEnvMap", "C_EnvCubemap", "client.dll");
	SCHEMA(bool, m_Entity_bIndoorCubeMap, "m_Entity_bIndoorCubeMap", "C_EnvCubemap", "client.dll");
	SCHEMA(bool, m_Entity_bCopyDiffuseFromDefaultCubemap, "m_Entity_bCopyDiffuseFromDefaultCubemap", "C_EnvCubemap", "client.dll");
	SCHEMA(bool, m_Entity_bEnabled, "m_Entity_bEnabled", "C_EnvCubemap", "client.dll");
};

// Class: C_EnvCubemapFog (Size: 0x648)
class C_EnvCubemapFog : public C_BaseEntity {
public:
	SCHEMA(float32, m_flEndDistance, "m_flEndDistance", "C_EnvCubemapFog", "client.dll");
	SCHEMA(float32, m_flStartDistance, "m_flStartDistance", "C_EnvCubemapFog", "client.dll");
	SCHEMA(float32, m_flFogFalloffExponent, "m_flFogFalloffExponent", "C_EnvCubemapFog", "client.dll");
	SCHEMA(bool, m_bHeightFogEnabled, "m_bHeightFogEnabled", "C_EnvCubemapFog", "client.dll");
	SCHEMA(float32, m_flFogHeightWidth, "m_flFogHeightWidth", "C_EnvCubemapFog", "client.dll");
	SCHEMA(float32, m_flFogHeightEnd, "m_flFogHeightEnd", "C_EnvCubemapFog", "client.dll");
	SCHEMA(float32, m_flFogHeightStart, "m_flFogHeightStart", "C_EnvCubemapFog", "client.dll");
	SCHEMA(float32, m_flFogHeightExponent, "m_flFogHeightExponent", "C_EnvCubemapFog", "client.dll");
	SCHEMA(float32, m_flLODBias, "m_flLODBias", "C_EnvCubemapFog", "client.dll");
	SCHEMA(bool, m_bActive, "m_bActive", "C_EnvCubemapFog", "client.dll");
	SCHEMA(bool, m_bStartDisabled, "m_bStartDisabled", "C_EnvCubemapFog", "client.dll");
	SCHEMA(float32, m_flFogMaxOpacity, "m_flFogMaxOpacity", "C_EnvCubemapFog", "client.dll");
	SCHEMA(int32, m_nCubemapSourceType, "m_nCubemapSourceType", "C_EnvCubemapFog", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_iszSkyEntity, "m_iszSkyEntity", "C_EnvCubemapFog", "client.dll");
	SCHEMA(bool, m_bHasHeightFogEnd, "m_bHasHeightFogEnd", "C_EnvCubemapFog", "client.dll");
	SCHEMA(bool, m_bFirstTime, "m_bFirstTime", "C_EnvCubemapFog", "client.dll");
};

// Class: C_EnvDecal (Size: 0xEE8)
class C_EnvDecal : public C_BaseModelEntity {
public:
	SCHEMA(float32, m_flWidth, "m_flWidth", "C_EnvDecal", "client.dll");
	SCHEMA(float32, m_flHeight, "m_flHeight", "C_EnvDecal", "client.dll");
	SCHEMA(float32, m_flDepth, "m_flDepth", "C_EnvDecal", "client.dll");
	SCHEMA(uint32, m_nRenderOrder, "m_nRenderOrder", "C_EnvDecal", "client.dll");
	SCHEMA(bool, m_bProjectOnWorld, "m_bProjectOnWorld", "C_EnvDecal", "client.dll");
	SCHEMA(bool, m_bProjectOnCharacters, "m_bProjectOnCharacters", "C_EnvDecal", "client.dll");
	SCHEMA(bool, m_bProjectOnWater, "m_bProjectOnWater", "C_EnvDecal", "client.dll");
	SCHEMA(float32, m_flDepthSortBias, "m_flDepthSortBias", "C_EnvDecal", "client.dll");
};

// Class: C_EnvDetailController (Size: 0x600)
class C_EnvDetailController : public C_BaseEntity {
public:
	SCHEMA(float32, m_flFadeStartDist, "m_flFadeStartDist", "C_EnvDetailController", "client.dll");
	SCHEMA(float32, m_flFadeEndDist, "m_flFadeEndDist", "C_EnvDetailController", "client.dll");
};

// Class: C_EnvLightProbeVolume (Size: 0x1688)
class C_EnvLightProbeVolume : public C_BaseEntity {
public:
	SCHEMA(Vector, m_Entity_vBoxMins, "m_Entity_vBoxMins", "C_EnvLightProbeVolume", "client.dll");
	SCHEMA(Vector, m_Entity_vBoxMaxs, "m_Entity_vBoxMaxs", "C_EnvLightProbeVolume", "client.dll");
	SCHEMA(bool, m_Entity_bMoveable, "m_Entity_bMoveable", "C_EnvLightProbeVolume", "client.dll");
	SCHEMA(int32, m_Entity_nHandshake, "m_Entity_nHandshake", "C_EnvLightProbeVolume", "client.dll");
	SCHEMA(int32, m_Entity_nPriority, "m_Entity_nPriority", "C_EnvLightProbeVolume", "client.dll");
	SCHEMA(bool, m_Entity_bStartDisabled, "m_Entity_bStartDisabled", "C_EnvLightProbeVolume", "client.dll");
	SCHEMA(int32, m_Entity_nLightProbeSizeX, "m_Entity_nLightProbeSizeX", "C_EnvLightProbeVolume", "client.dll");
	SCHEMA(int32, m_Entity_nLightProbeSizeY, "m_Entity_nLightProbeSizeY", "C_EnvLightProbeVolume", "client.dll");
	SCHEMA(int32, m_Entity_nLightProbeSizeZ, "m_Entity_nLightProbeSizeZ", "C_EnvLightProbeVolume", "client.dll");
	SCHEMA(int32, m_Entity_nLightProbeAtlasX, "m_Entity_nLightProbeAtlasX", "C_EnvLightProbeVolume", "client.dll");
	SCHEMA(int32, m_Entity_nLightProbeAtlasY, "m_Entity_nLightProbeAtlasY", "C_EnvLightProbeVolume", "client.dll");
	SCHEMA(int32, m_Entity_nLightProbeAtlasZ, "m_Entity_nLightProbeAtlasZ", "C_EnvLightProbeVolume", "client.dll");
	SCHEMA(bool, m_Entity_bEnabled, "m_Entity_bEnabled", "C_EnvLightProbeVolume", "client.dll");
};

// Class: C_EnvSky (Size: 0xF10)
class C_EnvSky : public C_BaseModelEntity {
public:
	SCHEMA(bool, m_bStartDisabled, "m_bStartDisabled", "C_EnvSky", "client.dll");
	SCHEMA(Color, m_vTintColor, "m_vTintColor", "C_EnvSky", "client.dll");
	SCHEMA(Color, m_vTintColorLightingOnly, "m_vTintColorLightingOnly", "C_EnvSky", "client.dll");
	SCHEMA(float32, m_flBrightnessScale, "m_flBrightnessScale", "C_EnvSky", "client.dll");
	SCHEMA(int32, m_nFogType, "m_nFogType", "C_EnvSky", "client.dll");
	SCHEMA(float32, m_flFogMinStart, "m_flFogMinStart", "C_EnvSky", "client.dll");
	SCHEMA(float32, m_flFogMinEnd, "m_flFogMinEnd", "C_EnvSky", "client.dll");
	SCHEMA(float32, m_flFogMaxStart, "m_flFogMaxStart", "C_EnvSky", "client.dll");
	SCHEMA(float32, m_flFogMaxEnd, "m_flFogMaxEnd", "C_EnvSky", "client.dll");
	SCHEMA(bool, m_bEnabled, "m_bEnabled", "C_EnvSky", "client.dll");
};

// Class: C_EnvVolumetricFogController (Size: 0x6A8)
class C_EnvVolumetricFogController : public C_BaseEntity {
public:
	SCHEMA(float32, m_flScattering, "m_flScattering", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(Color, m_TintColor, "m_TintColor", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(float32, m_flAnisotropy, "m_flAnisotropy", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(float32, m_flFadeSpeed, "m_flFadeSpeed", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(float32, m_flDrawDistance, "m_flDrawDistance", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(float32, m_flFadeInStart, "m_flFadeInStart", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(float32, m_flFadeInEnd, "m_flFadeInEnd", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(float32, m_flIndirectStrength, "m_flIndirectStrength", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(int32, m_nVolumeDepth, "m_nVolumeDepth", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(float32, m_fFirstVolumeSliceThickness, "m_fFirstVolumeSliceThickness", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(int32, m_nIndirectTextureDimX, "m_nIndirectTextureDimX", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(int32, m_nIndirectTextureDimY, "m_nIndirectTextureDimY", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(int32, m_nIndirectTextureDimZ, "m_nIndirectTextureDimZ", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(Vector, m_vBoxMins, "m_vBoxMins", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(Vector, m_vBoxMaxs, "m_vBoxMaxs", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(bool, m_bActive, "m_bActive", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(GameTime_t, m_flStartAnisoTime, "m_flStartAnisoTime", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(GameTime_t, m_flStartScatterTime, "m_flStartScatterTime", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(GameTime_t, m_flStartDrawDistanceTime, "m_flStartDrawDistanceTime", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(float32, m_flStartAnisotropy, "m_flStartAnisotropy", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(float32, m_flStartScattering, "m_flStartScattering", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(float32, m_flStartDrawDistance, "m_flStartDrawDistance", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(float32, m_flDefaultAnisotropy, "m_flDefaultAnisotropy", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(float32, m_flDefaultScattering, "m_flDefaultScattering", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(float32, m_flDefaultDrawDistance, "m_flDefaultDrawDistance", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(bool, m_bStartDisabled, "m_bStartDisabled", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(bool, m_bEnableIndirect, "m_bEnableIndirect", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(bool, m_bIsMaster, "m_bIsMaster", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(int32, m_nForceRefreshCount, "m_nForceRefreshCount", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(float32, m_fNoiseSpeed, "m_fNoiseSpeed", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(float32, m_fNoiseStrength, "m_fNoiseStrength", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(Vector, m_vNoiseScale, "m_vNoiseScale", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(float32, m_fWindSpeed, "m_fWindSpeed", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(Vector, m_vWindDirection, "m_vWindDirection", "C_EnvVolumetricFogController", "client.dll");
	SCHEMA(bool, m_bFirstTime, "m_bFirstTime", "C_EnvVolumetricFogController", "client.dll");
};

// Class: C_EnvVolumetricFogVolume (Size: 0x640)
class C_EnvVolumetricFogVolume : public C_BaseEntity {
public:
	SCHEMA(bool, m_bActive, "m_bActive", "C_EnvVolumetricFogVolume", "client.dll");
	SCHEMA(Vector, m_vBoxMins, "m_vBoxMins", "C_EnvVolumetricFogVolume", "client.dll");
	SCHEMA(Vector, m_vBoxMaxs, "m_vBoxMaxs", "C_EnvVolumetricFogVolume", "client.dll");
	SCHEMA(bool, m_bStartDisabled, "m_bStartDisabled", "C_EnvVolumetricFogVolume", "client.dll");
	SCHEMA(bool, m_bIndirectUseLPVs, "m_bIndirectUseLPVs", "C_EnvVolumetricFogVolume", "client.dll");
	SCHEMA(float32, m_flStrength, "m_flStrength", "C_EnvVolumetricFogVolume", "client.dll");
	SCHEMA(int32, m_nFalloffShape, "m_nFalloffShape", "C_EnvVolumetricFogVolume", "client.dll");
	SCHEMA(float32, m_flFalloffExponent, "m_flFalloffExponent", "C_EnvVolumetricFogVolume", "client.dll");
	SCHEMA(float32, m_flHeightFogDepth, "m_flHeightFogDepth", "C_EnvVolumetricFogVolume", "client.dll");
	SCHEMA(float32, m_fHeightFogEdgeWidth, "m_fHeightFogEdgeWidth", "C_EnvVolumetricFogVolume", "client.dll");
	SCHEMA(float32, m_fIndirectLightStrength, "m_fIndirectLightStrength", "C_EnvVolumetricFogVolume", "client.dll");
	SCHEMA(float32, m_fSunLightStrength, "m_fSunLightStrength", "C_EnvVolumetricFogVolume", "client.dll");
	SCHEMA(float32, m_fNoiseStrength, "m_fNoiseStrength", "C_EnvVolumetricFogVolume", "client.dll");
	SCHEMA(Color, m_TintColor, "m_TintColor", "C_EnvVolumetricFogVolume", "client.dll");
	SCHEMA(bool, m_bOverrideTintColor, "m_bOverrideTintColor", "C_EnvVolumetricFogVolume", "client.dll");
	SCHEMA(bool, m_bOverrideIndirectLightStrength, "m_bOverrideIndirectLightStrength", "C_EnvVolumetricFogVolume", "client.dll");
	SCHEMA(bool, m_bOverrideSunLightStrength, "m_bOverrideSunLightStrength", "C_EnvVolumetricFogVolume", "client.dll");
	SCHEMA(bool, m_bOverrideNoiseStrength, "m_bOverrideNoiseStrength", "C_EnvVolumetricFogVolume", "client.dll");
};

// Class: C_EnvWind (Size: 0x6F0)
class C_EnvWind : public C_BaseEntity {
public:
	SCHEMA(C_EnvWindShared, m_EnvWindShared, "m_EnvWindShared", "C_EnvWind", "client.dll");
};

// Class: C_EnvWindClientside (Size: 0x6F0)
class C_EnvWindClientside : public C_BaseEntity {
public:
	SCHEMA(C_EnvWindShared, m_EnvWindShared, "m_EnvWindShared", "C_EnvWindClientside", "client.dll");
};

// Class: C_EnvWindController (Size: 0x718)
class C_EnvWindController : public C_BaseEntity {
public:
	SCHEMA(C_EnvWindShared, m_EnvWindShared, "m_EnvWindShared", "C_EnvWindController", "client.dll");
	SCHEMA(float32, m_fDirectionVariation, "m_fDirectionVariation", "C_EnvWindController", "client.dll");
	SCHEMA(float32, m_fSpeedVariation, "m_fSpeedVariation", "C_EnvWindController", "client.dll");
	SCHEMA(float32, m_fTurbulence, "m_fTurbulence", "C_EnvWindController", "client.dll");
	SCHEMA(float32, m_fVolumeHalfExtentXY, "m_fVolumeHalfExtentXY", "C_EnvWindController", "client.dll");
	SCHEMA(float32, m_fVolumeHalfExtentZ, "m_fVolumeHalfExtentZ", "C_EnvWindController", "client.dll");
	SCHEMA(int32, m_nVolumeResolutionXY, "m_nVolumeResolutionXY", "C_EnvWindController", "client.dll");
	SCHEMA(int32, m_nVolumeResolutionZ, "m_nVolumeResolutionZ", "C_EnvWindController", "client.dll");
	SCHEMA(int32, m_nClipmapLevels, "m_nClipmapLevels", "C_EnvWindController", "client.dll");
	SCHEMA(bool, m_bIsMaster, "m_bIsMaster", "C_EnvWindController", "client.dll");
	SCHEMA(bool, m_bFirstTime, "m_bFirstTime", "C_EnvWindController", "client.dll");
};

// Class: C_EnvWindShared (Size: 0xF8)
class C_EnvWindShared {
public:
	SCHEMA(GameTime_t, m_flStartTime, "m_flStartTime", "C_EnvWindShared", "client.dll");
	SCHEMA(uint32, m_iWindSeed, "m_iWindSeed", "C_EnvWindShared", "client.dll");
	SCHEMA(uint16, m_iMinWind, "m_iMinWind", "C_EnvWindShared", "client.dll");
	SCHEMA(uint16, m_iMaxWind, "m_iMaxWind", "C_EnvWindShared", "client.dll");
	SCHEMA(int32, m_windRadius, "m_windRadius", "C_EnvWindShared", "client.dll");
	SCHEMA(uint16, m_iMinGust, "m_iMinGust", "C_EnvWindShared", "client.dll");
	SCHEMA(uint16, m_iMaxGust, "m_iMaxGust", "C_EnvWindShared", "client.dll");
	SCHEMA(float32, m_flMinGustDelay, "m_flMinGustDelay", "C_EnvWindShared", "client.dll");
	SCHEMA(float32, m_flMaxGustDelay, "m_flMaxGustDelay", "C_EnvWindShared", "client.dll");
	SCHEMA(float32, m_flGustDuration, "m_flGustDuration", "C_EnvWindShared", "client.dll");
	SCHEMA(uint16, m_iGustDirChange, "m_iGustDirChange", "C_EnvWindShared", "client.dll");
	SCHEMA(uint16, m_iInitialWindDir, "m_iInitialWindDir", "C_EnvWindShared", "client.dll");
	SCHEMA(float32, m_flInitialWindSpeed, "m_flInitialWindSpeed", "C_EnvWindShared", "client.dll");
	SCHEMA(Vector, m_location, "m_location", "C_EnvWindShared", "client.dll");
	SCHEMA(CHandle, m_hEntOwner, "m_hEntOwner", "C_EnvWindShared", "client.dll");
};

// Class: C_EnvWindVolume (Size: 0x630)
class C_EnvWindVolume : public C_BaseEntity {
public:
	SCHEMA(bool, m_bActive, "m_bActive", "C_EnvWindVolume", "client.dll");
	SCHEMA(Vector, m_vBoxMins, "m_vBoxMins", "C_EnvWindVolume", "client.dll");
	SCHEMA(Vector, m_vBoxMaxs, "m_vBoxMaxs", "C_EnvWindVolume", "client.dll");
	SCHEMA(bool, m_bStartDisabled, "m_bStartDisabled", "C_EnvWindVolume", "client.dll");
	SCHEMA(int32, m_nShape, "m_nShape", "C_EnvWindVolume", "client.dll");
	SCHEMA(float32, m_fWindSpeedMultiplier, "m_fWindSpeedMultiplier", "C_EnvWindVolume", "client.dll");
	SCHEMA(float32, m_fWindTurbulenceMultiplier, "m_fWindTurbulenceMultiplier", "C_EnvWindVolume", "client.dll");
	SCHEMA(float32, m_fWindSpeedVariationMultiplier, "m_fWindSpeedVariationMultiplier", "C_EnvWindVolume", "client.dll");
	SCHEMA(float32, m_fWindDirectionVariationMultiplier, "m_fWindDirectionVariationMultiplier", "C_EnvWindVolume", "client.dll");
};

// Class: C_Fish (Size: 0x1248)
class C_Fish : public CBaseAnimGraph {
public:
	SCHEMA(Vector, m_pos, "m_pos", "C_Fish", "client.dll");
	SCHEMA(Vector, m_vel, "m_vel", "C_Fish", "client.dll");
	SCHEMA(QAngle, m_angles, "m_angles", "C_Fish", "client.dll");
	SCHEMA(int32, m_localLifeState, "m_localLifeState", "C_Fish", "client.dll");
	SCHEMA(float32, m_deathDepth, "m_deathDepth", "C_Fish", "client.dll");
	SCHEMA(float32, m_deathAngle, "m_deathAngle", "C_Fish", "client.dll");
	SCHEMA(float32, m_buoyancy, "m_buoyancy", "C_Fish", "client.dll");
	SCHEMA(CountdownTimer, m_wiggleTimer, "m_wiggleTimer", "C_Fish", "client.dll");
	SCHEMA(float32, m_wigglePhase, "m_wigglePhase", "C_Fish", "client.dll");
	SCHEMA(float32, m_wiggleRate, "m_wiggleRate", "C_Fish", "client.dll");
	SCHEMA(Vector, m_actualPos, "m_actualPos", "C_Fish", "client.dll");
	SCHEMA(QAngle, m_actualAngles, "m_actualAngles", "C_Fish", "client.dll");
	SCHEMA(Vector, m_poolOrigin, "m_poolOrigin", "C_Fish", "client.dll");
	SCHEMA(float32, m_waterLevel, "m_waterLevel", "C_Fish", "client.dll");
	SCHEMA(bool, m_gotUpdate, "m_gotUpdate", "C_Fish", "client.dll");
	SCHEMA(float32, m_x, "m_x", "C_Fish", "client.dll");
	SCHEMA(float32, m_y, "m_y", "C_Fish", "client.dll");
	SCHEMA(float32, m_z, "m_z", "C_Fish", "client.dll");
	SCHEMA(float32, m_angle, "m_angle", "C_Fish", "client.dll");
	SCHEMA(float32*, m_errorHistory, "m_errorHistory", "C_Fish", "client.dll");
	SCHEMA(int32, m_errorHistoryIndex, "m_errorHistoryIndex", "C_Fish", "client.dll");
	SCHEMA(int32, m_errorHistoryCount, "m_errorHistoryCount", "C_Fish", "client.dll");
	SCHEMA(float32, m_averageError, "m_averageError", "C_Fish", "client.dll");
};

// Class: C_FogController (Size: 0x668)
class C_FogController : public C_BaseEntity {
public:
	SCHEMA(fogparams_t, m_fog, "m_fog", "C_FogController", "client.dll");
	SCHEMA(bool, m_bUseAngles, "m_bUseAngles", "C_FogController", "client.dll");
	SCHEMA(int32, m_iChangedVariables, "m_iChangedVariables", "C_FogController", "client.dll");
};

// Class: C_FootstepControl (Size: 0x1000)
class C_FootstepControl : public C_BaseTrigger {
public:
	SCHEMA(CUtlSymbolLarge, m_source, "m_source", "C_FootstepControl", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_destination, "m_destination", "C_FootstepControl", "client.dll");
};

// Class: C_FuncConveyor (Size: 0xEF8)
class C_FuncConveyor : public C_BaseModelEntity {
public:
	SCHEMA(Vector, m_vecMoveDirEntitySpace, "m_vecMoveDirEntitySpace", "C_FuncConveyor", "client.dll");
	SCHEMA(float32, m_flTargetSpeed, "m_flTargetSpeed", "C_FuncConveyor", "client.dll");
	SCHEMA(GameTick_t, m_nTransitionStartTick, "m_nTransitionStartTick", "C_FuncConveyor", "client.dll");
	SCHEMA(int32, m_nTransitionDurationTicks, "m_nTransitionDurationTicks", "C_FuncConveyor", "client.dll");
	SCHEMA(float32, m_flTransitionStartSpeed, "m_flTransitionStartSpeed", "C_FuncConveyor", "client.dll");
	SCHEMA(CUtlVector< CHandle >, m_hConveyorModels, "m_hConveyorModels", "C_FuncConveyor", "client.dll");
	SCHEMA(float32, m_flCurrentConveyorOffset, "m_flCurrentConveyorOffset", "C_FuncConveyor", "client.dll");
	SCHEMA(float32, m_flCurrentConveyorSpeed, "m_flCurrentConveyorSpeed", "C_FuncConveyor", "client.dll");
};

// Class: C_FuncElectrifiedVolume (Size: 0xEC8)
class C_FuncElectrifiedVolume : public C_FuncBrush {
public:
	SCHEMA(ParticleIndex_t, m_nAmbientEffect, "m_nAmbientEffect", "C_FuncElectrifiedVolume", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_EffectName, "m_EffectName", "C_FuncElectrifiedVolume", "client.dll");
	SCHEMA(bool, m_bState, "m_bState", "C_FuncElectrifiedVolume", "client.dll");
};

// Class: C_FuncLadder (Size: 0xF08)
class C_FuncLadder : public C_BaseModelEntity {
public:
	SCHEMA(Vector, m_vecLadderDir, "m_vecLadderDir", "C_FuncLadder", "client.dll");
	SCHEMA(CUtlVector<CHandle>, m_Dismounts, "m_Dismounts", "C_FuncLadder", "client.dll");
	SCHEMA(Vector, m_vecLocalTop, "m_vecLocalTop", "C_FuncLadder", "client.dll");
	SCHEMA(VectorWS, m_vecPlayerMountPositionTop, "m_vecPlayerMountPositionTop", "C_FuncLadder", "client.dll");
	SCHEMA(VectorWS, m_vecPlayerMountPositionBottom, "m_vecPlayerMountPositionBottom", "C_FuncLadder", "client.dll");
	SCHEMA(float32, m_flAutoRideSpeed, "m_flAutoRideSpeed", "C_FuncLadder", "client.dll");
	SCHEMA(bool, m_bDisabled, "m_bDisabled", "C_FuncLadder", "client.dll");
	SCHEMA(bool, m_bFakeLadder, "m_bFakeLadder", "C_FuncLadder", "client.dll");
	SCHEMA(bool, m_bHasSlack, "m_bHasSlack", "C_FuncLadder", "client.dll");
};

// Class: C_FuncMonitor (Size: 0x1370)
class C_FuncMonitor : public C_FuncBrush {
public:
	SCHEMA(CUtlString, m_targetCamera, "m_targetCamera", "C_FuncMonitor", "client.dll");
	SCHEMA(int32, m_nResolutionEnum, "m_nResolutionEnum", "C_FuncMonitor", "client.dll");
	SCHEMA(bool, m_bRenderShadows, "m_bRenderShadows", "C_FuncMonitor", "client.dll");
	SCHEMA(bool, m_bUseUniqueColorTarget, "m_bUseUniqueColorTarget", "C_FuncMonitor", "client.dll");
	SCHEMA(CUtlString, m_brushModelName, "m_brushModelName", "C_FuncMonitor", "client.dll");
	SCHEMA(CHandle, m_hTargetCamera, "m_hTargetCamera", "C_FuncMonitor", "client.dll");
	SCHEMA(bool, m_bEnabled, "m_bEnabled", "C_FuncMonitor", "client.dll");
	SCHEMA(bool, m_bDraw3DSkybox, "m_bDraw3DSkybox", "C_FuncMonitor", "client.dll");
};

// Class: C_FuncTrackTrain (Size: 0xEC0)
class C_FuncTrackTrain : public C_BaseModelEntity {
public:
	SCHEMA(int32, m_nLongAxis, "m_nLongAxis", "C_FuncTrackTrain", "client.dll");
	SCHEMA(float32, m_flRadius, "m_flRadius", "C_FuncTrackTrain", "client.dll");
	SCHEMA(float32, m_flLineLength, "m_flLineLength", "C_FuncTrackTrain", "client.dll");
};

// Class: C_GameRules (Size: 0x40)
class C_GameRules {
public:
	SCHEMA(CNetworkVarChainer, __m_pChainEntity, "__m_pChainEntity", "C_GameRules", "client.dll");
	SCHEMA(int32, m_nTotalPausedTicks, "m_nTotalPausedTicks", "C_GameRules", "client.dll");
	SCHEMA(int32, m_nPauseStartTick, "m_nPauseStartTick", "C_GameRules", "client.dll");
	SCHEMA(bool, m_bGamePaused, "m_bGamePaused", "C_GameRules", "client.dll");
};

// Class: C_GlobalLight (Size: 0xAF0)
class C_GlobalLight : public C_BaseEntity {
public:
	SCHEMA(uint16, m_WindClothForceHandle, "m_WindClothForceHandle", "C_GlobalLight", "client.dll");
};

// Class: C_GradientFog (Size: 0x690)
class C_GradientFog : public C_BaseEntity {
public:
	SCHEMA(float32, m_flFogStartDistance, "m_flFogStartDistance", "C_GradientFog", "client.dll");
	SCHEMA(float32, m_flFogEndDistance, "m_flFogEndDistance", "C_GradientFog", "client.dll");
	SCHEMA(bool, m_bHeightFogEnabled, "m_bHeightFogEnabled", "C_GradientFog", "client.dll");
	SCHEMA(float32, m_flFogStartHeight, "m_flFogStartHeight", "C_GradientFog", "client.dll");
	SCHEMA(float32, m_flFogEndHeight, "m_flFogEndHeight", "C_GradientFog", "client.dll");
	SCHEMA(float32, m_flFarZ, "m_flFarZ", "C_GradientFog", "client.dll");
	SCHEMA(float32, m_flFogMaxOpacity, "m_flFogMaxOpacity", "C_GradientFog", "client.dll");
	SCHEMA(float32, m_flFogFalloffExponent, "m_flFogFalloffExponent", "C_GradientFog", "client.dll");
	SCHEMA(float32, m_flFogVerticalExponent, "m_flFogVerticalExponent", "C_GradientFog", "client.dll");
	SCHEMA(Color, m_fogColor, "m_fogColor", "C_GradientFog", "client.dll");
	SCHEMA(float32, m_flFogStrength, "m_flFogStrength", "C_GradientFog", "client.dll");
	SCHEMA(float32, m_flFadeTime, "m_flFadeTime", "C_GradientFog", "client.dll");
	SCHEMA(bool, m_bStartDisabled, "m_bStartDisabled", "C_GradientFog", "client.dll");
	SCHEMA(bool, m_bIsEnabled, "m_bIsEnabled", "C_GradientFog", "client.dll");
	SCHEMA(bool, m_bGradientFogNeedsTextures, "m_bGradientFogNeedsTextures", "C_GradientFog", "client.dll");
};

// Class: C_HandleTest (Size: 0x600)
class C_HandleTest : public C_BaseEntity {
public:
	SCHEMA(CHandle, m_Handle, "m_Handle", "C_HandleTest", "client.dll");
	SCHEMA(bool, m_bSendHandle, "m_bSendHandle", "C_HandleTest", "client.dll");
};

// Class: C_Hostage (Size: 0x14C0)
class C_Hostage : public C_BaseCombatCharacter {
public:
	SCHEMA(EntitySpottedState_t, m_entitySpottedState, "m_entitySpottedState", "C_Hostage", "client.dll");
	SCHEMA(CHandle, m_leader, "m_leader", "C_Hostage", "client.dll");
	SCHEMA(CountdownTimer, m_reuseTimer, "m_reuseTimer", "C_Hostage", "client.dll");
	SCHEMA(Vector, m_vel, "m_vel", "C_Hostage", "client.dll");
	SCHEMA(bool, m_isRescued, "m_isRescued", "C_Hostage", "client.dll");
	SCHEMA(bool, m_jumpedThisFrame, "m_jumpedThisFrame", "C_Hostage", "client.dll");
	SCHEMA(int32, m_nHostageState, "m_nHostageState", "C_Hostage", "client.dll");
	SCHEMA(bool, m_bHandsHaveBeenCut, "m_bHandsHaveBeenCut", "C_Hostage", "client.dll");
	SCHEMA(CHandle, m_hHostageGrabber, "m_hHostageGrabber", "C_Hostage", "client.dll");
	SCHEMA(GameTime_t, m_fLastGrabTime, "m_fLastGrabTime", "C_Hostage", "client.dll");
	SCHEMA(Vector, m_vecGrabbedPos, "m_vecGrabbedPos", "C_Hostage", "client.dll");
	SCHEMA(GameTime_t, m_flRescueStartTime, "m_flRescueStartTime", "C_Hostage", "client.dll");
	SCHEMA(GameTime_t, m_flGrabSuccessTime, "m_flGrabSuccessTime", "C_Hostage", "client.dll");
	SCHEMA(GameTime_t, m_flDropStartTime, "m_flDropStartTime", "C_Hostage", "client.dll");
	SCHEMA(GameTime_t, m_flDeadOrRescuedTime, "m_flDeadOrRescuedTime", "C_Hostage", "client.dll");
	SCHEMA(CountdownTimer, m_blinkTimer, "m_blinkTimer", "C_Hostage", "client.dll");
	SCHEMA(Vector, m_lookAt, "m_lookAt", "C_Hostage", "client.dll");
	SCHEMA(CountdownTimer, m_lookAroundTimer, "m_lookAroundTimer", "C_Hostage", "client.dll");
	SCHEMA(bool, m_isInit, "m_isInit", "C_Hostage", "client.dll");
	SCHEMA(AttachmentHandle_t, m_eyeAttachment, "m_eyeAttachment", "C_Hostage", "client.dll");
	SCHEMA(AttachmentHandle_t, m_chestAttachment, "m_chestAttachment", "C_Hostage", "client.dll");
	SCHEMA(CBasePlayerController*, m_pPredictionOwner, "m_pPredictionOwner", "C_Hostage", "client.dll");
	SCHEMA(GameTime_t, m_fNewestAlphaThinkTime, "m_fNewestAlphaThinkTime", "C_Hostage", "client.dll");
};

// Class: C_Inferno (Size: 0x84C0)
class C_Inferno : public C_BaseModelEntity {
public:
	SCHEMA(ParticleIndex_t, m_nfxFireDamageEffect, "m_nfxFireDamageEffect", "C_Inferno", "client.dll");
	SCHEMA(Vector*, m_firePositions, "m_firePositions", "C_Inferno", "client.dll");
	SCHEMA(Vector*, m_fireParentPositions, "m_fireParentPositions", "C_Inferno", "client.dll");
	SCHEMA(bool*, m_bFireIsBurning, "m_bFireIsBurning", "C_Inferno", "client.dll");
	SCHEMA(Vector*, m_BurnNormal, "m_BurnNormal", "C_Inferno", "client.dll");
	SCHEMA(int32, m_fireCount, "m_fireCount", "C_Inferno", "client.dll");
	SCHEMA(int32, m_nInfernoType, "m_nInfernoType", "C_Inferno", "client.dll");
	SCHEMA(float32, m_nFireLifetime, "m_nFireLifetime", "C_Inferno", "client.dll");
	SCHEMA(bool, m_bInPostEffectTime, "m_bInPostEffectTime", "C_Inferno", "client.dll");
	SCHEMA(int32, m_lastFireCount, "m_lastFireCount", "C_Inferno", "client.dll");
	SCHEMA(int32, m_nFireEffectTickBegin, "m_nFireEffectTickBegin", "C_Inferno", "client.dll");
	SCHEMA(int32, m_drawableCount, "m_drawableCount", "C_Inferno", "client.dll");
	SCHEMA(bool, m_blosCheck, "m_blosCheck", "C_Inferno", "client.dll");
	SCHEMA(int32, m_nlosperiod, "m_nlosperiod", "C_Inferno", "client.dll");
	SCHEMA(float32, m_maxFireHalfWidth, "m_maxFireHalfWidth", "C_Inferno", "client.dll");
	SCHEMA(float32, m_maxFireHeight, "m_maxFireHeight", "C_Inferno", "client.dll");
	SCHEMA(Vector, m_minBounds, "m_minBounds", "C_Inferno", "client.dll");
	SCHEMA(Vector, m_maxBounds, "m_maxBounds", "C_Inferno", "client.dll");
	SCHEMA(float32, m_flLastGrassBurnThink, "m_flLastGrassBurnThink", "C_Inferno", "client.dll");
};

// Class: C_InfoVisibilityBox (Size: 0x610)
class C_InfoVisibilityBox : public C_BaseEntity {
public:
	SCHEMA(int32, m_nMode, "m_nMode", "C_InfoVisibilityBox", "client.dll");
	SCHEMA(Vector, m_vBoxSize, "m_vBoxSize", "C_InfoVisibilityBox", "client.dll");
	SCHEMA(bool, m_bEnabled, "m_bEnabled", "C_InfoVisibilityBox", "client.dll");
};

// Class: C_Item (Size: 0x19E0)
class C_Item : public C_EconEntity {
public:
	SCHEMA(char*, m_pReticleHintTextName, "m_pReticleHintTextName", "C_Item", "client.dll");
};

// Class: C_ItemDogtags (Size: 0x19E8)
class C_ItemDogtags : public C_Item {
public:
	SCHEMA(CHandle, m_OwningPlayer, "m_OwningPlayer", "C_ItemDogtags", "client.dll");
	SCHEMA(CHandle, m_KillingPlayer, "m_KillingPlayer", "C_ItemDogtags", "client.dll");
};

// Class: C_KeychainModule (Size: 0x1168)
class C_KeychainModule : public C_CS2WeaponModuleBase {
public:
	SCHEMA(uint32, m_nKeychainDefID, "m_nKeychainDefID", "C_KeychainModule", "client.dll");
	SCHEMA(uint32, m_nKeychainSeed, "m_nKeychainSeed", "C_KeychainModule", "client.dll");
};

// Class: C_Knife (Size: 0x1F90)
class C_Knife : public C_CSWeaponBase {
public:
	SCHEMA(bool, m_bFirstAttack, "m_bFirstAttack", "C_Knife", "client.dll");
};

// Class: C_LightEntity (Size: 0xEB8)
class C_LightEntity : public C_BaseModelEntity {
public:
	SCHEMA(CLightComponent*, m_CLightComponent, "m_CLightComponent", "C_LightEntity", "client.dll");
};

// Class: C_LocalTempEntity (Size: 0x1200)
class C_LocalTempEntity : public CBaseAnimGraph {
public:
	SCHEMA(int32, flags, "flags", "C_LocalTempEntity", "client.dll");
	SCHEMA(GameTime_t, die, "die", "C_LocalTempEntity", "client.dll");
	SCHEMA(float32, m_flFrameMax, "m_flFrameMax", "C_LocalTempEntity", "client.dll");
	SCHEMA(float32, x, "x", "C_LocalTempEntity", "client.dll");
	SCHEMA(float32, y, "y", "C_LocalTempEntity", "client.dll");
	SCHEMA(float32, fadeSpeed, "fadeSpeed", "C_LocalTempEntity", "client.dll");
	SCHEMA(float32, bounceFactor, "bounceFactor", "C_LocalTempEntity", "client.dll");
	SCHEMA(int32, hitSound, "hitSound", "C_LocalTempEntity", "client.dll");
	SCHEMA(int32, priority, "priority", "C_LocalTempEntity", "client.dll");
	SCHEMA(Vector, tentOffset, "tentOffset", "C_LocalTempEntity", "client.dll");
	SCHEMA(QAngle, m_vecTempEntAngVelocity, "m_vecTempEntAngVelocity", "C_LocalTempEntity", "client.dll");
	SCHEMA(int32, tempent_renderamt, "tempent_renderamt", "C_LocalTempEntity", "client.dll");
	SCHEMA(Vector, m_vecNormal, "m_vecNormal", "C_LocalTempEntity", "client.dll");
	SCHEMA(float32, m_flSpriteScale, "m_flSpriteScale", "C_LocalTempEntity", "client.dll");
	SCHEMA(int32, m_nFlickerFrame, "m_nFlickerFrame", "C_LocalTempEntity", "client.dll");
	SCHEMA(float32, m_flFrameRate, "m_flFrameRate", "C_LocalTempEntity", "client.dll");
	SCHEMA(float32, m_flFrame, "m_flFrame", "C_LocalTempEntity", "client.dll");
	SCHEMA(char*, m_pszImpactEffect, "m_pszImpactEffect", "C_LocalTempEntity", "client.dll");
	SCHEMA(char*, m_pszParticleEffect, "m_pszParticleEffect", "C_LocalTempEntity", "client.dll");
	SCHEMA(bool, m_bParticleCollision, "m_bParticleCollision", "C_LocalTempEntity", "client.dll");
	SCHEMA(int32, m_iLastCollisionFrame, "m_iLastCollisionFrame", "C_LocalTempEntity", "client.dll");
	SCHEMA(Vector, m_vLastCollisionOrigin, "m_vLastCollisionOrigin", "C_LocalTempEntity", "client.dll");
	SCHEMA(Vector, m_vecTempEntVelocity, "m_vecTempEntVelocity", "C_LocalTempEntity", "client.dll");
	SCHEMA(Vector, m_vecPrevAbsOrigin, "m_vecPrevAbsOrigin", "C_LocalTempEntity", "client.dll");
	SCHEMA(Vector, m_vecTempEntAcceleration, "m_vecTempEntAcceleration", "C_LocalTempEntity", "client.dll");
};

// Class: C_MapVetoPickController (Size: 0xF40)
class C_MapVetoPickController : public C_BaseEntity {
public:
	SCHEMA(int32, m_nDraftType, "m_nDraftType", "C_MapVetoPickController", "client.dll");
	SCHEMA(int32, m_nTeamWinningCoinToss, "m_nTeamWinningCoinToss", "C_MapVetoPickController", "client.dll");
	SCHEMA(int32*, m_nTeamWithFirstChoice, "m_nTeamWithFirstChoice", "C_MapVetoPickController", "client.dll");
	SCHEMA(int32*, m_nVoteMapIdsList, "m_nVoteMapIdsList", "C_MapVetoPickController", "client.dll");
	SCHEMA(int32*, m_nAccountIDs, "m_nAccountIDs", "C_MapVetoPickController", "client.dll");
	SCHEMA(int32*, m_nMapId0, "m_nMapId0", "C_MapVetoPickController", "client.dll");
	SCHEMA(int32*, m_nMapId1, "m_nMapId1", "C_MapVetoPickController", "client.dll");
	SCHEMA(int32*, m_nMapId2, "m_nMapId2", "C_MapVetoPickController", "client.dll");
	SCHEMA(int32*, m_nMapId3, "m_nMapId3", "C_MapVetoPickController", "client.dll");
	SCHEMA(int32*, m_nMapId4, "m_nMapId4", "C_MapVetoPickController", "client.dll");
	SCHEMA(int32*, m_nMapId5, "m_nMapId5", "C_MapVetoPickController", "client.dll");
	SCHEMA(int32*, m_nStartingSide0, "m_nStartingSide0", "C_MapVetoPickController", "client.dll");
	SCHEMA(int32, m_nCurrentPhase, "m_nCurrentPhase", "C_MapVetoPickController", "client.dll");
	SCHEMA(int32, m_nPhaseStartTick, "m_nPhaseStartTick", "C_MapVetoPickController", "client.dll");
	SCHEMA(int32, m_nPhaseDurationTicks, "m_nPhaseDurationTicks", "C_MapVetoPickController", "client.dll");
	SCHEMA(int32, m_nPostDataUpdateTick, "m_nPostDataUpdateTick", "C_MapVetoPickController", "client.dll");
	SCHEMA(bool, m_bDisabledHud, "m_bDisabledHud", "C_MapVetoPickController", "client.dll");
};

// Class: C_MolotovProjectile (Size: 0x1478)
class C_MolotovProjectile : public C_BaseCSGrenadeProjectile {
public:
	SCHEMA(bool, m_bIsIncGrenade, "m_bIsIncGrenade", "C_MolotovProjectile", "client.dll");
};

// Class: C_Multimeter (Size: 0x1168)
class C_Multimeter : public CBaseAnimGraph {
public:
	SCHEMA(CHandle, m_hTargetC4, "m_hTargetC4", "C_Multimeter", "client.dll");
};

// Class: C_NametagModule (Size: 0x1168)
class C_NametagModule : public C_CS2WeaponModuleBase {
public:
	SCHEMA(CUtlString, m_strNametagString, "m_strNametagString", "C_NametagModule", "client.dll");
};

// Class: C_OmniLight (Size: 0x1210)
class C_OmniLight : public C_BarnLight {
public:
	SCHEMA(float32, m_flInnerAngle, "m_flInnerAngle", "C_OmniLight", "client.dll");
	SCHEMA(float32, m_flOuterAngle, "m_flOuterAngle", "C_OmniLight", "client.dll");
	SCHEMA(bool, m_bShowLight, "m_bShowLight", "C_OmniLight", "client.dll");
};

// Class: C_ParticleSystem (Size: 0x1460)
class C_ParticleSystem : public C_BaseModelEntity {
public:
	SCHEMA(char*, m_szSnapshotFileName, "m_szSnapshotFileName", "C_ParticleSystem", "client.dll");
	SCHEMA(bool, m_bActive, "m_bActive", "C_ParticleSystem", "client.dll");
	SCHEMA(bool, m_bFrozen, "m_bFrozen", "C_ParticleSystem", "client.dll");
	SCHEMA(float32, m_flFreezeTransitionDuration, "m_flFreezeTransitionDuration", "C_ParticleSystem", "client.dll");
	SCHEMA(int32, m_nStopType, "m_nStopType", "C_ParticleSystem", "client.dll");
	SCHEMA(bool, m_bAnimateDuringGameplayPause, "m_bAnimateDuringGameplayPause", "C_ParticleSystem", "client.dll");
	SCHEMA(GameTime_t, m_flStartTime, "m_flStartTime", "C_ParticleSystem", "client.dll");
	SCHEMA(float32, m_flPreSimTime, "m_flPreSimTime", "C_ParticleSystem", "client.dll");
	SCHEMA(Vector*, m_vServerControlPoints, "m_vServerControlPoints", "C_ParticleSystem", "client.dll");
	SCHEMA(uint8*, m_iServerControlPointAssignments, "m_iServerControlPointAssignments", "C_ParticleSystem", "client.dll");
	SCHEMA(CHandle*, m_hControlPointEnts, "m_hControlPointEnts", "C_ParticleSystem", "client.dll");
	SCHEMA(bool, m_bNoSave, "m_bNoSave", "C_ParticleSystem", "client.dll");
	SCHEMA(bool, m_bNoFreeze, "m_bNoFreeze", "C_ParticleSystem", "client.dll");
	SCHEMA(bool, m_bNoRamp, "m_bNoRamp", "C_ParticleSystem", "client.dll");
	SCHEMA(bool, m_bStartActive, "m_bStartActive", "C_ParticleSystem", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_iszEffectName, "m_iszEffectName", "C_ParticleSystem", "client.dll");
	SCHEMA(CUtlSymbolLarge*, m_iszControlPointNames, "m_iszControlPointNames", "C_ParticleSystem", "client.dll");
	SCHEMA(int32, m_nDataCP, "m_nDataCP", "C_ParticleSystem", "client.dll");
	SCHEMA(Vector, m_vecDataCPValue, "m_vecDataCPValue", "C_ParticleSystem", "client.dll");
	SCHEMA(int32, m_nTintCP, "m_nTintCP", "C_ParticleSystem", "client.dll");
	SCHEMA(Color, m_clrTint, "m_clrTint", "C_ParticleSystem", "client.dll");
	SCHEMA(bool, m_bOldActive, "m_bOldActive", "C_ParticleSystem", "client.dll");
	SCHEMA(bool, m_bOldFrozen, "m_bOldFrozen", "C_ParticleSystem", "client.dll");
};

// Class: C_EnvParticleGlow (Size: 0x1478)
class C_EnvParticleGlow : public C_ParticleSystem {
public:
	SCHEMA(float32, m_flAlphaScale, "m_flAlphaScale", "C_EnvParticleGlow", "client.dll");
	SCHEMA(float32, m_flRadiusScale, "m_flRadiusScale", "C_EnvParticleGlow", "client.dll");
	SCHEMA(float32, m_flSelfIllumScale, "m_flSelfIllumScale", "C_EnvParticleGlow", "client.dll");
	SCHEMA(Color, m_ColorTint, "m_ColorTint", "C_EnvParticleGlow", "client.dll");
};

// Class: C_PathParticleRope (Size: 0x708)
class C_PathParticleRope : public C_BaseEntity {
public:
	SCHEMA(bool, m_bStartActive, "m_bStartActive", "C_PathParticleRope", "client.dll");
	SCHEMA(float32, m_flMaxSimulationTime, "m_flMaxSimulationTime", "C_PathParticleRope", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_iszEffectName, "m_iszEffectName", "C_PathParticleRope", "client.dll");
	SCHEMA(CUtlVector< CUtlSymbolLarge >, m_PathNodes_Name, "m_PathNodes_Name", "C_PathParticleRope", "client.dll");
	SCHEMA(float32, m_flParticleSpacing, "m_flParticleSpacing", "C_PathParticleRope", "client.dll");
	SCHEMA(float32, m_flSlack, "m_flSlack", "C_PathParticleRope", "client.dll");
	SCHEMA(float32, m_flRadius, "m_flRadius", "C_PathParticleRope", "client.dll");
	SCHEMA(Color, m_ColorTint, "m_ColorTint", "C_PathParticleRope", "client.dll");
	SCHEMA(int32, m_nEffectState, "m_nEffectState", "C_PathParticleRope", "client.dll");
	SCHEMA(CUtlVector< Vector >, m_PathNodes_Position, "m_PathNodes_Position", "C_PathParticleRope", "client.dll");
	SCHEMA(CUtlVector< Vector >, m_PathNodes_TangentIn, "m_PathNodes_TangentIn", "C_PathParticleRope", "client.dll");
	SCHEMA(CUtlVector< Vector >, m_PathNodes_TangentOut, "m_PathNodes_TangentOut", "C_PathParticleRope", "client.dll");
	SCHEMA(CUtlVector< Vector >, m_PathNodes_Color, "m_PathNodes_Color", "C_PathParticleRope", "client.dll");
	SCHEMA(CUtlVector< bool >, m_PathNodes_PinEnabled, "m_PathNodes_PinEnabled", "C_PathParticleRope", "client.dll");
	SCHEMA(CUtlVector< float32 >, m_PathNodes_RadiusScale, "m_PathNodes_RadiusScale", "C_PathParticleRope", "client.dll");
};

// Class: C_PhysMagnet (Size: 0x1188)
class C_PhysMagnet : public CBaseAnimGraph {
public:
	SCHEMA(CUtlVector< int32 >, m_aAttachedObjectsFromServer, "m_aAttachedObjectsFromServer", "C_PhysMagnet", "client.dll");
	SCHEMA(CUtlVector< CHandle >, m_aAttachedObjects, "m_aAttachedObjects", "C_PhysMagnet", "client.dll");
};

// Class: C_PhysPropClientside (Size: 0x1330)
class C_PhysPropClientside : public C_BreakableProp {
public:
	SCHEMA(GameTime_t, m_flTouchDelta, "m_flTouchDelta", "C_PhysPropClientside", "client.dll");
	SCHEMA(GameTime_t, m_fDeathTime, "m_fDeathTime", "C_PhysPropClientside", "client.dll");
	SCHEMA(Vector, m_vecDamagePosition, "m_vecDamagePosition", "C_PhysPropClientside", "client.dll");
	SCHEMA(Vector, m_vecDamageDirection, "m_vecDamageDirection", "C_PhysPropClientside", "client.dll");
	SCHEMA(DamageTypes_t, m_nDamageType, "m_nDamageType", "C_PhysPropClientside", "client.dll");
};

// Class: C_PhysicsProp (Size: 0x1310)
class C_PhysicsProp : public C_BreakableProp {
public:
	SCHEMA(bool, m_bAwake, "m_bAwake", "C_PhysicsProp", "client.dll");
};

// Class: C_PlantedC4 (Size: 0x16D8)
class C_PlantedC4 : public CBaseAnimGraph {
public:
	SCHEMA(bool, m_bBombTicking, "m_bBombTicking", "C_PlantedC4", "client.dll");
	SCHEMA(int32, m_nBombSite, "m_nBombSite", "C_PlantedC4", "client.dll");
	SCHEMA(int32, m_nSourceSoundscapeHash, "m_nSourceSoundscapeHash", "C_PlantedC4", "client.dll");
	SCHEMA(EntitySpottedState_t, m_entitySpottedState, "m_entitySpottedState", "C_PlantedC4", "client.dll");
	SCHEMA(GameTime_t, m_flNextGlow, "m_flNextGlow", "C_PlantedC4", "client.dll");
	SCHEMA(GameTime_t, m_flNextBeep, "m_flNextBeep", "C_PlantedC4", "client.dll");
	SCHEMA(GameTime_t, m_flC4Blow, "m_flC4Blow", "C_PlantedC4", "client.dll");
	SCHEMA(bool, m_bCannotBeDefused, "m_bCannotBeDefused", "C_PlantedC4", "client.dll");
	SCHEMA(bool, m_bHasExploded, "m_bHasExploded", "C_PlantedC4", "client.dll");
	SCHEMA(float32, m_flTimerLength, "m_flTimerLength", "C_PlantedC4", "client.dll");
	SCHEMA(bool, m_bBeingDefused, "m_bBeingDefused", "C_PlantedC4", "client.dll");
	SCHEMA(float32, m_bTriggerWarning, "m_bTriggerWarning", "C_PlantedC4", "client.dll");
	SCHEMA(float32, m_bExplodeWarning, "m_bExplodeWarning", "C_PlantedC4", "client.dll");
	SCHEMA(bool, m_bC4Activated, "m_bC4Activated", "C_PlantedC4", "client.dll");
	SCHEMA(bool, m_bTenSecWarning, "m_bTenSecWarning", "C_PlantedC4", "client.dll");
	SCHEMA(float32, m_flDefuseLength, "m_flDefuseLength", "C_PlantedC4", "client.dll");
	SCHEMA(GameTime_t, m_flDefuseCountDown, "m_flDefuseCountDown", "C_PlantedC4", "client.dll");
	SCHEMA(bool, m_bBombDefused, "m_bBombDefused", "C_PlantedC4", "client.dll");
	SCHEMA(CHandle, m_hBombDefuser, "m_hBombDefuser", "C_PlantedC4", "client.dll");
	SCHEMA(C_AttributeContainer, m_AttributeManager, "m_AttributeManager", "C_PlantedC4", "client.dll");
	SCHEMA(CHandle, m_hDefuserMultimeter, "m_hDefuserMultimeter", "C_PlantedC4", "client.dll");
	SCHEMA(GameTime_t, m_flNextRadarFlashTime, "m_flNextRadarFlashTime", "C_PlantedC4", "client.dll");
	SCHEMA(bool, m_bRadarFlash, "m_bRadarFlash", "C_PlantedC4", "client.dll");
	SCHEMA(CHandle, m_pBombDefuser, "m_pBombDefuser", "C_PlantedC4", "client.dll");
	SCHEMA(GameTime_t, m_fLastDefuseTime, "m_fLastDefuseTime", "C_PlantedC4", "client.dll");
	SCHEMA(CBasePlayerController*, m_pPredictionOwner, "m_pPredictionOwner", "C_PlantedC4", "client.dll");
	SCHEMA(Vector, m_vecC4ExplodeSpectatePos, "m_vecC4ExplodeSpectatePos", "C_PlantedC4", "client.dll");
	SCHEMA(QAngle, m_vecC4ExplodeSpectateAng, "m_vecC4ExplodeSpectateAng", "C_PlantedC4", "client.dll");
	SCHEMA(float32, m_flC4ExplodeSpectateDuration, "m_flC4ExplodeSpectateDuration", "C_PlantedC4", "client.dll");
};

// Class: C_PlayerPing (Size: 0x648)
class C_PlayerPing : public C_BaseEntity {
public:
	SCHEMA(CHandle, m_hPlayer, "m_hPlayer", "C_PlayerPing", "client.dll");
	SCHEMA(CHandle, m_hPingedEntity, "m_hPingedEntity", "C_PlayerPing", "client.dll");
	SCHEMA(int32, m_iType, "m_iType", "C_PlayerPing", "client.dll");
	SCHEMA(bool, m_bUrgent, "m_bUrgent", "C_PlayerPing", "client.dll");
	SCHEMA(char*, m_szPlaceName, "m_szPlaceName", "C_PlayerPing", "client.dll");
};

// Class: C_PlayerSprayDecal (Size: 0xFC0)
class C_PlayerSprayDecal : public C_ModelPointEntity {
public:
	SCHEMA(int32, m_nUniqueID, "m_nUniqueID", "C_PlayerSprayDecal", "client.dll");
	SCHEMA(uint32, m_unAccountID, "m_unAccountID", "C_PlayerSprayDecal", "client.dll");
	SCHEMA(uint32, m_unTraceID, "m_unTraceID", "C_PlayerSprayDecal", "client.dll");
	SCHEMA(uint32, m_rtGcTime, "m_rtGcTime", "C_PlayerSprayDecal", "client.dll");
	SCHEMA(Vector, m_vecEndPos, "m_vecEndPos", "C_PlayerSprayDecal", "client.dll");
	SCHEMA(Vector, m_vecStart, "m_vecStart", "C_PlayerSprayDecal", "client.dll");
	SCHEMA(Vector, m_vecLeft, "m_vecLeft", "C_PlayerSprayDecal", "client.dll");
	SCHEMA(Vector, m_vecNormal, "m_vecNormal", "C_PlayerSprayDecal", "client.dll");
	SCHEMA(int32, m_nPlayer, "m_nPlayer", "C_PlayerSprayDecal", "client.dll");
	SCHEMA(int32, m_nEntity, "m_nEntity", "C_PlayerSprayDecal", "client.dll");
	SCHEMA(int32, m_nHitbox, "m_nHitbox", "C_PlayerSprayDecal", "client.dll");
	SCHEMA(float32, m_flCreationTime, "m_flCreationTime", "C_PlayerSprayDecal", "client.dll");
	SCHEMA(int32, m_nTintID, "m_nTintID", "C_PlayerSprayDecal", "client.dll");
	SCHEMA(uint8, m_nVersion, "m_nVersion", "C_PlayerSprayDecal", "client.dll");
	SCHEMA(uint8*, m_ubSignature, "m_ubSignature", "C_PlayerSprayDecal", "client.dll");
	SCHEMA(CPlayerSprayDecalRenderHelper, m_SprayRenderHelper, "m_SprayRenderHelper", "C_PlayerSprayDecal", "client.dll");
};

// Class: C_PlayerVisibility (Size: 0x628)
class C_PlayerVisibility : public C_BaseEntity {
public:
	SCHEMA(float32, m_flVisibilityStrength, "m_flVisibilityStrength", "C_PlayerVisibility", "client.dll");
	SCHEMA(float32, m_flFogDistanceMultiplier, "m_flFogDistanceMultiplier", "C_PlayerVisibility", "client.dll");
	SCHEMA(float32, m_flFogMaxDensityMultiplier, "m_flFogMaxDensityMultiplier", "C_PlayerVisibility", "client.dll");
	SCHEMA(float32, m_flFadeTime, "m_flFadeTime", "C_PlayerVisibility", "client.dll");
	SCHEMA(bool, m_bStartDisabled, "m_bStartDisabled", "C_PlayerVisibility", "client.dll");
	SCHEMA(bool, m_bIsEnabled, "m_bIsEnabled", "C_PlayerVisibility", "client.dll");
};

// Class: C_PointCamera (Size: 0x658)
class C_PointCamera : public C_BaseEntity {
public:
	SCHEMA(float32, m_FOV, "m_FOV", "C_PointCamera", "client.dll");
	SCHEMA(float32, m_Resolution, "m_Resolution", "C_PointCamera", "client.dll");
	SCHEMA(bool, m_bFogEnable, "m_bFogEnable", "C_PointCamera", "client.dll");
	SCHEMA(Color, m_FogColor, "m_FogColor", "C_PointCamera", "client.dll");
	SCHEMA(float32, m_flFogStart, "m_flFogStart", "C_PointCamera", "client.dll");
	SCHEMA(float32, m_flFogEnd, "m_flFogEnd", "C_PointCamera", "client.dll");
	SCHEMA(float32, m_flFogMaxDensity, "m_flFogMaxDensity", "C_PointCamera", "client.dll");
	SCHEMA(bool, m_bActive, "m_bActive", "C_PointCamera", "client.dll");
	SCHEMA(bool, m_bUseScreenAspectRatio, "m_bUseScreenAspectRatio", "C_PointCamera", "client.dll");
	SCHEMA(float32, m_flAspectRatio, "m_flAspectRatio", "C_PointCamera", "client.dll");
	SCHEMA(bool, m_bNoSky, "m_bNoSky", "C_PointCamera", "client.dll");
	SCHEMA(float32, m_fBrightness, "m_fBrightness", "C_PointCamera", "client.dll");
	SCHEMA(float32, m_flZFar, "m_flZFar", "C_PointCamera", "client.dll");
	SCHEMA(float32, m_flZNear, "m_flZNear", "C_PointCamera", "client.dll");
	SCHEMA(bool, m_bCanHLTVUse, "m_bCanHLTVUse", "C_PointCamera", "client.dll");
	SCHEMA(bool, m_bAlignWithParent, "m_bAlignWithParent", "C_PointCamera", "client.dll");
	SCHEMA(bool, m_bDofEnabled, "m_bDofEnabled", "C_PointCamera", "client.dll");
	SCHEMA(float32, m_flDofNearBlurry, "m_flDofNearBlurry", "C_PointCamera", "client.dll");
	SCHEMA(float32, m_flDofNearCrisp, "m_flDofNearCrisp", "C_PointCamera", "client.dll");
	SCHEMA(float32, m_flDofFarCrisp, "m_flDofFarCrisp", "C_PointCamera", "client.dll");
	SCHEMA(float32, m_flDofFarBlurry, "m_flDofFarBlurry", "C_PointCamera", "client.dll");
	SCHEMA(float32, m_flDofTiltToGround, "m_flDofTiltToGround", "C_PointCamera", "client.dll");
	SCHEMA(float32, m_TargetFOV, "m_TargetFOV", "C_PointCamera", "client.dll");
	SCHEMA(float32, m_DegreesPerSecond, "m_DegreesPerSecond", "C_PointCamera", "client.dll");
	SCHEMA(bool, m_bIsOn, "m_bIsOn", "C_PointCamera", "client.dll");
	SCHEMA(C_PointCamera*, m_pNext, "m_pNext", "C_PointCamera", "client.dll");
};

// Class: C_PointCameraVFOV (Size: 0x660)
class C_PointCameraVFOV : public C_PointCamera {
public:
	SCHEMA(float32, m_flVerticalFOV, "m_flVerticalFOV", "C_PointCameraVFOV", "client.dll");
};

// Class: C_PointClientUIDialog (Size: 0xEE8)
class C_PointClientUIDialog : public C_BaseClientUIEntity {
public:
	SCHEMA(CHandle, m_hActivator, "m_hActivator", "C_PointClientUIDialog", "client.dll");
	SCHEMA(bool, m_bStartEnabled, "m_bStartEnabled", "C_PointClientUIDialog", "client.dll");
};

// Class: C_PointClientUIHUD (Size: 0x10A8)
class C_PointClientUIHUD : public C_BaseClientUIEntity {
public:
	SCHEMA(bool, m_bCheckCSSClasses, "m_bCheckCSSClasses", "C_PointClientUIHUD", "client.dll");
	SCHEMA(bool, m_bIgnoreInput, "m_bIgnoreInput", "C_PointClientUIHUD", "client.dll");
	SCHEMA(float32, m_flWidth, "m_flWidth", "C_PointClientUIHUD", "client.dll");
	SCHEMA(float32, m_flHeight, "m_flHeight", "C_PointClientUIHUD", "client.dll");
	SCHEMA(float32, m_flDPI, "m_flDPI", "C_PointClientUIHUD", "client.dll");
	SCHEMA(float32, m_flInteractDistance, "m_flInteractDistance", "C_PointClientUIHUD", "client.dll");
	SCHEMA(float32, m_flDepthOffset, "m_flDepthOffset", "C_PointClientUIHUD", "client.dll");
	SCHEMA(uint32, m_unOwnerContext, "m_unOwnerContext", "C_PointClientUIHUD", "client.dll");
	SCHEMA(uint32, m_unHorizontalAlign, "m_unHorizontalAlign", "C_PointClientUIHUD", "client.dll");
	SCHEMA(uint32, m_unVerticalAlign, "m_unVerticalAlign", "C_PointClientUIHUD", "client.dll");
	SCHEMA(uint32, m_unOrientation, "m_unOrientation", "C_PointClientUIHUD", "client.dll");
	SCHEMA(bool, m_bAllowInteractionFromAllSceneWorlds, "m_bAllowInteractionFromAllSceneWorlds", "C_PointClientUIHUD", "client.dll");
	SCHEMA(CUtlVector< CUtlSymbolLarge >, m_vecCSSClasses, "m_vecCSSClasses", "C_PointClientUIHUD", "client.dll");
};

// Class: C_PointClientUIWorldPanel (Size: 0x1100)
class C_PointClientUIWorldPanel : public C_BaseClientUIEntity {
public:
	SCHEMA(bool, m_bForceRecreateNextUpdate, "m_bForceRecreateNextUpdate", "C_PointClientUIWorldPanel", "client.dll");
	SCHEMA(bool, m_bMoveViewToPlayerNextThink, "m_bMoveViewToPlayerNextThink", "C_PointClientUIWorldPanel", "client.dll");
	SCHEMA(bool, m_bCheckCSSClasses, "m_bCheckCSSClasses", "C_PointClientUIWorldPanel", "client.dll");
	SCHEMA(CTransform, m_anchorDeltaTransform, "m_anchorDeltaTransform", "C_PointClientUIWorldPanel", "client.dll");
	SCHEMA(CPointOffScreenIndicatorUi*, m_pOffScreenIndicator, "m_pOffScreenIndicator", "C_PointClientUIWorldPanel", "client.dll");
	SCHEMA(bool, m_bIgnoreInput, "m_bIgnoreInput", "C_PointClientUIWorldPanel", "client.dll");
	SCHEMA(bool, m_bLit, "m_bLit", "C_PointClientUIWorldPanel", "client.dll");
	SCHEMA(bool, m_bFollowPlayerAcrossTeleport, "m_bFollowPlayerAcrossTeleport", "C_PointClientUIWorldPanel", "client.dll");
	SCHEMA(float32, m_flWidth, "m_flWidth", "C_PointClientUIWorldPanel", "client.dll");
	SCHEMA(float32, m_flHeight, "m_flHeight", "C_PointClientUIWorldPanel", "client.dll");
	SCHEMA(float32, m_flDPI, "m_flDPI", "C_PointClientUIWorldPanel", "client.dll");
	SCHEMA(float32, m_flInteractDistance, "m_flInteractDistance", "C_PointClientUIWorldPanel", "client.dll");
	SCHEMA(float32, m_flDepthOffset, "m_flDepthOffset", "C_PointClientUIWorldPanel", "client.dll");
	SCHEMA(uint32, m_unOwnerContext, "m_unOwnerContext", "C_PointClientUIWorldPanel", "client.dll");
	SCHEMA(uint32, m_unHorizontalAlign, "m_unHorizontalAlign", "C_PointClientUIWorldPanel", "client.dll");
	SCHEMA(uint32, m_unVerticalAlign, "m_unVerticalAlign", "C_PointClientUIWorldPanel", "client.dll");
	SCHEMA(uint32, m_unOrientation, "m_unOrientation", "C_PointClientUIWorldPanel", "client.dll");
	SCHEMA(bool, m_bAllowInteractionFromAllSceneWorlds, "m_bAllowInteractionFromAllSceneWorlds", "C_PointClientUIWorldPanel", "client.dll");
	SCHEMA(CUtlVector< CUtlSymbolLarge >, m_vecCSSClasses, "m_vecCSSClasses", "C_PointClientUIWorldPanel", "client.dll");
	SCHEMA(bool, m_bOpaque, "m_bOpaque", "C_PointClientUIWorldPanel", "client.dll");
	SCHEMA(bool, m_bNoDepth, "m_bNoDepth", "C_PointClientUIWorldPanel", "client.dll");
	SCHEMA(bool, m_bVisibleWhenParentNoDraw, "m_bVisibleWhenParentNoDraw", "C_PointClientUIWorldPanel", "client.dll");
	SCHEMA(bool, m_bRenderBackface, "m_bRenderBackface", "C_PointClientUIWorldPanel", "client.dll");
	SCHEMA(bool, m_bUseOffScreenIndicator, "m_bUseOffScreenIndicator", "C_PointClientUIWorldPanel", "client.dll");
	SCHEMA(bool, m_bExcludeFromSaveGames, "m_bExcludeFromSaveGames", "C_PointClientUIWorldPanel", "client.dll");
	SCHEMA(bool, m_bGrabbable, "m_bGrabbable", "C_PointClientUIWorldPanel", "client.dll");
	SCHEMA(bool, m_bOnlyRenderToTexture, "m_bOnlyRenderToTexture", "C_PointClientUIWorldPanel", "client.dll");
	SCHEMA(bool, m_bDisableMipGen, "m_bDisableMipGen", "C_PointClientUIWorldPanel", "client.dll");
	SCHEMA(int32, m_nExplicitImageLayout, "m_nExplicitImageLayout", "C_PointClientUIWorldPanel", "client.dll");
};

// Class: CPointOffScreenIndicatorUi (Size: 0x1110)
class CPointOffScreenIndicatorUi : public C_PointClientUIWorldPanel {
public:
	SCHEMA(bool, m_bBeenEnabled, "m_bBeenEnabled", "CPointOffScreenIndicatorUi", "client.dll");
	SCHEMA(bool, m_bHide, "m_bHide", "CPointOffScreenIndicatorUi", "client.dll");
	SCHEMA(float32, m_flSeenTargetTime, "m_flSeenTargetTime", "CPointOffScreenIndicatorUi", "client.dll");
	SCHEMA(C_PointClientUIWorldPanel*, m_pTargetPanel, "m_pTargetPanel", "CPointOffScreenIndicatorUi", "client.dll");
};

// Class: C_PointClientUIWorldTextPanel (Size: 0x1300)
class C_PointClientUIWorldTextPanel : public C_PointClientUIWorldPanel {
public:
	SCHEMA(char*, m_messageText, "m_messageText", "C_PointClientUIWorldTextPanel", "client.dll");
};

// Class: C_PointCommentaryNode (Size: 0x11B8)
class C_PointCommentaryNode : public CBaseAnimGraph {
public:
	SCHEMA(bool, m_bActive, "m_bActive", "C_PointCommentaryNode", "client.dll");
	SCHEMA(bool, m_bWasActive, "m_bWasActive", "C_PointCommentaryNode", "client.dll");
	SCHEMA(GameTime_t, m_flEndTime, "m_flEndTime", "C_PointCommentaryNode", "client.dll");
	SCHEMA(GameTime_t, m_flStartTime, "m_flStartTime", "C_PointCommentaryNode", "client.dll");
	SCHEMA(float32, m_flStartTimeInCommentary, "m_flStartTimeInCommentary", "C_PointCommentaryNode", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_iszCommentaryFile, "m_iszCommentaryFile", "C_PointCommentaryNode", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_iszTitle, "m_iszTitle", "C_PointCommentaryNode", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_iszSpeakers, "m_iszSpeakers", "C_PointCommentaryNode", "client.dll");
	SCHEMA(int32, m_iNodeNumber, "m_iNodeNumber", "C_PointCommentaryNode", "client.dll");
	SCHEMA(int32, m_iNodeNumberMax, "m_iNodeNumberMax", "C_PointCommentaryNode", "client.dll");
	SCHEMA(bool, m_bListenedTo, "m_bListenedTo", "C_PointCommentaryNode", "client.dll");
	SCHEMA(CHandle, m_hViewPosition, "m_hViewPosition", "C_PointCommentaryNode", "client.dll");
	SCHEMA(bool, m_bRestartAfterRestore, "m_bRestartAfterRestore", "C_PointCommentaryNode", "client.dll");
};

// Class: C_PointValueRemapper (Size: 0x670)
class C_PointValueRemapper : public C_BaseEntity {
public:
	SCHEMA(bool, m_bDisabled, "m_bDisabled", "C_PointValueRemapper", "client.dll");
	SCHEMA(bool, m_bDisabledOld, "m_bDisabledOld", "C_PointValueRemapper", "client.dll");
	SCHEMA(bool, m_bUpdateOnClient, "m_bUpdateOnClient", "C_PointValueRemapper", "client.dll");
	SCHEMA(ValueRemapperInputType_t, m_nInputType, "m_nInputType", "C_PointValueRemapper", "client.dll");
	SCHEMA(CHandle, m_hRemapLineStart, "m_hRemapLineStart", "C_PointValueRemapper", "client.dll");
	SCHEMA(CHandle, m_hRemapLineEnd, "m_hRemapLineEnd", "C_PointValueRemapper", "client.dll");
	SCHEMA(float32, m_flMaximumChangePerSecond, "m_flMaximumChangePerSecond", "C_PointValueRemapper", "client.dll");
	SCHEMA(float32, m_flDisengageDistance, "m_flDisengageDistance", "C_PointValueRemapper", "client.dll");
	SCHEMA(float32, m_flEngageDistance, "m_flEngageDistance", "C_PointValueRemapper", "client.dll");
	SCHEMA(bool, m_bRequiresUseKey, "m_bRequiresUseKey", "C_PointValueRemapper", "client.dll");
	SCHEMA(ValueRemapperOutputType_t, m_nOutputType, "m_nOutputType", "C_PointValueRemapper", "client.dll");
	SCHEMA(CUtlVector< CHandle >, m_hOutputEntities, "m_hOutputEntities", "C_PointValueRemapper", "client.dll");
	SCHEMA(ValueRemapperHapticsType_t, m_nHapticsType, "m_nHapticsType", "C_PointValueRemapper", "client.dll");
	SCHEMA(ValueRemapperMomentumType_t, m_nMomentumType, "m_nMomentumType", "C_PointValueRemapper", "client.dll");
	SCHEMA(float32, m_flMomentumModifier, "m_flMomentumModifier", "C_PointValueRemapper", "client.dll");
	SCHEMA(float32, m_flSnapValue, "m_flSnapValue", "C_PointValueRemapper", "client.dll");
	SCHEMA(float32, m_flCurrentMomentum, "m_flCurrentMomentum", "C_PointValueRemapper", "client.dll");
	SCHEMA(ValueRemapperRatchetType_t, m_nRatchetType, "m_nRatchetType", "C_PointValueRemapper", "client.dll");
	SCHEMA(float32, m_flRatchetOffset, "m_flRatchetOffset", "C_PointValueRemapper", "client.dll");
	SCHEMA(float32, m_flInputOffset, "m_flInputOffset", "C_PointValueRemapper", "client.dll");
	SCHEMA(bool, m_bEngaged, "m_bEngaged", "C_PointValueRemapper", "client.dll");
	SCHEMA(bool, m_bFirstUpdate, "m_bFirstUpdate", "C_PointValueRemapper", "client.dll");
	SCHEMA(float32, m_flPreviousValue, "m_flPreviousValue", "C_PointValueRemapper", "client.dll");
	SCHEMA(GameTime_t, m_flPreviousUpdateTickTime, "m_flPreviousUpdateTickTime", "C_PointValueRemapper", "client.dll");
	SCHEMA(Vector, m_vecPreviousTestPoint, "m_vecPreviousTestPoint", "C_PointValueRemapper", "client.dll");
};

// Class: C_PointWorldText (Size: 0x1180)
class C_PointWorldText : public C_ModelPointEntity {
public:
	SCHEMA(bool, m_bForceRecreateNextUpdate, "m_bForceRecreateNextUpdate", "C_PointWorldText", "client.dll");
	SCHEMA(char*, m_messageText, "m_messageText", "C_PointWorldText", "client.dll");
	SCHEMA(char*, m_FontName, "m_FontName", "C_PointWorldText", "client.dll");
	SCHEMA(char*, m_BackgroundMaterialName, "m_BackgroundMaterialName", "C_PointWorldText", "client.dll");
	SCHEMA(bool, m_bEnabled, "m_bEnabled", "C_PointWorldText", "client.dll");
	SCHEMA(bool, m_bFullbright, "m_bFullbright", "C_PointWorldText", "client.dll");
	SCHEMA(float32, m_flWorldUnitsPerPx, "m_flWorldUnitsPerPx", "C_PointWorldText", "client.dll");
	SCHEMA(float32, m_flFontSize, "m_flFontSize", "C_PointWorldText", "client.dll");
	SCHEMA(float32, m_flDepthOffset, "m_flDepthOffset", "C_PointWorldText", "client.dll");
	SCHEMA(bool, m_bDrawBackground, "m_bDrawBackground", "C_PointWorldText", "client.dll");
	SCHEMA(float32, m_flBackgroundBorderWidth, "m_flBackgroundBorderWidth", "C_PointWorldText", "client.dll");
	SCHEMA(float32, m_flBackgroundBorderHeight, "m_flBackgroundBorderHeight", "C_PointWorldText", "client.dll");
	SCHEMA(float32, m_flBackgroundWorldToUV, "m_flBackgroundWorldToUV", "C_PointWorldText", "client.dll");
	SCHEMA(Color, m_Color, "m_Color", "C_PointWorldText", "client.dll");
	SCHEMA(PointWorldTextJustifyHorizontal_t, m_nJustifyHorizontal, "m_nJustifyHorizontal", "C_PointWorldText", "client.dll");
	SCHEMA(PointWorldTextJustifyVertical_t, m_nJustifyVertical, "m_nJustifyVertical", "C_PointWorldText", "client.dll");
	SCHEMA(PointWorldTextReorientMode_t, m_nReorientMode, "m_nReorientMode", "C_PointWorldText", "client.dll");
};

// Class: C_PostProcessingVolume (Size: 0x1030)
class C_PostProcessingVolume : public C_BaseTrigger {
public:
	SCHEMA(float32, m_flFadeDuration, "m_flFadeDuration", "C_PostProcessingVolume", "client.dll");
	SCHEMA(float32, m_flMinLogExposure, "m_flMinLogExposure", "C_PostProcessingVolume", "client.dll");
	SCHEMA(float32, m_flMaxLogExposure, "m_flMaxLogExposure", "C_PostProcessingVolume", "client.dll");
	SCHEMA(float32, m_flMinExposure, "m_flMinExposure", "C_PostProcessingVolume", "client.dll");
	SCHEMA(float32, m_flMaxExposure, "m_flMaxExposure", "C_PostProcessingVolume", "client.dll");
	SCHEMA(float32, m_flExposureCompensation, "m_flExposureCompensation", "C_PostProcessingVolume", "client.dll");
	SCHEMA(float32, m_flExposureFadeSpeedUp, "m_flExposureFadeSpeedUp", "C_PostProcessingVolume", "client.dll");
	SCHEMA(float32, m_flExposureFadeSpeedDown, "m_flExposureFadeSpeedDown", "C_PostProcessingVolume", "client.dll");
	SCHEMA(float32, m_flTonemapEVSmoothingRange, "m_flTonemapEVSmoothingRange", "C_PostProcessingVolume", "client.dll");
	SCHEMA(bool, m_bMaster, "m_bMaster", "C_PostProcessingVolume", "client.dll");
	SCHEMA(bool, m_bExposureControl, "m_bExposureControl", "C_PostProcessingVolume", "client.dll");
};

// Class: C_Precipitation (Size: 0x1040)
class C_Precipitation : public C_BaseTrigger {
public:
	SCHEMA(float32, m_flDensity, "m_flDensity", "C_Precipitation", "client.dll");
	SCHEMA(float32, m_flParticleInnerDist, "m_flParticleInnerDist", "C_Precipitation", "client.dll");
	SCHEMA(char*, m_pParticleDef, "m_pParticleDef", "C_Precipitation", "client.dll");
	SCHEMA(bool*, m_bActiveParticlePrecipEmitter, "m_bActiveParticlePrecipEmitter", "C_Precipitation", "client.dll");
	SCHEMA(bool, m_bParticlePrecipInitialized, "m_bParticlePrecipInitialized", "C_Precipitation", "client.dll");
	SCHEMA(bool, m_bHasSimulatedSinceLastSceneObjectUpdate, "m_bHasSimulatedSinceLastSceneObjectUpdate", "C_Precipitation", "client.dll");
	SCHEMA(int32, m_nAvailableSheetSequencesMaxIndex, "m_nAvailableSheetSequencesMaxIndex", "C_Precipitation", "client.dll");
};

// Class: C_RagdollProp (Size: 0x11E8)
class C_RagdollProp : public CBaseAnimGraph {
public:
	SCHEMA(CUtlVector< bool >, m_ragEnabled, "m_ragEnabled", "C_RagdollProp", "client.dll");
	SCHEMA(CUtlVector< Vector >, m_ragPos, "m_ragPos", "C_RagdollProp", "client.dll");
	SCHEMA(CUtlVector< QAngle >, m_ragAngles, "m_ragAngles", "C_RagdollProp", "client.dll");
	SCHEMA(float32, m_flBlendWeight, "m_flBlendWeight", "C_RagdollProp", "client.dll");
	SCHEMA(CHandle, m_hRagdollSource, "m_hRagdollSource", "C_RagdollProp", "client.dll");
	SCHEMA(AttachmentHandle_t, m_iEyeAttachment, "m_iEyeAttachment", "C_RagdollProp", "client.dll");
	SCHEMA(float32, m_flBlendWeightCurrent, "m_flBlendWeightCurrent", "C_RagdollProp", "client.dll");
	SCHEMA(CUtlVector< int32 >, m_parentPhysicsBoneIndices, "m_parentPhysicsBoneIndices", "C_RagdollProp", "client.dll");
	SCHEMA(CUtlVector< int32 >, m_worldSpaceBoneComputationOrder, "m_worldSpaceBoneComputationOrder", "C_RagdollProp", "client.dll");
};

// Class: C_RagdollPropAttached (Size: 0x1220)
class C_RagdollPropAttached : public C_RagdollProp {
public:
	SCHEMA(uint32, m_boneIndexAttached, "m_boneIndexAttached", "C_RagdollPropAttached", "client.dll");
	SCHEMA(uint32, m_ragdollAttachedObjectIndex, "m_ragdollAttachedObjectIndex", "C_RagdollPropAttached", "client.dll");
	SCHEMA(Vector, m_attachmentPointBoneSpace, "m_attachmentPointBoneSpace", "C_RagdollPropAttached", "client.dll");
	SCHEMA(Vector, m_attachmentPointRagdollSpace, "m_attachmentPointRagdollSpace", "C_RagdollPropAttached", "client.dll");
	SCHEMA(Vector, m_vecOffset, "m_vecOffset", "C_RagdollPropAttached", "client.dll");
	SCHEMA(float32, m_parentTime, "m_parentTime", "C_RagdollPropAttached", "client.dll");
	SCHEMA(bool, m_bHasParent, "m_bHasParent", "C_RagdollPropAttached", "client.dll");
};

// Class: C_RectLight (Size: 0x1208)
class C_RectLight : public C_BarnLight {
public:
	SCHEMA(bool, m_bShowLight, "m_bShowLight", "C_RectLight", "client.dll");
};

// Class: C_RetakeGameRules (Size: 0x118)
class C_RetakeGameRules {
public:
	SCHEMA(int32, m_nMatchSeed, "m_nMatchSeed", "C_RetakeGameRules", "client.dll");
	SCHEMA(bool, m_bBlockersPresent, "m_bBlockersPresent", "C_RetakeGameRules", "client.dll");
	SCHEMA(bool, m_bRoundInProgress, "m_bRoundInProgress", "C_RetakeGameRules", "client.dll");
	SCHEMA(int32, m_iFirstSecondHalfRound, "m_iFirstSecondHalfRound", "C_RetakeGameRules", "client.dll");
	SCHEMA(int32, m_iBombSite, "m_iBombSite", "C_RetakeGameRules", "client.dll");
	SCHEMA(CHandle, m_hBombPlanter, "m_hBombPlanter", "C_RetakeGameRules", "client.dll");
};

// Class: C_RopeKeyframe (Size: 0x1220)
class C_RopeKeyframe : public C_BaseModelEntity {
public:
	class CPhysicsDelegate {
		public:
			SCHEMA(C_RopeKeyframe*, m_pKeyframe, "m_pKeyframe", "C_RopeKeyframe::CPhysicsDelegate", "client.dll");
	};

	SCHEMA(uint16_t, m_LinksTouchingSomething, "m_LinksTouchingSomething", "C_RopeKeyframe", "client.dll");
	SCHEMA(int32, m_nLinksTouchingSomething, "m_nLinksTouchingSomething", "C_RopeKeyframe", "client.dll");
	SCHEMA(bool, m_bApplyWind, "m_bApplyWind", "C_RopeKeyframe", "client.dll");
	SCHEMA(int32, m_fPrevLockedPoints, "m_fPrevLockedPoints", "C_RopeKeyframe", "client.dll");
	SCHEMA(int32, m_iForcePointMoveCounter, "m_iForcePointMoveCounter", "C_RopeKeyframe", "client.dll");
	SCHEMA(bool*, m_bPrevEndPointPos, "m_bPrevEndPointPos", "C_RopeKeyframe", "client.dll");
	SCHEMA(Vector*, m_vPrevEndPointPos, "m_vPrevEndPointPos", "C_RopeKeyframe", "client.dll");
	SCHEMA(float32, m_flCurScroll, "m_flCurScroll", "C_RopeKeyframe", "client.dll");
	SCHEMA(float32, m_flScrollSpeed, "m_flScrollSpeed", "C_RopeKeyframe", "client.dll");
	SCHEMA(uint16, m_RopeFlags, "m_RopeFlags", "C_RopeKeyframe", "client.dll");
	SCHEMA(uint8, m_nSegments, "m_nSegments", "C_RopeKeyframe", "client.dll");
	SCHEMA(CHandle, m_hStartPoint, "m_hStartPoint", "C_RopeKeyframe", "client.dll");
	SCHEMA(CHandle, m_hEndPoint, "m_hEndPoint", "C_RopeKeyframe", "client.dll");
	SCHEMA(AttachmentHandle_t, m_iStartAttachment, "m_iStartAttachment", "C_RopeKeyframe", "client.dll");
	SCHEMA(AttachmentHandle_t, m_iEndAttachment, "m_iEndAttachment", "C_RopeKeyframe", "client.dll");
	SCHEMA(uint8, m_Subdiv, "m_Subdiv", "C_RopeKeyframe", "client.dll");
	SCHEMA(int16, m_RopeLength, "m_RopeLength", "C_RopeKeyframe", "client.dll");
	SCHEMA(int16, m_Slack, "m_Slack", "C_RopeKeyframe", "client.dll");
	SCHEMA(float32, m_TextureScale, "m_TextureScale", "C_RopeKeyframe", "client.dll");
	SCHEMA(uint8, m_fLockedPoints, "m_fLockedPoints", "C_RopeKeyframe", "client.dll");
	SCHEMA(uint8, m_nChangeCount, "m_nChangeCount", "C_RopeKeyframe", "client.dll");
	SCHEMA(float32, m_Width, "m_Width", "C_RopeKeyframe", "client.dll");
	SCHEMA(C_RopeKeyframe::CPhysicsDelegate, m_PhysicsDelegate, "m_PhysicsDelegate", "C_RopeKeyframe", "client.dll");
	SCHEMA(int32, m_TextureHeight, "m_TextureHeight", "C_RopeKeyframe", "client.dll");
	SCHEMA(Vector, m_vecImpulse, "m_vecImpulse", "C_RopeKeyframe", "client.dll");
	SCHEMA(Vector, m_vecPreviousImpulse, "m_vecPreviousImpulse", "C_RopeKeyframe", "client.dll");
	SCHEMA(float32, m_flCurrentGustTimer, "m_flCurrentGustTimer", "C_RopeKeyframe", "client.dll");
	SCHEMA(float32, m_flCurrentGustLifetime, "m_flCurrentGustLifetime", "C_RopeKeyframe", "client.dll");
	SCHEMA(float32, m_flTimeToNextGust, "m_flTimeToNextGust", "C_RopeKeyframe", "client.dll");
	SCHEMA(Vector, m_vWindDir, "m_vWindDir", "C_RopeKeyframe", "client.dll");
	SCHEMA(Vector, m_vColorMod, "m_vColorMod", "C_RopeKeyframe", "client.dll");
	SCHEMA(Vector*, m_vCachedEndPointAttachmentPos, "m_vCachedEndPointAttachmentPos", "C_RopeKeyframe", "client.dll");
	SCHEMA(QAngle*, m_vCachedEndPointAttachmentAngle, "m_vCachedEndPointAttachmentAngle", "C_RopeKeyframe", "client.dll");
	SCHEMA(bool, m_bConstrainBetweenEndpoints, "m_bConstrainBetweenEndpoints", "C_RopeKeyframe", "client.dll");
	SCHEMA(bool, m_bEndPointAttachmentPositionsDirty, "m_bEndPointAttachmentPositionsDirty", "C_RopeKeyframe", "client.dll");
	SCHEMA(bool, m_bEndPointAttachmentAnglesDirty, "m_bEndPointAttachmentAnglesDirty", "C_RopeKeyframe", "client.dll");
	SCHEMA(bool, m_bNewDataThisFrame, "m_bNewDataThisFrame", "C_RopeKeyframe", "client.dll");
	SCHEMA(bool, m_bPhysicsInitted, "m_bPhysicsInitted", "C_RopeKeyframe", "client.dll");
};

// Class: C_SceneEntity (Size: 0x658)
class C_SceneEntity : public C_PointEntity {
public:
	SCHEMA(bool, m_bIsPlayingBack, "m_bIsPlayingBack", "C_SceneEntity", "client.dll");
	SCHEMA(bool, m_bPaused, "m_bPaused", "C_SceneEntity", "client.dll");
	SCHEMA(bool, m_bMultiplayer, "m_bMultiplayer", "C_SceneEntity", "client.dll");
	SCHEMA(bool, m_bAutogenerated, "m_bAutogenerated", "C_SceneEntity", "client.dll");
	SCHEMA(float32, m_flForceClientTime, "m_flForceClientTime", "C_SceneEntity", "client.dll");
	SCHEMA(uint16, m_nSceneStringIndex, "m_nSceneStringIndex", "C_SceneEntity", "client.dll");
	SCHEMA(bool, m_bClientOnly, "m_bClientOnly", "C_SceneEntity", "client.dll");
	SCHEMA(CHandle, m_hOwner, "m_hOwner", "C_SceneEntity", "client.dll");
	SCHEMA(CUtlVector< CHandle >, m_hActorList, "m_hActorList", "C_SceneEntity", "client.dll");
	SCHEMA(bool, m_bWasPlaying, "m_bWasPlaying", "C_SceneEntity", "client.dll");
	SCHEMA(float32, m_flCurrentTime, "m_flCurrentTime", "C_SceneEntity", "client.dll");
};

// Class: C_ShatterGlassShardPhysics (Size: 0x13A0)
class C_ShatterGlassShardPhysics : public C_PhysicsProp {
public:
	SCHEMA(shard_model_desc_t, m_ShardDesc, "m_ShardDesc", "C_ShatterGlassShardPhysics", "client.dll");
};

// Class: C_SkyCamera (Size: 0x698)
class C_SkyCamera : public C_BaseEntity {
public:
	SCHEMA(sky3dparams_t, m_skyboxData, "m_skyboxData", "C_SkyCamera", "client.dll");
	SCHEMA(CUtlStringToken, m_skyboxSlotToken, "m_skyboxSlotToken", "C_SkyCamera", "client.dll");
	SCHEMA(bool, m_bUseAngles, "m_bUseAngles", "C_SkyCamera", "client.dll");
	SCHEMA(C_SkyCamera*, m_pNext, "m_pNext", "C_SkyCamera", "client.dll");
};

// Class: C_SmokeGrenadeProjectile (Size: 0x1608)
class C_SmokeGrenadeProjectile : public C_BaseCSGrenadeProjectile {
public:
	SCHEMA(int32, m_nSmokeEffectTickBegin, "m_nSmokeEffectTickBegin", "C_SmokeGrenadeProjectile", "client.dll");
	SCHEMA(bool, m_bDidSmokeEffect, "m_bDidSmokeEffect", "C_SmokeGrenadeProjectile", "client.dll");
	SCHEMA(int32, m_nRandomSeed, "m_nRandomSeed", "C_SmokeGrenadeProjectile", "client.dll");
	SCHEMA(Vector, m_vSmokeColor, "m_vSmokeColor", "C_SmokeGrenadeProjectile", "client.dll");
	SCHEMA(Vector, m_vSmokeDetonationPos, "m_vSmokeDetonationPos", "C_SmokeGrenadeProjectile", "client.dll");
	SCHEMA(int32, m_nVoxelFrameDataSize, "m_nVoxelFrameDataSize", "C_SmokeGrenadeProjectile", "client.dll");
	SCHEMA(int32, m_nVoxelUpdate, "m_nVoxelUpdate", "C_SmokeGrenadeProjectile", "client.dll");
	SCHEMA(bool, m_bSmokeVolumeDataReceived, "m_bSmokeVolumeDataReceived", "C_SmokeGrenadeProjectile", "client.dll");
	SCHEMA(bool, m_bSmokeEffectSpawned, "m_bSmokeEffectSpawned", "C_SmokeGrenadeProjectile", "client.dll");
};

// Class: C_SoundAreaEntityBase (Size: 0x620)
class C_SoundAreaEntityBase : public C_BaseEntity {
public:
	SCHEMA(bool, m_bDisabled, "m_bDisabled", "C_SoundAreaEntityBase", "client.dll");
	SCHEMA(bool, m_bWasEnabled, "m_bWasEnabled", "C_SoundAreaEntityBase", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_iszSoundAreaType, "m_iszSoundAreaType", "C_SoundAreaEntityBase", "client.dll");
	SCHEMA(Vector, m_vPos, "m_vPos", "C_SoundAreaEntityBase", "client.dll");
};

// Class: C_SoundAreaEntityOrientedBox (Size: 0x638)
class C_SoundAreaEntityOrientedBox : public C_SoundAreaEntityBase {
public:
	SCHEMA(Vector, m_vMin, "m_vMin", "C_SoundAreaEntityOrientedBox", "client.dll");
	SCHEMA(Vector, m_vMax, "m_vMax", "C_SoundAreaEntityOrientedBox", "client.dll");
};

// Class: C_SoundAreaEntitySphere (Size: 0x628)
class C_SoundAreaEntitySphere : public C_SoundAreaEntityBase {
public:
	SCHEMA(float32, m_flRadius, "m_flRadius", "C_SoundAreaEntitySphere", "client.dll");
};

// Class: C_SoundEventEntity (Size: 0x6C0)
class C_SoundEventEntity : public C_BaseEntity {
public:
	SCHEMA(bool, m_bStartOnSpawn, "m_bStartOnSpawn", "C_SoundEventEntity", "client.dll");
	SCHEMA(bool, m_bToLocalPlayer, "m_bToLocalPlayer", "C_SoundEventEntity", "client.dll");
	SCHEMA(bool, m_bStopOnNew, "m_bStopOnNew", "C_SoundEventEntity", "client.dll");
	SCHEMA(bool, m_bSaveRestore, "m_bSaveRestore", "C_SoundEventEntity", "client.dll");
	SCHEMA(bool, m_bSavedIsPlaying, "m_bSavedIsPlaying", "C_SoundEventEntity", "client.dll");
	SCHEMA(float32, m_flSavedElapsedTime, "m_flSavedElapsedTime", "C_SoundEventEntity", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_iszSourceEntityName, "m_iszSourceEntityName", "C_SoundEventEntity", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_iszAttachmentName, "m_iszAttachmentName", "C_SoundEventEntity", "client.dll");
	SCHEMA(CEntityIOOutput, m_onSoundFinished, "m_onSoundFinished", "C_SoundEventEntity", "client.dll");
	SCHEMA(float32, m_flClientCullRadius, "m_flClientCullRadius", "C_SoundEventEntity", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_iszSoundName, "m_iszSoundName", "C_SoundEventEntity", "client.dll");
	SCHEMA(CEntityHandle, m_hSource, "m_hSource", "C_SoundEventEntity", "client.dll");
	SCHEMA(int32, m_nEntityIndexSelection, "m_nEntityIndexSelection", "C_SoundEventEntity", "client.dll");
	SCHEMA(bool, m_bClientSideOnly, "m_bClientSideOnly", "C_SoundEventEntity", "client.dll");
};

// Class: C_SoundEventAABBEntity (Size: 0x6D8)
class C_SoundEventAABBEntity : public C_SoundEventEntity {
public:
	SCHEMA(Vector, m_vMins, "m_vMins", "C_SoundEventAABBEntity", "client.dll");
	SCHEMA(Vector, m_vMaxs, "m_vMaxs", "C_SoundEventAABBEntity", "client.dll");
};

// Class: C_SoundEventOBBEntity (Size: 0x6E8)
class C_SoundEventOBBEntity : public C_SoundEventEntity {
public:
	SCHEMA(Vector, m_vMins, "m_vMins", "C_SoundEventOBBEntity", "client.dll");
	SCHEMA(Vector, m_vMaxs, "m_vMaxs", "C_SoundEventOBBEntity", "client.dll");
};

// Class: C_SoundEventPathCornerEntity (Size: 0x6D8)
class SoundeventPathCornerPairNetworked_t;
class C_SoundEventPathCornerEntity : public C_SoundEventEntity {
public:
	SCHEMA(CUtlVector< SoundeventPathCornerPairNetworked_t >, m_vecCornerPairsNetworked, "m_vecCornerPairsNetworked", "C_SoundEventPathCornerEntity", "client.dll");
};

// Class: C_SoundEventSphereEntity (Size: 0x6C8)
class C_SoundEventSphereEntity : public C_SoundEventEntity {
public:
	SCHEMA(float32, m_flRadius, "m_flRadius", "C_SoundEventSphereEntity", "client.dll");
};

// Class: C_SoundOpvarSetPointBase (Size: 0x618)
class C_SoundOpvarSetPointBase : public C_BaseEntity {
public:
	SCHEMA(CUtlSymbolLarge, m_iszStackName, "m_iszStackName", "C_SoundOpvarSetPointBase", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_iszOperatorName, "m_iszOperatorName", "C_SoundOpvarSetPointBase", "client.dll");
	SCHEMA(CUtlSymbolLarge, m_iszOpvarName, "m_iszOpvarName", "C_SoundOpvarSetPointBase", "client.dll");
	SCHEMA(int32, m_iOpvarIndex, "m_iOpvarIndex", "C_SoundOpvarSetPointBase", "client.dll");
	SCHEMA(bool, m_bUseAutoCompare, "m_bUseAutoCompare", "C_SoundOpvarSetPointBase", "client.dll");
};

// Class: C_SpotlightEnd (Size: 0xEC0)
class C_SpotlightEnd : public C_BaseModelEntity {
public:
	SCHEMA(float32, m_flLightScale, "m_flLightScale", "C_SpotlightEnd", "client.dll");
	SCHEMA(float32, m_Radius, "m_Radius", "C_SpotlightEnd", "client.dll");
};

// Class: C_Sprite (Size: 0xF28)
class C_Sprite : public C_BaseModelEntity {
public:
	SCHEMA(CHandle, m_hAttachedToEntity, "m_hAttachedToEntity", "C_Sprite", "client.dll");
	SCHEMA(AttachmentHandle_t, m_nAttachment, "m_nAttachment", "C_Sprite", "client.dll");
	SCHEMA(float32, m_flSpriteFramerate, "m_flSpriteFramerate", "C_Sprite", "client.dll");
	SCHEMA(float32, m_flFrame, "m_flFrame", "C_Sprite", "client.dll");
	SCHEMA(GameTime_t, m_flDieTime, "m_flDieTime", "C_Sprite", "client.dll");
	SCHEMA(uint32, m_nBrightness, "m_nBrightness", "C_Sprite", "client.dll");
	SCHEMA(float32, m_flBrightnessDuration, "m_flBrightnessDuration", "C_Sprite", "client.dll");
	SCHEMA(float32, m_flSpriteScale, "m_flSpriteScale", "C_Sprite", "client.dll");
	SCHEMA(float32, m_flScaleDuration, "m_flScaleDuration", "C_Sprite", "client.dll");
	SCHEMA(bool, m_bWorldSpaceScale, "m_bWorldSpaceScale", "C_Sprite", "client.dll");
	SCHEMA(float32, m_flGlowProxySize, "m_flGlowProxySize", "C_Sprite", "client.dll");
	SCHEMA(float32, m_flHDRColorScale, "m_flHDRColorScale", "C_Sprite", "client.dll");
	SCHEMA(GameTime_t, m_flLastTime, "m_flLastTime", "C_Sprite", "client.dll");
	SCHEMA(float32, m_flMaxFrame, "m_flMaxFrame", "C_Sprite", "client.dll");
	SCHEMA(float32, m_flStartScale, "m_flStartScale", "C_Sprite", "client.dll");
	SCHEMA(float32, m_flDestScale, "m_flDestScale", "C_Sprite", "client.dll");
	SCHEMA(GameTime_t, m_flScaleTimeStart, "m_flScaleTimeStart", "C_Sprite", "client.dll");
	SCHEMA(int32, m_nStartBrightness, "m_nStartBrightness", "C_Sprite", "client.dll");
	SCHEMA(int32, m_nDestBrightness, "m_nDestBrightness", "C_Sprite", "client.dll");
	SCHEMA(GameTime_t, m_flBrightnessTimeStart, "m_flBrightnessTimeStart", "C_Sprite", "client.dll");
	SCHEMA(int32, m_nSpriteWidth, "m_nSpriteWidth", "C_Sprite", "client.dll");
	SCHEMA(int32, m_nSpriteHeight, "m_nSpriteHeight", "C_Sprite", "client.dll");
};

// Class: C_StattrakModule (Size: 0x1168)
class C_StattrakModule : public C_CS2WeaponModuleBase {
public:
	SCHEMA(bool, m_bKnife, "m_bKnife", "C_StattrakModule", "client.dll");
};

// Class: C_Team (Size: 0x6B0)
class C_Team : public C_BaseEntity {
public:
	SCHEMA(CUtlVector<CHandle>, m_aPlayerControllers, "m_aPlayerControllers", "C_Team", "client.dll");
	SCHEMA(CUtlVector<CHandle>, m_aPlayers, "m_aPlayers", "C_Team", "client.dll");
	SCHEMA(int32, m_iScore, "m_iScore", "C_Team", "client.dll");
	SCHEMA(char*, m_szTeamname, "m_szTeamname", "C_Team", "client.dll");
};

// Class: C_CSTeam (Size: 0x960)
class C_CSTeam : public C_Team {
public:
	SCHEMA(char*, m_szTeamMatchStat, "m_szTeamMatchStat", "C_CSTeam", "client.dll");
	SCHEMA(int32, m_numMapVictories, "m_numMapVictories", "C_CSTeam", "client.dll");
	SCHEMA(bool, m_bSurrendered, "m_bSurrendered", "C_CSTeam", "client.dll");
	SCHEMA(int32, m_scoreFirstHalf, "m_scoreFirstHalf", "C_CSTeam", "client.dll");
	SCHEMA(int32, m_scoreSecondHalf, "m_scoreSecondHalf", "C_CSTeam", "client.dll");
	SCHEMA(int32, m_scoreOvertime, "m_scoreOvertime", "C_CSTeam", "client.dll");
	SCHEMA(char*, m_szClanTeamname, "m_szClanTeamname", "C_CSTeam", "client.dll");
	SCHEMA(uint32, m_iClanID, "m_iClanID", "C_CSTeam", "client.dll");
	SCHEMA(char*, m_szTeamFlagImage, "m_szTeamFlagImage", "C_CSTeam", "client.dll");
	SCHEMA(char*, m_szTeamLogoImage, "m_szTeamLogoImage", "C_CSTeam", "client.dll");
};

// Class: C_TextureBasedAnimatable (Size: 0xEE8)
class C_TextureBasedAnimatable : public C_BaseModelEntity {
public:
	SCHEMA(bool, m_bLoop, "m_bLoop", "C_TextureBasedAnimatable", "client.dll");
	SCHEMA(float32, m_flFPS, "m_flFPS", "C_TextureBasedAnimatable", "client.dll");
	SCHEMA(Vector, m_vAnimationBoundsMin, "m_vAnimationBoundsMin", "C_TextureBasedAnimatable", "client.dll");
	SCHEMA(Vector, m_vAnimationBoundsMax, "m_vAnimationBoundsMax", "C_TextureBasedAnimatable", "client.dll");
	SCHEMA(float32, m_flStartTime, "m_flStartTime", "C_TextureBasedAnimatable", "client.dll");
	SCHEMA(float32, m_flStartFrame, "m_flStartFrame", "C_TextureBasedAnimatable", "client.dll");
};

// Class: C_TonemapController2 (Size: 0x610)
class C_TonemapController2 : public C_BaseEntity {
public:
	SCHEMA(float32, m_flAutoExposureMin, "m_flAutoExposureMin", "C_TonemapController2", "client.dll");
	SCHEMA(float32, m_flAutoExposureMax, "m_flAutoExposureMax", "C_TonemapController2", "client.dll");
	SCHEMA(float32, m_flExposureAdaptationSpeedUp, "m_flExposureAdaptationSpeedUp", "C_TonemapController2", "client.dll");
	SCHEMA(float32, m_flExposureAdaptationSpeedDown, "m_flExposureAdaptationSpeedDown", "C_TonemapController2", "client.dll");
	SCHEMA(float32, m_flTonemapEVSmoothingRange, "m_flTonemapEVSmoothingRange", "C_TonemapController2", "client.dll");
};

// Class: C_TriggerBuoyancy (Size: 0x1110)
class C_TriggerBuoyancy : public C_BaseTrigger {
public:
	SCHEMA(CBuoyancyHelper, m_BuoyancyHelper, "m_BuoyancyHelper", "C_TriggerBuoyancy", "client.dll");
	SCHEMA(float32, m_flFluidDensity, "m_flFluidDensity", "C_TriggerBuoyancy", "client.dll");
};

// Class: C_TriggerPhysics (Size: 0x1040)
class C_TriggerPhysics : public C_BaseTrigger {
public:
	SCHEMA(float32, m_gravityScale, "m_gravityScale", "C_TriggerPhysics", "client.dll");
	SCHEMA(float32, m_linearLimit, "m_linearLimit", "C_TriggerPhysics", "client.dll");
	SCHEMA(float32, m_linearDamping, "m_linearDamping", "C_TriggerPhysics", "client.dll");
	SCHEMA(float32, m_angularLimit, "m_angularLimit", "C_TriggerPhysics", "client.dll");
	SCHEMA(float32, m_angularDamping, "m_angularDamping", "C_TriggerPhysics", "client.dll");
	SCHEMA(float32, m_linearForce, "m_linearForce", "C_TriggerPhysics", "client.dll");
	SCHEMA(float32, m_flFrequency, "m_flFrequency", "C_TriggerPhysics", "client.dll");
	SCHEMA(float32, m_flDampingRatio, "m_flDampingRatio", "C_TriggerPhysics", "client.dll");
	SCHEMA(Vector, m_vecLinearForcePointAt, "m_vecLinearForcePointAt", "C_TriggerPhysics", "client.dll");
	SCHEMA(bool, m_bCollapseToForcePoint, "m_bCollapseToForcePoint", "C_TriggerPhysics", "client.dll");
	SCHEMA(Vector, m_vecLinearForcePointAtWorld, "m_vecLinearForcePointAtWorld", "C_TriggerPhysics", "client.dll");
	SCHEMA(Vector, m_vecLinearForceDirection, "m_vecLinearForceDirection", "C_TriggerPhysics", "client.dll");
	SCHEMA(bool, m_bConvertToDebrisWhenPossible, "m_bConvertToDebrisWhenPossible", "C_TriggerPhysics", "client.dll");
};

// Class: C_VoteController (Size: 0x630)
class C_VoteController : public C_BaseEntity {
public:
	SCHEMA(int32, m_iActiveIssueIndex, "m_iActiveIssueIndex", "C_VoteController", "client.dll");
	SCHEMA(int32, m_iOnlyTeamToVote, "m_iOnlyTeamToVote", "C_VoteController", "client.dll");
	SCHEMA(int32*, m_nVoteOptionCount, "m_nVoteOptionCount", "C_VoteController", "client.dll");
	SCHEMA(int32, m_nPotentialVotes, "m_nPotentialVotes", "C_VoteController", "client.dll");
	SCHEMA(bool, m_bVotesDirty, "m_bVotesDirty", "C_VoteController", "client.dll");
	SCHEMA(bool, m_bTypeDirty, "m_bTypeDirty", "C_VoteController", "client.dll");
	SCHEMA(bool, m_bIsYesNoVote, "m_bIsYesNoVote", "C_VoteController", "client.dll");
};

// Class: C_WeaponBaseItem (Size: 0x1F90)
class C_WeaponBaseItem : public C_CSWeaponBase {
public:
	SCHEMA(bool, m_bSequenceInProgress, "m_bSequenceInProgress", "C_WeaponBaseItem", "client.dll");
	SCHEMA(bool, m_bRedraw, "m_bRedraw", "C_WeaponBaseItem", "client.dll");
};

// Class: C_WeaponCZ75a (Size: 0x1FC0)
class C_WeaponCZ75a : public C_CSWeaponBaseGun {
public:
	SCHEMA(bool, m_bMagazineRemoved, "m_bMagazineRemoved", "C_WeaponCZ75a", "client.dll");
};

// Class: C_WeaponTaser (Size: 0x1FC0)
class C_WeaponTaser : public C_CSWeaponBaseGun {
public:
	SCHEMA(GameTime_t, m_fFireTime, "m_fFireTime", "C_WeaponTaser", "client.dll");
	SCHEMA(int32, m_nLastAttackTick, "m_nLastAttackTick", "C_WeaponTaser", "client.dll");
};

// Class: C_fogplayerparams_t (Size: 0x40)
class C_fogplayerparams_t {
public:
	SCHEMA(CHandle, m_hCtrl, "m_hCtrl", "C_fogplayerparams_t", "client.dll");
	SCHEMA(float32, m_flTransitionTime, "m_flTransitionTime", "C_fogplayerparams_t", "client.dll");
	SCHEMA(Color, m_OldColor, "m_OldColor", "C_fogplayerparams_t", "client.dll");
	SCHEMA(float32, m_flOldStart, "m_flOldStart", "C_fogplayerparams_t", "client.dll");
	SCHEMA(float32, m_flOldEnd, "m_flOldEnd", "C_fogplayerparams_t", "client.dll");
	SCHEMA(float32, m_flOldMaxDensity, "m_flOldMaxDensity", "C_fogplayerparams_t", "client.dll");
	SCHEMA(float32, m_flOldHDRColorScale, "m_flOldHDRColorScale", "C_fogplayerparams_t", "client.dll");
	SCHEMA(float32, m_flOldFarZ, "m_flOldFarZ", "C_fogplayerparams_t", "client.dll");
	SCHEMA(Color, m_NewColor, "m_NewColor", "C_fogplayerparams_t", "client.dll");
	SCHEMA(float32, m_flNewStart, "m_flNewStart", "C_fogplayerparams_t", "client.dll");
	SCHEMA(float32, m_flNewEnd, "m_flNewEnd", "C_fogplayerparams_t", "client.dll");
	SCHEMA(float32, m_flNewMaxDensity, "m_flNewMaxDensity", "C_fogplayerparams_t", "client.dll");
	SCHEMA(float32, m_flNewHDRColorScale, "m_flNewHDRColorScale", "C_fogplayerparams_t", "client.dll");
	SCHEMA(float32, m_flNewFarZ, "m_flNewFarZ", "C_fogplayerparams_t", "client.dll");
};

// Class: CountdownTimer (Size: 0x18)
class CountdownTimer {
public:
	SCHEMA(float32, m_duration, "m_duration", "CountdownTimer", "client.dll");
	SCHEMA(GameTime_t, m_timestamp, "m_timestamp", "CountdownTimer", "client.dll");
	SCHEMA(float32, m_timescale, "m_timescale", "CountdownTimer", "client.dll");
	SCHEMA(WorldGroupId_t, m_nWorldGroupId, "m_nWorldGroupId", "CountdownTimer", "client.dll");
};

// Class: EngineCountdownTimer (Size: 0x18)
class EngineCountdownTimer {
public:
	SCHEMA(float32, m_duration, "m_duration", "EngineCountdownTimer", "client.dll");
	SCHEMA(float32, m_timestamp, "m_timestamp", "EngineCountdownTimer", "client.dll");
	SCHEMA(float32, m_timescale, "m_timescale", "EngineCountdownTimer", "client.dll");
};

// Class: EntityRenderAttribute_t (Size: 0x48)
class EntityRenderAttribute_t {
public:
	SCHEMA(CUtlStringToken, m_ID, "m_ID", "EntityRenderAttribute_t", "client.dll");
	SCHEMA(Vector4D, m_Values, "m_Values", "EntityRenderAttribute_t", "client.dll");
};

// Class: EntitySpottedState_t (Size: 0x18)
class EntitySpottedState_t {
public:
	SCHEMA(bool, m_bSpotted, "m_bSpotted", "EntitySpottedState_t", "client.dll");
	SCHEMA(uint32*, m_bSpottedByMask, "m_bSpottedByMask", "EntitySpottedState_t", "client.dll");
};

// Class: FilterDamageType (Size: 0x658)
class FilterDamageType : public CBaseFilter {
public:
	SCHEMA(int32, m_iDamageType, "m_iDamageType", "FilterDamageType", "client.dll");
};

// Class: FilterHealth (Size: 0x660)
class FilterHealth : public CBaseFilter {
public:
	SCHEMA(bool, m_bAdrenalineActive, "m_bAdrenalineActive", "FilterHealth", "client.dll");
	SCHEMA(int32, m_iHealthMin, "m_iHealthMin", "FilterHealth", "client.dll");
	SCHEMA(int32, m_iHealthMax, "m_iHealthMax", "FilterHealth", "client.dll");
};

// Class: IntervalTimer (Size: 0x10)
class IntervalTimer {
public:
	SCHEMA(GameTime_t, m_timestamp, "m_timestamp", "IntervalTimer", "client.dll");
	SCHEMA(WorldGroupId_t, m_nWorldGroupId, "m_nWorldGroupId", "IntervalTimer", "client.dll");
};

// Class: OutflowWithRequirements_t (Size: 0x80)
class OutflowWithRequirements_t {
public:
	SCHEMA(CPulse_OutflowConnection, m_Connection, "m_Connection", "OutflowWithRequirements_t", "client.dll");
	SCHEMA(PulseDocNodeID_t, m_DestinationFlowNodeID, "m_DestinationFlowNodeID", "OutflowWithRequirements_t", "client.dll");
	SCHEMA(CUtlVector< PulseDocNodeID_t >, m_RequirementNodeIDs, "m_RequirementNodeIDs", "OutflowWithRequirements_t", "client.dll");
	SCHEMA(CUtlVector< int32 >, m_nCursorStateBlockIndex, "m_nCursorStateBlockIndex", "OutflowWithRequirements_t", "client.dll");
};

// Class: PhysicsRagdollPose_t (Size: 0x48)
class PhysicsRagdollPose_t {
public:
	SCHEMA(CUtlVector< CTransform >, m_Transforms, "m_Transforms", "PhysicsRagdollPose_t", "client.dll");
	SCHEMA(CHandle, m_hOwner, "m_hOwner", "PhysicsRagdollPose_t", "client.dll");
	SCHEMA(bool, m_bSetFromDebugHistory, "m_bSetFromDebugHistory", "PhysicsRagdollPose_t", "client.dll");
};

// Class: PredictedDamageTag_t (Size: 0x40)
class PredictedDamageTag_t {
public:
	SCHEMA(GameTick_t, nTagTick, "nTagTick", "PredictedDamageTag_t", "client.dll");
	SCHEMA(float32, flFlinchModSmall, "flFlinchModSmall", "PredictedDamageTag_t", "client.dll");
	SCHEMA(float32, flFlinchModLarge, "flFlinchModLarge", "PredictedDamageTag_t", "client.dll");
	SCHEMA(float32, flFriendlyFireDamageReductionRatio, "flFriendlyFireDamageReductionRatio", "PredictedDamageTag_t", "client.dll");
};

// Class: PulseNodeDynamicOutflows_t (Size: 0x18)
class PulseNodeDynamicOutflows_t {
public:
};

// Class: PulseObservableBoolExpression_t (Size: 0x78)
class PulseObservableBoolExpression_t {
public:
	SCHEMA(CPulse_OutflowConnection, m_EvaluateConnection, "m_EvaluateConnection", "PulseObservableBoolExpression_t", "client.dll");
	SCHEMA(CUtlVector< PulseRuntimeBlackboardReferenceIndex_t >, m_DependentObservableBlackboardReferences, "m_DependentObservableBlackboardReferences", "PulseObservableBoolExpression_t", "client.dll");
};

// Class: PulseSelectorOutflowList_t (Size: 0x18)
class PulseSelectorOutflowList_t {
public:
	SCHEMA(CUtlVector< OutflowWithRequirements_t >, m_Outflows, "m_Outflows", "PulseSelectorOutflowList_t", "client.dll");
};

// Class: SellbackPurchaseEntry_t (Size: 0x48)
class SellbackPurchaseEntry_t {
public:
	SCHEMA(uint16, m_unDefIdx, "m_unDefIdx", "SellbackPurchaseEntry_t", "client.dll");
	SCHEMA(int32, m_nCost, "m_nCost", "SellbackPurchaseEntry_t", "client.dll");
	SCHEMA(int32, m_nPrevArmor, "m_nPrevArmor", "SellbackPurchaseEntry_t", "client.dll");
	SCHEMA(bool, m_bPrevHelmet, "m_bPrevHelmet", "SellbackPurchaseEntry_t", "client.dll");
	SCHEMA(CEntityHandle, m_hItem, "m_hItem", "SellbackPurchaseEntry_t", "client.dll");
};

// Class: SequenceHistory_t (Size: 0x18)
class SequenceHistory_t {
public:
	SCHEMA(HSequence, m_hSequence, "m_hSequence", "SequenceHistory_t", "client.dll");
	SCHEMA(GameTime_t, m_flSeqStartTime, "m_flSeqStartTime", "SequenceHistory_t", "client.dll");
	SCHEMA(float32, m_flSeqFixedCycle, "m_flSeqFixedCycle", "SequenceHistory_t", "client.dll");
	SCHEMA(AnimLoopMode_t, m_nSeqLoopMode, "m_nSeqLoopMode", "SequenceHistory_t", "client.dll");
	SCHEMA(float32, m_flPlaybackRate, "m_flPlaybackRate", "SequenceHistory_t", "client.dll");
	SCHEMA(float32, m_flCyclesPerSecond, "m_flCyclesPerSecond", "SequenceHistory_t", "client.dll");
};

// Class: VPhysicsCollisionAttribute_t (Size: 0x30)
class VPhysicsCollisionAttribute_t {
public:
	SCHEMA(uint64, m_nInteractsAs, "m_nInteractsAs", "VPhysicsCollisionAttribute_t", "client.dll");
	SCHEMA(uint64, m_nInteractsWith, "m_nInteractsWith", "VPhysicsCollisionAttribute_t", "client.dll");
	SCHEMA(uint64, m_nInteractsExclude, "m_nInteractsExclude", "VPhysicsCollisionAttribute_t", "client.dll");
	SCHEMA(uint32, m_nEntityId, "m_nEntityId", "VPhysicsCollisionAttribute_t", "client.dll");
	SCHEMA(uint32, m_nOwnerId, "m_nOwnerId", "VPhysicsCollisionAttribute_t", "client.dll");
	SCHEMA(uint16, m_nHierarchyId, "m_nHierarchyId", "VPhysicsCollisionAttribute_t", "client.dll");
	SCHEMA(uint8, m_nCollisionGroup, "m_nCollisionGroup", "VPhysicsCollisionAttribute_t", "client.dll");
	SCHEMA(uint8, m_nCollisionFunctionMask, "m_nCollisionFunctionMask", "VPhysicsCollisionAttribute_t", "client.dll");
};

// Class: ViewAngleServerChange_t (Size: 0x48)
class ViewAngleServerChange_t {
public:
	SCHEMA(FixAngleSet_t, nType, "nType", "ViewAngleServerChange_t", "client.dll");
	SCHEMA(QAngle, qAngle, "qAngle", "ViewAngleServerChange_t", "client.dll");
	SCHEMA(uint32, nIndex, "nIndex", "ViewAngleServerChange_t", "client.dll");
};

// Class: WeaponPurchaseCount_t (Size: 0x38)
class WeaponPurchaseCount_t {
public:
	SCHEMA(uint16, m_nItemDefIndex, "m_nItemDefIndex", "WeaponPurchaseCount_t", "client.dll");
	SCHEMA(uint16, m_nCount, "m_nCount", "WeaponPurchaseCount_t", "client.dll");
};

// Class: WeaponPurchaseTracker_t (Size: 0x70)
class WeaponPurchaseTracker_t {
public:
};

// Class: audioparams_t (Size: 0x78)
class audioparams_t {
public:
	SCHEMA(Vector*, localSound, "localSound", "audioparams_t", "client.dll");
	SCHEMA(int32, soundscapeIndex, "soundscapeIndex", "audioparams_t", "client.dll");
	SCHEMA(uint8, localBits, "localBits", "audioparams_t", "client.dll");
	SCHEMA(int32, soundscapeEntityListIndex, "soundscapeEntityListIndex", "audioparams_t", "client.dll");
	SCHEMA(uint32, soundEventHash, "soundEventHash", "audioparams_t", "client.dll");
};

// Class: fogparams_t (Size: 0x68)
class fogparams_t {
public:
	SCHEMA(Vector, dirPrimary, "dirPrimary", "fogparams_t", "client.dll");
	SCHEMA(Color, colorPrimary, "colorPrimary", "fogparams_t", "client.dll");
	SCHEMA(Color, colorSecondary, "colorSecondary", "fogparams_t", "client.dll");
	SCHEMA(Color, colorPrimaryLerpTo, "colorPrimaryLerpTo", "fogparams_t", "client.dll");
	SCHEMA(Color, colorSecondaryLerpTo, "colorSecondaryLerpTo", "fogparams_t", "client.dll");
	SCHEMA(float32, start, "start", "fogparams_t", "client.dll");
	SCHEMA(float32, end, "end", "fogparams_t", "client.dll");
	SCHEMA(float32, farz, "farz", "fogparams_t", "client.dll");
	SCHEMA(float32, maxdensity, "maxdensity", "fogparams_t", "client.dll");
	SCHEMA(float32, exponent, "exponent", "fogparams_t", "client.dll");
	SCHEMA(float32, HDRColorScale, "HDRColorScale", "fogparams_t", "client.dll");
	SCHEMA(float32, skyboxFogFactor, "skyboxFogFactor", "fogparams_t", "client.dll");
	SCHEMA(float32, skyboxFogFactorLerpTo, "skyboxFogFactorLerpTo", "fogparams_t", "client.dll");
	SCHEMA(float32, startLerpTo, "startLerpTo", "fogparams_t", "client.dll");
	SCHEMA(float32, endLerpTo, "endLerpTo", "fogparams_t", "client.dll");
	SCHEMA(float32, maxdensityLerpTo, "maxdensityLerpTo", "fogparams_t", "client.dll");
	SCHEMA(GameTime_t, lerptime, "lerptime", "fogparams_t", "client.dll");
	SCHEMA(float32, duration, "duration", "fogparams_t", "client.dll");
	SCHEMA(float32, blendtobackground, "blendtobackground", "fogparams_t", "client.dll");
	SCHEMA(float32, scattering, "scattering", "fogparams_t", "client.dll");
	SCHEMA(float32, locallightscale, "locallightscale", "fogparams_t", "client.dll");
	SCHEMA(bool, enable, "enable", "fogparams_t", "client.dll");
	SCHEMA(bool, blend, "blend", "fogparams_t", "client.dll");
	SCHEMA(bool, m_bPadding2, "m_bPadding2", "fogparams_t", "client.dll");
	SCHEMA(bool, m_bPadding, "m_bPadding", "fogparams_t", "client.dll");
};

// Class: shard_model_desc_t (Size: 0x80)
class shard_model_desc_t {
public:
	SCHEMA(int32, m_nModelID, "m_nModelID", "shard_model_desc_t", "client.dll");
	SCHEMA(ShardSolid_t, m_solid, "m_solid", "shard_model_desc_t", "client.dll");
	SCHEMA(Vector2D, m_vecPanelSize, "m_vecPanelSize", "shard_model_desc_t", "client.dll");
	SCHEMA(Vector2D, m_vecStressPositionA, "m_vecStressPositionA", "shard_model_desc_t", "client.dll");
	SCHEMA(Vector2D, m_vecStressPositionB, "m_vecStressPositionB", "shard_model_desc_t", "client.dll");
	SCHEMA(CUtlVector< Vector2D >, m_vecPanelVertices, "m_vecPanelVertices", "shard_model_desc_t", "client.dll");
	SCHEMA(CUtlVector< Vector4D >, m_vInitialPanelVertices, "m_vInitialPanelVertices", "shard_model_desc_t", "client.dll");
	SCHEMA(float32, m_flGlassHalfThickness, "m_flGlassHalfThickness", "shard_model_desc_t", "client.dll");
	SCHEMA(bool, m_bHasParent, "m_bHasParent", "shard_model_desc_t", "client.dll");
	SCHEMA(bool, m_bParentFrozen, "m_bParentFrozen", "shard_model_desc_t", "client.dll");
	SCHEMA(CUtlStringToken, m_SurfacePropStringToken, "m_SurfacePropStringToken", "shard_model_desc_t", "client.dll");
};

// Class: sky3dparams_t (Size: 0x90)
class sky3dparams_t {
public:
	SCHEMA(int16, scale, "scale", "sky3dparams_t", "client.dll");
	SCHEMA(Vector, origin, "origin", "sky3dparams_t", "client.dll");
	SCHEMA(bool, bClip3DSkyBoxNearToWorldFar, "bClip3DSkyBoxNearToWorldFar", "sky3dparams_t", "client.dll");
	SCHEMA(float32, flClip3DSkyBoxNearToWorldFarOffset, "flClip3DSkyBoxNearToWorldFarOffset", "sky3dparams_t", "client.dll");
	SCHEMA(fogparams_t, fog, "fog", "sky3dparams_t", "client.dll");
	SCHEMA(WorldGroupId_t, m_nWorldGroupID, "m_nWorldGroupID", "sky3dparams_t", "client.dll");
};
}
