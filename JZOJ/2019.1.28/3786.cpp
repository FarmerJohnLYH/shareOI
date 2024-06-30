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
const int N=5050,M=10100;
int d[N][N][2];
int n,m,q;
int to[M],nex[M],las[N],tot;
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
}
int du[N];
void link(int x,int y)
{
	++du[x];
	to[++tot]=y,tot[nex]=x[las];
	las[x]=tot;
}
int dt[N*5],vis[N];
int f[N];
void work(int st)
{
	memset(vis,0,sizeof vis);
	int hd=0,tl=1;
	dt[tl]=st;vis[st]=1;d[st][st][0]=0;
	while(hd++<tl)
	{
		int x=dt[hd];
		if(f[x]) 
		{
			d[st][x][1]=min(d[st][x][0]+1,d[st][x][1]);
			d[st][x][0]=min(d[st][x][1]+1,d[st][x][0]); 
		} 
		for(int tmp=x[las];tmp;tmp=tmp[nex])
		{
			int t=tmp[to];
			if(d[st][x][0]+1<d[st][t][1]||d[st][x][1]+1<d[st][t][0])
			{
				d[st][t][1]=min(d[st][x][0]+1,d[st][t][1]);
				d[st][t][0]=min(d[st][x][1]+1,d[st][t][0]);
				if(!tmp[to][vis])
				{
					dt[++tl]=t;
					tmp[to][vis]=1;	
				}
			} 
		}
		vis[x]=0;
	}
}
int main()
{
	freopen("D:/LiuYuanHao/b.in","r",stdin);
	freopen("D:/LiuYuanHao/b.out","w",stdout);
	memset(d,127,sizeof d);
	n=read(),m=read(),q=read();
	fo(i,1,m)
	{
		int x=read(),y=read(); 
		if(x!=y)link(x,y),link(y,x);
		else f[x]=1;
	}
	fo(i,1,n)
	{
		work(i);
	 } 
	fo(l,1,q)
	{
//		printf("%d",l);
		int a=read(),b=read(),c=read();
		if(!(a==b&&c%2==0))
		{
			if(d[a][b][c%2]<=c) putchar('T'),putchar('A'),putchar('K');
			else putchar('N'),putchar('I'),putchar('E');
		}
		else
		{
			if(du[a])putchar('T'),putchar('A'),putchar('K');
			else putchar('N'),putchar('I'),putchar('E');
		}
		putchar('\n');
	}
	return 0;
}











