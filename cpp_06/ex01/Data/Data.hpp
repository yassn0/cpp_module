#pragma once

#include <string>

class Data
{
public:
	Data(std::string name);
	~Data();
	Data(const Data &);
	Data &operator=(const Data &);

private:
	Data();
	std::string _name;
};
