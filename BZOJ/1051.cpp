#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (int pq = (y),i = (x);i <= pq;++ i)
#define fd(i,x,y) for (int pq = (y),i = (x);i >= pq;-- i)
#define oo 2139062143
using namespace std;
typedef double db;
typedef long long ll;
int lowbit(int x) {return((x)&(-x));}
int min(int x,int y){return (x>y)?(y):(x);}
int max(int x,int y){return (x>y)?(x):(y);}
const int N=10100,M=50050;
int n,m;
int dfn[N],low[N];
struct edge{
	int to,nex,
}e[M];
int tot;
void link(int x,int y)
{
	e[++ tot].to=y,e[tot].nex=las[x];
	las[x]=tot;
}
int main()
{
	freopen("D:/LiuYuanHao/","r",stdin);
	scanf("%d%d",&n,&m);
	fo(i,1,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		link(x,y); 
	}
	dfs();
	return 0;
}
