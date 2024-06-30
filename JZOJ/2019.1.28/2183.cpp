#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (ll pq = (y),i = (x);i <= pq;++ i)
#define fd(i,x,y) for (ll pq = (y),i = (x);i >= pq;-- i)
#define oo 2139062143
using namespace std;
typedef double db;
typedef long long ll;
ll lowbit(ll x) {return((x)&(-x));}
ll max(ll x,ll y){return (x>y)?(x):(y);}
const ll N=110;
ll n;
struct edge{
	ll to,nex;
}e[N*2];
ll las[N],tot;
void link(ll x,ll y)
{
	e[++tot].to=y,e[tot].nex=las[x];
	las[x]=tot;
}
ll f[N][2][2];
void dfs(ll x,ll fa)
{
	ll p[2/*x是否被选*/][2/*儿子被选数*/];
	p[0][0]=p[1][0]=0;
	p[0][1]=p[1][1]=oo;
	if(e[las[x]].nex==0&&x!=1)
	{
		
		f[x][0][0]=0;
		f[x][0][1]=oo;
		f[x][1][1]=1;
		f[x][1][0]=oo;
		return;
	}
	for (ll tmp=las[x];tmp;tmp=e[tmp].nex)
	if(e[tmp].to!=fa)
	{
		ll to=e[tmp].to;
		dfs(to,x);
		ll gt[2][2];
		memcpy(gt,p,sizeof(p));
		p[0][0]=min(gt[0][0]+f[to][0][1],gt[0][1]+f[to][1][1]);
		p[0][1]=min(gt[0][1]+f[to][0][1],gt[0][0]+f[to][1][1]);
		p[1][0]=min(gt[1][0]+f[to][0][0],gt[1][1]+f[to][1][0]);
		p[1][1]=min(gt[1][1]+f[to][0][0],gt[1][0]+f[to][1][0]);
	}
	//x col_x chose_x 
	f[x][0][0]=p[0][0];
	f[x][0][1]=p[0][1];
	f[x][1][1]=p[1][0]+1;
	f[x][1][0]=p[1][1]+1;
	printf("");
}
int main()
{
//	freopen("D:/LiuYuanHao/b.in","r",stdin);
//	freopen("D:/LiuYuanHao/b.out","w",stdout);
	for (scanf("%lld",&n);n;scanf("%lld",&n))
	{
////		memset(f,127,sizeof f);
		fo(i,0,N-1) fo(j,0,1)fo(k,0,1) f[i][j][k]=oo;
		memset(las,0,sizeof las);
		tot=0;
		//clear
		
		fo(i,1,n-1)
		{
			ll x,y;
			scanf("%lld%lld",&x,&y);
			link(x,y),link(y,x);
		}
		dfs(1,0);
		printf("%lld\n",min(f[1][0][1],f[1][1][1]));
	}
	return 0;
}
