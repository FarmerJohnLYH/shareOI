#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=100100,M=200200;
int v[N],n,q;
int to[M],nex[M],las[N],tot;
ll ans;
void link(int x,int y)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
}
int bz[N];
void go(int x,int fa)
{
	bz[x]=1;
	for(int tp=las[x];tp;tp=tp[nex])
	if(to[tp]!=fa && to[tp][v])
		go(to[tp],x);
}
void run(int x,int d,int fa)
{
	if(!bz[x] && v[x]==1) ++ans,go(x,fa);	
	if(d>0)
	for(int tp=las[x];tp;tp=tp[nex])
	if(to[tp]!=fa)
		run(to[tp],d-1,x);
}
int du[N];
int dp[N];
struct node{
	int l,r,an;
}t[N*4];
node comb(node a,node b)
{
	node rt;rt.an=a.an+b.an;if(a.an==-1) return b;
	rt.l=a.l,rt.r=b.r;
	if(a.r&&b.l) rt.an-=1;
	return rt;
}
void cg(int x,int l,int r,int p,int v)
{
	// node rt;
	if(l==r)
	{
		t[x].l=t[x].r=t[x].an=v;
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid)cg(x<<1,l,mid,p,v);
	else cg(x<<1|1,mid+1,r,p,v);
	t[x]=comb(t[x<<1],t[x<<1|1]);
}
node query(int x,int l,int r,int ql,int qr)
{
	node rt;rt.an=-1;
	if(ql<=l&&r<=qr)
		return(t[x]);
	int mid=(l+r)>>1;
	if(ql<=mid)rt=(query(x<<1,l,mid,ql,qr));
	if(qr>mid) rt=comb(rt,query(x<<1|1,mid+1,r,ql,qr));
	return rt;
}
void dfs(int x,int f)
{
	dp[x]=dp[f]+1;
	for(int tp=las[x];tp;tp=tp[nex])
		if(to[tp]!=f)
			dfs(to[tp],x);
}
int main()
{
	freopen("lights.in","r",stdin);
	freopen("lights.out","w",stdout);
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&q);
	int flag=1;
	fo(i,1,n-1)
	{
		int x,y;scanf("%d%d",&x,&y);
		link(x,y),link(y,x);
		++du[x],++du[y];
		if(du[x]>2||du[y]>2) flag=0;
	}
	if(flag)
	{
		fo(i,1,n) if(du[i]==1)
		{
			dfs(i,0);
			break;
		}
		fo(i,1,n) 
		{
			char ch=getchar();while(ch!='0'&&ch!='1')ch=getchar();
			v[dp[i]]=ch-'0';
			cg(1,1,n,dp[i],v[dp[i]]);
		}
		fo(i,1,q)
		{
			int t,x,d;
			scanf("%d%d",&t,&x);
			if(t==1) v[dp[x]]^=1,cg(1,1,n,dp[x],v[dp[x]]);
			else
			{
				scanf("%d",&d);
				node ans=query(1,1,n,max(1,dp[x]-d),max(1,dp[x]-1));
				node bns=query(1,1,n,min(n,dp[x]+1),min(n,dp[x]+d));
				printf("%d\n",ans.an+bns.an);
			}
		}
		return 0;
	}
	fo(i,1,n) 
	{
		char ch=getchar();while(ch!='0'&&ch!='1')ch=getchar();
		v[i]=ch-'0';
	}
	fo(i,1,q)
	{
		int t,x,d;
		scanf("%d%d",&t,&x);
		if(t==1) v[x]=1^v[x];
		else
		{
			fo(i,1,n) bz[i]=0;
			ans=0;
			scanf("%d",&d);
			bz[x]=1;
			run(x,d,0);
			printf("%lld\n",ans);
		}
	}
	return 0;
}








