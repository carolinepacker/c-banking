/*
 * account.h
 *
 *  Created on: Sep 28, 2022
 *      Author: Caroline Packer
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <iostream>
#include <string>

class Account {
	private:
		int id = 0;
		std::string name;
		float balance;
		static int id_count;

	public:

		Account();

		Account(std::string name, int balance);

		void enter_info();

		void display_info() const;

		void deposit(float deposit_amt);

		void withdraw(float withdrawal_amt);

		int get_id() const;

};



#endif /* ACCOUNT_H_ */
