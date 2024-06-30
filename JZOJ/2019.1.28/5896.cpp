#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=200200;
int a[2][N],n;ll T;
ll tw[66];
int p[N*3],al;
int main()
{
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	// freopen("D:/LiuYuanHao/c.in","r",stdin);
	// freopen("D:/LiuYuanHao/c.out","w",stdout);
	scanf("%d%lld\n",&n,&T);
	tw[0]=1;
	al=2*n+2;
	fo(i,1,60)tw[i]=tw[i-1]*2%al;
	fo(i,1,n)
	{
		char c;scanf("%c",&c);
		a[0][i]=c-'0';
	}
	fo(i,1,n) p[i]=i;p[0]=p[n+1]=0;fo(i,1,n) p[n+i+1]=n-i+1;
	int o=0;
	fd(i,60,0)
	if(T&(1ll<<i))
	{	
		o^=1;
		fo(x,1,n)
			a[o][x]=a[1^o][p[(x-tw[i]+al)%al]]^a[1^o][p[(x+tw[i])%al]];
	}
	fo(i,1,n) printf("%d",a[o][i]);printf("\n");
	return 0;
}








