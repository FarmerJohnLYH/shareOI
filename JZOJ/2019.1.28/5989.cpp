#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=200200;
int n,m,q;
int tot,to[N*2],nex[N*2],las[N];
ll d[N],e[N],b[N],c[N],pe[N];
void link(int x,int y)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
}
priority_queue<ll> mx1,mx0,mn1,mn0;
int a[N];
void up(ll x,ll y)
{
	mx0.push(x),mn0.push(-x);
	mx1.push(y),mn1.push(-y);
}
void solve()
{
	memset(las,0,sizeof las);
	tot=0;
	fo(i,1,n)d[i]=1;
	fo(i,1,n) 
	{
		int p=a[i];
		link(i,p),link(p,i);
		++d[i],++d[p];
	}
	fo(i,1,n)e[i]=b[i]/d[i];
	fo(i,1,n)
	{
		c[i]=b[i]%d[i]+e[i];
		for(int tp=las[i];tp;tp=tp[nex])
		if(to[tp]!=a[i])
			c[i]+=e[to[tp]];
	}
}
ll ff(int y)
{
	return(y[b]/y[d]);
}
void 
int main()
{
	// freopen("forest.in","r",stdin);
	// freopen("forest.out","w",stdout);
	freopen("D:/LiuYuanHao/c.in","r",stdin);
	scanf("%d%d",&n,&q);
	fo(i,1,n) scanf("%lld",&b[i]);
	fo(i,1,n) scanf("%d",&a[i]);
	solve();
	fo(i,1,n) mx1.push(c[i]),mn1.push(-c[i]);
	while(q--)
	{
		int t;
		scanf("%d",&t);
		if(t==3)
		{
			ll q=mn1.top();
			while(!mn0.empty()&&q==mn0.top()) mn1.pop(),mn0.pop(),q=mn1.top();
			printf("%lld ",-q);
			 q=mx1.top();
			while(!mx0.empty()&&q==mx0.top()) mx1.pop(),mx0.pop(),q=mx1.top();
			printf("%lld\n",q);
		}
		if(t==2) 
		{
			int x;scanf("%d",&x);
			printf("%lld\n",c[x]+ff(a[x]));
		}
		if(t==1)
		{
			int x,z;scanf("%d%d",&x,&z);
			int y=a[x];a[x]=z;
			int d1=c[y],d2=c[z];c[y]-=ff(x),c[z]+=ff(x);
			
			cg(y,-1);
			cg(z,+1);
		}
	}
	return 0;
}








