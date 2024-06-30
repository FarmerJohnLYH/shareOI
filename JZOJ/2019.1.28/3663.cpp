#include <bitset>
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
const int N=5050;
int n,m,q;
int b[N][N];
//bitset<N> b[N];
int ans;
int bz[N],d[N];
void work(int x)
{
	int hd=0,tl=1;
	d[tl=1]=x;bz[x]=1;
	while(hd++<tl)
	{
		x=d[hd];
		fo(i,1,n)
		if(!bz[i]&&b[x][i])
		{
			bz[i]=1;
			d[++tl]=i;
		}
	}
}
int main()
{
//	freopen("D:/LiuYuanHao/c4.in","r",stdin);
//	freopen("D:/LiuYuanHao/c.out","w",stdout);
	freopen("compound.in","r",stdin);
	freopen("compound.out","w",stdout);
	scanf("%d%d",&n,&m);
	fo(i,1,m) 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		b[x][y]=b[y][x]=1;
	}
	ans=0;
	fo(i,1,n)
	if(!bz[i]) 
	{
		work(i),++ans;
	}
	scanf("%d\n",&q);
	while(q--)
	{
		char t=getchar();int x,y;
		while(t!='D'&&t!='A'&&t!='Q')t=getchar();
		int flag=0;
		if(t=='D')
		{
			scanf("%d%d",&x,&y);
			fo(i,1,n)
			if(b[x][i]&&b[i][y]) 
			{
				flag=1;
				break;
			}
			if(!flag) ++ans; 
			b[x][y]=b[y][x]=0;
		}else
		if(t=='A')
		{
			scanf("%d%d",&x,&y);
			fo(i,1,n)
			if(b[x][i]&&b[i][y])
			{
				flag=1;
				break;
			}
			if(!flag) --ans;
			b[x][y]=b[y][x]=1;
		}else
		if(t=='Q') printf("%d\n",ans);
	}
	return 0;
}











