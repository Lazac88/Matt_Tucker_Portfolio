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

ref class Tile
{
private:
	Boolean isWalkable;
	Boolean isContainer;
public:
	Tile(Bitmap^ tileImage, Boolean tileWalkable, Boolean tileContainer);
public:
	property Bitmap^ TileBitmap;


public:
	Boolean getIsWalkable();
	Boolean getIsContainer();
};

