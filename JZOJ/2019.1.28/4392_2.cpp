#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll N=100100;
ll s[N];
ll n,m,d;
ll ans,sum,tp,ri,le;
ll p[]={2,3,5,7,11,13,17,19,23,29,31};
ll gcd(ll x,ll y)
{
	return(y==0)?x:(gcd(y,x%y));
}
ll c[N];
void dfs(ll d,ll x,ll lcm,ll op){
	if(x>d)
	{
		if (lcm!=1)sum+=(ll)op*(ri/lcm-le/lcm);
		return;
	}
	dfs(d,x+1,lcm,op);
	if(c[x])dfs(d,x+1,lcm*x/gcd(x,lcm),-op);
}
void solve(ll d){
	sum=m;
	memset(c,0,sizeof c);
	for(ll i=0;p[i]<=d;++i)p[i][c]=1;
	fo(i,2,d)
	{
		ri=i*m,le=(i-1)*m;
		dfs(d,i,1,-1);
		c[i*2]=c[i*3]=c[i*5]=1;
	}
	s[d]=m*d-sum;
}
ll check(ll x)
{
	ll p=-1;
	fo(i,2,sqrt(x))
	if(x%i==0)
	{
		ll cnt=0;
		while(x%i==0) ++cnt,x/=i;
		if(p==-1) p=cnt;
		else p=gcd(p,cnt);
	}
	if(x!=1) p=1;
	return p==1;
}
int main()
{
	// freopen("D:/LiuYuanHao/b.in","r",stdin);
	scanf("%lld%lld",&n,&m);
	ans=(n-1)*m+1;
	d=sqrt(n);
	fo(i,2,d)
	if(check(i))
	{
		ll cnt=1;tp=i;
		while(tp*i<=n) tp=tp*i,++cnt;
		if(!s[cnt])solve(cnt);
		ans-=s[cnt];
	}
	printf("%lld",ans);
	return 0;
}











