#include "BankAccount.hpp"
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
