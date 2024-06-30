#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=8;
int n,m;
int son[N][N],bz[N][N];
int f[729+1][32+1];
int d[2000200][2][2];
int hd=0,tl=1;
int main()
{
	freopen("D:/LiuYuanHao/b.in","r",stdin);
	// freopen("shampagne.in","r",stdin);
	// freopen("shampagne.out","w",stdout);
	scanf("%d%d",&n,&k);
	fo(i,1,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		son[x][++son[x][0]]=y;
	}
	bfs();
	
	return 0;
}











