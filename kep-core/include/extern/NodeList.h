#pragma once
#include <ogre/OgrePrerequisites.h>
#include <kenshi/util/hand.h>
#include <kenshi/util/lektor.h>

class LocationNode;
class UsageNode;

class NodeList
{
public:
	Ogre::map<hand, Ogre::vector<LocationNode*>::type>::type _0x0;
	Ogre::map<hand, Ogre::vector<UsageNode*>::type>::type _0x28;
	Ogre::map<hand, Ogre::vector<LocationNode*>::type>::type _0x50;
	class ShownNode
	{
	public:
		Ogre::Entity* _0x0;
		LocationNode* _0x8;
	};
	lektor<ShownNode*> _0x78;
	Ogre::vector<UsageNode*>::type _0x90;
	Ogre::InstanceManager* _b0;

private:

};
