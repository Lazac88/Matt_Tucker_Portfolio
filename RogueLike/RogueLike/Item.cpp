/*
Date 8/10/16
Assignment: 2D RogueLike
Name: Matt Tucker
*/

#include "Item.h"


Item::Item(Graphics^ startCanvas, array<String^>^ startSpriteSheet, int startNFrames, Random^ startRandom, Tilemap^ newSpriteTilemap, int numSpriteSheets, Rectangle boundries, double reduceBoundsPercentage, EItemType startItemType) :
Sprite(startCanvas, startSpriteSheet, startNFrames, startRandom, newSpriteTilemap, numSpriteSheets, boundries, reduceBoundsPercentage)
{
	velocity = Point(0, 0);
	BoundsAction = EBoundsAction::FREE;
	itemType = startItemType;
}

void Item::FindMapPosition(Point heroStartLocation)
{
	int startX;
	int startY;
	Boolean floorFound = false;

	while (!floorFound)
	{
		startX = rand->Next(1260);
		startY = rand->Next(700);
		int colX = startX / TILE_SIZE;		//Find the column and row in the tilemap
		int colY = startY / TILE_SIZE;

		floorFound = spritesMap->getIsWalkable(colX, colY);		//check to see if that tile is walkable

		//Check to see if monster is within 2 tiles of the hero
		Point xRange = Point(heroStartLocation.X - ITEM_START_GAP, heroStartLocation.X + ITEM_START_GAP);
		Point yRange = Point(heroStartLocation.Y - ITEM_START_GAP, heroStartLocation.Y + ITEM_START_GAP);
		if (startX > xRange.X && startX < xRange.Y && startY > yRange.X && startY < yRange.Y)
		{
			floorFound = false;
		}
	}

	position.X = startX - (TILE_SIZE / 2);
	position.Y = startY - (TILE_SIZE / 2);
}
