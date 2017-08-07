#pragma once
#include "Tile.h"
#include "TileList.h"
#include "Tilemap.h"
#include "Dungeon.h"
#include "Hero.h"
#include "Monster.h"
#include "Item.h"
#include "GameConstants.h"

#define MAX_COLS 80
#define MAX_ROWS 40
#define TILE_SIZE 16
#define NUM_TILES 6
#define START_NUM_ITEMS 3

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

//Dungeon
#define TILE_SIZE 16
#define NEWGAME_MAX_ROOMS 6
#define MIN_ROOMS 4
//Hero
#define START_VEL 8
#define REVIVE_HEALTH 50
//Monster
#define MONSTER_START_VEL 5
#define NEWGAME_NUM_MONSTERS 5
#define START_MONSTER_POINTS 60
//Items
#define POTION_CHANCE 7


ref class GameManager
{
private:
	//tile and dungeon
	Bitmap^ tilePicture1;
	Bitmap^ tilePicture2;
	Bitmap^ tilePicture3;
	Bitmap^ tilePicture4;
	Bitmap^ tilePicture5;
	Bitmap^ tilePicture6;
	Graphics^ offScreenCanvas;
	TileList^ imageList;
	Tilemap^ dungeonTileMap;
	Dungeon^ newDungeon;	
	int maxRooms;
	Rectangle bounds;
private:
	Random^ rand;
	GameConstants^ myConstants;
private:
	//hero
	SpriteList^ heroList;
	array<String^>^ heroSheets;
	array<String^>^deathSheets;
	Point heroStartLocation;
	Hero^ heroSprite;

	array<String^>^ fireballSheets;
	SpriteList^ fireballList;

private:
	//portal
	SpriteList^ portalList;
	array<String^>^ portalSheets;
	Sprite^ portalSprite;

private:
	//items
	SpriteList^ itemList;
	array<String^>^ potionSheets;
	array<String^>^ reviveSheets;
	array<String^>^ swordSheets;
	array<String^>^ spearSheets;
	array<String^>^ armourSheets;
	array<String^>^ shieldSheets;
	array<String^>^ cloverSheets;
	array<String^>^ treasureSheets;
	int numItems;

private:
	//monster
	SpriteList^ monsterList;
	array<String^>^ monster1Sheets;
	array<String^>^ monster2Sheets;
	array<String^>^ monster3Sheets;
	int numMonsters;
	int monsterBonus;
	int monsterPoints;

public:
	GameManager(Graphics^ startOffScreenCanvas, Random^ startRandom);

public:
	//Dungeon methods
	void MakeMap();
	void DrawMap();
	void LoadMap();
	void UpdateLists();
	void NewLevel();
	void CreateMonsters();
	void CreateItems();
	void CreatePortal();
	void ClearFog();


public:
	//Hero methods
	void MoveHero(EDirection direction);
	void DrawHero();
	void RunHero();
	void SetHeroStartLocation();
	void SetPortalStartLocation();
	void DrawPortal();
	void CheckHeroState();
	void ShootFireball();
	void MoveFireballs();
	void DrawFireBalls();

	int getHeroAttack() { return heroSprite->getAttack(); }
	int getHeroStrength() { return heroSprite->getStrength(); }
	int getHeroDefence() { return heroSprite->getDefence(); }
	int getHeroEndurance() { return heroSprite->getEndurance(); }
	int getHeroLuck() { return heroSprite->getLuck(); }
	int getHeroRevive() { return heroSprite->getRevive(); }
	int getHeroScore() { return heroSprite->getScore(); }

public:
	//monster methods
	void SetMonsterStartLocations();
	void DrawMonsters();
	void MoveMonsters();

public:
	//item methods
	void DrawItems();
	void SetItemStartLocations();
public:
	Point findFloor();
};

