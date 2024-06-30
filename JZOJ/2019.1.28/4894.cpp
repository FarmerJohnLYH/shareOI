#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (register int i = (x);i <= (y);++ i)
#define fd(i,x,y) for (register int i = (x);i >= (y);-- i)
using namespace std;
typedef double db;
typedef long long ll;
int abs(int x) {return(((x)>=0)?(x):(-(x)));}
int max(int x,int y) {return(((x)>(y))?(x):(y));}
int min(int x,int y) {return(((x)<(y))?(x):(y));}
int lowbit(int x) {return((x)&(-x));}
const int N = 300300, Mo = 1e9 + 7;
int n;
ll ans;
struct node{
    ll x,y,z;
}a[N];
bool sm(node a,node b)
{
    if (a.y * b.y) return (1ll * a.x * b.y == 1ll * a.y * b.x);
    if (!a.y && !b.y) return 1; else return 0; 
}
bool cmp(node a,node b)
{
         if (a.y == 0 && b.y == 0) return 0;
    else if (!a.y) return 0;
    else if (!b.y) return 1;
    return (1ll * a.x * b.y < 1ll * b.x * a.y);
}
ll cnt(int x) {return (1ll * x * (x - 1) / 2);}
int main()
{
    scanf("%d", &n);
    fo(i,1,n) 
    {
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
        if (a[i].y < 0) a[i].x = - a[i].x,a[i].y = - a[i].y,a[i].z = - a[i].z;
    }
    sort(a + 1,a + 1 + n,cmp);
    ll j = 0,l = 0;
    fo(i,1,n)
    {
        if (i > 1 && sm(a[i],a[i - 1])) ++ j;
        else l += (count(j + 1)) % Mo,j = 0;
        ans = (ans + count(i - j - 1) - l) % Mo;
    }
    printf("%d", ans);
}