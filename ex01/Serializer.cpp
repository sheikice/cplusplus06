#include "Serializer.hpp"
#include <iostream>

uintptr_t Serializer::serializer(Data* data)
{
	return reinterpret_cast<uintptr_t>(data);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

std::ostream& operator<<(std::ostream& os, const Data& data)
{
	os << "data.nbr = " << data.nbr << "\n"
			<< "data.letter = " << data.letter << "\n"
			<< "data.test = " << data.str << "\n";
	return os;
}
