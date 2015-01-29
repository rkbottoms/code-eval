#include <iostream>
#include <fstream>

using namespace std;


std::ifstream::pos_type filesize(const char* filename)
{
    std::ifstream in(filename, std::ifstream::in | std::ifstream::binary);
    in.seekg(0, std::ifstream::end);
    return in.tellg(); 
}

int main(int argc, char const *argv[])
{
    int n = filesize(argv[1]);
    cout << n << endl;
    return 0;
}