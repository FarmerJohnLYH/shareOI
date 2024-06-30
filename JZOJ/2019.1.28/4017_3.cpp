#pragma GCC optimize(2) 
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef double db;
typedef pair<db,db> PI;
const int N=60600;
const db eps=1e-10;
struct seg{
	db mx[N*4],w[N*4];
	void add(int x,int l,int r,int p,db v)
	{
		if(l==r)
		{
			mx[x]=v;
			return;
		}
		int mid=(l+r)>>1;
		if(p<=mid) add(x<<1,l,mid,p,v);
		else add(x<<1|1,mid+1,r,p,v);
		mx[x]=max(mx[x<<1],mx[x<<1|1])+w[x];
	}
	void cg(int x,int l,int r,int ql,int qr,db v)
	{
		if(ql<=l&&r<=qr)
		{
			mx[x]+=v,w[x]+=v;
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) cg(x<<1,l,mid,ql,qr,v);
		if(qr>mid) cg(x<<1|1,mid+1,r,ql,qr,v);
		mx[x]=max(mx[x<<1],mx[x<<1|1])+w[x];
	}
	db qry(int x,int l,int r,int ql,int qr)
	{
		if(ql<=l&&r<=qr) return(mx[x]);
		int mid=(l+r)>>1;db rt=-oo;
		if(ql<=mid) rt=max(rt,qry(x<<1,l,mid,ql,qr));
		if(qr>mid) rt=max(rt,qry(x<<1|1,mid+1,r,ql,qr));
		return rt+w[x];
	}
}t;
int a[N],b[N],c[N],n,m;
int qu[N];
db w[N],f[N],g[N];
int read()
{
	int x=0,v=1; char ch=getchar();
	for(;ch<'0'||ch>'9';v=(ch=='-')?(-1):(v),ch=getchar());
	for(;ch<='9'&&ch>='0';x=x*10+ch-'0',ch=getchar());
	return x*v;
}
db wv[N];
bool check(db mid)
{
	fo(i,2,n)f[i]=-oo;f[1]=0;
	memset(wv,0,sizeof wv);
	fo(i,1,n*4)t.mx[i]=-oo,t.w[i]=0;
	t.add(1,1,n,1,f[1]);
	fo(i,1,n) w[i]=a[i]-mid*b[i];
	fd(i,n,1) wv[i]=wv[i+1]+(w[i]>0)*w[i];
	int hd=1,tl=1;qu[tl]=1;
	fo(i,2,n)
	{
		while(hd<tl&&c[i]>=qu[tl][c])
		{
			t.cg(1,1,n,qu[tl-1],qu[tl]-1,-qu[tl][w]);
			--tl;
		}
		qu[++tl]=i;
		t.cg(1,1,n,qu[tl-1],qu[tl]-1,qu[tl][w]);
		f[i]=t.qry(1,1,n,max(1,i-m),i-1);
		if((wv[i+1]+f[i]>0))t.add(1,1,n,i,f[i]);
	}
	return f[n]<=0;
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	n=read()+1,m=read();
	fo(i,2,n) a[i]=read(),b[i]=read(),c[i]=read();
	db l=0,r=1000000;
	fo(i,1,55)
	{
		db mid=(l+r)*0.50;
		if (check(mid)) r=mid;
		else l=mid;
	}
	db ans=(l+r)*0.50;int cnt=0;
	if(ans==0)printf("0.000000000e+000\n");
	else
	{
		while(ans<1) ans=ans*10.00,--cnt;
		while(ans>=10) ans=ans*0.10,++cnt;
		printf("%.9lfe",ans);
		if(cnt<0)cnt=-cnt,putchar('-');else putchar('+');
		if(cnt<100)printf("0");if(cnt<10)printf("0");if(cnt<1)printf("0");
		printf("%d\n",cnt);
	}
	return 0;
}



