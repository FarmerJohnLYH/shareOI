#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
#define fd(i,x,y) for (ll i=(x);i>=(y);--i)
#define add(x,y) (x+=(y))%=mo
using namespace std;
typedef long long ll;
const ll N=1001000,mo=1e9+7;
ll ans,m,ct[4];
ll jc[N],ny[N];
ll qsm(ll x,ll y)
{
	ll rt=1;
	fo(i,0,30)
	{
		if((1<<i)&y) rt=1ll*rt*x%mo;
		x=x*x%mo;
	}
	return rt;
}
ll pw[N];
ll C(ll a,ll b)
{
	return(a<b)?0:(1ll*jc[a]*ny[b]%mo*ny[a-b]%mo);
}
void init()
{
	ll a,b,c;
	scanf("%lld%lld%lld%lld",&m,&a,&b,&c);
	if(a>m||b>m||c>m){printf("0\n");return;}
	ct[1]=m-a,ct[2]=m-b,ct[3]=m-c;
	sort(ct+1,ct+1+3);
	jc[0]=1;fo(i,1,m) jc[i]=1ll*jc[i-1]*i%mo;
	ny[m]=qsm(jc[m],mo-2);
	fd(i,m-1,0)ny[i]=1ll*ny[i+1]*(i+1)%mo;
	pw[0]=1;fo(i,1,m)pw[i]=(pw[i-1]<<1)%mo;
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	init();
	fo(fr,1,3) fo(i,ct[fr]-1,ct[fr])
	{
		ll c[4],c0=0;
		fo(j,1,3)if(j!=fr)c[++c0]=ct[j];
		fo(j,0,i)
		if(!(1&((i-j)^(c[2]-c[1]))))
		if(((i-j-(c[2]-c[1]))>>1)>=0)
		{
			ll s=(i-j-(c[2]-c[1]))>>1;
			add(ans,C(i,j)*C(i-j,s)%mo*pw[j]%mo*C((c[1]-s-j)+i-1,i-1)%mo);
		}
	}
	printf("%lld\n",ans*2ll%mo);
}
