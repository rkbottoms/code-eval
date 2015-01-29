#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <sstream>
#include <cmath>

int main(int argc, const char *argv[]) 
{
    std::ifstream file(argv[1]);
    std::string line;
    char chars_to_remove[] = "(),";
    while (getline(file, line)) 
    {
        if(!line.empty())
        {
            //removing parentheses and commas
            for (int i = 0; i < strlen(chars_to_remove); i++) 
            {
                line.erase(
                    std::remove(line.begin(), line.end(), chars_to_remove[i]),
                    line.end()
                    );
            }
            std::stringstream stream(line);
            std::string buffer;
            std::vector<int> nums;
            while (stream >> buffer)
            {
                nums.push_back(stoi(buffer));
            }
            std::cout << sqrt( pow(nums[0] - nums[2], 2) + pow(nums[1] - nums[3], 2) ) << std::endl;
        }
    }
    file.close();
    return 0;
} 
