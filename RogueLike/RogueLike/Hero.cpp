/*
Date 8/10/16
Assignment: 2D RogueLike
Name: Matt Tucker
*/

#include "Hero.h"


Hero::Hero(Graphics^ startCanvas, array<String^>^ startSpriteSheet, int startNFrames, Random^ startRandom, Tilemap^ newSpriteTilemap,
	int numSpriteSheets, int startXPos, int startYPos, int startXVel, int startYVel, Rectangle boundries, double reduceBoundsPercentage) :
	Sprite(startCanvas, startSpriteSheet, startNFrames, startRandom, newSpriteTilemap,
	numSpriteSheets, startXPos, startYPos, startXVel, startYVel, boundries, reduceBoundsPercentage)
{
	currentHealth = START_HEALTH;
	totalHealth = START_HEALTH;
	attack = START_ATTACK;
	strength = START_STRENGTH;
	defence = START_DEFENCE;
	endurance = START_ENDURANCE;
	luck = START_LUCK;
	score = 0;
	revive = START_REVIVE;
	redBrush = gcnew SolidBrush(Color::Red);
	whiteBrush = gcnew SolidBrush(Color::White);
	heroState = EHeroState::EXPLORE;
}
void Hero::drawHealth()
{
	int locX = position.X + 7;						//Center the health bar over the monsters
	int locY = position.Y + 2;
	double healthLeftDouble;
	int healthLeftInt;

	if (currentHealth > 0)							//If health is more than 0 (so not trying to divide a 0 value)
	{
		healthLeftDouble = ((double)currentHealth / (double)totalHealth) * 200;
		healthLeftInt = System::Convert::ToInt32(healthLeftDouble);
	}
	else
	{
		healthLeftInt = 0;
	}


	canvas->FillRectangle(whiteBrush, HEALTHBAR_LOCX, HEALTHBAR_LOCY, HERO_HEALTHBAR_WIDTH, HERO_HEALTHBAR_HEIGHT);
	canvas->FillRectangle(redBrush, HEALTHBAR_LOCX, HEALTHBAR_LOCY, healthLeftInt, HERO_HEALTHBAR_HEIGHT);
}

void Hero::addScore(int scoreToAdd)		//Adds to score tally
{
	score += scoreToAdd;
}
