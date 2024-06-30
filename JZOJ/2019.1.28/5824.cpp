#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=3003000;
int fa[N];
vector<int> to[N];
int n,m,q,a[N];
int rt[2][N],dep[N];
void lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	rt[0][a[x]]=1,rt[1][a[y]]=1;
	while(dep[x]>dep[y])
	{
		x=fa[x];
		rt[0][a[x]]=1;
	}
	while(x!=y)
	{
		x=fa[x],y=fa[y];
		if(fa[x]!=fa[y]) rt[0][a[x]]=1,rt[1][a[y]]=1;
	}
}
void dfs(int x)
{
	dep[x]=dep[fa[x]]+1;
	for(int p=to[x].size()-1,j=0;j<=p;++j)
		dfs(to[x][j]);
}
int main()
{
//	freopen("party.in","r",stdin);
//	freopen("party.out","w",stdout);
//	 freopen("D:/LiuYuanHao/c.in","r",stdin);
	scanf("%d%d%d",&n,&m,&q);
	int flag=0;
	fo(i,2,n) 
	{
		scanf("%d",&fa[i]);
		if(fa[i]!=i-1)
			flag=1;
		to[fa[i]].push_back(i);
	}
	dfs(1);
	fo(i,1,n) scanf("%d",&a[i]);
	if(!flag) 
	{
		fo(i,1,q) printf("0\n");
		return 0;
	}
	while(q--)
	{
		int c;
		scanf("%d",&c);
		if(c==2)
		{
			memset(rt,0,sizeof rt);
			int x,y;
			scanf("%d%d",&x,&y);
			lca(x,y);
			int c[2],p=0;
			c[0]=c[1]=0;
			fo(i,1,1000)
			{
				if(!(rt[0][i]*rt[1][i])) 
					fo(l,0,1)if(rt[l][i]) ++c[l],rt[l][i]=0;
			}
			if(c[0]>c[1]) p=1;
			fo(i,1,1000)
			if(rt[0][i])
			{
				if(c[p]<c[p^1]) ++c[p];
				else ++c[p^1];
			}
			printf("%d\n",(c[0]+c[1]));
		}
		else 
		{
			int x;
			fo(i,1,c) scanf("%d",&x);
			printf("0\n");
		}
	}
	return 0;
}











