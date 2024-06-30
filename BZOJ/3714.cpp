#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
#define fi first
#define se second
#define mp make_pair
using namespace std;
typedef long long ll;
const ll N=2020;
priority_queue< pair<ll,ll> > qu;
ll n,m;
bool bz[N];
vector< pair<ll,ll> > to[N];
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%lld",&n);
	fo(i,1,n)
	{
		fo(j,i,n)
		{
			ll v;
			scanf("%lld",&v);
			to[i].push_back(mp(-v,j+1)),to[j+1].push_back(mp(-v,i));
		}
	}
	if(++n)
	{
		int tp=to[1].size();
		fo(i,0,tp-1) qu.push(to[1][i]);
	}bz[1]=1;
	ll ans=0;
	fo(i,2,n)
	{
		pair<ll,ll> q=qu.top();qu.pop();
		while(bz[q.se]&&!qu.empty()) q=qu.top(),qu.pop();
		if(!bz[q.se])
		{
			bz[q.se]=1;
			ans+=-q.fi;
			int tp=to[q.se].size();
			fo(i,0,tp-1) qu.push(to[q.se][i]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}











