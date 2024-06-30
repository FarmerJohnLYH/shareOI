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
const int N = 110;
int a[N][N];
int mxx[N],mxy[N];
int bz[N][N],gt[N][N];
bool okx[N],oky[N];
int n,m;
int main()
{
    freopen("D:/LiuYuanHao/","r",stdin);
    scanf("%d%d", &n, &m);
    fo(i,1,n) fo(j,1,m)
    {
        scanf("%d", &a[i][j]);
        mxx[i] = max(a[i][j],mxx[i]);
        mxy[j] = max(a[i][j],mxy[j]);
    }
    fo(i,1,n) fo(j,1,m)
        bz[i][j] = 1int * (a[i][j] == mxx[i]) + 1int *(a[i][j] == mxy[j]);
    fo(i,1,n) fo(j,1,m)
    {
        if (bz[i][j] == 2)
        {
            gt[i][j] = 1;
            okx[i] = 1,oky[j] = 1;
            fo(l,1,n) -- bz[l][j];
            fo(l,1,m) -- bz[i][l];
        }
    }
    fo(i,1,n)
    if (!okx[i])
    {
        fo(j,1,m) 
        if (bz[i][j] > 0)
        {
            gt[i][j] = 1;
            okx[i] = 1;
            break;
        }
    }
    fo(j,1,m)
    if (!oky[j])
    {
        fo(i,1,n) 
        if (bz[i][j] > 0)
        {
            gt[i][j] = 1;
            oky[j] = 1;
            break;
        }
    }
    ll ans = 0;
    fo(i,1,n) fo(j,1,m)
    if (!gt[i][j]) ans = ans + (a[i][j] - 1);
    printf("%lld", ans);
}











