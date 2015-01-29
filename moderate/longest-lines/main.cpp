#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


bool compareLength(const std::string & s1, const std::string & s2)
{
    return ( s1.length() > s2.length() );
}

int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream file(argv[1]);
    int n;
    getline(file, line);
    n = std::stoi(line);
    std::vector<std::string> lines;
    while(getline(file, line))
    {
        if(!line.empty())
        {
            lines.push_back(line);    
        }
    }
    std::sort(lines.begin(), lines.end(), compareLength);
    for (int i = 0; i < n; i++)
    {
        std::cout << lines[i] << std::endl;
    }
    file.close();
    return 0;
}