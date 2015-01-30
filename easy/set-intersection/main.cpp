#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>

std::set<int> split_list(std::string str)
{
    std::stringstream stream(str);
    std::string buffer;
    std::set<int> s;
    while(getline(stream, buffer, ','))
    {
        s.insert(std::stoi(buffer));
    }
    return s;
    
}
int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream file(argv[1]);
    while(getline(file, line))
    {
        if(!line.empty())
        {
            std::stringstream stream(line);
            std::string first_list, second_list;
            getline(stream, first_list, ';');
            getline(stream, second_list);
            std::set<int> first = split_list(first_list);
            std::set<int> second = split_list(second_list);
            std::vector<int> intersection;
            std::set_intersection(
                first.begin(), 
                first.end(), 
                second.begin(), 
                second.end(), 
                std::back_inserter(intersection)
                );
            if(!intersection.empty())
            {
                for(int i = 0; i < intersection.size(); i++)
                {
                    std::cout << intersection[i];
                    if(i < intersection.size() - 1)
                    {
                        std::cout << ",";
                    }
                }
            }
            std::cout <<  std::endl;
        }
    }
    file.close();
    return 0;
}
