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
const int N = 1001000;
int n,m;
int a[N],son[N][2],fa[N];
int SumL[N],SumR[N],tot,stack[N],tmp,d[N],Mx;
int las[N],to[N<<1],id[N<<1],nex[N<<1];
int le[N],ri[N],f[N],lca[N];
void link(int x,int y,int z)
{
    to[++ tot] = y,nex[tot] = las[x],id[tot] = z;las[x] = tot;
}
void Get(int x)
{
    int j = 0;
    for (d[j = 0] = x;f[d[j]];d[j] = f[d[j-1]]) ++ j;
    for (int i = 0,tmp = d[j];i < j;f[d[i ++]] = tmp);
}
int main()
{
    freopen("trip.in","r",stdin); freopen("trip.out","w",stdout);
    n = read(),m = read();
    a[0] = -oo;
    fo(i,1,n)
    {
        a[i] = read();
        if (a[i] > a[Mx]) Mx = i;
    }
    tot = 0;
    fo(i,1,n) 
    {
        for (;tot>0 && a[stack[tot]]<a[i];son[i][0]=stack[tot--]);
        fa[son[i][0]]=i;
        stack[++tot]=i;
    }
    tot = 0;
    fo(i,0,m - 1)
    {
        le[i] = read(),ri[i] = read();
        link(le[i],ri[i],i),link(ri[i],le[i],i);
    }
    for (stack[tot = 1] = Mx;tot > 0;)
    {
        int x = stack[tot],y;
        if (son[x][0] > 0)
        {
            y = son[x][0],SumL[y] = SumL[x] + 1,SumR[y] = SumR[x],son[x][0] = 0;
        }
        else 
        if (son[x][1] > 0)
        {
            y = son[x][1],SumL[y] = SumL[x],SumR[y] = SumR[x] + 1,son[x][1] = 0;
        }
        else
        {
            -- tot;
            for (int i = las[x];i;i = nex[i])
                Get(to[i]),lca[id[i]]=tmp;
            f[x] = fa[x];
            continue;
        }
        stack[++ tot] = y;
    }
    fo(i,0,m - 1)
    {
        write(SumL[le[i]] + SumR[ri[i]] - SumL[lca[i]] - SumR[lca[i]] + 1);
    }
}