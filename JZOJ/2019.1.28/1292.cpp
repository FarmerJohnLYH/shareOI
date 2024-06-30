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
const int mo=5000011,N=200200;
int f[N],cnt;
int n,k;
int main()
{
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	// freopen("a.ans","w",stdout);
	scanf("%d%d",&n,&k);
	cnt=0;
	fo(i,1,n+k+1)
	{
		if(i-k-1>0) cnt=(cnt+f[i-k-1])%mo;
		f[i]=(cnt+1)%mo;
	}
	printf("%d\n",f[n+k+1]);
	return 0;
}











