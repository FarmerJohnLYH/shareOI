#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=100100;
int a[N],c[N],n,m;
int T;
ll anp,anq;
int find(int x,int y)
{
	int le=x,ri=n,rt=0;
	while(le<=ri)
	{
		int mid=(le+ri)>>1;
		if(a[mid]<=y) le=mid+1,rt=mid;
		else ri=mid-1;
	}
	return rt;
}
int main()
{
	 freopen("atom.in","r",stdin);
	 freopen("atom.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		int q=0;n=0;
		scanf("%d%d",&q,&m);
		fo(i,1,q) 
			scanf("%d",&c[i]); 
		sort(c+1,c+1+q);
		fo(i,1,q)
		{
			a[++n]=c[i];
			if(n>1&&a[n]==a[n-1]) 
				--n;
		}
		anp=0,anq=1;
		fo(i,2,n-1)
		{
			int p=find(i+1,a[i-1]+m);
			if(p)
			if(anp*(a[p]-a[i-1])<=anq*(a[p]-a[i]))
			{
				anp=(a[p]-a[i]),anq=(a[p]-a[i-1]);
				if((long double)anp/(long double)anq>=0.9999)
					printf("");					
			}

		}
		if(anp==0) printf("-1\n");
		else printf("%.10Lf\n",(long double)anp/(long double)anq);
	}
	return 0;
}








