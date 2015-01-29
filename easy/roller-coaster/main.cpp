#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

int main(int argc, const char *argv[])
{
    std::string line;
    std::ifstream file(argv[1]);
    while(getline(file, line))
    {
        int count = 0;
        for(int i = 0; i < line.length(); i++)
        {
            if(isalpha(line[i]))
            {
                count++;
                //even
                if(count % 2)
                {
                    line[i] = toupper(line[i]);
                }
                //odd
                else
                {
                    line[i] = tolower(line[i]);
                }
            }
        }
        std::cout << line << std::endl;
    }
    file.close();
}
