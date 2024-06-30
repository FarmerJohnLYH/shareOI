#include <bitset>
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
const int N=6060,K=1010;
int n,k;
//char c[K];
bitset<2*N> p[N];
bool check(int x,int y)
{
	int tot=(p[x] & p[y]).count();
	if(tot*2>=n)
	{
		return 1;
	}
	return 0;
}
int main()
{
	 //freopen("confess.in","r",stdin);
	 //freopen("confess.out","w",stdout);
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d", &n);
	//int start=clock();
	k=((n*2)/6)+((n*2)%6!=0);
	fo(i,1,n+1)
	{
		//scanf("%s", c + 1);
		fo(j,1,k)
		{
			char c=getchar();
			while(c<33)c=getchar();
			c-=33;
			fo(l,0,5) p[i][(j-1)*6+l]=c>>l&1;
		}
	}
	srand(time(0));
	fo(l,1,10 * n)
	{
		//int cost=clock()-start;
		//if(cost>=990)return 0;
		int i=rand()%(n+1)+1,j=rand()%n+1;
		if(j>=i)++j;
		if(i==j)continue;
		if(check(i,j)) 
		{
			printf("%d", check(1,2));
			// printf("%d %d\n",i,j);
			return 0; 
		}	
	}
	return 0;
}
