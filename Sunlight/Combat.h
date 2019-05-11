#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <time.h>
#include <Windows.h>
#include "Inventory.h"

class Combat
{
private:

	Inventory myInventory;			//instanciating Inventory class for use in combat

	int pHealth;		//player health
	int pDamage;		//player damage can deal
	double pMana;	//rechargeable stat for special skills

	std::queue<int> qEnemies;			//queue to control enemy flow
	std::string eName;			//enemy name
	int eHealth;		//enemy health
	int eDamage;		//enemy damage

	std::vector<int> vEnemiesDefeated;		//counts enemies defeated throughout game
	std::vector<int>::iterator it;			//iterates through defeated enemies list

protected:

	void eThug()			//standard enemy type
	{
		eName = "Thug";
		eHealth = 20;
		eDamage = 12;
	}

	void eLeader()			//advanced enemy type
	{
		eName = "Leader";
		eHealth = 40;
		eDamage = 20;
	}

public:

	Combat()			//constructor for Combat class to set player stats
	{
		pHealth = 50;
		pDamage = 20;
		pMana = 5;
		eDamage = 0;
		eHealth = 0;
	}

	void health()			//health and mana HUD that appears every turn
	{
		std::cout << "\n------------------" << std::endl;
		std::cout << "Health: " << pHealth << std::endl;
		std::cout << "Mana: " << pMana << std::endl;
		std::cout << " " << std::endl;
		std::cout << eName << " Health: " << eHealth << std::endl;
		std::cout << "------------------\n" << std::endl;
	}

	int attack()			//creates player damage output
	{
		int roll;

		srand(time(NULL));			//makes rand more random by syncing it with constantly changing clock
		roll = rand() % pDamage + 1;
		std::cout << "You Attack..." << std::endl;
		std::cout << "You deal " << roll << " damage to the " << eName << "!" << std::endl;
		eHealth = eHealth - roll;			//take health away from enemy
		return roll;
	}

	int flame()		//one of user spells
	{
		int roll = 0;

		if (pMana > 0)			//check to see if user has enough mana to cast spell
		{
			srand(time(NULL));
			roll = rand() % 40 + 1;
			std::cout << "You cast Flame..." << std::endl;
			pMana -= 1;				//takes away a point of mana because of spell use
			std::cout << "You deal " << roll << " damage to the " << eName << "!" << std::endl;
			eHealth = eHealth - roll;
			return roll;
		}
		else              //if player does not have enough mana to cast spell
		{
			std::cout << "You don't have enough mana to cast this..." << std::endl;
			return roll;
		}
	}

	int wind()			//another user spell
	{
		int roll = 0;

		if (pMana > 0)
		{
			srand(time(NULL));
			roll = rand() % 10 + 1;
			std::cout << "You cast Wind..." << std::endl;
			pMana -= 1;
			std::cout << "Your blast of wind pushes the " << eName << " to the ground, staggering them!" << std::endl;
			eDamage = eDamage / 2;				//halves the enemy's attack damage
			std::cout << "You deal " << roll << " damage to the " << eName << "!" << std::endl;
			eHealth = eHealth - roll;
			return roll;
		}
		else              //if player does not have enough mana to cast spell
		{
			std::cout << "You don't have enough mana to cast this..." << std::endl;
			return roll;
		}
	}

	void setEnemyQueue()			//sets how many enemies will appear in the fight
	{
		int roll;
		int i;

		srand(time(NULL));
		roll = rand() % 3 + 1;

		for (i = 0; i < roll; i++)		//adding a random amount of enemies to the fight up to the roll amount
		{
			qEnemies.push(i);
		}

		if (qEnemies.size() == 1)
		{
			std::cout << i << " Enemy appears!" << std::endl;
		}
		else
		{
			std::cout << i << " Enemies appear!" << std::endl;
		}
	}

	int eAttack()			//enemy attack function to deal damage to player
	{
		int roll;

		srand(time(NULL));
		roll = rand() % eDamage + 1;
		std::cout << "The " << eName << " attacks and deals " << roll << " damage to you!" << std::endl;
		pHealth -= roll;			//health subtracted from player
		return roll;
	}

	void rewards()			//post-fight rewards to player
	{
		srand(time(NULL));
		int roll = rand() % 2 + 1;			//whether the user gets a health potion or mana potion from the fight
		
		if (roll == 1)			//adds a health potion to player inventory
		{
			myInventory.addToInventory("Health Potion");
			std::cout << "You received a Health Potion!" << std::endl;
		}
		else if (roll == 2)		//adds a mana potion to player inventory
		{
			myInventory.addToInventory("Mana Potion");
			std::cout << "You received a Mana Potion!" << std::endl;
		}

		pHealth = 100;				//restores player health after each fight
		std::cout << "Your health is also fully restored" << std::endl;
	}

	void fight()			//brings in the other functions from Combat class into a collective battle function
	{
		std::string choice;		//allows player to choose what to do during fight

		setEnemyQueue();
		while (qEnemies.size() > 0)		//while there are still enemies
		{
			if (qEnemies.size() > 1)
			{
				eThug();
			}
			else
			{
				eLeader();			//the final enemy of fight to be leader enemy
			}
			while (eHealth > 0)			//while current enemy alive
			{
				health();

				std::cout << "A " << eName << " is charging at you!" << std::endl;

				std::cout << "What will you do? (attack / spell / item): ";			//user choice for what move to do
				std::getline(std::cin, choice);
				while (choice != "attack" && choice != "Attack" && choice != "ATTACK" && choice != "spell" && choice != "Spell" && choice != "SPELL" && choice != "item" && choice != "Item" && choice != "ITEM")
				{
					std::cout << "Please enter 'attack', 'spell', or 'item': ";
					std::getline(std::cin, choice);
				}
				std::cout << " " << std::endl;

				if (choice == "attack" || choice == "Attack" || choice == "ATTACK")			//user chooses basic attack
				{
					attack();
				}
				else if (choice == "spell" || choice == "Spell" || choice == "SPELL")			//user chooses spell
				{
					std::cout << "Which spell would you like to cast? (flame / wind): ";
					std::getline(std::cin, choice);
					while (choice != "flame" && choice != "Flame" && choice != "FLAME" && choice != "wind" && choice != "Wind" && choice != "WIND")
					{
						std::cout << "Please enter either 'flame' or 'wind': ";
						std::getline(std::cin, choice);
					}
					if (choice == "flame" || choice == "Flame" || choice == "FLAME")
					{
						flame();
					}
					else if (choice == "wind" || choice == "Wind" || choice == "WIND")
					{
						wind();
					}
				}
				else if (choice == "item" || choice == "Item" || choice == "ITEM")			//user chooses to use item
				{
					myInventory.openInventory();

					std::cout << "What item would you like to use? (health potion / mana potion): ";
					std::getline(std::cin, choice);
					while (choice != "health potion" && choice != "Health Potion" && choice != "Health potion" && choice != "HEALTH POTION" && choice != "mana potion" && choice != "Mana Potion" && choice != "Mana potion" && choice != "MANA POTION")
					{
						std::cout << "Please enter either 'health potion' or 'mana potion': ";
						std::getline(std::cin, choice);
					}
					std::cout << " " << std::endl;
					if (choice == "health potion" || choice == "Health Potion" || choice == "Health potion" || choice == "HEALTH POTION")
					{
						if (myInventory.useItem("Health Potion") == 1)
						{
							pHealth = 100;
							std::cout << "Health fully restored" << std::endl;
						}
					}
					else if (choice == "mana potion" || choice == "Mana Potion" || choice == "Mana potion" || choice == "MANA POTION")
					{
						if (myInventory.useItem("Mana Potion") == 1)
						{
							pMana = 5;
							std::cout << "Mana fully restored" << std::endl;
						}
					}
					std::cout << " " << std::endl;
				}
				std::cout << " " << std::endl;

				eAttack();

				if (pHealth <= 0)
				{
					std::cout << "You died..." << std::endl;
					std::cout << "But I'll give you another chance" << std::endl;
					pHealth = 50;
				}

				if (eHealth <= 0)			//if enemy dies
				{
					qEnemies.pop();			//take an enemy out of the queue
					vEnemiesDefeated.push_back(1);				//adds an enemy to the 'vEnemiesDefeated' vector
					std::cout << "\nYou defeated the " << eName << "! " << qEnemies.size() << " enemies remaining!\n" << std::endl;
				}
			}
		}

		rewards();
		std::cout << " " << std::endl;

	}

	void enemiesDefeated()		//shows how many enemies defeated in playthrough
	{
		int total = 0;

		for (it = vEnemiesDefeated.begin(); it != vEnemiesDefeated.end(); ++it)		//iterates through the vector and adds the total together
		{
			total += *it;
		}

		std::cout << "Congratulations!" << std::endl;
		std::cout << "Throughout your adventure, you defeated " << total << " enemies!" << std::endl;
	}

};