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
#define fo(i,x,y) for (register int asDfg = (y),i = (x);i <= asDfg;++ i)
#define fd(i,x,y) for (register int asDfg = (y),i = (x);i >= asDfg;-- i)
using namespace std;
typedef double db;
typedef long long ll;
const int N = 550,Mo = 1e4+7;
int n,m,k;
int a[N][N];
int main()
{
    freopen("D:/LiuYuanHao/","r",stdin);
    scanf("%d%d%d", &n, &m, &k);
    fo(i,1,n) fo(j,1,m)
        scanf("%d", &a[i][j]);
    int ans = 0;
    fo(i,1,n-k+1) fo(j,1,m-k+1)
    {
        fo(l,i,i+n-1) fo(k,j,j+m-1)
        fo(L,i,i+n-1) fo(L,j,j+m-1)
            ans = (ans + abs(a[l][k] - a[L][K])) % Mo;
    }
    printf("%d", ans);
}


