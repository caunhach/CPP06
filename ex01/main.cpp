#include "Serializer.hpp"

int main(void)
{
	Data *data = new Data;
	data->id = 1;
	data->name = "Caunhach";

	uintptr_t raw = Serializer::serialize(data);
	Data *Serialized = Serializer::deserealize(raw);

	std::cout << "data->id: " << data->id << std::endl;
	std::cout << "data->name: " << data->name << std::endl;
	std::cout << "serializ(data): " << raw << std::endl;
	std::cout << "deserialize(raw): " << Serialized << std::endl;
	std::cout << "serialized->id: " << Serialized->id << std::endl;
	std::cout << "serialized->name: " << Serialized->name << std::endl;
	return 0;
}