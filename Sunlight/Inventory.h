#pragma once
#include <vector>
#include <iostream>
#include <string>

class Inventory
{
private:

	std::vector<std::string> inventory;

public:

	void addToInventory(std::string item)			//adds item to inventory
	{
		inventory.push_back(item);
	}

	void openInventory()							//displays inventory to the screen
	{
		std::cout << "\n----- Inventory -----" << std::endl;
		for (int i = 0; i < inventory.size(); i++)
		{
			std::cout << inventory[i] << std::endl;
		}
		std::cout << " -------------------\n " << std::endl;
	}

	int useItem(std::string item)					//removes used item from inventory
	{
		int success;
		std::vector<std::string>::iterator it = std::find(inventory.begin(), inventory.end(), item);		//iterator to find item
		
		if (it != inventory.end())
		{
			int indexNum = std::distance(inventory.begin(), it);
			inventory.erase(inventory.begin() + indexNum);
			success = 1;
		}
		else
		{
			std::cout << "Item not found in inventory" << std::endl;
			success = 0;
		}
		return success;
	}
};