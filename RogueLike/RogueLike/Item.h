/*
Date 8/10/16
Assignment: 2D RogueLike
Name: Matt Tucker
*/

#pragma once
#include "Sprite.h"
#include "Hero.h"
#include "Monster.h"

#define ITEM_START_GAP 64

public enum EItemType { POTION, REVIVE, SWORD, SPEAR, ARMOUR, SHIELD, CLOVER, TREASURE};		//Different Item Types

ref class Item : public Sprite
{
private:
	EItemType itemType;

public:
	Item(Graphics^ startCanvas, array<String^>^ startSpriteSheet, int startNFrames, Random^ startRandom, Tilemap^ newSpriteTilemap, int numSpriteSheets, Rectangle boundries, double reduceBoundsPercentage, EItemType startItemType);

public:
	void FindMapPosition(Point heroStartLocation);

public:
	//gets & sets
	EItemType getItemType() { return itemType; }
	void setItemType(EItemType newItemType) { itemType = newItemType; }
};

