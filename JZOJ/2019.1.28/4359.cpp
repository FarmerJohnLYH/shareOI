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
const int N=100100,Mo=100000007;
struct node{
	ll lt[2],rt[2];
	ll mt[2];
	int sum;
	int l,r;
	node(){}
	node(int x)
	{
		lt[0]=lt[1]=x;
		rt[0]=rt[1]=x;
		mt[0]=mt[1]=x;
		sum=l=r=x;
	}
}t[11][N*8];
int n,m;
int a[N];
void merge(node &x,node a,node b)
{
	if(a.r+1!=b.l) swap(a,b);
	x.l=a.l,x.r=b.r;
	x.sum=a.sum^b.sum;
	x.mt[0]=(0ll+a.mt[0]+b.mt[0]+a.rt[0]+b.lt[0]+1ll*(a.rt[0]*b.lt[0]+a.rt[1]*b.lt[1]))%Mo;
	x.mt[1]=(0ll+a.mt[1]+b.mt[1]+a.rt[1]+b.lt[1]+1ll*(a.rt[0]*b.lt[1]+a.rt[1]*b.lt[0]))%Mo;
	x.lt[0]=(0ll+a.lt[0]+b.lt[a.sum]+(1^a.sum))%Mo;
	x.lt[1]=(0ll+a.lt[1]+b.lt[1^a.sum]+a.sum)%Mo;
	x.rt[0]=(0ll+b.rt[0]+a.rt[b.sum]+(1^b.sum))%Mo;
	x.rt[1]=(0ll+b.rt[1]+a.rt[1^b.sum]+b.sum)%Mo;
}
void build(int o,int x,int l,int r)
{
	if(l==r)
	{
		t[o][x].sum=((a[l]&(1<<(o-1)))>0);
		t[o][x].l=t[o][x].r=l;
		return;
	}
	int mid=(l+r)>>1;
	build(o,x<<1,l,mid);
	build(o,x<<1|1,mid+1,r);
	merge(t[o][x],t[o][x<<1],t[o][x<<1|1]);
}
node tmp;
void change(int o,int pos,int l,int r,int x)
{
	if(l==r)
	{
		t[o][pos].sum=((a[l]&(1<<(o-1)))>0);
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)
	{
		change(o,pos<<1,l,mid,x);
	}
	else
	{
		change(o,pos<<1|1,mid+1,r,x);
	}
	merge(t[o][pos],t[o][pos<<1],t[o][pos<<1|1]);
}
void find(int o,int x,int l,int r,int ql,int qr)
{
	if(l==ql&&r==qr)
	{
		if(tmp.l==0) tmp=t[o][x];
		else merge(tmp,tmp,t[o][x]);
		return;
	}
	int mid=(l+r)>>1;
	if(ql>mid) find(o,x<<1|1,mid+1,r,ql,qr);
	else if(qr<=mid) find(o,x<<1,l,mid,ql,qr);
	else 
	{
		find(o,x<<1,l,mid,ql,mid);
		find(o,x<<1|1,mid+1,r,mid+1,qr);
	}
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%d",&n);
	fo(i,1,n)
		scanf("%d",&a[i]);
	fo(i,1,10) 
		build(i,1,1,n);
	scanf("%d",&m);
	fo(i,1,m)
	{
		char c=' ';
		int x,y;
		while(c!='Q'&&c!='M')
		{
			c=getchar();
		}
		scanf("%d%d",&x,&y);
		if(c=='M')
		{
			a[x]=y;
			fo(i,1,10) change(i,1,1,n,x);
			continue;
		}
		ll ans=0;
		fo(i,1,10)
		{
			//check()
			tmp=node(0);
			find(i,1,1,n,x,y);
			ans=(ans+1ll*(tmp.lt[1]+tmp.rt[1]+tmp.mt[1]+tmp.sum)*(1<<(i-1))%Mo)%Mo;
		}
		printf("%lld\n",ans);
//		printf("a:%lld\n",1+2+3+(1^2)+(1^2^3)+(2^3));
	}
	return 0;
}
