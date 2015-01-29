#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

int find_next_index(std::vector<bool> & array, int p)
{
    for (int i = p + 1; i < array.size(); i++)
    {
        if (array[i] == true)
        {
            return i;
        }
    }
    return -1;
}
int main(int argc, char **argv)
{
    std::string line;
    std::ifstream file(argv[1]);
    while(getline(file, line))
    {
        if (!line.empty())
        {
            unsigned int x = std::stoi(line);
            std::vector<bool> possibilities(x, true);
            std::string output = "";
            int p = 2;
            while (p*p < x)
            {
                for (int k = p*p; k < x; k+=p)
                {
                    possibilities[k] = false;
                }
                p = find_next_index(possibilities, p);
                if (p == -1)
                {
                    break;
                }
            }
            for (int j = 2; j < possibilities.size(); j++)
            {
                if(possibilities[j])
                {
                    output.append(std::to_string(j)).append(",");
                }
            }
            //lazy way of formatting correctly
            output.pop_back();
            std::cout << output << std::endl;
            
        }
    }
    file.close();
    return 0;
}