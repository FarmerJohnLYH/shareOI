#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (ll pq = (y),i = (x);i <= pq;++ i)
#define fd(i,x,y) for (ll pq = (y),i = (x);i >= pq;-- i)
#define oo 9187201950435737471
using namespace std;
typedef double db;
typedef long long ll;
ll lowbit(ll x) {return((x)&(-x));}
ll min(ll x,ll y){return (x>y)?(y):(x);}
ll max(ll x,ll y){return (x>y)?(x):(y);}
const ll N=5050;
ll n;
struct node{
	ll x,y;
}a[N];
ll ans[N];
ll dis[N][N];
int main()
{
	freopen("D:/LiuYuanHao/b.in","r",stdin);
	memset(dis,127,sizeof dis);
	scanf("%lld",&n);
	fo(i,1,n)
	{
		scanf("%lld%lld",&a[i].x,&a[i].y);
	}
	fo(i,1,n)
	{
		dis[i][i]=0;
		fo(j,1,n)
		if(dis[i][j]>2)
		if((a[i].x>a[j].x&&a[i].y>a[j].y) || (a[i].x<a[j].x&&a[i].y<a[j].y))
		{
			dis[i][j]=dis[j][i]=1;
		}
	}
	fo(k,1,n) fo(i,1,n) 
	if(i!=k) fo(j,1,n)
	if(i!=j&&j!=k)
	if(dis[i][k]<oo&&dis[k][j]<oo)
	if(dis[i][j]>dis[i][k]+dis[k][j])
	{
		dis[i][j]=dis[i][k]+dis[k][j];
		dis[j][i]=dis[i][j];
	}
	fo(i,1,n) fo(j,1,n)
		ans[i]+=dis[i][j];
	fo(i,1,n) printf("%lld\n",ans[i]);
	return 0;
}
