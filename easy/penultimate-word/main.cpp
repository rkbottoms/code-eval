#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

int main(int argc, const char *argv[])
{
   std::ifstream file(argv[1]);
   std::string line;
   while(getline(file, line))
   {
        if (!line.empty())
        {
            std::stringstream ss(line);
            std::vector<std::string> sentence;
            std::string buffer;
            while(ss >> buffer)
            {
              sentence.push_back(buffer);
            }
            std::cout << sentence[sentence.size() - 2] << std::endl;
        }
   }
   file.close();
   return 0;
}