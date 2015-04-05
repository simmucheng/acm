#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    double  y1,y2,yw,xb,yb,r;
    while(cin>>y1>>y2>>yw>>xb>>yb>>r)
    {
        double xx;
        double len1,len2;
        len1=yw-r-(y1+y2)/2;
        if(yb<=(y1+y2)/2)
        {
        len2=yw-r-yb;
        xx=(len2/len1)*r+r;
        if(xx>xb)cout<<"-1"<<endl;
        else printf("%.10f\n",xx);
        }
       // else
        //{
          //  len2=yw-r-yb;
            //xx=
        //}
    }
    return 0;
}
