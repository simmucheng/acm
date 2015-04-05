#include<iostream>
using namespace std;
class Account
{
      int id;
      double balance;
      double annualInterestRate;
     public:
     Account()
      {
          id=0;
          balance=0;
          annualInterestRate=0;
      }
      Account(int newid,double newbalance,double newannualInterestRate)
      {
          id=newid;  balance=newbalance; annualInterestRate=newannualInterestRate;
      }
      int getID()
      {
          return id;
      }
      void setID(int id)
      {
          this->id =id;
      }
      int getBalance()
      {
          return balance;
      }
      void setBaolance(int balance)
      {
           this->balance =balance;
      }
       int getAnnualInterestRate()
      {
          return annualInterestRate;
      }
      void setAnnualInterestRate(int annualInterestRate)
      {
           this->annualInterestRate =annualInterestRate;
      }
      double getMonthlyInterRate(double annualInterestRate)
      {
          return annualInterestRate/12;
      }
      double withDraw(double rbalance)
      {
          return balance-rbalance;
      }
      double deposit(double rbalance)
      {
          return balance+rbalance;
      }
};
int main()
{
    Account q(1122,20000,0.045);
    q.withDraw(2500);
    q.deposit(3000);
    cout<<q.getBalance()<<endl;
    cout<<q.getAnnualInterestRate();

}
