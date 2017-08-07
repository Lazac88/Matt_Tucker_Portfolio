/*
Date 8/10/16
Assignment: 2D RogueLike
Name: Matt Tucker
*/

#pragma once
#include "Cell.h"
#include "SpriteList.h"
#include "Room.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#define MIN_SIZE 4
#define MAX_SIZE 10
#define MAX_COLS 80
#define MAX_ROWS 40

ref class Dungeon
{
private:
	
	Point dungeonSize;
	array<Cell^, 2>^ cellArray;
	array<int, 2>^ map;
	Random^ rand;
	array<Point>^ centrePointArray;
	int numRooms;

public:
	Dungeon(int startRooms, Random^ random);

public:

	void MakeDungeon(int startRooms);
	void MakeRooms();
	void MakeCorridors();
	void addToCellArray(Room^ newRoom);
	void initialCellFill();
	void convertToIntMap();

	array<int, 2>^ getNumberMap() { return map; }


};

