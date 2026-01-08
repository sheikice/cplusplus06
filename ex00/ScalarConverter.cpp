#include "ScalarConverter.hpp"
#include "CheckType.hpp"
#include <iostream>

void ScalarConverter::convert(const std::string& literal)
{
	int	type;

	type = CheckType::checkType(literal);
	std::cout << "Type is: ";
	switch (type)
	{
		case CHAR:
			std::cout << "char\n";
			break ;
		case INT:
			std::cout << "int\n";
			break ;
		case FLOAT:
			std::cout << "float\n";
			break ;
		case DOUBLE:
			std::cout << "double\n";
			break ;
		case UNDEFINED:
			std::cout << "undefined\n";
			break ;
	}
}
