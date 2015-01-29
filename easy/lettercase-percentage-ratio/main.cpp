#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main(int argc, const char *argv[])
{   
    std::ifstream file(argv[1]);
    std::string line = "";
    while(getline(file, line))
    {
        if (!line.empty())
        {
            double numLower = 0;
            double numUpper = 0;
            for(int i = 0; i < line.size(); i++)
            {
                if (isupper(line[i]))
                {
                    numUpper++;
                }
                else if(islower(line[i]))
                {
                    numLower++;
                }
            }
            double lower = ( numLower / (line.length()) ) * 100;
            double upper = ( numUpper / (line.length()) ) * 100;
            std::cout << std::setprecision(2);
            std::cout << std::fixed;
            std::cout << "lowercase: " << lower << " uppercase: " << upper << std::endl;
        }
    }
    file.close();
    return 0;
}
