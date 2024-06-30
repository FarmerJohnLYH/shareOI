#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=55,M=110;
const ll p1=19260817,p2=998244353;
int n,T;
int sz[N],mv[N],cnt;
vector<int> to[N],ans[M];
map<ll,int> mp;
int gs;
ll st[N],tw[N];int s0;
int du[N];
ll work(int x,int f)
{
	int le=s0+1,len=(du[x]+(f==0)-1);
	s0=le+len-1;
	for(int p=to[x].size()-1,i=0;i<=p;++i)
	if(to[x][i]!=f)
		st[le+i]=work(to[x][i],x);
	sort(st+le,st+le+len);
	ll rt=1;
	fo(i,le,le+len-1) 
		rt=(rt+tw[i-le+1]*st[i]%p2)%p2;
	s0=le-1;
	return(rt+p2)%p2;
}
void clear()
{
	s0=0;
} 
int in[M];
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&T,&n);
	tw[0]=1;
	fo(i,1,N-5) tw[i]=tw[i-1]*p1%p2;
	fo(k,1,T)
	{
		fo(i,1,n)
		{
			du[i]=0;
			while(!to[i].empty())to[i].pop_back();
		}
		fo(i,1,n-1)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			to[x].push_back(y),to[y].push_back(x);
			++du[x],++du[y];
			++in[y]; 
		}
		gs=0,s0=0;
		fo(i,1,n)if(!in[i]) gs=i;
		ll hv=work(gs,0);
		if(!mp[hv]) mp[hv]=++cnt;
		ans[mp[hv]].push_back(k);
	}
	fo(i,1,cnt)
	{
		printf("%d",ans[i][0]);
		for(int p=ans[i].size()-1,k=1;k<=p;++k)
			printf("=%d",ans[i][k]);
		printf("\n");
	}
	return 0;
}








