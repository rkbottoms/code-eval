#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>

int main(int argc, const char *argv[])
{
    std::string line;
    std::ifstream file(argv[1]);
    while(getline(file, line))
    {
        if(!line.empty())
        {
            line.resize(std::distance(line.begin(), std::unique(line.begin(), line.end())));
            std::cout << line << std::endl;
        }
    }
    file.close();
}

