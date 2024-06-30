#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=550,mo=998244353;
int n,m;
ll v[N*2];
int nex[N*2],las[N],to[N*2],bz[N];
int tot;ll tw[N];
void link(int x,int y,int va)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;v[tot]=tw[va];
}
int du[N],d[N],d0;
ll f[N][N];
ll ans;
void dfs(int x,ll va)
{
	if(x==-1)
	{
		ans=min(ans,va);
		return;
	}
	bz[x]=0;
	fo(i,1,d0)
	if(bz[d[i]])
	{
		bz[d[i]]=0;
		int flag=-1;
		fo(k,1,d0)if(bz[d[k]])
		{
			flag=d[k];
			break;
		}
		dfs(flag,va+f[d[i]][x]);
		bz[d[i]]=1;
	}
	bz[x]=1; 
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
//	 freopen("D:/LiuYuanHao/b.in","r",stdin);
	scanf("%d%d",&n,&m);
	tw[0]=1;
	fo(i,1,m)tw[i]=tw[i-1]*2ll%mo;
	memset(f,127,sizeof f);
	ans=oo;ll sum=0;
	fo(i,1,n) f[i][i]=0;
	fo(i,1,m)
	{
		sum=(sum+tw[i])%mo;
		int x,y;
		scanf("%d%d",&x,&y);
		du[x]^=1,du[y]^=1;
		f[x][y]=f[y][x]=min(f[x][y],tw[i]);
	}
	fo(k,1,n) fo(i,1,n) fo(j,1,n) 
	if(f[i][k]<oo&&f[k][j]<oo)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	fo(x,1,n)
		if(du[x]) d[++d0]=x,bz[x]=1;
	if(d0)dfs(d[1],0);else ans=0;
	printf("%lld\n",ans+sum);
	return 0;
}








