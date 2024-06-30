#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (register int asDfg = (y),i = (x);i <= asDfg;++ i)
#define fd(i,x,y) for (register int asDfg = (y),i = (x);i >= asDfg;-- i)
using namespace std;
typedef double db;
typedef long long ll;
int abs(int x) {return(((x)>=0)?(x):(-(x)));}
int max(int x,int y) {return(((x)>(y))?(x):(y));}
int min(int x,int y) {return(((x)<(y))?(x):(y));}
int lowbit(int x) {return((x)&(-x));}
const int N = 100100 * 2;
int p,f,n;
int w[N],c[N];
int las[N],staw[N],stac[N],sum[N];
struct node{
    int v,t;
    bool operator < (const node & temp) const {return abs(v) > abs(temp.v);}
}a[N];
int main()
{
    freopen("D:/LiuYuanHao/","r",stdin);
    p = read(),f = read(),n = p + f;
    fo(i,1,p) w[i] = read(),a[i].v = w[i],a[i].t = 0;
    fo(i,1,f) c[i] = read(),a[i + p].v = c[i],a[i + p].t = 1;
    int tmpw = 0,tmpc = 0;
    fo(i,1,n)
    {
        if (!staw[0]) tmpw = 0;
        if (!stac[0]) tmpc = 0;
        if (a[i].t)
        {
           las[i] = stac[stac[0] --]; 
           tmpc += cost(i,las[i]);
           sum[i] = tmpc;
           staw[++ staw[0]] = i;
        }
        else
        {
           las[i] = staw[staw[0] --]; 
           tmpw += cost(i,las[i]);
           sum[i] = tmpw;
           stac[++ stac[0]] = i;
        }
    }
    memset(f,127,sizeof f);
    f[0] = 0;
    fo(i,1,n)
    {
        if (!a[i].t) f[i] = f[i - 1];
        f[i] = min(f[i],f[las[i] - 1] + sum[i]);
    }
    printf("%d", f[n]);
}











