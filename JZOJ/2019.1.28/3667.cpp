#pragma GCC optimize(2)
#include <ctime>
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
const int N=300300;
int n,q;
int to[N*2],nex[N*2],las[N],tot;
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
}
void link(int x,int y)
{
	to[++tot]=y,tot[nex]=x[las],las[x]=tot;
}
int ans[N];
int sz[N],bz[N];
int fa[N];
int root;
int hd,tl;
int d[N][2],vis[N];
void bfs(int x,int ft)
{
	hd=0;
	d[tl=1][1]=x,d[tl][0]=ft;
	while(hd++<tl)
	{
		x=d[hd][1],ft=d[hd][0];
		fa[d[hd][1]]=d[hd][0];
		sz[x]=1;
		for(int tmp=x[las];tmp;tmp=nex[tmp])
		if(to[tmp]!=ft)
			d[++tl][1]=to[tmp],d[tl][0]=x;
	}
	fd(i,tl,1) d[i][0][sz]+=d[i][1][sz];
}
PI h[N];
void up(int x,int t)
{
	for(;x!=root&&bz[x]!=t;x=fa[x])bz[x]=t;
}
void work(int tp)
{
	hd=0;
	while(hd++<tl)
	{
		int x=d[hd][1];
		if(bz[x]<tp) 
			d[hd][0][ans]+=sz[x]-1;
		else 
		for(int tmp=x[las];tmp;tmp=nex[tmp])
		{
			int t=to[tmp];
			if(vis[t]<tp)
			{
				d[++tl][0]=d[hd][0],d[tl][1]=t;
				++ans[d[tl][0]];
				vis[t]=tp;
			}
		}
	}
}
int h0;
int buf[100];
void write(int x)
{
	if(x==0) 
	{
		putchar('0');
		return;
	}
	int b0=0;
	while(x) buf[++b0]=x%10,x/=10;
	fd(i,b0,1) putchar(buf[i]+'0');
}
int main()
{
	 freopen("worldtree.in","r",stdin);
	freopen("worldtree.out","w",stdout);
//	freopen("D:/LiuYuanHao/c2.in","r",stdin);
//	srand(time(0));rand();rand();
	n=read();
	fo(i,1,n-1)
	{
		int x=read(),y=read();
		link(x,y),link(y,x);
	}
	// root=1;
	root=(rand()%(n-2))+1; 
	bfs(root,0);
	q=read();
	fo(l,1,q)
	{
		fo(i,1,h0) ans[i]=0;
		bz[root]=l;
		h0=read();
		tl=0;
		fo(i,1,h0) h[i].fi=read(),h[i].se=i,ans[i]=1;
		sort(h+1,h+1+h0);
		fo(i,1,h0)
		{
			up(h[i].fi,l);
			d[++tl][1]=h[i].fi,d[tl][0]=h[i].se;
			vis[h[i].fi]=l;
		}
		work(l);
		fo(i,1,h0) write(ans[i]),putchar(' ');
		putchar('\n');
	}
 	return 0;
}




