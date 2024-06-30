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
typedef pair<int,int> PI;
int abs(int x) {return(((x)>=0)?(x):(-(x)));}
int max(int x,int y) {return(((x)>(y))?(x):(y));}
int min(int x,int y) {return(((x)<(y))?(x):(y));}
int lowbit(int x) {return((x)&(-x));}
const int N = 100 + 10;
int T;
ll x,k,l,a;
ll c,d,t;
ll work()
{
	while(x) 
	{
		if(t<=d) 
		{
			ll s=(x-1)/k;//层2
			if(t+s<=d)
			{
				t+=s;
				x-=s*k;
				break;
			}
			else
			{
				x-=(d-t+1)*k;
				t=(d+1)%k;
			}
		}
		else
		{
			if(t+x-1<k)return c*a*k+t+x-1;
			else x-=k-t,t=0;
		}
	}
	return (c+1)*a*k+(t+x-1+k)%k;
}
int main() 
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld%lld",&x,&k,&l,&a);
		c=l/a/k,d=l%(a*k);
		ll g[N];
		if (d>=k-1) g[1]=k*k;//1层解决
		else g[1]=k*(d+1)+(k-(d+1));
		t=0;
		int top=1;
		while(g[top]<x&&top<=c)g[++top]=g[top-1]*k;
		x=(x-1)%g[top]+1;
		//转k进制求每一层消耗生命
		fd(i,top-1,1)
		{
			int tp=(x-1)/g[i];
				x-=tp*g[i];
			t=(t+tp)%k;
		}
		//考虑第一二层
		printf("%lld\n", work());
	}
	return 0;
}