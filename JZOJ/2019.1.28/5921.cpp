#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=5050,mo=1e9+7;
int n,p[N];
int a[N],b[N];
int ans;
int main()
{
	freopen("derangement.in","r",stdin);
	freopen("derangement.out","w",stdout);
//	freopen("D:/LiuYuanHao/c.in","r",stdin);
	scanf("%d",&n);
	fo(i,1,n) scanf("%d",&p[i]);
	dfs(1);
	printf("%d\n",ans%mo);
	return 0;
}








