#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

std::string str_to_bin(std::vector<std::string> & input)
{
    std::string binary;
    for (int i = 0; i < input.size(); i+=2)
    {
        // flag is 0
        if(input[i].length() == 1)
        {
            //append next sequence of 0's
            binary.append(input[i+1]);
        }
        // flag is 00
        if(input[i].length() == 2)
        {
            //replace next sequence of 0's with 1's and append
            std::replace(input[i+1].begin(), input[i+1].end(), '0', '1');
            binary.append(input[i+1]);
        }
    }
    //truncating leading zeros;
    binary.erase(0, binary.find_first_not_of('0'));
    return binary;
}

size_t bin_to_dec(std::string binary)
{
    size_t decimal = 0;
    int index = 0;
    for (int i = binary.length() - 1; i >= 0; i--)
    {
        decimal += (binary[i] - '0') * pow(2, index);
        index++;
    }
    return decimal;
}

int main(int argc, const char *argv[])
{
    std::string line;
    std::ifstream file(argv[1]);
    while(getline(file, line))
    {
        if(!line.empty())
        {
            std::vector<std::string> input;
            std::string buffer;
            std::stringstream stream(line);
            while (stream >> buffer)
            {
                input.push_back(buffer);
            }
            std::cout << bin_to_dec(str_to_bin(input)) << std::endl;
        }
    }
    file.close();
    return 0;
}
