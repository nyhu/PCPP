#include <iostream>
#include "Account.class.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int deposit) {
    this->_accountIndex = Account::_nbAccounts;
    this->_amount = deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    Account::_nbAccounts += 1;
    Account::_totalAmount += deposit;

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << std::to_string(this->_amount);
    std::cout << ";created" << std::endl;
}

Account::~Account(void) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << std::to_string(this->_amount);
    std::cout << ";closed" << std::endl;

    Account::_nbAccounts -= 1;
    Account::_totalAmount -= this->_amount;
}

int Account::getNbAccounts(void) {
    return Account::_nbAccounts;
}

int Account::getTotalAmount(void) {
    return Account::_totalAmount;
}

int Account::getNbDeposits(void) {
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return Account::_totalNbWithdrawals;
}

void Account::makeDeposit(int deposit) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "deposit:" << deposit << ";";

    this->_nbDeposits += 1;
    this->_amount += deposit;
    Account::_totalNbDeposits += 1;
    Account::_totalAmount += deposit;

    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawl) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";

    if (this->_amount < withdrawl) {
        std::cout << "withdrawal:refused" << std::endl;
        return false;
    }

    this->_nbWithdrawals += 1;
    this->_amount -= withdrawl;
    Account::_totalAmount -= withdrawl;
    Account::_totalNbWithdrawals += 1;

    std::cout << "withdrawal:" << withdrawl << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return true;
}

int Account::checkAmount(void) const {
    return this->_amount;
}

void Account::displayStatus(void) const {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos(void) {
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts << ";";
    std::cout << "total:" << Account::_totalAmount << ";";
    std::cout << "deposits:" << Account::_totalNbDeposits << ";";
    std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp( void )
{
	char		str[100];
	std::time_t	t;

    std::time(&t);
	if (std::strftime(str, sizeof(str), "[%Y%m%d_%H%M%S] ", std::localtime(&t)))
		std::cout << str;
}
