#include <map>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (int pq = (y),i = (x);i <= pq;++ i)
#define fd(i,x,y) for (int pq = (y),i = (x);i >= pq;-- i)
#define oo 2139062143
using namespace std;
typedef double db;
typedef long long ll;
int lowbit(int x) {return((x)&(-x));}
int min(int x,int y){return (x>y)?(y):(x);}
int max(int x,int y){return (x>y)?(x):(y);}
const int N=550;
int fx[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
int n,m;
int f[N*N];
int a[N*N];
map <ll,bool> mp;
struct node{
	int x,y;
}st,en;
struct edge{
	int to,nex;
}e[N*N*2*4];
int las[N*N],tot;
int dis[N*N],d[N*N];
void link(int x,int y)
{
	e[++tot].to=y,e[tot].nex=las[x];
	las[x]=tot;
}
int gf(int x)
{
	return((f[x]==x)?(x):(f[x]=gf(f[x])));
}
int h(int x,int y)
{
	return((x-1)*m+y);
}
int main()
{
	freopen("D:/LiuYuanHao/b.in","r",stdin);
	freopen("D:/LiuYuanHao/b.out","w",stdout);
	for (scanf("%d%d",&n,&m);n+m;scanf("%d%d",&n,&m))
	{
		memset(a,0,sizeof a);
		memset(las,0,sizeof las);
		memset(dis,255,sizeof dis);
		memset(f,0,sizeof f);
		mp.clear();
		
		tot=0;
		//
		fo(i,1,n)
		{
			fo(j,1,m)
			{
				char c=getchar();
				while(c!='#'&&c!='@') c=getchar();
				a[h(i,j)]=(c=='#')?1:2;
				f[h(i,j)]=h(i,j);
				if(i>1)
					if(a[h(i-1,j)]==a[h(i,j)]) 
					{
						int fx=gf(h(i-1,j)),fy=gf(h(i,j));
						f[fy]=fx;
					} 
				if(j>1)
					if(a[h(i,j-1)]==a[h(i,j)])
					{
						int fx=gf(h(i,j-1)),fy=gf(h(i,j));
						f[fy]=fx;
					}
			}
		}
		scanf("%d%d%d%d",&st.x,&st.y,&en.x,&en.y);
		++st.x,++st.y,++en.x,++en.y;
		fo(i,1,n) fo(j,1,m)
		{
			int x=gf(h(i,j)),y=0;
			fo(l,0,3)
			{
				if(i+fx[l][0]==0||i+fx[l][0]>n||j+fx[l][1]==0||j+fx[l][1]>m) 
					continue;
				y=gf(h(i+fx[l][0],j+fx[l][1]));
				if(x!=y)
				{
					if(!mp[x*500*500+y]) 
					{
						mp[x*500*500+y]=1;
						link(x,y);
					}
				}
			}
		}
		int hd=0,tl=1;
		d[1]=gf(h(st.x,st.y));
		dis[d[1]]=0;
		while(hd++<tl)
		{
			int now=d[hd];
			for (int tmp=las[now];tmp;tmp=e[tmp].nex)
			{
				int to=e[tmp].to;
				if(dis[to]==-1)
					dis[to]=dis[now]+1,d[++tl]=to;
			}
			if(dis[gf(h(en.x,en.y))]>-1) break;
		}
		printf("%d\n",dis[gf(h(en.x,en.y))]);
		n=m=0;
	}
	return 0;
}
