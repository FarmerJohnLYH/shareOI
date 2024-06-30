#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define abs(x) (((x)>=0)?(x):(-(x)))
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define fo(i,x,y) for (int i = (x);i <= (y);++ i)
#define fd(i,x,y) for (int i = (x);i >= (y);-- i)
using namespace std;
typedef double db;
typedef long long ll;
const int N = 20002000;
int n;
int a,b,c,d,p,k;
int w[30][N],tw[30],t[N],ans; 
int jd(int x)
{
    if (x == 0) return 1; else return x;
}
int main()
{
    freopen("D:/LiuYuanHao/","r",stdin);
    tw[0] = 1;fo(i,1,23) tw[i] = tw[i - 1] << 1;
    scanf("%d%d%d", &n, &k, &p);
    scanf("%d%d%d%d", &a, &b, &c, &d);
    w[0][1] = a;
    fo(i,2,n) w[0][i] = (w[0][i - 1] * b + c) % d;
    fo(l,1,22) fo(i,1,n)
        w[l][i] = (ll)(jd(w[l - 1][i]) * jd(w[l - 1][i + tw[l - 1]])) % p;
    fo(i,1,n)
    {
        int tmp = k,m = 0,rt = 1,j = i;
        while (tmp && j <= n)
        {
            if (tmp & tw[m ++]) rt = (rt * w[m][j]),tmp -= tw[m - 1],j += tw[m - 1];
        }
        t[i] = rt;
        ans = ans ^ t[i];
    }
}





