#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
#define fi first 
#define se second 
using namespace std;
typedef pair<int,int> PI;
const int N=10010,M=100100;
int n,m,k;
struct edge{
	int v,x,y;
};
int g[N];
bool operator <(edge a,edge b)
{
	return(a.v+g[a.y]>b.v+g[b.y]);
}
vector<edge> to[N],ot[N];
int dis[N],bz[N];
priority_queue<edge> qu;
void Dij()
{
	memset(dis,127,sizeof dis);
	memset(bz,0,sizeof bz);
	while(!qu.empty()) qu.pop();
	dis[n]=0;edge t;
	t.y=n,t.v=0;
	qu.push(t);
	while(!qu.empty())
	{
		t=qu.top();qu.pop();
		if(!t.y[bz])
		{
			bz[t.y]=1;	
			for(int p=ot[t.y].size(),i=0;i<p;++i) 
			if(ot[t.y][i].y[dis]>ot[t.y][i].x[dis]+ot[t.y][i].v)
			{
				ot[t.y][i].y[dis]=ot[t.y][i].x[dis]+ot[t.y][i].v;
				edge tt=ot[t.y][i];tt.v=ot[t.y][i].y[dis];
				qu.push(tt);
			}
		}
	}
	fo(i,1,n) g[i]=dis[i];
}
int ti[N],ans[N],a0;
int astar()
{
	memset(ans,255,sizeof ans);
	memset(ti,0,sizeof ti);
	while(!qu.empty()) qu.pop();
	edge tp;tp.x=0,tp.y=1,tp.v=0;
	qu.push(tp);
	while(!qu.empty())
	{
		edge w=qu.top();qu.pop();
		if(w.y==n) 
		{
			if(w.v!=a0[ans]) ans[++a0]=w.v;
			if(a0==k)return(w.v);		
		}
		for(int p=to[w.y].size(),i=0;i<p;++i)
		{
			tp.y=to[w.y][i].y,tp.v=w.v+to[w.y][i].v;
			qu.push(tp);
		}
	}
	return -1;
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	fo(i,1,m)
	{
		edge tp;
		scanf("%d%d%d",&tp.x,&tp.y,&tp.v);
		to[tp.x].push_back(tp);swap(tp.x,tp.y);
		ot[tp.x].push_back(tp);
		char c;
		while(c=getchar(),c!='\n');
	}
	Dij();
	printf("%d\n",astar());
	return 0;
}











