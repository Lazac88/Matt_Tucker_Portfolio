/*
Date 8/10/16
Assignment: 2D RogueLike
Name: Matt Tucker
*/

#pragma once

#include "Sprite.h"
#include "Hero.h"
#include "Monster.h"
#include "Item.h"

#define MONSTER_RANGE 64
#define ITEM_RANGE 64
#define FIREBALL_STRENGTH 20

ref class SpriteList
{
private:
	Sprite^ head;
	Sprite^ tail;

private:
	Random^ rand;

public:
	SpriteList(Random^ newRand);
	void addSprite(Sprite^ newSprite);
	void deleteOneSprite(Sprite^ SpriteToDelete);
	void deleteAllDeadSprites();
	void runSprite();
	void moveSprite();
	void controlSprite(EDirection direction);
	void drawSprites();
	void updateSpriteFrame();
	void checkBounds();
	void bounce();
	int countSprites();
	Sprite^ checkSpriteCollision(Sprite^ otherSprite);	
	SpriteList^ checkSpriteListCollision(SpriteList^ otherSpriteList);
	void checkFireballWallCollision();

	void updateCollision(EBoundsAction action);

	//hero methods
	void battleMonsters(SpriteList^ monstersList);
	void heroDrawHealth();
	void checkItemCollision(Hero^ heroSprite);
	void setPortalStartLocation(Point heroStartLoc);

	//fireball method
	void checkFireballCollision(SpriteList^ otherSpriteList);

	//monster methods
	void setMonsterStartLocation(Point heroStartLoc);
	void monsterUpdateState(Hero^ heroSprite);
	void checkMonsterMove(Hero^ heroSprite);
	void monsterMove();
	void monsterWander(Monster^ currentMonster);
	void monsterDrawHealth();
	void killDeadMonsters();
	void checkMonsterCollision(Sprite^ otherSprite);
	void revealMonsters(Hero^ heroSprite);
	void improveMonsterStats(int improveNumber);

	//item methods
	void setItemStartPositions(Point heroStartLoc);
	void revealItems(Hero^ heroSprite);

	//portal methods
	Boolean checkPortalCollision(Sprite^ otherSprite);
	

	//sets & gets
	Sprite^ getHead() { return head; }
};



