#include "ScalarConverter.hpp"
#include "CheckType.hpp"

#include <iostream>
#include <string>

bool CheckType::checkChar(const std::string& literal)
{
	if (literal.size() != 1)
		return false;
	if (std::isalnum(literal.at(0)) && std::isalpha(literal.at(0)) == false)
		return false;
	return true;
}

bool CheckType::checkFloat(const std::string& literal)
{
	if (literal.find(".") == std::string::npos)
		return false;
	if (literal.find("f") == std::string::npos)
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
	std::cout << "[TEST: String is \"" << literal << "\"]\n";
	// if (literal.empty() == true)
	// 	return UNDEFINED ;
	if (CheckType::checkChar(literal) == true)
		return CHAR;
	if (CheckType::checkFloat(literal) == true)
		return FLOAT;
	if (CheckType::checkDouble(literal) == true)
		return DOUBLE;
	return INT;
}

const char* CheckType::charNotDisplayableException::what(void) const throw()
{
	return "This char isn't displayable\n";
}
