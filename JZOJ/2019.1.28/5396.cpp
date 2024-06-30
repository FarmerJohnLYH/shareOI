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
ll min(ll x,ll y){return (x>y)?(y):(x);}
ll max(ll x,ll y){return (x>y)?(x):(y);}
const int N = 1001000,M = 550;
ll a[N];
int n,m;
struct node{
	int id;
	ll v;
}k[M],d[N];
int d0,rt[M];
// __attribute__((optimize("-O2")))
bool cmp(node x,node y)
{
	return(x.v<y.v);
}
int main()
{
	// freopen("blocks.in","r",stdin);
	// freopen("blocks.out","w",stdout);
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&m);
	fo(i,1,n)scanf("%lld",&a[i]),a[i]+=a[i-1];
	fo(i,1,m)scanf("%lld",&k[i].v),k[i].id=i;
	sort(k+1,k+1+m,cmp); 
	fo(i,1,m)
	{
		d0=0;
		int ans=0;
		d[0].id=d[0].v=0;
		fo(j,1,n) a[j]-=k[i].v*j;
		fo(j,1,n)
			if(d[d0].v>a[j]) 
				d[++d0].v=a[j],d[d0].id=j;
		fd(j,n,1)
		{
			while (d[d0].v<=a[j] && d0 > 0) 
				ans=max(ans,j-d[d0].id),-- d0;
			if(d0==0&&a[j]>=0) 
			{
				ans=max(ans,j);
				break;
			}
		}
		fo(j,1,n) a[j]+=k[i].v*j;
		rt[k[i].id]=ans;
	}
	fo(i,1,m) printf("%d ", rt[i]);
	return 0;
}
