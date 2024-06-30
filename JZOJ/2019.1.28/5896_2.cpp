#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=100100;
int a[2][N],n;ll T;
int main()
{
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
//	freopen("D:/LiuYuanHao/c.in","r",stdin);
//	freopen("D:/LiuYuanHao/c.out","w",stdout);
	scanf("%d%lld\n",&n,&T);
	fo(i,1,n)
	{
		char c;scanf("%c",&c);
		a[0][i]=c-'0';
	}
	int o=0;
	fo(i,1,T)
	{
		o^=1;
		fo(x,1,n) a[o][x]=a[o^1][x-1]^a[o^1][x+1];
	}
	fo(i,1,n) printf("%d",a[o][i]);printf("\n");
	return 0;
}








