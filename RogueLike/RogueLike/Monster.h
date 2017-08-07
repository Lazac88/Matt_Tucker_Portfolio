/*
Date 8/10/16
Assignment: 2D RogueLike
Name: Matt Tucker
*/

#pragma once
#include "Sprite.h"
#include "Hero.h"


#define START_HERO_GAP 32
#define HEALTHBAR_WIDTH 10
#define HEALTHBAR_HEIGHT 2

public enum EMonsterState { WANDER, ORIENTATE, M_ATTACK };

ref class Monster : public Sprite
{
private:
	int wanderCount;
	EMonsterState monsterState;
	int currentHealth;		//health points before death
	int totalHealth;
	int attack;		//minimum attack
	int strength;	//potential extra attack damage
	int defence;	//minumum defence
	int endurance;	//potential extra defence points
	int luck;		//chance of a critical hit
	int pointsValue;
	int speed;
	Point chaseVelocity;
	Pen^ whitePen;
	Brush^ redBrush;
	Brush^ blackBrush;


public:
	Monster^ mNext;

public:
	Monster(Graphics^ startCanvas, array<String^>^ startSpriteSheet, int startNFrames, Random^ startRandom, Tilemap^ newSpriteTilemap,
		int numSpriteSheets, int startXPos, int startYPos, int startXVel, int startYVel, Rectangle boundries, double reduceBoundsPercentage,
			int monsterHealth, int monsterAttack, int monsterStrength, int monsterDefence, int monsterEndurance, int monsterLuck, int monsterSpeed, int monsterPoints);

public:
	void FindStartLocation(Point heroStartLocation);
	void Wander();
	void Orientate(Hero^ heroSprite);
	double ComputeAngleToTarget(Hero^ heroSprite);
	void monsterChase();
	void monsterAttack();
	Boolean isTileWalkable2();
	void drawHealth();

	void improveMonsterStats(int improveNumber);

public:
	//gets and sets
	int getHealth() { return currentHealth; }
	void setHealth(int newHealth) { currentHealth = newHealth; }

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

	int getPoints() { return pointsValue; }
	void setPoints(int newPoints) { pointsValue = newPoints; }

	EMonsterState getMonsterState() { return monsterState; }
	void setMonsterState(EMonsterState newState) { monsterState = newState; }
};

