#include<iostream>
using namespace std;
int main()
{
    int i,j,m,n;
    cin>>n;
    while(n--)
    {
        cin>>m;
        for(i=3;;i++)
        {
            double rr=180.0-360.0/i;
            double ee=180.0-360.0/(i+1);
            if(rr==m){cout<<"YES"<<endl;break;}
            else if(m<rr){cout<<"NO"<<endl;break;}
            else if(rr<m&&m<ee){cout<<"NO"<<endl;break;}
        }
    }
    return 0;
}
