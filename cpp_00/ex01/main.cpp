#include <iostream>
#include <iomanip>
#include <string>
#include "PhoneBook/PhoneBook.hpp"
#include "Contact/Contact.hpp"

void ft_putstr_10(const std::string &str)
{
	if (str.length() > 10)
		std::cout << std::setw(10) << str.substr(0, 9) + ".";
	else
		std::cout << std::setw(10) << str;
}

void get_index_display(const PhoneBook &repertoire, int max_contacts)
{
	int index;

	while (true)
	{
		std::cout << "Choose an index : ";
		std::cin >> index;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Error: Please enter a valid number" << std::endl;
		}
		else if (index <= max_contacts && index > 0)
			break;
		else
			std::cout << "Error: Index must be between 1 and " << max_contacts << std::endl;
	}
	for (int j = 0; j < max_contacts; j++)
	{
		Contact contact = repertoire.getContact(j);
		if (contact.getIndex() == index)
		{
			std::cout << "First Name: " << contact.getFirstName() << std::endl;
			std::cout << "Last Name: " << contact.getLastName() << std::endl;
			std::cout << "Nickname: " << contact.getNickname() << std::endl;
			std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
			std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
			break;
		}
	}
}

int main(int ac, char **av)
{
	(void)av;
	PhoneBook repertoire;
	std::string input;

	if (ac != 1)
		return (1);
	while (input.compare("EXIT"))
	{
		std::cin >> input;
		if (!input.compare("ADD"))
			repertoire.add();
		else if (!input.compare("SEARCH"))
			repertoire.search();
	}
	return (0);
}

