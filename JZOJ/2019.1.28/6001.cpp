#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo (1ll<<60)
#define fo(i,x,y) for(ll i=(x);i<=(y);++i)
#define fd(i,x,y) for(ll i=(x);i>=(y);--i)
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
typedef long long ll;
const ll N=100100*2,M=N*33;
ll n,q;
struct node{
	ll p,r,c,id;
}a[N];ll p[N];
ll bz[N];
ll to[M],nex[M],las[N],tot;
void link(ll x,ll y)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
}
bool cmp(node a,node b){return(a.p<b.p);}
ll dfn[N],low[N],cnt;
ll st[N],s0,t[N];
ll du[N],vis[N];
void dfs(ll x)
{
	dfn[x]=++cnt,low[x]=cnt;
	st[++s0]=x;vis[x]=1;
	for(ll tp=las[x];tp;tp=tp[nex])
	{
		if(!dfn[to[tp]])
		{
			dfs(to[tp]);
			low[x]=min(low[x],low[to[tp]]);
		}
		else if(vis[to[tp]]) low[x]=min(low[x],dfn[to[tp]]);
	}
	if(low[x]==dfn[x])
	{
		while(st[s0]!=x) vis[st[s0]]=0,t[st[s0]]=x,--s0;
		--s0;t[x]=x;
		vis[x]=0;
	}
}
priority_queue<ll> de[N],qe[N];
ll ans;
ll e[M][2],e0,ck[N],duu[N];
ll main()
{
	 freopen("mines.in","r",stdin);
	 freopen("mines.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.ans","w",stdout);
	scanf("%lld%lld",&n,&q);
	fo(i,1,n)
	{
		scanf("%lld%lld%lld",&a[i].p,&a[i].r,&a[i].c);
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	fo(i,1,n) p[a[i].id]=i;
	fo(i,1,n) 
	{
		ll q=a[i].p+a[i].r;
		fo(j,i+1,n) 
		{
			if(a[j].p<=q) link(i,j),e[++e0][0]=i,e[e0][1]=j,++duu[j];
			if(a[j].p+a[j].r>=q) break;
		}
	}
	fd(i,n,1) 
	{
		ll q=a[i].p-a[i].r;
		fd(j,i-1,1) 
		{
			if(a[j].p>=q) link(i,j),e[++e0][0]=i,e[e0][1]=j,++duu[j];
			if(a[j].p-a[j].r<=q) break;
		}
	}
	fo(i,1,n)if(!dfn[i])
		dfs(i); 
	fo(i,1,e0) if(e[i][0][t]!=e[i][1][t]) 
		++e[i][1][t][du];
	fo(i,1,n) if(t[i]==i && du[i]==0) ck[i]=1;
	fo(i,1,n) if(ck[t[i]]) 
		qe[t[i]].push(-a[i].c);
	fo(i,1,n) if(ck[i]) ans+=qe[i].top();
	fo(i,1,q)
	{               
		ll x,y,pre;
		scanf("%lld%lld",&x,&y);
		x=p[x];
		if(ck[t[x]]) 
		{
			pre=a[x].c;a[x].c=y;x=t[x];
			ll t=qe[x].top();      while(!de[x].empty() && de[x].top()==t) de[x].pop(),qe[x].pop(),t=qe[x].top();
			ans-=t;
			de[x].push(-pre);	
			qe[x].push(-y);
			t=qe[x].top();while(!de[x].empty() && de[x].top()==t) de[x].pop(),qe[x].pop(),t=qe[x].top();
			ans+=t;
		}
		printf("%lld\n",-ans);
	}
	return 0;
} 
