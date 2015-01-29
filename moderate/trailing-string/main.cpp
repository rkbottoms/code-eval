#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

int main(int argc, const char *argv[])
{
    std::string line;
    std::ifstream file(argv[1]);
    while(getline(file, line))
    {
        if(!line.empty())
        {
            std::vector<std::string> words;
            std::stringstream stream(line);
            std::string buffer;
            while(getline(stream, buffer, ','))
            {
                words.push_back(buffer);
            }
            if(words[1].size() > words[0].size())
            {
                std::cout << false << std::endl;
            }
            else
            {
                std::string temp = words[0].substr(words[0].size() - words[1].size(), words[1].size());
                std::cout << (temp == words[1]) << std::endl;
                
            }
        }
    }
}
