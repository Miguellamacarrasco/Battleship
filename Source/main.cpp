#include "head.h"

int find_consecutive_free_spaces(std::vector<int> vect)
{
	int highest_consecutive_spaces = 0;
	int spaces = 0;
	int counting = vect[0];
	for (int i = 1; i<vect.size(); i++)
	{
		if ((counting + 1) == vect[i])
		{
			spaces++;
		}
		else
		{
			if (highest_consecutive_spaces < spaces)
			{
				highest_consecutive_spaces = spaces;
			}
		}
		counting = vect[i];
	}
	return highest_consecutive_spaces;
}

std::pair<int,char> generate_ship_coords(std::vector<std::vector<int>> empty_spaces, ship* boat)
{
	int horizontal = rand() % 2;
	if (horizontal)
	{
		int random_y = rand() % 9;
		while (find_consecutive_free_spaces(empty_spaces[random_y]) < boat->size_of() + 2)
		{
			int random_y = rand() % 9;
		}
		int random_x = rand() % empty_spaces.size();
	}
	
}


int main()

{
	std::vector<std::vector<int>> free_spaces;
	for(auto vect1 : free_spaces)
	{
		for (int i=0;i<free_spaces.size();i++)
		{
			vect1[i] = i;
		}
	}
	srand(time(NULL));
	return 0;
}
