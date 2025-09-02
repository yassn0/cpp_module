#include <iostream>
#include <stdint.h>
#include "Serializer/Serializer.hpp"
#include "Data/Data.hpp"

int main()
{
	Data data("tree");

	Data *test = Serializer::deserialize(Serializer::serialize(&data));

	std::cout << "\n-- 1 --" << std::endl;
	std::cout << "original_ptr : " << &data << std::endl;
	std::cout << "Serialize_Deserialize : " << test << std::endl;

	std::cout << "\n-- 2 --" << std::endl;
	uintptr_t serialize = Serializer::serialize(&data);
	std::cout << "uintptr_t : " << serialize << std::endl;
	Data *deserialize = Serializer::deserialize(serialize);
	std::cout << "uintptr_t deserialize : " << deserialize << std::endl;

	std::cout << "\n-- 3 --" << std::endl;
	uintptr_t serialize_null = Serializer::serialize(NULL);
	std::cout << "uintptr_t_null : " << serialize_null << std::endl;
	Data *deserialize_null = Serializer::deserialize(serialize_null);
	std::cout << "uintptr_t_null deserialize : " << deserialize_null << std::endl << std::endl;
}