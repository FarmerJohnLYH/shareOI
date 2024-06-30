#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=100100,M=10010;
int n,v[N],dep[N];
int fa[N];
vector<int> to[N];
int d[N],d0;
int f[N];
void dfs(int x)
{
	dep[x]=fa[x][dep]+1;
	for(int p=to[x].size()-1,i=0;i<=p;++i)
		dfs(to[x][i]);
	if(to[x].empty()) d[++d0]=x;
}
int p[2][N],p0[2],va[N];
int g[N],mv[N],mf[N];
int main()
{
	 freopen("temmie.in","r",stdin);
	 freopen("temmie.out","w",stdout);
//	freopen("D:/LiuYuanHao/c2.in","r",stdin);
	scanf("%d",&n);
	fo(i,1,n)
	{
		int p,x;
		scanf("%d%d",&v[i],&p);
		fo(j,1,p)
		{
			scanf("%d",&x);
			to[i].push_back(x);
			fa[x]=i;
		}
	}
	fo(i,1,n) va[i]=v[fa[i]];
	dfs(1);
	int x=d[1],y;
	memset(f,128,sizeof f);
	while(x) f[x]=v[x],x=x[fa];
	fo(k,2,d0)
	{
		x=d[k-1],y=d[k];
		int o=0;p0[0]=p0[1]=1;
		p[0][1]=x,p[1][1]=y;
		while(x!=y)
		{
			if(dep[x]<dep[y])swap(x,y),o^=1;
			x=fa[x];p[o][++p0[o]]=x;
		}
		--p0[0],--p0[1];
		mv[p0[0]+1]=0;
		int mx=-oo;
		fd(i,p0[0],1) mv[i]=max(mv[i+1],p[0][i][va]);
		g[0]=-oo;
		fo(i,1,p0[0]) g[i]=max(g[i-1],p[0][i][f]-mv[i]);
		int j=p0[0],mxf=-oo;
		fd(i,p0[1],1)
		{
			mx=max(mx,p[1][i][va]);
			while(j>0&&mv[j]<=mx) mxf=max(mxf,p[0][j][f]),--j;
			if(j) f[p[1][i]]=max(f[p[1][i]],g[j]+v[p[1][i]]);
			f[p[1][i]]=max(f[p[1][i]],mxf-mx+v[p[1][i]]);
		}
	}
	x=d[d0];
	int ans=-oo;
	while(x) ans=max(ans,f[x]),x=fa[x];
	printf("%d\n",ans);
	return 0;
}








