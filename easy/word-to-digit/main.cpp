#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(int argc, char const *argv[])
{
    std::ifstream file(argv[1]);
    std::string line;
    while(getline(file, line))
    {
        
        if (!line.empty())
        {
            std::string output = "";
            std::stringstream stream(line);
            std::string word;
            while(getline(stream, word, ';'))
            {
                if (word == "zero") {
                    output.append("0");
                }
                else if (word == "one") {
                    output.append("1");
                }
                else if (word == "two") {
                    output.append("2");
                }
                else if (word == "three") {
                    output.append("3");
                }
                else if (word == "four") {
                    output.append("4");
                }
                else if (word == "five") {
                    output.append("5");
                }
                else if (word == "six") {
                    output.append("6");
                }
                else if (word == "seven") {
                    output.append("7");
                }
                else if (word == "eight") {
                    output.append("8");
                }
                else if (word == "nine") {
                    output.append("9");
                }
            }
            std::cout << output << std::endl;
        }
    }
    file.close();
    return 0;
}