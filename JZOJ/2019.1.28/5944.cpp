#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
#define fd(i,x,y) for(int i=(x);i>=(y);--i)
using namespace std;
typedef unsigned long long ull;
const int N=1000100,M=N*2;
const int p1=311,p2=19260817,p3=998244353;
int du[N],n;
int to[M],nex[M],las[N],tot;
void link(int x,int y)
{
	++du[y];
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
}
int rot,f[N];
int bz[N],sn[N];
void dfs(int x,int fa)
{
	int flag=0;
	for(int tp=las[x];tp;tp=tp[nex])
	if(to[tp]!=fa)
	{
		dfs(to[tp],x);
		sn[x]=to[tp];
		if(sn[x][bz]) flag=1;
		f[x]+=f[sn[x]];
	}
	if(du[x]==1||(du[x]==2&&sn[x][bz])) bz[x]=1;
	if(flag) --f[x];
	if(bz[x]) f[x]=1;
}
int main()
{
	freopen("beacon.in","r",stdin);
	freopen("beacon.out","w",stdout);
	// freopen("D:/LiuYuanHao/c.in","r",stdin);
	scanf("%d",&n);
		fo(i,1,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		link(x,y),link(y,x);
	}
	fo(i,1,n) 
		if(du[i]>=3)
		{
			rot=i;
			break;
		}
	if(rot==0)
	{
		printf("%d\n",!(n==1));
		return 0;
	}
	dfs(rot,0);
	printf("%d\n",f[rot]);
	return 0;

}









