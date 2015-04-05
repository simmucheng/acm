#include<stdio.h>
#include<stdlib.h>
typedef  struct LNode
{
	int data;
	struct LNode *next;
}LNode,*Llist;
LNode *creat_head();//����һ���ձ�
void creat_list(LNode *,int);//����һ������Ϊn����������
void insert_list(LNode *,int,int );//����һ��Ԫ��
int delete_list(LNode *,int);//ɾ��һ��Ԫ��
int found_list(LNode *,int);//�����ѯ
void reverse(LNode *);//������������
void delete_whole(LNode *);//ɾ����������
void print_list(LNode *);//��ӡ����

main()
{
	LNode *head;
	int n,n2;
	int x,i;
����int b;
	char temp1,temp2;
����head=creat_head();
����printf("����������Ľڵ����n=");
����scanf("%d",&n);
����printf("\n���������ݣ�\n");
����creat_list(head,n);//��������
	print_list(head);
����printf("\n*********************************************************\n");
	printf("\n��������������Ԫ��\n");
	printf("\n����������Ҫ�����Ԫ��x=");
����scanf("%d",&x);
����printf("\n�����뼴�������λ�� i=");
����scanf("%d",&i);
����insert_list(head,x,i);//����Ԫ��
����print_list(head);
����printf("\n*********************************************************\n");
	printf("\n�����������ɾ��Ԫ��\n");
	printf("\n�����뼴��ɾ��Ԫ�ص�λ�ã�i=");
����scanf("%d",&i);
b=delete_list(head,i);//ɾ��Ԫ��
print_list(head);
printf("\n\n�ɹ�ɾ��Ԫ�أ�%d",b);
printf("\n*********************************************************\n");
	printf("\n������������ѯ\n");
	printf("\n�����뼴����ѯ��Ԫ�أ�x=");
����scanf("%d",&n2);
����if(found_list(head,n2)>0)  //�����ѯ
		printf("�ҵ��ˣ��ڵ�%d��λ����",found_list(head,n2));
����else
		printf("û���ҵ�!");
����printf("\n*********************************************************\n");
����printf("\n�Ƿ�����������Y/N\n");
	fflush(stdin);
	scanf("%c",&temp1);
����if('Y'==temp1) //��������
	{
����reverse(head);
		print_list(head);
����}
����printf("\n*********************************************************\n");
	printf("\n�Ƿ�ɾ����������Y/N\n");
����fflush(stdin);
	scanf("%c",&temp2);
����if('Y'==temp2) //ɾ������
	{
����delete_whole(head);
����printf("\n�ɹ�ɾ����������\n");
}
}

//����һ��������
LNode *creat_head()
{
	LNode  *p;
����p=(Llist)malloc(sizeof(LNode));
	if(NULL==p)
		printf("�ڴ�����ʧ�ܣ�");
	else
	{
����p->next=NULL;
����return(p);
	}
}

//����һ������Ϊn����������
void creat_list(LNode *head,int n)
{
	LNode *p,*q;
	int i;
	p=head;
����for(i=1;i<=n;i++)
	{
		q=(Llist)malloc(sizeof(LNode));
		if(NULL==p)
			printf("�ڴ�����ʧ�ܣ�");
		else
		{
			printf("data:");scanf("%d",&q->data);
			q->next=NULL;
			p->next=q;
			p =q;
		}
	}
}

//����һ��Ԫ��
void insert_list(LNode *head,int x,int i )
{
����int j=0;
	LNode *p,*s;
	p=head;
����while((p!=NULL)&&(j<i-1))
	{
		p=p->next;
		j++;
	}
����if(p==NULL)  exit(0);
����s=(Llist)malloc(sizeof(LNode));
	if(NULL==p)
		printf("�ڴ�����ʧ�ܣ�");
	else
	{
		s->data=x;
		s->next=p->next;
		p->next=s;
	}

}

//ɾ��һ��Ԫ��
int delete_list(LNode *head,int  i)
{
����LNode *p,*q;
	int j=0;
	int x;
����p=head;
����while((p!=NULL)&&(j<i-1))
	{
		p=p->next;
		j++;
	}
����if(p==NULL)  exit(0);
����q=p->next;
	p->next=q->next;
	x=q->data;
	free(q);
	q=NULL;
	return(x);
}
//ɾ����������
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

//��������
void reverse(LNode *head)
{
	LNode *p,*s,*t;
	p=head;
	s=p->next;
	while(s->next!=NULL)//��Ҫ�û�����
	{
		t=s->next;
		s->next=p;
		p=s;
		s=t;
	}
	s->next=p;
	head->next->next=NULL;//��β
	head->next=s;//��ͷ
}

//��ӡ����
void print_list(LNode * head)
{
	LNode *p;

	for(p=head->next;p!=NULL;)
	{
		printf("%d   ",p->data);
		p=p->next;
	}
}

//�����ѯ
int found_list(LNode *head,int n)
{
	LNode *p;
	int i=1;
����for(p=head->next;p!=NULL;)
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

