#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <set>

int main(int argc, char const* argv[])
{
   std::string line;
   std::ifstream file(argv[1]);
   while(getline(file, line))
   {
       if(!line.empty())
       {
           std::stringstream stream(line);
           std::string buffer;
           getline(stream, buffer, ';');
           std::set<int> numbers;
           while(getline(stream, buffer, ','))
           {
               bool inserted = numbers.insert(std::stoi(buffer)).second;
               if (!inserted)
               {
                   std::cout << buffer << std::endl;
                   break;
               }
           }
           
       }
   }
   return 0;
}