#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=110,P=N*N,M=P*4*2*2;
int tot=1;
int n,m,p;
int a[N][N];
int to[M],nex[M],f[M],las[P];
int d[P],c[P],cur[P];
int col(int x,int y){return((x+y)&1);}
int v(int x,int y){return((x-1)*m+y);}
int S,T,ans;
void link(int x,int y,int va,int vb)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot,f[tot]=va;
	to[++tot]=x,nex[tot]=las[y],las[y]=tot,f[tot]=vb;
}
int dfs(int x,int fw)
{
	if(x==T) return(fw);
	int cnt=0;
	for (int tp=cur[x];tp;tp=tp[nex])
	{
		cur[x]=tp;
		if(tp[f]>0&&d[tp[to]]+1==d[x])
		{
			int fp=dfs(tp[to],min(fw-cnt,tp[f]));
			f[tp]-=fp,f[tp^1]+=fp,cnt+=fp;
			if(cnt==fw)return(fw);
		}
	}	
	cur[x]=las[x];
	if(--c[d[x]]<=0) d[S]=T;
	c[++d[x]]++;
	return(cnt);
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&m);
	S=n*m+1,T=n*m+2;
	fo(i,1,n) fo(j,1,m)
	{
		scanf("%d",&a[i][j]);
		if(col(i,j)) link(S,v(i,j),a[i][j],0);
		else link(v(i,j),T,a[i][j],0);
		ans+=a[i][j];
	}
	fo(i,1,n) fo(j,1,m)
	{
		scanf("%d",&a[i][j]);
		if(!col(i,j)) link(S,v(i,j),a[i][j],0);
		else link(v(i,j),T,a[i][j],0);
		ans+=a[i][j];
	}
	fo(i,1,n) fo(j,1,m) scanf("%d",&a[i][j]);
	int cc=0;
	fo(i,1,n) fo(j,1,m)
	{
		int k=i+1,l=j+1;
//		cc+=a[i][j];
		if(k<=n) 
		{
			link(v(i,j),v(k,j),a[i][j]+a[k][j],a[i][j]+a[k][j]);
			cc+=a[i][j]+a[k][j];
		}
		if(l<=m) 
		{
			link(v(i,j),v(i,l),a[i][j]+a[i][l],a[i][j]+a[i][l]);
			cc+=a[i][j]+a[i][l];
		}
	}
	int cnt=0;
	c[0]=T;fo(i,1,T) cur[i]=las[i]; 
	while(d[S]<T) cnt+=dfs(S,oo);
	printf("%d\n",ans+cc-cnt);
	return 0;
}
































