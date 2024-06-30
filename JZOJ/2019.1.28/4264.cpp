#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll M=10010,P=100100;
ll T;
ll p[P],bz[P],p0;
ll n,m,A;
void init(ll n)
{
	bz[1]=1;
	fo(i,2,n)
	{
		if(!bz[i]) p[++p0]=i;
		fo(j,1,p0)
		{
			if(1ll*p[j]*i>n)break;
			bz[p[j]*i]=1;
			if(i%p[j]==0) break;
		}
	}
}
ll q[P],e[P],q0;
void deal(ll m)
{
	q0=0;
	fo(i,1,p0)
	{
		if(p[i]*p[i]>m) break;
		if(m%p[i]==0) 
		{
			q[++q0]=p[i];e[q0]=1;
			m/=p[i];
			while(m%p[i]==0)
				++e[q0],m/=p[i],q[q0]*=p[i];
		}
	}
	if(m>1) e[++q0]=1,q[q0]=m;
}
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1,y=0;
		return(a);
	}
	ll rt=(exgcd(b,a%b,x,y));
	ll t=x;x=y;y=(t-(a/b)*y);
	return rt;
}
ll check(ll x){return(x<0)?0:(x);}
ll calc(ll a,ll b)
{
	ll x,y,rt=0;
	exgcd(a,b,x,y);
	while(x<0) x+=b;
	ll k=A*x%b,p=n/a;
	if(p>=k) rt+=(p-k)/b+1;
	if(k==0)--rt;
	return rt;
}
ll ans;
void dfs(ll x,ll v)
{
	if(x>q0)
	{
		ans+=calc(v,m/v);
		return;
	}
	dfs(x+1,v);
	dfs(x+1,v*q[x]);
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	init(P-10);
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&n,&m,&A);
		deal(m);
		ans=0;
		dfs(1,1);
		printf("%lld\n",ans);
	}
	return 0;
}
