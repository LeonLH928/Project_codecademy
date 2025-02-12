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
  this->addHistoryForTransfer(des, src, money_transfer);
  return 1;
}
void Bank::deposit(string des, double amount) {
  BankAccount *user = this->findAccount(des);
  if (!user) {
    cout << "No such users!\n";
    return;
  }
  user->processDeposit(amount);
  this->addHistoryForDeposit(des, amount);
}
void Bank::withdraw(string des, double amount) {
  BankAccount *user = this->findAccount(des);
  if (!user) {
    cout << "No such users!\n";
    return;
  }
  user->processWithdrawal(amount);
  this->addHistoryForWithdraw(des, amount);
}
void Bank::printAccounts() {
  for (auto& account : this->accounts) {
    cout << "Account number " << account.getAccountNumber() << " has a balance of " << account.getBalance() << '\n';
  }
}
void Bank::addHistoryForTransfer(string des, string src, double amount) {
  BankAccount *des_user = this->findAccount(des);
  BankAccount *src_user = this->findAccount(src);
  des_user->incrementOrderByOne();
  src_user->incrementOrderByOne();
  string new_history_src = to_string(src_user->getOrder()) + ". " + "You transferred " + to_string(amount) + " dollars to the account with account number of " + des + "\n";
  src_user->addHistory(new_history_src);
  string new_history_des = to_string(des_user->getOrder()) + ". " + "You received " + to_string(amount) + " dollars from the account with account number of " + src + "\n";
  des_user->addHistory(new_history_des);
}
void Bank::addHistoryForWithdraw(string src, double amount) {
  BankAccount *user = this->findAccount(src);
  user->incrementOrderByOne();
  string new_his = to_string(user->getOrder()) + ". " + "You withdrawed " + to_string(amount) + " dollars.\n";
  user->addHistory(new_his);
}
void Bank::addHistoryForDeposit(string src, double amount) {
  BankAccount *user = this->findAccount(src);
  user->incrementOrderByOne();
  string new_his = to_string(user->getOrder()) + ". " + "You deposited " + to_string(amount) + " dollars.\n";
  user->addHistory(new_his);
}