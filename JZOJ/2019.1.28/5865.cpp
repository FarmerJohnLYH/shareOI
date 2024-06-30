 #pragma GCC optimize(3) 
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=200200;
int n,m,k;
struct node{
	int s,t,a;
}a[N];
int q;
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
	if(x<0) putchar('-'),x=-x;
	b0=0;
	if(x==0)putchar('0');
	else
	while(x) buf[++b0]=x%10,x/=10;
	fd(i,b0,1) putchar(buf[i]+'0');
	putchar('\n');
}
bool cmp(node a,node b)
{
	return(a.a!=b.a)?(a.a<b.a):(a.s<b.s||(a.s==b.s&&a.t<b.t));
}
int f[20][N],lz[N*4],t[N*4];
void down(int x,int l,int r)
{
	if(l>=r)return;
	if(lz[x])
	{
		t[x<<1]=max(t[x<<1],lz[x]);
		t[x<<1|1]=max(t[x<<1|1],lz[x]);
		lz[x<<1]=max(lz[x<<1],lz[x]);
		lz[x<<1|1]=max(lz[x<<1|1],lz[x]);
	}
}
void cg(int x,int l,int r,int ql,int qr,int v) 
{
	if(ql<=l&&r<=qr)
	{
		lz[x]=max(lz[x],v);
		t[x]=max(t[x],v);
		return;
	}
	down(x,l,r);
	int mid=(l+r)>>1;	
	if(ql<=mid) cg(x<<1,l,mid,ql,qr,v);
	if(qr>mid) cg(x<<1|1,mid+1,r,ql,qr,v);
	t[x]=max(t[x<<1],t[x<<1|1]);
}
int query(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)
		return(t[x]);
	int mid=(l+r)>>1;
	down(x,l,r);int rt=0;
	if(ql<=mid) rt=max(rt,query(x<<1,l,mid,ql,qr));
	if(qr>mid) rt=max(rt,query(x<<1|1,mid+1,r,ql,qr));
	return rt;
}
int main()
{
	freopen("trip.in","r",stdin);
	freopen("trip.out","w",stdout);
//	freopen("D:/LiuYuanHao/c1.in","r",stdin);
//	freopen("D:/LiuYuanHao/c.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	fo(i,1,m)
	a[i].s=read(),a[i].t=read(),a[i].a=read(),--a[i].t;
//		scanf("%d%d%d",&a[i].s,&a[i].t,&a[i].a),--a[i].t;
	sort(a+1,a+1+m,cmp);
	fo(i,1,n) cg(1,1,n,i,i,i);
	int las=0,flag=0;
	fo(i,1,m)
	{	
		if(a[i].a!=a[i-1].a)
		{
			if(a[i].a-a[i-1].a>1) flag=1;
			if(las+1<=n&&las>0)cg(1,1,n,las+1,n,n);
			las=a[i].t;cg(1,1,n,1,a[i].s,a[i].s);
		}
		else 
		{
			if(las+1<a[i].s)cg(1,1,n,las+1,a[i].s,a[i].s);
			las=max(las,a[i].t);
		}
	}
	if(las+1<=n&&las>0) cg(1,1,n,las+1,n,n);
	if(k>a[m].a) flag=1;
	fo(x,1,n) f[0][x]=query(1,1,n,x,x);
	fo(p,1,20) fo(x,1,n)
	{
		f[p][x]=f[p-1][f[p-1][x]];	
//		cg(1,1,n,x,x,f[p][x]);
	}
	scanf("%d",&q);
	while(q--)
	{
		int le,ri;
		le=read(),ri=read();
//		scanf("%d%d",&le,&ri);
		if(flag||le==ri)
		{
			printf("1\n");
			continue;
		}
		int x=le,cnt=0;
		fd(p,20,0) if(f[p][x]<ri||f[p][x]==0)
			cnt+=(1<<p),x=f[p][x];
		if(f[0][x]>=ri) write(cnt+1);
//		printf("%d\n",cnt+1);
		else write(-1);
//		printf("-1\n");
	}
	return 0;
}











