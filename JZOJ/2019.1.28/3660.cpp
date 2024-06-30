#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x),asdfgh=(y);i<=asdfgh;++i)
#define fd(i,x,y) for (ll i=(x),asdfgh=(y);i>=asdfgh;--i)
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<db,db> PI;
ll abs(ll x) {return(((x)>=0)?(x):(-(x)));}
ll max(ll x,ll y) {return(((x)>(y))?(x):(y));}
ll min(ll x,ll y) {return(((x)<(y))?(x):(y));}
ll lowbit(ll x) {return((x)&(-x));}
const ll N=50050;
const db pai=3.1415926535898,EPS=1e-15;
ll n;
PI a[N];
db A;
ll p;
bool operator < (PI a,PI b)
{
	return((1ll*a.fi*a.fi+1ll*a.se*a.se)<(1ll*b.fi*b.fi+1ll*b.se*b.se));
}
db dis(PI x,PI y)
{
	return(sqrt((x.fi-y.fi)*(x.fi-y.fi)+(x.se-y.se)*(x.se-y.se)));
}
PI rd(PI a,PI b,PI c)
{
	PI rt;
	db a1=b.fi-a.fi,b1=b.se-a.se,c1=((a1*a1)+(b1*b1))/2;
	db a2=c.fi-a.fi,b2=c.se-a.se,c2=((a2*a2)+(b2*b2))/2;
	db d=(a1*b2-a2*b1);
	rt.fi=a.fi+(c1*b2-c2*b1)/d;
	rt.se=a.se+(a1*c2-a2*c1)/d;
	return rt;
}
int main()
{
	freopen("amplifier.in","r",stdin);
	freopen("amplifier.out","w",stdout);
	// freopen("D:/LiuYuanHao/b1.in","r",stdin);
	scanf("%lld",&n);
	fo(i,1,n)scanf("%lf%lf",&a[i].fi,&a[i].se);
	scanf("%lf%lld",&A,&p);sort(a+1,a+1+n);
	A=A*pai/180;
	fo(i,1,n)
	{
		PI t=a[i];
		a[i].fi=t.fi*cos(A)-t.se*sin(A);
		a[i].se=t.fi*sin(A)+t.se*cos(A);
		a[i].fi=(db)a[i].fi/p;
	}
	db ans=0;PI ct=a[1];
	fo(i,2,n)
	if(dis(ct,a[i])-ans>EPS)
	{
		ct=a[i];
		ans=0;
		fo(j,1,i-1)
		if(dis(ct,a[j])-ans>EPS)
		{
			ct.fi=(a[i].fi+a[j].fi)/2;
			ct.se=(a[i].se+a[j].se)/2;
			ans=dis(ct,a[j]);
			fo(k,1,j-1)
			if(dis(ct,a[j])-ans>EPS)
			{
				ct=rd(a[i],a[j],a[k]);
				ans=dis(ct,a[i]);
			}
		}
	}
	printf("%.3lf\n",ans);
	return 0;
}











