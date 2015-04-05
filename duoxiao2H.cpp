#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
typedef long long LL;
 
const LL MOD = 1000000007;
 
struct Matrix
{
        LL a[4][4];
        LL * operator[](int d)
        {
                return a[d];
        }
        void init()
        {
                memset(a, 0, sizeof(a));
        }
        void print()
        {
                for(int i=0;i<4;++i)
                {
                        for(int j=0;j<4;++j)
                                cout << a[i][j] << " ";
                        cout << endl;
                }
        }
};
 
Matrix operator * (Matrix &a, Matrix &b)
{
        Matrix c;
        c.init();
        for(int i=0;i<4;++i)
        {
                for(int j=0;j<4;++j)
                {
                        for(int k=0;k<4;++k)
                                c[i][j] += a[i][k] * b[k][j];
                        c[i][j] %= MOD;
                }
        }
        return c;
}
 
Matrix operator ^ (Matrix a, int n)
{
        Matrix ans;
        ans.init();
        for(int i=0;i<4;++i)ans[i][i] = 1;
        while(n)
        {
                if(n & 1)ans = ans * a;
                a = a * a;
                n >>= 1;
        }
        return ans;
}
 
Matrix a;
 
int main()
{
        LL b[4], c[4];
        while (scanf("%lld%lld%lld%lld",&b[0],&b[1],&b[2],&b[3])!=EOF)
        {
                a.init();
                a[0][0] = 3; a[0][1] = 1;
                a[1][0] = 1; a[1][2] = 1;
                a[2][0] = -3;a[2][3] = 1;
                LL d, x;
                scanf("%lld%lld",&d,&x);
                Matrix t = a ^ (d-1);
                //t.print();
                LL ans = 0;
                memset(c, 0, sizeof(c));
                for(int i=0;i<4;++i)
                {
                        for(int j=0;j<4;++j)
                                c[j] += b[i] * t[i][j];
                }
                LL p = 1;
                for(int i=3;i>=0;--i)
                {
                        c[i] %= MOD;
                        ans += c[i] * p;
                        p = p * x % MOD;
                }
                ans %= MOD; while(ans < 0) ans += MOD;
                printf("%lld\n",ans);
        }
        return 0;
}