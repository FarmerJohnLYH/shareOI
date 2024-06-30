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
const int N=300300*2;
int n,s;
int to[N],nex[N],las[N],v[N]; 
int dis[N],di[N],fa[N];
int sta[N],s0,tot;
int st,en;
void link(int x,int y,int V)
{
	to[++tot]=y,tot[nex]=las[x];las[x]=tot;
	v[tot]=V;
}
int dt[N];
void bfs(int root)
{
	memset(dis,127,sizeof dis);
	int hd=0,tl=1;
	dt[1]=root;dis[root]=0;
	while(hd++<tl)
	{
		int now=hd[dt];
		for (int tp=now[las];tp;tp=tp[nex])
		if(tp[to][dis]==oo)
		{
			int t=tp[to];
			fa[t]=now;
			if(di[t]) dis[t]=dis[now];
			else dis[t]=dis[now]+v[tp];
			dt[++tl]=t;
		}
	}
}
int check(int D)
{
	int hd=1,tl=s0;
	while(sta[1]-sta[hd+1]<=D&&hd<=s0) ++hd;
	while(sta[tl-1]<=D&&tl>=1) --tl;
	if(sta[hd]-sta[tl]<=s) return 1;
	return 0;
}
int main()
{
	freopen("D:/LiuYuanHao/a1.in","r",stdin);
	scanf("%d%d",&n,&s);
	fo(i,1,n-1)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		link(x,y,z),link(y,x,z);
	}
	st=1;
	bfs(1);fo(i,1,n) if(dis[i]>dis[st]) st=i;
	en=st;
	bfs(st);fo(i,1,n) if(dis[i]>dis[en]) en=i;
	while(en!=st)
	{
		sta[++s0]=dis[en];di[en]=1;
		en=fa[en];
	}
	di[st]=1;sta[++s0]=0;sta[0]=oo;
	int le=0,ri=dis[1];
	int ans=oo;
	bfs(en);
	fo(i,1,n) le=max(le,dis[i]);
	while(le<=ri)
	{
		int mid=(le+ri)>>1;
		if(check(mid)) ri=mid-1,ans=mid;
		else le=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}










