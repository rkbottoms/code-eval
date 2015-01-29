#include <iostream>
#include <fstream>
#include <string>

int main (int argc, const char *argv[])
{
    std::ifstream file(argv[1]);
    std::string line;
    while (getline(file, line))
    {
        if (!line.empty())
        {
            int commaPosition = line.find_first_of(",");
            std::string str = line.substr(0, commaPosition);
            std::string c = line.substr(commaPosition + 1, line.length());
            int last = str.find_last_of(c);
            std::cout << last << std::endl;
        }
    }
    file.close();
    return 0;
}
