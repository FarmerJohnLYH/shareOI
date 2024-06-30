 #pragma GCC optimize(2) 
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
#define fi first 
#define se second
using namespace std;
typedef pair<int,int> PI;
const int N=500500;
int n,m;
int h[N],d[N],f[N],g[N];
vector<PI> tw[N];
int mx[N],bz[N],d0,cnt[N];
int find(int x,int ty)
{
	int le=0,ri=d0,mid,rt=0;
	while(le<=ri)
	{
		mid=(le+ri)>>1;
		if(d[mid]*ty<x*ty)rt=mid,le=mid+1; 
		else ri=mid-1;
	}
	return rt;
}
int all,ans,w[N],pr[N];
void run()
{
	d[d0=0]=-oo;
	memset(f,0,sizeof f);
	fo(i,1,n)
	{
		for(int p=tw[i].size()-1,j=0;j<=p;++j)
			mx[tw[i][j].se]+=find(tw[i][j].fi,1);
		int p=find(h[i],1);
		if(p==d0) d[d0=p+1]=h[i];
		else d[p+1]=min(d[p+1],h[i]);
		f[i]=p+1;
	}
	ans=d0;
	d[d0=0]=oo;
	memset(g,0,sizeof g);
	fd(i,n,1)
	{
		for(int p=tw[i].size()-1,j=0;j<=p;++j)
			mx[tw[i][j].se]+=find(tw[i][j].fi,-1);
		int p=find(h[i],-1);
		if(p==d0) d[d0=p+1]=h[i];
		else d[p+1]=max(d[p+1],h[i]);
		g[i]=p+1;
	}
	fo(i,1,n)
		if(f[i]+g[i]==ans+1) ++cnt[f[i]];
}
int qa[N],qb[N];
int main()
{
//	freopen("kite.in","r",stdin);
//	freopen("kite.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%d%d",&n,&m);
	fo(i,1,n) scanf("%d",&h[i]);
	fo(i,1,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		qa[i]=x,qb[i]=y;
		tw[x].push_back(make_pair(y,i));
	}
	run();
	all=ans;
	fo(i,1,m)
	{
		int x=qa[i],y=qb[i],pre;
		pre=all;
		if(cnt[f[x]]==1&&f[x]+g[x]==all+1) --pre;
		printf("%d\n",max(mx[i]+1,pre));
	}
	return 0;
}








