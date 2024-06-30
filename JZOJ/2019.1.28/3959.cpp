#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
#define fi first
#define se second 
using namespace std;
typedef pair<int,int> PI;
const int N=100100*4,L=-1000000010,R=1000000010;
int n,m;
PI pa[N];
int f[N];
struct seg{
	int a[N*4],lz[N*4],to[N*4][2];
	int tot;
	void add(int x,int l,int r,int ql,int qr)
	{
		if(a[x])return;
		if(ql<=l&&r<=qr) 
		{
			a[x]=lz[x]=1;
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) 
		{
			if(!to[x][0]) to[x][0]=++tot;
			add(to[x][0],l,mid,ql,qr);
		}
		if(qr>mid) 
		{
			if(!to[x][1]) to[x][1]=++tot;
			add(to[x][1],mid+1,r,ql,qr);
		}
		a[x]=a[to[x][0]]&a[to[x][1]];
	}
	void update(int x)
	{
		lz[x]=0;
		fo(l,0,1)
		{
			if(!to[x][l]) to[x][l]=++tot;
			lz[to[x][l]]=1,a[to[x][l]]=1;	
		}
	}
	int query(int x,int l,int r,int ql,int qr)
	{
		if(lz[x])update(x);
		if(!x)return 0;
		if(ql<=l&&r<=qr) return(a[x]);
		int rt=1,mid=(l+r)>>1;
		if(ql<=mid) rt&=query(to[x][0],l,mid,ql,qr);
		if(qr>mid) rt&=query(to[x][1],mid+1,r,ql,qr);
		return rt;
	}
}t;
int main()
{
//	freopen("D:/LiuYuanHao/a1.in","r",stdin);
	scanf("%d",&n);
	t.tot=1;
	fo(i,1,n) f[i]=i;
	fo(i,1,n)
	{
		int tp,x,y;
		scanf("%d%d%d",&tp,&x,&y);
		if(tp==1) 
		{
			++x,--y;
			pa[++m].fi=x,pa[m].se=y;
			int p=query(1,L,R,x);if(!p) p=query(1,L,R,y)
			if(p) f[]
		}
		else
		if(tp==2)
		{
		}
	}
	return 0;
}











