#include "communication.h"
#include "head.h"
void set_ship_coordinates(std::pair<int, char> *positions, int x, char y, bool &horizontal, int size)
{
	if(horizontal)
	{
		for (int i = 0; i<size;i++)
		{
			positions[i] = {x, y+i};
		}
		return;
	}
	for (int i=0; i<size;i++)
	{
	positions[i] = {x+i, y};
	}
	return;
}

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

std::pair<std::pair<int,char>,bool> generate_ship_coords(std::vector<std::vector<int>> empty_spaces, int size)
{
	int horizontal = rand() % 2;
	if (horizontal)
	{
		int random_y = rand() % 9;
		int free_spaces = find_consecutive_free_spaces(empty_spaces[random_y]);
		while (free_spaces < size + 2)
		{
			int random_y = rand() % 9;
		}
		int random_x = rand() % free_spaces;
		return std::pair<std::pair<int,char>, int>(std::pair<int, char>(random_x, (char)random_y+65),(bool) horizontal);
	}
	
}