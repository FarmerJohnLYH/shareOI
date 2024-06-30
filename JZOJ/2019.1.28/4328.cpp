//#pragma GCC optimize(2)
#include <ctime> 
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=300300;
int dep[N],vis[N];
int n,m,p0,p[N];
int rt,mx;
int fa[20][N],v[20][N];
int to[N*2],nex[N*2],las[N],va[N*2];
int tot;
int ans;
void link(int x,int y,int v)
{	
	to[++tot]=y,nex[tot]=las[x];las[x]=tot;
	va[tot]=v;
}
void dfs(int x)
{
	for(int tp=las[x];tp;tp=tp[nex])
	if(to[tp]!=fa[0][x])
	{
		fa[0][to[tp]]=x,dep[to[tp]]=dep[x]+1;
		v[0][to[tp]]=va[tp];
		dfs(to[tp]);
	}
}
int pi[N][2],len[N],fr[N][2];
int pv[N][2];
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	int d=dep[x]-dep[y];
	fo(i,0,18)if((1<<i)&d) x=fa[i][x];
	if(x==y)return x;
	fd(i,18,0)if(fa[i][x]!=fa[i][y]) 
		x=fa[i][x],y=fa[i][y];
	return fa[0][x];
}
int val(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	int d=dep[x]-dep[y],rt=0;
	fo(i,0,18)if((1<<i)&d) rt+=v[i][x],x=fa[i][x];
	if(x==y)return rt;
	fd(i,18,0)if(fa[i][x]!=fa[i][y]) rt+=v[i][x]+v[i][y],x=fa[i][x],y=fa[i][y];
	rt+=v[0][x]+v[0][y];
	return rt;
}
int pri;
int main()
{
//	freopen("transport.in","r",stdin);
//	freopen("transport.out","w",stdout);
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&m);pri=oo;
	int ppp=clock();
	printf("%d\n",clock()-ppp);ppp=clock();
	fo(i,1,n-1)
	{
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		link(x,y,v),link(y,x,v);	
	}
	rt=1,mx=0;
	fa[0][1]=0,dep[1]=1;
	printf("%d\n",clock()-ppp);ppp=clock();
	dfs(1);
	printf("%d\n",clock()-ppp);ppp=clock();
	fo(l,1,18) fo(x,1,n)
	{
		v[l][x]=v[l-1][x]+v[l-1][fa[l-1][x]];
		fa[l][x]=fa[l-1][fa[l-1][x]];
	}
	mx=0;
	printf("%d\n",clock()-ppp);ppp=clock();
	fo(i,1,m)
	{
		scanf("%d%d",&pi[i][0],&pi[i][1]);
		len[i]=val(pi[i][0],pi[i][1]);
		if(mx==0||len[mx]<len[i]) mx=i;
	}
	int ry=mx;mx=0;rt=pi[ry][0];
	fa[0][rt]=0,dep[rt]=1;
	dfs(rt);
	fo(l,1,18) fo(x,1,n)
	{
		v[l][x]=v[l-1][x]+v[l-1][fa[l-1][x]];
		fa[l][x]=fa[l-1][fa[l-1][x]];
	}
	p[p0=1]=mx=pi[ry][1];
	while(mx!=rt) mx=fa[0][mx],p[++p0]=mx;
	fo(i,1,p0>>1) swap(p[i],p[p0-i+1]);
	fo(i,1,m)
	if(i!=ry)
	{
		fr[i][0]=lca(pi[i][0],p[p0]);
		fr[i][1]=lca(pi[i][1],p[p0]);
		if(fr[i][0]==fr[i][1]) 
		{
			ans=max(ans,len[i]),fr[i][0]=fr[i][1]=0;
		}
		else 
		{
			if(dep[fr[i][0]]>dep[fr[i][1]])swap(fr[i][0],fr[i][1]);
			pv[dep[fr[i][0]]][0]=max(len[i],pv[dep[fr[i][0]]][0]);
			pv[dep[fr[i][1]]][1]=max(len[i],pv[dep[fr[i][1]]][1]);
		}
	}else fr[i][0]=fr[i][1]=0;
	fo(i,2,p0) pv[i][1]=max(pv[i-1][1],pv[i][1]);
	fd(i,p0-1,1) pv[i][0]=max(pv[i+1][0],pv[i][0]);
	fo(i,2,p0)
	{
		int x=p[i];
		int tmp=max(len[ry]-v[0][x],max(pv[i-1][1],pv[i][0]));
		pri=min(pri,tmp);
	}
	if(p0==1) pri=0;
	printf("%d\n",max(pri,ans));
	return 0;
}








