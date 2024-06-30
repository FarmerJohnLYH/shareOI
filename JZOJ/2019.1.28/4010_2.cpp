#pragma GCC optimize(2)
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int P=110,M=20003000;
int le,ri,p;
int a[M],m,n;
int f[M],g[M];
void dfs(int v,int s)
{
	fo(i,s,n)
	if(1ll*v*a[i]<=ri)
	{
		dfs(v*a[i],i);
		a[++m]=v*a[i];
	}
}
void init(int p)
{
	a[m=1]=1;
	fo(i,2,min(97,ri))
	{
		int flag=1;
		fo(j,2,i-1)
			if(i%j==0)
			{
				flag=0;
				break;
			}
		if(flag) a[++m]=i;
	}
	n=m;
	fo(i,2,n) dfs(a[i],i);
	sort(a+1,a+1+m);
}
void solve()
{
	memset(f,127,sizeof f);
	f[1]=0;
	fo(l,2,p)
	{
		int j=1;
		fo(i,1,m)
		{
			while(j<=m&&1ll*a[i]*l!=a[j]) ++j;
			if(j>m)break;
			if(f[j]>f[i]+1) 
			{
				f[j]=f[i]+1;
				if(l+f[j]<=p)g[j]=1;
			}
		}
	}
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d%d",&le,&ri,&p);
	init(p);
	solve();
	int ans=0;
	fo(i,1,m)
	if(a[i]>=le&&g[i]) ++ans;
	printf("%d\n",ans);
	return 0;
}











