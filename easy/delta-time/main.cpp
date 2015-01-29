#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <cstdio>

void code_eval_time(int time_value)
{
    //computing hours
    int hour_difference = time_value / 3600;
    //compute remaining time by subtracting hour_difference
    int remaining_time = time_value - (3600 * hour_difference);
    //computing minutes
    int minute_difference = remaining_time / 60;
    //computing seconds by subtracting minute_difference
    int second_difference = remaining_time - (60 * minute_difference);
    printf("%02d:%02d:%02d\n", hour_difference, minute_difference, second_difference);

}
int convert_to_seconds(std::string time_string)
{
    std::string buffer;
    std::vector<int> times;
    std::stringstream stream(time_string);
    while(getline(stream, buffer, ':'))
    {
        times.push_back(stoi(buffer));
    }
    return (3600 * times[0]) + (60 * times[1]) + (times[2]);
}
int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream file(argv[1]);
    while (getline(file, line))
    {
        if(!line.empty())
        {
            int space_position = line.find_first_of(' ');
            std::string time_one = line.substr(0, space_position);
            std::string time_two = line.substr(space_position + 1);
            int time_one_seconds = convert_to_seconds(time_one);
            int time_two_seconds = convert_to_seconds(time_two);
            int difference = abs(time_one_seconds - time_two_seconds);
            code_eval_time(difference);
        }
    }
    return 0;
}
