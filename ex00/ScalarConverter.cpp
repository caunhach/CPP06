#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) { }

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	return *this;
}

ScalarConverter::~ScalarConverter(void) { }

void    ScalarConverter::convert(const std::string& str)
{
	e_type type = TypeManager::defineType(str);
	if (type == CHAR)
		TypeManager::convertChar(str);
	else if (type == INT)
		TypeManager::convertInt(str);
	else if (type == FLOAT)
		TypeManager::convertFloat(str);
	else if (type == DOUBLE)
		TypeManager::convertDouble(str);
	else if (type == SPECIAL)
		TypeManager::convertSpecial(str);
	else if (type == INVALID)
		TypeManager::printInvalid(str);
}