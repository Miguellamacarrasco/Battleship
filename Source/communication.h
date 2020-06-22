#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <experimental/filesystem>
#include <fstream>
#include <algorithm>


using position = std::vector<std::vector<int>>; //y<x> 
using real_position = std::pair<int,char>; // x = char, y = int
using orientation = bool; //1 = Horizontal, 0 = Vertical
using position_orientation = std::pair<position, orientation>;
using real_position_orientation = std::pair<real_position, orientation>;

class observer
{
    std::experimental::filesystem::path the_path;
    public:
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
        std::vector<std::string> vector_of_strings;
        while(true) //QuE EfIcIeNtE!!!!1
        {
            auto amount_of_files = std::distance(std::experimental::filesystem::directory_iterator(the_path), std::experimental::filesystem::directory_iterator{});
            if (amount_of_files > 0)
            {
                std::string line;
                vector_of_strings.clear();
                for (auto iterator : std::experimental::filesystem::directory_iterator{the_path})
                {
                    std::ifstream my_file (iterator.path());
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
            }
        }
    } 
};

class writer
{
    std::experimental::filesystem::path the_path;
    std::experimental::filesystem::path the_file;
    int command_counter = 0;
    public: 
    writer(std::string word)
    {
        std::experimental::filesystem::path temp(word);
        the_path = word;
    }
    void write(std::string command)
    {
        the_file.replace_filename(the_path.string() + ((char (command_counter+48)) + ".Comando.out"));
        std::ofstream my_file(the_file);
        if (my_file.is_open())
        {
            my_file << command;
        }
        my_file.close();
        command_counter++;
    }
};

