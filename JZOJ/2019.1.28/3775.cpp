//#pragma GCC optimize(2) 
#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo (1ll<<62)
#define fo(i,x,y) for (ll i=(x),asdfgh=(y);i<=asdfgh;++i)
#define fd(i,x,y) for (ll i=(x),asdfgh=(y);i>=asdfgh;--i)
#define fi first
#define se second
using namespace std;
typedef double db;
typedef unsigned long long ll;
typedef pair<ll,ll> PI;
ll abs(ll x) {return(((x)>=0)?(x):(-(x)));}
ll max(ll x,ll y) {return(((x)>(y))?(x):(y));}
ll min(ll x,ll y) {return(((x)<(y))?(x):(y));}
ll lowbit(ll x) {return((x)&(-x));}
const ll T=1010,C=66;
ll k;
ll t,q[T];
ll ans,p[C],p0;
ll a[T],a0,sa;
ll qsm(ll x,ll y)
{
	ll rt=1;
	for(int p=1;y>=p;x=x*x,p=p<<1)
	if(y&p)rt=rt*x;
	return rt;
}
ll solve()
{
	ll rt=1;
	fo(i,1,a0)
		rt=rt*qsm(p[i],a[i]);
	return rt;
}
ll JC(ll l,ll r,ll ql,ll qr)
{
	ll rt=1;
	int qi=ql;
	fo(i,l,r)
	{
		rt=rt*i;
		while(qi<=qr&&(rt%qi==0)) rt/=qi++;
	}
	return rt;
}
ll gcd(ll x,ll y)
{
	return(x==0)?y:(gcd(y%x,x));
}
void dfs(ll x,ll v)
{
	if(x>k||x<0||k%x!=0||a0>18)return;
	if(x==k) 
	{
		ans=min(ans,v);
		return;
	}
	ll fz=1,fm=1,fx=x,va=1;
	fo(i,1,a[a0])
	{
		fz=(sa+i),fm=i;
		ll gd=gcd(fz,fm);fz/=gd,fm/=gd;
		fx=fx/fm*fz;
		db pd=0;
		//fx*fz;
		if(pd>k)
			break;
		fx=fx*fz;
		a[++a0]=i;sa+=i;
		va=va*p[a0];
		pd=v*va;
		if(pd>oo)
			break;
		dfs(fx,v*va);
		--a0;sa-=i;
	}
}
int main()
{
	freopen("D:/LiuYuanHao/b2.in","r",stdin);
	freopen("D:/LiuYuanHao/b.out","w",stdout);
	fo(i,2,1000000)
	{
		if(p0>=18)break;
		int flag=0;
		fo(j,1,p0)
		if(i%p[j]==0) 
		{
			flag=1;
			break;
		}
		if(!flag) p[++p0]=i;
	}
	scanf("%llu",&t);
	fo(i,1,t) scanf("%llu",&q[i]);
	fo(i,1,t) 
	{
		k=q[i];
		if(q[i]==1)
			printf("2\n");
		else
		{
			a[0]=62,a0=0,sa=0;
			ans=oo;
			dfs(1,1);
			printf("%llu\n",ans);
		}
	}
	return 0;
}



