#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>


int main(int argc, char const *argv[])
{
    std::ifstream file(argv[1]);
    std::string line;
    while (getline(file, line))
    {
        if(!line.empty())
        {
            int x = std::stoi(line);
            if ( 0 <= x && x <=2)
            {
                std::cout << "Still in Mama's arms";
            }
            else if (3 <= x && x <= 4)
            {
                std::cout << "Preschool Maniac";
            }
            else if (5 <= x && x <= 11)
            {
                std::cout << "Elementary school";
            }
            else if (12 <= x && x <= 14)
            {
                std::cout << "Middle school";
            }
            else if (15 <= x && x <= 18)
            {
                std::cout << "High school";
            }
            else if (19 <= x && x <= 22)
            {
                std::cout << "College";
            }
            else if (23 <= x && x <= 65)
            {
                std::cout << "Working for the man";
            }
            else if (66 <= x && x <= 100)
            {
                std::cout << "The Golden Years";
            }
            else if (0 > x || x > 100)
            {
                std::cout << "This program is for humans";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}