#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int i,j,m,n;
    int Claim[4][3];
    int Allo[4][3];
    int CA[4][3];
    int S[3];
    int used[3];
    int leave[3];
    int state[4];
    while(1)
    {
        memset(used,0,sizeof(used));
        memset(state,0,sizeof(state));
        cout<<"Claim :"<<endl;
        for(i=0;i<4;i++)
            {
              for(j=0;j<3;j++)
              {
                  cin>>Claim[i][j];
                //  cout<<Claim[i][j]<<' ';
              }
          //    cout<<endl;
            }
        cout<<"Allo :"<<endl;
        for(i=0;i<4;i++)
        {
            for(j=0;j<3;j++)
              {
                  cin>>Allo[i][j];
                //  cout<<Allo[i][j]<<' ';
                  CA[i][j]=Claim[i][j]-Allo[i][j];
                  used[j]+=Allo[i][j];
              }
            //  cout<<endl;
        }
        for(i=0;i<4;i++)
        {
            for(j=0;j<3;j++)
              {
                  cout<<CA[i][j]<<' ';
                //  cout<<Allo[i][j]<<' ';
                  //CA[i][j]=Claim[i][j]-Allo[i][j];
                  //used[j]+=Allo[i][j];
              }
              cout<<endl;
        }
        cout<<"Resource:"<<endl;
        for(i=0;i<3;i++)
        {
            cin>>S[i];
           // cout<<S[i]<<' ';
            leave[i]=S[i]-used[i];

        }
        cout<<"Leave:"<<endl;
        for(i=0;i<3;i++)
        cout<<leave[i]<<' ';
        cout<<endl;
        while(1)
        {
            //cout<<"rtbh"<<endl;
          int m=0;
          for(i=0;i<4;i++)
           {
            if(state[i]==1)continue;
            int mark=0;
            if(CA[i][0]<=leave[0])
            {
                mark=1;
                for(j=1;j<3;j++)
                {
                    if(leave[j]<CA[i][j]){mark=0;break;}
                }
            }
            if(mark==1)
            {
                m=1;
                state[i]=1;
                cout<<"The number of "<<i+1<<"should be taken"<<endl;
                for(j=0;j<3;j++)
                {
                    leave[j]+=Allo[i][j];

                }
            }
           }
            if(m==0)break;
        }
        int end=0;
        for(i=0;i<3;i++)
        {
            if(leave[i]!=S[i]){end=1;break;}
        }
        if(end==0)cout<<"safe state"<<endl;
        else cout<<"unsafe state"<<endl;
    }
    return 0;
}
