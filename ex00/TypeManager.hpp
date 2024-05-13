#ifndef TYPE_MANAGER_HPP
# define TYPE_MANAGER_HPP

# include <iostream>
# include <string>
# include <cmath>
# include <limits>

# define MAX_INT std::numeric_limits<int>::max()
# define MIN_INT std::numeric_limits<int>::min()
# define MAX_FLOAT std::numeric_limits<float>::max()
# define MIN_FLOAT std::numeric_limits<float>::min()
# define MAX_DOUBLE std::numeric_limits<double>::max()
# define MIN_DOUBLE std::numeric_limits<double>::min()

enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL,
	INVALID
};

class TypeManager {
	private:
		TypeManager(void);
		TypeManager(const TypeManager &src);
		TypeManager &operator=(const TypeManager &src);
		~TypeManager(void);
	public:
		static e_type defineType(const std::string &str);
		static bool	isChar(const std::string &str, size_t &len);
		static bool	isInt(const std::string &str);
		static bool isFloat(const std::string &str, size_t &len, size_t &dot);
		static bool isDouble(const std::string &str, size_t &len, size_t &dot);
		static bool isSpecial(const std::string &str);
		static void convertChar(const std::string &str);
		static void convertInt(const std::string &str);
		static void convertFloat(const std::string &str);
		static void convertDouble(const std::string &str);
		static void convertSpecial(const std::string &str);
		static void printInvalid(const std::string &str);
};

#endif