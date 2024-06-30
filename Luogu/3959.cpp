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
const int N=15,M=1010,V=500500,S=4096+100;
int g[N][S],f[N][S];
int n,m;
int dis[N][N],t[N];
int cost(int s1,int s2)
{
	//s2已存在 添加s1
	int rt=0;
	fo(i,1,n)
	if(t[i]&s1)
	{
		if(g[i][s2]==oo) return oo; 
		rt+=g[i][s2];
	}
	return rt; 
}
int main()
{
	freopen("D:/LiuYuanHao/a2.in","r",stdin);
	memset(dis,127,sizeof dis);
	memset(f,127,sizeof f);
	scanf("%d%d",&n,&m);
	t[1]=1;
	fo(i,2,n+1) t[i]=t[i-1]<<1; 
	int all=t[n+1]-1;
	fo(i,1,m)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		dis[x][y]=min(dis[x][y],c);
		dis[y][x]=dis[x][y];
	}	
	fo(i,1,n) fo(s,0,all)
	if(!(s&t[i]))
	{
		int tmp=oo;
		fo(l,1,n)
		if(s&t[l])
		{
			tmp=min(tmp,dis[i][l]);
		}
		g[i][s]=tmp;
	}
	fo(i,1,n) f[0][t[i]]=0;
	fo(i,1,n)
	{
		fo(sf,0,all)
		if(f[i-1][sf]<oo)
		{
			fo(st,0,all)
			if(!(sf&st))
			{
				int sn=sf|st;
				int cos=cost(st,sf);
				if(cos==oo) continue;
				f[i][sn]=min(f[i][sn],f[i-1][sf]+cos*i);
			}
		}
	}
	int ans=oo;
	fo(i,0,n) 
		ans=min(ans,f[i][all]);
	printf("%d\n",ans);
	return 0;
}












