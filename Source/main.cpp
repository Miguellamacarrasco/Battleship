#include "head.h"

void create_ship(std::string type, player_self & player, int size, std::vector<std::string> nombres)
{
	std::pair<std::pair<int, int>, bool> coordenadas = generate_ship_coords(player, size);
	int random_name = rand() % nombres.size();
	std::map<std::string, ship>::iterator it;
	player.set_ship(nombres[random_name], type, coordenadas.first.first, (char) coordenadas.first.second + 'A', coordenadas.second);
	nombres[random_name].erase();

}

int main()
{
	srand (time(0));
	player_self player_1;
	std::vector<std::string> nombres = {"BAP Almirante Grau", "BAP Coronel Bolognesi", "BAP Villar", "BAP García y García", "BAP Colonel Bolognesi", "BAP Castilla", "BAP Guise", "BAP Teniente Palacios", "BAP Carvajal", "BAP Montero", "BAP Mariátegui", "BAP San Lorenzo"};
	for (int i = 0; i< 5; i++)
	{
		create_ship("Torpedo Boat", player_1, 1, nombres);

	}
	std::cout << player_1.fleet.begin()->first;
	for (int i = 0; i < 4; i++)
	{
		create_ship("Submarine", player_1, 2, nombres);
	}
	for (int i = 0; i < 3; i++)
	{
		create_ship("Battlecruiser", player_1, 3, nombres);
	}
	create_ship("Aircraft_carrier", player_1, 4, nombres);
	
	return 0;
}
