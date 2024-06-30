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
bool b[110];
int to[110],nex[110],las[110];
ldb ans,p[110];
void link(int x,int y)
{
	to[++tot]=y,nex[tot]=las[x];las[x]=tot;
}
void dfs(int x,int ct)
{
	if(x==a[n][m])
	{
		ans=ans+p[ct];
		return;
	}
	if(b[x])return;
	b[x]=1;
	for (int tp=las[x];tp;tp=tp[nex])
		dfs(tp[to],ct+1);
	b[x]=0;
}
db mp;
int main()
{
	freopen("D:/LiuYuanHao/b.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		memset(las,0,sizeof las);
		scanf("%d%d%lf",&n,&m,&mp);mp=1-mp;tot=cnt=0;
		ans=0.0000000;
		fo(i,1,n) fo(j,1,m) a[i][j]=++cnt;
		p[0]=one,p[1]=mp;
		fo(i,2,50) p[i]=p[i-1]*p[1];
		fo(i,1,n) fo(j,1,m)
		{
			if(i-1>0) link(a[i][j],a[i-1][j]);
			if(j-1>0) link(a[i][j],a[i][j-1]);
			if(i+1<=n) link(a[i][j],a[i+1][j]);
			if(j+1<=m) link(a[i][j],a[i][j+1]);
		}
		memset(b,0,sizeof b);
		dfs(a[1][1],0);
		mp=ans;
		printf("%.8lf\n",mp);
	}
	return 0;
}











