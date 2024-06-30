#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
#define fd(i,x,y) for (ll i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const ll N=600300;
ll n,m;
ll to[N*2],nex[N*2],las[N];
ll low[N],dfn[N],tot;
ll ri[N],sm[N];
void link(ll x,ll y)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
}
ll cnt,bri[N*2];
ll sta[N],s0;
int vis[N];
void dfs(ll x,ll f)
{
	dfn[x]=low[x]=++cnt;
	sta[++s0]=x;vis[x]=1;	
	for(ll tp=las[x];tp;tp=tp[nex])
	if(tp!=f)
	{
		ll tt=to[tp];
		if(!dfn[tt])
		{
			dfs(tt,tp^1);	
			low[x]=min(low[x],low[tt]);
			if(low[tt]==dfn[x])
			{
				ll mn=x,mx=x;
				while(sta[s0]!=x&&s0>0) 
				{
					mn=min(mn,sta[s0]),mx=max(mx,sta[s0]);
					sta[s0][vis]=0;
					--s0;
				}
				if(mn!=mx)
					ri[mn]=min(ri[mn],mx-1);
			}
			else if(low[tt]>dfn[x]) --s0;
		}else 
			if(vis[tt])low[x]=min(low[x],dfn[tt]);
	}
}
ll q;
ll ans;
ll find(ll l,ll r,ll v)
{
	ll mid,rt=l-1;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(ri[mid]==v)return mid;
		if(ri[mid]<v) l=mid+1,rt=mid;
		else r=mid-1;
	}
	return rt;
}
int main()
{
	 freopen("graph.in","r",stdin);
	 freopen("graph.out","w",stdout);
//	freopen("D:/LiuYuanHao/a2.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	tot=1;
	scanf("%lld%lld",&n,&m);
	fo(i,1,m)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		link(x,y),link(y,x);
	}
	memset(ri,127,sizeof ri);
	dfs(1,0);
	ri[n]=n;
	fd(i,n-1,1) ri[i]=min(ri[i+1],ri[i]);ri[0]=0;
	fo(i,1,n) sm[i]=sm[i-1]+ri[i];
	scanf("%lld",&q);
	while(q--)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		ll p=find(x,y,y);//涓ユ牸<y
		ll ans=sm[p]-sm[x-1]+1ll*(y-p)*y;
		--y,--x;
		ans=ans-(1ll*(x+y)*(y-x+1)/2);
		printf("%lld\n",ans);
	}
	return 0;
}

