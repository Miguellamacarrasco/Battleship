#include "head.h"


int main()
{
	srand(time(NULL));
	std::vector<std::vector<int>> free_spaces;
	for(auto vect1 : free_spaces)
	{
		for (int i=0;i<free_spaces.size();i++)
		{
			vect1[i] = i;
		}
	}

	real_position_orientation ship_coords = generate_ship_coords(free_spaces, 4);
	Aircraft_carrier Our_carrier(ship_coords.first, ship_coords.second);
	remove_position(ship_coords, free_spaces);

	ship_coords = generate_ship_coords(free_spaces, 3);
	
	return 0;
}
