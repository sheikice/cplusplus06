#ifndef PRINTLITERAL_HPP
# define PRINTLITERAL_HPP

#include <string>

class PrintLiteral
{
	private:
		PrintLiteral();
		~PrintLiteral();
		static void printChar(const std::string&);
		static void printInt(const std::string&);
		static void printFloat(const std::string&);
		static void printDouble(const std::string&);
		static void printNan(std::string);
		
	public:
		static void printLiteral(const std::string&, int);
};

#endif
