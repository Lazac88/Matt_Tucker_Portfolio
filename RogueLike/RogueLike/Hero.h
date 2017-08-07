/*
Date 8/10/16
Assignment: 2D RogueLike
Name: Matt Tucker
*/

#pragma once
#include "Sprite.h"

//Hero Start Constants
#define START_HEALTH 100
#define START_ATTACK 10
#define START_STRENGTH 1
#define START_DEFENCE 3
#define START_ENDURANCE 1
#define START_LUCK 1
#define START_REVIVE 0

#define HERO_HEALTHBAR_WIDTH 200
#define HERO_HEALTHBAR_HEIGHT 20
#define HEALTHBAR_LOCX 12
#define HEALTHBAR_LOCY 651

public enum EHeroState { EXPLORE, ATTACK };

ref class Hero : public Sprite
{
private:
	int currentHealth;		//health points before death
	int totalHealth;
	int attack;		//minimum attack
	int strength;	//potential extra attack damage
	int defence;	//minumum defence
	int endurance;	//potential extra defence points
	int luck;		//chance of a critical hit
	int score;
	int revive;
	Brush^ redBrush;
	Brush^ whiteBrush;
	EHeroState heroState;

public:
	Hero(Graphics^ startCanvas, array<String^>^ startSpriteSheet, int startNFrames, Random^ startRandom, Tilemap^ newSpriteTilemap,
		int numSpriteSheets, int startXPos, int startYPos, int startXVel, int startYVel, Rectangle boundries, double reduceBoundsPercentage);

public:
	void drawHealth();
	void addScore(int scoreToAdd);		//Created this set differently for ease of code

public:
	//gets and sets
	int getHealth() { return currentHealth; }
	void setHealth(int newHealth) { currentHealth = newHealth; }

	int getTotalHealth() { return totalHealth; }
	void setTotalHealth(int newTotalHealth) { totalHealth = newTotalHealth; }

	int getAttack() { return attack; }
	void setAttack(int newAttack) { attack = newAttack; }

	int getStrength() { return strength; }
	void setStrength(int newStrength){ strength = newStrength; }

	int getDefence() { return defence; }
	void setDefence(int newDefence) { defence = newDefence; }

	int getEndurance() { return endurance; }
	void setEndurance(int newEndurance) { endurance = newEndurance; }

	int getLuck() { return luck; }
	void setLuck(int newLuck) { luck = newLuck; }

	int getScore() { return score; }

	int getRevive() { return revive; }
	void setRevive(int newRevive) { revive = newRevive; }

	EHeroState getHeroState() { return heroState; }
	void setHeroState(EHeroState newState) { heroState = newState; }
};

