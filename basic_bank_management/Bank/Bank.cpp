#include "Bank.hpp"
#include <iostream>
void Bank::createAccount(string accountNumber, double initial_balance) {
  BankAccount new_account(accountNumber, initial_balance);
  this->accounts.push_back(new_account);
}
BankAccount* Bank::findAccount(string number_search) {
  for (BankAccount &account : this->accounts) {
    if (number_search == account.getAccountNumber()) {
      return &account;
    }
  }
  return nullptr;
}
int Bank::transferMoney(string des, string src, double money_transfer) {
  BankAccount *des_user = this->findAccount(des);
  BankAccount *src_user = this->findAccount(src);
  
  if (!des_user || !src_user) {
    return 2;
  }
  int check = src_user->processWithdrawal(money_transfer);
  if (check == 0) {
    src_user->processDeposit(money_transfer);
    return 3;
  }
  des_user->processDeposit(money_transfer);
  return 1;
}
void Bank::deposit(string des, double amount) {
  BankAccount *user = this->findAccount(des);
  if (!user) {
    cout << "No such users!\n";
    return;
  }
  user->processDeposit(amount);
}
void Bank::withdraw(string des, double amount) {
    BankAccount *user = this->findAccount(des);
  if (!user) {
    cout << "No such users!\n";
    return;
  }
  user->processWithdrawal(amount);
}
void Bank::printAccounts() {
  for (auto& account : this->accounts) {
    cout << account.getAccountNumber() << ' ' << account.getBalance() << '\n';
  }
}