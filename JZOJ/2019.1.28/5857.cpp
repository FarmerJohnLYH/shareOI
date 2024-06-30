#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=220,M=N*N;
int n,m;
int nex[M],las[N],to[M],tot;
int pex[M],pas[N],po[M],pot;
int typ,du[N][2];
int g[N][N];
void link(int x,int y)
{
	++du[y][1],++du[x][0];
	nex[++tot]=las[x],to[tot]=y,las[x]=tot;
	swap(x,y);
	pex[++pot]=pas[x],po[pot]=y,pas[x]=pot;
}
int vis[N];
void check(int x,int y)
{
	vis[y]=1;
	for(int tp=pas[x];tp;tp=tp[pex])
	if(!tp[po][vis])
	{
		g[x][po[tp]]=1;
		check(x,tp[po]);
	}
}
void init()
{
	scanf("%d%d",&n,&m);
	fo(i,1,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		link(x,y);
	}

	typ=3;fo(i,1,n) if(du[i][0]*du[i][1]!=0) 
		{
			typ=0;
			break;
		}
	if(typ)return;
	typ=2;fo(i,2,n) if(du[i][0]!=1) 
		{
			typ=0;
			break;
		}
	if(typ)return;
	typ=1;fo(i,2,n) if(du[i][1]!=1) 
		{
			typ=0;
			break;
		}
	fo(i,1,n)
	{
		memset(vis,0,sizeof vis);
		check(i,i);
	}
}
int pfs(int x)
{
	int rt=0;
	for(int tp=pas[x];tp;tp=tp[pex])
		rt+=pfs(tp[po]);
	if(!rt) return 1;
	return rt;
}
int dfs(int x)
{
	int rt=0;
	for(int tp=las[x];tp;tp=tp[nex])
		rt+=dfs(tp[to]);
	if(!rt) return 1;
	return rt;
}
int ans,h[N];
void work(int x,int c)
{
	if(c>=ans) ans=c;
	if(x>n) return;
	work(x+1,c);
	fo(i,1,n)if(g[x][i]&&h[i]) 
		return;
	h[x]=1;
	work(x+1,c+1);
	h[x]=0;
}
int main()
{
	freopen("dance.in","r",stdin);
	freopen("dance.out","w",stdout);
//	freopen("D:/LiuYuanHao/c1.in","r",stdin);
	init();
	if(typ==2)
	{
		printf("%d\n",pfs(1));
		return 0;
	}
	if(typ==1) 
	{
		printf("%d\n",dfs(1));
		return 0;
	}
	if(typ==3)
	{
		int cnt=0;
		fo(i,1,n) 
		if(du[i][0])++cnt;
		printf("%d\n",max(cnt,n-cnt));
		return 0;
	}
	ans=1;
	work(1,0);
	printf("%d\n",ans);
	return 0;
}











