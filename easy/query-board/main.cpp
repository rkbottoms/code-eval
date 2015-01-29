#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>

void SetRow(int (&board)[256][256], int i, int x)
{
    for (int j = 0; j < 256; j++)
    {
        board[i][j] = x;
    }
}

void SetCol(int (&board)[256][256], int j, int x)
{
    for (int i = 0; i < 256; i++)
    {
        board[i][j] = x;
    }
}

void QueryRow(int (&board)[256][256], int i)
{
    int sum = 0;
    for (int j = 0; j < 256; j++)
    {
        sum += board[i][j];
    }
    std::cout << sum << std::endl;;
    
}
void QueryCol(int (&board)[256][256], int j)
{
    int sum = 0;
    for (int i = 0; i < 256; i++)
    {
        sum += board[i][j];
    }
    std::cout << sum << std::endl;
}
int main(int argc, char const *argv[])
{
    int board[256][256] = {{0}};
    std::ifstream file(argv[1]);
    std::string line;
    std::string buffer;
    while (getline(file, line))
    {
        std::vector<std::string> operations;
        if(!line.empty())
        {
            std::stringstream ss(line);
            while (ss >> buffer)
            {
                operations.push_back(buffer);
            }
            if(operations[0] == "SetCol")
            {
                SetCol(board, std::stoi(operations[1]), std::stoi(operations[2]));
            }
            else if(operations[0] == "SetRow")
            {
                SetRow(board, std::stoi(operations[1]), std::stoi(operations[2]));
            }
            else if(operations[0] == "QueryCol")
            {
                QueryCol(board, std::stoi(operations[1]));
            }
            else
            {
                QueryRow(board, std::stoi(operations[1]));
            }
            
        }
    }
    file.close();
    return 0;
}