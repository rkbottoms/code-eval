#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
;
int main (int argc, const char *argv[])
{
    std::ifstream file(argv[1]);
    std::string line;
    while (getline(file, line))
    {
        if (!line.empty())
        {
            for(int i = 0; i < line.length(); i++)
            {
                if(isupper(line[i]))
                {
                    line[i] = tolower(line[i]);
                }
                else
                {
                    line[i] = toupper(line[i]);
                }
            }
            std::cout << line << std::endl;
        }
    }
    file.close();
    return 0;
}