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
const int N=200200;
int w,h,n;
PI a[N];
int b[N],l[N],ans=0;
int b0,mx;
bool cmp(PI x,PI y)
{
	return(x.fi<y.fi||(x.fi==y.fi&&x.se<y.se));
}
int gf(int x)
{
	return(l[x]==x?x:l[x]=gf(l[x]));
}
int find(int x)
{
	int le=1,ri=b0;
	while(le<=ri)
	{
		int mid=(le+ri)>>1;
		if(b[mid]==x)
		{
			if(b[mid]==b[mid+1])
				le=mid+1;
			else return(mid);
		}
		else if(b[mid]<x) le=mid+1;
		else if(b[mid]>x) ri=mid-1;
	}
}
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout); 
	freopen("paint.out","w",stdout); 
//	freopen("D:/LiuYuanHao/c.in","r",stdin);
	scanf("%d%d%d",&w,&h,&n);
	fo(i,1,n)
		scanf("%d%d",&a[i].fi,&a[i].se);
	n+=4;a[n-3].fi=a[n-3].se=a[n-2].fi=a[n-2].se=0;
	a[n-1].fi=w,a[n-1].se=h;a[n].fi=w,a[n].se=h;
	sort(a+1,a+1+n,cmp);
	fo(le,1,n)
	{
		b0=0,mx=-1;
		fo(i,le+1,n-1) b[++b0]=a[i].se;
		b[b0+1]=0;
		sort(b+1,b+1+b0);
		fo(i,1,b0) mx=max(mx,b[i+1]-b[i]),l[i]=i;
		ans=max(ans,mx+a[n].fi-a[le].fi);	
		fd(ri,n-1,1)
		{
			c0=0;
			fo(l,le+1,ri-1) c[++c0]=a[l].se;
			sort(c+1,c+1+c0);
			
			ans=max(ans,mx+a[ri].fi-a[le].fi);
		}
	}
	printf("%d\n",ans*2);
	return 0;
}











