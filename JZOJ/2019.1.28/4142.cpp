#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll N=100100*20;
priority_queue<ll> qu;
ll n;
ll f[N];
ll dep[N],sz[N];
ll to[N],las[N],nex[N];
ll tot;
void link(ll x,ll y)
{
	to[++tot]=y,nex[tot]=las[x],x[las]=tot;
}
void dfs(ll x)
{
	sz[x]=1;
	for (ll tp=las[x];tp;tp=tp[nex])
	{
		ll t=to[tp];
		dfs(t);
		sz[x]+=sz[t];
	}
}
ll d[N],ans;
void solve(ll st)
{
	while(!qu.empty()) qu.pop(); 
	ll d0=0;
	for (ll tp=las[st];tp;tp=tp[nex])
		d[++d0]=tp[to];
	if(d0==1)
	{
//		ans+=0;
		//ans+=sz[d[1]];
		return;
	}
	if(d0==0)return;
	fo(i,1,d0) qu.push(-d[i][sz]);
	while(!qu.empty())
	{
		ll x=-qu.top();qu.pop();
		if(qu.empty())break;ll y=-qu.top();qu.pop();
		ll c=x+y;
		ans+=c;
		qu.push(-c);
	}
}
int main()
{
//	 freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%lld",&n);
	fo(i,2,n)
	{
		ll x;
		scanf("%lld",&x);
		link(x,i);
	}
	dfs(1);
	fo(i,1,n) solve(i);
	printf("%lld\n",ans);
	return 0;
}











