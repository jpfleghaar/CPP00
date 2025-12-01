/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 20:26:27 by jpflegha          #+#    #+#             */
/*   Updated: 2025/12/01 18:37:50 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp( void )
{
    std::time_t now = std::time(NULL);
        std::tm *timePtr = std::localtime(&now);

    std::cout << '['
              << (timePtr->tm_year + 1900)
              << (timePtr->tm_mon + 1)
              << timePtr->tm_mday << '_'
              << timePtr->tm_hour
              << timePtr->tm_min
              << timePtr->tm_sec
              << "] ";
}

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _totalAmount += initial_deposit;
    _nbAccounts++;
    _displayTimestamp();
    std::cout   << "index:" << _accountIndex
                << ";amount:" <<_amount
                << ";created"   << std::endl;

}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed" << std::endl;
}

void    Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout   << "accouts:" << _nbAccounts
                << ";total:"    << _totalAmount
                << ";deposits:" << _totalNbDeposits
                << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void    Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout   << "index:"   << _accountIndex
                << ";amount:"   << _amount
                << ";deposits:"  << _nbDeposits
                << ";withdrawls:" << _nbWithdrawals << std::endl;
}

void    Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout   <<"index:" <<_accountIndex
                << ";p_amount:" << _amount;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << ";deposit" << deposit
                << ";amount:" << _amount
                << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout   << "index:" << _accountIndex
                << ";p_amount:" << _amount;
    if(withdrawal > _amount)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return (false);
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    std::cout   << ";withdrawal:" << withdrawal
                << ":amount:"   << _amount
                << ";nb_withdrawal:" << _nbWithdrawals << std::endl;
    return (true);
}

int Account::checkAmount(void) const{
    return (_amount);
}