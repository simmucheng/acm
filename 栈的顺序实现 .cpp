/*实验目的和要求
1、掌握栈的存储结构及其基本操作。学会定义栈的顺序存储结构及其各种基本操作的实现。
2、掌握栈的后进先出原则。
3、通过具体的应用实例，进一步熟悉和掌握栈在实际问题中的运用。

实验内容
1、设栈采用顺序存储结构（用动态数组），请编写栈的各种基本操作的实现函数，并存放在头文件stack.h中。同时建立一个验证操作实现的主函数文件stack.cpp，编译并调试程序，直到正确运行。
提示：
⑴ 栈的动态数组顺序存储结构可定义如下：
　　int IsReverse(char  struct  Stack {
　　    ElemType  *stack ;		// 存栈元素
　　    int  top;         		   // 栈顶指示器
　　    int MaxSize;            // 栈的最大长度
　　  };
⑵ 栈的基本操作可包括：
① void InitStack (Stack &S);    //构造一个空栈 S
② int EmptyStack (Stack S);   //若栈S为空栈返回1，否则返回0
③ void Push(Stack &S, ElemType item);   //元素 item进栈
④ ElemType Pop(Stack &S);    //栈S的栈顶元素出栈并返回
⑤ ElemType Peek(Stack S);   //取栈S的当前栈顶元素并返回
⑥ void ClearStack (Stack &S);   //清除栈s，使成为空栈

2、应用：写一函数，判断给定的字符串是否中心对称。如字符串“abcba”、“abccba”均为中心对称，字符串“abcdba”不中心对称。要求利用test7.h中已实现的有关栈的基本操作函数来实现。请把该函数添加到文件test7.cpp中的主函数前，并在主函数中添加相应语句进行测试。函数原型如下：
*s)   //判断字符串S是否中心对称，是返回1，否则返回0
3、填写实验报告，实验报告文件取名为report7.doc。
4、上传实验报告文件report7.doc 、源程序文件test7.cpp及test7.h到Ftp服务器上（ ftp://10.61.14.240:5000 ）自己的文件夹下。

三. 函数的功能说明及算法思路
  （包括每个函数的功能说明，及一些重要函数的算法实现思路）
　　int IsReverse(char  struct  Stack {
　　    ElemType  *stack ;		// 存栈元素
　　    int  top;         		   // 栈顶指示器
　　    int MaxSize;            // 栈的最大长度
　　  };
⑵ 栈的基本操作可包括：
① void InitStack (Stack &S);    //构造一个空栈 S
② int EmptyStack (Stack S);   //若栈S为空栈返回1，否则返回0
③ void Push(Stack &S, ElemType item);   //元素 item进栈
④ ElemType Pop(Stack &S);    //栈S的栈顶元素出栈并返回
⑤ ElemType Peek(Stack S);   //取栈S的当前栈顶元素并返回
⑥ void ClearStack (Stack &S);   //清除栈s，使成为空栈

四. 实验结果与分析
　　（包括运行结果截图、结果分析等）


【附录----源程序】
test7.cpp:*/
#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int ElemType;
struct  Stack
{
    ElemType  *stack ;  // 存栈元素
    int  top;              // 栈顶指示器
    int MaxSize;            // 栈的最大长度
};

void InitStack (Stack &S)    //构造一个空栈 S
{
  S.MaxSize=10;
  S.stack=new ElemType[S.MaxSize];
  if(!S.stack){
    cout<<"fail"<<endl;
    exit(1);
  }
  S.top=-1;
}
int EmptyStack (Stack S)   //若栈S为空栈返回1，否则返回0
{
  return S.top==-1;
}
void Push(Stack &S, ElemType item)   //元素 item进栈
{
  if(S.top==S.MaxSize-1){
    int k=sizeof(ElemType);
    S.stack=(ElemType*)realloc(S.stack,2*S.MaxSize*k);
    S.MaxSize=2*S.MaxSize;
  }
  S.top++;
  S.stack[S.top]=item;
}
ElemType Pop(Stack &S)    //栈S的栈顶元素出栈并返回
{
  if(S.top==-1){
    cerr<<"Stack is empty!"<<endl;
    exit(1);
  }
  S.top--;
  return S.stack[S.top+1];
}
ElemType Peek(Stack S)   //取栈S的当前栈顶元素并返回
{
  if(S.top==-1){
    cerr<<"Stack is empty!"<<endl;
    exit(1);
  }
  return S.stack[S.top];
}
void ClearStack (Stack &S)   //清除栈s，使成为空栈
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
 cout<<"输入字符个数n:";
 cin>>n;
 cout<<"输入n个字符：";
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
  //cout<<"字符串S中心对称"<<endl;
 //else
  cout<<"字符串S不中心对称"<<endl;
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
