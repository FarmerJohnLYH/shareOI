#pragma GCC optimize(2)
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for(ll i=(x);i<=(y);++i)
#define fd(i,x,y) for(ll i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const ll N=10001000,ct=20,all=(1ll<<ct);
ll a,p,q,k;
ll b0,l,m,cc;
ll v[66],va[N];
ll ans,pa[all+100],pb[all+100];
ll calc(ll y)
{
	// printf("%lld %lld\n",y%all,y/all);
	ll rt=pa[y%all]*pb[y/all]%p;
	return rt;
}
ll b[N];
int main()
{
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	// freopen("D:/LiuYuanHao/a.out","w",stdout);
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	scanf("%lld%lld%lld%lld",&a,&p,&q,&k);
	scanf("%lld%lld%lld%lld",&b0,&l,&m,&cc);
	b[0]=b0;
	fo(i,1,q) 
	{
		b[i]=(b[i-1]*m%l+cc)%l;
		// printf("%lld\n",b[i]);
		// calc(i);
	}
	pa[0]=1;
	fo(i,1,all+1) pa[i]=1ll*pa[i-1]*a%p;
	pb[0]=1;
	pb[1]=pa[all];
	fo(i,2,all+1) pb[i]=pb[i-1]*pb[1]%p;
	fo(i,1,q)va[i]=calc(b[i]);
	ll tp=q/k;   
	fo(i,1,tp)
	{
		ll j=1,s=(i-1)*k;
		for(;j+3<=k;j+=4)
		{
			ans^=va[s+j];
			ans^=va[s+j+1];
			ans^=va[s+j+2];
			ans^=va[s+j+3];
		}
		while(j<=k) ans^=va[s+j],++j;
		printf("%lld\n",ans);
	}
	return 0;
}


