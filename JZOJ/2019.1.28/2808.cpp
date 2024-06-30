#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=200200,P=500500;
int n,q,m,tot;
int f[N];
struct node{
	int sn[2],v,sz;
}a[N];
int fa[N],sz[N];
int gl(int x){return(x==a[fa[x]].sn[1]);}
int abs(int x){return(x>=0)?x:(-x);}
int gf(int x)
{
	return(f[x]==x)?x:(f[x]=gf(f[x]));
}
void update(int x)
{
	a[x].sz=(x<=n);
	fo(l,0,1)if(a[x].sn[l]) 
		a[x].sz+=a[a[x].sn[l]].sz;
}
void rotate(int x)
{
	int y=fa[x],f=fa[y],p=gl(x);
	a[f].sn[gl(y)]=x;fa[x]=f;
	fa[y]=x;
	a[y].sn[p]=a[x].sn[!p];if(a[x].sn[!p])a[x].sn[!p][fa]=y;
	a[x].sn[!p]=y;
	update(y);
}
void mkrt(int x,int f)
{
	while(fa[x]!=f)
	{
		if(fa[x][fa]!=f) 
		{
			if(gl(x)==gl(fa[x])) rotate(fa[x]);
			else rotate(x);
		}
		rotate(x);
	}
	update(x),update(f);
}
void ins(int x,int fat)
{
	int f=0,p=fat;
	while(p) 
		f=p,p=a[p].sn[a[x].v>a[p].v];
	p=x;fa[x]=f;a[f].sn[a[x].v>a[f].v]=x;
	update(x);
	mkrt(x,fat[fa]);
}
void run(int x,int y)
{
	fo(l,0,1)
		if(a[x].sn[l]) run(a[x].sn[l],y);
	ins(x,y);
}
int pos[N];
int fth(int x,int v)
{
	if(a[x].sn[0]&&a[a[x].sn[0]].sz>=v) return fth(a[x].sn[0],v);
	if((a[x].sn[0]&&a[a[x].sn[0]].sz==v-1)||(!a[x].sn[0]&&v==1)) 
		return x;
	return(fth(a[x].sn[1],v-(a[x].sn[0]?a[a[x].sn[0]].sz:0)-1));
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&m);
	fo(i,1,n)
	{
		scanf("%d",&a[i].v);
		fa[i]=n+i;
		a[i].sz=a[n+i].sz=1;
		a[n+i].sn[0]=i;
		a[i].v[pos]=i;
		f[i]=i; 
	}
	fo(i,1,m)
	{
		int x,y;  
		scanf("%d%d",&x,&y);
		int fx=gf(x),fy=gf(y);
		if(fx!=fy)
		{
			if(a[fx+n].sz>a[fy+n].sz) swap(fx,fy),swap(x,y);
			f[fx]=fy;
			run(a[n+fx].sn[0],a[fy+n].sn[0]);
		}
	}
	int _;
	scanf("%d",&_);
	while(_--)
	{
		char ch=getchar();int x,y;
		while(ch!='B'&&ch!='Q') ch=getchar();
		scanf("%d%d",&x,&y);
		if(ch=='B')
		{
			int fx=gf(x),fy=gf(y);
			if(fx!=fy)
			{
				if(a[fx+n].sz>a[fy+n].sz) swap(fx,fy),swap(x,y);
				f[fx]=fy;
				run(a[n+fx].sn[0],a[fy+n].sn[0]);
			}
		}
		else
		{
			x=gf(x);
			if(a[n+x].sz>=y)
				printf("%d\n",fth(n+x,y));
			else 
				printf("-1\n");
		}
	}
	return 0;
}








