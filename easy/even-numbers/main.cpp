#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
int main (int argc, char const *argv[])
{
    std::ifstream file(argv[1]);
    std::string line;
    while (getline(file, line))
    {
        if (!line.empty())
        {
            int n = std::stoi(line);
            if (n % 2 == 0)
            {
                std::cout << true << std::endl;
            }
            else std::cout << false << std::endl;
        }
    }
    file.close();
    return 0;
}
