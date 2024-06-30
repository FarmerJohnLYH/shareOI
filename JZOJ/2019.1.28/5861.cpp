#pragma GCC optimize(3) 
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
#define fi first
#define se second
using namespace std;
typedef pair<int,pair<int,int> > PI;
const int N=3*4004000,M=1e9;
int n,m,tot;
PI a[N];
int t[N];
int ans,ar,ap;
int r[N],r0,sn[N][2],rot;
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
}
int buf[30],b0;
void write(int x)
{
	b0=0;
	if(x==0)putchar('0');
	else
	while(x) buf[++b0]=x%10,x/=10;
	fd(i,b0,1) putchar(buf[i]+'0');
} 
void add(int &x,int l,int r,int p)
{
	if(!x) x=++tot;
	if(l==r)
	{
		++t[x];
		return;
	}
	int mid=(l+r)>>1;
	if(p>mid) add(sn[x][1],mid+1,r,p);
	else add(sn[x][0],l,mid,p);
	t[x]=sn[x][0][t]+sn[x][1][t];
}
int find(int x,int l,int r,int p)
{
	int mid=(l+r)>>1;
	if(l==r) 
		return(l);
	if(t[sn[x][1]]>=p) return(find(sn[x][1],mid+1,r,p));
	else return(find(sn[x][0],l,mid,p-t[sn[x][1]]));
}
bool cmp(PI x,PI y)
{
	return(x.se.fi<y.se.fi);
}
int gt(int tp,int p,int l,int r)
{
	int mid,rt=0;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(a[mid].se.fi==p) 
		{
			rt=mid;
			if(tp==1) r=mid-1;
			else l=mid+1;	
		}else
		if(a[mid].se.fi>p) 
		{
			r=mid-1;
			if(tp==1)rt=mid;		
		}
		else 
		{
			l=mid+1;
			if(tp==-1)rt=mid;
		}
	}
	return rt;
}
void build(int &x,int l,int r,int ql,int qr)
{
	if(!x)x=++tot;
	if(l==r)
	{
		t[x]=qr-ql+1;
		return;
	}
	int mid=(l+r)>>1;
	if(a[qr].se.fi>mid) build(sn[x][1],mid+1,r,gt(1,mid+1,ql,qr),qr);
	if(a[ql].se.fi<=mid) build(sn[x][0],l,mid,ql,gt(-1,mid,ql,qr));
	t[x]=sn[x][0][t]+sn[x][1][t];
}
int main()
{
	 freopen("failure.in","r",stdin);
	 freopen("failure.out","w",stdout);
//	 freopen("D:/LiuYuanHao/b.in","r",stdin);
//	 freopen("D:/LiuYuanHao/b.out","w",stdout);
	int p=read();
	n=read(),m=read();
	fo(i,1,n)
	{
		a[i].fi=read(),a[i].se.fi=read();
		a[i].se.se=i;
	}
	sort(a+1,a+1+n);
	tot=rot=1;
	ans=0;
	sort(a+1,a+1+m-1,cmp);
	build(rot,1,M,1,m-1);
	fo(i,m,n)
	{
		add(rot,1,M,a[i].se.fi);
		int p=find(rot,1,M,m);
		if(ans<p-a[i].fi) ans=p-a[i].fi,ar=i,ap=p;
	}
	write(ans),putchar('\n');
	if(ans==0)
	{
		fo(i,1,m) printf("%d ",i);
		return 0;
	}
	fd(i,ar,1)
	{
		if(a[i].se.fi>=ap) 
			r[++r0]=a[i].se.se;
		if(r0>=m)break;
	}
	sort(r+1,r+1+r0);
	fo(i,1,r0)
		write(r[i]),putchar(' ');
	return 0;
}
