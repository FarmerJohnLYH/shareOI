#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=222,M=N*N*2,E=M*4*2;
int co[N][N],va[N][N],n,m;
char s[N][N];int all;
int fx[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int c(int x,int y){return(x^y)&1;}
int h(int x,int y){return(x-1)*m+y;}
int check(int x,int y)
{
	return(1<=x&&x<=n&&1<=y&&y<=m);
}
struct network{
	int tot;
	int S,T;
	int to[E],nex[E],v[E],las[M];
	void link(int x,int y,int vl)
	{
		if(v==0)return;
		to[++tot]=y,nex[tot]=las[x],las[x]=tot,v[tot]=vl;
		to[++tot]=x,nex[tot]=las[y],las[y]=tot,v[tot]=0;
	}
	void prework()
	{
		tot=1;
		S=n*m*2+1,T=S+1;
		fo(i,1,n)fo(j,1,m)
		if(c(i,j))
		{
			int x=h(i,j),xx=x+n*m;
			link(x,xx,va[i][j]),link(S,x,co[i][j]);
			fo(l,0,3)
			if(check(i+fx[l][0],j+fx[l][1]))
			{
				int y=h(i+fx[l][0],j+fx[l][1]),yy=y+n*m;
				link(x,y,oo),link(xx,yy,oo);
			}
		}
		else
		{
			int x=h(i,j),xx=x+n*m;
			link(x,xx,va[i][j]),link(xx,T,co[i][j]);
		}
	}
	int dep[M],g[M];
	int dfs(int x,int fw)
	{
		if(x==T)return(fw);
		int rt=0;
		for(int tp=las[x],tt=tp[to];tp;tp=tp[nex],tt=tp[to])
		if(tp[v]>0&&dep[tt]==dep[x]-1)
		{
			int fwt=dfs(tt,min(tp[v],fw-rt));
			tp[v]-=fwt,v[tp^1]+=fwt,rt+=fwt;
			if(rt==fw)return(fw);
		}
		if((--g[dep[x]++])==0)dep[S]=T;
		++g[dep[x]];
		return rt;
	}
	int solve()
	{
		int rt=0;
		memset(dep,0,sizeof dep);
		memset(g,0,sizeof g);
		g[0]=T;
		while(dep[S]<T) rt+=dfs(S,oo);
		return rt;
	}
}nt;
int main()
{
	freopen("D:/LiuYuanHao/a4.in","r",stdin);
	scanf("%d%d",&n,&m);
	fo(i,1,n) 
	{
		scanf("%s",s[i]+1);
		fo(j,1,m) 
		{
			co[i][j]=s[i][j];
			if(s[i][j]>='a'&&s[i][j]<='z')co[i][j]-='a'-10;
			else if(s[i][j]>='A'&&s[i][j]<='Z')co[i][j]-='A'-36;
			else co[i][j]-='0';
		}
	}	
	fo(i,1,n) 
	{
		scanf("%s",s[i]+1);
		fo(j,1,m) 
		{
			va[i][j]=s[i][j];
			if(s[i][j]>='a'&&s[i][j]<='z')va[i][j]-='a'-10;
			else if(s[i][j]>='A'&&s[i][j]<='Z')va[i][j]-='A'-36;
			else va[i][j]-='0';
			all+=va[i][j];
		}
	}
	nt.prework();
	int tmp=0;
	printf("%d\n",all-(tmp=nt.solve()));
	return 0;
}











