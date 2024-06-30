 #pragma GCC optimize(2)
#include <set>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
#define fd(i,x,y) for (ll i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const ll N=500500;
ll n,m;
ll f[N],g[N];
ll nex[N*2],las[N],tot,va[N*2],to[N*2];
void link(ll x,ll y,ll c)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
	va[tot]=c;
}
ll le,ri,mid,ans;
#define max(x,y) ((x)>(y)?(x):(y))
vector<ll> a[N];
multiset<ll> q;
ll bz[N];
bool cmp(ll x,ll y)
{
	return(x>y);
}
void work(ll x,ll fa)
{
	for(ll tp=las[x];tp;tp=tp[nex])
	if(to[tp]!=fa)
	{
		work(to[tp],x);
		f[x]+=f[to[tp]];
		if(g[to[tp]]+va[tp]>=mid) ++f[x];
		else a[x].push_back(g[to[tp]]+va[tp]);
	}
	sort(a[x].begin(),a[x].end(),cmp);
	q.clear();
	ll tt=a[x].size()-1;
	fd(i,tt,0)
	{
		ll p=a[x][i];
		if(q.lower_bound(mid-p)!=q.end()) q.erase(q.lower_bound(mid-p)),++f[x];
		else q.insert(p);
		a[x].pop_back();
	}
	if(!q.empty()) 
	{
		multiset<ll>::iterator it=q.end();it--; 
		g[x]=*it;
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%lld%lld",&n,&m);
	fo(i,1,n-1)
	{
		ll x,y,c;scanf("%lld%lld%lld",&x,&y,&c);
		link(x,y,c),link(y,x,c);
		ri+=c;
	}
	ri/=m;le=1;
	while(le<=ri)
	{
		fo(i,1,n) 
			f[i]=g[i]=0;
		mid=(le+ri)>>1;
		work(1,0);
		if(f[1]>=m) le=mid+1,ans=mid;
		else ri=mid-1; 
	}
	printf("%lld\n",ans);
	return 0;
}








