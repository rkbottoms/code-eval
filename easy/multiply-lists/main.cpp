#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <string>


std::vector<int> convertLineToVector(std::stringstream & stream, std::string & buffer, std::vector<int> & array)
{
    while(stream >> buffer)
    {
        array.push_back(atoi(buffer.c_str()));
    }
    return array;
}
int main(int argc, char const *argv[])
{
    //file input
    std::string line;
    std::ifstream file(argv[1]);
    while(getline(file, line))
    {
        if(!line.empty())
        {
            int barPosition = line.find_first_of("|");
            std::string firstPart = line.substr(0, barPosition);
            std::string secondPart = line.substr(barPosition + 2);
            std::vector<int> first, second;
            std::string buffer;
            std::stringstream firstStream(firstPart);
            std::stringstream secondStream(secondPart);
            first = convertLineToVector(firstStream, buffer, first);
            second = convertLineToVector(secondStream, buffer, second);
            for(int i = 0; i < first.size(); i++)
            {
                std::cout << first[i] * second[i] << " ";
            }
        }
        std::cout << std::endl;
    }
    file.close();
    return 0;
}