#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<string>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define NULL 0
using namespace std;
struct node
{
    string  num;
    int time;
    int mark;

};
typedef node ElemType;
struct  Stack
{
    ElemType  *stack ;  // 存栈元素
    int  top;              // 栈顶指示器
    int MaxSize;            // 栈的最大长度
};
typedef node QElemType;
typedef int Status;


typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;


QueuePtr p,q;

//队列的实现
Status InitQueue(LinkQueue &Q)/*构造空队列Q*/
{
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q.front)
		exit(OVERFLOW);
     Q.front->next=NULL;
	 return OK;
}

/*Status QueueEmpty(LinkQueue Q)
{
	if(Q.front->next==0)
		return TRUE;
	else
		return FALSE;
}
*/

int QueueLength(LinkQueue Q)//返回队列Q的长度
{
	int i=0;
	p=Q.front;
	while(Q.rear!=p)
	{
		i++;
		p=p->next;
	}
	return i;
}


Status GetHead(LinkQueue Q,QElemType &r)/*用e返回Q的队头元素*/
{
	if(Q.front==Q.rear)
		return 0;
	p=Q.front->next;
	r=p->data;
	return OK;
}


Status EnQueue(LinkQueue &Q,QElemType e)/*插入元素e为Q的新的队尾元素*/
{
	if(!(p=(QueuePtr)malloc(sizeof(QNode))))
		exit(OVERFLOW);
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return OK;
}

Status DeQueue(LinkQueue &Q,QElemType &e)/*删除Q的队头元素，并用e返回其值*/
{

	if(Q.front==Q.rear)
		return ERROR;
	p=Q.front->next;
	e=p->data;
	Q.front->next=p->next;
	if(Q.rear==p)
		Q.rear=Q.front;
	free(p);
	return OK;
}


Status QueueTraverse(LinkQueue Q,void(*visit)(QElemType))/*依次对Q的每个数据元素调用函数visit()*/
{
	p=Q.front->next;
	while(p)
	{
		visit(p->data);
		p=p->next;
	}
	return OK;
	printf("\n");
}

void print(QElemType c)
{
	printf("%d ",c);
}


int main()
{
	int i;
	node e;
	Stack q;
    LinkQueue Q;
	i=InitQueue(Q);
	int m,n;
	node t;
	node r;
	while(cin>>n)
	{
	    cout<<"进程名"<<"运行时间"<<"状态"<<endl;
	    while(n--)
	    {
         cin>>t.num>>t.time;
         t.mark=t.time;
	     EnQueue(Q,t);
	    }
	    while(QueueLength(Q))
	    {
	        if(GetHead(Q,r)==1)
	        {
	          r.time-=(r.mark-1);
              cout<<r.num<<' '<<"unknow"<<" running"<<endl;
	          if(r.time>0){EnQueue(Q,r);cout<<r.num<<' '<<r.mark-1<<" ready"<<endl;}
	          else cout<<r.num<<' '<<r.time<<" finish"<<endl;
	        }
	    }
	}
   return 0;
}















