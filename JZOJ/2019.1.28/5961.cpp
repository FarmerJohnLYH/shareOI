#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
int a,b,ans;
int n;
int main()
{
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&a);
	ans=a;
	fo(i,2,n)
	{
		scanf("%d",&b);
		ans+=max(0,b-a);a=b;
	}
	printf("%d\n",ans);
	return 0;
}








