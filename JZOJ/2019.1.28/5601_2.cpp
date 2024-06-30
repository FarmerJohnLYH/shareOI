#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=55000,Q=N*2;
int n,q;
int to[N*8],nex[N*8],las[N],la2[N];
int tot;
struct qry{
	int id,x,y,z;
	qry(int x_=0,int y_=0,int z_=0int id_=0)
};
vector<qry> a,c,g;
void link(int x,int y,int *las)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
}
int deg[N],d[N],d0,bz[N];
#define tt to[tp]
void init()
{
	fo(i,1,n) if(deg[i]==2)
		d[++d0]=i;
	fo(i,1,d0)
	{
		int x=d[i],a[3],a0=0;bz[x]=1;
		for(int tp=las[x];tp;tp=tp[nex])
		if(!bz[tt])
		{
			if(--deg[tt] == 2) d[++d0]=tt;
			a[++a0]=tt;
		}	
		g.push_back(qry(x,a[1],a[2]));
	}
	for(int p=g.size(),i=0;i<=p;++i)
	{
		qry q=g[i];
		
	}
}
int main()
{
	freopen("D:/LiuYuanHao/","r",stdin);
	scanf("%d",&n);
	fo(i,1,n-1) link(i,i+1,las),link(i+1,i,las),deg[i]=2;
	deg[n]=2;link(1,n,las),link(n,1,las);
	fo(i,1,n-3)
	{
		scanf("%d%d",&x,&y);
		link(x,y,las),link(y,x,las);
		++deg[x],++deg[y];
	}
	init();
	return 0;
}








