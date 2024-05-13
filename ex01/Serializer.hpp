#ifndef SERIALIZER_HPP
# define SEREALIZER_HPP

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer &src);
		Serializer &operator=(const Serializer &src);
		~Serializer(void);
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data*		deserealize(uintptr_t raw);
};

#endif