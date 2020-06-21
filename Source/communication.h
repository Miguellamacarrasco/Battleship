#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <experimental/filesystem>
#include <fstream>

class observer
{
    std::filesystem::path the_path;
    public:
    observer()
    {

    }
    observer(std::string word)
    {
        std::filesystem::path temp(word);
        if (!std::filesystem::exists(temp))
        {
            std::filesystem::create_directory(temp);
        }
        the_path = temp;
    }
    void execute()
    {
        std::error_code e;
        while(true) //QuE EfIcIeNtE!!!!1
        {
            auto amount_of_files = std::distance(std::filesystem::directory_iterator(the_path), std::filesystem::directory_iterator{});
            if (amount_of_files > 0)
            {
                std::string line;
                std::vector<std::string> vector_of_strings;
                for (auto iterator : std::filesystem::directory_iterator{the_path})
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
                    std::filesystem::remove(iterator.path(),e);
                    if (e)
                    {
                        std::cerr << e.message() << '\n';
                    }
                }
            }
        }
    } 
};

