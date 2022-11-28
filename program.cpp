//============================================================================
// Name        : bankingW03.cpp
// Author      : Caroline Packer
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "account.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

// Function prototypes
void add_account(list<Account>& account_list);
void display_accounts(list<Account>& account_list);
list<Account>::iterator find_id(list<Account>& account_list, int id);

int main() {
	/*Account a1;
	a1.enter_info();
	cout << endl; */
	list<Account> accounts;

	int choice = -1;
	do {
		cout << "Account Menu: " << endl;
		cout << "0. Quit Program" << endl;
		cout << "1. Display Account Information" << endl;
		cout << "2. Add a deposit to an account" << endl;
		cout << "3. Withdraw from an account" << endl;
		cout << "4. Add new account" << endl;
		cout << "5. Find account by ID" << endl;
		cout << "Your choice: ";
		cin >> choice;

		if (choice == 1) {
			// DISPLAY ALL ACCOUNTS
			display_accounts(accounts);
			cout << endl;
		} else if (choice == 2) {
			// DESPOSIT
			// find iterator for id
			int desiredId;
			cout << "Enter the ID of the account to find: ";
			cin >> desiredId;
			list<Account>::iterator it;
			it = find_id(accounts, desiredId);
			if (it != accounts.end()) {
				it->display_info();
				float deposit_amt;
				cout << "Amount to deposit: ";
				cin >> deposit_amt;
				cout << endl;
				it->deposit(deposit_amt);
			} else {
				cout << "ID not found." << endl;
				cout << endl;
			}
		} else if (choice == 3) {
			// WITHDRAW
			// find iterator for id
			int desiredId;
			cout << "Enter the ID of the account to find: ";
			cin >> desiredId;
			list<Account>::iterator it;
			it = find_id(accounts, desiredId);
			if (it != accounts.end()) {
				it->display_info();
				float withdrawal_amt;
				cout << "Amount to withdraw: ";
				cin >> withdrawal_amt;
				cout << endl;
				it->withdraw(withdrawal_amt);
			} else {
				cout << "ID not found." << endl;
				cout << endl;
			}
		} else if (choice == 4) {
			// ADD ACCOUNT
			add_account(accounts);
			cout << endl;
		} else if (choice == 5) {
			// FIND ACCOUNT AND DISPLAY
			int desiredId;
			cout << "Enter the ID of the account to find: ";
			cin >> desiredId;
			list<Account>::iterator it;
			it = find_id(accounts, desiredId);

			if (it != accounts.end()) {
				it->display_info();
				cout << endl;
			} else {
				cout << "ID not found." << endl;
				cout << endl;
			}
		}

	} while (choice != 0);

	return 0;
}

void add_account(list<Account>& account_list) {
	string name;
	string balance;

	cout << "Enter the name: ";
	cin >> name;
	cout << "Enter the initial balance: ";
	cin >> balance;

	Account account{name, stoi(balance)};

	account_list.push_back(account);


}

void display_accounts(list<Account>& account_list) {
	list<Account>::iterator it;
	for (it = account_list.begin(); it != account_list.end(); it++) {
		it->display_info();
	}
}

list<Account>::iterator find_id(list<Account>& account_list, int id) {
	list<Account>::iterator it;
	for (it = account_list.begin(); it != account_list.end(); it++) {
		if (it->get_id() == id) {
			return it;
		}
	}
	return it;
}











