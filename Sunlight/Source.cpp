/*
* Program Name: Final Application
* Author: Logan Kinman
* Date Last Updated: 5-10-2019
* Purpose: Create a turn-based fighter/adventure game using multiple data structures
*/

#pragma once;
#include <iostream>
#include <string>
#include "Inventory.h"
#include "Combat.h"
#include "Diffusion.h"

int main()
{
	std::string userChoice;		//used for branching paths in game

	Combat myCombat;			//instanciate Combat class
	Diffusion myDiffusion;		//instanciate Diffusion class

	std::cout << "You wake up in near-complete darkness.\nLooking around, you notice you are in a cave, \nbut you have no idea how you got here." << std::endl;
	std::cout << "What will you do? (walk/stay): ";
	std::cin >> userChoice;
	while (userChoice != "walk" && userChoice != "WALK" && userChoice != "stay" && userChoice != "STAY")
	{
		std::cout << "Enter either 'walk' or 'stay': ";
		std::cin >> userChoice;
	}
	std::cout << " " << std::endl;

	if (userChoice == "walk" || userChoice == "WALK")
	{
		std::cout << "You stand up and begin making your way through the dark, damp cave.\nSquinting, you can see a faint light at the end of the tunnel." << std::endl;
		std::cout << "You feel a tingling sensation in your right hand.\nLooking at your hand, you notice that it is glowing a yellowish-white hue." << std::endl;
		std::cout << "What will you do? (continue/hand): ";
		std::cin >> userChoice;
		while (userChoice != "continue" && userChoice != "CONTINUE" && userChoice != "hand" && userChoice != "HAND")
		{
			std::cout << "Enter either 'continue' or 'hand': ";
			std::cin >> userChoice;
		}
		std::cout << " " << std::endl;
		if (userChoice == "continue" || userChoice == "CONTINUE")
		{
			std::cout << "You keep walking down the tunnel, hoping to find some answers\nabout what you're doing in here..." << std::endl;
		}
		else
		{
			std::cout << "Your hand has never done anything like this before...\nWhat could be going on with you, and why are you in this cave?" << std::endl;
		}
		std::cout << "All of a sudden, you hear some men come around the corner\ncarrying a knocked out villager into the cave" << std::endl;
		std::cout << "One of them shouts, 'Hey! We've got a live one!' and begin running toward you!" << std::endl;
		std::cout << "With adrenaline rushing, the glow of your hand erupts into a fire!\nIt looks like you're ready for a fight!\n" << std::endl;

		myCombat.fight();
	}
	else
	{
		std::cout << "You lay in the damp muck of the cave,\nwith unanswered questions running through your mind about\nhow you got here." << std::endl;
		std::cout << "All of a sudden, you hear some men come around the corner\ncarrying a knocked out villager into the cave" << std::endl;
		std::cout << "One of them shouts, 'Hey! We've got a live one!' and begin running toward you!" << std::endl;
		std::cout << "With adrenaline rushing, your hand begins to glow and erupts into a fire!\nIt looks like you're ready for a fight!\n" << std::endl;

		myCombat.fight();
	}

	std::cout << "The fight was over. You begin sprinting toward the mouth\nof the cave as quickly as you can." << std::endl;
	std::cout << "As you get closer to the light coming from outside,\na few silhouettes of guards become appearent!" << std::endl;
	std::cout << "'One of them must be escaping!' you hear one shout." << std::endl;
	std::cout << "What will you do? (hide/fight): ";
	std::cin >> userChoice;
	while (userChoice != "hide" && userChoice != "HIDE" && userChoice != "fight" && userChoice != "FIGHT")
	{
		std::cout << "Enter either 'hide' or 'fight': ";
		std::cin >> userChoice;
	}
	std::cout << " " << std::endl;

	if (userChoice == "hide" || userChoice == "HIDE")
	{
		std::cout << "You duck around a corner and crouch to the floor,\nhoping to avoid the guards spotting you." << std::endl;
		std::cout << "The guards run straight past you, you are good to go." << std::endl;
		std::cout << "What will you do? (go): ";
		std::cin >> userChoice;
		while (userChoice != "go" && userChoice != "GO")
		{
			std::cout << "Enter 'go': ";
			std::cin >> userChoice;
		}
		std::cout << " " << std::endl;

		if (myDiffusion.dHide() > 5)
		{
			std::cout << "[HIDE SUCCESS]" << std::endl;
			std::cout << "You slip past the guards and walk outside the cave" << std::endl;
		}
		else
		{
			std::cout << "[HIDE FAIL]" << std::endl;
			std::cout << "As you begin walking out of the cave a guard grabs you\nby the shoulders and whips you around" << std::endl;
			std::cout << "'Not so fast!' he cries, as he raises his hand to attack!" << std::endl;
			myCombat.fight();
		}
	}
	else
	{
		myCombat.fight();
	}

	std::cout << "You step outside the cave and see a terrifying sight" << std::endl;
	std::cout << "In your village, a massive machine that looks like a siphon is\nchanneling a wispy, purple material from the ground" << std::endl;
	std::cout << "You need to get away from the village, and the sunlight makes you conspicuous" << std::endl;
	std::cout << "What will you do? (sneak/run): ";
	std::cin >> userChoice;
	while (userChoice != "sneak" && userChoice != "SNEAK" && userChoice != "run" && userChoice != "RUN")
	{
		std::cout << "Enter either 'sneak' or 'run': ";
		std::cin >> userChoice;
	}
	std::cout << " " << std::endl;

	if (userChoice == "sneak" || userChoice == "SNEAK")
	{
		if (myDiffusion.dSneak() > 15)
		{
			std::cout << "[SNEAK SUCCESS]" << std::endl;
			std::cout << "You make it to the edge of the village" << std::endl;
		}
		else
		{
			std::cout << "[SNEAK FAIL]" << std::endl;
			std::cout << "Some guards see you trying to sneak your way\nthrough the village in broad daylight" << std::endl;
			std::cout << "You begin to run as quickly as you can!" << std::endl;
			std::cout << "Eventually, you make it to the edge of the village" << std::endl;
		}
	}
	else
	{
		std::cout << "You decide to make a run for it. You sprint as quickly\nas you can through the village." << std::endl;
		std::cout << "You make it to the edge of the village" << std::endl;
	}
	std::cout << "and dash into a thicket of trees." << std::endl;

	std::cout << "Your arm begins to burn and cause extreme pain! What is going on!?" << std::endl;
	std::cout << "All of a sudden, and hand grabs and covers your mouth\nand sternly whispers to you not to move and to stay quiet!" << std::endl;
	std::cout << "What will you do? (struggle/quiet): ";
	std::cin >> userChoice;
	while (userChoice != "struggle" && userChoice != "STRUGGLE" && userChoice != "quiet" && userChoice != "QUIET")
	{
		std::cout << "Enter either 'struggle' or 'quiet': ";
		std::cin >> userChoice;
	}
	std::cout << " " << std::endl;

	if (userChoice == "struggle" || userChoice == "STRUGGLE")
	{
		std::cout << "You try to struggle against the unknown attacker,\nbut it's no use." << std::endl;
		std::cout << "'I told you not to move!' they state again" << std::endl;
	}
	std::cout << "'Don't worry.' they say, loosening their grip, 'I'm not your enemy.'" << std::endl;
	std::cout << "But if I hadn't have grabbed you, you would've tried to attack me.\n" << std::endl;
	std::cout << "You look at the stranger and notice he is a man with long,\nblack hair and a white countenance" << std::endl;
	std::cout << "What will you do? (speak/quiet): ";
	std::cin >> userChoice;
	while (userChoice != "speak" && userChoice != "SPEAK" && userChoice != "quiet" && userChoice != "QUIET")
	{
		std::cout << "Enter either 'speak' or 'quiet': ";
		std::cin >> userChoice;
	}
	std::cout << " " << std::endl;

	if (userChoice == "speak" || userChoice == "SPEAK")
	{
		std::cout << "'Yeah,' you say, 'well I've done enough fighting today.'" << std::endl;
		std::cout << "'I just want to know what's going on here?'" << std::endl;
	}
	else
	{
		std::cout << "'Not going to talk, I see.' he says, 'I'm..I'm sorry.\nI just couldn't take any chances.'" << std::endl;
	}

	std::cout << "'They are siphoning the magic from this village, he explains,\n'And with the magic, they plan on taking rule over the whole land.'" << std::endl;
	std::cout << "'But I know how to stop them' he continues,\n'If the siphon's core is destroyed, their whole plan is destroyed.'" << std::endl;

	std::cout << "What will you do? (go): ";
	std::cin >> userChoice;
	while (userChoice != "go" && userChoice != "GO")
	{
		std::cout << "Enter either 'go' or 'GO': ";
		std::cin >> userChoice;
	}
	std::cout << " " << std::endl;

	std::cout << "You make your way toward the siphon. It is large and\nvery loud, concealing your presence." << std::endl;
	std::cout << "You creep around the machine until you find\nwhat looks like a control panel." << std::endl;
	std::cout << "As you are fiddling with the control panel,\nsome guards walk up and ask you to state your business" << std::endl;
	std::cout << "What will you do? (lie/fight): ";
	std::cin >> userChoice;
	while (userChoice != "lie" && userChoice != "LIE" && userChoice != "fight" && userChoice != "FIGHT")
	{
		std::cout << "Enter either 'lie' or 'fight': ";
		std::cin >> userChoice;
	}
	std::cout << " " << std::endl;

	if (userChoice == "lie" || userChoice == "LIE")
	{
		if (myDiffusion.dLie() > 5)
		{
			std::cout << "[LIE SUCCESS]" << std::endl;
			std::cout << "'Can't you see I'm trying to fix this thing?' you shout" << std::endl;
			std::cout << "'Or I can just stop and let boss be mad at you folk!'" << std::endl;
			std::cout << "'Er..no, please continue' the guards answer\n'Keep up the, uh, good work.'" << std::endl;
		}
		else
		{
			std::cout << "[LIE FAIL]" << std::endl;
			std::cout << "You try to make up some story about being a\ntechnician fixing the siphon." << std::endl;
			std::cout << "The looks on the guards faces show you they are not convinced..." << std::endl;
			myCombat.fight();
		}
	}
	else
	{
		myCombat.fight();
	}

	std::cout << " " << std::endl;
	std::cout << "As you mess with the control panel some more,\nyou manage to pop it off the siphon entirely!" << std::endl;
	std::cout << "You see what seems to be the exposed core -\na bright white ball of pure energy." << std::endl;
	std::cout << "\nSuddenly, your arm begins to burn with a pain you have\nnever felt before!!!" << std::endl;
	std::cout << "All you have to do is grab the core." << std::endl;
	std::cout << "What will you do? (grab/run): ";
	std::cin >> userChoice;
	while (userChoice != "grab" && userChoice != "GRAB" && userChoice != "run" && userChoice != "RUN")
	{
		std::cout << "Enter either 'grab' or 'run': ";
		std::cin >> userChoice;
	}
	std::cout << " " << std::endl;

	if (userChoice == "run" || userChoice == "RUN")
	{
		while (userChoice != "grab" || userChoice == "GRAB")
		{
			std::cout << "All you have to do is grab the core: ";
			std::cin >> userChoice;
		}
	}

	std::cout << "\nYou reach inside the siphon, slowly getting closer to the core." << std::endl;
	std::cout << "Inches away, your hand is burning more and more" << std::endl;
	std::cout << "You grab the core." << std::endl;
	std::cout << "The light around you starts to become brighter\nand brighter until\n.\n.\n.\n.\n.\n." << std::endl;
	std::cout << "Until there is nothing\n.\n.\n.\n.\n.\n." << std::endl;
	std::cout << "The end" << std::endl;

	myCombat.enemiesDefeated();

	system("pause");
	return 0;
}