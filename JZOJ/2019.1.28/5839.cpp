#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=10001000,M=22,mo=1000000007;
int n,m;
int u[M],v[M];
int f[N],du[N],qu[M*2],sz[N];
int ge[N],g0,q0;
ll ans,jc[N];
ll qsm(ll x,ll y)
{
	ll rt=1;
	fo(i,0,30)
	{
		if((1ll<<i)&y) rt=rt*x%mo;
		x=x*x%mo;	
	}
	return rt;
}
int gf(int x)
{
	return(f[x]==x)?(x):(f[x]=gf(f[x]));
}
int tj[N];
void dfs(ll x,ll fg)
{
	if(x>m) 
	{
		fo(i,1,q0) 
		{
			f[qu[i]]=qu[i],sz[qu[i]]=1;
			tj[qu[i]]=(du[qu[i]]==1);
		}
		ll tot=0;
		fo(i,1,g0) 
		{
			ll fx=gf(ge[i][u]),fy=gf(ge[i][v]);
			if(fx==fy) 
			{
				if(sz[fx]==q0&&q0==n)
					ans=(ans+2)%mo;
				return;
			}
			else f[fy]=fx,sz[fx]+=sz[fy],tj[fx]+=tj[fy];
		}
		fo(i,1,q0) 
		if(gf(f[qu[i]])==qu[i])
		{
			if(tj[qu[i]]!=2) 
				return;
			++tot;
		}	
		ans=(ans+fg*jc[n-g0-1]%mo*(1ll<<tot)%mo)%mo;
		return;
	}
	dfs(x+1,fg);
		++du[u[x]],++du[v[x]];
		if(du[u[x]]<=2&&du[v[x]]<=2)
		{
			if(du[u[x]]==1) qu[++q0]=u[x];
			if(du[v[x]]==1) qu[++q0]=v[x];
			ge[++g0]=x;
			dfs(x+1,mo-fg);
			--g0;
			if(du[v[x]]==1) --q0;
			if(du[u[x]]==1) --q0;
		}
		--du[u[x]],--du[v[x]];
}
int main()
{
	freopen("lighthouse.in","r",stdin);
	freopen("lighthouse.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&m);
	fo(i,1,m)
		scanf("%d%d",&u[i],&v[i]);
	jc[0]=1;fo(i,1,n) jc[i]=jc[i-1]*i%mo;
	dfs(1,1);
	printf("%lld\n",ans*qsm(2,mo-2)%mo);
	return 0;
}











