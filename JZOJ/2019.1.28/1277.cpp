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
const int N = 10100;
int n,l,h,r;
int s[N],a[N],b[N];
bool bz[N][N];
struct node{
    int a,b;
}p[N];
bool cmp(node a,node b)
{
    return ((a.a < b.a) || ((a.a == b.a) && (a.b < b.b)));
}
int main()
{
    freopen("D:/LiuYuanHao/a.in","r",stdin);
    scanf("%d%d%d%d", &n, &l, &h, &r);
    fo(i,1,n)
    {
        scanf("%d%d", &a[i], &b[i]);
        if (a[i] > b[i]) swap(a[i],b[i]);
        p[i].a = a[i],p[i].b = b[i];
        //-- s[a[i] + 1],++ s[b[i]];
    }
    sort(p + 1,p + 1 + n,cmp);
    fo(i,1,n) if (p[i].a != p[i - 1].a || p[i].b != p[i - 1].b) -- s[p[i].a + 1],++ s[p[i].b];
    fo(i,1,n) 
    {
        s[i] = s[i - 1] + s[i];
        printf("%d\n", s[i] + h);
    }
}





