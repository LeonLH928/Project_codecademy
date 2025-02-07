#include "BankAccount.hpp"
BankAccount::BankAccount(string accountNumber, double balance) : accountNumber(accountNumber), balance(balance), history("History:\n"),
history_order(0) {}
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
void BankAccount::processDeposit(double amount) {
  Transaction transaction_amount(amount);
  transaction_amount.deposit(*this);
}
int BankAccount::processWithdrawal(double amount) {
  Transaction transaction_amount(amount);
  return transaction_amount.withdraw(*this);
}
void BankAccount::printHistory() {
  cout << this->history;
}
void BankAccount::incrementOrderByOne() {
  this->history_order++;
}
int BankAccount::getOrder() {
  return this->history_order;
}
void BankAccount::addHistory(string new_history) {
  this->history += new_history;
}