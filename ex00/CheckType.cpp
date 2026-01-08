#include "ScalarConverter.hpp"
#include "CheckType.hpp"

#include <string>

bool CheckType::checkNan(const std::string& literal)
{
	if (literal == "nan" || literal == "nanf" || literal == "+inf"
		|| literal == "-inf" || literal == "+inff" || literal == "-inff")
		return true;
	return false;
}

bool CheckType::checkChar(const std::string& literal)
{
	if (literal.empty() || literal.size() != 1)
		return false;
	if (std::isalnum(literal.at(0)) && std::isalpha(literal.at(0)) == false)
		return false;
	return true;
}

bool CheckType::checkFloat(const std::string& literal)
{
	size_t	fCheck = literal.find("f");	
	size_t	dotCheck = literal.find(".");

	if (dotCheck == std::string::npos || fCheck != literal.size() - 1)
		return false;
	if (dotCheck == 0 && literal.size() < 3)
		return false;
	return true;
}

bool CheckType::checkDouble(const std::string& literal)
{
	if (literal.find(".") == std::string::npos)
		return false;
	if (literal.find("f") != std::string::npos)
		return false;
	return true;
}

int CheckType::checkType(const std::string& literal)
{
	if (CheckType::checkNan(literal))
		return UNDEFINED;
	if (CheckType::checkChar(literal) == true)
		return CHAR;
	if (CheckType::checkFloat(literal) == true)
		return FLOAT;
	if (CheckType::checkDouble(literal) == true)
		return DOUBLE;
	return INT;
}
