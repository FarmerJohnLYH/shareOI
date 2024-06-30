#include <cmath>
#include <ctime>
#include <queue>
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
typedef pair<ll,ll> PI;
ll abs(ll x) {return(((x)>=0)?(x):(-(x)));}
ll max(ll x,ll y) {return(((x)>(y))?(x):(y));}
ll min(ll x,ll y) {return(((x)<(y))?(x):(y));}
ll lowbit(ll x) {return((x)&(-x));}
const ll N=110,M=100100,Mo=998244353;
ll m,n,a,b,p,q;
ll f[M][N];
ll qsm(ll a,ll b)
{
	ll x=1;
	a%=Mo,b%=(Mo-1);
	while(b)
	{
		x=((b&1))?((x*(a))%Mo):(x);
		b>>=1,a=(a*a)%Mo;
	}
	return x;
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	//freopen("table.in","r",stdin);
	//freopen("table.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld%lld",&m,&n,&a,&b,&p,&q);
	int mm=0,nn=1; 
	fo(i,1,n) scanf("%lld",&f[p][i]);
	fo(i,1,n)
	{
		fd(j,p-1,1)
			f[j][i]=(f[j+1][i]+1ll*(Mo-f[j][i-1])*b)%Mo*qsm(a,Mo-2)%Mo;
	}
	fo(j,p+1,m) fo(i,1,n)
		f[j][i]=(f[j-1][i]*a+f[j-1][i-1]*b)%Mo;
	fo(i,1,q)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",f[x][y]);
	}
	return 0;
}











