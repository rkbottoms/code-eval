#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>

//horrible exception hackery
bool isInteger(const std::string & s)
{
    try 
    {
            std::stoi(s);
            return true;
    }
    catch (std::invalid_argument &ia)
    {
        return false;
    }
        
}
int main(int argc, char const* argv[])
{
   std::string line;
   std::ifstream file(argv[1]);
   while(getline(file, line))
   {
       if(!line.empty())
       {
           std::string buffer, output;
           std::vector<std::string> elements, words, digits;
           std::stringstream stream(line);
           while (getline(stream, buffer, ','))
           {
               if(isInteger(buffer))
               {
                   digits.push_back(buffer);
               }
               else
               {
                   words.push_back(buffer);
               }
           }
           if(words.size() > 0)
           {
                //output words
               for (int i = 0; i < words.size(); i++)
               {
                   output.append(words[i]);
                   if (i != words.size() - 1)
                   {
                       output.append(",");
                   }
               }       
           }
           if(words.size() > 0 && digits.size() > 0)
           {
               output.append("|");
           }
           if(digits.size() > 0)
           {
               //output digits
               for(int i = 0; i < digits.size(); i++)
               {
                   output.append(digits[i]);
                   if (i != digits.size() - 1)
                   {
                       output.append(",");
                   }
               }
           }
           std::cout << output << std::endl;
       }
   }
   file.close();
   return 0;
}
