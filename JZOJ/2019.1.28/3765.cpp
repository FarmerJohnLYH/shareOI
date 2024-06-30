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
const int N = 1001000,M = 100100,ti = 10,mx = 362881,T = 37;
int n,m;
struct node{
    int x,y;
}e[N];
int v[N][T * 4];
double ans[N];
void random()
{
    fo(i,1,m) v[i][1] = rand() % mx + 1,v[i][0] = 1; 
}
void comb(int *x,int *y,int *c)
{
    int tot = 0;
    fo(i,1,x[0]) c[++ c[0]] = x[i]; fo(i,1,y[0]) c[++ c[0]] = y[i];
    sort(c + 1,c + 1 + c[0]);
    fo(i,1,c[0] - 1) if (c[i] == c[i + 1]) c[i + 1] = oo,++ tot; 
    sort(c + 1,c + 1 + c[0]);
    c[0] -= tot;
}
int main()
{
    freopen("D:/LiuYuanHao/a.in","r",stdin);
    scanf("%d%d", &n, &m);
    fo(i,m + 1,n) scanf("%d%d", &e[i].x, &e[i].y);
    srand(20030417);
    fo(l,1,ti)
    {
        random();
        fo(i,m + 1,n)
        {
            comb(v[e[i].x],v[e[i].y],v[i]);
            if (v[i][0] < T) ans[i] += v[i][0]; else ans[i] += (double)(mx * T / v[i][T]);
        }
    }
    fo(i,m + 1,n) printf("%d\n", ans[i]/ti);
}


