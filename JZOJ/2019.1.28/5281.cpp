#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (register ll i = (x);i <= (y);++ i)
#define fd(i,x,y) for (register ll i = (x);i >= (y);-- i)
using namespace std;
typedef double db;
typedef long long ll;
ll abs(ll x) {return(((x)>=0)?(x):(-(x)));}
ll max(ll x,ll y) {return(((x)>(y))?(x):(y));}
ll min(ll x,ll y) {return(((x)<(y))?(x):(y));}
ll lowbit(ll x) {return((x)&(-x));}
const ll N = 1001000;
ll n,m,q;
struct node{
    string v;
    ll r,d;
}a[N];

ll hash(ll x,ll y) {return y * (m + 1) + x;}
ll find(ll x,ll y)
{
    if (x > y)
    {
        ll ans = hash(x,0);
        fo(i,1,y) ans = a[ans].d;
        return ans;
    }
    else 
    {
        ll ans = hash(0,y);
        fo(i,1,x) ans=a[ans].r;
        return ans;
    }
}
int main()
{
//    freopen("D:/LiuYuanHao/a.in","r",stdin);
    scanf("%lld%lld%lld", &n, &m, &q);
    fo(i,0,n) fo(j,0,m)
    {
        if (i && j) scanf("%s", &a[hash(j,i)].v);
        a[hash(j,i)].r = hash(j + 1,i);
        a[hash(j,i)].d = hash(j,i + 1);
    }

    while(q--)
    {
        ll x1,y1,x2,y2,l,c;
        scanf("%lld%lld%lld%lld%lld%lld", &y1, &x1, &y2, &x2, &l, &c);
        ll p1 = find(x1 - 1,y1 - 1),p2=find(x2 - 1,y2 - 1);
        ll t1 = p1,t2 = p2;
        fo(i,1,l)
        {
            t1 = a[t1].d,t2 = a[t2].d;
            swap(a[t1].r,a[t2].r);
        }
        fo(i,1,c)
        {
            t1 = a[t1].r,t2 = a[t2].r;
            swap(a[t1].d,a[t2].d);
        }
        t1 = p1,t2 = p2;
        fo(i,1,c)
        {
            t1 = a[t1].r,t2 = a[t2].r;
            swap(a[t1].d,a[t2].d);
        }
        fo(i,1,l)
        {
            t1 = a[t1].d,t2 = a[t2].d;
            swap(a[t1].r,a[t2].r);
        }
    }
    for(ll i = 1,p = a[0].d;i <= n;++ i,p = a[p].d)
    {
        for(ll j = 1,q = a[p].r;j <= m;++ j,q = a[q].r)
            printf("%s ", a[q].v);
        printf("\n");
    }
}