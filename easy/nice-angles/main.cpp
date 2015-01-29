#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <iomanip>

int main(int argc, char const *argv[])
{
	std::string line;
	std::ifstream file(argv[1]);
	while(getline(file, line))
	{
		if(!line.empty())
		{
			double angle = std::stod(line);
			std::array<int, 3> time;
			for (int i = 0; i < time.size(); ++i)
			{
				//hours will always be the number
				//before the decimal so a hacky
				//way is to demote angle from
				//a double to an int. The 
				//extra precision is lost
				time[i] = angle;
				//remove everything before decimal
				angle -= time[i];
				//multiply by 60 to get next measurement
				angle *= 60;
			}
			std::cout << time[0] << "." << 
			std::setw(2) << std::setfill('0') << time[1] << "\'" <<
			std::setw(2) << std::setfill('0') << time[2] << "\"" << std::endl;
		}
	}
	file.close();
	return 0;
}