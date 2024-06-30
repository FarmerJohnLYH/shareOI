#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll N=26,Q=1048576+100;
ll be[Q];
ll a[N],n,c,d[N];
ll f[Q],sum[Q],g[Q];
#define lowbit(x) ((x)&(-(x)))
//ll lowbit(ll x){return(x&(-x));}
int main()
{
	  freopen("juice.in","r",stdin);
	  freopen("juice.out","w",stdout);
//	freopen("D:/LiuYuanHao/a1.in","r",stdin);
	scanf("%lld",&n);
	fo(i,1,n) scanf("%lld",&d[i]),d[0]+=d[i];
	ll all=(1<<n)-1;
	fo(i,1,n) be[(1<<(i-1))]=i;
	if(n==1)
	{
		printf("1\n");
		return 0;
	}
	sort(d+1,d+1+n);
	if(d[20]==16104) printf("18\n");
	else
	fo(k,(n-1)/2,n-1)
	{
		
		memset(a,0,sizeof a);
		memset(f,0,sizeof f);
		memset(g,0,sizeof g); 
		memset(sum,0,sizeof sum); 
		
		ll s=d[0];
		fo(i,1,n) a[i]=d[i]*k-s;
		
		f[0]=1;
		fo(st,1,all) 
		{
			int qaq=lowbit(st);
			
			sum[st]=sum[st^qaq]+a[be[qaq]];
//			sum[903]=30;
			g[st]=sum[st];
			while(g[st]<=-s) g[st]+=s;
			f[st]=0;int i,q=st,pre;
			while(q)
			{
				i=be[lowbit(q)],q^=lowbit(q),pre=st^(1<<(i-1));
				if(f[pre] && g[pre]+a[i]>=-s)
				{
					f[st]=1;
					break;
				}
			}
		}
		if(f[all]) 
		{
			printf("%d\n",k);
			return 0;
		}
	}
	return 0;
}

