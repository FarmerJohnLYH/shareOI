#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=10001000;
int n;ll mo,s;
ll f[N];
int main()
{
	freopen("suffix.in","r",stdin);
	freopen("suffix.out","w",stdout);
	// freopen("D:/LiuYuanHao/","r",stdin);
	scanf("%d%lld%lld",&n,&s,&mo);
	f[0]=1,f[1]=s;
	fo(i,2,n)
		f[i]=(f[i-1]*s%mo-f[(i+1)/2]+mo)%mo;
	printf("%lld\n",f[n]);
	return 0;
}








