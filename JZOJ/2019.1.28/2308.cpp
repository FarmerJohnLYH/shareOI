#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (int pq = (y),i = (x);i <= pq;++ i)
#define fd(i,x,y) for (int pq = (y),i = (x);i >= pq;-- i)
#define oo 2139062143
using namespace std;
typedef double db;
typedef long long ll;
int lowbit(int x) {return((x)&(-x));}
int min(int x,int y){return (x>y)?(y):(x);}
int max(int x,int y){return (x>y)?(x):(y);}
const int N=1010;
int n,m;
int to[N][N];
int p[N];
bool bz[N];
int ans[N],c[N];
int b;
bool dfs(int x)
{
	fo(i,1,to[x][0])
	{
		int t=to[x][i];
		if(t==b) continue;
		if(!bz[t])
		{
			bz[t]=1;
			if(p[t]==0||(dfs(p[t])))
			{
				p[t]=x;
				return(1);
			}
		}
	}
	return(0);
}
int main()
{
	freopen("D:/LiuYuanHao/a2.in","r",stdin);
//	freopen("D:/LiuYuanHao/a2.out","w",stdout);
	scanf("%d%d",&n,&m);
	fo(i,1,n)
	{
		scanf("%d",&to[i][0]);
		fo(l,1,to[i][0]) scanf("%d",&to[i][l]);
	}
	b=0;
	fo(i,1,n)
	{
		memset(bz,0,sizeof bz);
		dfs(i);
	}
	fo(i,1,m) c[i]=p[i];
	for (b=1;b<=m;++b)
	{
		memset(bz,0,sizeof bz);
//		fo(i,1,m) p[i]=c[i];
		if(p[b])
		{
			if(!dfs(p[b]))
				ans[++ans[0]]=b; 
			else
				fo(i,1,m) p[i]=c[i];
		}
	}
	fo(i,1,ans[0])
		printf("%d\n",ans[i]);
	return 0;
}

