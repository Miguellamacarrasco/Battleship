#ifndef HEAD_H
#define HEAD_H

#include "communication.h"
int find_consecutive_free_spaces(std::vector<int> vect);
std::pair<std::pair<int,char>,bool> generate_ship_coords(std::vector<std::vector<int>> empty_spaces, int size);
void set_ship_coordinates(std::pair<int, char> *positions, int x, char y, bool &horizontal, int size);
void remove_position(real_position_orientation ship_coords, std::vector<std::vector<int>> & free_spaces);

class ship
{
	public:
	/*Como no siempre vamos a saber el tamaño de la nave o su horientacion 
	tiene mas sentido que manejemos su pocision como una lista de coordenadas*/
	std::pair<int, char> * positions;
	std::pair<int, char> * hitted_positions;
	int size;
	bool horizontal;
	//F significa que no se conoze el tipo de nave (lo usaremos para naves enemigas)
	char boat_class = 'F';
	public:
	int size_of()
	{
		return size;
	}
};

class Aircraft_carrier : public ship 
{
	public:
	//Este constructor debe ser usado SOLAMENTE con nuestras naves
	Aircraft_carrier(int x, char y, bool horizontal)
	{
		boat_class = 'A';
		horizontal = horizontal;
		size = 4;
		positions = new std::pair<int, char>[4];
		set_ship_coordinates(positions, x, y, horizontal, 4);
	}
	Aircraft_carrier(std::pair<int, char> position, bool _horizontal)
	{
		boat_class = 'A';
		horizontal = _horizontal;
		size = 4;
		positions = new std::pair<int, char>[4];
		set_ship_coordinates(positions, position.first, position.second, horizontal, 4);
	}
};

class Battlecruiser : public ship
{
	public: 
	//Este constructor debe ser usado SOLAMENTE con nuestras naves
	Battlecruiser(int x, char y, bool _horizontal)
	{
		boat_class = 'B';
		horizontal = _horizontal;
		size = 3;
		positions = new std::pair<int,char>[3];
		set_ship_coordinates(positions, x, y, horizontal, 3);
	}
};

class Submarine : public ship
{
	public: 
	//Este constructor debe ser usado SOLAMENTE con nuestras naves
	Submarine(int x, char y, bool _horizontal)
	{
		boat_class = 'S';
		horizontal = _horizontal;
		size = 2;
		positions = new std::pair<int,char>[2];
		set_ship_coordinates(positions, x, y, horizontal, 2);
	}
};

class Torpedo_boat : public ship
{
	public: 
	//Este constructor debe ser usado SOLAMENTE con nuestras naves
	Torpedo_boat(int x, char y, bool _horizontal)
	{
		boat_class = 'T';
		horizontal = _horizontal;
		size = 1;
		positions = new std::pair<int,char>[1];
		set_ship_coordinates(positions, x, y, horizontal, 1);
	}
};


class player_self
{
	public:
	std::map<std::string, ship> fleet; 
	std::string token;
	void set_ship(std::string name,std::string type, int x, int y, bool Horizontal)
	{
		
			if (type == "Aircraft_carrier")
			{
				Aircraft_carrier Aircraft_carrier_OBJ(x, y, Horizontal);
				fleet.insert(std::pair<std::string, ship>(name,Aircraft_carrier_OBJ));
			}
			if (type == "Battlecruiser")
			{
				Battlecruiser Battlecruiser_OBJ(x, y, Horizontal);
				fleet.insert(std::pair<std::string, ship>(name,Battlecruiser_OBJ));
			}
			if (type == "Submarine")
			{
				Submarine Submarine_OBJ(x, y, Horizontal);
				fleet.insert(std::pair<std::string, ship>(name, Submarine_OBJ));
			}
			if (type == "Torpedo Boat")
			{
				Torpedo_boat Torpedo_boat_OBJ(x, y, Horizontal);
				fleet.insert(std::pair<std::string, ship>(name,Torpedo_boat_OBJ));
			}	
		
	}
	ship get_ship(std::string name)
	{
		return fleet[name];
	}

};

std::pair<std::pair<int, int>, bool> generate_ship_coords(player_self player, int size)
{
	
	bool flag = true;
	int random_x;
	int random_y;
	int horizontal;
    random_x = rand() % 11;
    random_y = rand() % 11;
	std::map<std::string, ship>::iterator it;
	for (it = player.fleet.begin(); it != player.fleet.end(); it++)
	{
		for (int i = 0; i < it->second.size; i++)
		{
			if (it->second.positions[i].first == random_x || it->second.positions[i].first == (char) (random_y + 97)) return generate_ship_coords(player, size);
		}
	}
	return std::pair<std::pair<int, int>, bool> (std::pair<int, int>(random_x, random_y), (bool) horizontal);
}



#endif