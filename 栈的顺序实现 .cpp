/*ʵ��Ŀ�ĺ�Ҫ��
1������ջ�Ĵ洢�ṹ�������������ѧ�ᶨ��ջ��˳��洢�ṹ������ֻ���������ʵ�֡�
2������ջ�ĺ���ȳ�ԭ��
3��ͨ�������Ӧ��ʵ������һ����Ϥ������ջ��ʵ�������е����á�

ʵ������
1����ջ����˳��洢�ṹ���ö�̬���飩�����дջ�ĸ��ֻ���������ʵ�ֺ������������ͷ�ļ�stack.h�С�ͬʱ����һ����֤����ʵ�ֵ��������ļ�stack.cpp�����벢���Գ���ֱ����ȷ���С�
��ʾ��
�� ջ�Ķ�̬����˳��洢�ṹ�ɶ������£�
����int IsReverse(char  struct  Stack {
����    ElemType  *stack ;		// ��ջԪ��
����    int  top;         		   // ջ��ָʾ��
����    int MaxSize;            // ջ����󳤶�
����  };
�� ջ�Ļ��������ɰ�����
�� void InitStack (Stack &S);    //����һ����ջ S
�� int EmptyStack (Stack S);   //��ջSΪ��ջ����1�����򷵻�0
�� void Push(Stack &S, ElemType item);   //Ԫ�� item��ջ
�� ElemType Pop(Stack &S);    //ջS��ջ��Ԫ�س�ջ������
�� ElemType Peek(Stack S);   //ȡջS�ĵ�ǰջ��Ԫ�ز�����
�� void ClearStack (Stack &S);   //���ջs��ʹ��Ϊ��ջ

2��Ӧ�ã�дһ�������жϸ������ַ����Ƿ����ĶԳơ����ַ�����abcba������abccba����Ϊ���ĶԳƣ��ַ�����abcdba�������ĶԳơ�Ҫ������test7.h����ʵ�ֵ��й�ջ�Ļ�������������ʵ�֡���Ѹú�����ӵ��ļ�test7.cpp�е�������ǰ�������������������Ӧ�����в��ԡ�����ԭ�����£�
*s)   //�ж��ַ���S�Ƿ����ĶԳƣ��Ƿ���1�����򷵻�0
3����дʵ�鱨�棬ʵ�鱨���ļ�ȡ��Ϊreport7.doc��
4���ϴ�ʵ�鱨���ļ�report7.doc ��Դ�����ļ�test7.cpp��test7.h��Ftp�������ϣ� ftp://10.61.14.240:5000 ���Լ����ļ����¡�

��. �����Ĺ���˵�����㷨˼·
  ������ÿ�������Ĺ���˵������һЩ��Ҫ�������㷨ʵ��˼·��
����int IsReverse(char  struct  Stack {
����    ElemType  *stack ;		// ��ջԪ��
����    int  top;         		   // ջ��ָʾ��
����    int MaxSize;            // ջ����󳤶�
����  };
�� ջ�Ļ��������ɰ�����
�� void InitStack (Stack &S);    //����һ����ջ S
�� int EmptyStack (Stack S);   //��ջSΪ��ջ����1�����򷵻�0
�� void Push(Stack &S, ElemType item);   //Ԫ�� item��ջ
�� ElemType Pop(Stack &S);    //ջS��ջ��Ԫ�س�ջ������
�� ElemType Peek(Stack S);   //ȡջS�ĵ�ǰջ��Ԫ�ز�����
�� void ClearStack (Stack &S);   //���ջs��ʹ��Ϊ��ջ

��. ʵ���������
�������������н����ͼ����������ȣ�


����¼----Դ����
test7.cpp:*/
#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int ElemType;
struct  Stack
{
    ElemType  *stack ;  // ��ջԪ��
    int  top;              // ջ��ָʾ��
    int MaxSize;            // ջ����󳤶�
};

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

int main()
{
 Stack s;
 InitStack (s);
 char a[80];
 int i,n;
 cout<<"�����ַ�����n:";
 cin>>n;
 cout<<"����n���ַ���";
    for(i=0;i<n;i++)
 cin>>a[i];
 a[i]='\0';
 i=0;
 while(a[i]!='\0'){
       Push(s,a[i]);
       i++;
  }
 EmptyStack (s);
    //if(IsReverse(a,s))
  //cout<<"�ַ���S���ĶԳ�"<<endl;
 //else
  cout<<"�ַ���S�����ĶԳ�"<<endl;
 ClearStack (s);
}
int IsReverse(char *s,Stack a)
{
 int i;
    i=0;
 while(s[i]!='\0')
 {
 if(Pop(a)!=s[i])
  return 0;
 else
  i++;
 }
 return 1;
}
