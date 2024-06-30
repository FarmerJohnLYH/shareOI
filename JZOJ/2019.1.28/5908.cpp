#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=200200,M=1001000;
int n,q;
int fa[20][N],tot,to[N*2],nex[N*2],las[N];
ll v[N],dis[N];
int d[M],bz[N],dep[N],d0;
struct qy{
	int tp,x;
	ll y;
}a[N];
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
}
void link(int x,int y)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
}
int dfn[N],cnt,sz[N],pp[N];
void dfs(int x)
{
	sz[x]=1;
	dfn[x]=++cnt;pp[cnt]=x;
	dep[x]=dep[fa[0][x]]+1;
	dis[x]=dis[fa[0][x]]+v[x];
	for(int tp=las[x];tp;tp=tp[nex])
	if(to[tp]!=fa[0][x])
	{
		fa[0][to[tp]]=x;
		dfs(to[tp]);
		sz[x]+=to[tp][sz];
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	int d=dep[x]-dep[y];
	fo(i,0,18) if(d&(1<<i)) x=fa[i][x];
	if(x==y)return(x);
	fd(i,18,0) if(fa[i][x]!=fa[i][y])x=fa[i][x],y=fa[i][y];
	return(fa[0][x]);
}
bool cmp(int x,int y)
{
	return(dfn[x]<dfn[y]);
}
ll ans;
ll t[N];
int lowbit(int x)
{
	return(x&(-x));
}
void add(int x,int y)
{
	if(x<=0)return;
	for(;x<=n;x+=lowbit(x)) t[x]+=y;
}
ll query(int x)
{
	if(x<=0)return 0;
	ll rt=0;
	for(;x;x-=lowbit(x)) rt+=t[x];
	return rt;
}
void solve()
{
	fo(i,1,q) 
	{
		if(a[i].tp==2)
		{
			add(dfn[a[i].x],a[i].y);	
			add(dfn[a[i].x]+sz[a[i].x],-a[i].y);	
		}
		else
		{
			ans=0;
			int la=d[a[i].x];	
			fo(j,a[i].x,a[i].y) 
			{
				ans+=query(dfn[d[j]]);
				if(j>a[i].x) ans-=query(dfn[lca(d[j],d[j-1])]),la=lca(la,d[j]);
			}
			ans-=query(dfn[fa[0][la]]);
			printf("%lld\n",ans);
		}
	} 
}
int main()
{
	freopen("kaihuang.in","r",stdin);
	freopen("kaihuang.out","w",stdout);
//	freopen("D:/LiuYuanHao/b2.in","r",stdin);
//	freopen("D:/LiuYuanHao/b.out","w",stdout);
	n=read(),q=read();
	fo(i,1,n) 
		v[i]=read();
	fo(i,1,n-1)
	{
		int x=read(),y=read();
		link(x,y),link(y,x);
	} 
	dfs(1);
	fd(i,n,2) 
		dis[pp[i]]-=dis[pp[i-1]];
	fo(i,1,n) 
		add(dfn[i],dis[i]);
	fo(l,1,18) fo(x,1,n)
		fa[l][x]=fa[l-1][fa[l-1][x]];
	fo(i,1,q)
	{
		char ch=getchar();while(ch!='Q'&&ch!='C') ch=getchar();
		if(ch=='Q')
		{
			a[i].tp=1;
			a[i].x=d0+1;
			int x=read();
			while(x!=0) 
			{
				if(!bz[x])d[++d0]=x;
				bz[x]=1;
				x=read();
			}
			a[i].y=d0;
			sort(d+a[i].x,d+a[i].y+1,cmp);
			fo(j,a[i].x,a[i].y)bz[d[j]]=0;
		}
		if(ch=='C')
		{
			a[i].tp=2;
			a[i].x=read(),a[i].y=read()-v[a[i].x];
			v[a[i].x]+=a[i].y;
		}
	}
	solve();
	return 0;
}








