#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>

int main(int argc, char const *argv[])
{
    //file input
    std::string line;
    std::ifstream file(argv[1]);
    while(getline(file, line))
    {
        
        if(!line.empty())
        {
            std::string output, buffer;
            std::stringstream stream(line);
            std::vector<int> route;
            //add starting point at position 0
            route.push_back(0);
            //separate cities and distances by space character (' ')
            while(stream >> buffer)
            {
                //finding index of comma
                int commaPosition = buffer.find_first_of(",");
                //splitting up cities and distances at the commaPosition
                std::string name = buffer.substr(0, commaPosition);
                //buffer.length() - 2 because we ignore the semicolon
                //at the end
                int distance = std::stoi(buffer.substr(commaPosition + 1, buffer.length() - commaPosition - 2));
                route.push_back(distance);
            }
            //sort distances in ascending order
            std::sort(route.begin(), route.end());
            for(int i = 0; i < route.size() - 1; i++)
            {
                output.append(std::to_string(route[i+1] - route[i]));
                if(i != route.size() - 2)
                {
                    output.append(",");
                }
            }
            std::cout << output << std::endl;
        }
    }
    file.close();
    return 0;
}