#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll N=32,M=1010;
ll a[N],n,c;
int ss,tt;
int tot,nex[M],las[N],cnt,v[M],d[N],g[N];
void link(int x,int y,int v)
{
	
}
int dfs(int x,int qv)
{
	if(x==tt) return qv;
	int nw=0;
	for(int tp=las[x];tp;tp=tp[nex])
	if(v[tp]>0 && d[to[tp]]+1==d[x])
	{
		int tmp=dfs(to[tp],min(v[tp],qv-nw));
		nw+=tmp,v[tp]-=tmp,v[tp^1]+=tmp;
		if(qv==nw) return qv;
	}
	--g[d[x]],++d[x],++g[d[x]];
	if(g[d[x]-1]==0) d[ss]=cnt;
	return nw;
}
int main()
{
//	freopen("juice.in","r",stdin);
//	freopen("juice.out","w",stdout);
	freopen("D:/LiuYuanHao/a1.in","r",stdin);
	scanf("%lld",&n);
	fo(i,1,n) scanf("%lld",&a[i]),a[i]*=2,a[0]+=a[i];
	sort(a+1,a+1+n);
	tot=1,cnt=n+2;
	
	return 0;
}

