
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
    friend bool operator ==(Comp &e,Comp &d)
    {
        return (e.x==d.x&&e.y==d.y);
    }
    friend bool operator !=(Comp &e,Comp &d)
    {
        return (e.x!=d.x||e.y!=d.y);
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
    Comp B(1,2);
    Comp C,D;
    //C=A+B;
    if(A!=B)cout<<"you are a boy"<<endl;
    else cout<<"you are a girl"<<endl;
    return 0;
}
