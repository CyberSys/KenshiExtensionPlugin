#pragma once
#include <boost/thread/shared_mutex.hpp>

#include <ogre/OgrePrerequisites.h>

#include <kenshi/util/OgreUnordered.h>
#include <kenshi/CharMovement.h>

class ConstantTracerT
{
public:
	bool _0x0;
	PhysHitItem* _0x8;
	PhysHitItem* _0x10;
	bool _0x18;
};

struct PhysHitItem
{
	physHit hit;
	Ogre::Vector3 _0x60;
	Ogre::Vector3 _0x6c;
	int _0x78;
	bool _0x7c;
};

class HarpoonManager;

class Harpoon
{
public:
	hand opponent;
	hand shooter;
	float range;
	float shotSpeed;
	float friendlyFireAvoidance;
	float damage;
	Ogre::InstancedEntity* entity;
	Ogre::SceneNode* node;
	float lifeTime;
	ConstantTracerT* tracer;
	int _0x70;
	Character* hitPerson;
	bool hitTracer;
	HarpoonManager* manager;
};

class HarpoonManager
{
public:
	ogre_unordered_map<std::string, Ogre::InstanceManager*>::type _0x0;
	ogre_unordered_map<std::pair<std::string, std::string>, Ogre::FastArray<Harpoon*>>::type _0x40;
	Ogre::FastArray<Harpoon*> _0x80;
	Ogre::FastArray<Harpoon*> _0x98;
	boost::shared_mutex _0xb0;
};
