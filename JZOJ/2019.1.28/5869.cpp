#pragma GCC optimize(2) 
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=100100;
int n,m,k;
int a[N],to[N*2],nex[N*2],las[N],tot;
void link(int x,int y)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
}
int dis[N],ans[N];
int d[N*44],hd,tl;
int vis[N];
void spfa(int st)
{
	memset(vis,0,sizeof vis);
	hd=0,tl=1;
	vis[st]=1;d[1]=st;
	while(hd++<tl)
	{
		int x=d[hd];
		for(int tp=las[x];tp;tp=tp[nex])
		if(tp[to][dis]>dis[x]+1)
		{
			dis[tp[to]]=dis[x]+1;
			if(!vis[tp[to]])
				vis[d[++tl]=tp[to]]=1;
		}
		vis[x]=0;
	}
}
int main()
{
	freopen("oasis.in","r",stdin);
	freopen("oasis.out","w",stdout);
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	// freopen("D:/LiuYuanHao/a.out","w",stdout);
	// int pp=clock();
	scanf("%d%d%d",&n,&m,&k);
	fo(i,1,k) scanf("%d",&a[i]);
	fo(i,1,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		link(x,y),link(y,x);
	}
	memset(dis,127,sizeof dis);
	dis[a[1]]=0;
	spfa(a[1]);fo(i,1,n) ans[i]=max(ans[i],dis[i]);
	fo(l,2,k)
	{
		int p=dis[a[l]];
		fo(i,1,n) dis[i]+=p;
		dis[a[l]]=0;
		spfa(a[l]);
		fo(i,1,n) ans[i]=max(ans[i],dis[i]);
	}
	fo(i,1,n) printf("%d ",ans[i]);
	// printf("\n%d\n",clock()-pp);
	return 0;
}











