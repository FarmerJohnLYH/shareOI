#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
#define fd(i,x,y) for(int i=(x);i>=(y);--i)
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
typedef long long ll;
const int N=100100;
const ll inf=(1ll<<60);
int n,m;
int p[N]; 
int qa,qx,qb,qy;
int fa[20][N],d0;
ll f[20][N][2][2],va[N][2],pv[N][2];//va[x][y] x点及其子树权值和
int las[N],nex[N*2],to[N*2],dep[N];//f[p][x][cx][cf] 不包括x点 包括2^p级祖先
ll ans;
void add(ll &x,ll y)
{
	x=x+y;
	if(x>inf) x=inf;
}
void dfs(int x)
{
	for(int tp=las[x];tp;tp=tp[nex])
	if(to[tp]!=fa[0][x])
	{
		fa[0][to[tp]]=x;
		dep[to[tp]]=dep[x]+1;
		dfs(to[tp]);
	}
	va[x][0]=0,va[x][1]=p[x];
	for(int tp=las[x];tp;tp=tp[nex])
	if(tp[to]!=fa[0][x])
	{
		add(va[x][1],min(va[to[tp]][1],va[to[tp]][0]));
		add(va[x][0],va[to[tp]][1]);
	}
}
void run(int x)
{
	ll s[2];s[0]=s[1]=0;
	fo(k,0,1)add(pv[x][k],pv[fa[0][x]][k]);
	s[0]=va[x][0],s[1]=va[x][1]-p[x];//pv[x][y] 除去x点及其子树的权值和 其中x选色y
	for(int tp=las[x];tp;tp=tp[nex])
	{
		add(pv[to[tp]][0],s[0]-va[to[tp]][1]);
		add(pv[to[tp]][1],s[1]-min(va[to[tp]][1],va[to[tp]][0]));
	}
	for(int tp=las[x];tp;tp=tp[nex])
	if(to[tp]!=fa[0][x])
		run(to[tp]);
}
int tot;
void link(int x,int y)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
}
char sts[10];
void lca(int x,int y,int ax,int ay)
{
	if(dep[x]<dep[y]) swap(x,y),swap(ax,ay);
	int d=dep[x]-dep[y];ll le[2],ri[2];//终点颜色
	le[0]=le[1]=ri[0]=ri[1]=0;
	ans=va[x][ax]+va[y][ay];
	fo(i,0,18) if((1<<i)&d)
	{
		if(ax!=-1) add(le[0],f[i][x][ax][0]),add(le[1],f[i][x][ax][1]),ax=-1;
		
		x=fa[i][x];
	}
	if(x==y) 
	{
		add(ans,le[ay]);
		return;
	}
	fd(i,18,0)
	if(fa[i][x]!=fa[i][y])
	{
	
		x=fa[i][x],y=fa[i][y];
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,sts);
	fo(i,1,n) scanf("%d",&p[i]);
	fo(i,1,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		link(x,y),link(y,x);
	}
	dfs(1);run(1);
	fo(i,1,n) fo(k1,0,1) 
	{
		for(int tp=las[i];tp;tp=tp[nex])
		if(tp[to]!=fa[0][i])
		{
			int t=to[tp];
			add(f[0][i][k1][1],min(va[t][0],va[t][1]));
			add(f[0][i][k1][0],va[t][1]);
		}
	}
	fo(l,1,18)
		fo(i,1,n) fo(k1,0,1) fo(k2,0,1) fo(k3,0,1)
			fa[l][i]=fa[l-1][fa[l-1][i]],add(f[l][i][k1][k3],f[l-1][i][k1][k2]+f[l-1][fa[l-1][i]][k2][k3]);
	while(m--)
	{
		scanf("%d%d%d%d",&qa,&qx,&qb,&qy);
		if(qa==qb)
		{
			if(qx!=qy)printf("-1\n");
			else printf("%lld\n",pv[qa][qx]+va[qa][qx]-p[qa]);
			continue;
		}
		ans=0;
		lca(qa,qb,qx,qy);
		if(ans>=inf) printf("-1\n");
		else printf("%lld\n",ans);
	}
	return 0;
}



