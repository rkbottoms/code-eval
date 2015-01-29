#include <iostream>
#include <fstream>
#include <string>

std::string to_binary(const std::string & str)
{
    if (str == "0") {return str;}
    int n = stoi(str);
    std::string binary;
    while ( n != 0)
    {
        binary.insert(0, std::to_string(n % 2));
        n >>= 1;
    }
    return binary;
}
int main(int argc, const char *argv[])
{
    std::string line;
    std::ifstream file(argv[1]);
    while(getline(file, line))
    {
        if(!line.empty())
        {
            std::cout << to_binary(line) << std::endl;
        }
    }
    file.close();
    return 0;
}
