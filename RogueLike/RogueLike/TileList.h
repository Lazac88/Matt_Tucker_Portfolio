/*
Date 8/10/16
Assignment: 2D RogueLike
Name: Matt Tucker
*/

#pragma once

#include "Tile.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class TileList
{
private:
	array<Tile^>^ tileArray;
public:
	TileList(int numTiles);

public:
	//Return the bitmap of the tile at position tileIndex in the TileList's array of tile
	Bitmap^ getTileBitmap(int tileIndex);

	//Places tileToEnter at location tileIndex in the TileList's array of Tile
	void SetTileArrayEntry(int tileIndex, Tile^ tileToEnter);

	//Gets if selected tile is walkable and returns true or false
	Boolean getIsWalkable(int mapNum);
};

