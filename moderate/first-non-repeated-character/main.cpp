#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

int main(int argc, char const *argv[])
{
    std::ifstream file(argv[1]);
    std::string line;
    while (getline(file, line))
    {
        if (!line.empty())
        {
            std::unordered_map<char, int> strings;
            std::vector<char> insertOrder;
            for (int i = 0; i < line.length(); i++)
            {
                if(!(isspace(line[i])))
                {
                    insertOrder.push_back(line[i]);
                    bool inserted = strings.emplace(line[i], 1).second;
                    if(!inserted)
                    {
                        strings.at(line[i]) = strings.at(line[i]) + 1;
                    }
                }
            }
            for (auto &itr : insertOrder)
            {
                if(strings.at(itr) == 1)
                {
                    std::cout << itr << std::endl;
                    break;
                }
            }
        }
    }
    file.close();
    return 0;
}