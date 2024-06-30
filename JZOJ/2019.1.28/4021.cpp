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
typedef unsigned long long ull;
typedef pair<int,int> PI;
int abs(int x) {return(((x)>=0)?(x):(-(x)));}
int max(int x,int y) {return(((x)>(y))?(x):(y));}
int min(int x,int y) {return(((x)<(y))?(x):(y));}
int lowbit(int x) {return((x)&(-x));}
const int N=100100;
ll a[N],mx=0;
ll c[N],v[2],all;
ll ans[N],A=0,tot;
int n;
void dfs(int x,int t)
{
	if(x>n)
	{
		if((v[0]+v[1]>A)||(tot<v[1]&&v[0]+v[1]==A))
		{
			A=v[0]+v[1],tot=v[1];
			fo(i,1,n) ans[i]=c[i]+1;
		}
		return;
	}
	dfs(x+1,t);
	v[1]^=a[x],v[0]^=a[x];
	c[x]=1-c[x];
	dfs(x+1,t+1);
	c[x]=1-c[x];
	v[1]^=a[x],v[0]^=a[x];
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%lld",&n);
	fo(i,1,n)
	{
		scanf("%lld",&a[i]);
		c[i]=0,v[0]^=a[i];
	}
	all=v[0];
	dfs(1,0);
	fo(i,1,n) printf("%lld ",ans[i]);
	return 0;
}











