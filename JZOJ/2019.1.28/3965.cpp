#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x),asdfgh=(y);i<=asdfgh;++i)
#define fd(i,x,y) for (int i=(x),asdfgh=(y);i>=asdfgh;--i)
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int,int> PI;
int abs(int x) {return(((x)>=0)?(x):(-(x)));}
int max(int x,int y) {return(((x)>(y))?(x):(y));}
int min(int x,int y) {return(((x)<(y))?(x):(y));}
int lowbit(int x) {return((x)&(-x));}
const int N=100100;
int n,k;
struct node{
	int a,b,c;
}c[N];
int g[N],x[N],y[N];
int t[N*10*8],lz[N*10*8];
int MN=oo,MX=-oo,ans=0;
bool cmp(node a,node b){return(a.b<b.b);}
void ud(int x,int v)
{
	lz[x]=0;
	int l=x<<1,r=l|1;
	lz[l]+=v,lz[r]+=v;
	t[l]+=v,t[r]+=v;
}
void change(int x,int l,int r,int ql,int qr,int v)
{
	if(ql>qr)return;
	if(lz[x]&&l!=r) ud(x,lz[x]);
	if(l==ql&&r==qr)
	{
		t[x]+=v,lz[x]+=v;
		return;
	}
	int mid=l+r>>1;
	if(mid>=ql) change(x<<1,l,mid,ql,min(mid,qr),v);
	if(mid+1<=qr) change(x<<1|1,mid+1,r,max(ql,mid+1),qr,v);
	t[x]=max(t[x<<1],t[x<<1|1]);
}
int main()
{
    // freopen("D:/LiuYuanHao/c2.in","r",stdin);
	scanf("%d%d",&n,&k);k<<=1;
	fo(i,1,n) 
	{
		scanf("%d%d%d",&i[g],&i[x],&i[y]);
		i[x]=i[x]+i[y],i[y]=i[x]-2*i[y]+1e6;
		// swap(i[x],i[y]);
		c[i].a=i[g],c[i].b=i[x],c[i].c=i[y];
		MN=min(MN,i[y]),MX=max(MX,i[y]);
	}
	sort(c+1,c+1+n,cmp);
	fo(i,1,n) i[g]=c[i].a,i[x]=c[i].b,i[y]=c[i].c;
	for (int l=0,r=1;max(l,r)<=n;)
	{
		int lx=x[l];
		while(l<=n&&x[l]==lx)
		{
			if(l) change(1,MN,MX,l[y],min(MX,l[y]+k),-l[g]);
			++l;
		}
		while(r<=n&&x[r]<=l[x]+k)
		{
			change(1,MN,MX,y[r],min(MX,y[r]+k),r[g]);
			++r;
		}
		ans=max(ans,t[1]);
	}
	printf("%d\n",ans);
}



