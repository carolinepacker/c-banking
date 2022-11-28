/*
 * account.cpp
 *
 *  Created on: Sep 28, 2022
 *      Author: Caroline Packer
 */

#include <string>
#include <iostream>
#include "account.h"

int Account::id_count = 0;

Account::Account(): id(id_count++), name(""), balance(0)
{
}

// constructor with parameters
Account::Account(std::string name, int balance) :
		id(id_count++), name(name), balance(balance)
{
}


void Account::display_info() const
{
	std::cout << "Found account:  Account ID: " << id << "  Name: " << name << "  Balance: $" << balance << std::endl;
}

void Account::enter_info()
{
	std::cout << "Enter the name: ";
	std::cin >> name;
	std::cout << "Enter the balance: ";
	std::cin >> balance;
	//id = id_count;
	//id_count++;
}

void Account::deposit(float deposit_amt)
{
	balance = balance + deposit_amt;
}

void Account::withdraw(float withdrawal_amt)
{
	balance = balance - withdrawal_amt;
}

int Account::get_id() const
{
	return id;
}







