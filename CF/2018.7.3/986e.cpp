#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
#define fd(i,x,y) for (ll i=(x);i>=(y);--i)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PI;
const ll mo=1000000007,N=100100,V=10001000;
ll n,q;
struct node{
	ll tp,x,y,l,lf,v;
	ll id;
}a[N*2];
ll fa[26][N],dep[N];
vector<ll> to[N];
ll tt[N],a0;
ll ans[N];
ll L[N],tot,R[N];
void dfs(ll x)
{
	L[x]=++tot;
	dep[x]=fa[0][x][dep]+1;
	fo(i,1,24) 
	{
		fa[i][x]=fa[i-1][fa[i-1][x]];
		if(0==fa[i][x])break;
	}
	tt[x]=to[x].size();
	fo(i,0,tt[x]-1)
	if(to[x][i]!=fa[0][x])
	{
		fa[0][to[x][i]]=x;
		dfs(to[x][i]);
	}
	R[x]=tot;
}
bool cmv(node a,node b)
{
	return(a.v<b.v||(a.v==b.v&&a.tp>b.tp));
}
ll lca(ll x,ll y)
{
	if(dep[x]<dep[y]) swap(x,y);
	ll tp=dep[x]-dep[y];
	fd(i,24,0)
	if(tp&(1<<i)) x=fa[i][x]; 
	fd(i,24,0)
	if(fa[i][x]!=fa[i][y]) x=fa[i][x],y=fa[i][y];
	return(fa[0][x]);
}
ll p[V/100],bz[V],p0;
void Prime_get()
{
	bz[1]=1;
	fo(i,2,10000000)
	{
		if(!bz[i]) p[++p0]=i;
		fo(j,1,p0)
		if(1ll*i*p[j]<10000000)
		{
			bz[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
}
ll tr[N],tr2[N];
ll lowbit(ll x)
{
	return(x&(-1));
}
ll query(ll x)
{
	ll rt=0;
	while(x>0)
	{
		rt+=tr[x];
		x-=lowbit(x);
	}
	return rt;
}
void add(ll x,ll v)
{
	while(x<=n)
	{
		tr[x]+=v;
		x+=lowbit(x);
	}
}

ll query2(ll x)
{
	ll rt=0;
	while(x>0)
	{
		rt+=tr2[x];
		x-=lowbit(x);
	}
	return rt;
}
void add2(ll x,ll v)
{
	while(x<=n)
	{
		tr2[x]+=v;
		x+=lowbit(x);
	}
}
ll qsm(ll x,ll y)
{
	ll rt=1;
	fo(i,0,24)
	{
		if(y&(1<<i)) rt=(1ll*rt*x)%mo;
		x=(1ll*x*x)%mo;
	}
	return rt;
}
vector<PI> wz[N],cl,cl2;
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%I64d",&n);
	fo(i,1,n-1)
	{
		ll x,y;
		scanf("%I64d%I64d",&x,&y);
		to[x].push_back(y),to[y].push_back(x);
	}
	fo(i,1,n)
	{
		ll x;
		scanf("%I64d",&x);
		a[++a0].tp=1;
		a[a0].x=i,a[a0].v=x;
	}
	dfs(1);
	Prime_get();
	scanf("%I64d",&q);
	fo(i,1,q)
	{
		ll u,v,x;
		scanf("%I64d%I64d%I64d",&u,&v,&x);
		a[++a0].tp=2;
		a[a0].x=u,a[a0].y=v,a[a0].l=lca(u,v),a[a0].lf=fa[0][lca(u,v)];
		a[a0].v=x;a[a0].id=i;
		ans[i]=1;
	}
	sort(a+1,a+1+a0,cmv);
	fo(i,1,a0)
	{
		ll x=a[i].v,ct;
		fo(j,1,p0)
		{
			ct=0;
			if(p[j]*p[j]>x) break;
			if(x%p[j]==0)
				while(x%p[j]==0) x/=p[j],++ct;
			if(ct)
			{
				PI aa;aa.fi=i,aa.se=ct;
				wz[j].push_back(aa);
			}
		}
	}
	fo(l,1,p0)
	{
		ll tpt=wz[l].size();
		fo(ii,0,tpt-1)
		{
			ll i=wz[l][ii].fi,vl=wz[l][ii].se; 
			if(a[i].tp==1) 
			{
				ll x=a[i].x;
				add(L[x]-1,-vl);
				add(R[x],vl);
				cl.push_back(make_pair(L[x]-1,vl));
				cl.push_back(make_pair(R[x],-vl));
				add2(L[x]-1,-1);
				add2(R[x],1);
				cl2.push_back(make_pair(L[x]-1,1));
				cl2.push_back(make_pair(R[x],-1));
			}
			if(a[i].tp==2)
			{
				ll x=a[i].x,y=a[i].y,l=a[i].l,lf=a[i].lf;
				ll rt=query(x)+query(y)-query(l)-query(lf);
				ll rt2=query2(x)+query2(y)-query2(l)-query2(lf);
				ans[a[i].id]=(1ll*ans[a[i].id]*qsm(p[l],rt))%mo;
				ans[a[i].id]=(1ll*ans[a[i].id]*qsm(qsm(p[l],rt2),mo-2))%mo;
			}
		}

		fo(ii,0,tpt-1)
		{
			ll i=wz[l][ii].fi,vl=wz[l][ii].se; 
			if(a[i].tp==2)
			{
				ll x=a[i].x,y=a[i].y,l=a[i].l,lf=a[i].lf;
				ll rt2=query2(x)+query2(y)-query2(l)-query2(lf);
				ans[a[i].id]=(1ll*ans[a[i].id]*qsm(p[l],rt2))%mo;
			}
		}
		tpt=cl.size();
		fo(i,0,tpt-1) add(cl[i].fi,cl[i].se);
		cl.clear();
		tpt=cl2.size();
		fo(i,0,tpt-1) add(cl2[i].fi,cl2[i].se);
		cl2.clear();
	}
	fo(i,1,q) 
		printf("%I64d\n",ans[i]);
	return 0;
}











