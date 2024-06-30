#pragma GCC optimize(2)
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
const int N=44;
int n,m;
ll a[N][N];
bool flag;
ll tw[N];
int g[N][N];
void dfs(int p)
{
	if(flag)return;
	if((p-1)*2>=n)
	{	
			fo(i,2,m)
				fo(j,1,n)
					a[i][j]=a[i-1][j-1]^a[i-1][j]^a[i-1][j+1]^a[i-2][j];
		fo(i,2,n) 
		{
			if((a[m][i]^a[m][i-1]^a[m][i-2]^a[m-1][i-1])) 
				return;
		}
		if(!(a[m][n]^a[m][n-1]^a[m-1][n])) 
		{
			flag=1;
			fo(i,1,m)
			{
				fo(j,1,n)
				{
					printf("%d ",a[i][j]);
				}
				printf("\n");
			}
		}
		return;
	}
	a[1][p]=a[1][n-p+1]=1;
	dfs(p+1);	
	a[1][p]=a[1][n-p+1]=0;
	dfs(p+1);
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&m);
	int cc=clock();
	swap(n,m); 
	a[1][1]=tw[1]=1;
	fo(i,2,max(m,n)+2) 
	{
		tw[i]=tw[i-1]<<1;
		if(i<=n) a[1][i]=tw[i];
	}
	fo(i,2,m)
		fo(j,1,n)
			a[i][j]=a[i-1][j-1]^a[i-1][j]^a[i-1][j+1]^a[i-2][j];
	fo(i,1,n) 
	{
		fo(j,1,n)
		if(a[m][i]&tw[j]) 
			g[i][++g[i][0]]=j;	
	}
	memset(a,0,sizeof a);
	flag=0;dfs(1);
	return 0;
}



