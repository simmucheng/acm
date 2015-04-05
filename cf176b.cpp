#include<iostream>
#include<cstdio>
using namespace std;
__int64 k;
__int64 summ(__int64 ll)
{
    return (k+ll-2)*(k-ll+1)/2+1;
}
__int64 judge(__int64 mm,__int64 sta,__int64 end)
{
   
   while(sta<=end)
   {
   	__int64 mid=(sta+end)/2;
   	if(summ(mid)>mm)sta=mid+1;
    else if(mm>summ(mid)&&summ(sta)>mm)end=mid-1;
    else if(mm==summ(mid))return mid;
    else if(mm>summ(sta)&&mm<summ(sta-1))return sta;
    else if(mm==summ(sta))return sta;
   }
} 
int main()
{
	int i,j,m,n;
	__int64 num;
	while(scanf("%I64d%I64d",&num,&k)!=EOF)
	{
	 if(num==1)cout<<"0"<<endl;
	 else if(num<=k)cout<<"1"<<endl;
	 else if(num>summ(2))cout<<"-1"<<endl;
	 else 
	 {
	 __int64 sp=judge(num,2,k);
	 if(num-summ(sp))cout<<(k-sp+2)<<endl;
	 else cout<<k+1-sp<<endl;
    }
    } 
	return 0;
}