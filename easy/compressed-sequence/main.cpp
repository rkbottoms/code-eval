#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

int main(int argc, char const *argv[])
{
   std::string line;
   //opening file
   std::ifstream file(argv[1]);
   while(getline(file, line))
   {    
       if(!line.empty())
       {
           std::string buffer, output;
           std::vector<std::string> sequence;
           std::stringstream stream(line);
           //putting elements of line into array
           while(stream >> buffer)
           {
               sequence.push_back(buffer);
           }
           //current integer to compress
           std::string current = sequence[0];
           int currentCount = 0;
           for(int i = 0; i < sequence.size(); i++)
           {
               //next integer in sequence matches the current
               std::string next = sequence[i];
               if(current == next)
               {
                   currentCount++;
                   continue;
               }
               //next integer in sequence does not match the current
               //change current integer
               //set count to 1
               else
               {
                   output.append(std::to_string(currentCount).append(" ").append(current).append(" "));
                   current = sequence[i];
                   currentCount = 1;
               }
           }
           //output last compressed integer
           output.append(std::to_string(currentCount).append(" ").append(current).append(" "));
           std::cout << output << std::endl;
       }
   }
   file.close();
   return 0;
}
