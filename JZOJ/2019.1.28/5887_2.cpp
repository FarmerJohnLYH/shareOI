#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=200200;
int T,n;
vector<int> to[N];
ll f[N],g[N],ans;
ll fa[N],p[N],q[N];
int d[N];
void dfs(int x)
{
	for(int p=to[x].size()-1,i=0;i<=p;++i)
	if(to[x][i]!=fa[x])
	{
		to[x][i][fa]=x;
		dfs(to[x][i]);
		f[x]=max(f[x],to[x][i][f]+1);
	}
}
void work(int x)
{
	int d0=0;
	for(int pp=to[x].size()-1,i=0;i<=pp;++i)
	if(to[x][i]!=fa[x]) d[++d0]=to[x][i];
		
	fo(j,0,d0+1)p[j]=q[j]=0; 
	fo(j,1,d0)p[j]=max(p[j-1],f[d[j]]);
	fd(j,d0,1)q[j]=max(q[j+1],f[d[j]]);
	fo(j,1,d0)g[d[j]]=max(g[d[j]],max(p[j-1],q[j+1])+1);
	fo(j,1,d0)g[d[j]]=max(g[d[j]],g[x]+1); 
	for(int pp=to[x].size()-1,i=0;i<=pp;++i)
	if(to[x][i]!=fa[x]) work(to[x][i]);
}
int main()
{
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
//	freopen("D:/LiuYuanHao/b1.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		fo(i,1,n-1)
		{

			int x,y;
			scanf("%d%d",&x,&y);
			to[x].push_back(y),to[y].push_back(x);
		}
		memset(f,0,sizeof f);
		memset(fa,0,sizeof fa);
		memset(g,0,sizeof g);
		dfs(1);
		fo(i,1,n) ++f[i];
		work(1);
		ans=f[1];
		fo(i,2,n) ans+=min(f[i]+1,g[i]);
		printf("%lld\n",ans);
		fo(i,1,n)
			while(!to[i].empty()) to[i].pop_back();
	}
	return 0;
}








