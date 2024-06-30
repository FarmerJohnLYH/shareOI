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
int n,s,k;
int main()
{
	freopen("repulsed.in","r",stdin);
	freopen("repulsed.out","w",stdout);
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d%d", &n, &s, &k);
	printf("%d", n/s);
	return 0;
}
