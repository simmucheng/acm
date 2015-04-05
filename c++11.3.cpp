#include<iostream>
#include<cmath>
class MyPoint
{
    double x,y;
    public:
    MyPoint(double x=0,double y=0)
    {
        this->x=x;
        this->y=y;
    }
    void setx(double x)
    {
        this->x=x;
    }
    double getx()
    {
        return x;
    }
    double gety()
    {
        return y;
    }
    virtual double getdistance(MyPoint &e)
    {
        return sqrt((x-e.x)*(x-e.x)+(y-e.y)*(y-e.y));
    }
};
class DPoint: public MyPoint
{
    double z;
    public:
    DPoint()
    {
        z=5;
    }
    DPoint(double x,double y,double z):MyPoint(x,y)
    {
        this->z=z;
    }
    double getz()
    {
        return z;
    }
     double distance(DPoint &e)
     {
         double x1=(this->getx()-e.getx())*(this->getx()-e.getx());
         double y1=(this->gety()-e.gety())*(this->gety()-e.gety());
         return pow(x1+y1+(z-e.z)*(z-e.z),1/3.0);
     }
};
using namespace std;
int main()
{
    //double n,m;
    //MyPoint a(3,4);
    //MyPoint b(2,3);
    DPoint c;
    DPoint d(0,0,0);
    c.setx(5);
    cout<<c.getx()<<endl;
   // cout<<d.gety()<<endl;
    //cout<<a.getdistance(b)<<endl;
    //cout<<c.getz()<<endl;
    cout<<c.distance(d)<<endl;
    return 0;
}
