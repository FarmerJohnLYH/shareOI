#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x),asdfgh=(y);i<=asdfgh;++i)
#define fd(i,x,y) for (int i=(x);asdfgh=(y);i>=asdfgh;--i)
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
const int N=40040;
int n;
ll m;
int t[N],r[N],R[N];
ll q[N],f[N];
PI a[N];
int main()
{
	freopen("D:/LiuYuanHao/c2.in","r",stdin);
	scanf("%d%lld",&n,&m);
	fo(i,1,n)
		scanf("%d%d",&a[i].fi,&a[i].se);
	a[++n].fi=1000100,a[n].se=0;
	sort(a+1,a+1+n);
	fo(i,1,n) 
	{
		t[i]=a[i].fi,r[i]=a[i].se;
		R[i]=R[i-1]+r[i];
		q[i]=1ll*r[i]*t[i]+q[i-1];
	}
	memset(f,127,sizeof f);
	f[0]=0;
	ll ans=0;
	fo(i,1,n)
	{
		ll cnt=0;
		fo(j,0,i-1)
		{
			f[i]=min(f[i],f[j]+q[i-1]-q[j]-1ll*t[j]*(R[i-1]-R[j])+m);
		}
	}
	printf("%lld",f[n]-m);
}











