#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=110,M=100100*2;
int n,m,q;
int u[M],v[M],c[M];
struct gub{
	int a[N],tot;
}g[M*4],p;
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
}
struct tre{
	int f[N];
	int gf(int x)
	{
		return((f[x]==x)?(x):(f[x]=gf(f[x])));
	}
	void check(int x,gub &p)
	{
		int fx=gf(u[x]),fy=gf(v[x]);
		if(fx!=fy) 
		{
			f[fx]=fy;
			p.a[++p.tot]=x;
		}
		return;
	}
	void combine(gub &x,gub y)
	{
		gub cc;cc.tot=0;
		int p0=1,p1=1;
		fo(i,1,n) f[i]=i;
		while(p0<=x.tot&&p1<=y.tot)
		{
			if(x.a[p0][c]<=y.a[p1][c]) check(x.a[p0++],cc);
			else check(y.a[p1++],cc);
		}
		fo(i,p0,x.tot) check(x.a[i],cc);
		fo(i,p1,y.tot) check(y.a[i],cc);
		x.tot=cc.tot;
		fo(i,1,cc.tot) x.a[i]=cc.a[i];
	}
	void build(int x,int l,int r,gub &p)
	{
		if(l==r)
		{
			p.tot=g[x].tot=1,p.a[1]=g[x].a[1]=l;
			return;
		}
		int mid=(l+r)>>1;
		gub tp[2];tp[1].tot=tp[0].tot=0;
		build(x<<1,l,mid,tp[0]);
		build(x<<1|1,mid+1,r,tp[1]);
		p.tot=0;
		combine(tp[0],tp[1]);
		g[x].tot=p.tot=tp[0].tot;
		fo(i,1,p.tot) g[x].a[i]=p.a[i]=tp[0].a[i];
	}
	void query(int x,int l,int r,int ql,int qr,gub &p)
	{
		if(l>=ql&&r<=qr)
		{
			combine(p,g[x]);
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid)	query(x<<1,l,mid,ql,qr,p);
		if(qr>mid) query(x<<1|1,mid+1,r,ql,qr,p);
	}
}tr;
int main()
{
//	freopen("highway.in","r",stdin);
//	freopen("highway.out","w",stdout);
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	n=read(),m=read(),q=read();
	fo(i,1,m) u[i]=read(),v[i]=read(),c[i]=read();
	p.tot=0;
	tr.build(1,1,m,p);
	fo(i,1,q)
	{
		int ans=0,l=read(),r=read();
		p.tot=0;
		tr.query(1,1,m,l,r,p);
		fo(i,1,p.tot) ans+=p.a[i][c];
		printf("%d\n",ans);
	}
	return 0;
}











