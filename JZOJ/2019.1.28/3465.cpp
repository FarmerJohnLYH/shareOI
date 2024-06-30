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
const ll N=100100;
ll f[N],n;
ll v;
pair<ll,ll> a[N],c[N];
ll g[N],g0;
ll le,ri,md,rt;
int main()
{
//	freopen("D:/LiuYuanHao/c.in","r",stdin);
	scanf("%lld",&n);
	fo(i,1,n) scanf("%lld%lld",&c[i].se,&c[i].fi);
	scanf("%lld",&v);
	fo(i,1,n) a[i].fi=(c[i].fi*v-c[i].se),a[i].se=(c[i].fi*v+c[i].se);
	sort(a+1,a+1+n);
	memset(g,127,sizeof g);
	g0=0;g[0]=-oo;
	fo(i,1,n)
	if(a[i].fi>=0&&a[i].se>=0)
	{
		if(a[i].se>=g[g0]) g[++g0]=a[i].se;
		else
		{
			le=0,ri=g0,rt=0;
			while(le<=ri)
			{
				md=(le+ri)>>1;
				if(a[i].se>=g[md]) le=md+1,rt=md;
				else ri=md-1; 
			}
			g[rt+1]=min(g[rt+1],a[i].se);
		}
	}
	printf("%lld ",g0);

	memset(g,127,sizeof g);
	g0=0;g[0]=-g[0];
	fo(i,1,n)
	{
		if(a[i].se>=g[g0]) g[++g0]=a[i].se;
		else
		{
			le=0,ri=g0,rt=0;
			while(le<=ri)
			{
				md=(le+ri)>>1;
				if(a[i].se>=g[md]) le=md+1,rt=md;
				else ri=md-1; 
			}
			g[rt+1]=min(g[rt+1],a[i].se);
		}
	}
	printf("%lld\n",g0);
	return 0;
}











