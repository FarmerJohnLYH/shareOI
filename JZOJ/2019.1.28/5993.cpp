#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll N=10001000,mo=998244353;
ll n,m;
ll all,ans;
void dfs(ll x,ll y,ll t)
{
	if(t==0)
	{
		ans=ans+y;
		return ;
	}
	dfs(x+1,max(x+1,y),t-1);
	dfs(x-1,y,t-1);
}
ll qsm(ll x,ll y)
{
	ll rt=1;
	while(y)
	{
		if(y&1) rt=rt*x%mo;
		y/=2,x=x*x%mo;
	}
	return rt;
}
int main()
{
	freopen("D:/LiuYuanHao/b.in","r",stdin);
	freopen("D:/LiuYuanHao/b.ans","w",stdout);
	fo(nn,2,20)
	{
		// scanf("%lld%lld",&n,&m);
		n=nn;ans=0;
		all=qsm(1ll<<n,mo-2);
		dfs(0,0,n);
		// printf("%d:%lld\n",nn,ans*2+(1ll<<n));
		printf("%lld,",ans*2+(1ll<<n));	
	}
	return 0;
}








