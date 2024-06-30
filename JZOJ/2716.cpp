 #pragma GCC optimize(2) 
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=5050;
int n,m,ans;
int a[N],b[N];
int main()
{
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&m);
	fo(i,1,n) scanf("%d",&a[i]);sort(a+1,a+1+n);
	fo(i,1,m) scanf("%d",&b[i]);sort(b+1,b+1+m);
	fd(i,n,1) 
	{
		sort(b+1,b+1+m);
		fd(j,m,m-a[i]+1) --b[j];
		ans+=a[i];
	}
	fo(i,1,m) ans+=max(b[i],0);
	printf("%d\n",ans);
	return 0;
}








