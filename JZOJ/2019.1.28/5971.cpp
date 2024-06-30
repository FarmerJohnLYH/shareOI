#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
#define fd(i,x,y) for (ll i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const ll N=220;
ll n,a[N];
ll fa[10][N];
ll to[N][N],t0[N];
ll d[N],d0,bz[N];
ll ans,g[N],de[N];
ll cnt,dep[N],sz[N];
ll lca(ll x,ll y)
{
	if(dep[x]<dep[y]) swap(x,y);
	ll d=dep[x]-dep[y];
	fo(i,0,8) if(d&(1<<i)) x=fa[i][x];
	if(x==y)return x;
	fd(i,8,0) if(fa[i][x]!=fa[i][y]) x=fa[i][x],y=fa[i][y];
	return fa[0][x];
}
ll smin(ll x,ll y)
{
	if(x*y==0) return x^y;
	if(g[d[x]]==g[d[y]]) return max(x,y);
	return(g[d[x]]<g[d[y]])?x:y;
}
ll pv[N];
inline ll find(ll x)
{
	ll px=0;
	if(pv[x] && (!bz[pv[x]])) return pv[x];
	fo(i,1,t0[x])
	if(to[x][i]!=fa[0][x])
	{
		ll qaq=find(to[x][i]);
		px=smin(px,qaq);
	}
	return px;
}
ll tot;
void dfs(ll x)
{
	if(cnt>=ans) return;
	ll px=0;
	px=find(x);
	if(!px) return;
	bz[px]=1;
	cnt+=dep[d[px]]-dep[x];
	++tot;
	fo(i,1,t0[x])
	if(to[x][i]!=fa[0][x])
		dfs(to[x][i]);
}
void run(ll x,ll f)
{
	fa[0][x]=f;
	dep[x]=dep[f]+1;
	de[x]=de[f]+de[x];
	ll pv=g[x];g[x]=0;
	fo(i,1,t0[x]) 
	if(to[x][i]!=f)
		run(to[x][i],x),g[x]=max(g[x],to[x][i][g]),sz[x]+=to[x][i][sz];
	g[x]+=pv;
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
// freopen("party.in","r",stdin);
// freopen("party.out","w",stdout);
	scanf("%lld",&n);
	fo(i,1,n)
	{
		char ch=getchar();while(ch!='0'&&ch!='1') ch=getchar();
		if(ch=='1') d[++d0]=i;
	}
	fo(i,1,n-1)
	{
		ll x,y;
		scanf("%lld%d",&x,&y);
		to[x][++t0[x]]=y,to[y][++t0[y]]=x;	
	}
	ans=oo;
	fo(i,1,n)
	{
		memset(bz,0,sizeof bz);
		memset(sz,0,sizeof sz);
		memset(g,0,sizeof g);
		memset(dep,0,sizeof dep);
		memset(pv,0,sizeof pv);
		memset(fa,0,sizeof fa);
		memset(de,0,sizeof de);
		cnt=tot=0;
		fo(x,1,d0) sz[d[x]]++,++de[d[x]],++g[d[x]],pv[d[x]]=x;
		run(i,0);
		if(i==9)
			printf("");
		fo(x,1,n) g[x]=(g[x]+de[x]*1000)*1000+sz[x];
		fo(l,1,8) fo(x,1,n)
			fa[l][x]=fa[l-1][fa[l-1][x]];
		dfs(i);
		ans=min(ans,cnt);
	}
	printf("%lld\n",ans);
	return 0;
}




