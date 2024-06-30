//ÔÙ¼ûÀ² µÜµÜ! 
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
#define fi first
#define se second
#define mp make_pair 
typedef long long ll;
typedef unsigned long long ull;
typedef long double db;
typedef pair<ll,ll> PI;
const ll mo=3814697265625,M=1953125,PP=1001000,phi=mo/5*4;
const db eps=1e-9;
ll T,n;
/*
ll mul(ll x, ll y,ll mo) {
    ll s = 0;
    for(; y; y /= 2, x = x * 2 % mo)
        if(y & 1) s = (s + x) % mo;
    return s;
}

ll mul(ll x,ll y,ll mo)
{
	ll tp=(ll)((db)x/(db)mo*(db)y+eps);tp=tp*mo;
	ll rt=(x*y-tp)%mo;
	return(rt+mo)%mo;
}

*/ ll mul(ll x, ll y,ll mo) {
    ll z = (db) x * y / mo; z = x * y - z * mo;
    if(z < 0) z += mo; else if(z > mo) z -= mo;
    return z;
}
PI mu(PI a,PI b)
{
	return(mp((mul(a.fi,b.se,mo)+mul(a.se,b.fi,mo))%mo,mul(a.se,b.se,mo)));
}
ll qsm(ll x,ll y)
{
	ll rt=1;
	fo(i,0,50)
	{
		if((1ll<<i)&(y)) 
			rt=mul(rt,x,mo);
		x=mul(x,x,mo);
	}
	return rt;
}
PI d[M+100],q[M+100];
ll JC[PP];
ll jc(ll x)
{
	if(x==0)return 1;
	if(x<PP) return(JC[x]);
	x=min(x,mo-1);
	ll rt=1,tmp=x/5;
	fo(i,1,M-1)d[i]=mp(1,i);
	q[0]=mp(0,1);
	fo(i,1,M-1)
	if(i%5)
	{
		q[i]=mu(q[i-1],d[i]); 
	}
	ll cnt=0;
	for(;x>=M;x-=M)
	{
		++cnt;
		rt=mul(rt,(mul(mul(q[M-1].fi,cnt,mo),M,mo)+q[M-1].se)%mo,mo);
	}
	++cnt;
	rt=mul(rt,(mul(mul(q[x].fi,cnt,mo),M,mo)+q[x].se)%mo,mo);
	return mul(rt,jc(tmp),mo);
}
ll C(ll x,ll y)
{
	qsm(mul(jc(x),jc(y-x),mo),phi);
	return(mul(jc(y),qsm(mul(jc(x),jc(y-x),mo),phi),mo));
}
int main()
{
	freopen("catalan.in","r",stdin);
	freopen("catalan.out","w",stdout);
//	freopen("D:/LiuYuanHao/b.in","r",stdin);
	JC[0]=1;fo(i,1,PP) JC[i]=mul(JC[i-1],i,mo);
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		ll p=C(n,n*2);
		p=qsm(n+1,phi);
		p=mul(C(n,n*2),qsm(n+1,phi),mo);
		printf("%lld\n",mul(C(n,n*2),qsm(n+1,phi),mo));
	}
	return 0;
}











