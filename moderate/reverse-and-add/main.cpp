#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

std::string reverse(std::string str)
{
    for (int i = 0; i < str.length() / 2; i++)
    {
        char temp = str[i];
        str[i] = str[str.length() - i - 1];
        str[str.length() - i - 1] = temp;
    }
    return str;
}

bool isPalindrome(std::string x)
{
    for (int i = 0; i < x.length() / 2; i++)
    {
        if (x[i] != x[x.length() - i - 1])
        {
            return false;
        }
    }
    return true;
}
int main(int argc, char const *argv[])
{
    std::ifstream file(argv[1]);
    std::string line;
    while(getline(file, line))
    {
        
        if (!line.empty())
        {
            int count = 0;
            if (!(isPalindrome(line)))
            {
                for (int i = 0; i < 100; i++)
                {
                    std::string temp  = reverse(line);
                    int n = std::stoi(line);
                    int m = std::stoi(temp);
                    int x = n + m;
                    count++;
                    if (isPalindrome(std::to_string(x)))
                    {
                        std::cout << count << " " << x << std::endl;
                        break;
                    }
                    line = std::to_string(x);
                }   
            }
            else
            {
               std::cout << count << " " << line << std::endl; 
            }
        }
    }
    file.close();
    return 0;
}