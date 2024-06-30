#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x),asdfgh=(y);i<=asdfgh;++i)
#define fd(i,x,y) for (int i=(x),asdfgh=(y);i>=asdfgh;--i)
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int,int> PI;
int abs(int x) {return(((x)>=0)?(x):(-(x)));}
int max(int x,int y) {return(((x)>(y))?(x):(y));}
int min(int x,int y) {return(((x)<(y))?(x):(y));}
int lowbit(int x) {return((x)&(-x));}
const int N=5050,P=10010;
int n,p;
int to[N],nex[N],las[N];
int tot;
void link(int x,int y)
{
	to[++tot]=y,tot[nex]=las[x];
	las[x]=tot;
}
int w[N],f[N],v[N];
int dp[N][P];
void dfs(int x)
{
	if(x!=f[x])
		fo(j,0,p-w[x]) 
		if(dp[f[x]][j]>=0)dp[x][j+x[w]]=dp[f[x]][j]+v[x];
	for (int tp=las[x];tp;tp=tp[nex])
	{
		int t=tp[to];
		if(t!=x)dfs(t);
		fo(j,1,p) dp[x][j]=max(dp[x][j],dp[t][j]);
//		printf("");
	}
}
int main()
{
	freopen("medicine.in","r",stdin);
	freopen("medicine.out","w",stdout);
//	freopen("D:/LiuYuanHao/a1.in","r",stdin);
	scanf("%d%d",&n,&p);
	fo(i,1,n)
	{
		scanf("%d%d%d",&w[i],&f[i],&i[v]);
		link(i[f],i);
	}
	memset(dp,128,sizeof dp);
	dp[1][w[1]]=v[1];
	dfs(1);
	int ans=0;
	fo(j,0,p) ans=max(ans,dp[1][j]);
	printf("%d\n",ans);
	return 0;
}











