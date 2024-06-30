#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x),asdfgh=(y);i<=asdfgh;++i)
#define fd(i,x,y) for (ll i=(x),asdfgh=(y);i>=asdfgh;--i)
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<ll,ll> PI;
ll abs(ll x) {return(((x)>=0)?(x):(-(x)));}
ll max(ll x,ll y) {return(((x)>(y))?(x):(y));}
ll min(ll x,ll y) {return(((x)<(y))?(x):(y));}
ll lowbit(ll x) {return((x)&(-x));}
const ll N=250250*2;
ll n;
ll to[N],nex[N],las[N];
ll f[N],g[N];
ll sz[N],tot;
ll fa[N];
ll ans;
void dfs(ll x,ll ft)
{
	fa[x]=ft;
	for(ll tmp=las[x];tmp;tmp=tmp[nex])
	if(to[tmp]!=ft)
	{
		ll t=tmp[to];
		dfs(t,x);
		sz[x]+=sz[t];
		f[x]+=sz[t]+f[t];
	}
	++sz[x];
}
ll mn[10],m0;
void dg(ll x,ll ft)
{
	ll siz=sz[1]-sz[x];
	g[x]=g[fa[x]]+(sz[1]-sz[x])+(f[fa[x]]-f[x]-sz[x]);
	for(ll tmp=las[x];tmp;tmp=tmp[nex])
	if(to[tmp]!=ft)
	{
		ll t=tmp[to];
		dg(t,x);
		siz=max(siz,sz[t]);
	}
		 if(siz==mn[0])mn[++m0]=x;
	else if(siz<mn[0]) mn[0]=siz,mn[m0=1]=x;
}
void link(ll x,ll y)
{
	(++tot)[to]=y,tot[nex]=las[x];
	x[las]=tot;
}
ll a[N],a0;
ll p[N],p0;
ll F[N];
ll solve(ll m)
{
	sort(a+1,a+1+a0);
	ll ls=a[1],tt=1;
	fo(i,2,a0)
	{
		if(a[i]==ls) ++tt;
		else
		{
			--tt,p[++p0]=ls;
			fo(l,0,19)
			if(tt>=(1<<l)) p[++p0]=ls*(1<<l),tt-=(1<<l);
			fo(l,0,19)
			if(tt&(1<<l)) p[++p0]=ls*(1<<l);
			tt=1,ls=a[i];
		}
	}
		--tt,p[++p0]=ls;		
		fo(l,0,19)
		if(tt>=(1<<l)) p[++p0]=ls*(1<<l),tt-=(1<<l);
		fo(l,0,19)
		if(tt&(1<<l)) p[++p0]=ls*(1<<l);
	memset(F,0,sizeof F);
	F[0]=1;
	fo(j,1,p0)
		fd(i,m,1)
		{
			if(i-p[j]<0)break;
			if(F[i-p[j]])F[i]=1;
		}
	fd(i,m,0)
		if(F[i]) return((sz[1]-1-i)*i);
}
void work(ll x)
{
	if(fa[x])a[a0=1]=sz[1]-sz[x]; else a0=0;
	for (ll tmp=las[x];tmp;tmp=nex[tmp])
	if(tmp[to]!=x[fa])
		a[++a0]=tmp[to][sz];
	ll sum=f[x]+g[x]+solve((sz[1]-1)/2);
	if(sum>ans)ans=sum;
}
int main()
{
//	freopen("polarization.in","r",stdin);
//	freopen("polarization.out","w",stdout);
	freopen("D:/LiuYuanHao/c2.in","r",stdin);
	scanf("%lld",&n);
	fo(i,1,n-1) 
	{
		ll x,y;
		scanf("%lld%d",&x,&y);
		link(x,y),link(y,x);
	}
	mn[0]=oo;
	dfs(1,0);
	f[0]=f[1]+sz[1],g[0]=0;
	dg(1,0);
	fo(i,1,m0) work(mn[i]);
	printf("%lld %lld\n",n-1,ans);
	return 0;
}











