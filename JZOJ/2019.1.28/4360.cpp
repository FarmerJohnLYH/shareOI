#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
typedef double db;
const ll N=1010,M=10100*2,eps=100000;
ll n;
ll l[N],r[N],a[M];
ll p[N],d[N],t[N];
ll du[N];
ll tot,to[M],nex[M],las[N];
struct network{
	ll tot;
	ll to[M],nex[M],las[N],v[M];
	ll lev[N],pag[N],mem[N];
	ll S,T,n;
	ll dfs(ll x,ll fw)
	{
		if(x==T)return(fw);
		ll cnt=0;
		for (ll tp=mem[x];tp;tp=tp[nex])
		{
			mem[x]=tp;
			if(lev[tp[to]]==lev[x]+1&&tp[v]>0)
			{
				ll pp=dfs(to[tp],min(fw-cnt,tp[v]));
				tp[v]-=pp,v[tp^1]+=pp,cnt+=pp;
				if(cnt==fw) return(fw);
			}	
		}
		if((--pag[lev[x]++])<=0) d[S]=n/*点个数***/;
		++pag[lev[x]];
		return(cnt);
	}
	void link(ll x,ll y,ll vv)
	{
		to[++tot]=y,tot[nex]=las[x];las[x]=tot;
		v[tot]=vv;
		to[++tot]=x,tot[nex]=las[y];las[y]=tot;
		v[tot]=0;
	}
	ll solve()
	{
		ll rt=0;
		while(d[S]<n) 
		{
			fo(i,1,n) mem[i]=las[i];
			rt+=dfs(S,oo);
		}
		return rt;
	}
}sp;
void link(ll x,ll y)
{
	to[++tot]=y,tot[nex]=las[x],las[x]=tot;
	++du[y];
}
ll dt[N*10],bz[N];
void topu()
{
	ll hd=0,tl=0;
	fo(i,1,n)
	if(!du[i]) dt[++tl]=i,bz[i]=1;
	while(hd++<tl)
	{
		ll x=dt[hd],tt;
		for (ll tp=las[x];tp;tp=tp[nex])
		if(!bz[tt=tp[to]]) 
			if(--du[tt]<=0) dt[++tl]=tt,bz[tt]=1;
	}
	fo(i,1,n)
	if(bz[i])
		for (ll tp=las[i];tp;tp=tp[nex])
		if(bz[tp[to]])
			sp.link(i,tp[to],oo);
}
ll val[N];
bool check(ll x)
{	
	ll rt=0;
	fo(i,1,n)
	if(bz[i])
	{
		val[i]=t[i]*eps-d[i]*x;	
		if(val[i]<0) sp.link(sp.S,i,-val[i]);
		else sp.link(i,sp.T,val[i]),rt+=val[i];
	}
	ll tp=sp.solve();
	sp.tot-=(sp.n-2)*2;
	return((rt-tp)<=0);
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%lld",&n);
	fo(i,1,n)
	{
		ll x;
		scanf("%lld",&x);
		l[i]=l[i-1]+1,r[i]=l[i]+x-1;
		fo(j,l[i],r[i]) 
		{
			scanf("%lld",&a[j]);
			link(a[j],i);
		}
	}
	sp.tot=1;sp.S=n+1,sp.T=n+2;
	fo(i,1,n) scanf("%lld%lld",&t[i],&d[i]);
	topu();
	fo(i,1,n) sp.n+=bz[i];
	ll le=0,ri=eps*10000000000ll,mid,ans=0;
	while(le<=ri)
	{
		mid=(le+ri)>>1;
		if(check(mid)) ans=mid,ri=mid-1;
		else le=mid+1;
	}
	printf("%.8lf",(db)eps/(db)ans);
	return 0;
}











