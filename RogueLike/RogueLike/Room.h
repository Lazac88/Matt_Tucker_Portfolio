/*
Date 8/10/16
Assignment: 2D RogueLike
Name: Matt Tucker
*/
#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#define MAX_COLS 80
#define MAX_ROWS 40

ref class Room
{
private:
	Point size;
	Point roomLoc;
	Point centreRoom;

public:
	Room^ Next;
public:
	Room(Point roomSize, Point roomLocation);

public:
	Point getSize() { return size; }
	Point getLocation() { return roomLoc; }
	Point getCentre() { return centreRoom; }		//Nice method which returns the rooms centre

	void setSize(Point rSize) { size = rSize; }
	void setLocation(Point rLocation) { roomLoc = rLocation; }
};

