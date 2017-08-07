/*
Date 8/10/16
Assignment: 2D RogueLike
Name: Matt Tucker
*/

#include "GameManager.h"
#include "Sprite.h"
#include "Hero.h"


GameManager::GameManager(Graphics^ startOffScreenCanvas, Random^ startRandom)
{
	myConstants = gcnew GameConstants();
	rand = startRandom;
	offScreenCanvas = startOffScreenCanvas;
	numItems = START_NUM_ITEMS;
	numMonsters = NEWGAME_NUM_MONSTERS;
	monsterBonus = 1;
	monsterPoints = START_MONSTER_POINTS;
	maxRooms = NEWGAME_MAX_ROOMS;
	heroStartLocation = Point(0, 0);
	bounds = Rectangle(0, 0, 1280, 720);
	
	//Create a tileList
	imageList = gcnew TileList(NUM_TILES);

	//Create a Tile and add it to the tileList
	tilePicture1 = gcnew Bitmap("images/Dirt.png");				//Dirt
	Tile^ newTile1 = gcnew Tile(tilePicture1, false, false);
	imageList->SetTileArrayEntry(0, newTile1);

	tilePicture2 = gcnew Bitmap("images/floor.png");			//Floor
	Tile^ newTile2 = gcnew Tile(tilePicture2, true, false);
	imageList->SetTileArrayEntry(1, newTile2);

	tilePicture3 = gcnew Bitmap("images/Dungeon_Wall.png");		//Walls
	Tile^ newTile3 = gcnew Tile(tilePicture3, false, false);
	imageList->SetTileArrayEntry(2, newTile3);

	tilePicture4 = gcnew Bitmap("images/Door.jpg");				//Door
	Tile^ newTile4 = gcnew Tile(tilePicture4, true, false);
	imageList->SetTileArrayEntry(3, newTile4);

	tilePicture5 = gcnew Bitmap("images/fog_tile.png");			//Fog
	Tile^ newTile5 = gcnew Tile(tilePicture5, false, false);
	imageList->SetTileArrayEntry(4, newTile5);

	tilePicture6 = gcnew Bitmap("images/Corridor2.png");			//Corridor
	Tile^ newTile6 = gcnew Tile(tilePicture6, true, false);
	imageList->SetTileArrayEntry(5, newTile6);

	//Create the tileMap
	dungeonTileMap = gcnew Tilemap(imageList, startOffScreenCanvas, MAX_ROWS, MAX_COLS, TILE_SIZE, TILE_SIZE);
	newDungeon = gcnew Dungeon(4, rand);

	//Create the hero images and list
	heroList = gcnew SpriteList(rand);

	heroSheets = gcnew array<String^>(4);
	heroSheets[0] = "images/Mage_East.png";
	heroSheets[1] = "images/Mage_South.png";
	heroSheets[2] = "images/Mage_West.png";
	heroSheets[3] = "images/Mage_North.png";


	//Create the fireball list and sheets
	fireballList = gcnew SpriteList(rand);

	fireballSheets = gcnew array<String^>(4);
	fireballSheets[0] = "images/Fireball_East.gif";
	fireballSheets[1] = "images/Fireball_South.gif";
	fireballSheets[2] = "images/Fireball_West.gif";
	fireballSheets[3] = "images/Fireball_North.gif";

	//Portal Sheets
	portalSheets = gcnew array<String^>(4);
	portalSheets[0] = "images/portal.png";
	portalSheets[1] = "images/portal.png";
	portalSheets[2] = "images/portal.png";
	portalSheets[3] = "images/portal.png";
	
	//Item Sheets
	potionSheets = gcnew array<String^>(4);
	potionSheets[0] = "images/HealthPotion.png";
	potionSheets[1] = "images/HealthPotion.png";
	potionSheets[2] = "images/HealthPotion.png";
	potionSheets[3] = "images/HealthPotion.png";

	reviveSheets = gcnew array<String^>(4);
	reviveSheets[0] = "images/Revive.png";
	reviveSheets[1] = "images/Revive.png";
	reviveSheets[2] = "images/Revive.png";
	reviveSheets[3] = "images/Revive.png";

	swordSheets = gcnew array<String^>(4);
	swordSheets[0] = "images/Sword.png";
	swordSheets[1] = "images/Sword.png";
	swordSheets[2] = "images/Sword.png";
	swordSheets[3] = "images/Sword.png";

	spearSheets = gcnew array<String^>(4);
	spearSheets[0] = "images/Spear.png";
	spearSheets[1] = "images/Spear.png";
	spearSheets[2] = "images/Spear.png";
	spearSheets[3] = "images/Spear.png";

	armourSheets = gcnew array<String^>(4);
	armourSheets[0] = "images/Armour.png";
	armourSheets[1] = "images/Armour.png";
	armourSheets[2] = "images/Armour.png";
	armourSheets[3] = "images/Armour.png";

	shieldSheets = gcnew array<String^>(4);
	shieldSheets[0] = "images/Shield.png";
	shieldSheets[1] = "images/Shield.png";
	shieldSheets[2] = "images/Shield.png";
	shieldSheets[3] = "images/Shield.png";

	cloverSheets = gcnew array<String^>(4);
	cloverSheets[0] = "images/Clover.png";
	cloverSheets[1] = "images/Clover.png";
	cloverSheets[2] = "images/Clover.png";
	cloverSheets[3] = "images/Clover.png";

	treasureSheets = gcnew array<String^>(4);
	treasureSheets[0] = "images/Treasure_Chest.gif";
	treasureSheets[1] = "images/Treasure_Chest.gif";
	treasureSheets[2] = "images/Treasure_Chest.gif";
	treasureSheets[3] = "images/Treasure_Chest.gif";


	//Monster Sheets
	monster1Sheets = gcnew array<String^>(4);		//Blob
	monster1Sheets[0] = "images/blob.png";
	monster1Sheets[1] = "images/blob.png";
	monster1Sheets[2] = "images/blob.png";
	monster1Sheets[3] = "images/blob.png";

	monster2Sheets = gcnew array<String^>(4);		//Skelly
	monster2Sheets[0] = "images/Skelly_East.png";
	monster2Sheets[1] = "images/Skelly_South.png";
	monster2Sheets[2] = "images/Skelly_West.png";
	monster2Sheets[3] = "images/Skelly_North.png";

	monster3Sheets = gcnew array<String^>(4);		//Gork
	monster3Sheets[0] = "images/Gork_East.png";
	monster3Sheets[1] = "images/Gork_South.png";
	monster3Sheets[2] = "images/Gork_West.png";
	monster3Sheets[3] = "images/Gork_North.png";

	//Death Sprite
	deathSheets = gcnew array<String^>(4);
	deathSheets[0] = "images/Mage_Hat.png";
	deathSheets[1] = "images/Mage_Hat.png";
	deathSheets[2] = "images/Mage_Hat.png";
	deathSheets[3] = "images/Mage_Hat.png";

	//Create the hero
	heroSprite = gcnew Hero(offScreenCanvas, heroSheets, 4, rand, dungeonTileMap, 4, heroStartLocation.X, heroStartLocation.Y, START_VEL, START_VEL, bounds, 0.2);
	heroSprite->BoundsAction = EBoundsAction::FREE;
	heroList->addSprite(heroSprite);

	//Create the items
	CreateItems();

	//Create the monsters
	CreateMonsters();

	//Create the portal
	CreatePortal();
	
}

//============================================DUNGEON METHODS==========================================================//

void GameManager::MakeMap()
{
	int numberOfRooms = rand->Next(4, 20);
	newDungeon->MakeDungeon(numberOfRooms);
}

void GameManager::DrawMap()
{
	dungeonTileMap->DrawMap();
}

void GameManager::ClearFog()
{
	int heroCol = heroSprite->getXPos() / TILE_SIZE;
	int heroRow = heroSprite->getYPos() / TILE_SIZE;

	dungeonTileMap->ScanArea(heroCol, heroRow);
}

void GameManager::LoadMap()
{
	//Grab 2D int array from GameManager once it is generated by the dungeon and set it in the Tilemap
	array<int, 2>^ tempMap = newDungeon->getNumberMap();
	dungeonTileMap->setMapFromArray(tempMap);
	dungeonTileMap->SetFogMap();
}

void GameManager::NewLevel()
{
	MakeMap();
	LoadMap();
	SetHeroStartLocation();
	CreateItems();
	monsterPoints += 40;		//Increases the number of monsters in each level
	monsterBonus += 1;
	CreateMonsters();
	monsterList->improveMonsterStats(monsterBonus);
	SetPortalStartLocation();
	SetItemStartLocations();
	SetMonsterStartLocations();
}

void GameManager::CreateMonsters()
{
	//Create the monster images and list
	monsterList = gcnew SpriteList(rand);

	//Each monster is worth a certain amount of points depending on their stats. As a player moves through more more levels, more monsters will appear.
	int count = 0;
	while (count < monsterPoints)				
	{
		
		int monsterSelect = rand->Next(3);
		Monster^ monsterSprite;
		switch (monsterSelect)
		{
		case 0:			//Blob Monster
			monsterSprite = gcnew Monster(offScreenCanvas, monster1Sheets, 9, rand, dungeonTileMap, 4, 0, 0, MONSTER_START_VEL, MONSTER_START_VEL, bounds, 0.2,
				myConstants->BlobHealth, myConstants->BlobAttack, myConstants->BlobStrength, myConstants->BlobDefence, myConstants->BlobEndurance, myConstants->BlobLuck, myConstants->BlobSpeed, myConstants->BlobHealth);
			monsterSprite->IsAnimating = false;
			monsterSprite->IsMoving = false;
			monsterList->addSprite(monsterSprite);
			count += myConstants->BlobPoints;
			break;
		case 1:			//Another Monster
			monsterSprite = gcnew Monster(offScreenCanvas, monster2Sheets, 4, rand, dungeonTileMap, 4, 0, 0, MONSTER_START_VEL, MONSTER_START_VEL, bounds, 0.2, 
				myConstants->SkellyHealth, myConstants->SkellyAttack, myConstants->SkellyStrength, myConstants->SkellyDefence, myConstants->SkellyEndurance, myConstants->SkellyLuck, myConstants->SkellySpeed, myConstants->SkellyPoints);
			monsterSprite->BoundsAction = EBoundsAction::FREE;
			monsterSprite->IsAnimating = false;
			monsterSprite->IsMoving = false;
			monsterList->addSprite(monsterSprite);
			count += myConstants->SkellyPoints;
			break;
		case 2:			//Another Monster
			monsterSprite = gcnew Monster(offScreenCanvas, monster3Sheets, 4, rand, dungeonTileMap, 4, 0, 0, MONSTER_START_VEL, MONSTER_START_VEL, bounds, 0.2, 
				myConstants->GorkHealth, myConstants->GorkAttack, myConstants->GorkStrength, myConstants->GorkDefence, myConstants->GorkEndurance, myConstants->GorkLuck, myConstants->GorkSpeed, myConstants->GorkPoints);
			monsterSprite->BoundsAction = EBoundsAction::FREE;
			monsterSprite->IsAnimating = false;
			monsterSprite->IsMoving = false;
			monsterList->addSprite(monsterSprite);
			count += myConstants->GorkPoints;
			break;
		}
	}
}

void GameManager::CreateItems()
{
	//Create the items
	itemList = gcnew SpriteList(rand);
	
	//Health Items
	for (int i = 0; i < numItems; i++)
	{
		int potionChance = rand->Next(10);
		if (potionChance <= POTION_CHANCE)
		{
			Item^ potionSprite = gcnew Item(offScreenCanvas, potionSheets, 1, rand, dungeonTileMap, 4, bounds, 0.1, EItemType::POTION);
			potionSprite->IsAnimating = false;
			potionSprite->IsMoving = false;
			itemList->addSprite(potionSprite);
		}
		else
		{
			Item^ reviveSprite = gcnew Item(offScreenCanvas, reviveSheets, 1, rand, dungeonTileMap, 4, bounds, 0.1, EItemType::REVIVE);
			reviveSprite->IsAnimating = false;
			reviveSprite->IsMoving = false;
			itemList->addSprite(reviveSprite);
		}
	}

	//Stats Items
	for (int i = 0; i < numItems; i++)
	{
		int itemChance = rand->Next(50);
		if (itemChance < 10)
		{
			Item^ swordSprite = gcnew Item(offScreenCanvas, swordSheets, 1, rand, dungeonTileMap, 4, bounds, 0.1, EItemType::SWORD);
			swordSprite->IsAnimating = false;
			swordSprite->IsMoving = false;
			itemList->addSprite(swordSprite);
		}
		else if (itemChance >= 10 && itemChance < 20)
		{
			Item^ spearSprite = gcnew Item(offScreenCanvas, spearSheets, 1, rand, dungeonTileMap, 4, bounds, 0.1, EItemType::SPEAR);
			spearSprite->IsAnimating = false;
			spearSprite->IsMoving = false;
			itemList->addSprite(spearSprite);
		}
		else if (itemChance >= 20 && itemChance < 30)
		{
			Item^ armourSprite = gcnew Item(offScreenCanvas, armourSheets, 1, rand, dungeonTileMap, 4, bounds, 0.1, EItemType::ARMOUR);
			armourSprite->IsAnimating = false;
			armourSprite->IsMoving = false;
			itemList->addSprite(armourSprite);
		}

		else if (itemChance >= 30 && itemChance < 40)
		{
			Item^ shieldSprite = gcnew Item(offScreenCanvas, shieldSheets, 1, rand, dungeonTileMap, 4, bounds, 0.1, EItemType::SHIELD);
			shieldSprite->IsAnimating = false;
			shieldSprite->IsMoving = false;
			itemList->addSprite(shieldSprite);
		}
		else
		{
			Item^ cloverSprite = gcnew Item(offScreenCanvas, cloverSheets, 1, rand, dungeonTileMap, 4, bounds, 0.1, EItemType::CLOVER);
			cloverSprite->IsAnimating = false;
			cloverSprite->IsMoving = false;
			itemList->addSprite(cloverSprite);
		}
	}

	//Treasure Item - One per level
	Item^ treasureSprite = gcnew Item(offScreenCanvas, treasureSheets, 1, rand, dungeonTileMap, 4, bounds, 0.1, EItemType::TREASURE);
	treasureSprite->IsAnimating = false;
	treasureSprite->IsMoving = false;
	itemList->addSprite(treasureSprite);
}

void GameManager::CreatePortal()
{
	portalList = gcnew SpriteList(rand);
	Sprite^ portalSprite = gcnew Sprite(offScreenCanvas, portalSheets, 1, rand, dungeonTileMap, 4, 0, 0, 0, 0, bounds, 0.1);
	portalList->addSprite(portalSprite);
}

//====================================================================================================================//

//============================================HEROES METHODS==========================================================//
Point GameManager::findFloor()
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

		floorFound = dungeonTileMap->getIsWalkable(colX, colY);		//check to see if that tile is walkable
	}

	int middleX = startX - (TILE_SIZE / 2);
	int middleY = startY - (TILE_SIZE / 2);
	Point startLocation = Point(middleX, middleY);
	return startLocation;
}

void GameManager::MoveHero(EDirection direction)
{
	heroList->controlSprite(direction);								//sets sprites direction
	
	if (heroSprite->getHeroState() == EHeroState::EXPLORE)			//can only move when not in combat with enemy sprites
	{
		heroList->moveSprite();
	}
	
	heroList->updateSpriteFrame();									//hero will still animate with keydown no matter what state
																	//Might make attack animation later with timer tick.
}

void GameManager::RunHero()
{
	heroList->heroDrawHealth();
	if (portalList->checkPortalCollision(heroSprite))
	{
		NewLevel();
	}
	CheckHeroState();
	if (heroSprite->getHeroState() == EHeroState::ATTACK)
	{
		heroList->battleMonsters(monsterList);
	}
	itemList->checkItemCollision(heroSprite);			//Look for item collision
}

void GameManager::DrawHero()
{
	heroList->drawSprites();
}

void GameManager::DrawPortal()
{
	portalList->drawSprites();
}

void GameManager::SetHeroStartLocation()
{
	heroStartLocation = findFloor();
	heroSprite->setXPos(heroStartLocation.X);
	heroSprite->setYPos(heroStartLocation.Y);
}

void GameManager::SetPortalStartLocation()
{
	portalList->setPortalStartLocation(heroStartLocation);
}

void GameManager::CheckHeroState()
{
	if (heroSprite->getHealth() == 0)
	{
		heroSprite->IsAlive = false;
		//if hero has revive, set health to 50 and make IsAlive true. Remove 1 revive
		int revives = heroSprite->getRevive();
		if (revives > 0)
		{
			int newRevives = revives - 1;
			heroSprite->setRevive(newRevives);
			heroSprite->IsAlive = true;
			heroSprite->setHealth(REVIVE_HEALTH);
		}
		else
		{
			//if hero is dead replace with a dead hero
			int deathXLocation = heroSprite->getXPos();
			int deathYLocation = heroSprite->getYPos();
			
			Hero^ deadHero = gcnew Hero(offScreenCanvas, deathSheets, 1, rand, dungeonTileMap, 4, deathXLocation, deathYLocation, 0, 0, bounds, 0.1);
			heroList->addSprite(deadHero);
		}		
	}
	if (heroSprite->HasCollided)
	{
		heroSprite->setHeroState(EHeroState::ATTACK);		
	}
	else
	{
		heroSprite->setHeroState(EHeroState::EXPLORE);
	}
}

void GameManager::ShootFireball()
{
	if (heroSprite->getHeroState() == EHeroState::EXPLORE)
	{
		EDirection direction = heroSprite->SpriteDirection;
		Point velocity = Point(10, 10);
		Sprite^ fireballSprite = gcnew Sprite(offScreenCanvas, fireballSheets, 1, rand, dungeonTileMap, 4, bounds, 0.1);
		fireballSprite->SpriteDirection = direction;
		fireballSprite->setVelocity(velocity);
		fireballSprite->setXPos(heroSprite->getXPos() + 6);		//make fireball location same as hero using +6
		fireballSprite->setYPos(heroSprite->getYPos() + 6);
		fireballList->addSprite(fireballSprite);
	}	
}

void GameManager::MoveFireballs()
{
	fireballList->moveSprite();
}

void GameManager::DrawFireBalls()
{
	fireballList->drawSprites();
}
//=====================================================================================================================//

//============================================MONSTER METHODS==========================================================//
void GameManager::DrawMonsters()
{
	monsterList->drawSprites();
	monsterList->monsterDrawHealth();
}

void GameManager::MoveMonsters()
{
	monsterList->revealMonsters(heroSprite);
	monsterList->monsterUpdateState(heroSprite);
	monsterList->checkMonsterMove(heroSprite);
	monsterList->monsterMove();
	monsterList->updateSpriteFrame();
}

void GameManager::SetMonsterStartLocations()
{
	monsterList->setMonsterStartLocation(heroStartLocation);
}

//=====================================================================================================================//

//==================================DUNGEON COLLISION METHODS==========================================================//

void GameManager::UpdateLists()
{
	heroSprite->HasCollided = false;							//Reset hero collision for next timer tick
	heroList->deleteAllDeadSprites();
	monsterList->checkMonsterCollision(heroSprite);
	fireballList->checkFireballCollision(monsterList);
	fireballList->checkFireballWallCollision();
	monsterList->killDeadMonsters();
	monsterList->deleteAllDeadSprites();
	fireballList->deleteAllDeadSprites();
	itemList->deleteAllDeadSprites();
}

//=====================================================================================================================//

//===============================================ITEM METHODS==========================================================//

void GameManager::SetItemStartLocations()
{
	itemList->setItemStartPositions(heroStartLocation);
}

void GameManager::DrawItems()
{
	itemList->revealItems(heroSprite);
	itemList->drawSprites();
}