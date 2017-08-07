/*
Date 8/10/16
Assignment: 2D RogueLike
Name: Matt Tucker
*/

#include "SpriteList.h"


SpriteList::SpriteList(Random^ newRand)
{
	head = nullptr;
	tail = nullptr;
	rand = newRand;
}

void SpriteList::addSprite(Sprite^ newSprite)
{
	//Check to see if there are no Sprites currently
	if (head == nullptr)
	{
		head = newSprite;
		tail = newSprite;
	}
	else
	{
		//Making the old tails Next value point at the newSprite
		tail->Next = newSprite;
		//Making the tail point at the newSprite
		tail = newSprite;
	}
}

void SpriteList::deleteOneSprite(Sprite^ SpriteToDelete)
{

	if (head == SpriteToDelete)			//Conditions involving the first node
	{
		if (tail == SpriteToDelete)		//if the node to delete is the only node in the list
		{
			head = nullptr;
			tail = nullptr;
		}
		else							//If the node to delete is the first node in the list
		{
			head = SpriteToDelete->Next;
		}
	}
	else								//Conditions involving any node except the first
	{
		Sprite^ nodeWalker = head;
		while (nodeWalker->Next != SpriteToDelete)
		{
			nodeWalker = nodeWalker->Next;
		}
		nodeWalker->Next = SpriteToDelete->Next;   //If the node is somewhere in the middle of the list

		if (tail == nodeWalker)			//If node is last in the list
		{
			tail = nodeWalker;			//nodeWalker is pointing at node before the one that gets deleted
		}
	}
}

void SpriteList::deleteAllDeadSprites()
{
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{
		if (!nodeWalker->IsAlive)
		{			
			deleteOneSprite(nodeWalker);
		}
		nodeWalker = nodeWalker->Next;
	}
}

void SpriteList::runSprite()
{
	//checkBounds();
	moveSprite();
	updateSpriteFrame();
}

void SpriteList::moveSprite()
{
	//Make a reference to the head Sprite
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{
		
		nodeWalker->Move();
		//move reference to the next Sprite in the list
		nodeWalker = nodeWalker->Next;
	}
}

void SpriteList::updateSpriteFrame()
{
	//Make a reference to the head Sprite
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{		
		nodeWalker->UpdateFrame();		
		nodeWalker = nodeWalker->Next;
	}
}

void SpriteList::checkBounds()
{
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{
		nodeWalker->WallsAction();
		nodeWalker = nodeWalker->Next;
	}	
}

void SpriteList::bounce()
{
	//Make a reference to the head Sprite
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{
		nodeWalker->BounceWalls();
		//move reference to the next Sprite in the list
		nodeWalker = nodeWalker->Next;
	}
}

void SpriteList::controlSprite(EDirection direction)
{
	//Make a reference to the head Sprite
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{
		nodeWalker->SpriteDirection = direction;
		nodeWalker = nodeWalker->Next;
	}
}

void SpriteList::drawSprites()
{
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{

		nodeWalker->Draw();


		nodeWalker = nodeWalker->Next;
	}
}

int SpriteList::countSprites()
{
	Sprite^ nodeWalker = head;
	int count = 0;
	while (nodeWalker != nullptr)
	{
		count++;
		nodeWalker = nodeWalker->Next;
	}
	return count;
}

//================================================Collision Methods=================================================================//

void SpriteList::updateCollision(EBoundsAction action)
{
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{

		nodeWalker->BoundsAction = action;


		nodeWalker = nodeWalker->Next;
	}
}

Sprite^ SpriteList::checkSpriteCollision(Sprite^ otherSprite)
{
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{
		bool smash = nodeWalker->SpriteCollision(otherSprite);
		if (smash)
		{
			return nodeWalker; //Return the first sprite with which we have collided
		}

		nodeWalker = nodeWalker->Next;
	}
	//If we get here there were no collisions
	return nullptr;
}

//This method checks a SpriteList for collisions with the current spritelist.
//It returns a list of sprites that has collided with the current spritelist.
SpriteList^ SpriteList::checkSpriteListCollision(SpriteList^ otherSpriteList)
{
	SpriteList^ newList = gcnew SpriteList(rand);

	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{
		Sprite^ otherNodeWalker = otherSpriteList->head;
		while (otherNodeWalker != nullptr)
		{
			if (nodeWalker->SpriteCollision(otherNodeWalker))
			{
				newList->addSprite(otherNodeWalker);
			}
			otherNodeWalker = otherNodeWalker->Next;
		}

		nodeWalker = nodeWalker->Next;
	}

	return newList;
}


//====================================================Monster Methods=============================================================//
void SpriteList::setMonsterStartLocation(Point heroStartLoc)
{
	Monster^ nodeWalker = (Monster^)head;
	while (nodeWalker != nullptr)
	{

		nodeWalker->FindStartLocation(heroStartLoc);


		nodeWalker = (Monster^)nodeWalker->Next;
	}
}

void SpriteList::monsterUpdateState(Hero^ heroSprite)
{
	Monster^ nodeWalker = (Monster^)head;
	while (nodeWalker != nullptr)
	{
		Point^ heroCenter = heroSprite->findCenter();						
		Point^ monsterCenter = nodeWalker->findCenter();
		int xPosHero = heroCenter->X;
		int yPosHero = heroCenter->Y;
		int lowXRange = monsterCenter->X - MONSTER_RANGE;
		int highXRange = monsterCenter->X + MONSTER_RANGE;
		int lowYRange = monsterCenter->Y - MONSTER_RANGE;
		int highYRange = monsterCenter->Y + MONSTER_RANGE;

		if (nodeWalker->getHealth() <= 0)
		{
			nodeWalker->IsAlive = false;
		}
		else if (xPosHero > lowXRange && xPosHero < highXRange && yPosHero > lowYRange && yPosHero < highYRange)
		{
			nodeWalker->setMonsterState(EMonsterState::ORIENTATE);
		}
		else
		{
			nodeWalker->setMonsterState(EMonsterState::WANDER);
		}
		
		
		nodeWalker = (Monster^)nodeWalker->Next;
	}
}

void SpriteList::improveMonsterStats(int improveNumber)			//Increase monster strength each level
{
	Monster^ nodeWalker = (Monster^)head;
	while (nodeWalker != nullptr)
	{

		nodeWalker->improveMonsterStats(improveNumber);


		nodeWalker = (Monster^)nodeWalker->Next;
	}
}

void SpriteList::checkMonsterMove(Hero^ heroSprite)				//Sets monster direction
{
	Monster^ nodeWalker = (Monster^)head;
	while (nodeWalker != nullptr)
	{
		EMonsterState mState = nodeWalker->getMonsterState();
		if (mState == EMonsterState::WANDER)
		{
			monsterWander(nodeWalker);
		}
		if (mState == EMonsterState::ORIENTATE)
		{
			nodeWalker->Orientate(heroSprite);
		}
		if (mState == EMonsterState::M_ATTACK)
		{
			//Stand Still
			nodeWalker->monsterAttack();
			//Maybe change animation
		}

		nodeWalker = (Monster^)nodeWalker->Next;
	}
}

void SpriteList::monsterMove()
{
	Monster^ nodeWalker = (Monster^)head;
	while (nodeWalker != nullptr)
	{
		EMonsterState mState = nodeWalker->getMonsterState();
		if (mState == EMonsterState::ORIENTATE)
		{
			nodeWalker->monsterChase();
		}
		else
		{
			nodeWalker->Move();
		}
		nodeWalker = (Monster^)nodeWalker->Next;
	}
}

void SpriteList::monsterWander(Monster^ currentMonster)
{
	currentMonster->Wander();
}

void SpriteList::killDeadMonsters()
{
	Monster^ nodeWalker = (Monster^)head;
	while (nodeWalker != nullptr)
	{
		int monsterHealth = nodeWalker->getHealth();
		if (monsterHealth = 0)
		{
			nodeWalker->IsAlive = false;
		}

		nodeWalker = (Monster^)nodeWalker->Next;
	}
}

void SpriteList::monsterDrawHealth()
{
	Monster^ nodeWalker = (Monster^)head;
	while (nodeWalker != nullptr)
	{
		nodeWalker->drawHealth();

		nodeWalker = (Monster^)nodeWalker->Next;
	}
}

//Improved collision method that sets any sprites to collided and state to attack, if they contact the hero
void SpriteList::checkMonsterCollision(Sprite^ otherSprite)
{
	Monster^ nodeWalker = (Monster^)head;
	while (nodeWalker != nullptr)
	{
		bool smash = nodeWalker->SpriteCollision(otherSprite);
		if (smash)
		{
			nodeWalker->HasCollided = true;
			nodeWalker->setMonsterState(EMonsterState::M_ATTACK);
			otherSprite->HasCollided = true;
		}

		nodeWalker = (Monster^)nodeWalker->Next;
	}
}

void SpriteList::revealMonsters(Hero^ heroSprite)
{
	Monster^ nodeWalker = (Monster^)head;
	while (nodeWalker != nullptr)
	{
		Point^ heroCentre = heroSprite->findCenter();
		Point^ monsterCentre = nodeWalker->findCenter();
		int startXRange = heroCentre->X - MONSTER_RANGE;
		int startYRange = heroCentre->Y - MONSTER_RANGE;
		int endXRange = heroCentre->X + MONSTER_RANGE;
		int endYRange = heroCentre->Y + MONSTER_RANGE;
		int monsterX = monsterCentre->X;
		int monsterY = monsterCentre->Y;

		if (monsterX > startXRange && monsterX < endXRange && monsterY > startYRange && monsterY < endYRange)
		{
			nodeWalker->IsAnimating = true;
			nodeWalker->IsMoving = true;
		}

		nodeWalker = (Monster^)nodeWalker->Next;
	}
}

//============================================HERO METHODS======================================================//
void SpriteList::battleMonsters(SpriteList^ monsterList)
{
	int damageAmplifier = 1;
	Hero^ heroNodeWalker = (Hero^)head;
	Monster^ monsterNodeWalker = (Monster^)monsterList->head;
	while (monsterNodeWalker != nullptr)
	{
		if (monsterNodeWalker->HasCollided)		//Battle if collided with hero
		{
			//Step 1: Calculate if hero will score a critical hit.
			int critChance = rand->Next(11);
			int heroLuck = heroNodeWalker->getLuck();
			if (critChance <= heroLuck)
			{
				damageAmplifier = 2;
			}
			else
			{
				damageAmplifier = 1;
			}
			//Step 2: Calculate Hero Damage, Monster Defence, and totalDamage inflicted.
			int heroDamage = (heroNodeWalker->getAttack() + rand->Next(heroNodeWalker->getStrength())) * damageAmplifier;
			int monsterDefence = monsterNodeWalker->getDefence() + rand->Next(monsterNodeWalker->getEndurance());
			int totalDamage = heroDamage - monsterDefence;
			if (totalDamage < 0)
			{
				totalDamage = 0;
			}
			//Step 3: Remove totalDamage from monster health
			int currMonsterHealth = monsterNodeWalker->getHealth();
			int newMonsterHealth = currMonsterHealth - totalDamage;
			if (newMonsterHealth <= 0)
			{
				newMonsterHealth = 0;
				monsterNodeWalker->IsAlive = false;
				int points = monsterNodeWalker->getPoints();
				heroNodeWalker->addScore(points);
			}
			monsterNodeWalker->setHealth(newMonsterHealth);

			//Step 4: Repeat above process for monster attack on hero
			//calculate crit chance
			critChance = rand->Next(11);
			int monsterLuck = monsterNodeWalker->getLuck();
			if (critChance <= monsterLuck)
			{
				damageAmplifier = 2;
			}
			else
			{
				damageAmplifier = 1;
			}
			//Calculate damage
			int monsterDamage = (monsterNodeWalker->getAttack() + rand->Next(monsterNodeWalker->getStrength())) * damageAmplifier;
			int heroDefence = heroNodeWalker->getDefence() + rand->Next(heroNodeWalker->getEndurance());
			totalDamage = monsterDamage - heroDefence;
			if (totalDamage < 0)
			{
				totalDamage = 0;
			}
			//Remove health from hero
			int currHeroHealth = heroNodeWalker->getHealth();
			int newHeroHealth = currHeroHealth - totalDamage;
			if (newHeroHealth < 0)
			{
				newHeroHealth = 0;
			}
			heroNodeWalker->setHealth(newHeroHealth);
		}		

		//Find next monster in combat
		monsterNodeWalker = (Monster^)monsterNodeWalker->Next;
	}
}

void SpriteList::heroDrawHealth()
{
	Hero^ nodeWalker = (Hero^)head;
	while (nodeWalker != nullptr)
	{
		nodeWalker->drawHealth();

		nodeWalker = (Hero^)nodeWalker->Next;
	}
}

void SpriteList::checkItemCollision(Hero^ heroSprite)
{
	Item^ nodeWalker = (Item^)head;
	while (nodeWalker != nullptr)
	{
		bool smash = nodeWalker->SpriteCollision(heroSprite);
		if (smash)
		{
			nodeWalker->IsAlive = false;
			EItemType foundItem = nodeWalker->getItemType();

			if (foundItem == EItemType::POTION)						//HEALTH POTION
			{
				int totalHealth = heroSprite->getTotalHealth();
				int currHealth = heroSprite->getHealth();
				if (currHealth == totalHealth)
				{
					nodeWalker->IsAlive = true;
				}
				else
				{
					int newHealth = currHealth + 20;
					if (newHealth > totalHealth)			//Check to see that new health isn't more than the hero is allowed in total
					{
						newHealth = totalHealth;
					}
					heroSprite->setHealth(newHealth);
				}
							
			}
			if (foundItem == EItemType::REVIVE)					//REVIVE POTION
			{
				int currRevive = heroSprite->getRevive();
				int newRevive = currRevive + 1;
				heroSprite->setRevive(newRevive);
			}
			if (foundItem == EItemType::SWORD)					//Sword improves attack
			{
				int currAttack = heroSprite->getAttack();
				int newAttack = currAttack + 1;
				heroSprite->setAttack(newAttack);
			}
			if (foundItem == EItemType::SPEAR)					//Spear improves strength
			{
				int currStr = heroSprite->getStrength();
				int newStrength = currStr + 1;
				heroSprite->setStrength(newStrength);
			}
			if (foundItem == EItemType::ARMOUR)					//Armour improves defence
			{
				int currDef = heroSprite->getDefence();
				int newDef = currDef + 1;
				heroSprite->setDefence(newDef);
			}
			if (foundItem == EItemType::SHIELD)					//Shield improves endurance
			{
				int currEnd = heroSprite->getEndurance();
				int newEnd = currEnd + 1;
				heroSprite->setEndurance(newEnd);
			}
			if (foundItem == EItemType::CLOVER)					//Clover improves luck. Maximum 6 (at this stage)
			{
				int currLuck = heroSprite->getLuck();
				if (currLuck < 6)
				{
					int newLuck = currLuck + 1;
					heroSprite->setLuck(newLuck);
				}				
			}
			if (foundItem == EItemType::TREASURE)					//Clover improves luck. Maximum 6 (at this stage)
			{
				int pointsChance = rand->Next(3);
				switch (pointsChance)
				{
				case 0:
					heroSprite->addScore(100);
					break;
				case 1:
					heroSprite->addScore(200);
					break;
				case  2:
					heroSprite->addScore(300);
				}				
			}
		}

		nodeWalker = (Item^)nodeWalker->Next;
	}
}

void SpriteList::setPortalStartLocation(Point heroStartLoc)
{
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{

		nodeWalker->FindStartLocation(heroStartLoc);


		nodeWalker = nodeWalker->Next;
	}
}

//===========================================================ITEM METHODS=================================================================//

void SpriteList::setItemStartPositions(Point heroStartLoc)
{
	
	Item^ nodeWalker = (Item^)head;
	while (nodeWalker != nullptr)
	{
		nodeWalker->FindMapPosition(heroStartLoc);

		nodeWalker = (Item^)nodeWalker->Next;
	}	
}

void SpriteList::revealItems(Hero^ heroSprite)
{
	Item^ nodeWalker = (Item^)head;
	while (nodeWalker != nullptr)
	{
		Point^ heroCentre = heroSprite->findCenter();
		Point^ monsterCentre = nodeWalker->findCenter();
		int startXRange = heroCentre->X - ITEM_RANGE;
		int startYRange = heroCentre->Y - ITEM_RANGE;
		int endXRange = heroCentre->X + ITEM_RANGE;
		int endYRange = heroCentre->Y + ITEM_RANGE;
		int itemX = monsterCentre->X;
		int itemY = monsterCentre->Y;

		if (itemX > startXRange && itemX < endXRange && itemY > startYRange && itemY < endYRange)
		{
			nodeWalker->IsAnimating = true;
			nodeWalker->IsMoving = true;
		}

		nodeWalker = (Item^)nodeWalker->Next;
	}
}

//===========================================================PORTAL METHODS=================================================================//

Boolean SpriteList::checkPortalCollision(Sprite^ otherSprite)
{
	Sprite^ nodeWalker = head;
	Boolean newLevel = false;
	while (nodeWalker != nullptr)
	{
		bool smash = nodeWalker->SpriteCollision(otherSprite);
		if (smash)
		{
			newLevel = true;
		}

		nodeWalker = (Monster^)nodeWalker->Next;
	}

	return newLevel;
}

//============================================FIREBALL METHODS======================================================//
//This method checks a SpriteList for collisions with the current spritelist.
//It returns a list of sprites that has collided with the current spritelist.
void SpriteList::checkFireballCollision(SpriteList^ monsterSpriteList)
{
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{
		Monster^ monsterNodeWalker = (Monster^)monsterSpriteList->head;
		while (monsterNodeWalker != nullptr)
		{
			if (nodeWalker->SpriteCollision(monsterNodeWalker))
			{
				nodeWalker->IsAlive = false;
				int currHealth = monsterNodeWalker->getHealth();
				int newHealth = currHealth - FIREBALL_STRENGTH;
				monsterNodeWalker->setHealth(newHealth);
			}
			monsterNodeWalker = (Monster^)monsterNodeWalker->Next;
		}

		nodeWalker = nodeWalker->Next;
	}
}

void SpriteList::checkFireballWallCollision()
{
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{
		if (!nodeWalker->isTileWalkable())
		{
			nodeWalker->IsAlive = false;
		}
		nodeWalker = nodeWalker->Next;
	}
}