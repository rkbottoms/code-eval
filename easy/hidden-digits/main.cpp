#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>

int main(int argc, char const *argv[])
{
    std::ifstream file(argv[1]);
    std::string line;
    while(getline(file, line))
    {
        if (!line.empty())
        {
            int count = 0;
            for (int i = 0; i < line.length(); i++)
            {
                if( isalpha(line[i]) && islower(line[i]) && (line[i] - 'a' < 10))
                {
                    std::cout << line[i] - 'a';
                    count++;
                }
                else if (isdigit(line[i]))
                {
                    std::cout << line[i];
                    count++;
                }
            }
            if (count == 0)
            {
                std::cout << "NONE";
            }
            std::cout << std::endl;
        }
    }
    file.close();
    return 0;
}