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
    void add(Comp &W)
    {
        x=x+W.x;
        y=y+W.y;
        cout<<x<<'+'<<' '<<y<<endl;
    }
};
int main()
{
    Comp A(1,2);
    Comp B(2,3);
    A.add(B);
    return 0;
}
