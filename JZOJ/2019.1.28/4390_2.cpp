#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=200200,mo=999999599;
int n,m,d;
int p[N];
int qsm(int x,int y)
{
	int rt=1;
	fo(i,0,30)
	{
		if((1<<i)&y) rt=1ll*rt*x%mo;
		x=1ll*x*x%mo;
	}
	return rt;
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&m);
	p[0]=1;
	fo(i,1,n)
	{
		fo(j,1,oo)
		{
			int le=j*(3*j-1)/2,ri=j*(3*j+1)/2,op=(j&1)?1:(-1);
			if(le<=i) p[i]=(0ll+p[i]+op*p[i-le]+mo-1)%(mo-1);
			if(ri<=i) p[i]=(0ll+p[i]+op*p[i-ri]+mo-1)%(mo-1);
			if(le>i&&ri>i)break;
		}
	}
	printf("%d\n",qsm(m,p[n]));
	return 0;
}











