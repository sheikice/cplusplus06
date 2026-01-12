#include "PrintLiteral.hpp"
#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits.h>
#include <limits>
#include <cmath>
#include <cerrno>

static	const int	SCIENTIFIC_NOTATION = 9999999;
static const double	EPSILON = 1e-9;

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
	long	nbr;
	bool	error = false;

	errno = 0;
	nbr = strtol(literal.c_str(), &endptr, 10);
	if (errno == ERANGE || nbr < INT_MIN || nbr > INT_MAX)
		error = true;
	if (error == true || (endptr && *endptr))
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return ;
	}
	if (nbr < CHAR_MIN || nbr > CHAR_MAX)
		std::cout << "char: impossible\n";
	else if (isprint(static_cast<unsigned char>(nbr)) == false)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: " << static_cast<char>(nbr) << "\n";
	std::cout << "int: " << static_cast<int>(nbr) << "\n";
	if (std::abs(nbr) > SCIENTIFIC_NOTATION)
		std::cout << "float: " << std::setprecision(7) << static_cast<float>(nbr) << "f\n";
	else
		std::cout << "float: " << std::setprecision(7) << static_cast<float>(nbr) << ".0f\n";
	if (std::abs(nbr) < SCIENTIFIC_NOTATION)
		std::cout << "double: " << std::setprecision(7) << static_cast<double>(nbr) << ".0\n";
	else
		std::cout << "double: " << std::setprecision(7) << static_cast<double>(nbr) << "\n";
}

void PrintLiteral::printFloat(const std::string& literal)
{
	char	*endptr;
	float	nbr;


	errno = 0;
	nbr = strtof(literal.c_str(), &endptr);
	if (errno == ERANGE || (endptr && *endptr != 'f') || (endptr && *endptr && *(endptr + 1)))
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
	if (nbr < INT_MIN || nbr > INT_MAX)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(nbr) << "\n";
	if (std::abs(std::floor(nbr) - nbr) < EPSILON && std::abs(nbr) <= SCIENTIFIC_NOTATION)
		std::cout << "float: " << std::setprecision(7) << static_cast<float>(nbr) << ".0f\n";
	else
		std::cout << "float: " << std::setprecision(7) << static_cast<float>(nbr) << "f\n";
	if (std::abs(std::floor(nbr) - nbr) < EPSILON && std::abs(nbr) <= SCIENTIFIC_NOTATION)
		std::cout << "double: " << std::setprecision(7) << static_cast<double>(nbr) << ".0\n";
	else
		std::cout << "double: " << std::setprecision(7) << static_cast<double>(nbr) << "\n";
}

void PrintLiteral::printDouble(const std::string& literal)
{
	char				*endptr;
	double				nbr;
	float				nbr_float;

	errno = 0;
	nbr = strtod(literal.c_str(), &endptr);
	nbr_float = static_cast<float>(nbr);
	if (errno == ERANGE || (endptr && *endptr))
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return ;
	}
	if (nbr < CHAR_MIN || nbr > CHAR_MAX)
		std::cout << "char: impossible\n";
	else if (isprint(static_cast<unsigned char>(nbr)) == false)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: " << static_cast<char>(nbr) << "\n";
	if (nbr < INT_MIN || nbr > INT_MAX)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(nbr) << "\n";
	if (-nbr_float > std::numeric_limits<float>::max() || nbr_float > std::numeric_limits<float>::max())
		std::cout << "float: impossible\n";
	else if (std::abs(std::floor(nbr) - nbr) < EPSILON && std::abs(nbr) <= SCIENTIFIC_NOTATION)
		std::cout << "float: " << std::setprecision(7) << static_cast<float>(nbr) << ".0f\n";
	else
		std::cout << "float: " << std::setprecision(7) << static_cast<float>(nbr) << "f\n";
	if (std::abs(std::floor(nbr) - nbr) < EPSILON && std::abs(nbr) <= SCIENTIFIC_NOTATION)
		std::cout << "double: " << std::setprecision(7) << nbr << ".0\n";
	else
		std::cout << "double: " << std::setprecision(7) << static_cast<double>(nbr) << "\n";
}
