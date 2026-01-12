#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "utils.hpp"
#include <stdint.h>

class Serializer
{
	private:
		Serializer();
		~Serializer();

	public:
		static uintptr_t	serializer(Data*);
		static Data*		deserialize(uintptr_t);
};

std::ostream& operator<<(std::ostream&, const Data&);

#endif
