#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=10010,M=400400;
int n,m;
int to[M],nex[M],las[N],tot;
ll v[M];
void link(int x,int y,int va)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
	v[tot]=va;
}
ll ans;
int bz[N];
ll dis[N][2];int bp[N][2];
int d[10*N],hd,tl;
#define min(x,y) (((x)<(y))?(x):(y))
int update(int x,ll va,int f)
{
	int rt=0;
	if(va<dis[x][1]&&f!=bp[x][1]) 
	{
		rt=1;
		dis[x][0]=dis[x][1];
		bp[x][0]=bp[x][1];	
		bp[x][1]=f;
		dis[x][1]=va;
	}else 
	if(va<dis[x][0]&&f!=bp[x][0]) 
	{
		dis[x][0]=va,rt=1;
		bp[x][0]=f;	
	}
	return rt;
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	tot=1;ans=1ll<<60;
	scanf("%d%d",&n,&m);
	fo(i,1,m)
	{
		int x,y,va,vb;
		scanf("%d%d%d%d",&x,&y,&va,&vb);
		link(x,y,va),link(y,x,vb);
	}
	memset(dis,127/4,sizeof dis);
	dis[1][1]=0;
	hd=0,tl=0;
	for(int tp=las[1];tp;tp=tp[nex])
	{
		int qaq=0;
		fd(l,1,0) qaq|=update(to[tp],v[tp],tp);		
		if(qaq&&bz[to[tp]]) d[++tl]=to[tp],bz[to[tp]]=1;
	}
	hd=0;
	while(hd++<tl)
	{
		int x=d[hd];
		for(int tp=las[x];tp;tp=tp[nex])
		if(to[tp]!=1)
		{
			int qaq=0;
			fd(l,1,0)
				qaq|=update(to[tp],dis[x][l]+v[tp],bp[x][l]);
			if(qaq&&!bz[to[tp]]) d[++tl]=to[tp],bz[to[tp]]=1;
		}
		bz[x]=0;
	}
	for(int tp=las[1];tp;tp=tp[nex])
	{
		int i=to[tp];
		if(dis[i][1]==v[tp])
			ans=min(ans,dis[i][0]+v[tp]);
		else ans=min(ans,dis[i][1]+v[tp]);
	}
	printf("%lld\n",ans);
	return 0;
}








