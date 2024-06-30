#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=18,M=N*N;
int bz[4][N][N];//  1行2列3方格 
char S[N][N];int st[N][N];
struct node{
	int x,y,id;
}a[M];int a0;
bool cmp(node a,node b)
{
	return(a.id<b.id);
}
int h(int x,int y)
{
	x=(x+3)/4,y=(y+3)/4;
	return((x-1)*4+y);
}
void add(int x,int y,int p,int v)
{
	bz[1][x][p]=v,bz[2][y][p]=v;
	bz[3][h(x,y)][p]=v;	
}
int flag;
int jd(int x,int y,int p)
{
	return((!bz[1][x][p])&&(!bz[2][y][p])&&(!bz[3][h(x,y)][p]));
}
void dfs(int x)
{
	if(flag)return;
	if(x>a0)
	{
		fo(i,1,16) 
		{
			fo(j,1,16)
			{
				char p=st[i][j]+'A'-1;
				printf("%c",p);
			}
			printf("\n");
		}
		flag=1;
		return;
	}
	fo(i,1,16)
	if(jd(a[x].x,a[x].y,i))
	{
		add(a[x].x,a[x].y,i,1);
		st[a[x].x][a[x].y]=i;
		dfs(x+1);
		st[a[x].x][a[x].y]=0;
		add(a[x].x,a[x].y,i,0);
	}
}
int main()
{
	freopen("D:/LiuYuanHao/b.in","r",stdin);
	freopen("D:/LiuYuanHao/b.out","w",stdout);
	fo(i,1,16) scanf("%s\n",S[i]+1);
	fo(i,1,16) fo(j,1,16)
	{
		if(S[i][j]=='-') a[++a0].x=i,a[a0].y=j;//,a[a0].id=h(i,j)*(N-h(i,j))
		else
		{
			st[i][j]=S[i][j]-'A'+1;
			add(i,j,st[i][j],1);
		}
	}
	fo(i,1,a0)
	{
		fo(j,1,16)
		if(jd(a[i].x,a[i].y,j)) ++a[i].id;
		a[i].id=a[i].id*4096-h(a[i].x,a[i].y)*(N-h(a[i].x,a[i].y));
	}
	sort(a+1,a+1+a0,cmp);
	dfs(1);
	return 0;
}











