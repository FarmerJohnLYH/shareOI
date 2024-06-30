#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define fo(i,x,y) for (register int asDfg = (y),i = (x);i <= asDfg;++ i)
#define fd(i,x,y) for (register int asDfg = (y),i = (x);i >= asDfg;-- i)
using namespace std;
int abs(int x){return ((((x)>=0)?(x):(-(x))));}
int max(int x,int y){return (((x)>(y))?(x):(y));}
int min(int x,int y){return (((x)<(y))?(x):(y));}
typedef double db;
typedef long long ll;
const int N = 100100,M = 200200;
int n,m;
struct edge{
    int x,y;
    int val;
}e[M];
int f[N];
bool cmp(edge x,edge y)
{
    return x.val < y.val;
}
int main()
{
    freopen("D:/LiuYuanHao/","r",stdin);
    scanf("%d", &T);
    while (T --)
    {
        scanf("%d%d", &n, &m);
        fo(i,1,m) scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].val);
        sort(e + 1,e + 1 + m,cmp);
        fo(i,1,n) f[i] = i;
        int ans = 0,mn = oo;
        fo(i,1,m)
            if (gf(e[i].x) != gf(e[i].y))
            {
                fa[gf(e[i].x)] = gf(e[i].y);
                ans = ans + e[i].val;
            }
        build();
        mn = ans;
        printf("%d\nYes\n", mn);
    }
}






