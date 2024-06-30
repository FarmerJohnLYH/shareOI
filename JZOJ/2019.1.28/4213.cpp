#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=101000;
int s[2][N],n,m;
int check(int x,int p,int n)
{
	fo(i,1,x) if(s[p][i]!=s[p][n-x+i])
		return 0;
	return 1;
}
int bor(int p,int n)
{
	int ans=0;
	fo(i,1,n-1)
		if(check(i,p,n)) ans=max(ans,i); 
	return ans;
}
int main()
{
	freopen("D:/LiuYuanHao/a.ans","w",stdout);
	s[1][1]=2;
	s[0][1]=1;
	int s0=1,p0=1;
	n=20;
	fo(l,1,n)
	{
		fo(i,1,p0) s[1][s0+i]=s[0][i];
		fo(i,1,s0) s[0][i]=s[1][i];
		s0+=p0;p0=s0-p0;
		printf("%d ",s0);
	}
		printf("\n");
	return 0;
}











