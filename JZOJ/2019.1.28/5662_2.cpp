#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x),asdfgh=(y);i<=asdfgh;++i)
#define fd(i,x,y) for (int i=(x),asdfgh=(y);i>=asdfgh;--i)
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int,int> PI;
int abs(int x) {return(((x)>=0)?(x):(-(x)));}
int max(int x,int y) {return(((x)>(y))?(x):(y));}
int min(int x,int y) {return(((x)<(y))?(x):(y));}
int lowbit(int x) {return((x)&(-x));}
const int N=2002000,mo=1000000007;
struct data{
	int l,r;
}son[N];
ll f[N],sum[N],a[N],fa[N],sz[N],b[N],c[N];
int n,q,opt,x,s;
ll ans;
struct tree{
	int l,r;
	ll mul;
}t[N*4];
void dfs(int x)
{
    sz[x]=1;
    if(son[x].l) dfs(son[x].l);
    b[++s]=x;c[x]=s;
    if(son[x].r)dfs(son[x].r);
    sum[x]=(sum[son[x].l]+sum[son[x].r]+a[x])%mo;
    f[x]=((f[son[x].l]*f[son[x].r])%mo*sum[x])%mo;
    sz[x]+=sz[son[x].l]+sz[son[x].r];
}
void build(int rt,int l,int r)
{
    t[rt].l=l,t[rt].r=r;
    if (l==r)
	{
        t[rt].mul=sum[b[l]];
        return;
    }
    int mid=(l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    t[rt].mul=(t[rt<<1].mul*t[rt<<1|1].mul)%mo;
}
void change(int rt,int l,int r,int x,int y)
{
    if (l==r)
	{
        t[rt].mul=y;
        return;
    }
    int mid=(l+r)>>1;
    if(mid>=x) change(rt<<1,l,mid,x,y);
    else change(rt<<1|1,mid+1,r,x,y);
    t[rt].mul=(t[rt<<1].mul*t[rt<<1|1].mul)%mo;   
}
ll solve(int rt,int l,int r,int x,int y)
{
    if(l==x&&r==y)
		return(t[rt].mul); 
    int mid=(l+r)>>1;
    ll ret=1;
    	 if(y<=mid)ret=(ret*solve(rt<<1,l,mid,x,y))%mo;
    else if(x>mid)ret=ret*solve(rt<<1|1,mid+1,r,x,y)%mo;
    else ret=ret*solve(rt<<1,l,mid,x,mid)%mo,ret=ret*solve(rt<<1|1,mid+1,r,mid+1,y)%mo;
	return ret;
}
void rrotate(int x)
{
    int y=son[x].l;
    if (son[fa[x]].l==x) son[fa[x]].l=y; else son[fa[x]].r=y;
    int u=sz[y];
    sz[y]=sz[x];sz[x]=sz[x]-u+sz[son[y].r];
    fa[son[y].r]=x;fa[y]=fa[x];fa[x]=y;
    son[x].l=son[y].r;son[y].r=x;
    sum[x]=(sum[son[x].l]+sum[son[x].r]+a[x])%mo;
    change(1,1,n,c[x],sum[x]);
    sum[y]=(sum[son[y].l]+sum[son[y].r]+a[y])%mo;
    change(1,1,n,c[y],sum[y]);
}
void lrotate(int x)
{
    int y=son[x].r;
    if(son[fa[x]].l==x) son[fa[x]].l=y; else son[fa[x]].r=y;
    int u=sz[y];
    sz[y]=sz[x];sz[x]=sz[x]-u+sz[son[y].l];
    fa[son[y].l]=x;fa[y]=fa[x];fa[x]=y;
    son[x].r=son[y].l;son[y].l=x;
    sum[x]=(sum[son[x].l]+sum[son[x].r]+a[x])%mo;
    change(1,1,n,c[x],sum[x]);
    sum[y]=(sum[son[y].l]+sum[son[y].r]+a[y])%mo;
    change(1,1,n,c[y],sum[y]);
}
int main(){
//	freopen("D:/LiuYuanHao/b.in","r",stdin);
     freopen("splay.in","r",stdin);
     freopen("splay.out","w",stdout);
    scanf("%d%d",&n,&q);
    f[0]=1;
    fo(i,1,n)
    {
        scanf("%d%d%d",&a[i],&son[i].l,&son[i].r);
        f[i]=1;
        son[i].l[fa]=i,son[i].r[fa]=i;
    }
    fo(i,0,N-1)t[i].mul=1;
    dfs(1);
    build(1,1,n);
    fo(i,1,q)
    {   
		int opt,x; 
		scanf("%d%d",&opt,&x);
        if(opt==0&&son[x].l) rrotate(x);
        if(opt==1&&son[x].r) lrotate(x);
        if(opt==2)
		{
            ans=1;
            printf("%lld\n",solve(1,1,n,c[x]-son[x].l[sz],c[x]+son[x].r[sz]));
        }
    }
}

