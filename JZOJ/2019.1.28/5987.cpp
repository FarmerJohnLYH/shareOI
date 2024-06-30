#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=250250,mo=998244353;
int n,m,t,w;
int f[N];
int gf(int x)
{
	return(x==f[x]?x:(f[x]=gf(f[x])));
}
int main()
{
	freopen("cactus.in","r",stdin);
	freopen("cactus.out","w",stdout);
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d%d%d",&n,&m,&t,&w);
	fo(i,1,n) f[i]=i;
	fo(i,1,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(gf(x)!=gf(y))
			f[gf(x)]=gf(y),--n;
		printf("%d\n",n);
	}
	return 0;
}








