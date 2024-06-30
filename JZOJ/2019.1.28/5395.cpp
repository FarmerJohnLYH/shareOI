#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (ll pq = (y),i = (x);i <= pq;++ i)
#define fd(i,x,y) for (ll pq = (y),i = (x);i >= pq;-- i)
#define oo 2139062143
using namespace std;
typedef double db;
typedef long long ll;
ll lowbit(ll x) {return((x)&(-x));}
ll min(ll x,ll y){return (x>y)?(y):(x);}
ll max(ll x,ll y){return (x>y)?(x):(y);}
const ll N = 100010000,K = 1001000;
const ll Mo = 998244353;
ll l,r,k;
ll qsm(ll x,ll y)
{
	ll rt=1,p=x;
	while (y)
	{
		if (y&1) rt=(1ll*rt*p)%Mo;
		p=(1ll*p*p)%Mo;
		y>>=1;
	}
	return(rt);
}
ll ans[K*2];
ll pre[K*2],suf[K*2],jc[K*2],f[K*2];
ll solve(ll n)
{
	if(n==0)return(0);
	if(n<=K)return((ans[n]-1+ans[2]-ans[1]+Mo)%Mo);
	ll rt = 0;
	pre[0] = 1;
	fo(i,1,k+2) pre[i]=1ll*pre[i-1]*(n-i)%Mo;
	suf[k+3]=1;
	fd(i,k+2,1) suf[i]=1ll*suf[i+1]*(n-i)%Mo;
	ll l=k+1,r=0,flag=((k+1)&1)?(-1):(1);
	fo(i,1,k+2)
	{
		ll s=1ll*pre[i-1]*suf[i+1]%Mo,m=1ll*(flag*jc[l]+Mo)*jc[r]%Mo;
		rt=(1ll*ans[i]*s%Mo*qsm(m,Mo-2)%Mo+rt)%Mo;
		--l,++r;
		flag*=-1;
	}
	rt=((1ll*rt+ans[2]-ans[1]+Mo)%Mo-1+Mo)%Mo;
	return rt;
}
int main()
{
	// freopen("count.in","r",stdin);
	// freopen("count.out","w",stdout);
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	// freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%d%d%d", &l, &r, &k);
	jc[0] = 1;
	fo(i,1,K) jc[i] = (1ll*jc[i - 1]*i)%Mo;
	ans[1]=1;
	fo(i,2,K)
		ans[i]=(ans[i-1]+qsm(i,k))%Mo;
	printf("%d",(solve(r)-solve(l-1)+Mo)%Mo);
}
