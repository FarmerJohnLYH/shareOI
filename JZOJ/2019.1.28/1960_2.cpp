#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=100100;
int n,m;
int a[N],mx[N],fa[N],son[N][2];
int laz[N];
int gl(int x){return(x==son[fa[x]][1]);}
void add(int x,int v)
{
	a[x]+=v,mx[x]+=v,laz[x]+=v;
}
void down(int x)
{
	if(laz[x])
		fo(l,0,1)
		if(son[x][l])
			add(son[x][l],laz[x]);
	laz[x]=0;
}
void updata(int x)
{
	down(x);
	mx[x]=a[x];
	fo(l,0,1)if(son[x][l])
	{	
		down(son[x][l]);
		mx[x]=max(mx[x],son[x][l][mx]);	
	}
}
void rotate(int x)
{
	int y=fa[x],z=gl(x);
	down(y),down(x);
	son[fa[y]][gl(y)]=x;fa[x]=fa[y];
	fa[y]=x;
	son[y][z]=son[x][z^1];
	if(son[x][z^1])fa[son[x][z^1]]=y;
	son[x][z^1]=y;
	updata(y);
}
void splay(int x,int y)
{
	while(fa[x]!=y)
	{
		if(x[fa][fa]!=y)
		{
			if(gl(fa[x])==gl(x)) rotate(fa[x]);
			else rotate(x);
		}
		rotate(x);
	}
	updata(x);
}
int build(int f,int l,int r)
{
	int md=l+r>>1;
	if(md>l)son[md][0]=build(md,l,md-1);
	if(md<r)son[md][1]=build(md,md+1,r);
	fa[md]=f;
	updata(md);
	return md;
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%d",&n);
	fo(i,2,n+1) scanf("%d",&a[i]);
	son[0][0]=build(0,1,n+2);
	scanf("%d",&m);
	fo(i,1,m)
	{
		int t,x,y,c;
		scanf("%d%d%d",&t,&x,&y);
		++x,++y;
		splay(x-1,0),splay(y+1,x-1);
		down(x-1),down(y+1);
		if(t==1)
		{
			scanf("%d",&c);
			add(son[y+1][0],c);
		}
		else printf("%d\n",son[y+1][0][mx]);
	}
	return 0;
}











