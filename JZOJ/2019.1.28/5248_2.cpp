#include <vector>
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
#define fo(i,x,y) for (register int i = (x);i <= (y);++ i)
#define fd(i,x,y) for (register int i = (x);i >= (y);-- i)
using namespace std;
typedef double db;
typedef long long ll;
const int N = 100100;
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;
    int n=q*w;return n;
}
int buf[30];
void write(int x)
{
    if (x<0) putchar('-'),x=-x;
    buf[0]=0;
    while (x) buf[++buf[0]]=x%10,x/=10;
    if (!buf[0]) buf[0]=1,buf[1]=0;
    while (buf[0]) putchar('0'+buf[buf[0]--]);
}
int n,m,q;
ll fa[N][22],val[N][22],dp[N];
vector<int> e[N],tms[N],to[N];
void dfs(int x,int f)
{
    fa[x][0] = f,val[x][0] = dp[f];
    fo(i,1,18)
    {
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
        val[x][i] = min(val[x][i - 1],val[fa[x][i - 1]][i - 1]);
    }
    dp[x] = (x == 1)?0:(oo * oo);
    int siz = to[x].size();
    fo(i,0,size - 1)
    {
        ll tmp = (oo * oo), y = x, k = to[x][i], p = 0;
        fo(q,0,18)
        {
            if (k & (1 << q))
            {
                tmp = min(tmp,val[y][p]);
                y = fa[y][p];
            } 
            ++ p;
        }
        dp[x] = min(dp[x],tmp + tms[x][i]);
    }
    siz = e[x].size();
    fo(i,0,siz - 1)
        if (e[x][i] != f) dfs(e[x][i],x);
}
int main()
{
    n = read(),m = read();
    fo(i,1,n - 1)
    {
        u = read(),v = read();
        e[u].push_back(v),e[v].push_back(u);
    }
    fo(i,1,m)
    {
        u = read(),v = read(),w = read();
        to[u].push_back(v),tms[u].push_back(w);
    }
    dfs(1,1);
    q = read();
    fo(i,1,q)
        u = read(),write(dp[u]);
}