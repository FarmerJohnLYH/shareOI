#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int ppp=(y),i=(x);i<=(ppp);++i)
using namespace std;
const int N=1010,M=5050,all=4095;
int n,m,dep[N];
struct edge{
	int x,y,m,c,qx,qy;
	edge(int x_=0,int y_=0,int m_=0,int c_=0)
	{
		x=x_,y=y_,m=m_,c=c_,qx=qy=-1;
	}
}e[M];int e0;
vector<edge> a[N];
vector<int> to[N];
int f[N][M],ans,fa[N],sum;
int find(int f,int x)
{
	fo(i,0,to[f].size()-1)
		if(to[f][i]==x) return i;
	return -1;
}
void dfs(int x)
{
	dep[x]=dep[fa[x]]+1;
	fo(i,0,to[x].size()-1)
	if(to[x][i]!=fa[x])
	{
		to[x][i][fa]=x;
		dfs(to[x][i]);
	}
}
int val(int x)
{
	return(x==-1)?(0):(1<<(x));
}
int calc(int x,int y,int a)
{	
	if(dep[x]<dep[y]) swap(x,y);
	int rt=f[x][all]+f[y][all];
	if(y==a)
	{
		rt=f[x][all];
		while(fa[x]!=y) rt+=f[fa[x]][all-val(find(fa[x],x))],x=fa[x];
		return rt;
	}
	while(fa[x]!=fa[y])
	{
		if(dep[x]<dep[y]) swap(x,y);
		rt+=f[fa[x]][all-val(find(fa[x],x))],x=fa[x];
	}
	return rt;
}
void work(int x)
{
	int sum=0;
	fo(i,0,to[x].size()-1)
	if(to[x][i]!=fa[x])
		work(to[x][i]);
	fo(st,0,all)
	{
		int cnt=0;
		fo(i,0,to[x].size()-1)
		if(st&val(i))
			cnt+=f[to[x][i]][all];
		f[x][st]=max(f[x][st],cnt);
	}
	fo(i,0,a[x].size()-1)
	{
		edge nw=a[x][i];int cal=calc(nw.x,nw.y,nw.m);
		fo(st,0,all)
			if((st&val(nw.qx) || (val(nw.qx)==0)) && (st&val(nw.qy) || (val(nw.qy)==0)))
			{
				f[x][st]=max(f[x][st],f[x][st-val(nw.qx)-val(nw.qy)]+cal+nw.c);	
			}
	}
}
int lca(int x,int y,int &qx,int &qy)
{
	if(dep[x]<dep[y]) swap(x,y),swap(qx,qy);
	int flag=0,px=x;
	while(px)
	{
		if(px==y)
		{
			flag=1;
			break;
		}
		px=fa[px];
	}
	if(flag)
	{
		while(fa[x]!=y) x=fa[x];
		qx=find(y,x);
		return y;
	}
	while(fa[x]!=fa[y])
	{
		if(dep[x]<dep[y]) swap(x,y),swap(qx,qy);
		x=fa[x];
	}
	qx=find(fa[x],x),qy=find(fa[x],y);
	return fa[x];
}
int du[N];
int main()
{
	freopen("zujijihua.in","r",stdin);
	freopen("zujijihua.out","w",stdout);
//	freopen("D:/LiuYuanHao/a1.in","r",stdin);
	scanf("%d%d",&n,&m);
	fo(i,1,m)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
//		if(x==y)continue;
		if(c==0) 
		{
			to[x].push_back(y),to[y].push_back(x);
		}else e[++e0]=edge(x,y,0,c);
	}
	dfs(1);
	fo(i,1,e0)
	{
		e[i].m=lca(e[i].x,e[i].y,e[i].qx,e[i].qy);
		if(((dep[e[i].x]+dep[e[i].y]-dep[e[i].m]*2+1)&1)==0) ans+=e[i].c,e[i].m=-1;
		else 
			if(e[i].x!=e[i].y)
			{
				a[e[i].m].push_back(e[i]),sum+=e[i].c;
			}
	}
	work(1);
	printf("%d\n",ans+sum-f[1][all]);
	return 0;
}








