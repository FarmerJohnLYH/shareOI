#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const ll N=200200,M=66,mo=1000000007;
ll n,m;
ll to[N*2],nex[N*2],las[N*2];
ll v[N*2];
ll a[M];
ll st,en;
ll fa[N],di[N],de[N];
ll mx; 
void add(ll v)
{
	fd(i,mx,0) 
	if((1ll<<i)&v)
	{
		if(!a[i]) 
		{
			a[i]=v;
			break;
		}
		else v^=a[i];
	}
}
void dfs(ll x,ll ban)
{
	for(ll tp=las[x];tp;tp=tp[nex])
	if(tp!=ban)
	{
		if(de[to[tp]]) 
			add(v[tp]^to[tp][di]^x[di]);
		else 
		{
			di[to[tp]]=di[x]^tp[v];
			de[to[tp]]=de[x]+1;
			dfs(to[tp],tp^1);
		}
	}
}
ll tot=1;
void link(ll x,ll y,ll c)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;v[tot]=c;
	to[++tot]=x,nex[tot]=las[y],las[y]=tot;v[tot]=c;
}
ll ans;
int main()
{
//	freopen("D:/LiuYuanHao/a2.in","r",stdin);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	mx=60;
	fo(i,1,m)
	{
		ll x,y;ll c;
		scanf("%lld%lld%lld",&x,&y,&c);
		link(x,y,c);
	}
	scanf("%lld%lld",&st,&en);
	de[st]=1;
	dfs(st,0);
	ll cnt=0;
	fo(i,0,mx)if(a[i])++cnt;
    fo(i,0,mx)
	{
        ll ct=0;
        fo(j,0,mx)if(a[j]&(1ll<<i))++ct;
        
        if(ct)ans=(ans+(1ll<<i)%mo*((1ll<<(cnt-1))%mo))%mo;
        else 
		if(di[en]&(1ll<<i))
			ans=(ans+(1ll<<i)%mo*((1ll<<cnt)%mo))%mo;
    }
	printf("%lld\n",ans);
	return 0;
}











