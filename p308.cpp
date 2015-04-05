#include<iostream>
#include<cmath>
using namespace std;
class MyPoint
{
      double x,y;
    public:
      double getX()
      {
          return x;
      }
       double getY()
      {
          return y;
      }
        MyPoint()
        {
           x=0,y=0;
        }
        MyPoint(double x,double y)
        {
          this->x=x;
          this->y=y;
        }

        double distance(MyPoint &MyPoint1)
        {
            double a;
            a=sqrt((x-MyPoint1.x)*(x-MyPoint1.x)+(y-MyPoint1.y)*(y-MyPoint1.y));
            return a;
        }

};
int main()
{
    MyPoint q1(1,3),q2(2,3);
    int m,n;
    while(cin>>m>>n)
    {
       cout<<q1.getX()<<' '<<q1.getY()<<endl;
       cout<<q2.getX()<<' '<<q2.getY()<<endl;
       cout<<q1.distance(q2);
    }
    return 0;
}
