#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <set>

int main(int argc, char const *argv[])
{
    std::ifstream file(argv[1]);
    std::string line;
    while(getline(file, line))
    {
        if (!line.empty())
        {
            std::string output = "";
            std::set<std::string> s;
            std::stringstream stream(line);
            std::string word;
            while(getline(stream, word, ','))
            {
                if(s.insert(word).second)
                {
                    output.append(word).append(",");    
                }
            }
            output.pop_back();
            std::cout << output << std::endl;
        }
    }
    file.close();
    return 0;
}