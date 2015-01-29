#include <iostream>

int main()
{
    int n = 1;
    if(*(char*)&n == 1)
    {
        std::cout << "LittleEndian" << std::endl;
    }
    else
    {
        std::cout << "BigEndian" << std::endl;
    }
}