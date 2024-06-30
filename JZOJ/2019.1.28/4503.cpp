#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fi first
#define se second
#define mp make_pair
using namespace std;
typedef long long ll;
const int N=30030,L=16;
int n;ll a[N];
vector< pair<int,ll> >to[N];
vector<int> lk[N];
int vis[N],siz[N],cp[N];
ll sm[N][L];
int rot,all;
int te[N],cnt;
int fa[N][L],sz[N][L],ct[N];
void dfs(int x,int f,ll dp,int k)
{
	te[++cnt]=x;
	sm[x][k]=(a[x]&(1<<k))?(dp):0,siz[x]=1,cp[x]=0;
	for(int p=to[x].size()-1,i=0;i<=p;++i)
	if(!to[x][i].fi[vis]&&to[x][i].fi!=f)
	{
		dfs(to[x][i].fi,f,dp+to[x][i].se,k);
		sm[x][k]+=sm[to[x][i].fi][k];
		siz[x]+=to[x][i].fi[siz];
		cp[x]=max(cp[x],to[x][i].fi[siz]);
	}
	cp[x]=max(cp[x],all-siz[x]);
	if(rot==0||cp[x]<cp[rot]) rot=x;
}
ll ans[N][L],ams;
void solve(int x)
{
	vis[x]=1;
	memset(ans[x],0,sizeof ans[x]);
	fo(l,0,13)
	{
		cnt=0;
		dfs(x,0,0,l);
		fo(i,2,cnt) 
		{
			int px=te[i];
			ans[x][l]=ans[x][l]+sm[px][l]*(sm[x][l]-sm[px][l]);
		}
		ams=ams+ans[x][l]*(1<<l);
	}
	fo(i,2,cnt)
	{
		int px=te[i];
		fa[px][++ct[px]]=x,sz[px][ct[px]]=siz[px];
	}
	for(int p=to[x].size()-1,i=0;i<=p;++i)
	if(!to[x][i].fi[vis])
	{
		rot=0,all=siz[to[x][i].fi];
		dfs(to[x][i],0,0,0);
		solve(rot);
	}
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d",&n);
	fo(i,1,n) scanf("%lld",&a[i]);
	fo(i,1,n-1)
	{
		int x,y;ll c;
		scanf("%d%d%lld",&x,&y,&c);
		to[x].push_back(mp(y,c));
		to[y].push_back(mp(x,c));
	}
	ams=0;
	solve(1);int T;
	scanf("%d",&T);
	while(T--)
	{
		int px;ll pv;
		scanf("%d%lld",&px,&pv);
		fo(i,1,px[ct])
		{

		}
	}
	return 0;
}








