#ifndef CHECKTYPE_HPP
# define CHECKTYPE_HPP

#include <string>

class CheckType
{
	private:
		CheckType(void);
		~CheckType(void);

		static bool checkChar(const std::string& literal);
		static bool checkFloat(const std::string& literal);
		static bool checkDouble(const std::string& literal);
		static bool checkNan(const std::string& literal);
		
	public:
		static int checkType(const std::string&);
};

#endif
