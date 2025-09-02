#include <iostream>
#include "Contact.hpp"

Contact::Contact(void) : _index(-1)
{
}

Contact::~Contact(void)
{
}

int Contact::getIndex(void) const
{
	return this->_index;
}

std::string Contact::getFirstName(void) const
{
	return this->_first_name;
}

std::string Contact::getLastName(void) const
{
	return this->_last_name;
}

std::string Contact::getNickname(void) const
{
	return this->_nickname;
}

std::string Contact::getPhoneNumber(void) const
{
	return this->_phone_number;
}

std::string Contact::getDarkestSecret(void) const
{
	return this->_darkest_secret;
}

void Contact::setIndex(int index)
{
	this->_index = index;
}

void Contact::setFirstName(const std::string &first_name)
{
	this->_first_name = first_name;
}

void Contact::setLastName(const std::string &last_name)
{
	this->_last_name = last_name;
}

void Contact::setNickname(const std::string &nickname)
{
	this->_nickname = nickname;
}

void Contact::setPhoneNumber(const std::string &phone_number)
{
	this->_phone_number = phone_number;
}

void Contact::setDarkestSecret(const std::string &darkest_secret)
{
	this->_darkest_secret = darkest_secret;
}
