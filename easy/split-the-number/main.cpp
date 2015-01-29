#include <iostream>
#include <fstream>
#include <string>

//takes in two numbers specified by m and n,
//then performs the operation specified by op
int performOperation(long m, long n, char op)
{
    if(op == '+') {return m+n;}
    else {return m-n;}
}
int main(int argc, const char * argv[])
{
    std::string line;
    std::ifstream file(argv[1]);
    while(getline(file, line))
    {
        if(!line.empty())
        {
            //splitting line on space character
            int space = line.find_first_of(" ");
            std::string number = line.substr(0, space);
            std::string pattern = line.substr(space + 1);
            //finding the index of the operation
            int split = pattern.find_first_of("+-");
            //storing the operation
            char operation = pattern[split];
            //spliting the number based on the operation index
            long num1 = std::stol(number.substr(0, split));
            long num2 = std::stol(number.substr(split));
            std::cout << performOperation(num1, num2, operation) << std::endl;
        }
    }
}
