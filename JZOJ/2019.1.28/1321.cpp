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
const int N = 40;
int e[N][N];
int n,m;
int h[N];
int ans;
struct node{
    int x,y;
}a[N];
void dfs(int x,int y)
{
    if (y >= ans) return;
    if (x > n)
    {
        fo(l,1,n) 
            if ((h[l] & 1) == 0) return;
        ans = y;
        return;
    }
    dfs(x + 1,y);
    fo(i,1,e[x][0]) ++ h[e[x][i]];
    ++ h[x];
    dfs(x + 1,y + 1);
    fo(i,1,e[x][0]) -- h[e[x][i]];
    -- h[x];
}
bool cmpa(node x,node y)
{
    return (x.y < y.y) || ((x.y == y.y) && (x.x < y.x));
}
int main()
{
    freopen("D:/LiuYuanHao/a.in","r",stdin);
    scanf("%d%d", &n, &m);
    ans = oo;
    fo(i,1,m)
    {
        int x,y; 
        scanf("%d%d", &x, &y); 
        e[x][++ e[x][0]] = y,
        e[y][++ e[y][0]] = x;
    }
    //fo(i,1,n) a[i].x = i,a[i].y = e[i][0];
    //sort(a + 1,a + 1 + n,cmpa);
    //fo(i,1,n) h[i] = a[i].x;'
    dfs(1,0);
    printf("%d", ans);
}





