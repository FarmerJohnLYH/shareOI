#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
#define fd(i,x,y) for(int i=(x);i>=(y);--i)
using namespace std;
const int N=500500,mo=998244353;
int n;
int to[N*2],nex[N*2],las[N],tot,all;
int qsm(int a,int b)
{
	int rt=1;
	fo(i,0,30)
	{
		if((1<<i)&b) rt=1ll*rt*a%mo;
		a=1ll*a*a%mo;
	}
	return rt;
}
int du[N];
void link(int x,int y)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
	++du[y];
}
int dep[N],le,ri,fa[N];
void dfs(int x,int f)
{
	if(ri==0||dep[x]>dep[ri]) ri=x;
	for(int tp=las[x];tp;tp=tp[nex])
	if(to[tp]!=f)
	{
		to[tp][dep]=dep[x]+1;
		to[tp][fa]=x;
		dfs(to[tp],x);
	}
}
int d[N],d0;
int v[N];
int find(int x,int f,int v)
{
	if(dep[x]==v) return 1;
	int rt=0;
	for(int tp=las[x];tp;tp=tp[nex])
	if(to[tp]!=f)
	{
		dep[tp[to]]=dep[x]+1;
		rt+=find(tp[to],x,v);
	}
	return rt;
}
int jc[N],ny[N];
int ans;
int C(int n,int m)
{
	return(1ll*jc[n]*ny[m]%mo*ny[n-m]%mo);
}
int main()
{
//	freopen("D:/LiuYuanHao/a1.in","r",stdin); 
	freopen("winer.in","r",stdin);
	freopen("winer.out","w",stdout);
	scanf("%d",&n);
	fo(i,1,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		link(x,y),link(y,x);
	}
	fo(i,1,n) if(du[i]==1) ++all;
	dep[1]=0; fa[1]=0;dfs(1,0);swap(le,ri);
	dep[le]=0; fa[le]=0;dfs(le,0);
	if(dep[ri]&1)
	{
		int q=dep[ri]/2,x=ri;
		fo(i,1,q) x=fa[x];
		dep[x]=0;
		d[1]=find(x,fa[x],q);
		dep[fa[x]]=0;
		d[d0=2]=find(fa[x],x,q);
		d[0]=d[1]+d[2];
	}
	else
	{
		int q=dep[ri]/2,x=ri;
		fo(i,1,q) x=fa[x];
		for(int tp=las[x];tp;tp=tp[nex])
		{
			dep[to[tp]]=1;
			d[++d0]=find(to[tp],x,q);
			if(d[d0]==0) --d0;
			else d[0]+=d[d0];
		}
	}
	jc[0]=1;fo(i,1,all) jc[i]=1ll*jc[i-1]*i%mo;ny[all]=qsm(jc[all],mo-2);
	fd(i,all-1,0)ny[i]=(1ll*ny[i+1]*(i+1))%mo;
	v[d[0]]=(1ll*ny[d[0]]*jc[d[0]-1]%mo)*all%mo;
	fd(i,d[0]-1,1) v[i]=(v[i+1]+(1ll*ny[i]*jc[i-1]%mo)*all%mo)%mo;
	ans=0;
	fo(i,1,d0)
		fo(j,0,d[i]-1)
			ans=(ans+1ll*jc[d[0]-d[i]+j-1]*(d[0]-d[i])%mo*v[d[i]-j+1]%mo*jc[d[i]-j]%mo*C(d[i],j)%mo)%mo;
	ans=(1ll*ans*ny[d[0]])%mo;
	printf("%d\n",ans);
	return 0;
}



