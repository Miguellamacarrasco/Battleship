#include "head.h"


std::pair<int,char> generate_ship_coords(std::vector<std::vector<int>> empty_spaces)
{
	int random_y = rand() % 9;
	while (!(empty_spaces[random_y].size()))
	{
		int random_y = rand() % 9;
	}
}


int main()

{
	srand(time(NULL));
	return 0;
}
