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
const int N=100100;
struct edge{
	int to,nex;
}e[N*8],e2[N*8]/*反*/;
int las[N],las2[N],tot,tot2;
int b[N],arr[N];
int n,m,T;
void link(int x,int y)
{
	e[++ tot].to=y,e[tot].nex=las[x];
	las[x]=tot;
}
void link2(int x,int y)
{
	e2[++ tot2].to=y,e2[tot2].nex=las2[x];
	las2[x]=tot2;
}
void bfs(int sta)
{
	
}
int main()
{
	freopen("D:/LiuYuanHao/","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		memset(las,0,sizeof las);
		memset(las2,0,sizeof las2);
		tot=tot2=0;
		scanf("%d%d", &n, &m);
		fo(i,1,n) b[i]=i;
		fo(i,1,m)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			b[++x]=++y;
		}
		fo(i,1,n)
		{
			fo(l,1,6)
			{
				link(i,b[i+l]);
				link2(b[i+l],i);
			}
		}
		bfs(1);
	}
	return 0;
}
