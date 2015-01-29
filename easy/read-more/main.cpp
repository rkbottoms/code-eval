#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream file(argv[1], std::ifstream::in);
    while(getline(file,line))
    {
        if(!line.empty())
        {
            if(line.length() > 55)
            {
                //trim to 40 characters
                line = line.substr(0, 40);
                //trim past the last space
                int last_character = line.find_last_of(' ');
                line = line.substr(0, last_character);
                line.append("... <Read More>");
            }
            std::cout << line << std::endl;
        }
    }
    return 0;
}