#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll N=50050;
ll n,m;
ll c[N],a[N];
ll bl[N],len;
struct PI{
	ll fi,se,id;
}p[N],ans[N];
ll cnt;
bool cmp(PI a,PI b)
{
	return((a.fi[c]!=b.fi[c])?(a.fi[c]<b.fi[c]):(a.se<b.se));
}
ll gcd(ll x,ll y)
{
	return(y==0)?(x):(gcd(y,x%y));
}
ll sqr(ll x)
{
	return(x*x);
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%lld%lld",&n,&m);len=sqrt(n)+1;
	fo(i,1,n) scanf("%lld",&a[i]);
	fo(i,1,n)c[i]=i/len;
	fo(i,1,m) scanf("%lld%lld",&p[i].fi,&p[i].se),p[i].id=i;
	sort(p+1,p+1+m,cmp);
	fo(l,p[1].fi,p[1].se) ++bl[a[l]];
	fo(i,1,n)if(bl[i])cnt=cnt+bl[i]*bl[i];
	ans[p[1].id].fi=cnt-(p[1].se-p[1].fi+1),ans[p[1].id].se=(p[1].se-p[1].fi)*(p[1].se-p[1].fi+1);
	ll lx=p[1].fi,rx=p[1].se,ly,ry;
	fo(i,2,m)
	{
		ly=p[i].fi,ry=p[i].se;
		while(lx<ly) cnt+=sqr(bl[a[lx]]-1)-sqr(bl[a[lx]]),--bl[a[lx]],++lx;	
		while(lx>ly) --lx,cnt+=sqr(bl[a[lx]]+1)-sqr(bl[a[lx]]),++bl[a[lx]];
		while(rx<ry) ++rx,cnt+=sqr(bl[a[rx]]+1)-sqr(bl[a[rx]]),++bl[a[rx]];	
		while(rx>ry) cnt+=sqr(bl[a[rx]]-1)-sqr(bl[a[rx]]),--bl[a[rx]],--rx;	
		ans[p[i].id].fi=(cnt-(ry-ly+1)),ans[p[i].id].se=(ry-ly)*(ry-ly+1);
	}
	fo(i,1,m)
	{
		ll gd=gcd(ans[i].fi,ans[i].se);
		if(gd==0) printf("0/1\n");
		else printf("%lld/%lld\n",ans[i].fi/gd,ans[i].se/gd);
	}
	return 0;
}











