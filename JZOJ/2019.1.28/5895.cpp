#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=500500,mo=998244353;
int n,m;
int fa[N],b[N];
int f[N];
ll v[N*2],t[N];
int nex[N*2],las[N],to[N*2];
int tot;ll tw[N];
void link(int x,int y,int va)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;v[tot]=tw[va];
}
int du[N];ll ans;
void dfs(int x)
{
	for(int tp=las[x];tp;tp=tp[nex])
	if(to[tp]!=fa[x])
	{
		to[tp][fa]=x,t[to[tp]]=tp[v];
		dfs(to[tp]);
	}
	if(b[x]) ans=(ans+t[x])%mo,b[fa[x]]^=b[x],b[x]=0;
}
int gf(int x)
{
	return(f[x]==x)?x:(f[x]=gf(f[x]));
}
int main()
{
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	 freopen("D:/LiuYuanHao/b.in","r",stdin);
	scanf("%d%d",&n,&m);
	tw[0]=1;
	fo(i,1,m)tw[i]=tw[i-1]*2ll%mo;
	fo(i,1,n) f[i]=i;
	fo(i,1,m)
	{
		ans=(ans+tw[i])%mo;
		int x,y;
		scanf("%d%d",&x,&y);
		if(gf(x)!=gf(y))
		{
			f[gf(x)]=gf(y);
			link(x,y,i),link(y,x,i);
		}
		du[x]^=1,du[y]^=1;
	}
	fo(i,1,n) if(du[i]) b[i]=1; 
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}








