#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <experimental/filesystem>
#include <fstream>
#include <algorithm>
#include <functional>
#include <utility>

using position = std::vector<std::vector<int>>; //y<x> 
using real_position = std::pair<int,char>; // x = char, y = int
using orientation = bool; //1 = Horizontal, 0 = Vertical
using position_orientation = std::pair<position, orientation>;
using real_position_orientation = std::pair<real_position, orientation>;


class mapa
{
	position positions = {};
	std::function<std::pair<int,int> (mapa,int,int)> next_move;
	public:

	void hit(int x, int y)  
	{
		positions[y][x] = 2;
	}
	//or
	void miss(int x, int y)
	{
		positions[y][x] = 1;
	}
	void label_suspected_ship(int x, int y) 
	{
		positions[y][x] = 3;
	} 
	int read(int x, int y)
	{
		return positions[y][x];
	}
	int size(){
		return 10;
	}
};

class observer
{
    std::experimental::filesystem::path the_path;
    public:
    std::vector<std::string> vector_of_strings;
    observer()
    {

    }
    observer(std::string word)
    {
        std::experimental::filesystem::path temp(word);
        if (!std::experimental::filesystem::exists(temp))
        {
            std::experimental::filesystem::create_directory(temp);
        }
        the_path = temp;
    }
    void execute()
    {
        std::error_code e;
        vector_of_strings.clear();
        while(true) //QuE EfIcIeNtE!!!!1
        {
            auto amount_of_files = std::distance(std::experimental::filesystem::directory_iterator(the_path), std::experimental::filesystem::directory_iterator{});
            if (amount_of_files > 0)
            {
                std::string line;
                vector_of_strings.clear();
                for (auto iterator : std::experimental::filesystem::directory_iterator{the_path})
                {
                    std::ifstream my_file;
                    my_file.open(iterator.path(), std::ifstream::in);
                    if (my_file.is_open())
                    {
                        while (getline(my_file, line))
                        {
                            vector_of_strings.push_back(line);
                        }
                    }
                    my_file.close();
                    std::experimental::filesystem::remove(iterator.path(),e);
                    if (e)
                    {
                        std::cerr << e.message() << '\n';
                    }
                }
                 break;
            }
  
        }
    } 
};

class writer
{
    std::string path;
    int command_counter = 0;
    public: 
    writer(std::string word)
    {
        path = word;
    }
    void write(std::string command)
    {
        std::ofstream my_file(path);
        my_file << command;
        my_file.close();
        command_counter++;
    }
};

