#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

enum	TYPE {CHAR, INT, FLOAT, DOUBLE, UNDEFINED};

class ScalarConverter
{
	private:
		ScalarConverter(void);
		~ScalarConverter(void);
		
	public:
		static void convert(const std::string&);
};

#endif
