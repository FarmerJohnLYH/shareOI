#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define one 1.0000000000000
#define oo 2139062143
#define ldb db
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
//typedef __float128 ldb;
typedef double db;
typedef long long ll;
const ll M=1000000000000000000;
int T,n,m;
int tot,cnt,a[9][9];
int b[110];
int to[110],nex[110],las[110],ch[110];
ldb p[110];
void link(int x,int y)
{
	to[++tot]=y,nex[tot]=las[x];las[x]=tot;
	swap(x,y); 
	to[++tot]=y,nex[tot]=las[x];las[x]=tot;
}
db mp;
db ans;
int d[110],hd,tl;
int judge()
{
	memset(b,0,sizeof b);b[a[1][1]]=1;
	hd=0,tl=1;d[tl]=a[1][1];
	while(hd++<tl)
	{
		int now=d[hd];
		for (int tp=las[now];tp;tp=tp[nex]) 
		if(!b[tp[to]]&&ch[tp/2])
			d[++tl]=tp[to],b[tp[to]]=1;
	}
	return(b[a[n][m]]);
}
int sum;
void dfs(int x,db vl)
{
	if(x*2>tot)
	{
		if(judge()) ans+=vl;
		return;
	}
	ch[x]=0;
	dfs(x+1,vl*(1-p[1]));
	ch[x]=1;
	dfs(x+1,vl*p[1]);
}
int main()
{
	freopen("socialman.in","r",stdin);
	freopen("socialman.out","w",stdout);
	// freopen("D:/LiuYuanHao/b.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		memset(las,0,sizeof las);
		scanf("%d%d%lf",&n,&m,&mp);
		tot=1,cnt=0;
		ans=0.0000000;
		fo(i,1,n) fo(j,1,m) a[i][j]=++cnt;
		p[0]=one,p[1]=1-mp;
		fo(i,1,n) fo(j,1,m)
		{
			if(i+1<=n) link(a[i][j],a[i+1][j]);
			if(j+1<=m) link(a[i][j],a[i][j+1]);
		}
		dfs(1,one);
		printf("%.8lf\n",ans);
	}
	return 0;
}











