#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=22;
int n,k;
int t[N],d[N];
int st[4][N],s0[4];
int cnt=0;int kk;
void solve1(int so,int ta,int sp,int n)
{
	if(cnt==k)
		return;
	if(n>0)
	{
		solve1(so,sp,ta,n-1);
		st[ta][++s0[ta]]=st[so][s0[so]--],st[so][s0[so]+1]=0;
		++cnt;
		if(cnt==k) 
			return;
		solve1(sp,ta,so,n-1);
	}
}
void solve2(int so,int ta,int sp,int n)
{
	if(n>0)
	{
		solve2(so,ta,sp,n-1);
		st[sp][++s0[sp]]=st[so][s0[so]--],st[so][s0[so]+1]=0;
		++cnt;
		if(cnt==kk)
			return;
		solve2(ta,so,sp,n-1);
		st[ta][++s0[ta]]=st[sp][s0[sp]--],st[sp][s0[sp]+1]=0;
		++cnt;
		if(cnt==kk)
			return;
		solve2(so,ta,sp,n-1);
	}
}
int ans=0;
int mi[30];
int main()
{
	 // freopen("D:/LiuYuanHao/b.in","r",stdin);
	scanf("%d%d",&n,&k);
	int tot=0;mi[1]=1;
	fo(i,2,30) mi[i]=(mi[i-1]*3);
	while(k) ans=ans+(k&1)*2*mi[++tot],k/=2;
	printf("%d\n",ans);
	return 0;
	fd(i,n,1) st[1][++s0[1]]=i;
	cnt=0;
	solve1(1,3,2,n);
	s0[1]=s0[2]=s0[3]=0;
	fd(i,n,1) st[1][++s0[1]]=i,st[3][i]=0;
	cnt=0;
	solve2(1,3,2,n);
	return 0;
}











