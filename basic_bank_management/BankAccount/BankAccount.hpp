#include <string>
#include <iostream>
#include <vector>
using namespace std;
class BankAccount {
private:
  string history;
  int history_order;
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
  void printHistory(void);
  void incrementOrderByOne(void);
  int getOrder(void);
  void addHistory(string new_history);
};
