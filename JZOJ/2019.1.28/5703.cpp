#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define fi first
#define se second
#define oo 2139062143
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define abs(x) (((x)>0)?(x):(-(x)))
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef pair<int,int> PI;
const int N=500500;
typedef long long ll;
int n,q;
PI a[N];
int ql(int x)
{
	int p=x-1;
	while(a[p].se<=a[x].se) --p;
	return p;
}
int qr(int x)
{
	int p=x+1;while(a[p].se<=a[x].se) ++p;
	return p;
}
int l[N],r[N],u[N],v[N];
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("board.in","r",stdin);
	freopen("board.out","w",stdout);
	scanf("%d%d",&n,&q);
	fo(i,1,n) scanf("%d",&a[i].fi);
	fo(i,1,n) scanf("%d",&a[i].se);
	a[0].se=a[n+1].se=oo;
	fo(i,1,n) l[i]=ql(i),r[i]=qr(i);
	while(q--)
	{
		int tp,x,y;
		scanf("%d%d%d",&tp,&x,&y);
			 if(tp==3)a[x].fi=y;
		else if(tp==2)
		{
			a[x].se=y,l[x]=ql(x),r[x]=qr(x);
			fo(i,x+1,r[x]-1) l[i]=ql(i);
			fo(i,l[x]+1,x-1) r[i]=qr(i);
		} 
		else if(tp==1)
		{
			int u0=0,v0=0,p=x;
			while(p<=y)u[++u0]=p,p=r[p];
			if(u[u0]>n)--u0;
			p=y;
			while(p>=x)v[++v0]=p,p=l[p];
			if(v[v0]<1)v0--;
			ll ans=0;
			fo(i,1,u0)fo(j,1,v0)
				ans = max(ans,(ll)min(u[i][a].se,v[j][a].se)*abs(u[i][a].fi-v[j][a].fi));
			printf("%lld\n", ans);
		}
	}
	return 0;
}




