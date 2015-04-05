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
    friend void add(Comp &W,Comp &T)
    {
        T.x=T.x+W.x;
        T.y=T.y+W.y;
        cout<<T.x<<'+'<<' '<<T.y<<endl;
    }
};
int main()
{
    Comp A(1,2);
    Comp B(2,3);
    add(A,B);
    return 0;
}
