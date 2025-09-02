#include <iostream>
#include <iomanip>
#include <cctype>
#include "PhoneBook.hpp"

void ft_putstr_10(const std::string &str);
void get_index_display(const PhoneBook &repertoire, int i);

static std::string get_non_empty_input(const std::string &prompt)
{
	std::string input;

	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (!input.empty())
			return input;
		std::cout << "Error: Field cannot be empty. Please try again." << std::endl;
	}
}

static std::string get_phone_number(void)
{
	std::string input;

	while (true)
	{
		std::cout << "phone number : ";
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "Error: Phone number cannot be empty." << std::endl;
			continue;
		}
		bool valid = true;
		for (size_t i = 0; i < input.length(); i++)
		{
			if (!std::isdigit(input[i]))
			{
				valid = false;
				break;
			}
		}
		if (valid)
			return input;
		std::cout << "Error: Phone number must contain only digits." << std::endl;
	}
}

PhoneBook::PhoneBook(void) : _count(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

int PhoneBook::getCount(void) const
{
	return this->_count;
}

Contact PhoneBook::getContact(int index) const
{
	if (index >= 0 && index < 8)
		return this->_contacts[index];
	return Contact();
}

void PhoneBook::add()
{
	Contact contact;

	std::cin.ignore();
	contact.setIndex((this->_count % 8) + 1);

	contact.setFirstName(get_non_empty_input("first name : "));
	contact.setLastName(get_non_empty_input("last name : "));
	contact.setNickname(get_non_empty_input("nickname : "));
	contact.setPhoneNumber(get_phone_number());
	contact.setDarkestSecret(get_non_empty_input("darkest secret : "));

	this->_contacts[this->_count % 8] = contact;
	this->_count++;
}

void PhoneBook::search(void)
{
	int max_contacts = (this->_count > 8) ? 8 : this->_count;

	if (max_contacts == 0)
	{
		std::cout << "No contacts found." << std::endl;
		return;
	}
	std::cout << std::setw(10) << "Index" << "|"
		    << std::setw(10) << "FirstName" << "|"
		    << std::setw(10) << "LastName" << "|"
		    << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < max_contacts; i++)
	{
		if (this->_contacts[i].getIndex() != -1)
		{
			std::cout << std::setw(10) << this->_contacts[i].getIndex() << "|";
			ft_putstr_10(this->_contacts[i].getFirstName());
			std::cout << "|";
			ft_putstr_10(this->_contacts[i].getLastName());
			std::cout << "|";
			ft_putstr_10(this->_contacts[i].getNickname());
			std::cout << std::endl;
		}
	}
	if (max_contacts > 0)
		get_index_display(*this, max_contacts);
}
