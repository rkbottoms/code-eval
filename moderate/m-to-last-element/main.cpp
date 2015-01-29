#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream file(argv[1]);
    while(getline(file, line))
    {
        if(!line.empty());
        {   
            std::vector<std::string> lines;
            std::string buffer; 
            std::stringstream ss(line);
            while (ss >> buffer)
            {
                lines.push_back(buffer);
            }
            int n = std::stoi(lines.back());
            lines.pop_back();
            if (n <= lines.size())
            {
                std::cout << lines[lines.size() - n] << std::endl;    
            }
        }
    }
    file.close();
    return 0;
}