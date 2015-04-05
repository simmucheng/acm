#include<iostream>
using namespace std;
class CPoint
{
    friend CPoint Inflate(CPoint &pt,int nOffset);
    public :
    CPoint(int x=0,int y=0)
    {
        xPos=x;
        yPos=y;
    }
    void Print()const
    {
        cout<<"Point("<<xPos<<","<<yPos<<")"<<endl;
    }
    private:
    int xPos,yPos;
};
CPoint Inflate(CPoint &pt,int nOffset)
{
    pt.xPos+=nOffset;
    pt.yPos+=nOffset;
    return pt;
}
int main()
{
    CPoint a(12,12);
    Inflate(a,20);
    a.Print();
    return 0;
}
