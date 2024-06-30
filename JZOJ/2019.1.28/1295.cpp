#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=1010,M=50050;
int n,ml,md;
int to[M],nex[M],v[M],las[N];
int dis[N],vis[N],ti[N];
int d[M*10],tot;
void link(int x,int y,int c)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot,v[tot]=c;
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	memset(dis,127,sizeof dis);
	scanf("%d%d%d",&n,&ml,&md);
	fo(i,2,n) link(i,i-1,0);
	fo(i,1,ml)
	{
		int a,b,d;
		scanf("%d%d%d",&a,&b,&d);
		link(a,b,d);
	}
	fo(i,1,md)
	{
		int a,b,d;
		scanf("%d%d%d",&a,&b,&d);
		link(b,a,-d);
	}
	int hd=0,tl=1;
	d[1]=1;dis[1]=0;
	vis[1]=1;
	while(hd++<tl)
	{
		int x=d[hd];
		for(int tp=las[x];tp;tp=tp[nex])
		if(v[tp]+dis[x]<dis[tp[to]])
		{
			dis[tp[to]]=v[tp]+dis[x];
			if(!vis[tp[to]])
			{
				if(++ti[tp[to]]>n)
				{
					printf("-1\n");
					return 0;
				}
				tp[to][vis]=1;
				d[++tl]=to[tp];
			}
		}
		vis[x]=0;
	}
	if(dis[n]>=oo)printf("-2\n");
	else printf("%d\n",dis[n]);
	return 0;
}











