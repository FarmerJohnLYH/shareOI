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
const int N=20200,M=20200,K=220,Q=50500;
int n,m,k,q;
struct edge{
	int to,nex,v;
}e[M];
int dis[K][N];
int c[K],a[Q],b[Q],p[N];
int las[N];
int tot;
void link(int x,int y,int v)
{
	e[++tot].to=y,e[tot].nex=las[x],e[tot].v=v;
	las[x]=tot;
}
int d[N*10];
int vis[N];
void spfa(int x,int col)
{
	memset(vis,0,sizeof vis);
	dis[col][x]=0;
	int hd=0,tl=1;
	d[1]=x,vis[x]=1;
	while(hd++<tl)
	{
		int now=d[hd];
		for (int tmp=las[now];tmp;tmp=e[tmp].nex)
		{
			int to=e[tmp].to,ds=e[tmp].v+dis[col][now];
			if(ds<dis[col][to])
			{
				if(ds<0)
				{
					printf(" ");
				}
				dis[col][to]=ds;
				if(!vis[to])
				{
					d[++tl]=to;
					vis[to]=1;
				}
			}
		}
		vis[now]=0;
	}
}
int main()
{
	freopen("D:/LiuYuanHao/a1.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	memset(dis,127,sizeof dis);
	scanf("%d%d%d%d",&n,&m,&k,&q);
	fo(i,1,m)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		link(x,y,z);
	}
	fo(i,1,k)
	{
		scanf("%d",&c[i]);
		p[c[i]]=i;
	} 
	fo(i,1,k) 
	{
	if(i==10)		
	{
		printf("");
	}
	spfa(c[i],i);
}
	int ans=0,cnt=0;
	fo(i,1,q)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(p[x]) 
		{
			if(dis[p[x]][y]<oo)
			{
				ans+=dis[p[x]][y];
				cnt++;
			} 
			continue;
		}
		int mn=oo;
		for (int tmp=las[x];tmp;tmp=e[tmp].nex)
		{
			int to=e[tmp].to;
			if(p[to])
			if(dis[p[to]][y]<oo)
				mn=min(mn,e[tmp].v+dis[p[to]][y]);
		}
		if(mn<oo)
		{
			ans+=mn;
			cnt++;
		}
	}
	printf("%d\n%d\n",cnt,ans);
	return 0;
}
