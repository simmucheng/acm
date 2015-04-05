#include<iostream>
#include<algorithm>
#include<cstring>
#include<algorithm>
#include<stdlib.h>
#include<malloc.h>
#include<cstdio>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define NULL 0
typedef int Status;

using namespace std;
struct node
{
    char num;
    int time;
};

typedef struct QNode
{
    node r;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

QueuePtr p,q;


void InitQueue(LinkQueue &Q)/*构造空队列Q*/
{
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	//if(!Q.front)
		//exit(OVERFLOW);
     Q.front->next=NULL;
	// return OK;
}

Status QueueEmpty(LinkQueue Q)/*若Q为空，则返回TRUE,否则FALSE*/
{
	if(Q.front->next==NULL)
		return 1;
	else
		return 0;
}

Status GetHead(LinkQueue Q,node &e)/*用e返回Q的队头元素*/
{
	if(Q.front==Q.rear)
		return 0;
	p=Q.front->next;
	e=p->r;
	return true;
}

Status EnQueue(LinkQueue &Q,node e)/*插入元素e为Q的新的队尾元素*/
{
	//if(!()))
		//exit(OVERFLOW);
    p=(QueuePtr)malloc(sizeof(QNode));
	p->r=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return true;
}

Status DeQueue(LinkQueue &Q,node &e)/*删除Q的队头元素，并用e返回其值*/
{

	if(Q.front==Q.rear)
		return false;
	p=Q.front->next;
	e=p->r;
	Q.front->next=p->next;
	if(Q.rear==p)
		Q.rear=Q.front;
	free(p);
	return true;
}

int main()
{
    int m,n,k;
    char du;
    node h;
    node s[100];
    int l=0;
    LinkQueue Q;
	InitQueue(Q);
    cin>>n;
    while(cin>>du)
    {
        if(du=='A')
        {
         cin>>h.num>>h.time;
         if(l>=n){EnQueue(Q,h);}
         else
          {
            cout<<"state = "<<l<<endl;
            s[l++]=h;
          }
        }
        else if(du=='D')
        {
            node w[100];
            int x=0;
            cin>>h.num>>h.time;
            l--;
            k=l;
            while(1)
            {
                if(h.num==s[k].num)break;
                w[x++]=s[k];
                s[k].num=0;
                k--;
            }
            x--;
            while(1)
            {
                if(x==-1)break;
                s[k++]=w[x--];

            }
            if(!QueueEmpty())
            {
                s[k]=GetHead();
                DeQueue(Q,e);
                l=k;
            }
        }
        else if(du=='E')
        {
            cin>>h.num>>h.time;
            break;
        }
        cout<<endl;
    }
    for(int k=0;k<l;k++)
        cout<<k<<' '<<s[k].num<<' '<<s[k].time<<endl;
    return 0;
}

/*
2
A 1 4
D 1 8
A 2 3
A 3 4
A 4 5
*/
