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
const int N = 500500,Mo = 1e9 + 7;
int n;
int a[N];
ll ans;
struct node{
    int l,r;
    //a[i] = max(a[mx[i].l ~ mx[i].r])
}mx[N],mn[N];
int f[N],g[N],q[N];
void init()
{
    scanf("%d", &n);
    fo(i,1,n) scanf("%d", &a[i]);
    mx[1].l = mn[1].l = 1;
    mx[n].r = mn[n].r = n;
    fd(i,n - 1,1)
    {
        for (mx[i].r = i;a[i] > a[mx[i].r + 1] && mx[i].r + 1 <= n;mx[i].r = mx[mx[i].r + 1].r);
        for (mn[i].r = i;a[i] < a[mn[i].r + 1] && mn[i].r + 1 <= n;mn[i].r = mn[mn[i].r + 1].r);
    }
    fo(i,2,n)
    {
        for (mx[i].l = i;a[i] > a[mx[i].l - 1] && mx[i].l - 1 >= 1;mx[i].l = mx[mx[i].l - 1].l);
        for (mn[i].l = i;a[i] < a[mn[i].l - 1] && mn[i].l - 1 >= 1;mn[i].l = mn[mn[i].l - 1].l);
    }
    int j = 1;
    fo(i,1,n)
    {
        while (i > mn[j].r) j = mn[j].r + 1;
        f[i] = a[j];
    }
    j = 1;
    fo(i,1,n)
    {
        while (i > mx[j].r) j = mx[j].r + 1;
        g[i] = a[j];
    }
    fd(i,n,1) q[i] = (q[i + 1] + 1ll * g[i] * f[i] % Mo) % Mo;
}
int main()
{
//  freopen("seq.in","r",stdin);
//  freopen("seq.out","w",stdout);
    freopen("D:/LiuYuanHao/b.in","r",stdin);
    init();
    fo(i,1,n)
    {
        ans = (ans + q[i]) % Mo;
        int j = i + 1;
        fo(k,i + 1,mx[i].r) 
        {
            while (k > mx[j].r) j = mx[j].r + 1;
            g[k] = a[j];
        }
        fo(k,i + 1,mn[i].r) 
        {
            while (i > mn[j].r) j = mn[j].r + 1;
            f[i] = a[j];
        }
        fd(l,max(mn[l].r,mx[l].r),i + 1) q[l] = (q[l + 1] + 1ll * g[l] * f[l] % Mo) % Mo;
    }
    printf("%lld", ans);
}





