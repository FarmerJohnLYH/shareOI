#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=300300;
int n,m;
int w[N],fa[N];
int to[N],nex[N],las[N],pre[N];
int dep[N],bc[N];
void mk(int x,int f)
{
	dep[x]=dep[f]+1;
	mk(fa[x],x);
	for(int tp=las[x];tp;tp=tp[nex])
	if(to[tp]!=f)
		mk(to[tp],x);
	fa[x]=f;
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&m);
	fo(i,1,n) scanf("%d",&w[i]);
	while(m--)
	{
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if(op==1)
		{
			if(gb(x)==gb(y))gtc(x,y);
			else
			if(fa[x]==0) fa[x]=y,dep[x]=dep[y]+1;
			else
			{
				if(fa[y]!=0) mk(y,x);
				fa[y]=x;
			}
		}
		else
		if(op==2)
		{
			v[top[x]]+=y-w[x];
			w[x]=y;
		}
		else
		{
			int d=lca(a,b);
			printf("%d\n",d);
		}
	}
	return 0;
}











