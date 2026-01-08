#include "ScalarConverter.hpp"
#include "CheckType.hpp"
#include "PrintLiteral.hpp"

void ScalarConverter::convert(const std::string& literal)
{
	int	type;

	type = CheckType::checkType(literal);
	PrintLiteral::printLiteral(literal, type);
}
