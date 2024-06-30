#pragma GCC optimize(2) 
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for(ll i=(x);i<=(y);++i)
#define fd(i,x,y) for(ll i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=600600,cc=20;
int n;
int to[N*2],nex[N*2],las[N],fa[N],tot;
inline void link(ll x,ll y)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
}
ll ans,dep[N],cnt;
int d[N*2],d0,p[N],w[N],mn[22][N*2],pr[N],su[N],lg[N*2];
#define smn(x,y) ((dep[x]<dep[y]?(x):(y)))
void dfs(int x)
{
	dep[x]=dep[fa[x]]+1;cnt+=dep[x];
	d[++d0]=x,w[x]=d0;
	mn[0][d0]=d[d0];
	for(ll tp=las[x];tp;tp=tp[nex])
	if(to[tp]!=fa[x])
	{
		to[tp][fa]=x;
		dfs(to[tp]);
		d[++d0]=x;
		mn[0][d0]=d[d0];
	}
}
inline int lca(int x,int y)
{
	x=w[x],y=w[y];
	if(x>y)swap(x,y);
	int d=lg[y-x+1];
	return(smn(mn[d][x],mn[d][y-(1<<d)+1]));
}
inline int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
}
ll a[N];int r[22][N];
#define vmn(x,y) ((a[x]<a[y])?x:y)
int find(int x,int y)
{
	if(x>y)swap(x,y);
	int d=lg[y-x+1];
	return(vmn(r[d][x],r[d][y-(1<<d)+1]));
}
int ccc;
void calc(ll l,ll r)
{
	if(l>=r) return;
	ll mid=find(l,r);
	ans=ans+((mid-l+1)*(r-mid+1)-1)*a[mid];
	ccc+=((mid-l+1)*(r-mid+1)-1);
	calc(l,mid-1),calc(mid+1,r);
}
int main()
{
	  freopen("easy.in","r",stdin);
	  freopen("easy.out","w",stdout);
//	freopen("D:/LiuYuanHao/b.in","r",stdin);
//	freopen("D:/LiuYuanHao/b.out","w",stdout);
	n=read();
	fo(i,1,n-1) 
	{
		ll x=read(),y=read();
		link(x,y),link(y,x);
	}
	fo(i,1,n) p[i]=read();
	lg[1]=0;fo(i,2,n*2) lg[i]=lg[i>>1]+1;
	dfs(1);
	fo(i,1,cc) fo(x,1,d0)
		if(x+(1<<(i-1))<=d0) mn[i][x]=smn(mn[i-1][x],mn[i-1][x+(1<<(i-1))]);	
		else mn[i][x]=mn[i][x-1];
	fo(i,1,n-1) a[i]=dep[lca(p[i],p[i+1])],r[0][i]=i,ans+=a[i];
	fo(i,1,cc) fo(x,1,n-1)
		if(x+(1<<(i-1))<=n-1) r[i][x]=vmn(r[i-1][x],r[i-1][x+(1<<(i-1))]);	
		else r[i][x]=r[i][x-1];
	calc(1,n-1);
	printf("%lld\n",ans+cnt);
	return 0;
}





