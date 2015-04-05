#include<iostream>
using namespace std;
class Comp
{
    int x,y;
    public:
    Comp(int x=0,int y=0)
    {
        this->x=x;
        this->y=y;
    }
    friend Comp operator +(Comp &e,Comp &d)
    {
        Comp sum;
        sum.x=d.x+e.x;
        sum.y=d.y+e.y;
        return sum;
    }
    friend Comp operator +(Comp &e,int d)
    {
        Comp sum;
        sum.x=e.x+d;
        sum.y=e.y;
        return sum;
    }
    void cou()
    {
        cout<<x<<' '<<y<<endl;
    }
    /*void add(Comp &W)
    {
        x=x+W.x;
        y=y+W.y;
        cout<<x<<'+'<<' '<<y<<endl;
    }*/
};
int main()
{
    Comp A(1,2);
    Comp B(2,3);
    Comp C,D;
    C=A+B;
    D=A+100;
    C.cou();
    D.cou();
    return 0;
}
