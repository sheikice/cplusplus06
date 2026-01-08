#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./convert 42\n";
		return 1;
	}
	ScalarConverter::convert(av[1]);
	return 0;
}
