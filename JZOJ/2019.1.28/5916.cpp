#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fi first
#define se second
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
const int N=200200,M=300300;
int n,m;
ll a[N],f[M];
vector<PI> to[N];
int abs(int x)
{
	return(x>0)?x:(-x);
}
int vis[N];
void dfs(int x)
{
	vis[x]=1;
	for(int p=to[x].size()-1,i=0;i<=p;++i)
	if(!to[x][i].fi[vis])
	{
		dfs(to[x][i].fi);
		a[x]+=to[x][i].fi[a];
		f[abs(to[x][i].se)]+=a[to[x][i].fi]*(to[x][i].se/abs(to[x][i].se));
		to[x][i].fi[a]=0;
	}
}
int main()
{
	 freopen("flow.in","r",stdin);
	 freopen("flow.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d",&n);fo(i,1,n) scanf("%lld",&a[i]);
	scanf("%d",&m);
	fo(i,1,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		to[x].push_back(mp(y,i)),to[y].push_back(mp(x,-i));
	}
	dfs(1);
	if(a[1]!=0) printf("Impossible\n");
	else
	{
		printf("Possible\n");
		fo(i,1,m) printf("%lld\n",f[i]);
	}
	return 0;
}








