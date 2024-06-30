#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int mo=10007,H=2525,S=110;
int h,w,s;
int f[H][S][2]/*0Ri 1Dn*/;
ll ans;
void solve()
{
	ll cnt=0;
	
	fo(i,1,h-1)
	{	
	}
	ans=(ans+cnt)%mo;
}
int main()
{
	freopen("D:/LiuYuanHao/","r",stdin);
	scanf("%d%d%d",&h,&w,&s);
	solve();
	swap(h,w);
	solve();
	printf("%lld\n",ans);
	return 0;
}











