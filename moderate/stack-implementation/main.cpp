#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>

int main(int argc, char *argv[])
{
    std::ifstream file(argv[1]);
    std::string line;
    while(getline(file, line))
    {
        if (!line.empty())
        {
            std::stack<int> stk;
            std::string buffer = "";
            std::stringstream ss(line);
            while (ss >> buffer)
            {
                stk.push(stoi(buffer));
            }
            int limit = stk.size();
            for(int i = 0; i < limit; i++)
            {
                int n = stk.top();
                stk.pop();
                if(i % 2 == 0)
                {
                    std::cout << n << " ";
                }

            }
        }
        std::cout << std::endl;
    }
    file.close();
    return 0;
}