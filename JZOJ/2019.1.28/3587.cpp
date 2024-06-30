#include <queue>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define se second
#define fi first
#define fo(i,x,y) for (int pq = (y),i = (x);i <= pq;++ i)
#define fd(i,x,y) for (int pq = (y),i = (x);i >= pq;-- i)
#define oo 2139062143
using namespace std;
typedef double db;
typedef long long ll;
int lowbit(int x) {return((x)&(-x));}
int min(int x,int y){return (x>y)?(y):(x);}
int max(int x,int y){return (x>y)?(x):(y);}
const int N=10010,M=100100,C=100000000;
typedef pair<int,int> PI;
int n,m;
int f[N];
struct edge{
	int y,a;
	int nex;
}e[M*2];
int bz[N];
int tot,las[N];
priority_queue<PI>q;
void link(int x,int y,int a)
{
	e[++tot].y=y,e[tot].a=a,e[tot].nex=las[x];
	las[x]=tot;
}
int main()
{
	freopen("D:/LiuYuanHao/a1.in","r",stdin);
	scanf("%d%d",&n,&m);
	fo(i,1,n)
	{
		scanf("%d",&f[i]);
		q.push(make_pair(-f[i],i));
	}
	fo(i,1,m)
	{
		int a,x,y;
		scanf("%d%d%d",&a,&x,&y);
		link(x,y,a);
		link(y,x,a);
	}
	while(!bz[1])
	{
		PI top=q.top();
		q.pop();
		if(bz[top.se]) continue;
		bz[top.se]=1;
		for (int tmp=las[top.se];tmp;tmp=e[tmp].nex)
		{
			int y=e[tmp].y,a=e[tmp].a,x=top.se;
			if(f[a]>f[x]+f[y])
			{
				f[a]=f[x]+f[y];
				q.push(make_pair(-f[a],a));
			}
		}
	}
	printf("%d\n",f[1]);
	return 0;
}













