#pragma once

#include "../Data/Data.hpp"
#include <stdint.h>

class Serializer
{
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
	
private:
	Serializer();
	Serializer(const Serializer &);
};
