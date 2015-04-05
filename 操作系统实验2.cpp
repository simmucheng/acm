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
    ElemType  *stack ;  // ��ջԪ��
    int  top;              // ջ��ָʾ��
    int MaxSize;            // ջ����󳤶�
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

//���е�ʵ��
Status InitQueue(LinkQueue &Q)/*����ն���Q*/
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

int QueueLength(LinkQueue Q)//���ض���Q�ĳ���
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


Status GetHead(LinkQueue Q,QElemType &r)/*��e����Q�Ķ�ͷԪ��*/
{
	if(Q.front==Q.rear)
		return 0;
	p=Q.front->next;
	r=p->data;
	return OK;
}


Status EnQueue(LinkQueue &Q,QElemType e)/*����Ԫ��eΪQ���µĶ�βԪ��*/
{
	if(!(p=(QueuePtr)malloc(sizeof(QNode))))
		exit(OVERFLOW);
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return OK;
}

Status DeQueue(LinkQueue &Q,QElemType &e)/*ɾ��Q�Ķ�ͷԪ�أ�����e������ֵ*/
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


Status QueueTraverse(LinkQueue Q,void(*visit)(QElemType))/*���ζ�Q��ÿ������Ԫ�ص��ú���visit()*/
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
	    cout<<"������"<<"����ʱ��"<<"״̬"<<endl;
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















