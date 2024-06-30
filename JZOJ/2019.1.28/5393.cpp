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
const int N = 220,NUM = 10004,M = 6;
int f[N][NUM * 2][M];
int g[NUM * 2][M][M];
int n,m;
int a[N][M],ans,map[N][M];
int main()
{
	freopen("snakevsblock.in","r",stdin);
	freopen("snakevsblock.out","w",stdout);
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d", &n);
	fo(i,1,n) fo(j,0,4) scanf("%d", &a[i][j]);
	scanf("%d", &m);
	fo(i,1,m)
	{
		int x,y;
		scanf("%d%d", &x, &y);
		map[x][y - 1] = 1;
	}
	memset(f,128,sizeof f);
	f[0][4][2] = 0;
 	fo(i,1,n)
 	{
 		memset(g,128,sizeof g);
 		fo(j,0,NUM) fo(k,0,4)
 		if (j >= a[i][k] && j <= NUM + a[i][k])
 		{
 			f[i][j][k] = g[j][k][k] = f[i - 1][j - a[i][k]][k] + max(-a[i][k],0);
 		}
 		fo(l,1,4) fo(j,0,4)
 		{
 			int k = j + l;
 			if (j + l >= 5) break;
 			fo(v,0,NUM)
 			{
 				if (!map[i][j] && v - a[i][j] >= 0 && v - a[i][j] <= NUM) g[v][j][k] = g[v - a[i][j]][j + 1][k] + max(-a[i][j],0);
 				if (!map[i][k - 1] && v - a[i][k] >= 0 && v - a[i][k] <= NUM)g[v][j][k] = max(g[v][j][k],g[v - a[i][k]][j][k - 1] + max(-a[i][k],0));
 				fo(to,j,k) f[i][v][to]=max(f[i][v][to],g[v][j][k]);
 			}
 		}
	}
	ans = -oo;
	fo(l,0,n) fo(i,0,NUM) fo(j,0,4) 
		ans = max(ans, f[l][i][j]);
	printf("%d\n", ans);
	return 0;
}
