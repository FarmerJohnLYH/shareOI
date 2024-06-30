#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=100100;
int n,a[N],b[N];
long long ans;
int main()
{
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d",&n);
	fo(i,1,n) scanf("%d",&b[i]),a[i]=max(a[i-1],b[i]);
	ans=a[n]-b[n];fd(i,n-1,1) a[i]=max(a[i],a[i+1]-1),ans=ans+a[i]-b[i];
	printf("%I64d\n",ans); 
	return 0;
}











