#include<iostream>
using namespace std;

class Circle
{
    public:
    double radius;
    Circle()
    {
        radius=1;
    }
    Circle(double newradius)
    {
        radius=newradius;
    }
    double getArea()
    {
        return radius*2;
    }
};

int main()
{
    Circle c1;
    Circle c2(6);
    cout<<c1.getArea()<<endl;
    cout<<c2.getArea()<<endl;
    return 0;
}
