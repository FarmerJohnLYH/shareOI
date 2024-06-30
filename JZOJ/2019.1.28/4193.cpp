#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=255,M=10010*2;
int n,m,k;
int c[N];
int to[M],las[N],nex[M],vl[M];
struct qury{
	int x,y,a;
}q[M];
int bz[N],tot;
void link(int x,int y,int v)
{
	to[++tot]=y,tot[nex]=las[x],las[x]=tot;
	vl[tot]=v;
}
int dt[N*100],d[N];
void solve(int st)
{
	memset(bz,0,sizeof bz);
	memset(d,127,sizeof d);
	bz[st]=1;d[st]=0;
	int hd=0,tl=1,tt,x;dt[1]=st;
	while(hd++<tl)
	{
		x=dt[hd];
		for (int tp=las[x];tp;tp=tp[nex])
		if(d[x]+tp[vl]<d[tt=tp[to]]&&c[tt]<=c[st])
		{
			d[tt]=d[x]+tp[vl];
			if(!bz[tt])
			{
				bz[tt]=1;
				dt[++tl]=tt;
			}
		}
		bz[x]=0;
	}
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.ans","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	fo(i,1,n)scanf("%d",&c[i]);
	fo(i,1,m)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		link(x,y,z),link(y,x,z);
	}
	fo(i,1,k)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		q[i].a=oo,q[i].x=x,q[i].y=y;
	}
	fo(i,1,n)
	{
		solve(i);
		fo(j,1,k)
		if(d[q[j].x]<oo&&d[q[j].y]<oo)
			q[j].a=min(q[j].a,c[i]+d[q[j].x]+d[q[j].y]);
	}
	fo(i,1,k)
		printf("%d\n",q[i].a);
	return 0;
}











