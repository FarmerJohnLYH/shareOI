#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=1001000;
int n,a[N];
int p,fa[N];
int gf(int x)
{
	return(x==fa[x])?(x):(fa[x]=gf(fa[x]));
}
int main()
{
	freopen("snowman.in","r",stdin);
	freopen("snowman.out","w",stdout);
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d",&n);
	fo(i,1,n) scanf("%d",&a[i]),fa[i]=i;
	p=0;
	fd(i,n-1,1)
		if(a[i]>a[gf(i)+1]) fa[i-1]=gf(i),++p;
	printf("%d\n",p);
	return 0;
}








