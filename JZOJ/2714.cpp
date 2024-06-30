#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=1001000;
int n,to[N*2],nex[N*2],las[N],tot;
int t[N];
void link(int x,int y)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
}
int sz[N],fa[N];
int d[N],hd,tl;
void dfs(int x,int f)
{
	fo(i,1,n) sz[i]=1;
	d[tl=1]=x;hd=0;
	while(hd++<tl)
	{
		x=d[hd];
		for(int tp=las[x];tp;tp=tp[nex])
		if(to[tp]!=fa[x]) to[tp][fa]=x,d[++tl]=to[tp];
	}
	fd(i,n,1) sz[fa[d[i]]]+=sz[d[i]];
	fo(i,1,n) ++t[sz[i]];
}
int ans;
void solve(int d)
{
	int rt=0,x=d;
	while(x<=n) rt+=t[x],x+=d;
	if(rt*d==n) ++ans;
}
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
}
int main()
{
//	 freopen("D:/LiuYuanHao/a.in","r",stdin);
	n=read();
	fo(i,1,n-1)
	{
		int x=read(),y=read();
		link(x,y),link(y,x);
	}
	dfs(1,0);
	for(int d1=1;d1*d1<=n;++d1)
	if(n%d1==0)
	{
		solve(d1);
		if(d1*d1!=n) solve(n/d1);
	}
	printf("%d\n",ans);
	return 0;
}








