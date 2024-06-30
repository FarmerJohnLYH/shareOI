//#pragma GCC optimize(2) 
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
#define fd(i,x,y) for(int i=(x);i>=(y);--i)
using namespace std;
const int N=400400*10,M=200200*6*10;
int n,m,q;
int f[N];
vector<int> sn[N];int du[N];
int read()
{
	int rt=0,fg=1;char ch=getchar();
	while(ch!='-'&&(!(ch>='0'&&ch<='9'))) ch=getchar();
	if(ch=='-') fg=-1,ch=getchar();
	while(ch>='0'&&ch<='9') rt=rt*10+ch-'0',ch=getchar();
	return rt*fg;
}
int to[M],nex[M],las[N],tot;
inline void link(int x,int y)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
}
int to2[M],nex2[M],las2[N],tot2,pre[M];
inline void link2(int x,int y)
{
	to2[++tot2]=y,nex2[tot2]=las2[x],pre[las2[x]]=tot2;
	las2[x]=tot2;
}
int r[N];
int d[N];
int ans;
void check()
{
	fo(i,1,n) f[i]=oo;
	f[1]=0;d[1]=1;
	int hd=0,tl=1;
	while(hd++<tl)
	{
		int x=d[hd];
		for(int tp=las[x];tp;tp=tp[nex])
		if(f[x]+1<f[to[tp]])
		{
			f[to[tp]]=f[x]+1;
			d[++tl]=to[tp];
		}
	}
}
int buf[30],b0;
void write(int x)
{
	b0=0;
	if(x==0)putchar('0');
	else
	while(x) buf[++b0]=x%10,x/=10;
	fd(i,b0,1) putchar(buf[i]+'0');
	putchar('\n');
}
struct edeg{
	int x,y;
}e[M];int bz[M];
void del(int x,int f)
{
	if(las2[f]==x) las2[f]=nex2[x];
	nex2[pre[x]]=nex2[x],pre[nex2[x]]=pre[x];
}
int vis[N];
void run(int x)
{
	++ans;vis[x]=1;
	for(int tp=las2[x];tp;tp=tp[nex2])
	if(!to2[tp][vis])
	{
		--du[to2[tp]];
		del(tp,x);
		if(to2[tp][du]==0)
			run(to2[tp]);
	}
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("D:/LiuYuanHao/a.out","w",stdout);
//	freopen("train.in","r",stdin);
//	freopen("train.out","w",stdout);
	n=read(),m=read(),q=read();
	tot=1;
	fo(i,1,m)
	{
		int x,y;
		x=read(),y=read();
		link(x,y),link(y,x);
		e[i].x=x,e[i].y=y;
	}
	check();
	fo(i,1,q)
		r[i]=read();
	fo(i,1,m) 
	{
		if(e[i].x[f]>e[i].y[f]) swap(e[i].x,e[i].y);
		if(f[e[i].x]+1==f[e[i].y]) 
		{
			++du[e[i].y];
			link2(e[i].x,e[i].y);
			bz[i]=tot2;
		}
	}
	fo(i,1,q)
	{
		int p=r[i];
		if(bz[p])
		{
			if(e[p].y[vis]) continue;
			--e[p].y[du];
			del(bz[p],e[p].x);
			if(du[e[p].y]==0)run(e[p].y);
			bz[p]=0;
		}
		printf("%d\n",ans);
	}
	ans=0;
	fo(i,1,n) if(vis[i])
		++ans;
	return 0;
}
