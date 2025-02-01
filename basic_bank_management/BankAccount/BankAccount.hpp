#include <string>
#include <iostream>
#include <vector>
using namespace std;
class BankAccount {
private:
  string accountNumber;
  double balance;
  class Transaction {
  private:
    double transaction_amount;
  public:
    Transaction(double amount);
    void deposit(BankAccount&);
    int withdraw(BankAccount&);
  };
public:
  BankAccount(string accountNumber, double balance);
  string getAccountNumber(void);
  double getBalance(void);
  void setAccountNumber(string new_accountNumber);
  void setBalance(double new_balance);
  void processDeposit(double amount);
  int processWithdrawal(double amount);
};
