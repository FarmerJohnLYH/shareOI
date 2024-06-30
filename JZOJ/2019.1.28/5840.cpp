#pragma GCC optimize(2) 
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=800800;
int n,m;
int du[N];
int ans[N][2],a0;
int las[N],nex[N],to[N],pre[N],tot;
int bb,cnt,bz[N];
void link(int x,int y)
{
	nex[++tot]=las[x],to[tot]=y,las[x]=tot;
	pre[nex[tot]]=tot;
}
int gn(int x)
{
	return((!bz[x])||x==0)?(x):(nex[x]=gn(nex[x]));
}
void del(int x,int y)
{
	pre[nex[x]]=pre[x],nex[pre[x]]=nex[x];
	if(las[y]==x) las[y]=nex[x];
	bz[x]=1;
	nex[x]=gn(nex[x]);
}
void dfs(int x,int &la)
{
	for(int tp=las[x];tp;tp=gn(tp[nex]))
	if(!bz[tp])
	{
		del(tp,x),del(tp^1,tp[to]);
		dfs(tp[to],x);	
	}
	if(x==bb)return;
	if(la==bb) ans[++a0][0]=1,ans[a0][1]=x,++cnt;
	else
	{ 
		if(la==0) ans[++a0][0]=1,ans[a0][1]=x,++cnt; 
		else ans[++a0][0]=0,ans[a0][1]=x;
	}
}
int main()
{
	 freopen("miner.in","r",stdin);
	 freopen("miner.out","w",stdout);
//	freopen("D:/LiuYuanHao/b.in","r",stdin);
//	freopen("D:/LiuYuanHao/b.ans","w",stdout);
	scanf("%d%d",&n,&m);
	tot=1,bb=n+1;
	fo(i,1,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		link(x,y),link(y,x);
		++du[x],++du[y];
	}
	fo(i,1,n) if(du[i]&1) link(bb,i),link(i,bb);
	++n;
	int gg=0;
	dfs(bb,gg);
	fo(i,1,n) if(las[i]) dfs(i,gg);
	printf("%d\n%d\n",cnt-1,ans[a0][1]);
	fd(i,a0-1,1) printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}





