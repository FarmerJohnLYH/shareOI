#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=150150,P=4e7,mo=998244353;
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
}
int n,m;
struct node{
	int l,r,op;
	int ql,qr;
	ll v;
}c[N];
int sn[P][2],lz[P][2],cnt;
int rot[N*4],bz[N*4][2];
int ans;
void comb(int *a,int *b)
{
	a[0]=(1ll*a[0]*b[0]%mo);
	a[1]=(1ll*a[1]*b[0]+b[1])%mo;
}
void xia(int x)
{
	if(lz[x][0]!=1||lz[x][1]!=0)
	{
		fo(l,0,1)
		if(sn[x][l])
			comb(lz[sn[x][l]],lz[x]);
		lz[x][0]=1,lz[x][1]=0;
	}
}
void add(int &x,int l,int r,int ql,int qr,node p)
{
	if(!x)x=++cnt,lz[x][0]=1;
	if(l<r)xia(x);
	if(ql<=l&&r<=qr)
	{
		if(p.op==1) lz[x][1]=(lz[x][1]+p.v)%mo;
		else fo(k,0,1)lz[x][k]=(1ll*lz[x][k]*p.v%mo);
		return;
	}
	int mid=(l+r)>>1;
	if(ql<=mid) add(sn[x][0],l,mid,ql,qr,p);
	if(qr>mid) add(sn[x][1],mid+1,r,ql,qr,p);
}
void down(int x,int l,int r)
{
	if(bz[x][0]!=1||bz[x][1]!=0)
	{
		fo(k,0,1)
		{
			int y=x<<1|k;
			comb(bz[y],bz[x]);node qaq;
			qaq.op=2,qaq.v=bz[x][0];
			add(rot[y],1,n,l,r,qaq);
			qaq.op=1,qaq.v=bz[x][1];
			add(rot[y],1,n,l,r,qaq);
		}
		bz[x][0]=1,bz[x][1]=0;
	}
}
void cg(int x,int l,int r,node p)
{
	if(l<r)down(x,p.l,p.r);
	if(p.ql<=l&&r<=p.qr)
	{
		if(p.op==1) bz[x][1]=(bz[x][1]+p.v)%mo;
		else fo(k,0,1)bz[x][k]=(1ll*bz[x][k]*p.v%mo);
		add(rot[x],1,n,p.l,p.r,p);
		return;
	}
	int mid=(l+r)>>1;
	if(p.ql<=mid) cg(x<<1,l,mid,p);
	if(p.qr>mid) cg(x<<1|1,mid+1,r,p);
}
void find(int x,int l,int r,int p)
{
	if(!x) return;
	if(l<r)xia(x);
	if(l==r)
	{
		ans=lz[x][1];
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid) find(sn[x][0],l,mid,p);
	else find(sn[x][1],mid+1,r,p);
}
void query(int x,int l,int r,int p,int pp)
{
	if(l<r)down(x,p,p);
	if(l==r)
	{
		find(rot[x],1,n,pp);
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid) query(x<<1,l,mid,p,pp);
	else query(x<<1|1,mid+1,r,p,pp);
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	n=read(),m=read();
	fo(i,1,m) c[i].qr=m;
	fo(i,1,m)
	{
		c[i].op=read();
		if(c[i].op==1) c[i].ql=i,c[i].l=read(),c[i].r=read(),c[i].v=read();
		if(c[i].op==2) c[i].ql=i,c[i].l=read(),c[i].r=read(),c[i].v=read();
		if(c[i].op==3) c[i].v=read();
		if(c[i].op==4) c[read()].qr=i;
	}
	fo(i,1,n*4) bz[i][0]=1,bz[i][1]=0;
	fo(i,1,m)
	{
		printf("");
		if(c[i].op==4) continue;
		if(c[i].op==3) 
		{
			ans=0;
			query(1,1,m,i,c[i].v);
			printf("%d\n",ans);
		}
		else
			cg(1,1,m,c[i]);
	}
	return 0;
}








