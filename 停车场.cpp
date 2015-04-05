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

//ջ��ʵ��
void InitStack (Stack &S)    //����һ����ջ S
{
  S.MaxSize=10;
  S.stack=new ElemType[S.MaxSize];
  if(!S.stack){
    cout<<"fail"<<endl;
    exit(1);
  }
  S.top=-1;
}
int EmptyStack (Stack S)   //��ջSΪ��ջ����1�����򷵻�0
{
  return S.top==-1;
}
void Push(Stack &S, ElemType item)   //Ԫ�� item��ջ
{
  if(S.top==S.MaxSize-1){
    int k=sizeof(ElemType);
    S.stack=(ElemType*)realloc(S.stack,2*S.MaxSize*k);
    S.MaxSize=2*S.MaxSize;
  }
  S.top++;
  S.stack[S.top]=item;
}
ElemType Pop(Stack &S)    //ջS��ջ��Ԫ�س�ջ������
{
  if(S.top==-1){
    cerr<<"Stack is empty!"<<endl;
    exit(1);
  }
  S.top--;
  return S.stack[S.top+1];
}
ElemType Peek(Stack S)   //ȡջS�ĵ�ǰջ��Ԫ�ز�����
{
  if(S.top==-1){
    cerr<<"Stack is empty!"<<endl;
    exit(1);
  }
  return S.stack[S.top];
}
void ClearStack (Stack &S)   //���ջs��ʹ��Ϊ��ջ
{
  if(S.stack){
    delete []S.stack;
    S.stack=0;
  }
  S.top=-1;
  S.MaxSize=0;
}

//���е�ʵ��
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
	//e.num=1;
	//e.time=10;
	Stack q;
    InitStack (q);
    LinkQueue Q;
	i=InitQueue(Q);
    int m,n,k;
    int ww=0;
    char du;
    node h;
    node s[100];
    int l=0;
    int marktime;
    cin>>n;
    while(cin>>du)
    {
        if(du=='A')
        {
         cin>>h.num>>h.time;
         if(l>=n){EnQueue(Q,h);cout<<"������ = ��"<<ww++<<endl;}
         else
          {
            cout<<"ͣ������� = ��"<<l<<endl;
            s[l++]=h;
          }
        }
        else if(du=='D')
        {
            node w[100];
            int x=0;
            cin>>h.num>>h.time;
            marktime=h.time;
            l--;
            k=l;
            while(1)
            {
                if(h.num==s[k].num)break;
                w[x++]=s[k];
                s[k].num=0;
                k--;
            }
            cout<<"�뿪��ʱ�� ��= "<<h.time-s[k].time<<"���ã� "<<h.time-s[k].time+5<<" Ԫ"<<endl;
            x--;
            while(1)
            {
                if(x==-1)break;
                s[k++]=w[x--];

            }
            node f;
            int u=QueueLength(Q);
            if(u>0)
            {
                ww--;
              //  l++;
                if(GetHead(Q,f)==1){f.time=(f.time-marktime);s[k]=f;}
                DeQueue(Q,e);
                l=k;
                l++;
            }
        }
        else if(du=='E')
        {
            cin>>h.num>>h.time;
            break;
        }
        cout<<endl;
    }
   // for(int k=0;k<l;k++)
      //  cout<<k<<' '<<s[k].num<<' '<<s[k].time<<endl;
    return 0;
}
















