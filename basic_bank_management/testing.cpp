#include <iostream>
#include "Bank/Bank.hpp"

using namespace std;

int main() {
  Bank a_bank;
  // while (1) {
  //   cout << "Adding accounts... enter 1 to exit\n";
  //   int check;
  //   cin >> check;
  //   if (check == 1) break;
  //   cout << "Enter account number and balance respectively: \n";
  //   string account_number;
  //   double balance;
  //   getline(cin, account_number);
  //   cin >> balance;
  //   a_bank.createAccount(account_number, balance);
  // }
  a_bank.createAccount("1001", 5000);
  a_bank.createAccount("1002", 3000);
  a_bank.createAccount("1003", 2000);
  a_bank.printAccounts();
  a_bank.deposit("1001", 1000);
  a_bank.withdraw("1002", 500);
  a_bank.printAccounts();
  int result = a_bank.transferMoney("1002", "1001", 1000);
  if (result == 1) {
    cout << "The transaction was successful.\n";
    a_bank.printAccounts();
  }
  else if (result == 2) {
    cout << "No such users found.\n";
    a_bank.printAccounts();
  }
  else {
    cout << "No enough money to transfer.\n";
    a_bank.printAccounts();
  }
  BankAccount* account_1001 = a_bank.findAccount("1001");
  BankAccount* account_1002 = a_bank.findAccount("1002");
  BankAccount* account_1003 = a_bank.findAccount("1003");
  account_1001->printHistory();
  account_1002->printHistory();
  account_1003->printHistory();
  
  return 0;
}
