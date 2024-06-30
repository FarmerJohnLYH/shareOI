#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=20020,M=100100*4;
int n,m,du[N];
int c[M],to[M],nex[M],las[N],tot;
int v[N],v2[N];
void link(int x,int y,int d)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
	c[tot]=d;
}
int p;
struct node{
	int x,y,c;
}a[M];
bool cmp(node a,node b)
{
	return(a.x<b.x || (a.x==b.x&&a.y<b.y) || (a.x==b.x && a.x==b.y && a.c<b.c));
}
int d[N];
int main()
{
//	freopen("D:/LiuYuanHao/a1.in","r",stdin);
//	freopen("D:/LiuYuanHao/a1.ans","w",stdout);
	scanf("%d%d",&n,&m);
	fo(i,1,m)
	{
		int x,y,c;scanf("%d%d%d",&x,&y,&c);
		a[i].x=x,a[i].y=y,a[i].c=c;
	}
	sort(a+1,a+1+m,cmp);
	int a0=0;
	fo(i,1,m)
	if(a[i].x!=a[i-1].x || a[i].y!=a[i-1].y)
	{
		int x=a[i].x,y=a[i].y,c=a[i].c;
		link(x,y,c),link(y+n,x,c);
		++du[y];++d[x];
		a[++a0]=a[i];
	}
	m=a0;
	int ans=oo;
	fo(i,1,m)
	{
		fo(j,1,n) v[j]=oo,v2[j]=oo;
		int x=a[i].x,y;
		fo(j,i,m) if(a[j].x!=x) break;	
		else v[a[j].y]=a[j].c,i=j;
		p=0;
		fo(j,1,n)
			if((v[j]==oo && du[p]>du[j])) p=j;		
		if(!p)
		{
			p=1;
			fo(j,1,n) if(v[j]>v[p]) p=j;
		} 
		for(int tp=las[p+n];tp;tp=tp[nex])
		{
			y=to[tp];
			if(d[x]+d[y]<n) continue;
			for(int t2=las[y];t2;t2=t2[nex])			
				v2[to[t2]]=c[t2];
			int tmp=0;
			fo(j,1,n) tmp=max(tmp,min(v2[j],v[j]));
			ans=min(ans,tmp);
			for(int t2=las[y];t2;t2=t2[nex])			
				v2[to[t2]]=oo;
		}
	}
	ans==oo?printf("No solution\n"):printf("%d\n",ans);
	return 0;
}








