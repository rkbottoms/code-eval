#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main (int argc, const char *argv[])
{
    std::string line;
    std::ifstream file(argv[1]);
    while (getline(file, line))
    {
        if (!line.empty())
        {
            int commaPosition = line.find_first_of(",");
            int n = std::stoi(line.substr(0, commaPosition));
            int m = std::stoi(line.substr(commaPosition + 1, line.length() - 1));
            while ( n >= m)
            {
                n -= m;
            }
            std::cout << n << std::endl;
        }
    }
    file.close();
    return 0;
}