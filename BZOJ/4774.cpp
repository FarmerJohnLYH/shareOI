#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=20020,S=16*2;
int n,D,m;
int tot;
int nex[N],va[N],to[N],las[N];
int ans[S];
int f[S][N];
void link(int x,int y,int c)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot,va[tot]=c;
}
int d[N*100],hd,tl;
int vis[N];
void spfa(int st)
{
	memset(vis,0,sizeof vis);
	hd=0,tl=0;
	fo(i,1,n) if(f[st][i]!=oo) d[++tl]=i,vis[i]=1;
	while(hd++<tl)
	{
		int x=d[hd];
		for(int tp=las[x];tp;tp=tp[nex])
			if(f[st][to[tp]]>f[st][x]+va[tp])
			{
				f[st][to[tp]]=f[st][x]+va[tp];	
				if(!vis[to[tp]]) d[++tl]=to[tp],vis[to[tp]]=1;
			}
		vis[x]=0;
	}
}
int all;
void dfs(int cs,int al,int nw)
{
	if((1<<cs)>all)
	{
		fo(i,1,n)
		f[al][i]=min(f[al][i],f[al-nw][i]+f[nw][i]);
		return;
	}
	if(al&(1<<cs))dfs(cs+1,al,nw|(1<<cs));
	dfs(cs+1,al,nw);
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d%d",&n,&m,&D);
	fo(i,1,m)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		link(x,y,c),link(y,x,c);
	}
	all=(1<<D)-1;
	memset(f,127,sizeof f);
	fo(i,1,D)
	{
		memset(f[0],127,sizeof f[0]);
		f[0][i]=0;
		spfa(0);
		f[1<<(i-1)][i]=f[1<<(i-1)][n-i+1]=f[0][n-i+1];
	}
	fo(i,1,n) f[0][i]=0;
	fo(st,1,all)
	{
		spfa(st);
		dfs(0,st,0);
	}
	int ans=oo;
	fo(i,1,n) ans=min(ans,f[all][i]);
	printf("%d\n",ans);
	return 0;
}








