/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Copyright (C) 2025-2026 Lucius
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#pragma once
#include <ogre/OgrePrerequisites.h>
#include <ogre/OgreVector3.h>
#include <kenshi/util/lektor.h>
#include <kenshi/util/hand.h>
#include <kenshi/util/TimeOfDay.h>
#include <kenshi/FitnessSelector.h>
#include <kenshi/WorldEventStateQuery.h>
#include <kenshi/AI/AI.h>

enum MoveSpeed;
class Faction;
class TownBase;
class Platoon;
class AreaBiomeGroup;
class CampaignTriggerData;
class CampaignInstance;

enum Phase
{
	P_START,
	P_ASSUALT,
	P_RETREAT,
	P_VICTORY
};

enum WarCampaignEnum
{
	ASSAULT_TOWN,
	CONQUER_TOWN,
	DEFEND_TOWN,
	TRADER_VISIT
};

// KenshiLibでは未定義
class CampaignData
{
public:
	Faction* owner;
	bool targetCharacters;
	bool territorialTriggers;
	bool isHostile;
	int targetTechLevel;
	int targetPopulationMin;
	float chancePerDay;
	int _0x20;
	int _0x24;
	float rangeNear;
	float rangeFar;
	WorldEventStateQueryList worldState;
	lektor<GameData*> specificTargetNPC;
	lektor<GameData*> specialLeaders;
	FitnessSelector<GameData*> squadToUse;
	float repeatLimit;
	WarCampaignEnum key;
	TimeOfDay possTime;
	bool hasPt2AI;
	Faction* factionOverride;
	lektor<GameData*> triggerAlly;
	GameData* data;
	Ogre::map<uint32_t, GameData*>::type leaderSquadAI;
	Ogre::map<uint32_t, GameData*>::type othersSquadAI;
	FitnessSelector<CampaignTriggerData*> lossTrigger;
	FitnessSelector<CampaignTriggerData*> victoryTrigger;

	virtual RootObjectBase* vfunc0x0(Faction*, TownBase*);
	virtual float vfunc0x8(Faction*, TownBase*);
	virtual bool vfunc0x10();
	virtual CampaignInstance* vfunc0x18(int, Faction*, hand&, hand&);
};

// KenshiLibでは未定義
class CampaignInstance
{
public:
	int forces;
	CampaignData* data;
	TimeOfDay _update;
	TimeOfDay _update2;
	MoveSpeed travelSpeedUnloaded;
	MoveSpeed travelSpeedLoaded;
	int numForcesMin;
	int numForcesMax;
	int numForces;
	bool rd;
	bool trig;
	TargetInfo target;
	Faction* owner;
	Faction* enemy;
	hand leader;
	hand home;
	Phase phase;
	bool canTalkBeforeArrival;
	lektor<hand> squads;

	virtual ~CampaignInstance();
	virtual void func0x8();
	virtual void triggerVictory();
	virtual void triggerDefeated();
	virtual void setLeaderHandle(hand&);
	virtual Character* getLeaderCharacter();
	virtual Platoon* getLeaderPlatoon();
	virtual bool isEnemy(Character*);
	virtual std::string getDisplayName();
	virtual bool func0x48();
	virtual void update();
	virtual bool win();
	virtual UnloadedPlatoonJob getUnloadedPlatoonJob(Platoon*);
	virtual GameData* getCampaginAI(Platoon*);
	virtual void addPlatoon(Platoon*, bool);
	virtual bool func0x78(Character*);
	virtual void changeLeader(Platoon*);
	virtual TargetInfo getMyTarget(Platoon*);
	virtual MoveSpeed getUnloadedSpeed();
	virtual MoveSpeed getLoadedSpeed();
	virtual hand getTargetHandle();
	virtual Ogre::Vector3 getPosition(Platoon*);
	virtual Ogre::Vector3 getPositionForWaypoint(Platoon*);
	virtual bool isNearly();
};
