#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=66;
ll a,b;
ll g[N],f[N];
ll q[N];
ll calc(ll n)
{
	memset(f,0,sizeof f);memset(g,0,sizeof g);
	ll ans=0,m=0;
	fo(i,1,n)
	{

		g[i]=floor(pow(n,(double)1/(double)i))-1;
		if(g[i]<=0)
		{
			g[i]=0;m=i-1;
			break;
		}
	}
	fo(i,1,n)  
	{
		f[i]=g[i];
		fo(j,2,m/i) 
		{
			f[i]-=g[j*i]*q[j];
		}
 		if(f[i]<=0)
		{
			m=i-1;
			break;
		}
	}
	fo(i,1,m) 
		ans+=f[i]*i;
	return ans;
}
int fj(ll x)
{
	int tot=0;
	fo(i,2,x)
		while(x%i==0) x/=i,++tot;
	return tot;
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	q[1]=1;
	fo(i,2,60)
	{
		if(fj(i)&1) q[i]=1;else q[i]=-1;
	}
	for(;scanf("%lld%lld",&a,&b);)
	{
		if(a+b==0)return 0;
		printf("%lld\n",calc(b)-calc(a-1));
	}
	return 0;
}








