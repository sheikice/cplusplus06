#include "Base.hpp"
#include "utils.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int	main(void)
{
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		std::cout << "\n";
		Base* base = generate();
		if (!base)
			continue ;
		Base& ref = *base;
		identify(base);
		identify(ref);
		delete base;
	}

	return 0;
}
