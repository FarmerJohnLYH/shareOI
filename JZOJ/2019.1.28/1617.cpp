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
const int NM = 1024,int N = 11;
ll f[2][N * N][NM],cnt[NM],a[NM];
int n,m;
bool check(int x, int y){return !(x & y << 1 || x & y || x & y >> 1);}
int main()
{
    scanf("%d%d", &n, &m);
    tot = 0;
    f1[0][0] = 1;
    int all = (1 << n) - 1;
    fo(i,0,all)
    {
        fo(j,0,8) 
            if (i & (1 << j)) ++ cnt[i]; 
        if (!(i & (i << 1)) && !(i & (i >> 1))) a[++ tot] = i;
    }
    int o = 0;
    f[o][0] = 1;
    fo(i,1,n)
    {
        o = 1 ^ o;
        memset(f[o],0,sizeof f[o]);
        fo(j,1,tot) fo(k,1,tot) fo(l,cnt[a[j]],(i - 1) * n)
            if (check(a[j],a[k])) 
                f[o][l + cnt][a[k]][a[k]] += f[1 ^ o][l][a[j]];
    }
    o ^= 1;
    fo(i,1,tot) ans += f[o][m][a[i]];
    printf("%d", ans);
}