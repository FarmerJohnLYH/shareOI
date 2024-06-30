#include <cmath>
#include <ctime>
#include <queue>
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
const int N=2020;
int n,k;
int to[N],nex[N],las[N];
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("build.in","r",stdin); 
	freopen("build.out","w",stdout);
	scanf("%d%d",&n,&k);
	int ans=n*(n-1)/2+n;
	printf("%d",ans);
	return 0;
}











