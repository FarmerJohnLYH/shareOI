#pragma GCC optimize(2)
#pragma comment(linker, "/STACK:102400000,102400000") 
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (ll pq = (y),i = (x);i <= pq;++ i)
#define fd(i,x,y) for (ll pq = (y),i = (x);i >= pq;-- i)
#define oo 2139062143
using namespace std;
typedef long double db;
typedef long long ll;
ll lowbit(ll x) {return((x)&(-x));}
ll min(ll x,ll y){return (x>y)?(y):(x);}
ll max(ll x,ll y){return (x>y)?(x):(y);}
const ll N=4*500500;
ll n;
ll fa[N];
db f[N],g[N];
db d[N],v[N],q[N],ans;
ll to[N],nex[N],las[N];
ll tot,ts=0;
void link(ll x,ll y,db V)
{
	(++tot)[to]=y,tot[nex]=las[x],v[tot]=V;
	las[x]=tot;
}
int dt[N],d0;
int hd;
void bfs(int tp)
{
	hd=0;
	dt[d0=1]=1;
	while(hd++<d0)
	{
		int x=dt[hd];
		for (ll tmp=x[las];tmp;tmp=tmp[nex])
		if(tmp[to]!=fa[x])
			dt[++d0]=tmp[to],fa[to[tmp]]=dt[hd],d[to[tmp]]=v[tmp];
	}
}
void work(int tp)
{
	if(!tp)
	fd(i,d0,1)
	{
		int x=dt[i];
		f[x]=1-q[x];
		for (ll tmp=x[las];tmp;tmp=tmp[nex])
		if(tmp[to]!=fa[x])
		{
			ll t=tmp[to];
			d[t]=v[tmp];
			f[x]*=f[t]+(1-f[t])*(1-d[t]);
		}
	}
	if(tp)
	fo(i,1,d0)
	{
		int x=dt[i];
		db tmp;
		if((f[x]+(1-f[x])*(1-d[x]))==0) tmp=0;
		else tmp=(f[fa[x]]*g[fa[x]])/(f[x]+(1-f[x])*(1-d[x]));
		g[x]=tmp+(1-tmp)*(1-d[x]);
		
	}
//	printf(" ");
}
int main()
{
	 freopen("charger.in","r",stdin);
	 freopen("charger.out","w",stdout);
//	freopen("D:/LiuYuanHao/c1.in","r",stdin);
	scanf("%lld",&n);
	fo(i,1,n-1)
	{
		ll a,b,p;
		scanf("%lld%lld%lld",&a,&b,&p);
		link(a,b,(db)p/100),link(b,a,(db)p/100);
	}
	fo(i,1,n) 
	{
		scanf("%Lf",&q[i]);
		q[i]=(db)q[i]/100;
	}
	int hd;
	bfs(0);
	work(0),work(1);
	fo(i,1,n) ans=(ans+(db)(1-(db)(f[i]*g[i])));
	printf("%.6Lf",ans);
	return 0;
}

