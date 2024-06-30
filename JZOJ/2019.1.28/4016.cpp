#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=55,M=12;
int fx[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m,q0,qm;
struct node{
	int x,y,tp,s;
}q[M],d[N*N*(1<<(M-1))];
char s[N];
int lowbit(int x) 
{
	return((x)&(-(x)));
}
bool cmp(node a,node b)
{
	return(a.tp>b.tp);
}
int f[N][N][1<<M];
int mi(int x)
{
	return(1<<(x-1));
}
int vis[N][N][1<<M];
int check(int x,int y)
{
	return(x>=0&&x<=n&&y>=0&&y<=m);
}
void solve()
{
	memset(f,127,sizeof f);
	f[0][0][0]=0;
	int hd=0,tl=1;
	d[1].x=0,d[1].y=0,d[1].s=0;
	vis[0][0][0]=1;
	while((hd++)!=tl)
	{
		node w=d[hd];
		fo(l,0,3)
		{
			node to;to.s=w.s,to.x=w.x+fx[l][0],to.y=w.y+fx[l][1];to.tp=-1;
			if(!check(to.x,to.y)) continue;
			if(l<=1)
			{
				fo(i,1,q0)
				if(q[i].x==w.x+(l==0) && q[i].y>w.y) to.s^=mi(i);
			}
			if(f[to.x][to.y][to.s]>(f[w.x][w.y][w.s]+1)) 
			{
				f[to.x][to.y][to.s]=(f[w.x][w.y][w.s]+1);	
				if(!vis[to.x][to.y][to.s])
				{
					vis[to.x][to.y][to.s]=1;
					d[++tl]=to;
				}
			}
		}
		vis[w.x][w.y][w.s]=0;
	}
}
int ans[M];
int cnt(int x)
{
	int rt=0;
	while(x)x-=lowbit(x),++rt;
	return rt;
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	while(scanf("%s",s+1)!=EOF)
	{
		++n;
		if(!m)m=strlen(s+1);
		fo(i,1,m)
			if(s[i]!='.') q[++q0].tp=(s[i]=='I'),q[q0].x=n,q[q0].y=i;
	}
	sort(q+1,q+1+q0,cmp);
	fd(i,q0,1)if(q[i].tp==1)
	{qm=i;break;}
	solve();
	memset(ans,127,sizeof ans);
	fo(i,1,(1<<qm)-1)
		ans[cnt(i)]=min(ans[cnt(i)],f[0][0][i]);	
	fo(i,1,qm) printf("%d\n",ans[i]);
	return 0;
}











