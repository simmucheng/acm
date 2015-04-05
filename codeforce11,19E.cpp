#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int i,j,m,n;
    int t;
    char s[410];
    int a,b;
    int sum1,sum2;
    while(cin>>s)
    {
        a=b=0;
        int num1=0;
        int num2=0;
        int e=0;
        t=strlen(s);
        for(i=0;i<t;i++)
        {
            if(s[i]=='+')
                {
                    num1++;
                    if(num2>0)num2--;
                }
            else if(s[i]=='-')
                {
                    num2++;
                    if(num1>0)num1--;
                }
            //e=max(abs(num1-num2),e);
        }
        cout<<num1+num2<<endl;
        memset(s,0,sizeof(s));
    }
    return 0;
}
