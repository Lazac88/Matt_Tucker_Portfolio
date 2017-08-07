/*
Date 8/10/16
Assignment: 2D RogueLike
Name: Matt Tucker
*/

#pragma once

#include "Tilemap.h"
#define TILE_SIZE 16
#define START_PORTAL_GAP 64

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public enum EDirection { EAST, SOUTH, WEST, NORTH };
public enum EBoundsAction {BOUNCE, WRAP, DIE, STOP, FREE};


ref class Sprite
{
public:
	property EDirection SpriteDirection;
	property EBoundsAction BoundsAction;
	property Boolean IsAlive;
	property Boolean IsAnimating;
	property Boolean IsMoving;
	property Boolean HasCollided;

protected:
	Graphics^ canvas;
	array<Bitmap^>^ spriteSheets;
	array<Point>^ velocityDirection;	

	Rectangle spritesBounds;
	Rectangle reducedBounds;	
	
	int nFrames;
	int currentFrame;
	Point position;
	Point frameSize;
	Point velocity;
	double reducePercentage;
	Random^ rand;
	Tilemap^ spritesMap;

public:
	Sprite^ Next;

public:
	Sprite(Graphics^ startCanvas, array<String^>^ startSpriteSheet, int startNFrames, Random^ startRandom, Tilemap^ newSpriteTilemap, int numSpriteSheets, Rectangle boundries, double reduceBoundsPercentage);
	Sprite(Graphics^ startCanvas, array<String^>^ startSpriteSheet, int startNFrames, Random^ startRandom, Tilemap^ newSpriteTilemap,
			int numSpriteSheets, int startXPos, int startYPos, int startXVel, int startYVel, Rectangle boundries, double reduceBoundsPercentage);

	void setUp(Graphics^ startCanvas, array<String^>^ startSpriteSheet, int numSpriteSheets);
	void Draw();
	void Erase(Color eraseColour);
	void Move();
	void UpdateFrame();
	void SetSpriteSheet(Bitmap^ newSpriteSheet, int newNFrames);
	void BounceWalls();
	void StopWalls();
	void WallsAction();
	Boolean isTileWalkable();
	Point^ findCorner();
	Point^ findCenter();
	Rectangle^ smallRectangle();

	void FindStartLocation(Point heroStartLocation);

	Boolean SpriteCollision(Sprite^ otherSprite);

	int getYPos()  { return position.Y; }
	int getXPos()  { return position.X; }
	Rectangle getBounds() { return spritesBounds; }

	void setYPos(int y) { position.Y = y; }
	void setXPos(int x) { position.X = x; }
	void setVelocity(Point spriteVelocity) { velocity = spriteVelocity; }
	void setBounds(Rectangle bounds) { spritesBounds = bounds; }

};


