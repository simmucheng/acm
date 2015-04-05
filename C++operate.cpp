#include<iostream>
using namespace std;
class PP
{
    public :
    PP(int x=0,int y=0)
    {
        this->x=x;
        this->y=y;
    }
    PP operator+(PP &a)
    {
        PP b;
        //return (x==a.x&&y==a.y);
        b.x=this->x+a.x;
        b.y=this->y+a.y;
        return b;
    }
    void pr()
    {
        cout<<x<<' '<<y<<endl;
    }
    /*int judge(PP &a)
    {
        if(a.)
    }*/
    private :
    int x,y;
};
int main()
{
    PP a(12,12);
    PP b(12,12);
    a=a+b;
    a.pr();
    return 0;
}
