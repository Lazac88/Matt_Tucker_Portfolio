/*
Date 8/10/16
Assignment: 2D RogueLike
Name: Matt Tucker
*/
#include "Sprite.h"


Sprite::Sprite(Graphics^ startCanvas, array<String^>^ startSpriteSheet, int startNFrames, Random^ startRandom, Tilemap^ newSpriteTilemap, 
				int numSpriteSheets, Rectangle boundries, double reduceBoundsPercentage)
{
	
	spritesBounds = boundries; 
	setUp(startCanvas, startSpriteSheet, numSpriteSheets);

	spritesMap = newSpriteTilemap;
	reducePercentage = reduceBoundsPercentage;
	rand = startRandom;
	nFrames = startNFrames;
	position = Point(0, 0);
	frameSize.X = spriteSheets[0]->Width / nFrames;
	frameSize.Y = spriteSheets[0]->Height;
	velocity = Point(20, 20);
	currentFrame = 0;
	
}

Sprite::Sprite(Graphics^ startCanvas, array<String^>^ startSpriteSheet, int startNFrames, Random^ startRandom, Tilemap^ newSpriteTilemap,
				int numSpriteSheets, int startXPos, int startYPos, int startXVel, int startYVel, Rectangle boundries, double reduceBoundsPercentage)
{
	
	spritesBounds = boundries;
	setUp(startCanvas, startSpriteSheet, numSpriteSheets);

	reducePercentage = reduceBoundsPercentage;

	spritesMap = newSpriteTilemap;
	rand = startRandom;
	nFrames = startNFrames;
	position.X = startXPos;
	position.Y = startYPos;
	frameSize.X = spriteSheets[0]->Width / nFrames;
	frameSize.Y = spriteSheets[0]->Height;
	velocity.X = startXVel;
	velocity.Y = startYVel;
	currentFrame = 0;
	
}

void Sprite::setUp(Graphics^ startCanvas, array<String^>^ startSpriteSheet, int numSpriteSheets)
{
	canvas = startCanvas;

	//Adding different sprite sheets into array
	spriteSheets = gcnew array<Bitmap^>(numSpriteSheets);
	for (int i = 0; i < startSpriteSheet->Length; i++)
	{
		spriteSheets[i] = gcnew Bitmap(startSpriteSheet[i]);
		Color background = Color(spriteSheets[i]->GetPixel(0, 0));
		spriteSheets[i]->MakeTransparent(background);
	}
	SpriteDirection = EDirection::EAST;
	BoundsAction = EBoundsAction::BOUNCE;
	IsAlive = true;
	IsMoving = true;
	IsAnimating = true;
	HasCollided = false;

	//Initialise the velocity direction array of points
	velocityDirection = gcnew array<Point>(4);
	velocityDirection[EAST] = Point(1, 0);
	velocityDirection[SOUTH] = Point(0, 1);
	velocityDirection[WEST] = Point(-1, 0);
	velocityDirection[NORTH] = Point(0, -1);
	
}

void Sprite::Draw()
{
	int startY = 0;
	int startX = currentFrame * frameSize.X;
	Rectangle pixelsToDraw = Rectangle(startX, startY, frameSize.X, frameSize.Y);			//Creating the rectangle	

	//Drawing the sprite using the directional enum from the Bitmap array, its form position, and its rectangle on the form.
	if (IsAnimating)
	{
		canvas->DrawImage(spriteSheets[SpriteDirection], position.X, position.Y, pixelsToDraw, GraphicsUnit::Pixel);
	}
	

}

void Sprite::Erase(Color eraseColour)
{
	Brush^ brush = gcnew SolidBrush(eraseColour);
	Rectangle eraseRect = Rectangle(position.X, position.Y, frameSize.X, frameSize.Y);
	//canvas->DrawRectangle(brush, eraseRect);
}

void Sprite::Move()
{
	if (IsMoving)
	{ 
		Boolean tileIsWalkable = isTileWalkable();
		if (tileIsWalkable)
		{
			position.X += (velocity.X * velocityDirection[SpriteDirection].X);
			position.Y += (velocity.Y * velocityDirection[SpriteDirection].Y);
		}
	}
}

//finds if next tile is walkable or not
Boolean Sprite::isTileWalkable()
{
	Point^ spritesCorner = findCenter();
	int newXPos = spritesCorner->X + (velocity.X * velocityDirection[SpriteDirection].X);
	int newYPos = spritesCorner->Y + (velocity.Y * velocityDirection[SpriteDirection].Y);

	int columnNum = newXPos / spritesMap->tileWidth;
	int rowNum = newYPos / spritesMap->tileHeight;

	//Pass column and row of next tile to the tile map.
	//Tilemap will return if the tile is walkable or not as a bool
	Boolean walkable = spritesMap->getIsWalkable(columnNum, rowNum);
	return walkable;
}

Point^ Sprite::findCenter()			//Finds the center of the sprite. Makes sprite movement better
{
	Point^ spritesCenter = gcnew Point();
	spritesCenter->X = position.X + (frameSize.X / 2);
	spritesCenter->Y = position.Y + (frameSize.Y / 2);
	return spritesCenter;
}

Point^ Sprite::findCorner()
{
	Point^ spritesCorner = gcnew Point();
	switch (SpriteDirection)
	{
	case(NORTH) :
		spritesCorner->X = position.X + (frameSize.X / 2);
		spritesCorner->Y = position.Y;
		break;
	case (EAST) :
		spritesCorner->X = position.X + frameSize.X;
		spritesCorner->Y = position.Y + (frameSize.Y / 2);
		break;
	case (SOUTH) :
		spritesCorner->X = position.X + (frameSize.X / 2);
		spritesCorner->Y = position.Y + frameSize.Y;
		break;
	case (WEST) :
		spritesCorner->X = position.X;
		spritesCorner->Y = position.Y + (frameSize.Y / 2);
		break;
	}

	return spritesCorner;
}

void Sprite::UpdateFrame()
{
	//increments with looping using the mod function
	if (IsAnimating)
	{
		currentFrame = (currentFrame + 1) % nFrames;
	}
	
}

//This method is used to change the sprite sheet when required
void Sprite::SetSpriteSheet(Bitmap^ newSpriteSheet, int newNFrames)
{
	spriteSheets[SpriteDirection] = newSpriteSheet;
	nFrames = newNFrames;
}

void Sprite::BounceWalls()
{

	int rightEdge = (spritesBounds.X + spritesBounds.Width) - frameSize.X;
	int bottomEdge = (spritesBounds.Y + spritesBounds.Height) - frameSize.Y;


	if (position.X > spritesBounds.X && position.X < rightEdge && position.Y > spritesBounds.Y && position.Y < bottomEdge)
	{
		//do nothing
	}

	else if (position.X <= spritesBounds.X || position.X >= rightEdge)		//if sprite goes outside it's x axis
	{
		if (SpriteDirection == EDirection::EAST)
		{
			SpriteDirection = EDirection::WEST;
			position.X -= 10;
		}
		else
		{
			SpriteDirection = EDirection::EAST;
			position.X += 10;
		}

	}
	else														//if sprite goes ourside it's y-axis
	{
		if (SpriteDirection == EDirection::NORTH)
		{
			SpriteDirection = EDirection::SOUTH;
			position.Y += 10;
		}
		else
		{
			SpriteDirection = EDirection::NORTH;
			position.Y -= 10;
		}
	}
}

void Sprite::StopWalls()
{
	int rightEdge = (spritesBounds.X + spritesBounds.Width) - frameSize.X;
	int bottomEdge = (spritesBounds.Y + spritesBounds.Height) - frameSize.Y;


	if (position.X > spritesBounds.X && position.X <= rightEdge && position.Y > spritesBounds.Y && position.Y <= bottomEdge)
	{
		//do nothing
	}

	else
	{
		velocity.X = 0;
		velocity.Y = 0;

		//stop animation
		IsAnimating = false;
	}
}

void Sprite::WallsAction()
{
	//Bounce from walls
	switch (BoundsAction)
	{
		case(EBoundsAction::BOUNCE) :
			BounceWalls();
			break;
		case(EBoundsAction::STOP) :
			StopWalls();
			break;
	}	
}

Boolean Sprite::SpriteCollision(Sprite^ otherSprite)
{
	Rectangle^ smallRect = smallRectangle();
	Rectangle^ otherSmallRect = otherSprite->smallRectangle();
	Boolean result = true;

	if (smallRect->Right < otherSmallRect->Left)
	{
		result = false;
	}
	if (smallRect->Top > otherSmallRect->Bottom)
	{
		result = false;
	}
	if (smallRect->Left > otherSmallRect->Right)
	{
		result = false;
	}
	if (smallRect->Bottom < otherSmallRect->Top)
	{
		result = false;
	}
	return result;
}

Rectangle^ Sprite::smallRectangle()
{
	//Set up reduced bounds rectangle

	double reductionDistance = frameSize.X * reducePercentage;
	int newX = position.X + reductionDistance;
	int newY = position.Y + reductionDistance;
	int newWidth = frameSize.X - (2 * reductionDistance);
	int newHeight = frameSize.Y - (2 * reductionDistance);

	Rectangle^ newSmallRect = gcnew Rectangle(newX, newY, newWidth, newHeight);
	return newSmallRect;
}

void Sprite::FindStartLocation(Point heroStartLocation)
{
	int stopInfiLoop = 0;
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

		if (stopInfiLoop < 100)
		{
			//Check to see if monster is within 2 tiles of the hero
			Point xRange = Point(heroStartLocation.X - START_PORTAL_GAP, heroStartLocation.X + START_PORTAL_GAP);
			Point yRange = Point(heroStartLocation.Y - START_PORTAL_GAP, heroStartLocation.Y + START_PORTAL_GAP);
			if (startX > xRange.X && startX < xRange.Y && startY > yRange.X && startY < yRange.Y)
			{
				floorFound = false;
				stopInfiLoop++;
			}
		}
		
	}

	position.X = startX - (TILE_SIZE / 2);
	position.Y = startY - (TILE_SIZE / 2);
}



