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
const int N = 22,M = 440,NM = 1048576,Mo = 1e9 + 7;
int n,m,k,l;
int uv[N],tw[N];
int f[N][NM + 2],d[N][NM + 2];
int get(int m)
{
    int t = 0;
    while (m) ++ t,m -= lowbit(m);
    return t;
}
int main()
{
//  freopen("count.in","r",stdin);
//  freopen("count.out","w",stdout);
    freopen("D:/LiuYuanHao/a1.in","r",stdin);
    tw[0] = 1;fo(i,1,21) tw[i] = tw[i - 1] << 1;
    scanf("%d%d%d", &n, &m, &k);
    fo(i,1,m)
    {
        int x,y;
        scanf("%d%d", &x, &y);
        uv[x] |= tw[y - 1];
    }
    ll ans = 0;
    f[0][0] = 1,d[0][1] = 0,d[0][0] = 1;
    fo(p,0,k)
    {
        fo(s,0,tw[n] - 1)
        {
            fo(l,1,n)
            if (!(uv[l] & s) && !(tw[l - 1] & s))
                (f[p][s | tw[l - 1]] += f[p][s]) %= Mo;
            fo(l,1,n)
            if (!(tw[l - 1] & s) && (uv[l] & s))
            {
                int tmp = get((uv[l] & s));
                if (p + tmp > k) continue;
                (f[p + tmp][s | tw[l - 1]] += f[p][s]) %= Mo;
            }
        }
        ans = (ans + f[p][tw[n] - 1]) % Mo;
    }
    printf("%lld", ans);
}






