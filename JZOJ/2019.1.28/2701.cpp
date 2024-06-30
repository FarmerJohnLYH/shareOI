#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=40040,M=3*2*2*N;
int n,m,cnt; 
int le,ri,mid;
int L,R;
int a[220][220];
int tot,to[M],nex[M],las[N],v[M],bz[M];
int s,t,ss,tt;
inline int min(int x,int y){return(x<y?x:y);}
inline int max(int x,int y){return(x>y?x:y);}
void link(int x,int y,int va,int vb,int b)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;v[tot]=va;bz[tot]=b;
	to[++tot]=x,nex[tot]=las[y],las[y]=tot;v[tot]=vb;bz[tot]=0;
}
void edge(int x,int y,int l,int r)
{
	link(ss,y,l,0,1);
	link(x,tt,l,0,1);
	link(x,y,r-l,0,2);
}
inline int p(int x){return(x);}
inline int q(int x){return(x+n);}
int U[N],V[N],d[N],g[N];
int dfs(int x,int qv)
{
	if(x==tt) return qv;
	int nw=0;
	for(int tp=las[x];tp;tp=tp[nex])
	if(v[tp]>0 && d[to[tp]]+1==d[x])
	{
		int tmp=dfs(to[tp],min(v[tp],qv-nw));
		nw+=tmp,v[tp]-=tmp,v[tp^1]+=tmp;
		if(qv==nw) return qv;
	}
	--g[d[x]],++d[x],++g[d[x]];
	if(g[d[x]-1]==0) d[ss]=cnt;
	return nw;
}
int an[330][330];
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&m);
	ri=oo;
	fo(i,1,n) 
	{
		int sum=0;
		fo(j,1,m)
			scanf("%d",&a[i][j]),sum+=a[i][j];
		U[i]=sum;
		ri=min(ri,sum);
	}
	fo(j,1,m) 
	{
		int sum=0;
		fo(i,1,n)
			sum+=a[i][j];
		V[j]=sum;
		ri=min(ri,sum);
	}
	scanf("%d%d",&L,&R);
	cnt=n+m+4;s=n+m+1,t=n+m+2,ss=n+m+3,tt=n+m+4;
	int ans=ri;
	while(le<=ri)
	{
		mid=(le+ri)>>1;
		tot=1;
		fo(i,1,cnt+4) las[i]=0;
		fo(i,1,n) fo(j,1,m)
			edge(p(i),q(j),L,R);
		fo(i,1,n) edge(s,p(i),max(U[i]-mid,0),U[i]+mid);
		fo(j,1,m) edge(q(j),t,max(V[j]-mid,0),V[j]+mid);
		link(t,s,oo,0,0);
		fo(i,1,cnt+4) d[i]=0,g[i]=0;
		int sum=0;
		g[0]=cnt;
		while(d[ss]<cnt) sum+=dfs(ss,oo);
		int flag=1;
		fo(i,2,tot)
			if(bz[i]==1 && v[i]!=0) 
			{
				flag=0;
				break;
			}	
		if(flag) 
		{
			ans=mid,ri=mid-1;
			fo(i,2,tot)
			if(bz[i]==0&&to[i]>=1&&to[i]<=n&&to[i^1]>=n+1&&to[i^1]<=n+m)
				an[to[i]][to[i^1]-n]=v[i]+L;
		}
		else le=mid+1;
	}
	printf("%d\n",ans);
	fo(i,1,n) 
	{
		fo(j,1,m)
			printf("%d ",an[i][j]);
		puts("");
	}
	return 0;
}








