#include<iostream>
using namespace std;
int binary(int y,int num)
{
	if(num==0)return 1;
	if(y%2==1)return binary(y*y,num/2)*y;
    else return binary(y*y,num/2);
}
int main()
{
	int i,j,m,n;
	cin>>n;
    for(i=1;i<n;i++)
    {
    	for(j=1;j<n;j++)
    	if(binary())
    }
	return 0;
}