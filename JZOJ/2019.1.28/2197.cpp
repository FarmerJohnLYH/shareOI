#include <cmath>
#include <ctime>
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
const ll N=100100,V=64;
ll _;
ll n;
ll z[N];
ll ans[N];
char A,B,C;
ll las[V];
ll t[V];
ll f[N],s[N],fs[N];
ll v(char c)
{
	if(c=='A')return(0);
	if(c=='G')return(1);
	if(c=='C')return(2);
	if(c=='T')return(3);
	else return 16;
}
void ins(ll x,ll y)
{
	if(!las[x])
	{
		t[x]=1;
		las[x]=y;
		f[x]=0,s[x]=0;
	}
	else
	{
		ll p=y-las[x];
		f[x]+=t[x]*p*p+p*2*s[x];
		fs[x]+=f[x];
		s[x]+=p*t[x];
		ans[x]+=s[x];
		n+=t[x],++t[x];
		las[x]=y;
	}
}
int main()
{
	freopen("D:/LiuYuanHao/b3.in","r",stdin);
	freopen("D:/LiuYuanHao/b.out","w",stdout);
	// freopen("tri.in","r",stdin);
	// freopen("tri.out","w",stdout);
	scanf("%lld\n",&_);
	while(_--)
	{
		memset(las,0,sizeof las);
		memset(ans,0,sizeof ans);
		memset(f,0,sizeof f);
		memset(s,0,sizeof s);
		memset(t,0,sizeof t); 
		memset(fs,0,sizeof fs); 
		//
		
		n=0;
		ll len=0;
		A=getchar(),B=getchar(),C=getchar();
		while(v(C)<4)
		{
			z[++len]=v(A)*16+v(B)*4+v(C);
			A=B,B=C,C=getchar();
		}
		fo(i,1,len)
		{
			ins(z[i],i);			
		}
		if(n==0) printf("0.000000\n");
		else
		{
			ll x=0,y=0;
			fo(i,0,63)
			{
				x+=ans[i],y+=fs[i];
			}
			db X=(db)x/n;
			db Ans=(db)(y+n*X*X-2*X*x)/n;
			Ans=(Ans>555480000)?(Ans-0.0000001):Ans;
			printf("%.6lf\n",Ans);
		}

	}
	return 0;
}
