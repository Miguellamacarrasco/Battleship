#include "communication.h"

std::vector<int> find_consecutive_free_spaces(std::vector<int> vect)
{
	int highest_consecutive_spaces = 0;
	int spaces = 0;
	int counting = vect[0];
	std::vector<int> free_spaces;
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
				free_spaces.push_back(spaces);
			}
		}
		counting = vect[i];
	}
	std::sort(free_spaces.begin(), free_spaces.end());
	return free_spaces;
}

real_position_orientation generate_ship_coords(position empty_spaces, int size)
{
	int horizontal = rand() % 2;
	if (horizontal)
	{
		int random_y = rand() % 9;
		std::vector<int> free_spaces = find_consecutive_free_spaces(empty_spaces[random_y]);
		while (*free_spaces.end() < size)
		{
			int random_y = rand() % 9;
		}
		int cant_fit_in=free_spaces.size();
		for (; cant_fit_in>0; cant_fit_in--)
		{
			if (free_spaces[cant_fit_in] < size)
			{
				cant_fit_in++;
				break;
			}
		}
		int random_x = rand() % free_spaces.size() + cant_fit_in;
		return real_position_orientation(real_position(random_x, (char)random_y+65),(orientation) horizontal);
	}

		int random_x = rand() % 9;
		std::vector<int> free_spaces = find_consecutive_free_spaces(empty_spaces[random_x]);
		while (*free_spaces.end() < size)
		{
			int random_x = rand() % 9;
		}
		int cant_fit_in=free_spaces.size();
		for (; cant_fit_in>0; cant_fit_in--)
		{
			if (free_spaces[cant_fit_in] < size)
			{
				cant_fit_in++;
				break;
			}
		}
		int random_y = rand() % free_spaces.size() + cant_fit_in;
		return real_position_orientation(real_position(random_x, (char)random_y+65),(orientation) horizontal);
	
}

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

void remove_position(real_position_orientation position, std::vector<std::vector<int>> & from)
{
	from[(int)position.first.second-65].erase(from[(int)position.first.second-65].begin() + position.first.first);
}

std::pair<int,int> hit_follow_up(mapa hit_map, int x, int y){
	int counter = 2;
	while (!counter-- && x > 0 && x < hit_map.size())x--;
	counter = 2;
	while (!counter-- && y > 0 && y < hit_map.size())y--;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(hit_map.read(x,y) == 3) return std::pair<int,int> {x,y}; 
		}
	}
	return {};
	
}


std::pair<int,int> rand_hit(mapa hit_map, int x, int y){
	while(true){

		x = rand() % hit_map.size();
		y = rand() % hit_map.size();
		if(!hit_map.read(x,y)) return std::pair<int,int> {x,y};

	}
}
