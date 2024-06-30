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
const int N=1010,mo=1e9+7;
int n,m,k;
PI a[N];
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("count.in","r",stdin);
//	freopen("count.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	fo(i,1,k)
	{
		scanf("%d%d",&a[i].fi,&a[i].se);
	}
	sort(a+1,a+1+k);
	fo(i,1,k)
	{
	
	}
	return 0;
}











