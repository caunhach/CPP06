#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include "TypeManager.hpp"

class ScalarConverter 
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &src);
		~ScalarConverter(void);
	public:
		static void	convert(const std::string& str);
};

#endif