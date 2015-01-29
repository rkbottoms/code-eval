
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int main(int argc, const char *argv[])
{
    std::string line;
    std::ifstream file(argv[1]);
    while(getline(file, line))
    {
        if(!line.empty())
        {
            int comma = line.find_first_of(",");
            std::string src = line.substr(0, comma);
            //comma+2 to ignore space after comma
            std::string chars = line.substr(comma + 2);
            for(int i = 0; i < chars.length(); i++)
            {
                src.erase(std::remove(src.begin(), src.end(), chars[i]), src.end());
            }
            std::cout << src << std::endl;
        }
    }
    file.close();
}
