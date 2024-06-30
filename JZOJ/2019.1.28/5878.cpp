#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
#define fd(i,x,y) for (ll i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const ll mo=1e9+7,N=10001000;
ll n,m;
ll jc[N],ny[N]; 
ll qsm(ll x,ll y)
{
	ll rt=1;
	fo(i,0,30)
	{
		if((1<<i)&y) rt=rt*x%mo;
		x=x*x%mo;
	}
	return rt;
}
int main()
{
//	 freopen("D:/LiuYuanHao/","r",stdin);
	m=1;jc[0]=1;fo(i,1,1e7) jc[i]=1ll*jc[i-1]*i%mo;
	ny[10000000]=qsm(jc[10000000],mo-2);fd(i,1e7-1,0) ny[i]=1ll*ny[i+1]*(i+1)%mo;
	printf("%lld\n",jc[334]*ny[166]%mo); 
	return 0;
}








