#pragma GCC optimize(2) 
#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define abs(x) ((x<0)?(-x):(x))
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> node;
const int N=1010;
int T,n;
node a[N],c[N],d[N];int c0,d0;
int bz[N];
map<node,int> mp;
ll gcd(ll x,ll y)
{
	return((y==0)?x:(gcd(y,x%y)));
}
ll b[N];
ll dot(node a,node b)
{
	return(a.x*b.x+a.y*b.y);
}
int check(node a)
{
	fo(i,1,c0)
		b[i]=dot(c[i],a);
	sort(b+1,b+1+c0);
	fo(i,1,(c0+1)/2)
	if(b[i]!=-b[c0-i+1])
		return 0;
	return 1;
}
node get(int i,int j)
{
	node p=node(-(c[i].y+c[j].y)/2,(c[i].x+c[j].x)/2);
	ll c=gcd(abs(p.x),abs(p.y));
	if(p.x<0||(p.x==0&&p.y<0))c=-c;
	p.x/=c,p.y/=c;
	return p;
}
int main()
{
	freopen("life.in","r",stdin);
	freopen("life.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		ll sx=0,sy=0,ans=0;
		scanf("%d",&n);
		fo(i,1,n)
		{
			bz[i]=0;
			scanf("%lld%lld",&a[i].x,&a[i].y);
			a[i].x*=2*n,a[i].y*=2*n;
			sx+=a[i].x,sy+=a[i].y;
		}
		sx/=n,sy/=n;
		fo(i,1,n) 
		{
			a[i].x-=sx,a[i].y-=sy;
			if(a[i].x==a[i].y&&a[i].x==0) bz[i]=1;
		}
		fo(i,1,n) fo(j,i+1,n)
		if((!bz[i]) && (!bz[j]))
			if(a[i].x+a[j].x==0&&a[i].y+a[j].y==0) bz[i]=bz[j]=1;
		c0=0;
		fo(i,1,n) if(!bz[i])
			c[++c0]=a[i];
		if(c0<=2) 
		{
			printf("-1\n");
			continue;
		}
		fo(i,1,c0) fo(j,i+1,c0)
		{
			node p=get(i,j);
			mp[p]+=1;
			if(mp[p]==(c0/2)&&check(p))
				++ans;
		}
		fo(i,1,c0) fo(j,i+1,c0)
		{
			node p=get(i,j);
			mp[p]=0;
		}
		printf("%lld\n",ans);
	}
	return 0;
}












