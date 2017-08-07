/*
Date 8/10/16
Assignment: 2D RogueLike
Name: Matt Tucker
*/

#include "TileList.h"


TileList::TileList(int numTiles)
{
	tileArray = gcnew array<Tile^>(numTiles);
}

Bitmap^ TileList::getTileBitmap(int tileIndex)
{
	return tileArray[tileIndex]->TileBitmap;
}

void TileList::SetTileArrayEntry(int tileIndex, Tile^ tileToEnter)
{
	tileArray[tileIndex] = tileToEnter;
}

Boolean TileList::getIsWalkable(int mapNum)
{
	int test = mapNum;
	Boolean walkable = tileArray[mapNum]->getIsWalkable();
	return walkable;
}