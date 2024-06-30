//#pragma GCC optimize(2) 
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mul(x,y) {x=x*((y)%mo)%mo;}
#define oo 2139062143
#define lowbit(x) ((x)&(-(x)))
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int mo=998244353,N=800800,A=10001000;
int n,q,k;
struct node{
	int t,x,c,id;
	node(){}
	node(int t_,int x_,int c_,int i_=-1){t=t_,x=x_,c=c_,id=i_;}
};
bool cmp(node a,node b)
{
	return(a.c<b.c||(a.c==b.c&&a.t>b.t));
}
int p[N],p0,bz[A];
vector<node> a[N];
void init()
{
	bz[1]=1;
	fo(i,2,A-100)
	{
		if(!bz[i]) p[++p0]=i,bz[i]=p0;
		fo(j,1,p0)
		{
			if(1ll*p[j]*i>=A-10)break;
			bz[p[j]*i]=1;
			if(i%p[j]==0)break;
		}
	}
}
int to[N],nex[N],las[N],tot;
void link(int x,int y)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
}
int fa[N],dfn[N],cnt;
int sta[N],s0,sz[N],f[N];
void dfs(int x)
{
	sz[x]=1;
	sta[++s0]=x;
	dfn[x]=++cnt;
	if(s0>k) f[x]=sta[s0-k];
	for(int tp=las[x];tp;tp=tp[nex])
	if(to[tp]!=fa[x])
	{
		to[tp][fa]=x;
		dfs(to[tp]);
		sz[x]+=to[tp][sz];
	}
	--s0;
}
ll ans[N];int tr[2][N];
ll qsm(ll x,ll y)
{
	ll rt=1;
	fo(i,0,30)
	{
//		if(y<(1<<i)) return rt;
		if(y&(1<<i)) rt=rt*x%mo;
		x=x*x%mo;
	}
	return rt;
}
void add(int x,int v,int tp)
{
	for(;x<=n;x+=lowbit(x)) tr[tp][x]+=v;
}
int query(int x,int pv)
{
	int rt=0,r2=0;
	for(;x;x-=lowbit(x)) rt+=tr[1][x],r2+=tr[0][x];
	return rt+r2*pv;
}
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
}
int buf[30],b0;
void write(ll x)
{
	b0=0;
	if(x==0)putchar('0');
	else
	while(x) buf[++b0]=x%10,x/=10;
	fd(i,b0,1) putchar(buf[i]+'0');
}
int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
//	freopen("D:/LiuYuanHao/c1.in","r",stdin);
//	freopen("D:/LiuYuanHao/c.out","w",stdout);
	init();
	n=read(),q=read(),k=read();
	fo(i,1,n) 
	{
		int x=read(),y;
		if(!x)continue;
		y=x;
		fo(j,1,p0)
		{
			if(1ll*p[j]*p[j]>y) break;
			if(y%p[j]==0)
			{
				int c=0;
				while(y%p[j]==0) y/=p[j],++c;
				a[j].push_back(node(-1,i,c));
			}
		}
		if(y!=1) a[bz[y]].push_back(node(-1,i,1)); 
	}
	fo(i,1,n-1)
	{
		int x=read(),y=read();
//		scanf("%d%d",&x,&y);
		link(x,y),link(y,x);
	}
	dfs(1);
	q+=n;
	fo(i,1+n,q)
	{
		int x,c;
		x=read(),c=read();
		int y=c;
		fo(j,1,p0)
		{
			if(1ll*p[j]*p[j]>y) break;
			if(y%p[j]==0)
			{
				int c=0;
				while(y%p[j]==0) y/=p[j],++c;
				a[j].push_back(node(1,x,c,i-n));
			}
		}
		if(y!=1) 
			a[bz[y]].push_back(node(1,x,1,i-n)); 
		ans[i-n]=1;
	}
	fo(i,1,p0)
	if(!a[i].empty())
	{
		sort(a[i].begin(),a[i].end(),cmp);
		int sp=a[i].size()-1;
		fo(j,0,sp) if(a[i][j].t==-1)
		{
			add(dfn[a[i][j].x],1,0);
			if(a[i][j].x[f])add(dfn[a[i][j].x[f]],-1,0);
		}
		fo(j,0,sp)
		{
			if(a[i][j].t==-1) 
			{
				add(dfn[a[i][j].x],a[i][j].c,1);
				if(a[i][j].x[f])add(dfn[a[i][j].x[f]],-(a[i][j].c),1);
				add(dfn[a[i][j].x],-1,0);
				if(a[i][j].x[f])add(dfn[a[i][j].x[f]],1,0);
			}
			else
			{
				int x=a[i][j].x;
				int tmp=query(dfn[x]+sz[x]-1,a[i][j].c)-query(dfn[x]-1,a[i][j].c);	
				mul(ans[a[i][j].id],qsm(p[i],tmp));
			}
		}
		//clear
		fo(j,0,sp)
			if(a[i][j].t==-1) 
			{
				add(dfn[a[i][j].x],-a[i][j].c,1);
				if(a[i][j].x[f])add(dfn[a[i][j].x[f]],(a[i][j].c),1);
			}
	}
	fo(i,1,q-n)
		write(ans[i]),puts("");
//		printf("%lld\n",ans[i]);
	return 0;
}








