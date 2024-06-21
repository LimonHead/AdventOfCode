#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::string input{};
    std::ifstream input_file("input.txt");
    std::getline(input_file, input);

    

    // Part 1 //

    int result1{ 0 };

    for (char c : input)
    {
        if (c == '(') result1++;
        else result1--;
    }

    std::cout << "Part 1: " << result1 << '\n';



    // Part 2 //

    int result2{ 0 };

    int floor{ 0 };
    for (char c : input)
    {
        result2++;
        if (c == '(') floor++;
        else floor--;
        if (floor < 0) break;
    }

    std::cout << "Part 1: " << result2 << '\n';



    return 0;
}
