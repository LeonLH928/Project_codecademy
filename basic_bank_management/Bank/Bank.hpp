#include <vector>
#include "../BankAccount/BankAccount.hpp"
class Bank {
private:
  vector<BankAccount> accounts;
public:
  void createAccount(string accountNumber, double initial_balance);
  BankAccount* findAccount(string number_search);
  int transferMoney(string des, string src, double money_transfer);
  void deposit(string des, double amount);
  void withdraw(string des, double amount);
  void printAccounts(void);
  void addHistoryForTransfer(string des, string src, double amount);
  void addHistoryForWithdraw(string src, double amount);
  void addHistoryForDeposit(string src, double amount);
};