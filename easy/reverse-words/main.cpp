#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

int main (int argc, const char *argv[])
{
    std::ifstream file(argv[1]);
    std::string line;
    while (getline(file, line))
    {
        if (!line.empty())
        {
            std::vector<std::string> words;
            std::string buffer;
            std::stringstream ss(line);
            while (ss >> buffer)
            {
                words.push_back(buffer);
            }
            for (auto itr = words.rbegin(); itr != words.rend(); ++itr)
            {
                std::cout << *itr << " ";
            }
            std::cout << std::endl;
        }
    }
    file.close();
    return 0;
}