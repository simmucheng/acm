#include<stdio.h>
int main()
{
    char s[4];
    int x,y,z,i,j,m,n;
    while(scanf("%s",&s)==1)
    {
        m=strlen(s)-2;
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]=='0'&&s[i+1]=='0'){printf("-1\n");continue;}
        }
              else {
                  if(strlen(s)==8)
                  {

                  }
        x=(s[0]-'0')*10+(s[1]-'0')+(s[2]-'0')+(s[3]-'0');
        y=(s[1]-'0')*10+(s[0]-'0')+(s[2]-'0')+(s[3]-'0');
        z=(s[2]-'0')*10+(s[0]-'0')+(s[1]-'0')+(s[3]-'0');
        if(x>=y)m=x;
        else m=y;
        if(m>=z)n=m;
        else n=z;
        printf("%d\n",n);
        }
    }
    return 0;
}
