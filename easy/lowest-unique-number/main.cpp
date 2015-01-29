#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
    std::ifstream file;
    std::string line;
    file.open(argv[1]);
    while (getline(file, line))
    {
        if (!line.empty())
        {
            std::string buffer;
            std::stringstream ss(line);
            //string, bool pair corresponds to an string and whether is it unique
            // true -> unique, false -> not unique
            std::map<std::string, bool> myMap;
            //keep track of the insertOrder
            std::vector<std::string> insertOrder;
            while (ss >> buffer)
            {
                insertOrder.push_back(buffer);
                bool inserted = myMap.emplace(buffer, true).second;
                if(!inserted)
                {
                    myMap.at(buffer) = false;
                }
            }
            bool exists = false;
            for (auto &itr : myMap)
            {
                if(itr.second)
                {
                    int pos = find(insertOrder.begin(), insertOrder.end(), itr.first) - insertOrder.begin();
                    std::cout << pos + 1 << std::endl;
                    exists = true;
                    break;
                }
            }
            if (!exists)
            {
                std::cout << 0 << std::endl;
            }
        }
    }
    file.close();
    return 0;
}