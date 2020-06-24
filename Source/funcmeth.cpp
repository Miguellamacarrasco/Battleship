#include "communication.h"



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
