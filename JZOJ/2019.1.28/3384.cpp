#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
typedef long double db;
ll gcd(ll a,ll b)
{
	return(b==0)?a:(gcd(b,a%b));
}
ll mul(ll x,ll y,ll p)
{
	ll tp=(ll)((db)x*y/p+1e-8)*p;
	x=x*y-tp;
	while(x<0)x+=p;
	return x;
}
ll pw(ll a,ll n,ll p)
{
	ll v=1;a%=p;
	for(;n;n>>=1,a=mul(a,a,p))
		if(n&1)v=mul(v,a,p);
	return v;
}
ll phi(ll x)  
{
	ll y=x;
	fo(i,2,sqrt(x)+1)
	if(x%i==0) 
	{
		while(x%i==0) x/=i;
		y=y/i*(i-1);
	}
	if(x>1)y=y/x*(x-1);
	return y;
}
ll calc(ll A,ll B)
{
	ll x=phi(B),y=x;
	fo(i,2,sqrt(x)+1)
	if(x%i==0)
	{
		while(x%i==0)x/=i;
		while(y%i==0&&pw(A,y/i,B)==1)y/=i;
	}
	if(x>1&&pw(A,y/x,B)==1)y/=x;
	return y;
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	int T;scanf("%d",&T);
	while(T--)
	{
		ll a,b,c;scanf("%lld%lld%lld",&a,&b,&c);b/=gcd(a,b);
		ll cnt=0,x;
		while((x=gcd(b,c))!=1) b/=x,++cnt;
		printf("%lld %lld\n",cnt,(b==1)?0ll:calc(c,b));
	}
	return 0;
}



