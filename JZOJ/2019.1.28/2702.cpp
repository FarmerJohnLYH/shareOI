#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=10010,M=2*200200;
int n,m;
int tot,nex[M],las[N],to[M],v[M];
int dis[N][2],fi[N][2];
int d[N*10],hd,tl;
int vis[N];
int up(int x,int v,int fr)
{
	int rt=0;
	if(v<dis[x][1]) 
	{
		if(fr!=fi[x][1]) dis[x][0]=dis[x][1],fi[x][0]=fi[x][1];
		dis[x][1]=v,fi[x][1]=fr;
		rt=1;	
	}
	else if(fr!=fi[x][1] && v<dis[x][0]) 
		dis[x][0]=v,fi[x][0]=fr,rt=1;
	return rt;
}
void spfa()
{
	memset(dis,127,sizeof dis);
	hd=0,tl=0;
	for(int tp=las[1];tp;tp=tp[nex])
	{
		if(up(to[tp],v[tp],tp) && !vis[to[tp]])
			d[++tl]=to[tp],vis[to[tp]]=1;
	}
	while(hd++<tl)
	{
		int x=d[hd];
		for(int tp=las[x];tp;tp=tp[nex])
		{	
			fd(i,1,0) if(up(to[tp],v[tp]+dis[x][i],fi[x][i]) && !vis[to[tp]])
				d[++tl]=to[tp],vis[to[tp]]=1;
		}
		vis[x]=0;
	}

}
void link(int x,int y,int va)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
	v[tot]=va;
}
int main()
{
	freopen("D:/LiuYuanHao/b.in","r",stdin);
	tot=1; 
	scanf("%d%d",&n,&m);
	fo(i,1,m)
	{
		int x,y,w,v;
		scanf("%d%d%d%d",&x,&y,&w,&v);
		link(x,y,w),link(y,x,v);
	}
	spfa();
	int ans=oo;
	for(int tp=las[1];tp;tp=tp[nex])
	{
		int pt=tp^1,tt=to[tp];
		if(fi[tt][1]==tp) ans=min(ans,dis[tt][0]+v[pt]);
		else ans=min(ans,dis[tt][1]+v[pt]);
	}
	printf("%d\n",ans);
	return 0;
}








