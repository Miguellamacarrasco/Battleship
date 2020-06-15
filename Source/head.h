#pragma once
#include "funcmeth.cpp"
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
	ship();
	int size_of()
	{
		return size;
	}
};

class Aircraft_carrier : ship 
{
	public:
	//Hola 
	//Este constructor debe ser usado SOLAMENTE con nuestras naves
	Aircraft_carrier(int x, char y, bool horizontal)
	{
		ship::boat_class = 'A';
		ship::horizontal = horizontal;
		ship::size = 4;
		ship::positions = new std::pair<int, char>[4];
		set_ship_coordinates(ship::positions, x, y, horizontal, 4);
	}
	Aircraft_carrier(std::pair<int, char> position, bool horizontal)
	{
		ship::boat_class = 'A';
		ship::horizontal = horizontal;
		ship::size = 4;
		ship::positions = new std::pair<int, char>[4];
		set_ship_coordinates(ship::positions, position.first, position.second, horizontal, 4);
	}
};

class Battlecruiser : ship
{
	public: 
	//Este constructor debe ser usado SOLAMENTE con nuestras naves
	Battlecruiser(int x, char y, bool horizontal)
	{
		ship::boat_class = 'B';
		ship::horizontal = horizontal;
		ship::size = 3;
		ship::positions = new std::pair<int,char>[3];
		set_ship_coordinates(ship::positions, x, y, horizontal, 3);
	}
};

class Submarine : ship
{
	public: 
	//Este constructor debe ser usado SOLAMENTE con nuestras naves
	Submarine(int x, char y, bool horizontal)
	{
		ship::boat_class = 'S';
		ship::horizontal = horizontal;
		ship::size = 2;
		ship::positions = new std::pair<int,char>[2];
		set_ship_coordinates(ship::positions, x, y, horizontal, 2);
	}
};

class Torpedo_boat : ship
{
	public: 
	//Este constructor debe ser usado SOLAMENTE con nuestras naves
	Torpedo_boat(int x, char y, bool horizontal)
	{
		ship::boat_class = 'T';
		ship::horizontal = horizontal;
		ship::size = 1;
		ship::positions = new std::pair<int,char>[1];
		set_ship_coordinates(ship::positions, x, y, horizontal, 1);
	}
};



