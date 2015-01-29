/*
CHALLENGE DESCRIPTION:

Given numbers x and n, where n is a power of 2, print out the smallest multiple of n which is greater than or equal to x. Do not use division or modulo operator.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[])
{
	string line;
	ifstream file(argv[1]);
	while (getline(file, line)) 
   {
       
       if (!line.empty())
       {
           int commaPosition = line.find_first_of(",");
           string tempX = line.substr(0,commaPosition);
           string tempN = line.substr(commaPosition + 1, line.length() - 1);
           int x = atoi(tempX.c_str());
           int n = atoi(tempN.c_str());

           if (x < n)
           {
           		std::cout << n << std::endl;
           		break;
           }
           else
           {	
           		int multiple = n;
           		while (x > multiple)
           		{
           			multiple += n;
           		}
       			std::cout << multiple << std::endl;
           }
       }
	}
	file.close();
	return 0;
}