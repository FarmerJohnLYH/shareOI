#include <cmath>
#include <ctime>
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
const int N=100100,M=100100;
struct node
{
    int to,nex,fw;
}e[M*2];
int lev[N];
int las[N],mem[N];
int n,m,tot,s,t;
void link(int u,int v,int c)
{
    e[++tot].to=v,e[tot].nex=las[u],e[tot].fw=c;
    las[u]=tot;
    e[++tot].to=u,e[tot].nex=las[v],e[tot].fw=0;
    las[v]=tot;
}
int q[N];
bool bfs()
{
    fo(i,1,n) lev[i]=-1,mem[i]=las[i];
    lev[s]=0,q[1]=s;
    int hd=0,tl=1;
    while(hd++<tl)
    {
        int now=q[hd];
        for(int tmp=las[now];tmp;tmp=e[tmp].nex)
            if(e[tmp].fw>0&&lev[e[tmp].to]==-1)
            {
                lev[e[tmp].to]=lev[now]+1;
                q[++tl]=e[tmp].to;
            }
    }
    return(lev[t]!=-1);
}
int dfs(int now,int fw)
{
    if (now==t) return fw;
    int cst=0;
    for(int tmp=mem[now];tmp;tmp=e[tmp].nex)
    {
        mem[now]=tmp;
        if (e[tmp].fw>0&&lev[e[tmp].to]==lev[now]+1)
        {
            int fwt=dfs(e[tmp].to,min(e[tmp].fw,fw - cst));
            cst+=fwt,e[tmp].fw-=fwt,e[tmp^1].fw+=fwt;
            if(fw==cst) return cst;
        }
    }
    return cst;
}
int main()
{
//	freopen("D:/LiuYuanHao/c.in","r",stdin);
	freopen("connection.in","r",stdin);
	freopen("connection.out","w",stdout);
    tot=1;
    scanf("%d%d", &n, &m);
    s=1;
    fo(i,1,m)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        link(u,v,1);
        link(v,u,1);
    }
    int rt=oo;
    for (t=1;t<=n;++t)
    if(s!=t)
    {
    	int ans=0;
		fo(i,1,tot/2) e[i<<1].fw=1,e[(i<<1)^1].fw=0;
	    for(;bfs();)
			ans+=dfs(s,oo);
    	rt=min(rt,ans);
    }
    printf("%d",rt);
    return 0;
}
