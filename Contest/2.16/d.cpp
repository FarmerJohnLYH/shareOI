#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=200200,mo=1e9+7;
int n,q;
struct node{
	int l,r,c,id;
}a[N],d[N];int d0;
bool cmp(node a,node b)
{
	return(a.l>b.l || (a.l==b.l && a.r>b.r));
}
int z[N],y[N];
bool in(int x,int l,int r)
{
	return(x>=l&&x<=r);
}
int main()
{
	scanf("%d",&n);
	fo(i,1,n)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[i].l=x,a[i].r=y,a[i].c=x^y;
		a[i].id=i;
	}
	memset(z,127,sizeof z);
	memset(y,128,sizeof y);
	fo(i,1,n) fo(j,1,n)
		if(i!=j && a[j].l>=a[i].l&&a[j].r>=a[i].r)
			z[i]=min(z[i],j),y[i]=max(y[i],j);  
	scanf("%d",&q);
	fo(i,1,q)
	{
		int l,r;scanf("%d%d",&l,&r);
		int ans=1;
		fo(j,l,r) if(!(in(z[j],l,r) || in(y[j],l,r)))
			ans=ans*a[j].c%mo;
		printf("%d\n",ans);
	}
	return 0;
}








