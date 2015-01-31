#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>

int main(int argc, char const *argv[])
{
   std::ifstream file(argv[1]);
   std::string line;
   std::string buffer;
   int count = 1;
   std::string output = "";
   while(getline(file, line))
   {
        if (line.length() > 0)
        {
            std::stringstream ss(line);
            vector<int> nums;
            while(ss >> buffer)
            {
              nums.push_back(std::stoi(buffer));
            }
            int a = nums[0];
            int b = nums[1];
            int n = nums[2];
            for (int i = 1; i <= n; i++)
            {
                if ((i % a == 0) && (i % b == 0))
                {
                    output.append("FB ");
                }
                else if (i % a == 0)
                {
                    output.append("F ");
                }
                else if (i % b == 0)
                {
                    output.append("B ");
                }
                else 
                {
                    output.append(to_string(i));
                    output.append(" ");
                }
            }
            output.pop_back();
            output.append("\n");
        }
   }
   std::cout << output << std::endl;
   file.close();
   return 0;
}
