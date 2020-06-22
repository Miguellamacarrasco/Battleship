#ifndef HEAD_H
#define HEAD_H

#include "communication.h"
int find_consecutive_free_spaces(std::vector<int> vect);
std::pair<std::pair<int,char>,bool> generate_ship_coords(std::vector<std::vector<int>> empty_spaces, int size);
void set_ship_coordinates(std::pair<int, char> *positions, int x, char y, bool &horizontal, int size);
void remove_position(real_position_orientation ship_coords, std::vector<std::vector<int>> & free_spaces);

class ship
{
	protected:
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

class Aircraft_carrier : ship 
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

class Battlecruiser : ship
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

class Submarine : ship
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

class Torpedo_boat : ship
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



#endif