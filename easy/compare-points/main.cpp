#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

int main(int argc, const char *argv[])
{
    std::string line;
    std::ifstream file(argv[1]);
    while(getline(file, line))
    {
        if(!line.empty())
        {
            std::vector<int> coordinates;
            std::stringstream stream(line);
            std::string buffer;
            while(stream >> buffer)
            {
                coordinates.push_back(std::stoi(buffer));    
            }
            int o = coordinates[0];
            int p = coordinates[1];
            int q = coordinates[2];
            int r = coordinates[3];
            int deltaX = q - o;
            int deltaY = r - p;
            
            if(deltaX > 0 && deltaY > 0) {std::cout << "NE" << std::endl;}
            else if(deltaX < 0 && deltaY > 0) {std::cout << "NW" << std::endl;}
            else if(deltaX < 0 && deltaY < 0) {std::cout << "SW" << std::endl;}
            else if(deltaX > 0 && deltaY < 0) {std::cout << "NW" << std::endl;}
            else if(deltaX == 0 && deltaY > 0) {std::cout << "N" << std::endl;}
            else if(deltaX == 0 && deltaY > 0) {std::cout << "N" << std::endl;}
            else if(deltaX < 0 && deltaY == 0) {std::cout << "W" << std::endl;}
            else if(deltaX == 0 && deltaY < 0) {std::cout << "S" << std::endl;}
            else if(deltaX > 0 && deltaY == 0) {std::cout << "E" << std::endl;}
            else {std::cout << "here" << std::endl;}
        }
    }
    file.close();
    return 0;
}
