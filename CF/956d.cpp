#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fi first
#define se second
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
#define fd(i,x,y) for (ll i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const ll N=100100;
ll n,w,x[N],v[N],p[N];
ll gcd(ll x,ll y)
{
	return(y==0)?(x):(gcd(y,x%y));
}
struct fl{
	ll x,y;//x/y
	fl(){}
	fl(ll x_,ll y_)
	{
		x_=abs(x_),y_=abs(y_); 
		ll c=gcd(x_,y_);
		x_/=c,y_/=c;
		x=x_,y=y_;
	}
};
typedef pair<fl,fl> PI;
bool operator <(fl a,fl b)
{
	return((a.x*b.y<a.y*b.x));
}
bool sam(fl a,fl b)
{
	return(a.x==b.x&&a.y==b.y);
}
PI t[N];
pair<fl,ll> d[N];
ll tr[N];
ll lowbit(ll x)
{
	return (x&(-x));
}
ll query(ll x)
{
	ll rt=0;
	while(x)
	{
		rt+=tr[x];
		x-=lowbit(x);
	}
	return rt;
}
void add(ll x,ll v)
{
	while(x<=n) 
	{
		tr[x]+=v;
		x+=lowbit(x);
	}
}
bool cmp(PI a,PI b)
{
	return(a.fi<b.fi||(sam(a.fi,b.fi)&&b.se<a.se));
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%I64d%I64d",&n,&w);
	fo(i,1,n) 
	{
		scanf("%I64d%I64d",&x[i],&v[i]);
		ll v0=v[i]-w,v1=v[i]+w;
		t[i]=make_pair(fl(x[i],v0),fl(x[i],v1));
	}
	sort(t+1,t+1+n,cmp);
	fo(i,1,n)d[i].fi=t[i].se,d[i].se=i;
	sort(d+1,d+1+n);
	ll rk=0;
	fo(i,1,n)
	{
		++rk;
		if(sam(d[i].fi,d[i-1].fi)) --rk;
		p[d[i].se]=rk;
	}
	ll ans=0,cnt=0;
	fd(i,n,1)
	{
		ans+=query(p[i]);
		add(p[i],1);
	}
	printf("%I64d\n", ans);
	return 0;
}
