/*
Date 8/10/16
Assignment: 2D RogueLike
Name: Matt Tucker
*/

#include "Monster.h"


Monster::Monster(Graphics^ startCanvas, array<String^>^ startSpriteSheet, int startNFrames, Random^ startRandom, Tilemap^ newSpriteTilemap,
	int numSpriteSheets, int startXPos, int startYPos, int startXVel, int startYVel, Rectangle boundries, double reduceBoundsPercentage, 
	int monsterHealth, int monsterAttack, int monsterStrength, int monsterDefence, int monsterEndurance, int monsterLuck, int monsterSpeed, int monsterPoints) :
	Sprite(startCanvas, startSpriteSheet, startNFrames, startRandom, newSpriteTilemap,
	numSpriteSheets, startXPos, startYPos, startXVel, startYVel, boundries, reduceBoundsPercentage)
{
	wanderCount = 0;
	monsterState = EMonsterState::WANDER;
	currentHealth = monsterHealth;
	totalHealth = monsterHealth;
	attack = monsterAttack;
	strength = monsterStrength;
	defence = monsterDefence;
	endurance = monsterEndurance;
	luck = monsterLuck;
	pointsValue = monsterPoints;
	speed = monsterSpeed;
	chaseVelocity = Point(0, 0);
	whitePen = gcnew Pen(Color::White);
	redBrush = gcnew SolidBrush(Color::Red);
	blackBrush = gcnew SolidBrush(Color::Black);
}

void Monster::FindStartLocation(Point heroStartLocation)
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
		Point xRange = Point(heroStartLocation.X - START_HERO_GAP, heroStartLocation.X + START_HERO_GAP);
		Point yRange = Point(heroStartLocation.Y - START_HERO_GAP, heroStartLocation.Y + START_HERO_GAP);
		if (startX > xRange.X && startX < xRange.Y && startY > yRange.X && startY < yRange.Y)
		{
			floorFound = false;
		}
	}

	position.X = startX - (TILE_SIZE / 2);
	position.Y = startY - (TILE_SIZE / 2);	
}

void Monster::Wander()
{
	if (wanderCount < 10)
	{
		wanderCount++;
	}
	else
	{
		int randDirection = rand->Next(4);
		switch (randDirection)
		{
		case 0:
			SpriteDirection = EDirection::NORTH;
			break;
		case 1:
			SpriteDirection = EDirection::EAST;
			break;
		case 2:
			SpriteDirection = EDirection::SOUTH;
			break;
		case 3:
			SpriteDirection = EDirection::WEST;
			break;
		}
		wanderCount = 0;
	}
}

void Monster::Orientate(Hero^ heroSprite)
{
	double angle = ComputeAngleToTarget(heroSprite);

	chaseVelocity.X = Math::Cos(angle) * speed;
	chaseVelocity.Y = Math::Sin(angle) * speed;
}

double Monster::ComputeAngleToTarget(Hero^ heroSprite)
{
	double angle;

	int xDelta = heroSprite->getXPos() - position.X;
	int yDelta = heroSprite->getYPos() - position.Y;

	if ((xDelta != 0) && (yDelta != 0))
	{
		// Check order of args
		// atan2 returns the angle of rotation between two points with horizontal distance arg1 and vertical distance arg2
		angle = Math::Atan2(yDelta, xDelta);	// result is in radians
	}
	else
		angle = 0.0;	// instance and target share an x or y axis location. This works as a heuristic

	return angle;
}

void Monster::monsterChase()
{
	Boolean tileIsWalkable = isTileWalkable2();
	if (tileIsWalkable)
	{
		position.X += chaseVelocity.X;
		position.Y += chaseVelocity.Y;
	}		
}

//finds if next tile is walkable or not
Boolean Monster::isTileWalkable2()
{
	Point^ spritesCorner = findCenter();
	int newXPos = spritesCorner->X + (chaseVelocity.X * velocityDirection[SpriteDirection].X);
	int newYPos = spritesCorner->Y + (chaseVelocity.Y * velocityDirection[SpriteDirection].Y);

	int columnNum = newXPos / spritesMap->tileWidth;
	int rowNum = newYPos / spritesMap->tileHeight;

	//Pass column and row of next tile to the tile map.
	//Tilemap will return if the tile is walkable or not as a bool
	Boolean walkable = spritesMap->getIsWalkable(columnNum, rowNum);
	return walkable;
}

void Monster::monsterAttack()
{
	velocity.X = 0;
	velocity.Y = 0;
}

void Monster::drawHealth()
{
	int locX = position.X + 7;						//Center the health bar over the monsters
	int locY = position.Y + 2;
	double healthLeftDouble;
	int healthLeftInt;
 

	if (currentHealth > 0)							//If health is more than 0 (so not trying to divide a 0 value)
	{
		healthLeftDouble = ((double)currentHealth / (double)totalHealth) * 10;
		healthLeftInt = System::Convert::ToInt32(healthLeftDouble);
	}
	else
	{
		healthLeftInt = 0;
	}
	
	if (IsAnimating)
	{
		canvas->FillRectangle(blackBrush, locX, locY, HEALTHBAR_WIDTH, HEALTHBAR_HEIGHT);
		canvas->FillRectangle(redBrush, locX, locY, healthLeftInt, HEALTHBAR_HEIGHT);
	}	
}

void Monster::improveMonsterStats(int improveNumber)		//Method which increases monster stats by a random number each level
{
	int increase = rand->Next(improveNumber);
	attack += increase;
	increase = rand->Next(improveNumber);
	strength += increase;
	increase = rand->Next(improveNumber);
	defence += increase;
	increase = rand->Next(improveNumber);
	endurance += increase;
	increase = improveNumber * 5;
	currentHealth += increase;
	totalHealth += increase;
	increase = rand->Next(improveNumber);
	luck += increase;
	if (luck > 6)
	{
		luck = 6;
	}
}