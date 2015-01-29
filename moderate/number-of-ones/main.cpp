#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <bitset>

int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream file(argv[1]);
    while(getline(file, line))
    {
        if (!line.empty())
        {
            std::bitset<32> num(std::stoi(line));
            int count = 0;
            for (int i = 0; i < num.size(); i++)
            {
                if(num[i] == 1) {count++;}
            }
            std::cout << count << std::endl;
        }
    }
    file.close();
    return 0;
}