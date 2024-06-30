#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (int pq = (y),i = (x);i <= pq;++ i)
#define fd(i,x,y) for (int pq = (y),i = (x);i >= pq;-- i)
#define oo 2139062143
using namespace std;
typedef double db;
typedef long long ll;
int lowbit(int x) {return((x)&(-x));}
int min(int x,int y){return (x>y)?(y):(x);}
int max(int x,int y){return (x>y)?(x):(y);}
const int N=100100;
int n;
char st[N];
int L,ans=0;
int dis(int xl,int xr,int yl,int yr)
{
	if(yr-yl<xr-xl) swap(xl,yl),swap(xr,yr);
	int flag=0;
	fo(i,0,n+1)
	{
		if(flag+xl-1>=xr)break;
		if(st[xl+i]!=st[yl+i])
			break;
		flag=i+1;
	}
	return((yr-yl+1-flag)+(xr-xl+1-flag));	
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%s",st+1);
	scanf("%d",&L);
	n=strlen(st+1);
	fo(i,1,n) fo(ie,i,n) 
	fo(j,1,n) fo(je,j,n)
	if((i<j)||(i==j&&ie<=je))
	{
		int tmp=dis(i,ie,j,je);
		if(tmp<=L)
			++ans;
	}
	printf("%d\n",ans);
	return 0;
}
