#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


int main (int argc, char const *argv[])
{
    std::ifstream file(argv[1]);
    std::string line;
    while (getline(file, line))
    {
        int sum = 0;
        std::vector<std::string> words;
        if (!line.empty())
        {
            for (int i = 0; i < line.length(); i++)
            {
                int x = line[i] - '0';
                sum +=x;
            }
        }
        std::cout << sum << std::endl;
    }
    file.close();
    return 0;
}