#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=20020,E=40400*4;
int a[110][110];
int S,T;
int n,m;
int w(int x,int y)
{
	return((x-1)*m+y);
}
int tot=1;
int to[E],fw[E],nex[E];
int lev[N];
int las[N],mem[N]/*memory*/;
void link(int x,int y,int v)
{
	to[++tot]=y,nex[tot]=las[x],fw[tot]=v;las[x]=tot;
	to[++tot]=x,nex[tot]=las[y],fw[tot]=0;las[y]=tot;
}
int dt[N];
bool bfs()
{
    memset(lev,255,sizeof lev);
	mem[S]=las[S],mem[T]=las[T];
	fo(i,1,w(n,m)) lev[i]=-1,mem[i]=las[i];
    lev[S]=0,dt[1]=S;
    int hd=0,tl=1;
    while(hd++<tl)
    {
        int x=dt[hd];
        for (int tp=las[x];tp;tp=tp[nex])
        if(fw[tp]>0&&lev[to[tp]]==-1)
        {
        	lev[tp[to]]=lev[x]+1;
        	dt[++tl]=to[tp];
        }
    }
    return(lev[T]!=-1);
}
int dfs(int x,int fwt)
{
    if (x==T) return fwt;
    int cst=0;
    for (int tp=mem[x];tp;tp=tp[nex])
    {
    	mem[x]=tp;
    	if(fw[tp]>0&&lev[tp[to]]==lev[x]+1)
    	{
    		int cnt=dfs(tp[to],min(fw[tp],fwt-cst));
    		cst+=cnt,fw[tp]-=cnt,fw[tp^1]+=cnt;
    		if(fwt==cst) return(fwt);
    	}
    }
    return(cst);
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&m);
	S=10101,T=10201;
	fo(i,1,n)
	{
		fo(j,1,m) 
		{
			scanf("%d",&a[i][j]);
				 if(a[i][j]==1) link(S,w(i,j),E);
			else if(a[i][j]==2) link(w(i,j),T,E);
		}
	}
	fo(i,1,n) fo(j,1,m) 
	{ 
		if(i+1<=n)link(w(i+1,j),w(i,j),1),link(w(i,j),w(i+1,j),1);
		if(j+1<=m)link(w(i,j+1),w(i,j),1),link(w(i,j),w(i,j+1),1);
	}
	int ans=0;
	++n,++m;
    for(;bfs();)
        ans+=dfs(S,oo);
    printf("%d\n",ans);
	return 0;
}



