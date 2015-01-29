#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <list>
#include <algorithm>

std::vector<std::string> splitWords(std::string & str)
{
    std::stringstream stream(str);
    std::string buffer;
    std::vector<std::string> temp;
    while (stream >> buffer)
    {
        temp.push_back(buffer);
    }
    return temp;
}
std::vector<int> splitNumbers(std::string & str)
{
    std::stringstream stream(str);
    std::string buffer;
    std::vector<int> temp;
    while (stream >> buffer)
    {
        temp.push_back(atoi(buffer.c_str()));
    }
    return temp;
}

int find_missing_index(const std::vector<int> & numbers, int range)
{
    for(int i = 1; i <= range; i++)
    {
        if(std::find(numbers.begin(), numbers.end(), i) == numbers.end())
        {
            return i;
        }
    }
    return -1;
}
int main(int argc, char const* argv[])
{
   std::string line;
   std::ifstream file(argv[1]);
   while(getline(file, line))
   {
       if(!line.empty())
       {
           std::string words, sequence;
           std::stringstream stream(line);
           //splitting up words and sequence of numbers
           getline(stream, words, ';');
           getline(stream, sequence, '\n');
           //splitting into arrays of elements
           std::vector<std::string> shuffled = splitWords(words);
           std::vector<int> numbers = splitNumbers(sequence);
           //associating each word with correct index
           std::map<int, std::string> message;
           for(int i = 0; i < numbers.size(); i++)
           {
               message.insert(std::pair<int, std::string>(numbers[i], shuffled[i]));
           }
           //finding missing index and adding to map
           //the word with the missing index will always
           //be the last word in the shuffled vector
           int missing_index = find_missing_index(numbers, shuffled.size());
           message.insert(std::pair<int, std::string>(missing_index, shuffled.back()));
           for (const auto & itr : message)
           {
               std::cout << itr.second << " ";
           }
           std::cout << std::endl;
       }
   }
   file.close();
   return 0;
}
