#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=110;
int n,m,t,ans;
int a[N],b[N],k;
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&m);
	fo(i,1,n) scanf("%d",&a[i]);
	fo(i,1,n-1)
	{
		k+=(a[i]&1)?(-1):1;
		if(k==0&&abs(a[i+1]-a[i])<=m)b[++t]=abs(a[i+1]-a[i]); 
	}
	sort(b+1,b+t+1),k=0;
	fo(i,1,t) 
	{
		k+=b[i];
		if(k<=m)ans=i;
		else break;
	}
	printf("%d\n",ans);
}

