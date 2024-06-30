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
const int N=80080,M=80080*2,Q=50050,V=1010;
int n,m;
int a[N];
int to[M],nex[M],las[N],tot,fr[M];
int q;
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
}
void link(int x,int y)
{
	to[++tot]=y,tot[nex]=las[x],las[x]=tot;fr[tot]=x;
}
int st[N],bz[M],s0;
int check(int x)
{
	if(x==1)return 0;
	fo(i,1,s0) 
	if(st[i][to]==x) return(0);
	return 1;
}
void dfs(int x,int en)
{
	if(x==en)
	{
		fo(i,1,s0) st[i][bz]=1;
		return;
	}
	for (int tp=las[x];tp;tp=tp[nex])
	if(check(tp[to]))
	{
		st[++s0]=tp;
		dfs(tp[to],en);
		--s0;
	}
}
int fa[N];
int gf(int x)
{
	return(x==fa[x]?(x):fa[x]=gf(fa[x]));
}
int du[V];
int main()
{
//	freopen("D:/LiuYuanHao/b.in","r",stdin);
	freopen("map.in","r",stdin);
	freopen("map.out","w",stdout);
	n=read(),m=read();
	fo(i,1,n) a[i]=read();
	fo(i,1,m)
	{
		int x=read(),y=read();
		link(x,y),link(y,x);
	}
	q=read();
	fo(i,1,q)
	{
		int ty=read(),x=read(),y=read();
		memset(bz,0,sizeof bz);
		dfs(1,x);
		fo(i,1,n) fa[i]=i;
		fo(i,1,m)
		if(!bz[i*2]&&!bz[i*2-1])
		{
			int fx=gf(fr[i*2]),fy=gf(to[i*2]);
			if(fx!=fy) fa[fx]=fy;
		}
		memset(du,0,sizeof du);
		fo(i,1,n)
			if(a[i]<=y&&gf(i)==gf(x)) ++du[a[i]];
		int ans=0;
		fo(i,1,V-10)
			if(du[i]>0) ans+=((du[i]&1)==ty);
		printf("%d\n",ans);
	}

}












