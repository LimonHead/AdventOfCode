#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::string input{};
    std::ifstream input_file("input.txt");
    std::getline(input_file, input);

    // Part 1 //

    int floor{ 0 };
    for (char c : input)
    {
        if (c == '(') floor++;
        else floor--;
    }

    std::cout << floor;
    return 0;
}
