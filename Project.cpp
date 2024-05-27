// Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Team Leader: Mohamed Elnakshbandy          ID:A20000755
// Team Member: Mohamed Elsayed               ID:A20000751
// Team Member: Mohamed Ayman Abdelwahab      ID:A20000763

#include <iostream>
#include <string>
using namespace std;

class Account
{
protected:
	double Balance;
	int NumberOfDepositThisMonth;
	int NumberWithDrawals;
	double AnnualInterestRate;
	double MonthlyServiceCharge;
public:
	//default construvtor
	Account()
	{
		Balance =0 ;
		NumberOfDepositThisMonth = 0;
		NumberWithDrawals = 0;
		AnnualInterestRate=0;
		MonthlyServiceCharge = 0;
	}
	//constructor
	Account(double B, double AIR)
	{
		Balance = B;
		AnnualInterestRate = AIR;
	}
	void setBalance(double B)
	{
		Balance = B;
	}
	double getBalance()
	{
		return Balance;
	}
	void setAnnualInterestRate(double AIR)
	{
		AnnualInterestRate = AIR;
	}
	double getAnnualInterestRate()
	{
		return AnnualInterestRate;
	}
	virtual void deposit( double Money) 
	{
		Balance = Balance + Money; 

	}
	virtual void Withdraw(double Money)
	{
		Balance = Balance - Money;

	}
	virtual  void calcInterest(void)
	{
		double MonthlyInterestRate;
		double MonthlyInterest;
		 MonthlyInterestRate= (AnnualInterestRate / 12);

		 MonthlyInterest = Balance * MonthlyInterestRate;
		 Balance = Balance + MonthlyInterest;

	}
	virtual void MonthlyProc(void)
	{
		Balance = Balance - MonthlyServiceCharge;
		
		MonthlyServiceCharge = 0;
		NumberOfDepositThisMonth = 0;
		NumberWithDrawals = 0;
	}


};

class SavingAccount : public Account
{
protected:
	bool ActiveStatus;

public:
	//default constructor
	SavingAccount()
	{
		if (Balance > 25.0)
		{
			ActiveStatus = true;
		}
		else
		{
			ActiveStatus = false;
		}
	}

	//constructor
	SavingAccount(double B,double AIR)
    { 
		Balance = B;
		AnnualInterestRate = AIR;
		CheckActiveStatus();
		
	}
	void CheckActiveStatus()
	{
		if (Balance < 25)
		{
			ActiveStatus = false;
		}
		else 
		{
			ActiveStatus = true;

		}
	}
	void deposit(double Money)
	{
		Balance = Balance + Money;
		CheckActiveStatus();
		NumberOfDepositThisMonth++;
	}
	void Withdraw(double Money)
	{

		if (Money <= Balance)
		{
			if (ActiveStatus == true)
			{
				Balance = Balance - Money;
				CheckActiveStatus();
				NumberWithDrawals++; 				
			}
			else 
			{
				cout << "Account is not active " << endl;
			}
		}
		else
		{
			cout << "Your Balance is Suffient: " << endl;

		}
	}

	void MonthlyProc()

	{
		if (NumberWithDrawals > 4)  
		{
			MonthlyServiceCharge = NumberWithDrawals  - 4 ;
			Balance = Balance - MonthlyServiceCharge;
			CheckActiveStatus();


		}
		else {
			MonthlyServiceCharge = 0; 
			cout << " no charge" << endl;
		}
		
	}
	bool getActiveStatus()
	{
		return ActiveStatus;
	}
};


class CheckingAccount :public Account
{

public : 
	 CheckingAccount(double B , double AIR )
	{
		Balance = B;
		AnnualInterestRate = AIR;
	}
	void Withdraw(double Money)
	{

		if (Money <= Balance)
		{

			Balance = Balance - Money;

			NumberWithDrawals++;
		}
		else
		{
			cout<<"transiction not made:"<<endl;
			Balance = Balance - 15; 

		}


	}


	void MonthlyProc()

	{
		

		MonthlyServiceCharge = 5 + NumberWithDrawals * 0.10;

		Balance = Balance - MonthlyServiceCharge; 

	}

};

int main()
{  
	SavingAccount A1(100 , 0.12);
	cout<<A1.getBalance()<<endl;
	cout << A1.getActiveStatus() << endl;
	A1.Withdraw(90); 
	cout << A1.getBalance() << endl;
	cout << A1.getActiveStatus() << endl;
	A1.deposit(190);
	cout << A1.getBalance() << endl;
	cout << A1.getActiveStatus() << endl;
	A1.calcInterest();
	cout << A1.getBalance() << endl;
	cout << A1.getActiveStatus() << endl;
	A1.Withdraw(10); 
	cout << A1.getBalance() << endl;
	cout << A1.getActiveStatus() << endl;
    A1.Withdraw(10);
	cout << A1.getBalance() << endl;
	cout << A1.getActiveStatus() << endl;
	A1.Withdraw(10);
	cout << A1.getBalance() << endl;
	cout << A1.getActiveStatus() << endl;
	A1.Withdraw(10);
	cout << A1.getBalance() << endl;
	cout << A1.getActiveStatus() << endl;
	A1.Withdraw(10);
	cout << A1.getBalance() << endl;
	cout << A1.getActiveStatus() << endl;
	A1.MonthlyProc(); 
	cout << A1.getBalance() << endl;
	cout << A1.getActiveStatus() << endl;
	cout << "////////////////////////////////////////" << endl;
	cout << "////////////////////////////////////////" << endl;
	
	SavingAccount A2(20, 0.10);
	cout << A2.getBalance() << endl;
	cout << A2.getActiveStatus() << endl;
	A2.Withdraw(10);
	cout << A2.getBalance() << endl;
	cout << A2.getActiveStatus() << endl;
	A2.Withdraw(10);
	cout << A2.getBalance() << endl;
	cout << A2.getActiveStatus() << endl;
	A2.Withdraw(10);
	cout << A2.getBalance() << endl;
	cout << A2.getActiveStatus() << endl;
	A2.Withdraw(10);
	cout << A2.getBalance() << endl;
	cout << A2.getActiveStatus() << endl;
	A2.Withdraw(10);
	cout << A2.getBalance() << endl;
	cout << A2.getActiveStatus() << endl;
	cout << "Checking Account testing " << endl; 
	cout << "opening account with balance 100 and interest rate 0.12 "<< endl;
	cout << "////////////////////////////////////////" << endl;
	cout << "////////////////////////////////////////" << endl;
	cout << "////////////////////////////////////////" << endl;
	cout << "////////////////////////////////////////" << endl;
	
	CheckingAccount CA1(100, 0.12); 
	cout << "your balance " << CA1.getBalance() << endl;
	cout << "with draw 20 $ " << endl;
	CA1.Withdraw(20); 
	cout <<"your balance "<<  CA1.getBalance() << endl;

	cout << "with draw 100 $ " << endl;
	CA1.Withdraw(10);

	cout << "your balance " << CA1.getBalance() << endl;


	cout << "with draw 10 $ " << endl;
	CA1.Withdraw(10);

	cout << "your balance " << CA1.getBalance() << endl;


	CA1.calcInterest(); 

	cout << "your balance " << CA1.getBalance() << endl;


	CA1.MonthlyProc();

	cout << "your balance " << CA1.getBalance() << endl;

	cout << "////////////////////////////////////////" << endl;
	cout << "////////////////////////////////////////" << endl;

	CheckingAccount CA2(100, 0.12);
	cout << "your balance " << CA1.getBalance() << endl;
	cout << "with draw 100 $ " << endl;
	CA1.Withdraw(100);
	cout << "your balance " << CA1.getBalance() << endl;

	cout << "with draw 105 $ " << endl;
	CA1.Withdraw(105);

	cout << "your balance " << CA1.getBalance() << endl;


	cout << "with draw 150 $ " << endl;
	CA1.Withdraw(150);

	cout << "your balance " << CA1.getBalance() << endl;


	CA1.calcInterest();

	cout << "your balance " << CA1.getBalance() << endl;


	CA1.MonthlyProc();

	cout << "your balance " << CA1.getBalance() << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
