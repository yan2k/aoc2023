#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctype.h>
#include <exception> 

std::vector<std::string> getInput()
{
    std::string line;
    std::ifstream input("input");
    std::vector<std::string> v;

    if(!input.is_open())
    {
        std::cerr << "\n\033[1;31m>>> Error while trying to load input file\033[0m\n";
        std::terminate();
    }

    while(std::getline(input, line))
    {
        v.push_back(line);
    };

    input.close();
    return v;
}

std::string part1(std::vector<std::string> v)
{
    int result = 0;
    for(std::string line : v)
    {
        line.erase(std::remove_if(line.begin(), line.end(), [](char c) { return !std::isdigit(c); }), line.end());
        line = std::to_string(((int)line.front() - 48 )*10 + (int)line.back() - 48);
        result += ((int)line.front() - 48 )*10 + (int)line.back() - 48;
        
    }
    return std::to_string(result);
}

std::string part2(std::vector<std::string> v)
{
    //Don't ask
    std::string numbers[9] = {"on", "tw", "thre", "four", "fiv", "six", "seve", "eigh", "nin"};


    int result = 0;
    for(size_t j = 0; j < v.size(); j++)
    {
        for(int i = 0; i < 9; i++)
        {
           size_t pos = v[j].find(numbers[i]);
           if(pos != std::string::npos)
           {
                v[j].replace(pos, numbers[i].length(), std::to_string(i+1));
           } 
        }
    }

    return part1(v);
}


int main(int argc, char* argv[])
{
    std::vector<std::string> input = getInput();

    std::cout << "\n\033[1;33m>>> Part 1\033[0m\n";
    std::cout << "Result: " << part1(input) << "\n";

    std::cout << "\n\033[1;33m>>> Part 2\033[0m\n";
    std::cout << "Result: " << part2(input) << "\n";


    return 0;
}