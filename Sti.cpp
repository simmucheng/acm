#include<iostream>
using namespace std;
int main()
{
    int a,b,n,boat,man,bad;
    cin>>n;
    while(n--)
   {
       cin>>boat>>man;
       a=man;
       man-=boat;
       bad=(boat-1)/3+1;
       bad=(man-bad)/3;
       if(boat==1)bad=a/2;
       if(man==1)bad=1;
       cout<<bad<<endl;
   }
   return 0;
}
