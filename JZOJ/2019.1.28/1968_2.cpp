#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x),asdfgh=(y);i<=asdfgh;++i)
#define fd(i,x,y) for (ll i=(x);asdfgh=(y);i>=asdfgh;--i)
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<ll,ll> PI;
ll abs(ll x) {return(((x)>=0)?(x):(-(x)));}
ll max(ll x,ll y) {return(((x)>(y))?(x):(y));}
ll min(ll x,ll y) {return(((x)<(y))?(x):(y));}
ll lowbit(ll x) {return((x)&(-x));}
const ll N=40040*2;
ll n;
ll m;
ll t[N],r[N],R[N];
ll q[N],f[N];
PI a[N];
ll s[N][2],hd,tl;
ll pp[1001000];
ll cr(ll k,ll b,ll k1,ll b1)
{
	return(-((b-b1)/(k-k1)));
}
int main()
{
	freopen("D:/LiuYuanHao/c3.in","r",stdin);
	scanf("%lld%lld",&n,&m);
	fo(i,1,n)
	{
		ll a,b;
		scanf("%lld%lld",&a,&b);
		pp[a]+=b;	
	}
	n=0;
	fo(i,1,1000010)
	if(pp[i])
		a[++n].fi=i,a[n].se=pp[i];
	a[++n].fi=1000100,a[n].se=0;
	fo(i,1,n) 
	{
		t[i]=a[i].fi,r[i]=a[i].se;
		R[i]=R[i-1]+r[i];
		q[i]=1ll*r[i]*t[i]+q[i-1];
	}
	f[0]=0;
	ll ans=0;
	s[hd=tl=1][0]=s[1][1]=0;
	fo(i,1,n)
	{
		while(hd+1<=tl &&s[hd][0]+s[hd][1]*R[i-1] > s[hd+1][0]+s[hd+1][1]*R[i-1]) ++hd;
		f[i]=(q[i-1]+m)+s[hd][0]+s[hd][1]*R[i-1];
		ll k=(-t[i]),b=f[i]+t[i]*R[i]-q[i];
		while(tl-1>=hd&&k==s[tl][1]&&b<=s[tl][0]) --tl;
		while((tl-1>=hd)&&cr(k,b,s[tl][1],s[tl][0])<=cr(s[tl-1][1],s[tl-1][0],s[tl][1],s[tl][0])) --tl;
		s[++tl][1]=k,s[tl][0]=b;
	}
	printf("%lld",f[n]-m);
}











