#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>

int main(int argc, const char *argv[])
{
    std::string line;
    std::ifstream file(argv[1]);
    while(getline(file, line))
    {
        if(!line.empty())
        {
            std::vector<char> matrix;
            char buffer;
            std::stringstream stream(line);
            while(stream >> buffer)
            {
                matrix.push_back(buffer);
            }
            //it's simpler to just traverse the matrix
            //in rotated order than to actually perform
            //the rotation
            int n = sqrt(matrix.size());
            for(int i = matrix.size() - n; i < matrix.size(); i++)
            {
                for(int j = i; j >= 0; j-=n)
                {
                    std::cout << matrix[j] << " ";
                }
            }
            std::cout << std::endl;
        }
    }
}
