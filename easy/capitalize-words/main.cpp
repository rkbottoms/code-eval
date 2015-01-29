#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

int main (int argc, char const *argv[])
{
    std::ifstream file(argv[1]);
    std::string line;
    while (getline(file, line))
    {
        
        if (!line.empty())
        {
            std::string buffer;
            std::vector<std::string> words;
            std::stringstream ss(line);
            while (ss >> buffer)
            {
                words.push_back(buffer);
            }
            for (auto &x : words)
            {
                if (islower(x[0]))
                {
                    x[0] = toupper(x[0]);
                }
                std::cout << x << " ";
            }
            std::cout << std::endl;
        }
    }
}