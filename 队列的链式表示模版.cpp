#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define NULL 0
using namespace std;
struct node
{
    char num;
    int time;
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


Status InitQueue(LinkQueue &Q)/*����ն���Q*/
{
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q.front)
		exit(OVERFLOW);
     Q.front->next=NULL;
	 return OK;
}


Status DestroyQueue(LinkQueue &Q)/*���ٶ���Q*/
{
	while(Q.front)
	{
		Q.rear=Q.front->next;
		free(Q.front);
		Q.front=Q.rear;
	}
	return OK;
}


Status ClearQueue(LinkQueue &Q)/*��ն���Q*/
{
	Q.rear=Q.front;
	p=Q.front->next;
	Q.front->next=NULL;
	while(p)
	{
		q=p;
		p=p->next;
		free(q);
	}
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

/*Status QueueEmpty(LinkQueue Q)
//��QΪ�գ��򷵻�TRUE,����FALSE
{
	if(Q.front->next)
		return TRUE;
	else
		return FALSE;
}
*/
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
	e.num=1;
	e.time=10;
    LinkQueue Q;
	i=InitQueue(Q);

	/*printf("�Ƿ�ɹ��Ĺ�����һ���ն��У�%d(1:�� 0:��)\n",i);
	printf("�Ƿ�ն���?%d(1:�� 0:��)\n",QueueEmpty(Q));
    printf("���еĳ���Ϊ%d\n",QueueLength(Q));
	EnQueue(Q,e);
    //EnQueue(Q,5);
   // EnQueue(Q,10);
	printf("����3��Ԫ��(-5,5,10),���еĳ���Ϊ:%d\n",QueueLength(Q));
	printf("�Ƿ�ն���?%d(1:��0:��)\n",QueueEmpty(Q));
    printf("���е�Ԫ������Ϊ:");
	QueueTraverse(Q,print);
	printf("\n");
    i=GetHead(Q,e);
	if(i==1)
		printf("���е�ͷԪ��Ϊ:%d\n",e);
    DeQueue(Q,e);
	printf("ɾ���Ķ��е�ͷԪ��Ϊ:%d\n",e.time);
    i=GetHead(Q,e);
	if(i==1)
		printf("���е���ͷԪ��Ϊ:%d\n",e);
	ClearQueue(Q);
    printf("��ն��к�:Q.front=%u  Q.rear=%u  Q.front->next=%u\n",Q.front,Q.rear,Q.front->next);
	DestroyQueue(Q);
    printf("���ٶ��к�:Q.front=%u  Q.rear=%u\n",Q.front,Q.rear);*/

    int m,n,k;
    int ww=0;
    char du;
    node h;
    node s[100];
    int l=0;
    cin>>n;
    while(cin>>du)
    {
        if(du=='A')
        {
         cin>>h.num>>h.time;
        if(l>=n){EnQueue(Q,h);cout<<"queue = "<<ww++<<endl;}
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
            node f;
            int u=QueueLength(Q);
            if(u>0)ww--;
            if(u>0)
            {
                 //w=w-1;
                if(GetHead(Q,f)==1)s[k]=f;
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













