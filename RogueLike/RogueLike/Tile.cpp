/*
Date 8/10/16
Assignment: 2D RogueLike
Name: Matt Tucker
*/

#include "Tile.h"


Tile::Tile(Bitmap^ tileImage, Boolean tileWalkable, Boolean tileContainer)
{
	TileBitmap = tileImage;
	isWalkable = tileWalkable;
	isContainer = tileContainer;
}

Boolean Tile::getIsWalkable()
{
	return isWalkable;
}

Boolean Tile::getIsContainer()
{
	return isContainer;
}
