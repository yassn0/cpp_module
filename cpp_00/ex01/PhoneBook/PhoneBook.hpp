#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "../Contact/Contact.hpp"

class PhoneBook
{

private:
	int _count;
	Contact _contacts[8];

public:
	PhoneBook(void);
	~PhoneBook(void);

	void add(void);
	void search(void);

	int getCount(void) const;
	Contact getContact(int index) const;
};

#endif