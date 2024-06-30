#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=100100;
int a[N],n,m;
int T;
ll anp,anq;
int main()
{
	 freopen("atom.in","r",stdin);
	 freopen("atom.ans","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		n=0;
		scanf("%d%d",&n,&m);
		fo(i,1,n) 
		{
			scanf("%d",&a[i]);
		}
		anp=0,anq=1;
		fo(i,1,n) fo(j,1,n) fo(k,1,n)
		{
			if(a[i]<a[j]&&a[j]<a[k])
			if((a[k]-a[i])*anp<=anq*(a[k]-a[j]))
			if(a[k]-a[i]<=m)
			{
				anq=a[k]-a[i],anp=a[k]-a[j];
			}
		}
		if(anp==0) printf("-1\n");
		else printf("%.10Lf\n",(long double)anp/(long double)anq);
	}
	return 0;
}








