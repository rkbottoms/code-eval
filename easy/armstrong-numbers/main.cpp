#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>

int main(int argc, char const *argv[])
{
    std::ifstream file(argv[1]);
    std::string line;
    while(getline(file, line))
    {        
        std::vector<int> digits;
        if(!line.empty())
        {   
            int power = line.length();
            for (int i = 0; i < line.size(); i++)
            {
                digits.push_back(line[i] - '0');
            }
            int sum = 0;
            for (int j = 0; j < digits.size(); j++)
            {
                sum += pow(digits[j], power);
            }
            int num = std::stoi(line);
            if (num == sum)
            {
                std::cout  << "True" << std::endl;
            }
            else std::cout << "False" << std::endl;
        }
    }
    file.close();
    return 0;
}
