#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data		test = {42, 42, "Test working"};
	uintptr_t	serialize;
	Data*		deserialize;

	std::cout << "\n[TEST BEFORE]:\n" << test << "\n";
	serialize = Serializer::serializer(&test);
	deserialize = Serializer::deserialize(serialize);
	std::cout << "[TEST AFTER]:\n" << *deserialize << "\n";
	test.letter = 0;
	test.nbr = 0;
	test.str = "Reset";

	std::cout << "--------------------------------\n";
	std::cout << "\n[TEST BEFORE]:\n" << test << "\n";
	serialize = Serializer::serializer(&test);
	deserialize = Serializer::deserialize(serialize);
	std::cout << "[TEST AFTER]:\n" << *deserialize << "\n";
}
