#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string line;
    std::string output;
    std::ifstream file(argv[1]);
    while (getline(file, line))
    {
        if (!line.empty())
        {
            line = "0x" + line;
            int value = std::stoi(line, 0, 16);
            output.append(std::to_string(value));
            output.append("\n");
        }
    }
    std::cout << output << std::endl;
    file.close();
    return 0;
}