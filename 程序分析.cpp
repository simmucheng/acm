#include<iostream>
#include<cstdio>
using namespace std;
void dj
{
    if(codenum>=10&&codenum<=15)cout<<'A'<<endl;
}
//char s[1000][1000];
int main()
{
    int mark=0;
    int hnum=0;//����
    int tonum=0;
    int markex=0;
    int vomark=0;
    int vo=0;
    int totnum=0;
    int codenum=0;
    int ex;//ע��
    char w[1000];
    cin>>w;
    cout<<"The results of analysing program file "<<w<<';'<<endl;
    while(1)
    {
        cin>>s;
        totnum++;
        if((s>='a'&&s<='z')||(s>='A'&&s<='Z')||(s>='0'&&s<='9'))codenum++;
        if(s=='0')mark=1;
        if(mark==1&&s==';')break;
        if(s=='\n'){hnum++;vomark++;}//����
        else vomark=0;
        if(vomark==2)vo++;//���е�����
        if(s=='v'||s=='i')bo=1;
        if(s=='/')markex=1;
        if(vomark==2)
        if(markex==1&&s=='/'){ex++;markex=0;}//ע�͵ĸ���
        else markex=0;
        if(bo==1&&(s=='o'||s=='n'))bo=2;
        if(bo==2&&s=='{')
        {
            re++;
        }
        else if(bo==2&&s=='}')
        {
            la++;
            tonum++;
            bo=0;
        }//�����ĸ���
    }
    cout<<"Lines of code:   "<<codenum<<endl;
    cout<<"Lines of comments:    "<<hnum<<endl;
    cout<<"Blank lines:     "<<vo<<endl;
    cout<<"Code  Comments  Space"<<endl;
    cout<<"====   =======  ====="<<endl;
    cout<<code*100/totnum<<'%'<<"     "<<ex*100/totnum<<'%'<<"    "<<vo*100/totnum<<endl;
    cout<<"The program includes "<<tonum<<" functions."<<endl;
    printf("The average length of a section of code is %.1f lines\n",codenum*1.0/hnum);

    //cout<<""<<
    return 0;
}
