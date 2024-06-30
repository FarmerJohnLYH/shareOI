#include <cmath>
#include <ctime>
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
const int N=2*100100;
struct node{
	int x,y;
	int nex,las;
}a[N];
int n,D;
int d[N];
int t[N];
int ans[N];
void del(int x)
{
	a[a[x].nex].las=a[x].las;
	a[a[x].las].nex=a[x].nex;
}
int main()
{
	freopen("piepie.in","r",stdin);
	freopen("piepie.out","w",stdout);
//	freopen("D:/LiuYuanHao/p.in","r",stdin);
	scanf("%d%d",&n,&D);
	fo(i,1,n)
	{
		a[i-1].nex=i,a[i].las=i-1;
		scanf("%d%d",&a[i].x,&a[i].y);
		if(a[i].y==0)
		{
			d[++d[0]]=i;
			t[d[0]]=1;
//			bz[i]=1;
			del(i);
			ans[i]=1;
		}
	}
//	a[n].nex=1,a[1].las=n;
	fo(i,n+1,n+n)
	{
		a[i-1].nex=i,a[i].las=i-1;
		scanf("%d%d",&a[i].x,&a[i].y);
		if(a[i].x==0)
		{
			del(i);
//			bz[i]=1;
			d[++d[0]]=i;
			t[d[0]]=2;
			ans[i]=1;
		}
	}
	a[n+n].nex=n+n+1;
//	a[n+n].nex=n+1,a[n+1].las=n+n;
	int hd=0;
	while(hd++<d[0])
	{
		int now=d[hd];
		if(t[hd]==1)
		{
			for (int i=a[n].nex;i<=n+n&&i>n;i=a[i].nex)
			fo(i,n+1,n+n)
//			if(!bz[i])
			if(a[now].x-a[i].x<=D&&a[now].x-a[i].x>=0)
			{
				del(i);
				d[++d[0]]=i;
				t[d[0]]=2;
//				bz[i]=1;
				ans[i]=ans[d[hd]]+1;
			}
		}
		else
		{
			
			for (int i=a[0].nex;i<=n&&i>0;i=a[i].nex)
//			fo(i,1,n)
//			if(!bz[i])
			if(a[now].y-a[i].y<=D&&a[now].y-a[i].y>=0)
			{
				del(i); 
				d[++d[0]]=i;
				t[d[0]]=1;
//				bz[i]=1;
				ans[i]=ans[d[hd]]+1;
			}
		}
	}
	fo(i,1,n)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}
