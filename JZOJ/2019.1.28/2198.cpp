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
const int N=11;
int n,m;
int _;
int l[N],h[N];
int a[N][N],b[N][N];
bool bh[N][N],bl[N][N];
int flag=0;
void dfs(int x,int y)
{
	if(flag>=2) return;
	if(x>n)
	{
		int bz=0;
		fo(i,1,n) bz|=h[i];
		fo(i,1,m) bz|=l[i];
		if(bz) return;
		++flag;
		fo(i,1,n)fo(j,1,m) b[i][j]=a[i][j];
		return;
	}
	if(y>m) 
	{
		if(h[x]>0) return;
		dfs(x+1,1);
		return;	
	}
	if(a[x][y]) 
	{
		dfs(x,y+1);
		return;	
	}
	fo(i,1,9)
	if((!bh[x][i])&&!bl[y][i])
	{
		if(i>h[x]||i>l[y]) break;
		a[x][y]=i;
		h[x]-=i,l[y]-=i;
		bh[x][i]=bl[y][i]=1;
		dfs(x,y+1);
		h[x]+=i,l[y]+=i;
		a[x][y]=0;
		bh[x][i]=bl[y][i]=0;
	}
}
int main()
{
	freopen("D:/LiuYuanHao/c1.in","r",stdin);
	freopen("D:/LiuYuanHao/c.out","w",stdout);
//	freopen("kakuro.in","r",stdin);
//	freopen("kakuro.out","w",stdout);
	scanf("%d",&_);
	while(_--)
	{
		//clear
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(h,0,sizeof h);
		memset(l,0,sizeof l);
		memset(bh,0,sizeof bh);
		memset(bl,0,sizeof bl);
		n=m=0;
		

		scanf("%d%d",&n,&m);
		fo(i,1,n) scanf("%d",&h[i]);
		fo(i,1,m) scanf("%d",&l[i]);
		fo(i,1,n) fo(j,1,m)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j])
			{
				h[i]-=a[i][j],l[j]-=a[i][j];
				bh[i][a[i][j]]=bl[j][a[i][j]]=1;
			}
		}
		flag=0;
		dfs(1,1);
		if(flag==0)
		{
			printf("No answer.\n");
		}
		else
		if(flag>=2)
		{
			printf("Not unique.\n");
		}
		else
		if(flag==1)
		{
			fo(i,1,n) 
			{
				fo(j,1,m)
					printf("%d ",b[i][j]);
				printf("\n");
			}
		}
	}
	return 0;
}
