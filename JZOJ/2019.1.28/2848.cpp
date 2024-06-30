#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=220*4,K=22,P=N*2,M=P*P*2;
int n,m,k,en;
int tm[N][N],cs[N][N];
int q[N][5];
int S,T,s;
int tot,ans;
int vis[P],d[P*10],dis[P],pre[N];
int to[M],nex[M],las[M],cst[M],fw[M];
void link(int x,int y,int v,int vv)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot,cst[tot]=vv,fw[tot]=v;
	to[++tot]=x,nex[tot]=las[y],las[y]=tot,cst[tot]=-vv,fw[tot]=0;
}
int spfa()
{
	memset(dis,128,sizeof dis);
	memset(vis,0,sizeof vis);
	memset(pre,0,sizeof pre);
	vis[S]=1;d[1]=S;dis[S]=0;
	int hd=0,tl=1;
	while(hd<tl)
	{
		int x=d[++hd];
		for (int tp=las[x];tp;tp=tp[nex])
		if(fw[tp]>0)
		{
			int tt=to[tp];
			if(dis[x]+tp[cst]>dis[tt])
			{
				dis[tt]=dis[x]+tp[cst];
				pre[tt]=(tp^1);
				if(!vis[tt])
				{
					vis[tt]=1;
					d[++tl]=tt;
				}
			}
		}
		vis[x]=0;
	}
	if(dis[T]<=-oo) return(0);
	int x=T,tp=oo;
//	sum=0;
	while(x!=S)
	{
		tp=min(tp,fw[pre[x]^1]);
		x=pre[x][to];
	}
	x=T;
	while(x!=S)
	{
//		if(fw[pre[x]^1]==tp&&fw[pre[x]^1]) sum+=cst[pre[x]^1];
		fw[pre[x]^1]-=tp;
		fw[pre[x]]+=tp;
		x=pre[x][to];
	} 
	ans+=dis[T]*tp;
	return 1;
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	tot=1;
	scanf("%d%d%d%d",&n,&m,&k,&en);
	fo(i,1,n) fo(j,1,n) scanf("%d",&tm[i][j]);
	fo(i,1,n) fo(j,1,n) scanf("%d",&cs[i][j]);
	fo(i,1,m) scanf("%d%d%d%d%d",&q[i][1],&q[i][2],&q[i][3],&q[i][4],&q[i][0]),++q[i][1],++q[i][2];
	S=m*2+1,T=m*2+2,s=m*2+3;
	link(S,s,k,0);
	fo(i,1,m) 
	{
		if(tm[1][q[i][1]]<=q[i][3]) 
		{
			link(s,i,1,q[i][0]-cs[1][q[i][1]]);
			if(tm[q[i][2]][1]+q[i][4]<=en) link(i+m,T,1,-cs[q[i][2]][1]);
		}
		link(i,i+m,1,0);	
	}
	fo(i,1,m) fo(j,1,m)
	if(i!=j&&q[i][4]+tm[q[i][2]][q[j][1]]<=q[j][3])
		link(i+m,j,1,q[j][0]-cs[q[i][2]][q[j][1]]);
	while(spfa());
	printf("%d\n",ans);
	return 0;
}











