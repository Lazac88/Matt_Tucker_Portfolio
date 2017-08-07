/*
Date 8/10/16
Assignment: 2D RogueLike
Name: Matt Tucker
*/

#pragma once

#include "TileList.h"

#define SCAN_BOX 3
#define SCAN_SIZE 2

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;

ref class Tilemap
{
private:
	TileList^ tileList;
	StreamReader^ sr;
	array<int, 2>^ backgroundMap;
	array<int, 2>^ fogMap;
	Graphics^ canvas;
	Random^ rand;
	int mapCols;
	int mapRows;

public:
	property int tileWidth;
	property int tileHeight;

public:
	Tilemap(TileList^ startTileList, Graphics^ startCanvas, int mapRows, int mapColumns, int newTileWidth, int newTileHeight);

public:
	void SetMapEntry(int col, int row, int tileIndex);
	int GetMapEntry(int col, int row);
	void LoadMapFromFile(String^ fileName);
	void setMapFromArray(array<int, 2>^ mapArray);

public:
	void DrawMap();
	void SetFogMap();
	void ScanArea(int heroCol, int heroRow);

public:
	Boolean getIsWalkable(int col, int row);
};

