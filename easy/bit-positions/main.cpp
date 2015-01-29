#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream file(argv[1]);
    while (getline(file, line)) 
    {
        int n, p1, p2;
        if (!line.empty())
        {
            //reading n
            int commaPosition = line.find_first_of(",");
            std::string temp = line.substr(0, commaPosition);
            n = std::stoi(temp);
            line = line.substr(commaPosition + 1, line.length() - temp.length() - 1);
            //reading p1
            commaPosition = line.find_first_of(",");
            temp = line.substr(0, commaPosition);
            //p1 is 1 based so subtract 1 to make zero based
            p1 = std::stoi(temp) - 1;
            line = line.substr(commaPosition + 1, line.length() - temp.length() - 1);
            //reading p2
            commaPosition = line.find_first_of(",");
            temp = line.substr(0, commaPosition);
            //p2 is 1 based so subtract 1 to make zero based
            p2 = std::stoi(temp) - 1;
            bool match;
            if((n >> p1 & 1) == (n >> p2 & 1))
            {
                std::cout << "true" << std::endl;
            }
            else std::cout << "false" << std::endl;
        }
    }
}