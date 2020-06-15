#include "head.h"

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
	std::pair<std::pair<int,char>,bool> ship_coords = generate_ship_coords(free_spaces, 4);
	Aircraft_carrier Our_carrier(ship_coords.first, ship_coords.second);
	srand(time(NULL));
	return 0;
}
