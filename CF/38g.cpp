#pragma GCC optimize(2) 
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=100100;
int n,a[N],c[N];
int sn[N][2],fa[N];
int v[N],va[N],sz[N];
int tot,rt;
int find(int t)
{
	int x=rt;
	while(1)
	{
		if(t>sn[x][0][sz]+1) t-=sn[x][0][sz]+1,x=sn[x][1]; 
		else if(t==sn[x][0][sz]+1) return x;
		else x=sn[x][0];
	}
	return -1;
}
int gl(int x)
{
	return(sn[fa[x]][1]==x);
}
void udt(int x)
{
	v[x]=va[x];sz[x]=1;
	fo(i,0,1) if(sn[x][i])
		v[x]=max(v[x],sn[x][i][v]),sz[x]+=sn[x][i][sz];
}
void rtt(int x)
{
	int y=fa[x],p=gl(x);
	sn[fa[y]][gl(y)]=x,fa[x]=fa[y];
	sn[y][p]=sn[x][p^1];if(sn[x][p^1]) sn[x][p^1][fa]=y;
	sn[x][p^1]=y;fa[y]=x;
	udt(y);
}
void mkrt(int x,int f)
{
	while(fa[x]!=f)
	{
		if(fa[x][fa]!=f)
		{
			if(gl(fa[x])==gl(x)) rtt(fa[x]);
			else rtt(x);
		}
		rtt(x);
	}
	udt(x);
	if(f==0) rt=x;
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d",&n);
	v[rt=1]=oo;tot=1;sz[1]=1;
	fo(i,1,n) 
	{
		scanf("%d%d",&a[i],&c[i]);
		c[i]=min(c[i],i-1);
		int le=1,ri=c[i],fv=0;
		while(le<=ri)
		{
			int mid=(le+ri)>>1,x=find(tot-mid);
			mkrt(x,0);//取c[i]=mid是否合法
			if((!sn[x][1])||sn[x][1][v]<a[i]) fv=mid,le=mid+1;
			else ri=mid-1;
		}
 		mkrt(find(tot-fv),0);
		if(sn[rt][1]) mkrt(find(tot-fv+1),rt),sn[sn[rt][1]][0]=++tot,va[tot]=v[tot]=a[i],fa[tot]=sn[rt][1],mkrt(tot,0);
		else sn[rt][1]=++tot,va[tot]=v[tot]=a[i],fa[tot]=rt,mkrt(tot,0); 
	}
	fo(i,1,n) printf("%d ",find(i+1)-1);
	printf("\n");
	return 0;
}








