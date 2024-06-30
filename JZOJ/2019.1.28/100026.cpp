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
const int N = 100100,K = 10000010000,t = 35;
int n,k;
int f[N][t + 11],s[N][t + 11],m[N][t + 11];
int main()
{
    freopen("D:/LiuYuanHao/b.in","r",stdin);
    scanf("%d%d", &n, &k);
    fo(i,1,n) scanf("%d", &f[i][0]);
    fo(i,1,n) scanf("%d", &s[i][0]),m[i][0] = s[i][0];
    fo(l,1,t) fo(i,1,n) 
        f[i][l] = f[f[i][l - 1]][l - 1],
        s[i][l] = s[i][l - 1] + s[f[i][l - 1]][l - 1],
        m[i][l] = min(m[i][l - 1],m[f[i][l - 1]][l - 1]);
    fo(i,1,n)
    {
        int tmp = k,S = i,M = i;
        fd(l,t,0) 
            if (tmp >= (1 << l)) tmp -= (1 << l),S = s[S][l],M = m[M][l];
        printf("%d%d", S, M);
    }


}





