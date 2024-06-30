#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
#define fi first
#define se second
using namespace std;
typedef pair<int,int> PI;
const int N=200200;
int n;
PI a[N],b[N];
int t[N*4];
void add(int x,int l,int r,int p)
{
	if(l==r)
	{
		++t[x];
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid) add(x<<1,l,mid,p);
	else add(x<<1|1,mid+1,r,p);
	t[x]=t[x<<1]+t[x<<1|1];
}
int del(int x,int l,int r,int p)
{
	if((r<p)) return 0;
	if(!t[x]) return 0;
	if(l==r)
	{
		--t[x];
		return 1;
	}
	int mid=(l+r)>>1,rt=0;
	if(del(x<<1,l,mid,p)) rt=1;
	else rt=del(x<<1|1,mid+1,r,p);
	t[x]=t[x<<1]+t[x<<1|1];
	return rt;
}
int main()
{
	 freopen("guide.in","r",stdin);
	 freopen("guide.out","w",stdout);
//	freopen("D:/LiuYuanHao/a1.in","r",stdin);
	scanf("%d",&n);scanf("%d",&n);
	fo(i,1,n) scanf("%d%d",&a[i].fi,&a[i].se);
	fo(i,1,n) scanf("%d%d",&b[i].fi,&b[i].se);
	sort(b+1,b+1+n);sort(a+1,a+1+n);
	int j=n,cnt=0;
	fd(i,n,1)
	{
		while(j>0&&a[i].fi<=b[j].fi) add(1,1,2*n,b[j].se),--j;
		if(del(1,1,2*n,a[i].se)) ++cnt;
	}
	printf("%d\n",cnt);
	return 0;
}











