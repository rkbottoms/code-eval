#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <cctype>

int main(int argc, char const *argv[])
{
    //file input
    std::ifstream file(argv[1]);
    std::string line;
    while (getline(file, line))
    {
        std::string output;
        if (line.length() > 0)
        {
            //splitting each up each line by comma to insert into container
            std::string token;
            std::stringstream stream(line);
            //map to keep track of numbers and how many times they occur
            //within a line
            std::map<std::string, int> strings;
            int numberOfElementsPerLine = 0;
            while (getline(stream, token, ','))
            {
                if (token != " ")
                {
                    //if the number is already in the table, increment its number
                    //of occurrences
                    //emplace returns a pair that contains an interator to the 
                    //position of the number in the table and a boolean value
                    //reflecting if the number exists in the table or not
                    bool inserted = strings.emplace(token,1).second;
                    if(!inserted)
                    {
                        strings.at(token) = strings.at(token) + 1;
                    }
                }
                numberOfElementsPerLine++;
            }
            double threshold = numberOfElementsPerLine / 2;
            for (auto const &itr : strings)
            {
                
                if (itr.second > threshold)
                {
                    output.append(itr.first);
                    break;
                }
            }
        }
        if (output.length() > 0)
        {
            std::cout << output << std::endl;
        }
        else
        {
            std::cout << "None" << std::endl;
        }
    }
    file.close();
    return 0;
}