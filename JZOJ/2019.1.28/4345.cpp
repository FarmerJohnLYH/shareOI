#include <map>
#include <cmath>
#include <ctime>
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
int min(int x,int y){return (x>y)?(y):(x);}
int max(int x,int y){return (x>y)?(x):(y);}
const int Mo=1e9+7,V=100100,N=44;
int n,d;
int r[N];
ll all;
map <ll,int> mp;
ll hash(ll x,ll y,ll z)
{
	return((z+y*(all+1)+((d+1)*(all+1))*x));
}
ll dfs(int pos,int las,ll sta)
{
	if(pos>d)
	{
		if(sta!=all) return 0;
		else return(1);
	}
	ll tmp=hash(las,pos,sta);
	if(mp[tmp]) 
		return(mp[tmp]);
	ll rt=0;
	fo(i,1,n)
	if(!(sta&(1<<(i-1))))
	{
		if(las<=pos-r[i])
			rt=(rt+dfs(pos+r[i],pos,sta|(1<<(i-1))))%Mo;
	}
	rt=(rt+dfs(pos+1,las,sta))%Mo;
	mp[tmp]=rt;
	return rt;
}
int main()
{
//	freopen("D:/LiuYuanHao/b1.in","r",stdin);
	scanf("%d%d",&n,&d);
	all=(1<<n)-1;
	int s=0;
	fo(i,1,n) scanf("%d",&r[i]),s+=r[i];
	printf("%lld",dfs(1,-oo,0));
	return 0;
}
