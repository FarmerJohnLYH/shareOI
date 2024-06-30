#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=220;
int n,m,k,va[N][N];
int a[N][N];
int p[N],p0;
int flag=0;
int b[N];
int check()
{
	b[0]=0;
	fo(i,1,p0) 
	{
		b[i]=b[i-1]+(p[i]?(-1):(1));
		if(b[i]<0) return 1;
	}
	return b[p0]!=0;
}
void run(int x,int y)
{
	if(!flag)return;	
	p[++p0]=a[x][y];
	if(x==n&&y==m)
	{
		if(check()) 
		{
			flag=0;
			check();	
		}
		--p0;
		return;
	}
	if(x<n)run(x+1,y);
	if(y<m)run(x,y+1);
	--p0;
}
int tot;
void dfs(int x,int y)
{
	if(x>n)
	{
//		a[1][1]=0;a[1][2]=1;a[1][3]=0;a[1][4]=1;
//		a[2][1]=1;a[2][2]=0;a[2][3]=1;a[2][4]=0;
//		a[3][1]=0;a[3][2]=1;a[3][3]=0;a[3][4]=1;
		p0=0;flag=1;run(1,1);
		if(flag) 
		{
			printf("%d:\n",++tot);
			fo(i,1,n)
			{
				fo(j,1,m) printf("%d",a[i][j]);
				puts("");
			}
			puts("");
		} 
		return;
	}
	if(y>m){dfs(x+1,1);return;}
	fo(k,0,1)
	{
		a[x][y]=k;
		dfs(x,y+1);		
	}

}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("D:/LiuYuanHao/a.ans","w",stdout);
	scanf("%d%d",&n,&m);
	dfs(1,1);
	return 0;
}








