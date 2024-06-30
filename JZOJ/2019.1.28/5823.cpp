#pragma GCC optimize(2)
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=55,M=888;
int n,m,k,cnt;
int b[N][N],v[N][N];
int ans,g[M][2*N][N];
priority_queue<int> qu;int sz;
int f[4][2][2],cntt,flag;
int pd(int x)
{
	return(x<=0||x>n);
}
int check(int x,int y,int fx)
{
	fo(l,0,1) 
	{
		if(pd(x+f[fx][l][0])||pd(y+f[fx][l][1]))return 0;
		if(b[x+f[fx][l][0]][y+f[fx][l][1]]) return 0;
	}
	return 1;
}
void kp(int x,int y,int fx,int val)
{
	fo(l,0,1) 
	{
		if(pd(x+f[fx][l][0])||pd(y+f[fx][l][1]))continue;
		b[x+f[fx][l][0]][y+f[fx][l][1]]=val;
	}
}
void dfs(int xy,int x,int p,int val)
{
	if(val+g[p][xy][x]<=ans) return;
	if(val>ans) 
		ans=val;
	if(p==0||xy==n+n+1)return;
	if((++cntt)>10000000)
		flag=1;
	if(flag)return;
	int y=xy-x;
	if(y<=0) 
	{
		dfs(xy+2,1,p,val);
		return;
	}
	dfs(xy,x+1,p,val);
	if(!b[x][y])
	fo(f,0,3)
	if(check(x,y,f)) 
	{
		kp(x,y,f,1);
		dfs(xy,x+1,p-1,val+v[x][y]);
		kp(x,y,f,0);
	}
}
int main()
{
	freopen("marshland.in","r",stdin);
	freopen("marshland.out","w",stdout);
//	freopen("D:/LiuYuanHao/c.in","r",stdin);
	int all=0;cntt=0;
	scanf("%d%d%d",&n,&m,&k);m=min(m,880);
	fo(i,1,n) fo(j,1,n) scanf("%d",&v[i][j]),all+=v[i][j];
	f[0][0][0]=1,f[0][1][1]=1;
	f[1][0][0]=-1,f[1][1][1]=-1;
	f[2][0][1]=-1,f[2][1][0]=1;
	f[3][0][1]=1,f[3][1][0]=-1;
	fo(i,1,k) 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		b[x][y]=1;
	}
	if(m*n*n<=100000000)
	fo(l,1,m)
	{
		cnt=sz=0;
		for(int i=n+n-1;i>=3;i-=2) fd(x,n,1)
		{
			int y=i-x;
			if(y>n||y<=0) continue;
			cnt+=v[x][y];
			++sz;qu.push(-v[x][y]);
			if(sz>l) 
			{
				int p=qu.top();qu.pop();
				cnt+=p;--sz;
			}
			g[l][i][x]=cnt;
		}
	}
	ans=0;
	dfs(3,1,m,0);
	printf("%d\n",all-ans);
	return 0;
}











