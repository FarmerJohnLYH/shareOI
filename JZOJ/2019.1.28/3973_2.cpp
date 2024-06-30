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
const int N=1001000*2;
int n,m;
struct edge{
	int to,nex;
	int id;
}e[N*2];
int tot;
int las[N];
int fa[N][2];
int col[N];
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
}
void link(int x,int y,int i)
{
	++tot;
	e[tot].to=y,e[tot].nex=x[las],e[tot].id=i;
	las[x]=tot;
}
int dep[N];
void dfs(int x,int f)
{
	fa[x][1]=f;
	dep[x]=dep[f]+1;
	for (int i=las[x];i;i=e[i].nex)
	if(e[i].to!=f)
	{
		dfs(e[i].to,x);
		fa[e[i].to][0]=e[i].id;
	}
}
int buf[30];
void write(int x)
{
	if(x==0)putchar('0');
	int b0=0;
	while(x)buf[++b0]=x%10,x/=10;
	fd(i,b0,1)putchar(buf[i]+'0');
}
int main()
{
	 freopen("D:/LiuYuanHao/b.in","r",stdin);
	 freopen("D:/LiuYuanHao/b.out","w",stdout);
	// scanf("%d%d",&n,&m);
	n=read(),m=read();
	fo(i,1,n-1)
	{
		int x=read(),y=read();
		// scanf("%d%d",&x,&y);
		link(x,y,i),link(y,x,i);
	}
	dfs(1,0);
	fo(i,1,m)
	{
		int typ=read(),x,y;
		// scanf("%d",&typ);
		if(typ==1)
		{
			int ans=0;
			x=read();
			// scanf("%d",&x);
			while(x!=1)
			{
				if(fa[x][0][col]) 
				{
					ans=fa[x][0];
					break;
				} 
				x=fa[x][1];
			}
			write(ans);putchar('\n');
			// printf("%d\n",ans);
		}
		if(typ==2)
		{
			x=read(),y=read();
			// scanf("%d%d",&x,&y);
			if(x==y)continue;
			if(dep[x]<dep[y]) swap(x,y);
			while(dep[x]>dep[y])
			{
				fa[x][0][col]=1;
				x=fa[x][1];
			}
			while(x!=y)
			{
				fa[x][0][col]=fa[y][0][col]=1;
				x=fa[x][1],y=fa[y][1];
			}
		}
	}
	return 0;
}











