#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,sz,rt;
int fa[100005],son[100005][2];
int size[100005];
bool rev[100005];
void updata(int k)
{
	int l=son[k][0],r=son[k][1];
	size[k]=size[l]+size[r]+1;
}
void pushdown(int k)
{
	int l=son[k][0],r=son[k][1];
	if(rev[k])
	{
		swap(son[k][0],son[k][1]);
		rev[l]^=1;rev[r]^=1;
		rev[k]=0;
	}
}
void rotate(int x,int &k)
{
	int y=fa[x],z=fa[y],l,r;
	if(son[y][0]==x)l=0;else l=1;r=l^1;
	if(y==k)k=x;
	else {if(son[z][0]==y)son[z][0]=x;else son[z][1]=x;}
	fa[x]=z;fa[y]=x;fa[son[x][r]]=y;
	son[y][l]=son[x][r];son[x][r]=y;
	updata(y);updata(x);
}
void splay(int x,int &k)
{
	while(x!=k)
	{
		int y=fa[x],z=fa[y];
		if(y!=k)
		{
			if(son[y][0]==x^son[z][0]==y)rotate(x,k);
			else rotate(y,k);
		}
		rotate(x,k);
	}
}
int find(int k,int rank)
{
	pushdown(k);
	int l=son[k][0],r=son[k][1];
	if(size[l]+1==rank)return k;
	else if(size[l]>=rank)return find(l,rank);
	else return find(r,rank-size[l]-1);
}
void rever(int l,int r)
{
	int x=find(rt,l),y=find(rt,r);
	splay(x,rt);splay(y,son[x][1]);
	int z=son[y][0];
	rev[z]^=1;
}
void build(int l,int r,int f)
{
	if(l>r)return;
	int mid=(l+r)>>1,now=mid;
	if(l==r)
	{
		fa[now]=f;size[now]=1;
		if(l<f)son[f][0]=now;
		else son[f][1]=now;
		return;
	}
	build(l,mid-1,mid);build(mid+1,r,mid);
	fa[now]=f;updata(mid);
	if(mid<f)son[f][0]=now;
	else son[f][1]=now;
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	n=read();m=read();
	build(1,n+2,0);rt=(n+3)>>1;
	fo(i,1,m)
	{
		int l=read()+1,r=read()+1;
		rever(l-1,r+1);
	}
	fo(i,2,n+1)printf("%d ",find(rt,i)-1);
	return 0;
}
