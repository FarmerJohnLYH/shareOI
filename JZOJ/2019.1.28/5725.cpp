#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define sqr(x) ((x)*(x))
#define fi first
#define se second 
using namespace std;
typedef pair<int,int> PI;
const int N=440,M=N*N;
int n,m;
int x[N],y[N];
int f[N];
struct node{
	int x,y,c;
}a[M];
int tot;
PI ans[N];
int gf(int x)
{
	return((f[x]==x)?(x):(f[x]=gf(f[x])));
}
void mst()
{
	fo(i,1,n) f[i]=i;
	fo(i,1,m)	
	{
		int x=a[i].x,y=a[i].y,fx,fy;
		if((fx=gf(x))!=(fy=gf(y)))
		{
			f[fx]=fy;
			ans[++tot].fi=x,ans[tot].se=y;
		}
	}
}
bool cmp(node a,node b)
{
	return(a.c<b.c);
}
int main()
{
	freopen("chaw.in","r",stdin);
	freopen("chaw.out","w",stdout);
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	while(scanf("%d",&n)!=EOF)
	{
		tot=m=0;
		fo(i,1,n)
		{
			scanf("%d%d",&x[i],&y[i]);
			fo(j,1,i-1) a[++m].x=i,a[m].y=j,a[m].c=sqr(x[i]-x[j])+sqr(y[i]-y[j]);
		}
		sort(a+1,a+1+m,cmp);
		mst();
		fo(i,1,n-1) printf("%d %d\n",ans[i].fi,ans[i].se);
	}
	return 0;
}











