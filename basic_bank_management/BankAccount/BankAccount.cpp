#include "BankAccount.hpp"
BankAccount::BankAccount(string accountNumber, double balance) : accountNumber(accountNumber), balance(balance) {}
string BankAccount::getAccountNumber() {
  return this->accountNumber;
}
double BankAccount::getBalance() {
  return this->balance;
}
void BankAccount::setAccountNumber(string new_accountNumber) {
  this->accountNumber = new_accountNumber;
}
void BankAccount::setBalance(double new_balance) {
  this->balance = new_balance;
}
BankAccount::Transaction::Transaction(double amount)
  : transaction_amount(amount) {}
void BankAccount::Transaction::deposit(BankAccount &account) {
  std::cout << "Your balance before transaction: " << account.getBalance() << '\n';
  account.setBalance(account.getBalance() + this->transaction_amount);
  std::cout << "Your balance after transaction: " << account.getBalance() << '\n';
}
int BankAccount::Transaction::withdraw(BankAccount &account) {
  if (account.getBalance() >= this->transaction_amount) {
    std::cout << "Your balance before transaction: " << account.getBalance() << '\n';
    account.setBalance(account.getBalance() - this->transaction_amount);
    std::cout << "Your balance after transaction: " << account.getBalance() << '\n';
    return 1;
  }
  std::cout << "You don't have enough money to withdraw!\n";
  return 0;
}
void BankAccount::processDeposit(double amount) {
  Transaction transaction_amount(amount);
  transaction_amount.deposit(*this);
}
int BankAccount::processWithdrawal(double amount) {
  Transaction transaction_amount(amount);
  return transaction_amount.withdraw(*this);
}
