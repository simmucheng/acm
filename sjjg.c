#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
////////////////////////////////////////////

//����������
typedef struct Node
{
    ElemType data;              //�������е�������
    struct Node *next;          //��������ָ����
}Node,*LinkedList;

////////////////////////////////////////////

//�������ĳ�ʼ��

LinkedList LinkedListInit()
{
    Node *L;
    L = (Node *)malloc(sizeof(Node));   //������ռ�
    if(L == NULL)                       //�ж��Ƿ����㹻���ڴ�ռ�
        printf("�����ڴ�ռ�ʧ��\n");
    L->next = NULL;                  //��next����ΪNULL,��ʼ����Ϊ0�ĵ�����
}

////////////////////////////////////////////

//�������Ľ���1��ͷ�巨����������

LinkedList LinkedListCreatH()
{
    Node *L;
    L = (Node *)malloc(sizeof(Node));   //����ͷ���ռ�
    L->next = NULL;                      //��ʼ��һ��������

    ElemType x;                         //xΪ�����������е�����
    while(scanf("%d",&x) != EOF)
    {
        Node *p;
        p = (Node *)malloc(sizeof(Node));   //�����µĽ��
        p->data = x;                     //���������ֵ
        p->next = L->next;                    //�������뵽��ͷL-->|2|-->|1|-->NULL
        L->next = p;
    }
    return L;
}

////////////////////////////////////////////

//�������Ľ���2��β�巨����������

LinkedList LinkedListCreatT()
{
    Node *L;
    L = (Node *)malloc(sizeof(Node));   //����ͷ���ռ�
    L->next = NULL;                  //��ʼ��һ��������
    Node *r;
    r = L;                          //rʼ��ָ���ն˽�㣬��ʼʱָ��ͷ���
    ElemType x;                         //xΪ�����������е�����
    while(scanf("%d",&x) != EOF)
    {
        Node *p;
        p = (Node *)malloc(sizeof(Node));   //�����µĽ��
        p->data = x;                     //���������ֵ
        r->next = p;                 //�������뵽��ͷL-->|1|-->|2|-->NULL
        r = p;
    }
    r->next = NULL;

    return L;
}

////////////////////////////////////////////

//�������Ĳ��룬�������ĵ�i��λ�ò���x��Ԫ��

LinkedList LinkedListInsert(LinkedList L,int i,ElemType x)
{
    Node *pre;                      //preΪǰ�����
    pre = L;
    int tempi = 0;
    for (tempi = 1; tempi < i; tempi++)
        pre = pre->next;                 //���ҵ�i��λ�õ�ǰ�����
    Node *p;                                //����Ľ��Ϊp
    p = (Node *)malloc(sizeof(Node));
    p->data = x;
    p->next = pre->next;
    pre->next = p;

    return L;
}

////////////////////////////////////////////

//��������ɾ������������ɾ��ֵΪx��Ԫ��

LinkedList LinkedListDelete(LinkedList L,ElemType x)
{
    Node *p,*pre;                   //preΪǰ����㣬pΪ���ҵĽ�㡣
    p = L->next;
    while(p->data != x)              //����ֵΪx��Ԫ��
    {
        pre = p;
        p = p->next;
    }
    pre->next = p->next;          //ɾ������������ǰ��nextָ�����̡�
    free(p);
    return L;
}

/////////////////////////////////////////////

int main()
{
    LinkedList list,start;
/*  printf("�����뵥���������ݣ�");
    list = LinkedListCreatH();
    for(start = list->next; start != NULL; start = start->next)
        printf("%d ",start->data);
    printf("\n");
*/  printf("�����뵥���������ݣ�");
    list = LinkedListCreatT();
    for(start = list->next; start != NULL; start = start->next)
        printf("%d ",start->data);
    printf("\n");

    int i;
    ElemType x;
    printf("������������ݵ�λ�ã�");
    scanf("%d",&i);
    printf("������������ݵ�ֵ��");
    scanf("%d",&x);
    LinkedListInsert(list,i,x);
    for(start = list->next; start != NULL; start = start->next)
        printf("%d ",start->data);
    printf("\n");
    printf("������Ҫɾ����Ԫ�ص�ֵ��");
    scanf("%d",&x);
    LinkedListDelete(list,x);
    for(start = list->next; start != NULL; start = start->next)
        printf("%d ",start->data);
    printf("\n");

    return 0;
}