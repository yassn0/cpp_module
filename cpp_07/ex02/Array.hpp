#include <iostream>
#include <exception>

template <typename T>
class Array
{
public:
	Array(void) : _tab(new T[0]), _size(0)
	{
		std::cout << "Constructor template Array called" << std::endl;
	}
	~Array()
	{
		if (_tab)
			delete [] _tab;
	}
	Array(unsigned int n) : _tab(new T[n]), _size(n)
	{
		std::cout << "Constructor for unsigned int template Array called" << std::endl;
	}
	Array(const Array &copy) : _size(copy._size)
	{
		std::cout << "Constructor copy template Array called" << std::endl;
		_tab = NULL;
		*this = copy;
	}
	Array &operator=(const Array &obj)
	{
		if (_tab)
			delete [] _tab;
		if (this != &obj)
		{
			_size = obj._size;
			_tab = new T[_size];
			for (size_t i = 0; i < _size; i++)
				_tab[i] = obj._tab[i];
		}
		std::cout << "operator= template Array called" << std::endl;
		return *this;
	}

	class Bad_Index : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "You've entered a wrong index in your array";
		}
	};

	T &operator[](int index)
	{
		if (index < 0)
		{
			throw Bad_Index();
		}
		else if (index >= static_cast<int>(_size))
		{
			throw Bad_Index();
		}
		return _tab[index];
	};

	size_t size()
	{
		return _size;
	}

private:
	T *_tab;
	size_t _size;
};
