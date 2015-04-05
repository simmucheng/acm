#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
class Rational
{
    long numerator;
    long denominator;
    public :
    Rational(long numerator,long denominator);
    void set(long x,long y)
    {
        this->numerator=x;
        this->denominator=y;
    }
    long getDenominator()
    {
        return this->denominator;
    }
    long getNumerator()
    {
        return this->numerator;
    }
    long gcd(long n,long d);
    Rational add(Rational &secondRational);
    void co()
    {
        cout<<this->numerator<<'/'<<this->denominator<<endl;
    }
};
long Rational::gcd(long n, long d) {
  //int n1 = abs((int)n);
  long n1=n>0?n:-n;
  long n2=d>0?d:-d;
  //int n2 = abs((int)d);
  int gcd = 1;
  for (int k = 1; k <= n1 && k <= n2; k++)
  {
    if (n1 % k == 0 && n2 % k == 0)
      gcd = k;
  }
  return gcd;
}
Rational ::Rational(long numerator,long denominator)
{
    long factor = gcd(numerator,denominator);
    //cout<<"GCD"<<factor<<endl;
    //while()
    //cout<<numerator<<'/'<<denominator<<endl;
    //this->numerator=numerator/factor;
   // this->denominator=denominator/factor;
    cout<<numerator<<'/'<<denominator<<endl;
}
Rational Rational::add(Rational &secondRational)
{
  cout<<numerator<<"vjnfiehb"<<endl;
  long n=numerator*secondRational.getDenominator()+denominator*secondRational.getNumerator();
  long d=denominator*secondRational.getDenominator();
  //cout<<"n = "<<n<<' '<<"d = "<<d<<endl;
  return Rational(n, d);
}
int main()
{
    long i,j,m,n;
    m=1;
    n=2;
    Rational A(1,2);
    Rational B(1,2);
    for(i=1;i<10;i++)
    {
        B.set(++m,++n);
        B.co();
        A.add(B);
    }

    return 0;
}
