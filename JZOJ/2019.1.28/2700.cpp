#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define ll long long 
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
int n,m;
int p[100100];
int d(int x)
{
	if(x<10) return x;
	else
	{
		int v=0;
		while(x) v+=x%10,x/=10;
		return(d(v));
	}
}
ll solve(ll x)
{
	ll ans=x/22680;ans=ans*p[22680];
	x%=22680;
	ans+=p[x];
	return ans;
}
int _;
int ck(int x)
{
	fo(i,1,9)
	if(x%i==0)
		if(d(x/i)==i) return 1;
	return 0;
}
int main()
{
	// freopen("D:/LiuYuanHao/a.out","w",stdout);
	fo(i,1,22680) p[i]=ck(i)+p[i-1];
	scanf("%d",&_);
	while(_--)
	{
		ll l,r;scanf("%lld%lld",&l,&r);
		printf("%lld\n",solve(r)-solve(l-1));
	}
	return 0;
}








