#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=22,M=4388608;
int a[M],n,m;
int bz[M],p[M];
int all;
void dfs(int x)
{
	if(bz[x])return;
	bz[x]=1;
	if(p[x]) dfs(all^x);
	fo(i,0,n-1)
	if(x&(1<<i)) dfs(x-(1<<i));
}
int main()
{
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&m);
	all=(1<<n)-1;
	fo(i,1,m) scanf("%d",&a[i]),p[a[i]]=1;
	int ans=0;
	fo(i,1,m)
	if(!bz[a[i]])
	{
		++ans;
		bz[a[i]]=1;
		dfs(a[i]^all);
	}
	printf("%d\n",ans);
	return 0;
}










