#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=100100;
int a[N];
int n,m,f[N],g[N];
int p[N],p0;
void solve(int *c)
{
	memset(p,127,sizeof p);
	p0=0;p[0]=0;
	fo(i,1,m)
	{
		int l=0,r=p0,rt=0;	
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(p[mid]<=a[i]) rt=mid,l=mid+1;
			else r=mid-1;
		}
		c[i]=max(c[i],rt+1);
		p0=max(p0,c[i]);
		if(a[i]<=p[c[i]]) p[c[i]]=a[i];
	}
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&m);
	fo(i,1,n) 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		++a[x],--a[y+1];
	}
	int mx=a[1];
	fo(i,2,m) a[i]+=a[i-1],mx=max(mx,a[i]);
	solve(f);
	fo(i,1,m>>1) swap(a[i],a[m-i+1]);
	solve(g);
	fo(i,1,m>>1) swap(g[i],g[m-i+1]);
	int ans=0;
	fo(i,1,m)ans=max(ans,g[i]+f[i]-1);
	printf("%d\n",ans);
	return 0;
}











