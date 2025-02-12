# Project Title: 
Basic Bank Management
# Description: 
This project:
+ simulates basic functionalities of a bank.
+ is implemented in C++.
+ is to show implementations of encapsulation's concepts in Object-oriented programming.
+ uses knowledge of encapsulation like access specifiers, nested class, etc.
+ For information about what this project can do, please check the Bank.hpp in Bank and BankAccount.hpp in BankAccount


# Features
+ Depositing, withdrawing, transferring, and history review.

# How to use:
1. In testing.cpp, create a *bank* object and create bank accounts stored in this *bank* using method *.createAccount(string account_number, int initial_balance)* 
2. Try using and playing around with these methods:
+ *.printAccounts()*: print all the accounts followed by their **current** balance.
+ *.deposit(string account_number, int deposit)*: deposit money into one bank account.
+ *.withdraw(string account_number, int withdrawal)*: withdraw money from one bank account.
+ *.transferMoney(string des_account_number, string src_account_number, int amount_transfer)*: transfer an amount of money from one account to another account. There are 3 possibilites for this method: 1 if the transaction is successful, 2 if the account is not found, 3 if there is no enough money.
+ *.printHistory()*: print deposit, withdraw and transaction history of one *BankAccount* object.


# Collaborators: 
This project is developved by myself based on the instructions given on Codecademy.
# License: 
MIT license.