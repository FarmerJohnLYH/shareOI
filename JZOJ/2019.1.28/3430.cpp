#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=1010,M=500500;
int n,m,e,p,l,K;
int a[N][N],b[N][N],c[N][N],dis[N];
int nex[M],las[M],to[M],v[M];
int de[M*11],d[M*11][2],tot=0;
int vis[N];
int f[N][44],bz[N][N];
void link(int x,int y,int z)
{
	nex[++tot]=las[x],las[x]=tot,to[tot]=y;
	v[tot]=z;
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d%d%d%d%d",&n,&m,&e,&p,&l,&K);
	memset(a,127,sizeof a);
	fo(i,1,e)
	{
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		z=min(z,a[x][y]);
		c[x][y]=c[y][x]=a[x][y]=a[y][x]=z;
	}
	fo(i,1,p)
	{
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		link(x-1,y,z);
	}
	fo(i,1,n) link(i-1,i,0),link(i,i-1,-1);

	int hd=0,tl=1;de[1]=0;
	memset(dis,128,sizeof dis);
	vis[0]=1,dis[0]=0;
	while(hd<tl)
	{
		int x=de[++hd];
		for(int k=las[x];k;k=nex[k])
			if(dis[to[k]]<dis[x]+v[k])
			{
				dis[to[k]]=dis[x]+v[k];
				if(vis[to[k]]==0)
				{
					de[++tl]=to[k];
					vis[to[k]]=1;
				}
			}
		vis[x]=0;
	}
	fd(i,n,0) dis[i]=dis[i]-dis[i-1];
	fo(k,1,n)if(dis[k]!=1)
	fo(i,1,n) fo(j,1,n)
	if(i!=k&&i!=j&&j!=k)
	if(a[i][k]<oo&&a[k][j]<oo)
		a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	d[1][0]=1,d[1][1]=0;
	memset(f,127,sizeof f);
	f[1][0]=0,bz[1][0]=1;
	hd=0,tl=1;
	while(hd<tl)
	{
		int x=d[++hd][0],tt=d[hd][1];
		fo(y,1,n)
		{
			if(c[x][y]>0&&f[x][tt]<oo&&f[y][tt]>f[x][tt]+c[x][y])
			{
				f[y][tt]=f[x][tt]+c[x][y];
				if (bz[y][tt]==0)
					d[++tl][0]=y,d[tl][1]=tt,bz[y][tt]=1;
			}
			if(tt<K&&a[x][y]<=l&&f[y][tt+1]>f[x][tt])
			{
				f[y][tt+1]=f[x][tt];
				if(bz[y][tt+1]==0)
					d[++tl][0]=y,d[tl][1]=tt+1,bz[y][d[tl][1]]=1;
			}
		}
		bz[x][tt]=0;
	}
	int ans=oo;
	fo(i,0,K) ans=min(ans,f[n][i]);
	printf("%d\n",ans);
}
