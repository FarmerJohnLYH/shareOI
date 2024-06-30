#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define clear(a) {fo(i,1,n) a[i]=0;}
using namespace std;
const int N=200200;
int n,m;
int nex[N*2],to[N*2],las[N],tot;
void link(int x,int y)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
}
int mx,fa[N],dep[N];
int ans,tpp[N];
int sta[N];
void dfs(int x)
{
	for(int tp=las[x];tp;tp=tp[nex])
	if(tp[to]!=fa[x])
	{
		dep[tp[to]]=dep[x]+1;
		fa[tp[to]]=x;
		dfs(tp[to]);
	}
	if(dep[x]>dep[mx])mx=x;
}
int rot,enl;
int ln[N],l0;
int d[N],hd,tl;
int dis[N];
int solve(int fx,int fy)
{
	memset(dis,127,sizeof dis);
	hd=0,tl=2;
	dis[fx]=dis[fy]=0;
	d[1]=fx,d[2]=fy;
	int mx=0;
	while(hd++<tl)
	{
		int x=d[hd];
		mx=max(mx,dis[x]);
		for(int tp=las[x];tp;tp=tp[nex])
		if(to[tp][dis]==oo)
		{
			to[tp][dis]=dis[x]+1;
			d[++tl]=to[tp];
		}
	}
	return(mx);
}
int main()
{
	  freopen("ob.in","r",stdin);
	  freopen("ob.out","w",stdout);
//	freopen("D:/LiuYuanHao/b2.in","r",stdin);
	scanf("%d",&n);
	fo(i,1,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		link(x,y),link(y,x);
	}
	dep[1]=1;
	dfs(1);
	clear(dep);dep[mx]=1;clear(fa);
	rot=mx;dfs(mx);
	enl=mx;
	for(int x=enl;x;x=fa[x]) ln[++l0]=x;
	int le=0,ri=l0/2+1;ans=ri;
	while(le<=ri)
	{
		m=(le+ri)>>1;
		int tp;
		if((tp=solve(ln[l0-m],ln[m+1]))<=m) 
			ri=m-1,ans=m;
		else le=m+1;
//		printf("%d\n",tp);
	}
	printf("%d\n",ans);
	return 0;
}











