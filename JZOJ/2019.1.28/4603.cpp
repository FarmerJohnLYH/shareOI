#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (int pq = (y),i = (x);i <= pq;++ i)
#define fd(i,x,y) for (int pq = (y),i = (x);i >= pq;-- i)
#define oo 2139062143
using namespace std;
typedef double db;
typedef long long ll;
int lowbit(int x) {return((x)&(-x));}
int min(int x,int y){return (x>y)?(y):(x);}
int max(int x,int y){return (x>y)?(x):(y);}
const int N=100100,C=33;
int n,c,m;
int x,y,z;
int t[N*8];
int lz[N*8];
void build(int x,int l,int r)
{
	if(l==r)
	{
		t[x]=1;
		return;
	}
	int mid=(l+r)>>1;
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
	t[x]=t[x<<1]|t[x<<1|1];
}
int tot=0;
void updata(int x,int y)
{
	t[x]=y;
	lz[x]=y;
}
void down(int x)
{
	if(!lz[x]) return;
	updata(x<<1,lz[x]);
	updata(x<<1|1,lz[x]);
	lz[x]=0;
}
void change(int x,int l,int r,int ql,int qr,int qv)
{
	if(l>r)return;
	if(l==ql&&r==qr)
	{
		updata(x,qv);
		return;
	}
	down(x);
	int mid=(l+r)>>1;
		 if(qr<=mid) change(x<<1,l,mid,ql,qr,qv);
	else if(ql>=mid+1) change(x<<1|1,mid+1,r,ql,qr,qv);
	else change(x<<1,l,mid,ql,mid,qv),change(x<<1|1,mid+1,r,mid+1,qr,qv);
	t[x]=t[x<<1]|t[x<<1|1];
}
int query(int x,int l,int r,int ql,int qr)
{
	if(ql==l&&qr==r) 
		return(t[x]);
	down(x);
	int mid=(l+r)>>1;
	int rt=0;	 
		 if(qr<=mid) rt|=query(x<<1,l,mid,ql,qr);
	else if(ql>=mid+1) rt|=query(x<<1|1,mid+1,r,ql,qr);
	else rt|=query(x<<1,l,mid,ql,mid)|query(x<<1|1,mid+1,r,mid+1,qr);
	return rt;
}
int count(int x)
{
	int rt=0;
	while(x) x-=lowbit(x),++rt;
	return rt;
}
int main()
{
	freopen("D:/LiuYuanHao/a2.in","r",stdin);
	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%d%d%d",&n,&c,&m);
	build(1,1,n);
	while(m--)
	{
		char ch=getchar();
		while(ch!='C'&&ch!='P') ch=getchar();
		scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		if(ch=='C')
		{
			scanf("%d",&z);
			if(z==3)
			{
//				printf(" ");
			}
			change(1,1,n,x,y,1<<(z-1));
		}
		else
		{
			if((++tot)==9)
			{
//				printf(" ");
			}
			int ans=query(1,1,n,x,y);
			printf("%d\n",count(ans));
		}
	}
	return 0;
}
