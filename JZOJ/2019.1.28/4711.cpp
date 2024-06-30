#pragma GCC optimize(2)
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
ll er(ll x)
{
	return(1<<(x));
}
const ll N=100100,MX=(1<<21)-1;
ll n,q;
ll a[N];
ll opt,x,y;
ll t[22][MX];
void add(ll pos,ll x,ll v)
{
	++x;
	while(x<=MX)
	{
		t[pos][x]+=v;
		x+=lowbit(x);
	}
}
ll query(ll pos,ll x)
{
	++x;
	x=min(x,MX);
	ll rt=0;
	while(x>0)
	{
		rt+=t[pos][x];
		x-=lowbit(x);
	}	
	return rt;
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%lld%d",&n,&q);
	fo(i,1,n)
	{
		scanf("%lld",&a[i]);
		fo(l,0,20) add(l,a[i]&(er(l+1)-1),1);
	}
	while(q--)
	{
		scanf("%lld%lld%lld",&opt,&x,&y);
		if(opt==1)
		{
			fo(l,0,20) add(l,a[x]&(er(l+1)-1),-1),add(l,y&(er(l+1)-1),1);
			a[x]=y;
		}
		else
		if(opt==2)
		{
			ll ans=0;
			fo(l,0,20)
			if(y&er(l))
			{
				ll tmp=0;
				tmp+=(query(l,er(l+1)-1-(x&(er(l+1)-1)))-query(l,er(l)-1-(x&(er(l+1)-1))));
				tmp+=query(l,er(l+1)+er(l+1)-1-(x&(er(l+1)-1)))-query(l,er(l+1)+er(l)-1-(x&(er(l+1)-1)));
				ans+=tmp*er(l);
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
