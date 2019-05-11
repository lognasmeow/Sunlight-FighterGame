#pragma once
#include <time.h>

class Diffusion			//ways to avoid combat
{
private:

	int roll = 0;

public:

	int dSneak()		//roll for sneaking around enemies
	{
		srand(time(NULL));
		roll = rand() % 25 + 1;
		return roll;
	}

	int dLie()		//roll for lying way out of fight
	{
		srand(time(NULL));
		roll = rand() % 10 + 1;		//not a great liar...
		return roll;
	}

	int dHide()			//roll for hiding from enemies
	{
		srand(time(NULL));
		roll = rand() % 30 + 1;
		return roll;
	}
};