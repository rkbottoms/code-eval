#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <cctype>



int main(int argc, char const *argv[])
{
    std::unordered_map<std::string, char> morse_map;
    morse_map[".-"] = 'A';
    morse_map["-..."] = 'B';
    morse_map["-.-."] = 'C';
    morse_map["-.."] = 'D';
    morse_map["."] = 'E';
    morse_map["..-."] = 'F';
    morse_map["--."] = 'G';
    morse_map["...."] = 'H';
    morse_map[".."] = 'I';
    morse_map[".---"] = 'J';
    morse_map["-.-"] = 'K';
    morse_map[".-.."] = 'L';
    morse_map["--"] = 'M';
    morse_map["-."] = 'N';
    morse_map["---"] = 'O';
    morse_map[".--."] = 'P';
    morse_map["--.-"] = 'Q';
    morse_map[".-."] = 'R';  
    morse_map["..."] = 'S';
    morse_map["-"] = 'T';
    morse_map["..-"] = 'U';
    morse_map["...-"] = 'V';
    morse_map[".--"] = 'W';
    morse_map["-..-"] = 'X';
    morse_map["-.--"] = 'Y';
    morse_map["--.."] = 'Z';
    morse_map[".----"] = '1';
    morse_map["..---"] = '2';
    morse_map["...--"] = '3';
    morse_map["....-"] = '4';
    morse_map["....."] = '5';
    morse_map["-...."] = '6';
    morse_map["--..."] = '7';
    morse_map["---.."] = '8';
    morse_map["----."] = '9';
    morse_map["-----"] = '0';
    
    std::string line;
    std::ifstream file(argv[1]);
    while(getline(file, line))
    {
        if(!line.empty())
        {
            std::vector<std::string> morse_code;
            //split line on double spaces
            size_t position = 0;
            std::string delimeter = "  ";
            std::string morse_letter;
            while((position = line.find(delimeter)) != std::string::npos)
            {
                morse_letter = line.substr(0, position);
                morse_code.push_back(morse_letter);
                line.erase(0, position + delimeter.length());
            }
            morse_code.push_back(line);
            //printing out letters
            for (int i = 0; i < morse_code.size(); ++i)
            {
                std::string buffer;
                std::vector<std::string> temp;
                std::stringstream stream(morse_code[i]);
                while(stream >> buffer)
                {
                    std::cout << morse_map.at(buffer);
                }
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}