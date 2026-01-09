#include "PrintLiteral.hpp"
#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <limits>
#include <cmath>

void PrintLiteral::printLiteral(const std::string& literal, int type)
{
	switch (type)
	{
		case UNDEFINED:
			PrintLiteral::printNan(literal);
			break ;
		case CHAR:
			PrintLiteral::printChar(literal);
			break ;
		case INT:
			PrintLiteral::printInt(literal);
			break ;
		case FLOAT:
			PrintLiteral::printFloat(literal);
			break ;
		case DOUBLE:
			PrintLiteral::printDouble(literal);
			break ;
	}
}

void PrintLiteral::printNan(std::string literal)
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
	{
		std::cout << "float: " << literal << "f\n";
		std::cout << "double: " << literal << "\n";
	}
	else
	{
		std::cout << "float: " << literal << "\n";
		literal.resize(literal.size() - 1);
		std::cout << "double: " << literal << "\n";
	}
}

void PrintLiteral::printChar(const std::string& literal)
{
	char c;

	if (literal.empty() == true)
		c = 0;
	else
		c = literal.at(0);
	if (isprint(c) == false)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: " << c << "\n";
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << "float: " << static_cast<float>(c) << ".0f\n";
	std::cout << "double: " << static_cast<double>(c) << ".0\n";
}

void PrintLiteral::printInt(const std::string& literal)
{
	char	*endptr;
	long		nbr;

	nbr = strtol(literal.c_str(), &endptr, 10);
	std::cout << "INT:" << *endptr << "\n";
	if (endptr && *endptr)
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return ;
	}
	std::cout << endptr << "\n";
	if (nbr < CHAR_MIN || nbr > CHAR_MAX)
		std::cout << "char: impossible\n";
	else if (isprint(nbr) == false)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: " << static_cast<char>(nbr) << "\n";
	if (nbr > std::numeric_limits<int>::max() || nbr < std::numeric_limits<int>::min())
	{
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
	}
	else
	{
		std::cout << "int: " << static_cast<int>(nbr) << "\n";
		std::cout << "float: " << static_cast<float>(nbr) << ".0f";
		std::cout << "double: " << static_cast<double>(nbr) << ".0\n";
	}
}

void PrintLiteral::printFloat(const std::string& literal)
{
	char	*endptr;
	double		nbr;

	nbr = strtod(literal.c_str(), &endptr);
	// std::cout << nbr << " / " << *endptr << "\n";
	if ((endptr && *endptr != 'f') || (endptr && *endptr && *(endptr + 1)))
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return ;
	}
	if (nbr < CHAR_MIN || nbr > CHAR_MAX)
		std::cout << "char: impossible\n";
	else if (isprint(nbr) == false)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: " << static_cast<char>(nbr) << "\n";
	if (nbr > std::numeric_limits<float>::max() || nbr < std::numeric_limits<float>::min())
	{
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
	}
	else
	{
		std::cout << "int: " << static_cast<int>(nbr) << "\n";
		std::cout << "float: " << static_cast<float>(nbr);
		if (std::floor(nbr) == nbr)
			std::cout << ".0f\n";
		else
			std::cout << "f\n";
		std::cout << "double: " << static_cast<double>(nbr) << "\n";
	}
}

void PrintLiteral::printDouble(const std::string& literal)
{
	char	*endptr;
	long		nbr;

	nbr = strtol(literal.c_str(), &endptr, 10);
	if (endptr && *endptr)
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return ;
	}
	std::cout << endptr << "\n";
	if (nbr < CHAR_MIN || nbr > CHAR_MAX)
		std::cout << "char: impossible\n";
	else if (isprint(nbr) == false)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: " << static_cast<char>(nbr) << "\n";
	if (nbr > std::numeric_limits<int>::max() || nbr < std::numeric_limits<int>::min())
	{
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
	}
	else
	{
		std::cout << "int: " << static_cast<int>(nbr) << "\n";
		std::cout << "float: " << static_cast<float>(nbr) << ".0f\n";
		std::cout << "double: " << static_cast<double>(nbr) << ".0\n";
	}
}
