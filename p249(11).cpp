#include<iostream>
using namespace std;
int countLetters(const char * const s)
{
    int e;
    for(e=0;;e++)
    {
        if(s[e]=='\0')
        break;
    }
    return e;
}
int main()
{
    char w[]="C++ and java in 2008";
    cout<<countLetters(w)<<endl;
    return 0;
}
