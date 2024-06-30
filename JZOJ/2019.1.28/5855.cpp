#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PI;
const ll N=1000000000000000;
ll T;
ll a,b,c;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1,y=0;
		return(a);
	}
	ll g=exgcd(b,a%b,x,y);
	ll t=x;
	x=y,y=t-(a/b)*y;
	return g;
}
ll mul(ll x,ll y,ll MOD){
    x=x%MOD,y=y%MOD;
    return ((x*y-(ll)(((long double)x*y+0.5)/MOD)*MOD)%MOD+MOD)%MOD;
}
PI operator *(PI a,ll b)
{
	ll p=(double)a.second/(double)N*b;a.second=mul(a.second,b,N);
	a.first=a.first*b+p;
	return(a);
}
PI operator -(PI a,ll b)
{
	a.second-=b;if(a.second<=-N) a.second+=N,--a.first;
	return(a);
}
PI operator -(PI a,PI b)
{
	a.second-=b.second,a.first-=b.first;
	if(a.second<=-N) a.second+=N,--a.first;
	return(a);
}
PI operator +(PI a,ll b)
{
	a.second+=b;if(a.second>N) a.first+=a.second/N,a.second%=N;
	return(a);
}
PI operator +(PI a,PI b)
{
	a.second+=b.second,a.first+=b.first;
	if(a.second>N) a.first+=a.second/N,a.second%=N;
	return(a);
}
PI operator /(PI a,ll b)
{
	double p=a.first*N+a.second;
	p=p/b;ll g=p,m=p/N;
	if(p>=N) g=(p-m*N);
	a.first=m,a.second=g; 
	return(a);
}
bool operator <(PI a,ll b)
{
	return(a.first>0)?0:(a.second<b);
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		ll x=0,y=0;
		ll g=exgcd(a,b,x,y);
		if(c%g!=0) printf("0\n");
		else
		{
			PI X,Y;X.second=x,Y.second=y;
			X.first=Y.first=0;
			a/=g,b/=g;
			ll d=c/g;
			X=X*d;
			Y=Y*d;
			PI p=X/b;
			PI q=p*b;
			X=X-p*b;Y=Y+p*a;
			while(X<0) X=X+b,Y=Y-a;
			while(!(X<b)) X=X-b,Y=Y+a;
			PI ans=Y/a;
			if(X.second>=0&&X.first>=0&&Y.second>=0&&Y.first>=0)ans.second++;
			printf("%lld\n",ans.second+ans.first*N);
		}
	}
	return 0;
}











