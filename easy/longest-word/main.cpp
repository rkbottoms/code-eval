#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

int main(int argc, char const *argv[])
{
   std::ifstream file(argv[1]);
   std::string line;
   std::string buffer;
   while(getline(file, line))
   {
        if (!line.empty())
        {
            std::stringstream ss(line);
            std::vector<std::string> sentence;
            while(ss >> buffer)
            {
              sentence.push_back(buffer);
            }
            int max = 0;
            int maxIndex = 0;
            for (int i = 0; i < sentence.size(); i++)
            {
                if (max < sentence[i].size())
                {
                    max = sentence[i].size();
                    maxIndex = i;
                }
            }
            std::cout << sentence[maxIndex] << std::endl;
        }
   }
   file.close();
   return 0;
}
