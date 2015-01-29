#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream file(argv[1]);
    while (getline(file, line))
    {
        if (!line.empty())
        {
            //split line on colon
            std::string buffer, output;
            std::stringstream stream(line);
            std::vector<std::string> elements;
            //elements will always be a 2 element vector
            while (getline(stream, buffer, ':'))
            {
                elements.push_back(buffer);
            }
            std::stringstream number_stream(elements[0]);
            std::stringstream swap_stream(elements[1]);
            std::vector<std::string> numbers, swap_indices;
            while (getline(number_stream, buffer, ' '))
            {
                numbers.push_back(buffer);
            }
            while (getline(swap_stream, buffer, ','))
            {
                swap_indices.push_back(buffer);
            }
            for (int i = 0; i < swap_indices.size(); i++)
            {
                std::string buffer;
                std::stringstream stream(swap_indices[i]);
                std::vector<int> positions;
                while(getline(stream, buffer, '-'))
                {
                    positions.push_back(stoi(buffer));   
                }
                //positions will always be a 2 element vector
                int a = positions[0];
                int b = positions[1];
                std::swap(numbers[a], numbers[b]);
            }
            for (int j = 0; j < numbers.size(); j++)
            {
                output.append(numbers[j]).append(" ");
            }
            std::cout << output << std::endl;
            
            
        }
    }
    file.close();
    return 0;
}

