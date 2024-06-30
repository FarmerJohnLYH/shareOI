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
const int W=30030,H=30030;
int w,h,qw,qh,aw,ah;
int main()
{
//	freopen("game.in","r",stdin);
//	freopen("game.out","w",stdout);
	 freopen("D:/LiuYuanHao/b3.in","r",stdin);
	scanf("%d%d%d%d",&w,&h,&qw,&qh);
	db p=((w-qw)/qw/2);
	int t=max(p-3,1);
	while((t*2+1)*qw<w) ++t;
	aw=t;
	p=((h-qh)/qh/2);
	t=max(p-3,1);
	while((t*2+1)*qh<=h) ++t;
	ah=t;
	printf("%d\n",aw*ah);
	return 0;
}









