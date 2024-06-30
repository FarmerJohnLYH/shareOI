#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=500500;
int tot,nex[N],las[N];
ll ans,a[N],v[N];
void link(int x,int y)
{
	v[++tot]=y,nex[tot]=las[x],las[x]=tot;
}
ll t[4*N];
void add(int l,int r,int p,int k,ll o)
{
	if (l>r||l>k||r<k) return;
	t[p]+=o;
	if(l==r&&l==k) return;
	int mid=(l+r)>>1;
	add(l,mid,p<<1,k,o);
	add(mid+1,r,p<<1|1,k,o);
}

int query(int l,int r,int p,ll k)
{
	if(t[p]<k)return 0;
	if(l==r&&k<=t[p])return r;
	int mid=(l+r)>>1;
	if(t[p<<1|1]>=k)return query(mid+1,r,p<<1|1,k);
	return query(l,mid,p<<1,k-t[p<<1|1]);
}
int n,m,p;
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d%d",&n,&m,&p);
	fo(i,1,n)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		y+=m+1,z+=m+1;
		if(y<z)
			link(y,x),link(z,-x);
		else
		if(y>z)
			link(y,x),link(1,x),link(z,-x);
	}
	fo(i,1,2*m)
	{
		for(int tp=las[i];tp;tp=tp[nex]) 
		if(tp[v]>0) add(1,N,1,tp[v],1);
		else add(1,N,1,-tp[v],-1);
		ll o=query(1,N,1,p);
		ans+=o*o;
	}
	printf("%lld\n",ans);
}
