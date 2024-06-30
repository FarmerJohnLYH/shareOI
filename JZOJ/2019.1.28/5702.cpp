#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=200200,mo=998244353;
int n,m,k;
int las[N],to[N],nex[N],tot;
int c[11][11];
int fa[N];
ll f[N][2][11];
ll fr[11],a[11],g[11],w[11];
void com(ll *a,ll *b)
{
	fo(i,0,k) g[i]=0;
	fo(i,0,k) fo(j,0,i)
	g[i]=(g[i]+(a[j]*b[i-j]%mo)*c[i][j])%mo;
	fo(i,0,k) a[i]=g[i];
}
void link(int x,int y)
{
	to[++tot]=y,tot[nex]=las[x],las[x]=tot;
}
void dfs(int x)
{
	fa[x]=1;
	for (int tp=las[x];tp;tp=tp[nex])
	if(!fa[tp[to]])
		dfs(tp[to]);
	f[x][0][0]=f[x][1][0]=1;
	for (int tp=las[x];tp;tp=tp[nex])
	if(!fa[tp[to]])
	{
		int t=to[tp];
		fo(i,0,k) w[i]=(f[t][0][i]+f[t][1][i])%mo;
		com(f[x][0],w);
		fo(i,0,k) w[i]=f[t][1][i];
		com(w,fr);
		fo(i,0,k) w[i]=(w[i]+f[t][0][i])%mo;
		com(f[x][1],w);
	}
	fa[x]=0;
}
int main()
{
//	freopen("subgraph.in","r",stdin);
//	freopen("subgraph.out","w",stdout);
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	fo(i,0,10) 
	{
		c[i][0]=c[i][i]=1;
		fo(j,1,(i+1)/2)c[i][j]=c[i][i-j]=(c[i-1][j-1]+c[i-1][j])%mo; 
	}
	fo(i,1,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		link(x,y),link(y,x);
	}
	fo(i,0,k) fr[i]=1;
	dfs(1);
	printf("%lld\n",(f[1][0][k]+f[1][1][k])%mo);
	return 0;
}











