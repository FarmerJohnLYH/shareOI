#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef __int128 ll;
const ll N=100000000000000;
// ll T;
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
char wp[1000];int w0;
void write(__int128 m)
{
	w0=0;
	while(m) 
	{
		wp[++w0]=m%10;
		m/=10;	
	}
	if(w0==0)wp[w0=1]=0;
	fd(i,w0,1)
		putchar(wp[i]+'0');
	printf("\n");
}
int main()
{
	// freopen("cake.in","r",stdin);
	// freopen("cake.out","w",stdout);
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("D:/LiuYuanHao/a.out","w",stdout
		);
	long long T;
	scanf("%lld",&T);
	while(T--)
	{
		long long A,B,C;
		scanf("%lld%lld%lld",&A,&B,&C);
		a=A,b=B,c=C;
		ll x=0,y=0;
		ll g=exgcd(a,b,x,y);
		if(c%g!=0) printf("0\n");
		else
		{
			a/=g,b/=g;
			ll d=c/g;
			x=x*d,y=y*d;
			ll p=x/b;x=x-p*b;y=y+a*p;
			while(x<-b) x=x+b,y=y-a;
			while(x>=b) x=x-b,y=y+a;
			ll ans=y/a;
			if(x>=0&&y>=0)++ans;
			write(ans);
//			printf("%lld\n",ans);
		}
	}
	return 0;
}
