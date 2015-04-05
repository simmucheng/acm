#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int change[201000];
int ma=0;
struct node
{
	int rr;
	int ll;
	int num;
}w[201000<<2];
struct node1
{
	int sta;
	int id;
}s[201000];
void build(int l,int r,int nn)
{
	 w[nn].ll=l;
	 w[nn].rr=r;
	 w[nn].num=r-l+1;
     if(l==r)return ;
     int mid=(l+r)/2;
     build(l,mid,nn<<1);
     build(mid+1,r,(nn<<1)+1);
     return ;
} 
void insert(int ss,int nn,int mark)
{
	//cout<<"ss = "<<ss<<' '<<w[nn].ll<<' '<<w[nn].rr<<' '<<w[nn].num<<endl;
	int mid=(w[nn].ll+w[nn].rr)/2;
    if(w[nn].num==0)return ;
    if(w[nn].ll==w[nn].rr)
    {
    	change[w[nn].ll]=mark;
    	//cout<<w[nn].ll<<' '<<mark<<endl;
    	w[nn].num--;
        ma=1;
    	return ;
    }
    //if(ma==1)
    if(ss<=w[nn<<1].num)
    insert(ss,nn<<1,mark);
    if(ma==1)w[nn].num--;
    else if(ss<=w[nn<<1].num+w[(nn<<1)+1].num)
    {
    	ss-=w[nn<<1].num;
        insert(ss,(nn<<1)+1,mark);
        if(ma==1)w[nn].num--;
    }
    return ;
}
/*void init(int nn)
{
     for(int ii=0;ii<=nn;ii++)

}*/
int main()
{
	int i,j,m,n;
	while(scanf("%d",&n)!=EOF)
	{
		//init(n);
		build(1,n,1);
         for(i=1;i<=n;i++)
         	scanf("%d%d",&s[i].sta,&s[i].id);
         for(i=n;i>=1;i--)
         	{
         		ma=0;
         		//cout<<"next = "<<s[i].sta+1<<' '<<s[i].id<<endl;
         		insert(s[i].sta+1,1,s[i].id);
         	}
         for(i=1;i<n;i++)
         	printf("%d ",change[i]);
         printf("%d\n",change[n]);
	}
	return 0;
}