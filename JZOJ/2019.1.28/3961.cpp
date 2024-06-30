#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=55,S=50050;
int f[N][S];
int n,T;
bool dfs(int x,int y)
{
    if(f[x][y]>=0)return f[x][y];
	if(x==0)return(f[x][y]=(y&1));
    if(y==1)return(f[x][y]=dfs(x+1,0));
    f[x][y]=0;
    f[x][y]|=(!dfs(x-1,y));
    if(!f[x][y]&&y>0) f[x][y]|=(!dfs(x-1,y+1))||(!dfs(x,y-1));
    if(!f[x][y]&&x>1) f[x][y]|=(!dfs(x-2,y+2+(y>0)));
    return(f[x][y]);
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	memset(f,255,sizeof f);
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n);
		int n1=0,s=-1;
		fo(i,1,n)
		{
			int x;
			scanf("%d",&x);
			if(x==1)++n1;
			else s+=x+1;
		}
		if(s<0)s=0;
		if(dfs(n1,s)) printf("Chicken Leg Prevails!\n");
		else printf("SRQ CZY\n");
	}
    return 0;
}
