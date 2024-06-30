#include <bitset>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
#define fi first
#define se second
using namespace std;
const int N=2020;
int n,m,k;
int t[N][N],t0[N],v[N][N];
int f[N],mp[N][N];
int gf(int x){return(x==f[x])?x:(f[x]=gf(f[x]));}
int bz[N];
int ans,p0;
int g[N],d[N],sz[N],c[N];
#define min(x,y) ((x)<(y)?(x):(y))
int check(int x)
{
	return(sz[gf(x)]==1||(sz[gf(x)]>1&&bz[g[gf(x)]]));
}
int nex[N];
void solve()
{
	if(!check(1) || !check(n)) return;
	d[1]=0;
	fo(i,1,n+1) nex[i]=oo;
	fd(i,n,2) 
	{
		d[i]=oo,c[i]=check(i);
		if(sz[gf(i)]>1&&bz[g[gf(i)]]) nex[i-1]=i;
		nex[i]=min(nex[i+1],nex[i]);
	}
	nex[1]=min(nex[2],nex[1]);
	fo(i,1,n)
	if(d[i]<oo)
	{
		fo(j,1,t0[i])
		if(c[t[i][j]] && t[i][j]<=nex[i])
			d[t[i][j]]=min(d[t[i][j]],d[i]+v[i][j]);
	}
	ans=min(ans,d[n]);
}
void dfs(int x)
{
	if(x>p0) 
	{
		solve();
		return;
	}
	bz[x]=0;
	dfs(x+1);
	bz[x]=1;
	dfs(x+1);
}
int main()
{
	 freopen("underground.in","r",stdin);
	 freopen("underground.out","w",stdout);
//	freopen("D:/LiuYuanHao/c.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	memset(mp,127,sizeof mp);
	fo(i,1,m)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		mp[x][y]=min(mp[x][y],c);
	}
	fo(x,1,n) fo(y,x+1,n) 
	if(mp[x][y]<oo) t[x][++t0[x]]=y,v[x][t0[x]]=mp[x][y];
	if(k>22)
	{
		int x=1,ans=0;
		while(x<n&&t0[x]>0)
		{
			ans+=v[x][1];
			x=t[x][1];
		}
		printf("%d\n",ans);
		return 0;
	}
	fo(i,1,n) f[i]=i,sz[i]=1;
	fo(i,1,k)
	{
		int x,y;scanf("%d%d",&x,&y);
		sz[gf(y)]+=sz[gf(x)];
		f[gf(x)]=gf(y);
	}
	p0=0;
	fo(x,1,n) if(f[x]==x&&sz[x]>1) g[x]=++p0;
	ans=oo;
	dfs(1);
	printf("%d\n",ans);
	return 0;
}








