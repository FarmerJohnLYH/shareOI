#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N=100100;
int n,m,p;
int a[N],t[N*4],b[N];
pair<int,int> q[N],g[N];int g0;
ll c[N],sum;
#define lowbit(x) ((x)&(-(x)))
void add(int x,int v)
{
	for(;x<=n;x+=lowbit(x)) t[x]+=v;
}
int qry(int x)
{
	int rt=0;
	for(;x;x-=lowbit(x)) rt+=t[x];
	return rt;
}
ll va[N];
int main()
{
	freopen("D:/LiuYuanHao/","r",stdin);
	scanf("%d%d",&n,&m);
	fo(i,1,n) scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+1+n);p=unique(b+1,b+1+n)-b;
	fo(i,1,n) a[i]=lower_bound(b+1,b+1+p,a[i])-b;
	fd(i,n,1)
	{
		c[i]=qry(a[i]);
		sum+=c[i];
		va[a[i]]+=c[i];
		add(a[i]+1,1);
	}
	memset(t,0,sizeof t);
	fo(i,1,m) scanf("%d",&q[i].fi),q[i].se=i; 
	sort(q+1,q+1+m);
	int tmp=0;
	fo(i,1,m)
	if(q[i].fi!=q[i-1].fi)
	{
		int x=q[i].fi;
		if(a[x]<=tmp) continue;
		tmp=max(tmp,a[x]);
		g[++g0]=q[i];
		swap(g[g0].fi,g[g0].se);
	}
	sort(g+1,g+1+g0);
	printf("%lld\n",sum);
	int las=0;
	fo(i,1,g0)
	{
		fo(k,1,g[i].fi-g[i-1].fi-1) printf("%lld\n",sum);
2		fo(j,las+1,a[i]) sum-=va[i];
	}
	return 0;
}








