#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<stack>
using namespace std;
stack <char> w;
stack <char> d;
int main()
{
    int i,j,m,n;
    int s[23];
    int u[23];
    cin>>n;
    while(n--)
    {
        int a=0;
        int b=0;
        cin>>m;
        int y=m;
        for(i=0;i<m;i++)
        {
        cin>>s[i];
        while(a<s[i])
        {
          w.push('(');
          a++;
        }
        w.push(')');
        }
       /* while(!w.empty())
        {
            char h=w.top();
            cout<<h;
            w.pop();
        }*/
  //  }
        while(!w.empty())
        {
            w.pop();
            int a1=1;
            int a2=0;
            while(!w.empty())
            {

                char t;
                t=w.top();
                d.push(t);
                w.pop();
                if(t==')')a1++;
                else if(t=='(')a2++;
                if(a1==a2){u[--m]=a1;break;}
            }
            d.pop();
            while(!d.empty())
            {
                char f;
                f=d.top();
                w.push(f);
                d.pop();
            }
        }
        for(i=0;i<y;i++)
        cout<<u[i]<<' ';
        cout<<endl;
    }
    return 0;
}
