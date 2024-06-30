#include <map>
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
const int N = 100100,NUM = 200200 * 2;/*处理正负*/
int n,m;
struct node{
    int x,y,id;
    int u,d,l,r;
}a[N],o[N];
bool cmpx(node a,node b){return (a.x < b.x) || ((a.x == b.x) && (a.y < b.y))};
bool cmpy(node a,node b){return (a.y < b.y) || ((a.y == b.y) && (a.x < b.x))};
int main()
{
    freopen("D:/LiuYuanHao/","r",stdin);
    scanf("%d%d", &n, &m);
    fo(i,1,n)
        scanf("%d%d", &a[i].x, &a[i].y),a[i].id = i;
    scanf("\n");
    a[++ n].id = n,a[n].x = a[n].y = 0;//
    sort(a + 1,a + 1 + n,cmpx);
    a[0].x = a[0].y = oo;
    fo(i,1,n)
        if (a[i - 1].x == a[i].x)
        {
            a[i].d = a[i - 1].id;
            a[i - 1].u = a[i].id;
        }
    sort(a + 1,a + 1 + n,cmpy);
    fo(i,1,n)
        if (a[i - 1].y == a[i].y)
        {
            a[i].l = a[i - 1].id;
            a[i - 1].r = a[i].id;
        }
    fo(i,1,n) 
        if (a[i].id != n) o[a[i].id] = a[i];
    // -- n;
    int now = n + 1;
    fo(i,1,m)
    {
        char c;
        scanf("%c", &c);
        if (c == 'U') now = o[now].u;
        if (c == 'D') now = o[now].d;
        if (c == 'L') now = o[now].l;
        if (c == 'R') now = o[now].r;
    }
    printf("%d%d", o[now].x, o[now].y);
}





