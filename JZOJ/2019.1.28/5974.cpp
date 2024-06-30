#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=300300,M=10001000;
ll n;
int mi[M],p[N],bz[M],p0;
void init(int n)
{
	p0=0;bz[1]=1;mi[1]=1;
	fo(i,2,n)
	{
		if(!bz[i]) p[++p0]=i,mi[i]=1;
		fo(j,1,p0)
		{
			if(1ll*i*p[j]>n) break; 
			bz[i*p[j]]=1;
			if(i%p[j]==0) break;
			else mi[i*p[j]]=-mi[i];
		}
	}
}
int main()
{
//	freopen("calc.in","r",stdin);
//	freopen("calc.out","w",stdout);
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	init(1e7);
	scanf("%lld",&n);
	int p=sqrt(n); 
	ll ans=0;
	fo(d,1,p)
	{
		ll sum=0;
		fo(a,1,n/d/d)
		{
			ll all=n/a/d/d;
			ll bs=a+1,bt=bs;
			while(bs<2*a)
			{
				ll k=all/bs;
				if(!k) break;
				bt=min(all/k,2ll*a);
				sum+=(bt+1-bs)*k;
				bs=bt+1;
			}
		}
		ans+=sum*mi[d];
	}
	printf("%lld\n",ans);
	return 0;
}








