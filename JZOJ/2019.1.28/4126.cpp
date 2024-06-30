#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
#define fd(i,x,y) for (ll i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const ll mo=9699667,N=4000400,q1=9473;
ll n,m,d,s0,t0,sum;
char s[N],t[N];
ll ct[mo+10],qm[N],ny[N];
ll h[N];
ll ans=0;
ll qsm(ll x,ll y)
{
	ll rt=1;
	fo(i,0,30)
	{
		if(y<(1<<i))return(rt);
		if(y&(1<<i)) rt=1ll*rt*x%mo;
		x=1ll*x*x%mo;
	}
	return(rt);
}
ll hs(char *x) /*Len=m*/
{
	ll rt=0;
	fo(i,1,m) rt=(1ll*rt*q1+(x[i]-'a'+1))%mo; 
	return rt;
}
ll p[N];
ll get(ll x,ll x0,ll y,ll y0)
{
	ll rt=0;
	fo(i,1,y0) rt=(1ll*rt*q1+s[y+i]-'a'+1)%mo;
	fo(i,1,x0) rt=(1ll*rt*q1+s[x+i]-'a'+1)%mo;
	return rt;
}
void kmp(char *s/*len=d*/,char *t/*n-d*/,ll pl)
{
	ll ls=d,lt=n-d;
	ll j=0;p[1]=0;
	fo(i,2,lt)
	{
		while(t[i]!=t[j+1]&&j)j=p[j];
		if(t[i]==t[j+1])++j;
		p[i]=j;
	}
	j=0;
	fo(i,1,ls)
	{
		while(s[i]!=t[j+1]&&j)j=p[j];
		if(s[i]==t[j+1])++j;
		if(j==lt)
		{
			ll tp=get(pl,i-lt,pl+i+lt-1-1,m-(i-lt));
			ans+=ct[tp];
		}
	}
}
int main()
{
	freopen("D:/LiuYuanHao/b.in","r",stdin);
	scanf("%lld%lld%lld%lld",&s0,&t0,&n,&m);
	fo(i,1,s0)scanf("%s",s+1+(i-1)*n);
	fo(i,1,t0)scanf("%s",t+1+(i-1)*m);
	if(n<m)swap(n,m),swap(s,t),swap(s0,t0);
	fo(i,1,n*s0) h[i]=(1ll*h[i+1]*q1+s[i]-'a'+1)%mo;
	d=(n+m)>>1;
	fo(i,1,t0) ++ct[hs(t+(i-1)*m)];
	fo(i,1,s0) kmp(s+(i-1)*n,s+(i-1)*n+d,(i-1)*n);
	printf("%lld\n",ans);
	return 0;
}










