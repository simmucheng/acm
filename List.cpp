#include<stdio.h>
#include<stdlib.h>
typedef  struct LNode
{
	int data;
	struct LNode *next;
}LNode,*Llist;
LNode *creat_head();//创建一个空表
void creat_list(LNode *,int);//创建一个长度为n的线性链表
void insert_list(LNode *,int,int );//插入一个元素
int delete_list(LNode *,int);//删除一个元素
int found_list(LNode *,int);//链表查询
void reverse(LNode *);//倒置整个链表
void delete_whole(LNode *);//删除整个链表
void print_list(LNode *);//打印链表

main()
{
	LNode *head;
	int n,n2;
	int x,i;
　　int b;
	char temp1,temp2;
　　head=creat_head();
　　printf("请输入链表的节点个数n=");
　　scanf("%d",&n);
　　printf("\n请输入数据：\n");
　　creat_list(head,n);//创建链表
	print_list(head);
　　printf("\n*********************************************************\n");
	printf("\n下面进行链表插入元素\n");
	printf("\n请输入您需要插入的元素x=");
　　scanf("%d",&x);
　　printf("\n请输入即将插入的位置 i=");
　　scanf("%d",&i);
　　insert_list(head,x,i);//插入元素
　　print_list(head);
　　printf("\n*********************************************************\n");
	printf("\n下面进行链表删除元素\n");
	printf("\n请输入即将删除元素的位置：i=");
　　scanf("%d",&i);
b=delete_list(head,i);//删除元素
print_list(head);
printf("\n\n成功删除元素：%d",b);
printf("\n*********************************************************\n");
	printf("\n下面进行链表查询\n");
	printf("\n请输入即将查询的元素：x=");
　　scanf("%d",&n2);
　　if(found_list(head,n2)>0)  //链表查询
		printf("找到了，在第%d的位置上",found_list(head,n2));
　　else
		printf("没有找到!");
　　printf("\n*********************************************************\n");
　　printf("\n是否倒置整个链表？Y/N\n");
	fflush(stdin);
	scanf("%c",&temp1);
　　if('Y'==temp1) //倒置链表
	{
　　reverse(head);
		print_list(head);
　　}
　　printf("\n*********************************************************\n");
	printf("\n是否删除整个链表？Y/N\n");
　　fflush(stdin);
	scanf("%c",&temp2);
　　if('Y'==temp2) //删除链表
	{
　　delete_whole(head);
　　printf("\n成功删除整个链表\n");
}
}

//创建一个空链表
LNode *creat_head()
{
	LNode  *p;
　　p=(Llist)malloc(sizeof(LNode));
	if(NULL==p)
		printf("内存申请失败！");
	else
	{
　　p->next=NULL;
　　return(p);
	}
}

//创建一个长度为n的线性链表
void creat_list(LNode *head,int n)
{
	LNode *p,*q;
	int i;
	p=head;
　　for(i=1;i<=n;i++)
	{
		q=(Llist)malloc(sizeof(LNode));
		if(NULL==p)
			printf("内存申请失败！");
		else
		{
			printf("data:");scanf("%d",&q->data);
			q->next=NULL;
			p->next=q;
			p =q;
		}
	}
}

//插入一个元素
void insert_list(LNode *head,int x,int i )
{
　　int j=0;
	LNode *p,*s;
	p=head;
　　while((p!=NULL)&&(j<i-1))
	{
		p=p->next;
		j++;
	}
　　if(p==NULL)  exit(0);
　　s=(Llist)malloc(sizeof(LNode));
	if(NULL==p)
		printf("内存申请失败！");
	else
	{
		s->data=x;
		s->next=p->next;
		p->next=s;
	}

}

//删除一个元素
int delete_list(LNode *head,int  i)
{
　　LNode *p,*q;
	int j=0;
	int x;
　　p=head;
　　while((p!=NULL)&&(j<i-1))
	{
		p=p->next;
		j++;
	}
　　if(p==NULL)  exit(0);
　　q=p->next;
	p->next=q->next;
	x=q->data;
	free(q);
	q=NULL;
	return(x);
}
//删除整个链表
void delete_whole(LNode *head)
{
	LNode *p,*q;
	p=head;
	while(p!=NULL)
	{
		q=p->next;
		free(p);
		p=q;
	}
}

//倒置链表
void reverse(LNode *head)
{
	LNode *p,*s,*t;
	p=head;
	s=p->next;
	while(s->next!=NULL)//主要置换过程
	{
		t=s->next;
		s->next=p;
		p=s;
		s=t;
	}
	s->next=p;
	head->next->next=NULL;//收尾
	head->next=s;//赋头
}

//打印链表
void print_list(LNode * head)
{
	LNode *p;

	for(p=head->next;p!=NULL;)
	{
		printf("%d   ",p->data);
		p=p->next;
	}
}

//链表查询
int found_list(LNode *head,int n)
{
	LNode *p;
	int i=1;
　　for(p=head->next;p!=NULL;)
	{
		if(n==p->data)
		{
			return i;
		}
		i++;
		p=p->next;
	}
	if(NULL==p)
		return 0;
}

