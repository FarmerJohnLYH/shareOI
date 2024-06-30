//此做法有误 不能直接通过更换数字代表顺序直接搜索
//因为可能出现第i层集合相同而重复统计 
//以上  
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 213906214
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=111,M=N*N;
int a[N],n;
int ans=0;
int mnw,mxw;
int dep[N],to[N][N];
int	c[N][N];
int p[7270][N],p0;
struct network{
	int S,T,tot,n;
	int to[M],nex[M],las[N],f[M];
	int dep[N],c[N];
	void link(int x,int y,int v1,int v2)
	{
		to[++tot]=y,nex[tot]=las[x],las[x]=tot,f[tot]=v1;
		to[++tot]=x,nex[tot]=las[y],las[y]=tot,f[tot]=v2;
	}
	void clear()
	{
		tot=1;
		memset(las,0,sizeof las);
		memset(dep,0,sizeof dep);
	}
	int dfs(int x,int fl)
	{
		if(x==T)return(fl);
		int rt=0;
		for (int tp=las[x];tp;tp=tp[nex])
		if(f[tp]>0&&dep[tp[to]]==dep[x]-1)
		{
			int tt=tp[to],r=dfs(tt,min(f[tp],fl-rt));
			f[tot]-=r,f[tot^1]+=r,rt+=r;
			if(rt==fl)return(fl);
		}
		if(!(--c[dep[x]++])) dep[S]=n+1;
		++c[dep[x]];
		return rt;
	}
	int solve()
	{
		int rt=0;c[0]=n;
		while(dep[S]<n+1)rt+=dfs(S,oo);
		return rt;
	}
}nt;
int d[N][N],tt[N][N];
int check(int co,int md)
{
	fo(i,1,md) 
	{
		fo(j,1,c[i][0]) d[i][j]=p[co][c[i][j]];
		d[i][0]=c[i][0];
	}
	fo(i,2,md)
	{
		int cnt=0;
		nt.clear();
		nt.S=n+1,nt.T=n+2;nt.n=n+2;
		fo(l,1,d[i][0])
			fo(j,1,to[c[i][l]][0])
				nt.link(d[i][l],p[co][to[c[i][l]][j]],oo,oo);
		fo(j,1,d[i][0]) nt.link(nt.S,d[i][j],a[d[i][j]],0),cnt+=a[d[i][j]];
		fo(j,1,d[i-1][0]) nt.link(d[i-1][j],nt.T,a[d[i-1][j]],0);
		if(nt.solve()<cnt) return 0;
	}
	return 1;
}
int cnt;
int sta[N],du[N];
void gtw(int x,int s)
{
	if(x>n) 
	{
		++cnt;
		return;
	}
	fo(i,1,n)
	if((!(((1<<(i-1))&s)))&&du[i]==0)
	{
		fo(j,1,to[i][0]) --du[to[i][j]];
		gtw(x+1,s|(1<<(i-1))); 
		fo(j,1,to[i][0]) ++du[to[i][j]];
	}
}
int pd(int x,int md)
{
	fo(i,1,md)
	{
		fo(j,2,c[i][0])
		if(p[x][c[i][j]]!=p[x][c[i][j-1]]+1) return 1;
	}
	return 0;
}
void dfs(int x,int d)
{
	if(x>n) 
	{
		if(!c[d][0]&&d!=2) return;
		cnt=0;
		gtw(1,0);	
		int tmp=0;
		if((cnt>=mnw&&cnt<=mxw))	
		fo(i,1,p0)
		{
			if(pd(i,d)) continue;
			if(check(i,d))
				++tmp;
		}
		ans+=tmp;
		return;
	}
	fo(i,1,(1<<(c[d-1][0]-1)))
	{
		fo(l,1,x-1)
		if((1<<(l-1))&i)
			to[x][++to[x][0]]=c[d-1][l],++du[c[d-1][l]];
		c[d][++c[d][0]]=x;
		dfs(x+1,d);
		dfs(x+1,d+1);
		--c[d][0];
		fo(l,1,x-1)
		if((1<<(l-1))&i) --du[c[d-1][l]];
		to[x][0]=0;
	}
}
int st[N];
void init(int x,int s)
{
	if(x>n)
	{
		++p0;
		fo(i,1,n) p[p0][i]=st[i];
		return;
	}
	fo(i,1,n)
	if(!((1<<(i-1))&s)) 
	{
		st[x]=i;
		init(x+1,s|(1<<(i-1)));
		st[x]=0;
	}
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d",&n);
	fo(i,1,n) scanf("%d",&a[i]);
	scanf("%d%d",&mnw,&mxw);
	init(1,0);
	for(c[1][0]=1;c[1][0]<=n;c[1][0]++)
	{
		c[1][c[1][0]]=c[1][0];
		dfs(c[1][0]+1,2);
	}
	printf("%d\n",ans);
	return 0;
}











