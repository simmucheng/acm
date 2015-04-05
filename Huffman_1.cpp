#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxvalue 0x7fffffff
struct cam1
{
	char c;
	char s[50];
	int len;
}zimu[30];
struct cam2
{
	int weight;
	int parent,lchild,rchild;
}list[60];
void init()
{
	int i;
	for(i=0;i<26;i++)
	zimu[i].c='a'+i;
}
void huffmantree()
{
	int i,j;
	int x1,x2;
	int m1,m2;
	int pindu[100];  //26个字母的频度
	for(i=0;i<60;i++)
	list[i].parent=list[i].lchild=list[i].rchild=-1;
	for(i=0;i<n;i++)
	list[i].weight=pindu[i];
	for(i=0;i<25;i++)
	{
		x1=x2=0;
		m1=m2=maxvalue;
		for(j=0;j<26+i;j++)
		{
			if(list[j].weight<m1&&list[j].parent==-1)
			{
				x2=x1;
				m2=m1;
				x1=j;
				m1=list[j].weight;
			}
			else if(list[j].weight<m2&&list[j].parent==-1)
			{
				x2=j;
				m2=list[j].weight;
			}
		}
		list[26+i].lchild=x1;
		list[26+i].rchild=x2;
		list[x1].parent=list[x2].parent=26+i;
		list[26+i].weight=list[x1].weight+list[x2].weight;
	}
}
void huffmanbianma()
{
	int i,j,start;
	char s[100];
	int p,c,k;
	for(i=0;i<26;i++)
	{
		memset(s,0,sizeof(s));
		start=40;
		c=i;
		p=list[c].parent;
		while(p!=-1)
		{
			if(list[p].lchild==c)
			s[start]='0';
			else
			s[start]='1';
			start--;
			c=p;
			p=list[c].parent;
		}
		for(k=0,j=start+1;j<=40;k++,j++)
		zimu[i].s[k]=s[j];
		zimu[i].s[k]='\0';
		zimu[i].len=k;
	}
	printf("26个字母的哈夫曼编码如下：\n");
	for(i=0;i<26;i++)
	printf("%c----->%s\n",'a'+i,zimu[i].s);
}
int main()
{
	int i,j;
	int ans,len;
	char str[1000];
	int k1,k2,flag;
	printf("Welcome to Cambridgeacm\n");
	init();
	huffmantree();
	huffmanbianma();
	printf("输入1时执行编码\n");
	printf("输入2时执行译码\n");
	while(scanf("%d",&ans)!=EOF)
	{
		switch(ans)
		{
		    case 1:
			{
                 printf("请输入一段字符串\n");
                 scanf("%s",str);
				 len=strlen(str);
				 for(i=0;i<len;i++)
				 printf("%s",zimu[str[i]-'a'].s);
				 printf("\n");
				 printf("编码结束\n");
			}
			case 2:
			{
			     printf("请输入一段01代码\n");
				 scanf("%s",str);
                 len=strlen(str);
				 for(i=0;i<len;i++)
				 {
					 for(j=0;j<26;j++)
					 {
						 flag=1;
						 for(k1=i,k2=0;k1<=i+zimu[j].len-1&&str[k1]!='\0';k1++,k2++)
						 if(str[k1]!=zimu[j].s[k2])
						 {
							 flag=0;
							 break;
						 }
						 if(flag)
						 {
							 printf("%c",zimu[j].c);
							 i+=(zimu[j].len-1);
							 break;
						 }
					 }
				 }
				 printf("\n");
				 printf("译码结束\n");
			}
		}
	}
	return 0;
}

