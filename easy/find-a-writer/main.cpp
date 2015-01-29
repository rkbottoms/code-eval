#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

int main(int argc, char const* argv[])
{
   std::string line;
   std::ifstream file(argv[1]);
   while(getline(file, line))
   {
       if(!line.empty())
       {
           std::vector<int> key; 
           std::stringstream stream(line);
           std::string encoded, clues, buffer, output;
           //split encoded writer's name from clues
           getline(stream, encoded, '|');
           getline(stream, clues, '\n');
           std::stringstream ss(clues);
           while(ss >> buffer)
           {
               key.push_back(std::stoi(buffer));
               
           }
           for(int i = 0; i < key.size(); i++)
           {
               output.push_back(encoded[key[i] - 1]);
           }
           std::cout << output << std::endl;
       }
   }
   file.close();
   return 0;
}
