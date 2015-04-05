#include<iostream>
#include<cstring>
using namespace std;
class student
{
  int a,b;
  public:
  string teacher()
  {
      char s[91]="this is a jok";
      //cout<<"bniur"<<endl;
      return s;
  }
  void p()
  {
      cout<<"TTTT"<<endl;
  }
  int master(int *x,int *y);
};
   int student::master(int *x,int *y)
{
    return *x+*y;
}
int main()
{

    int r1=1;
    int r2=2;
    student s1;
    cout<<s1.master(&r1,&zr2)<<endl;
    return 0;
}
