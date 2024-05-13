#include "Serializer.hpp"

Serializer::Serializer(void) { }

Serializer::Serializer(const Serializer &src)
{
	*this = src;
}

Serializer &Serializer::operator=(const Serializer &src)
{
	if (this != &src)
		*this = src;
	return *this;
}

Serializer::~Serializer(void) { }

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserealize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}