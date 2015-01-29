#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

int main(int argc, char const *argv[])
{
   std::ifstream file(argv[1]);
   std::string line;
   std::cout << std::setprecision(3);
   std::cout << std::fixed;
   while(getline(file, line))
   {
        std::string buffer;
        if (!line.empty())
        {
            std::stringstream stream(line);
            std::vector<double> nums;
            while(stream >> buffer)
            {
                nums.push_back(std::stof(buffer));
            }
            std::sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size(); i++)
            {
                std::cout << nums[i] << " ";
            }
        }
        std::cout << std::endl;
        
    }
    file.close();
    return 0;
}
