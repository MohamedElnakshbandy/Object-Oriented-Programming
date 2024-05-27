# Object-Oriented-Programming

Banking System Project

Overview:
This project implements a simple banking system with different account types, 
allowing for deposits, withdrawals, and monthly processing. 
It includes classes for generic accounts, savings accounts, and checking accounts, each with specific behaviors and rules.

Features:
Account Management: Basic account operations like deposits, withdrawals, and interest calculations.
Savings Account: Special rules for active/inactive status and additional withdrawal charges.
Checking Account: Specific rules for overdrafts and monthly service charges.

Classes:
Account Class
A base class for managing a bank account.

Attributes:
Balance: Account balance.
NumberOfDepositThisMonth: Number of deposits made this month.
NumberWithDrawals: Number of withdrawals made this month.
AnnualInterestRate: Annual interest rate.
MonthlyServiceCharge: Monthly service charge.

Methods:
setBalance(double B): Set account balance.
getBalance(): Get account balance.
setAnnualInterestRate(double AIR): Set annual interest rate.
getAnnualInterestRate(): Get annual interest rate.
deposit(double Money): Deposit money.
Withdraw(double Money): Withdraw money.
calcInterest(): Calculate and apply monthly interest.
MonthlyProc(): Process monthly service charges and reset transaction counters.

SavingAccount Class
Inherits from Account and adds specific rules for savings accounts.

Attributes:
ActiveStatus: Indicates if the account is active.

Methods:
CheckActiveStatus(): Check and update active status.
deposit(double Money): Deposit money, update status, and increment deposit counter.
Withdraw(double Money): Withdraw money if active and balance is sufficient, update status, and increment withdrawal counter.
MonthlyProc(): Apply service charges for excess withdrawals and update status.

CheckingAccount Class
Inherits from Account and adds specific rules for checking accounts.

Methods:
Withdraw(double Money): Withdraw money if balance is sufficient or apply penalty for overdrafts.
MonthlyProc(): Apply fixed monthly service charges and per-withdrawal charges.

The main function demonstrates the usage of the SavingAccount and CheckingAccount classes:

Creates instances of SavingAccount and CheckingAccount.
Performs various operations like deposits, withdrawals, interest calculation, and monthly processing.
Outputs the account balance and status after each operation to the console.

Getting Started :
Clone the repository.
Open the project in your preferred C++ development environment.
Compile and run Project.cpp to see the banking system in action.

License:
This project is licensed under the MIT License - see the LICENSE.md file for details.
