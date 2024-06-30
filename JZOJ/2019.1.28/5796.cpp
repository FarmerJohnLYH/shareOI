#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int M=22;
int n,m;
ll ans,k[M];
ll gcd(ll x,ll y)
{
	return(y==0)?(x):(gcd(y,x%y));
}
ll lcm(ll x,ll y)
{
	return(x*y/gcd(x,y));
}
void exgcd(int a,int b,ll &x,ll &y)
{
	if(b==0) 
	{
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	ll t=x;x=y;
	y=t-(a/b)*y;
}
void dfs(int x,ll a,ll b,int fg)
{
	if(a>n||b>n)return;
	if(x>m)
	{
		if(a==1||b==1)return;
		if(gcd(a,b)>1)return;
		ll p=0,q=0;
		exgcd(a,b,p,q);
		p=((p%b)+b*2)%b;
		ans=ans+fg*(n/a-p+b)/b;
		return;
	}
	dfs(x+1,lcm(a,k[x]),b,-fg);
	dfs(x+1,a,lcm(b,k[x]),-fg);
	dfs(x+1,a,b,fg);
}
int main()
{
	 freopen("sazetak.in","r",stdin);
	 freopen("sazetak.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%d%d",&n,&m);
	fo(i,1,m) scanf("%lld",&k[i]);
	k[++m]=n;
	dfs(1,1,1,1);
	printf("%lld\n",ans);
	return 0;
}











