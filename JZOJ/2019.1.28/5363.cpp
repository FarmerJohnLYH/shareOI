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
const int N = 100100;
int las[N],to[N * 2],nex[N * 2],tot;
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;
    int n=q*w;return n;
}
void link(int a,int b)
{
    nex[++ tot] = las[a];
    to[tot] = b;
    las[a] = tot;
}
int n,a[N],stn[N],size[N],num;
ll ans[N];
struct node{
    int nex[26],cnt[22][2],cn[22][2];
}trie[600600];
int b[N][2],hd,tl;
void dfs(int p,int q,int dep,ll &z)
{
    fo(i,0,25)
    {
        int x = trie[p].nex[i],y = trie[q].nex[i];
        if (x)
        {
            fo(j,0,16)
                z += 1ll * trie[x].cnt[j][0] * (trie[q].cnt[j][1] - trie[y].cnt[j][1]) * (1 << j) * dep,
                z += 1ll * trie[x].cnt[j][1] * (trie[q].cnt[j][0] - trie[y].cnt[j][0]) * (1 << j) * dep;
            if (y) dfs(x,y,dep + 1,z);
        }
    }
    fo(j,0,16) 
        z += 1ll * trie[p].cn[j][0] * trie[q].cnt[j][1] * dep * (1 << j),
        z += 1ll * trie[p].cn[j][1] * trie[q].cnt[j][0] * dep * (1 << j);
}
void combine(int p,int q)
{
    fo(i,0,16)
    {
        trie[p].cn[i][0] += trie[q].cn[i][0];
        trie[p].cn[i][1] += trie[q].cn[i][1];
        trie[p].cnt[i][0] = trie[p].cn[i][0];
        trie[p].cnt[i][1] = trie[p].cn[i][1];
    }
    fo(i,0,25)
    {
        int x = trie[p].nex[i],y = trie[q].nex[i];
        if (x && y) combine(x,y);
        else if (y) trie[p].nex[i] = y;
        if (trie[p].nex[i])
        {
            int x = trie[p].nex[i];
            fo(i,0,16)
            {
                trie[p].cnt[i][0] += trie[x].cnt[i][0];
                trie[p].cnt[i][1] += trie[x].cnt[i][1];
            }
        }
    }
}
void merge(int x,int y,ll &z)
{
    dfs(stn[x],stn[y],0,z);
    combine(stn[x],stn[y]);
    size[x] += size[y];
}
int main()
{
    freopen("D:/LiuYuanHao/a.in","r",stdin);
    scanf("%d", &n);
    fo(i,1,n) scanf("%d", &a[i]);
    fo(i,1,n)
    {
        char ch = getchar();
        while (ch < 'a' || ch > 'z') ch = getchar();
        int x = stn[i] = ++ num;
        while (ch >= 'a' && ch <= 'z')
        {
            fo(tmp,0,16) ++ trie[x].cnt[tmp][a[i] >> tmp & 1];
            int y = ch - 'a';
            ++ size[i];
            x = trie[x].nex[y] = ++ num;
            ch = getchar();
        }
        fo(tmp,0,16) ++ trie[x].cnt[tmp][a[i] >> tmp & 1],++ trie[x].cn[tmp][a[i] >> tmp & 1];
    }
    fo(i,1,n - 1)
    {
        int x = read(),y = read();
        link(x,y),link(y,x);
    }
    hd = tl = 0;
    b[++ tl][0] = 1;
    while (hd ++ < tl)
    {
        int v = b[hd][0],fa = b[hd][1];
        for(int tmp = las[v];tmp;tmp = nex[tmp])
            if (to[tmp] != fa) b[++ tl][0] = to[tmp],b[tl][1] = v;
    }
    fd(i,tl,1)
    {
        int v = b[i][0],fa = b[i][1];
        int mx = v;
        for(int tmp = las[v];tmp;tmp = nex[tmp])
            if (to[tmp] != fa)
            {
                ans[v] += ans[to[tmp]];
                if (!mx || size[mx] < size[to[tmp]]) mx = to[tmp];
            }
        if (mx != v) merge(mx,v,ans[v]);
        for (int tmp = las[v];tmp;tmp = nex[tmp])
            if (to[tmp] != fa && to[tmp] != mx){
                merge(mx,to[tmp],ans[v]);
            }
        stn[v] = stn[mx];
    }
    fo(i,1,n) printf("%lld\n",ans[i]);
}