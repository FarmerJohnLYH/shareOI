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
const int N=110,M=N*N*2;
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
}
int tot;
int to[M],nex[M],las[N];
void link(int x,int y)
{
	to[++tot]=y,tot[nex]=las[x],x[las]=tot;
}
int n,r[N][N]/*dp*/;
int cl[N],sta[N],col[N];
int dt[N*10];
int flag=0;
int s[N][2],s0;
void bfs(int x,int y)
{
	int hd=0,tl=1;
	dt[tl=1]=x;
	while(hd++<tl)
	{
		x=dt[hd];
		for(int tmp=x[las];tmp;tmp=tmp[nex])
		{
			if(tmp[to][cl]<0) 
			{
				tmp[to][col]=y;
				tmp[to][cl]=1-x[cl];
				++s[s0][1-x[cl]];
				dt[++tl]=tmp[to];
			}else
			if(tmp[to][cl]!=1-x[cl])
			{
				flag=1;
				break;
			}		
		}
		if(flag)break;
	}
}
PI f[N]/*fi转移from se选择（0/1）*/;
int ans[2][N],a0[2];
void work(int x,int y)
{
	fo(i,1,n) 
		if(col[i]==col[x]) ans[y^cl[i]][++a0[y]]=x;
}
void print(int st)
{
	for (int tmp=st;f[tmp].se!=oo;tmp=f[tmp].fi)
	{
		int now=f[tmp].se;
		if(now<0) work(-now,1);
		else work(now,0);
	}
	fo(i,0,1)
	{
		printf("%d ",a0[i]);
		fo(j,1,a0[i]) printf("%d ",ans[i][j]);
		printf("\n");
	}
}
int main()
{
	 freopen("D:/LiuYuanHao/c.in","r",stdin);
	n=read();
	fo(i,1,n)
		for (int x=read();x;x=read()) r[i][x]=1;
	fo(i,1,n)fo(j,i+1,n)
	if(!(r[i][j]&&r[j][i])) link(i,j),link(j,i);
	// a[i][++a[i][0]]=j;
	memset(cl,255,sizeof cl);
	s0=0;
	fo(i,1,n)
	if(cl[i]<0)
	{
		s[++s0][cl[i]=1]=1;
		sta[s0]=i,col[i]=i;
		bfs(i,i);
		if(flag)
		{
			printf("-1 \n");
			return 0;
		}
	}
	memset(f,0,sizeof f);
	f[0].fi=f[0].se=oo;
	fo(i,1,s0)
	{
		fd(j,n/2,1)
		{
			fo(o,0,1)
			if(j>=s[i][o]&&(f[j-s[i][o]].se)!=0)
			{
				f[j].fi=j-s[i][o];
				f[j].se=sta[i]*((o)?(-1):1);
			}
		}
	}
	fd(l,n/2,0)
	if(f[l].fi)
	{
		print(l);		
		return 0;
	}
	return 0;
}







