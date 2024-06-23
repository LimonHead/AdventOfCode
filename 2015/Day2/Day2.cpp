#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <numeric>

std::vector<std::string> ParseByDelimiter(std::string input, char delimiter)
{
	std::vector<std::string> output{};
	std::string temp{};

	for (char c : input)
	{
		if (c == delimiter)
		{
			output.push_back(temp);
			temp = "";
		}
		else
		{
			temp += c;
		}
	}
	output.push_back(temp);

	return output;
}

void PrintVector(std::vector<int> vector)
{
	for (int item : vector)
	{
		std::cout << item << ",\n";
	}
}
void PrintVector(std::vector<std::string> vector)
{
	for (std::string item : vector)
	{
		std::cout << item << ",\n";
	}
}

int main()
{
	std::vector<std::string> input{};
	std::ifstream input_file("input.txt");
	std::string temp{};

	while (std::getline(input_file, temp))
	{
		input.push_back(temp);
	}



	// Part 1 //

	int result_1{ 0 };

	for (std::string s : input)
	{
		std::vector<std::string> split_string{ ParseByDelimiter(s, 'x') };
		std::vector<int> dimensions{ std::stoi(split_string[0]), std::stoi(split_string[1]), std::stoi(split_string[2]) };
		std::vector<int> areas{ dimensions[0] * dimensions[1],
								dimensions[0] * dimensions[2],
								dimensions[1] * dimensions[2] };

		result_1 += 2 * areas[0] + 2 * areas[1] + 2 * areas[2] + *std::min_element(areas.begin(), areas.end());
	}

	std::cout << "Part 1: " << result_1 << '\n';



	// Part 2 //

	int result_2{ 0 };

	for (std::string s : input)
	{
		std::vector<std::string> split_string{ ParseByDelimiter(s, 'x') };
		std::vector<int> dimensions{ std::stoi(split_string[0]), std::stoi(split_string[1]), std::stoi(split_string[2]) };
		std::vector<int> perimeters{ 2 * (dimensions[0] + dimensions[1]),
									 2 * (dimensions[0] + dimensions[2]),
									 2 * (dimensions[1] + dimensions[2]) };

		int volume{ dimensions[0] * dimensions[1] * dimensions[2] };

		result_2 += *std::min_element(perimeters.begin(), perimeters.end()) + volume;
	}

	std::cout << "Part 2: " << result_2 << '\n';



	return 0;
}
