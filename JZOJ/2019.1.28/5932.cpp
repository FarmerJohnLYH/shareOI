#pragma GCC optimize(2)
#include <bitset>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143 
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=1010,M=200200;
int n,q,m;
inline int min(int x,int y)
{
	return(x<y?x:y);
}
inline int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
}
//int to[M],nex[M],las[N],tot;
int to[N][N],bz[N][N];
bitset<N> tmp,a[N][N];
int d[2][N],tl[2],mx[N],vis[N];
void work(int st)
{
	memset(vis,0,sizeof vis);
	a[0][st][st]=1;
	d[0][tl[0]=1]=st;mx[st]=n;
	fo(k,1,n)
	{
		a[k][st]=a[k-1][st];
		tl[(k&1)]=0;
		fo(j,1,tl[!(k&1)])
		{
			int x=d[!(k&1)][j];
			fo(tp,1,to[x][0])
			{
				int tt=to[x][tp];
				if(!vis[tt]) vis[tt]=a[k][st][tt]=1,d[k&1][++tl[(k&1)]]=tt;
			}
		}
		if(tl[k&1]==0) 
		{
			mx[st]=k-1;
			break;
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
}
int main()
{
	   freopen("center.in","r",stdin);
	   freopen("center.out","w",stdout);
//	freopen("D:/LiuYuanHao/b.in","r",stdin);
//	freopen("D:/LiuYuanHao/b.out","w",stdout);
	n=read(),m=read(),q=read();
	fo(i,1,m)
	{
		int x=read(),y=read();
		if(!bz[x][y])
		{
			bz[x][y]=bz[y][x]=1;
			to[x][++to[x][0]]=y;
			to[y][++to[y][0]]=x;	
		}
	}
	fo(x,1,n)
		work(x);
	while(q--)
	{
		tmp.reset();
		int d0=read();
		fo(i,1,d0)
		{
			int x,y;
			x=read(),y=min(mx[x],read());
			tmp|=a[y][x];
		}
		int qaq=tmp.count();
		write(qaq);putchar('\n');
	}
	return 0;
}




