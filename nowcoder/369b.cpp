#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
using namespace std;
#define ll long long 
const ll N=200200;
ll n;
ll to[N*2],nex[N*2],las[N],v[N*2],tot;
void link(ll x,ll y,ll w)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot,v[tot]=w;
}
ll dis[N],ans;
void dfs(ll x,ll y,ll f)
{
	dis[x]=y;
	for(ll tp=las[x];tp;tp=tp[nex])
		if(to[tp]!=f)
			dfs(to[tp],v[tp]+y,x);
}
int main()
{
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%lld",&n);
	fo(i,1,n-1)
	{
		ll x,y,c;
		scanf("%lld%lld%lld",&x,&y,&c);
		link(x,y,c),link(y,x,c);	
		ans+=c*2;
	}
	dfs(1,0,0);
	ll m=1;
	fo(i,1,n) if(dis[m]<dis[i]) m=i;
	dfs(m,0,0);
	m=0; 
	fo(i,1,n) m=max(m,dis[i]);
	printf("%lld\n",ans-m);
	return 0;
}








