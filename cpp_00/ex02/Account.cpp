#include <iostream>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account() {}

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	this->_accountIndex = _nbAccounts;
	Account::_nbAccounts += 1;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		    << "amount:" << initial_deposit << ";" << "created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		    << "amount:" << this->_amount << ";" << "closed" << std::endl;
}

void Account::_displayTimestamp(void)
{
	std::time_t now = std::time(NULL);
	std::tm *tm_now = std::localtime(&now);

	std::cout << "["
		    << (tm_now->tm_year + 1900)
		    << (tm_now->tm_mon + 1 < 10 ? "0" : "") << tm_now->tm_mon + 1
		    << (tm_now->tm_mday < 10 ? "0" : "") << tm_now->tm_mday
		    << "_"
		    << (tm_now->tm_hour < 10 ? "0" : "") << tm_now->tm_hour
		    << (tm_now->tm_min < 10 ? "0" : "") << tm_now->tm_min
		    << (tm_now->tm_sec < 10 ? "0" : "") << tm_now->tm_sec
		    << "] ";
}

int Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";"
		    << "total:" << Account::_totalAmount << ";"
		    << "deposits:" << Account::_totalNbDeposits << ";"
		    << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	this->_nbDeposits += 1;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		    << "p_amount:" << this->_amount << ";"
		    << "deposit:" << deposit << ";"
		    << "amount:" << (this->_amount + deposit) << ";"
		    << "nb_deposits:" << this->_nbDeposits << std::endl;

	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (this->_amount - withdrawal < 0)
	{
		std::cout << "index:" << this->_accountIndex << ";"
			    << "p_amount:" << this->_amount << ";"
			    << "withdrawal:" << "refused" << std::endl;
		return false;
	}
	this->_nbWithdrawals += 1;
	std::cout << "index:" << this->_accountIndex << ";"
		    << "p_amount:" << this->_amount << ";"
		    << "withdrawal:" << withdrawal << ";"
		    << "amount:" << (this->_amount - withdrawal) << ";"
		    << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;

	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals += 1;
	return true;
}

int Account::checkAmount(void) const
{
	return (this->_amount);
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		    << "amount:" << this->_amount << ";"
		    << "deposits:" << this->_nbDeposits << ";"
		    << "withdrawals:" << this->_nbWithdrawals << std::endl;
}
