#include "TypeManager.hpp"

TypeManager::TypeManager(void) { }

TypeManager::TypeManager(const TypeManager &src)
{
	*this = src;
}

TypeManager &TypeManager::operator=(const TypeManager &src)
{
	return *this;
}

TypeManager::~TypeManager(void) { }

e_type TypeManager::defineType(const std::string &str)
{
	size_t len = str.length();
	size_t dot = str.find('.');
	size_t f = str.find('f');

	if (dot == std::string::npos)
	{
		if (isSpecial(str))
			return SPECIAL;
		else if (isChar(str, len))
			return CHAR;
		else if (isInt(str))
			return INT;
	}
	else if (dot != std::string::npos)
	{
		if (isFloat(str, len, dot) && f != std::string::npos)
			return FLOAT;
		else if (isDouble(str, len, dot) && f == std::string::npos)
			return DOUBLE;
	}
	return INVALID;
}

bool	TypeManager::isChar(const std::string &str, size_t &len)
{
	if (len == 1 && !(str[0] >= '0' && str[0] <= '9'))
		return true;
	if (len == 3 && str[0] == '\'' && str[2] == '\'')
		return true;
	return false;
}

bool	TypeManager::isInt(const std::string &str)
{
	int	i = -1;
	std::string value = str;

	if (value[0] == '+' || value[0] == '+')
		value = value.substr(1);
	
	while (value[++i] && value.length() > 0 && value.length() < 11)
	{
		if (!isdigit(value[i]))
			return false;
	}
	return true;
}

bool	TypeManager::isFloat(const std::string &str, size_t &len, size_t &dot)
{
	for (int i = dot - 1; i >= 0; i--)
	{
		if (!isdigit(str[i]) && i != 0)
			return false;
		else if (!isdigit(str[i]) && i == 0 && str[i] != '+' && str[i] != '-')
			return false;
	}
	for (size_t j = dot + 1; j < len; j++)
	{
		if (!isdigit(str[j]) && str[j] != 'f')
			return false;
		if (str[j] == 'f' && j != len - 1)
			return false;
	}
	return true;
}

bool	TypeManager::isDouble(const std::string &str, size_t &len, size_t &dot)
{
	for (int i = dot - 1; i >= 0; i--)
	{
		if (!isdigit(str[i]) && i != 0)
			return false;
		else if (!isdigit(str[i]) && i == 0 && str[i] != '+' && str[i] != '-')
			return false;
	}
	for (size_t j = dot + 1; j < len; j++)
	{
		if (!isdigit(str[j]))
			return false;
	}
	return true;
}

bool	TypeManager::isSpecial(const std::string &str)
{
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
		return true;
	return false;
}

void	TypeManager::convertChar(const std::string &str)
{
	char c;

	c = 0;
	if (str.length() == 1)
		c = str[0];
	else
		c = str[1];
	std::cout << "char: ";
	if (isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	TypeManager::convertInt(const std::string &str)
{
	long l = std::atol(str.c_str());

	std::cout << "char: ";
	if (l < 0 || l > 127)
		std::cout << "impossible" << std::endl;
	else if (!isprint(l))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(l) << "'" << std::endl;
	std::cout << "int: ";
	if (l < MIN_INT || l > MAX_INT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(l) << std::endl;
	std::cout << "float: " << static_cast<float>(l) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(l) << ".0" << std::endl;
}

void	TypeManager::convertFloat(const std::string &str)
{
	float f = std::atof(str.c_str());
	bool tolerance = std::fabs(f - static_cast<int>(f)) < 0.0000000000001;

	std::cout << "char: ";
	if (f < 0 || f > 127)
		std::cout << "impossible" << std::endl;
	else if (!isprint(f))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
	std::cout << "int: ";
	if (static_cast<long>(f) < MIN_INT || static_cast<long>(f) > MAX_INT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(f) << std::endl;
	std::cout << "float: ";
	if (f < MIN_FLOAT || f > MAX_FLOAT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << f << (tolerance ? ".0f" : "f") << std::endl;
	std::cout << "double: " << static_cast<double>(f) << (tolerance ? ".0" : "") << std::endl;
}

void	TypeManager::convertDouble(const std::string &str)
{
	double d = std::atof(str.c_str());
	bool   tolerance = std::fabs(d - static_cast<int>(d)) < 0.0000000000001;

	std::cout << "char: ";
	if (d < 0 || d > 127)
		std::cout << "impossible" << std::endl;
	else if (!isprint(d))
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: ";
	if (d < MIN_INT || d > MAX_INT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
	std::cout << "float: ";
	if (d < MIN_FLOAT || d > MAX_FLOAT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(d) << (tolerance ? ".0f" : "f") << std::endl;
	std::cout << "double: ";
	if (d < MIN_DOUBLE || d > MAX_DOUBLE)
		std::cout << "impossible" << std::endl;
	else
		std::cout << d << std::endl;
}

void	TypeManager::convertSpecial(const std::string &str)
{
	if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void	TypeManager::printInvalid(const std::string &str)
{
	std::cout << "Invalid input" << std::endl;
}