#include<iostream>
#include<cstring>
using namespace std;
bool isPalindrome(const char *);

int main()
{
    cout<<"Enter a string: ";
    char s[80];
    while(cin.getline(s,80))
    {
    if(isPalindrome(s))
      cout<<s<<" is a palindrome"<<endl;
    else
      cout<<s<<" is not a palindrome"<<endl;

    }
    return 0;
  // while()
}
bool isPalindrome(const char * const s)
{
    int low=0;
    int high=strlen(s)-1;
    while(low<high)
    {
        if(s[low]!=s[high])
        return false;
        low++;
        high--;
    }
    return true;
}
