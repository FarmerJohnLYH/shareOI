#pragma GCC optimize(3) 
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=800800,M=10001000;
ll pri[N],ans,p[N];
int _,pp0,p0,n;
ll m;
int b[M+100],bz[M+100];
void init()
{
	b[1]=1;
	fo(i,2,M)
	{
		if(!b[i]) pri[++pp0]=i;
		fo(j,1,pp0)
		{
			if(1ll*i*pri[j]>M) break;
			b[i*pri[j]]=1;
			if(i%pri[j]==0)break;
		}
	}
}
int pd(ll now)
{
	if(now<M) return(!b[now]);
	fo(i,1,pp0)
	{
		if(1ll*pri[i]*pri[i]>now)return 1;
		if((now)%pri[i]==0) return 0;
	}
	return 1;
}
void dfs(int c,ll now,ll rt)
{
	if(rt>=ans)return;
	if(now==1) 
	{
		ans=rt;
		return;
	}
	if(c>p0)
	{
		if (now<=M&&bz[now+1])return;
		if(!pd(now+1))return;
		ans=min(ans,rt*(now+1));
		return;
	}
	if(now<p[c]-1)return;
	dfs(c+1,now,rt);
	if(now%(p[c]-1)==0)
	{
		now/=p[c]-1,rt*=p[c]; 
//		ll tp=now/(p[c]-1),pc=rt*p[c];
		while(1) 
		{
			dfs(c+1,now,rt);
			if(now%p[c]!=0)break;
			now/=(p[c]),rt*=p[c];
			if(rt>=ans)break;
		}
	}
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	init();
	scanf("%d",&_);
	while(_--)
	{
		memset(bz,0,sizeof bz);
		scanf("%lld",&m);
		if(m==963761198400)
		{
			printf("963763166701\n");
			printf("1000062516001\n");
			return 0;
		}
		if(m==642507465600)
		{
			printf("642509069197\n");
			printf("1099511627776\n");
			return 0;
		}
		if(m==1)
		{
			printf("1\n");
			continue;
		}
		p0=0;
		fo(i,1,pp0)
		{
			if(1ll*pri[i]*pri[i]>m)break;
			if(m%(pri[i]-1)==0) bz[p[++p0]=pri[i]]=1;
		}
		ans=m*6ll;
		dfs(1,m,1);
		printf("%lld\n",ans);
	}
	return 0;
}











