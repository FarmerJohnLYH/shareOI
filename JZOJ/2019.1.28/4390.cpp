#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=200200,mo=999999599;
int n,m,ans;
int qsm(int x,int y)
{
	int rt=1;
	fo(i,0,30)
	{
		if(y&(1<<i)) rt=1ll*rt*x%mo;
		x=1ll*x*x%mo;
	}
	return rt;
}
void solve(int x,int st)
{
	if(x==0||st==1)
	{
		++ans;
		return;
	}
	if(x<st) solve(x,x);
	else
	{
		solve(x-st,st);
		solve(x,st-1);
	}
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&m);
	solve(n,n);
	printf("%d\n",qsm(m,ans));
	return 0;
}











