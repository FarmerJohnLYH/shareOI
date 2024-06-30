#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=22;
int n,k;
int st[4][N],s0[4];
int cnt=0,v[N];
void solve1(int so,int ta,int sp,int n)
{
	if(cnt==k) return;
	if(n>0)
	{
		solve1(so,sp,ta,n-1);
		st[ta][++s0[ta]]=st[so][s0[so]--],st[so][s0[so]+1]=0;
		++cnt;
		if(cnt==k) 
		{
			fo(i,1,3) fo(j,1,s0[i])
				v[st[i][j]]=i;
			return;
		}	
		solve1(sp,ta,so,n-1);
	}
}
ll ans,mi[N];
void solve2(int so,int ta,int sp,int n)
{
	if(n>0)
	{
		if(v[n]==so) 
		{
			solve2(so,ta,sp,n-1);
			return;
		}
		else
		{
			fd(i,n-1,1) st[ta][++s0[ta]]=st[so][s0[so]-i+1],st[so][s0[so]-i+1]=0; 
			s0[so]-=n-1;
			ans+=mi[n-1]-1;
		}
		st[sp][++s0[sp]]=st[so][s0[so]--],st[so][s0[so]+1]=0;
		++ans;
		if(v[n]==sp)
		{
			solve2(ta,so,sp,n-1);
			return;
		}
		else
		{
			fd(i,n-1,1) st[so][++s0[so]]=st[ta][s0[ta]-i+1],st[ta][s0[ta]-i+1]=0; 
			s0[ta]-=n-1;
			ans+=mi[n-1]-1;
		}
		st[ta][++s0[ta]]=st[sp][s0[sp]--],st[sp][s0[sp]+1]=0;
		++ans;
		solve2(so,ta,sp,n-1);
	}
}
int main()
{
	// freopen("D:/LiuYuanHao/b.in","r",stdin);
	scanf("%d%d",&n,&k);
	mi[0]=1;fo(i,1,n) mi[i]=mi[i-1]*3;
	fd(i,n,1) st[1][++s0[1]]=i;
	cnt=0;
	solve1(1,3,2,n);
	s0[1]=s0[2]=s0[3]=0;
	fd(i,n,1) st[1][++s0[1]]=i,st[3][i]=0;
	solve2(1,3,2,n);
	printf("%lld\n",ans);
	return 0;
}











