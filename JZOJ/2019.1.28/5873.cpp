#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef __int128 ll;
const int N=1010,M=1000010000;
int n,m;
struct node{
	ll ax,ay,v;
	int x,y;
}a[N];
ll g[N][N],f[N][N];
bool cmx(node a,node b)
{
	return(a.ax<b.ax);
}
bool cmy(node a,node b)
{
	return(a.ay<b.ay);
}
ll v[2][N];
int d0,d1;
void init()
{
	scanf("%d%d",&n,&m);
	fo(i,1,n)
	{
		long long px,py,pv;
		scanf("%lld%lld%lld",&px,&py,&pv);
		a[i].ax=px,a[i].ay=py,a[i].v=pv;
	}
	sort(a+1,a+1+n,cmx);
	int tp=1;
	a[1].x=1;
	v[0][1]=a[1].ax;
	fo(i,2,n)
	{
		if(a[i].ax!=a[i-1].ax) ++tp;
		a[i].x=tp;
		v[0][tp]=a[i].ax;
	}
	d0=tp;
	sort(a+1,a+1+n,cmy);
	tp=1;
	a[1].y=1;
	v[1][1]=a[1].ay;
	fo(i,2,n)
	{
		if(a[i].ay!=a[i-1].ay) ++tp;
		a[i].y=tp;
		v[1][tp]=a[i].ay;
	}
	d1=tp;
}
ll ans;
void add(ll &x,ll y)
{
	if(y>x) x=y,ans=max(ans,y);
}
int buf[100],b0;
void write(ll a)
{
	if(a==0) 
	{
		printf("0");
		return;
	}
	b0=0;
	while(a)
	{
		buf[++b0]=a%10;
		a/=10;
	}
	fd(i,b0,1) putchar(buf[i]+'0');
}
int main()
{
	freopen("growth.in","r",stdin);
	freopen("growth.out","w",stdout);
	// freopen("D:/LiuYuanHao/b1.in","r",stdin);
	init();
	fo(i,1,n)
		g[a[i].x][a[i].y]+=a[i].v;
	ans=0;
	fo(i,1,n) fo(j,1,n) g[i][j]+=g[i-1][j]+g[i][j-1]-g[i-1][j-1];
	fo(i,1,d0) fo(j,1,d1)
	{
		int q=m-(v[0][i]+v[1][j])+1;
		if(q>0)
		{
			add(f[i][j],f[i-1][j]+q*(g[i][j]-g[i-1][j]));
			add(f[i][j],f[i][j-1]+q*(g[i][j]-g[i][j-1]));
			add(ans,f[i][j]);
		}
	}
	write(ans);putchar('\n');
	return 0;
}








