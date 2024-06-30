#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=22;
int n,m;
int T,a[N][N];
int pd(int x,int y)
{
	return(a[x][y]==a[n-x+1][m-y+1]);
}
int check()
{
	fo(i,1,n) fo(j,1,m>>1)
	if(!pd(i,j))
		return 0;
	return 1;
}
int ct[27];
int mxp;
int main()
{
	 freopen("fragment.in","r",stdin);
	 freopen("fragment.out","w",stdout);
//	freopen("D:/LiuYuanHao/b2.in","r",stdin);
//	int ppp=clock();
	srand(time(0));rand();rand();
	scanf("%d",&T);scanf("%d\n",&T);
	mxp=2e6/T;
	while(T--)
	{
		scanf("%d%d\n",&n,&m);
		memset(ct,0,sizeof ct);
		fo(i,1,n) 
		{
			fo(j,1,m)
			{
				char ch;
				scanf("%c",&ch);
				++ct[ch-'A'];
				a[i][j]=ch-'A';
			}
			scanf("\n");		
		}
		int flag=0;
		fo(i,0,25) if(ct[i]&1) ++flag;
		if(flag>1||(flag==1&&(!((n*m)&1)))) 
		{
			printf("NO\n");
			continue;
		}
		flag=0;
		if(check()) 
		{
			printf("YES\n");
			continue;
		}
		int pp=mxp;
		while(--pp)
		{
			int bfg=0;
			int bz=rand()&1;
			int x=rand()%998244353,y=rand()%19260817;
			if(bz)
			{
				x=x%n+1,y=y%n+1;
				fo(i,1,m) 
				{
					swap(a[x][i],a[y][i]);
					if(!pd(x,i)||!pd(y,i)) bfg=1;
				}
			}
			else
			{
				x=x%m+1,y=y%m+1;
				fo(i,1,n) 
				{
					swap(a[i][x],a[i][y]);
					if(!pd(i,x)||!pd(i,y)) bfg=1;
				}
			}
			if(!bfg)
			if(check()) 
			{
				printf("YES\n");
				flag=1;
				break;
			}
		}
		if(!flag) printf("NO\n");
	}
//	printf("%d\n",clock()-ppp);
	return 0;
}











