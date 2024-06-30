#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=200200;
int n,m,h;
int c[N];
vector<int> to[N];
int bz[N],vis[N],sta[N];
int fa[N],dfn[N],top[N],f[N],p[N],du[N];
int tot,cnt,ans;
void tj(int x)
{
	dfn[x]=top[x]=++tot;sta[++sta[0]]=x;
	int sz=to[x].size();
	fo(i,0,sz-1)
	{
		int tt=to[x][i];
		if(!dfn[tt]) tj(tt);
		top[x]=min(top[x],top[tt]);
	}
	if(dfn[x]==top[x])
	{
		++cnt;
		for(int now=sta[sta[0]--];now!=x;now=sta[sta[0]--]) ++p[f[now]=cnt];
		++p[f[x]=cnt];
	}
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d%d",&n,&m,&h);
	fo(i,1,n) scanf("%d",&c[i]);
	fo(i,1,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(c[x]==(c[y]+1)%h) to[y].push_back(x);
		if(c[y]==(c[x]+1)%h) to[x].push_back(y);
	}
	ans=0,p[0]=oo;
	fo(i,1,n) 
	if(!dfn[i])tj(i);
	fo(i,1,n)
	{
		int sz=to[i].size();
		fo(l,0,sz-1)
		if(f[i]!=f[to[i][l]]) ++du[/*f[to[i][l]]*/f[i]];
	}
	fo(i,1,cnt)
	if(du[i]==0&&p[i]<p[ans]) ans=i;
	printf("%d\n",p[ans]);
	fo(i,1,n) 
	if(f[i]==ans)
		printf("%d ",i);
	return 0;
}











